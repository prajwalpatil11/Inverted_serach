/*
NAME : Prajwal Patil
DATE : 07/APRIL/2023
DESCRIPTION : INVERTED SEARCH 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

Slist *head = NULL;
int flag = 0;
int main (int argc, char* argv[])
{

	if(argc < 2)   // condition to pass the atleast 2 arguments 
	{
		printf("Pass Atleast 2 Arguments \n USAGE: ./a.out file1.txt file2.txt file3.txt \n "); // to print the error 
	}

	if(read_and_validate(argc,argv,&head) == SUCCESS)		// gives the status of the read and validate function
	{
		printf("INFO : Read and Validate Successful\n");
		int option;
		int update = 1;

		while(1)
		{

			printf("Select your Choice to perform the Operations\n");														
			printf("1. Create Database\n2. Display Database\n3. Search Database\n4. Save Database\n5. Update Database\n");		// display the menu to the terminal 
			scanf("%d", &option);		// read the option form the user 
			HT hash_table[27];			// create the hash table 
			if(update == 1)				// condtion to create the hash table only once
			{
				create_hashtable(hash_table);	// function call to create  the file hash table 
				update++;
			}
			switch(option)
			{
				case 1:
					{
						if(flag == 1)
						{
							printf("INFO DATABASE IS ALREADY CREATED");
						}
						else if(create_database(hash_table,head) == SUCCESS)  // check the status the of the create database and print the message 
						{
							flag = 1;
							printf("INFO : DATABASE CREATED SUCCESSFULLY\n");
						}	
						else
						{
							printf("ERROR : CREATING DATABASE FAiLED \n");
							return FAILURE;
						}
					}
					break;	
				case 2:
					{
						if(display_database(hash_table) == FAILURE)  // check the status of the display database 
						{
							printf("ERROR : THE DATABASE IS EMPTY\n");
						}
					}
					break;
				case 3:
					{
						char buffer[30];
						printf("INFO : Enter the Word to be Searched : ");
						scanf("%s", buffer);
						if(search_database(hash_table,buffer) == SUCCESS) //check the status of the search database 
						{
							printf("INFO : WORD FOUND IN DATABASE \n");
						}
						else
						{
							printf("ERROR : %s WORD IS NOT PRESENT IN DATABASE\n", buffer);
						}					
					}		
					break;
				case 4:
					{
						if(save_database(hash_table) == SUCCESS)   // chech the status of the save database 
						{
							printf(" INFO : DATABASE SAVED SUCCESSFULL\n");
						}
						else
						{
							printf("ERROR : DATA NOT SAVE SUCCESSFULL\n");
						}
					}
					break;
				case 5:                                                                         // chech for the status of the update database and perform the operaton 
					{                                                  
						char name[20];
						printf("\nEnter the file name to update data : ");
						scanf(" %s", name);
						if( strstr(name, ".txt") == NULL)
						{
							printf("\nERROR : %s is not a .txt file, Pass .txt files\n", name);
						}
						else if(check_empty(name) == -1)
						{
							printf("\nINFO : %s DOSEN'T EXIST\n", name);
						}
						else if( check_empty(name) == FAILURE)
							printf("\nINFO : %s file is empty\n", name);

						else if( update_database(hash_table, name) == SUCCESS)
						{
							printf(" INFO : %s FILE UPDATED TO  DATABASE SUCCESSFULLY\n", name);
							flag = 1;
						}
						else
							printf("\nERROR : %s file is not in correct pattern\nfile updation to DATABASE FAILED\n", name);
					}
					break;						
				default:							// deafult case to print 
					{
						printf("INFO : Enter Proper Choice\n");
						continue;
					}
			}
			while(1)    // to contine thw program enter the yes or no
			{
				char opt;
				printf("DO You want continue ?\n ENter y/Y to continue and n/N to Discontinue \n\n");
				scanf(" %c", &opt);
				if(opt == 'y' || opt == 'Y')
					break;
				else if (opt == 'n' || opt == 'N')
					return FAILURE;
				else
					puts("INFO : Enter Proper key");
			}
		}
	}
	else
	{
		printf("ERROR: Read and Validate Failed");
		return FAILURE;
	}
	return 0;
}

// funtion to craete the hash table
void create_hashtable(HT *hash)
{
	for(int i = 0; i < 27; i++)
	{
		hash[i].index = i;
		hash[i].link = NULL;	
	}
}
