/*
 * linked_list.h
 *
 *  Created on: Oct 30, 2023
 *      Author: Mohamed Demrdash
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include "platform_types.h"

#define DATA_FILE "data_base.txt"

typedef struct STUDENT
{
	struct STUDENT* next_student;

	float32 gpa;     //must be less than 4
	uint16   subject; // can't enroll in more than 5 subjects per term
	uint16  roll_no; //must be unique an doesn't exceed 4 digits
	uint8   first_name[11]; //the name can't exceed 10 letters
	uint8   last_name [11]; //the name can't exceed 10 letters
					  //every bit will represent a subject
					  //each subject has a code from 0 to 15
}STUDENT;

typedef struct
{
	STUDENT* fisrt_student;
	STUDENT* last_student;
	uint16 no_of_students;

}LIST_HEADER;

typedef enum
{
	LIST_NO_ERROR,
	LIST_EMPTY,
	LIST_NULL,
	LIST_CLOSE
}LIST_STATE;


LIST_STATE add_from_file		(LIST_HEADER* header_student_list,uint8* file_name);
LIST_STATE add_manually			(LIST_HEADER* header_student_list);
LIST_STATE find_by_roll_number	(LIST_HEADER* header_student_list,uint16 roll_no,uint8 error);
LIST_STATE find_by_first_name	(LIST_HEADER* header_student_list);
LIST_STATE studnets_of_course	(LIST_HEADER* header_student_list);
LIST_STATE delete_student		(LIST_HEADER* header_student_list);
LIST_STATE update_student		(LIST_HEADER* header_student_list);
LIST_STATE show_all				(LIST_HEADER* header_student_list);
LIST_STATE close_programe		(LIST_HEADER* header_student_list);


#endif /* LINKED_LIST_H_ */
