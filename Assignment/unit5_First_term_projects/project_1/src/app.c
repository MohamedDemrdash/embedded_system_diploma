/*
 ============================================================================
 Name        : app.c
 Author      : Mohamed Demrdash
 Version     :
 Description  : This project on the first term in the online diploma. It is
 	 	 	 : data base for school based on linked list.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main(void)
{

	LIST_HEADER header_student_list;
	header_student_list.fisrt_student  = NULL;
	header_student_list.last_student   = NULL;
	header_student_list.no_of_students = 0;
	uint16 ch,run= 1;
	uint8 file_name[15];
	uint16 roll_no =0;
	add_from_file(&header_student_list,(uint8*)DATA_FILE);
	while (run)
	{
		printf("---------------------\n");
		printf("\nChoose one of the following options:\n1-Add manually\t2-Add from a file\t3-Search by roll no\t4-Search by first name\t5-Course's students\n6-Delete a student\t7-Edit student info\t8-Show all student\t9-Close the programe\nchoose no.: ");
		fflush(stdin);
		scanf("%hu",&ch);
		printf("---------------------\n\n");
		switch (ch)
		{
		case 1:
			add_manually(&header_student_list);
			break;
		case 2:

			printf("Enter the file name: ");
			fflush(stdin);
			scanf("%s",file_name);
			add_from_file(&header_student_list,file_name);
			break;
		case 3:
			printf("Enter the roll number of the desired student: ");
			scanf("%hu",&roll_no);
			find_by_roll_number(&header_student_list,roll_no,TRUE);
			break;
		case 4:
			find_by_first_name(&header_student_list);
			break;
		case 5:
			studnets_of_course(&header_student_list);
			break;
		case 6:
			delete_student(&header_student_list);
			break;
		case 7:
			update_student(&header_student_list);
			break;
		case 8:
			show_all(&header_student_list);
			break;
		case 9:
			if(close_programe(&header_student_list) == LIST_CLOSE)
			{
				run =0;
			}
			break;
		default:
			break;
		}
	}

	return EXIT_SUCCESS;
}
