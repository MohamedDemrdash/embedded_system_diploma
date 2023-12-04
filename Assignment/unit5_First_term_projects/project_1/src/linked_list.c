/*
 * linked_list.c
 *
 *  Created on: Oct 30, 2023
 *      Author: Mohamed Demrdash
 */
#include "linked_list.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

LIST_STATE add_from_file(LIST_HEADER* header_student_list,uint8* file_name)
{
	LIST_STATE list_state;
	FILE* p_file_in;
	sint8 ch,flag=0;
	uint16 course_id =0;
	p_file_in =fopen((const char *)file_name,"r");
	while((ch = fgetc(p_file_in)) != EOF)
	{
		fseek(p_file_in,-1,SEEK_CUR);
		if(header_student_list->no_of_students == 0)
		{
			header_student_list->fisrt_student =(STUDENT*) malloc(sizeof(STUDENT));
			header_student_list->last_student = header_student_list->fisrt_student;
		}
		else
		{
			header_student_list->last_student->next_student =(STUDENT*) malloc(sizeof(STUDENT));
			header_student_list->last_student = header_student_list->last_student->next_student;
		}
		if(flag ==0 )
		{
			flag = 1;
		}
		fscanf(p_file_in,"%hu",&header_student_list->last_student->roll_no);
		fscanf(p_file_in,"%s",header_student_list->last_student->first_name);
		fscanf(p_file_in,"%s",header_student_list->last_student->last_name);
		fscanf(p_file_in,"%f",&header_student_list->last_student->gpa);
		header_student_list->last_student->subject = 0;
		while((ch = fgetc(p_file_in)) != EOF && ch != '\n')
		{
			fscanf(p_file_in,"%hu",&course_id);
			header_student_list->last_student->subject |= (1<<course_id);
		}
		header_student_list->last_student->next_student = NULL;
		header_student_list->no_of_students ++;
	}
	if(flag == 0)
	{
		printf("[ERROR] This file is Empty\n");
		list_state = LIST_NULL;
	}
	else
	{
		printf("[INFO] The data loaded successfully\n");
	}

	fclose(p_file_in);
	return list_state;
}

LIST_STATE add_manually(LIST_HEADER* header_student_list)
{
	LIST_STATE list_state;
	uint16 roll_no = 0;
	if(header_student_list->no_of_students == 0)
	{	
		header_student_list->fisrt_student =(STUDENT*) malloc(sizeof(STUDENT));
		if(header_student_list->fisrt_student == NULL)
		{
			list_state = LIST_NULL;
		}
		else
		{
			printf("Enter student's roll number: ");
			scanf("%hu",&header_student_list->fisrt_student->roll_no);
			fflush(stdin);
			printf("Enter student's first name: ");
			scanf("%s",header_student_list->fisrt_student->first_name);
			fflush(stdin);
			printf("Enter student's last name: ");
			scanf("%s",header_student_list->fisrt_student->last_name);
			fflush(stdin);
			printf("Enter student's GPA: ");
			scanf("%f",&header_student_list->fisrt_student->gpa);
			fflush(stdin);
			printf("Enter subjects code:-\n");
			uint16 count = 1,subject_id;
			header_student_list->fisrt_student->subject = 0;
			while(count <=5)
			{
				printf("%d- ",count);
				scanf("%hu",&subject_id);
				fflush(stdin);
				header_student_list->fisrt_student->subject |= (1<<subject_id);
				++count;
			}
			header_student_list->fisrt_student->next_student = NULL;
			header_student_list->last_student = header_student_list->fisrt_student;
			header_student_list->no_of_students ++;
			list_state = LIST_NO_ERROR;
		}
	}
	else
	{
		printf("Enter student's roll number: ");
		scanf("%hu",&roll_no);
		fflush(stdin);
		if (find_by_roll_number(header_student_list,roll_no,FALSE) == LIST_NO_ERROR)
		{
			printf("\n");
			printf("[ERROR] There is already a student with this roll number, please pick a unique one\n");
			free(header_student_list->last_student->next_student);
			list_state =LIST_NULL;
		}
		else
		{
			header_student_list->last_student->next_student = (STUDENT*) malloc(sizeof(STUDENT));
			if(header_student_list->last_student->next_student == NULL)
			{
				list_state =LIST_NULL;
			}
			else
			{

				header_student_list->last_student = header_student_list->last_student->next_student;
				header_student_list->last_student->roll_no = roll_no;
				printf("Enter student's first name: ");
				scanf("%s",header_student_list->last_student->first_name);
				fflush(stdin);
				printf("Enter student's last name: ");
				scanf("%s",header_student_list->last_student->last_name);
				fflush(stdin);
				printf("Enter student's GPA: ");
				scanf("%f",&header_student_list->last_student->gpa);
				fflush(stdin);
				printf("Enter subjects code:-\n");
				uint16 count = 1,subject_id;
				header_student_list->last_student->subject = 0;
				while(count <=5)
				{
					printf("%d- ",count);
					scanf("%hu",&subject_id);
					fflush(stdin);
					header_student_list->last_student->subject |= (1<<subject_id);
					count++;
				}
				header_student_list->last_student->next_student = NULL;
				header_student_list->no_of_students ++;

				list_state = LIST_NO_ERROR;
			}

		}

	}

	return list_state;
}

LIST_STATE find_by_roll_number(LIST_HEADER* header_student_list,uint16 roll_no,uint8 error)
{
	LIST_STATE list_state;
	STUDENT *current = header_student_list->fisrt_student;
	while(current != NULL)
	{
		if(current->roll_no == roll_no)
		{
			printf("\n");
			printf("Roll No.\tFirst Name  \tLast Name   \tGPA  \tSubjects_code\n");
			printf("%-8d\t",current->roll_no);
			printf("%-12s\t",current->first_name);
			printf("%-12s\t",current->last_name);
			printf("%-5.2f\t",current->gpa);
			uint16 subject_id = 0;
			while(subject_id < 16)
			{
				if((current->subject >> subject_id) & 1)
				{
					printf("%-2d ",subject_id);
				}
				else
				{

				}
				subject_id++;
			}
			printf("\n");
			break;
		}
		else
		{
			current = current->next_student;
		}
	}
	if(current == NULL)
	{
		if(error)
		{
			printf("[ERROR] There is no student with this roll number\n");
		}
		else
		{

		}
		list_state =LIST_NULL;
	}
	else
	{
		list_state = LIST_NO_ERROR;
	}
	return list_state;
}

LIST_STATE find_by_first_name(LIST_HEADER* header_student_list)
{
	LIST_STATE list_state;
	uint8 name[11];
	uint16 flag = 0;
	STUDENT *current = header_student_list->fisrt_student;
	printf("Enter the first name of the desired student: ");
	scanf("%s",name);
	printf("\n");
	while(current != NULL)
	{
		if(stricmp((const char*)current->first_name,(const char*)name) == 0)
		{
			if(flag == 0)
			{
				printf("Roll No.\tFirst Name  \tLast Name   \tGPA  \tSubjects_code\n");
				flag =1;
			}
			printf("%-8d\t",current->roll_no);
			printf("%-12s\t",current->first_name);
			printf("%-12s\t",current->last_name);
			printf("%-5.2f\t",current->gpa);
			uint16 subject_id = 0;
			while(subject_id < 16)
			{
				if((current->subject >> subject_id) & 1)
				{
					printf("%-2d ",subject_id);
				}
				else
				{

				}
				subject_id++;
			}
			printf("\n");
		}
		current = current->next_student;
	}
	if(flag == 0)
	{
		printf("[ERROR] There is no student with this first name\n");
		list_state =LIST_NULL;
	}
	else
	{
		list_state = LIST_NO_ERROR;
	}
	return list_state;
}

LIST_STATE studnets_of_course(LIST_HEADER* header_student_list)
{
	LIST_STATE list_state;
	uint16 course_id,flag=0;
	STUDENT *current = header_student_list->fisrt_student;
	printf("Enter the subject id: ");
	scanf("%hu",&course_id);
	printf("\n");
	while(current != NULL)
	{

		if(((current->subject)>>course_id)&1)
		{
			if(flag == 0)
			{
				printf("Roll No.\tFirst Name  \tLast Name   \tGPA  \tSubjects_code\n");
			}
			flag =1;
			printf("%-8d\t",current->roll_no);
			printf("%-12s\t",current->first_name);
			printf("%-12s\t",current->last_name);
			printf("%-5.2f\t",current->gpa);
			uint16 subject_id = 0;
			while(subject_id < 16)
			{
				if((current->subject >> subject_id) & 1)
				{
					printf("%-2d ",subject_id);
				}
				else
				{

				}
				subject_id++;
			}
			printf("\n");
			current = current->next_student;
		}
		else
		{
			current = current->next_student;
		}
	}
	if(flag == 0)
	{
		printf("[ERROR] There is no student enrolled in this subject\n");
		list_state =LIST_NULL;
	}
	else
	{
		list_state = LIST_NO_ERROR;
	}
	return list_state;
}

LIST_STATE delete_student(LIST_HEADER* header_student_list)
{
	LIST_STATE list_state;
	uint16 roll_no =0,flag = 0;
	STUDENT *current = header_student_list->fisrt_student, *previous;
	printf("Enter the roll number of the desired student: ");
	scanf("%hu",&roll_no);
	printf("\n");
	while(current != NULL)
	{
		if(current->roll_no == roll_no)
		{
			printf("Roll No.\tFirst Name  \tLast Name   \tGPA  \tSubjects_code\n");
			printf("%-8d\t",current->roll_no);
			printf("%-12s\t",current->first_name);
			printf("%-12s\t",current->last_name);
			printf("%-5.2f\t",current->gpa);
			uint16 subject_id = 0;
			while(subject_id < 16)
			{
				if((current->subject >> subject_id) & 1)
				{
					printf("%-2d ",subject_id);
				}
				else
				{

				}
				subject_id++;
			}
			if(flag == 0)
			{
				header_student_list->fisrt_student = current->next_student;
				free(current);
				header_student_list->no_of_students --;
				printf("\n");
				printf("[INFO] The student has been deleted successfully\n");
				break;
			}
			else
			{
				current  = current->next_student;
				free(previous->next_student);
				previous->next_student = current;
				header_student_list->no_of_students --;
				printf("\n\n");
				printf("[INFO] The student has been deleted successfully\n");
				break;
			}
		}
		else
		{
			previous = current;
			current = current->next_student;
		}
		flag ++;
	}
	if(current == NULL && flag != header_student_list->no_of_students)
	{
		printf("[ERROR]There is no student with this roll number\n");
		list_state =LIST_NULL;
	}
	else if (current == NULL && flag == header_student_list->no_of_students)
	{
		header_student_list->last_student = previous;
	}

	else
	{
		list_state = LIST_NO_ERROR;
	}
	return list_state;

}

LIST_STATE update_student(LIST_HEADER* header_student_list)
{
	LIST_STATE list_state;
	uint16 roll_no =0;
	STUDENT *current = header_student_list->fisrt_student;
	printf("Enter the roll number of the desired student: ");
	scanf("%hu",&roll_no);
	printf("\n");
	while(current != NULL)
	{
		if(current->roll_no == roll_no)
		{

			printf("Choose the info you want to change :-\n1-Roll no.\t2-First Name\t3-Last Name\t4-GPA\t5-Subjects\n");
			printf("choose no. : ");
			uint8 ch = 0;
			fflush(stdin);
			scanf(" %c",&ch);
			printf("\n");
			fflush(stdin);
			switch(ch)
			{
			case '1':
				printf("Enter the new roll no. : ");
				scanf("%hu",&current->roll_no);
				break;
			case '2':
				printf("Enter the new first name: ");
				scanf("%s",current->first_name);
				break;
			case '3':
				printf("Enter the new last name: ");
				scanf("%s",current->last_name);
				break;
			case '4':
				printf("Enter the new GPA: ");
				scanf("%f",&current->gpa);
				break;
			case '5':
				printf("Enter the new subjects : ");
				uint16 count = 1,subject_id;
				current->subject = 0;
				while(count <=5)
				{
					printf("%d- ",count);
					scanf("%hu",&subject_id);
					fflush(stdin);
					current->subject |= (1<<subject_id);
					++count;
				}
				break;
			}
			printf("Roll No.\tFirst Name  \tLast Name   \tGPA  \tSubjects_code\n");
			printf("%-8d\t",current->roll_no);
			printf("%-12s\t",current->first_name);
			printf("%-12s\t",current->last_name);
			printf("%-5.2f\t",current->gpa);
			uint16 subject_id = 0;
			while(subject_id < 16)
			{
				if((current->subject >> subject_id) & 1)
				{
					printf("%-2d ",subject_id);
				}
				else
				{

				}
				subject_id++;
			}
			printf("\n\n");
			printf("[INFO] The student has been updated successfully\n");
			break;
		}
		else
		{
			current = current->next_student;
		}
	}
	if(current == NULL)
	{
		printf("[ERROR] There is no student with this roll number\n");
		list_state =LIST_NULL;
	}
	else
	{
		list_state = LIST_NO_ERROR;
	}
	return list_state;
}

LIST_STATE show_all(LIST_HEADER* header_student_list)
{
	LIST_STATE list_state;
	STUDENT* current = header_student_list->fisrt_student;
	if(current == NULL)
	{
		printf("[ERROR] There is no students yet \n");
		list_state = LIST_NULL;
	}
	else
	{
		printf("Roll No.\tFirst Name  \tLast Name   \tGPA  \tSubjects_code\n");
		while(current != NULL)
		{

			printf("%-8d\t",current->roll_no);
			printf("%-12s\t",current->first_name);
			printf("%-12s\t",current->last_name);
			printf("%-5.2f\t",current->gpa);
			uint16 subject_id = 0;
			while(subject_id < 16)
			{
				if((current->subject >> subject_id) & 1)
				{
					printf("%-2d ",subject_id);
				}
				else
				{

				}
				subject_id++;
			}
			printf("\n");
			current = current->next_student;

		}
		list_state = LIST_NO_ERROR;
	}

	return list_state;
}

LIST_STATE close_programe(LIST_HEADER* header_student_list)
{
	LIST_STATE list_state;
	STUDENT *current , *previous;
	current = header_student_list->fisrt_student;
	uint16 count = 0;
	FILE* p_file_in = NULL;
	uint16 course_id =0;
	p_file_in =fopen((const char *)DATA_FILE,"w");
	while(count < header_student_list->no_of_students )
	{
		fprintf(p_file_in,"%hu",current->roll_no);
		fprintf(p_file_in," ");
		fprintf(p_file_in,"%s",current->first_name);
		fprintf(p_file_in," ");
		fprintf(p_file_in,"%s",current->last_name);
		fprintf(p_file_in," ");
		fprintf(p_file_in,"%f",current->gpa);
		while(course_id < 16)
		{
			if((current->subject >> course_id) & 1)
			{
				fprintf(p_file_in," ");
				fprintf(p_file_in,"%hu",course_id);
			}
			else
			{

			}
			course_id++;
		}
		course_id =0;
		fprintf(p_file_in,"\n");
		previous = current;
		current  = current->next_student;
		free(previous);
		count++;
	}
	fclose(p_file_in);
	if(current == NULL && count == header_student_list->no_of_students)
	{
		list_state = LIST_CLOSE;
	}
	else
	{
		list_state = LIST_NULL;
	}
	return list_state;
}

