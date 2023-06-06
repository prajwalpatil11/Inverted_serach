#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

Status read_and_validate(int argc, char *argv[], Slist **head)
{
	int flag = 0; 
	for(int i = 1; i < argc; i++)   // for loop to run the argc times 
	{
		if(!(strcmp(strstr(argv[i], "."), ".txt")))  // to caheck the file is .txt or not 
		{
			if(check_empty(argv[i]) == SUCCESS) // check the empty file and the file exixt or not 
			{
				if(insert_last(head, argv[i]) == SUCCESS) // check the insert last operation status 
				{
					//printf("INFO : Insert Successful done \n");
					flag = 1;
				}
				else if( insert_last(head, argv[i]) == FAILURE) 
				{ 
					printf("ERROR: INSERTING FAILURE\n");     // print the error message 

				}
				else
				{
					printf("ERROR: Duplicate File Found\n");   // error mseesge for the duplicate file found
				}
			}
			else if (check_empty(argv[1]) == FAILURE) 			//  check the  file is empty or not 
			{
				printf("ERROR : File Empty\n");  				// display the error if file empty then
			}	
			else
			{
				printf("ERROR : File not Present\n");			// if file not present then print the error 
			}
		}
		else
		{
			printf("ERROR : The File %s not found\n", argv[i]);  // chech the foe the passed file is txt or not 
		}	
	}
	if(flag == 1)
	{
		return SUCCESS;
	}
	else
	{
		return FAILURE;
	}
}
// function to check the empty file and the duplicate file
Status check_empty(char * file)
{
	FILE *fptr = fopen(file, "r");
	if(fptr == NULL)
	{
		return 1;
	}

	fseek(fptr, 0, SEEK_END);

	if(ftell(fptr) <= 1)
	{ 
		fclose(fptr);
		return FAILURE;
	}
	else
	{
		fclose(fptr);
		return SUCCESS;
	}
}

// function to insert at last 
Status insert_last(Slist **head, char* f_name)
{
	Slist *new = malloc(sizeof(Slist));
	Slist *temp = *head;
	while(temp)
	{
		if(strcmp(temp -> file_name, f_name) == 0)
		{
			return 1;
		}
		temp = temp -> link;

	}
	if(new == NULL)
	{
		return FAILURE;
	}
	else
	{
		strcpy(new -> file_name, f_name);
		new -> link = NULL;
	}

	if(*head == NULL)
	{
		*head = new;
		return SUCCESS;
	}
	else
	{
		Slist *temp;
		temp = *head;
		while(temp -> link != NULL)
		{
			temp = temp -> link;
		}
		temp -> link = new;
		return SUCCESS;
	}
}

