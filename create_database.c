#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Status create_database(HT *hash_table, Slist *head)
{
	Slist * temp = head;  // declare the slist variable to head 
	FILE *fptr;			// file pointer 
	char store[20]; // to store the content from the file pointer
	int index; 		// to store the index for the hash table 
	while(temp)     // travers the temp of the slist tiil the null
	{
		fptr = fopen(temp -> file_name , "r");		// open the file and collect in the file pointer 
		while(fscanf(fptr,"%s", store)!= EOF)		// scan the file till the end of the file 
		{
			char key = store[0];			// check the first character of the store is upper or lower case 
			if(key >= 'a' && key <= 'z')	// if the char is lower case
			{
				index = key % 97;			// then calculate the index using the formaula 
			}	
			else if(key >= 'A' && key <= 'Z')  // if the char is uppercase the conver to the lowercase 
			{
				index = key % 65;				// collect the lowercase value in the index 
			}
			else
			{
				index = 26;						// to store the special character in the last index 
			}	

			if(hash_table[index].link == NULL)			// check the index id null  or not 
			{
				main_node * m_new = malloc(sizeof(main_node));		// create the main node  
				sub_node * s_new = malloc(sizeof(sub_node));		// create  the sub node 
				if(m_new != NULL || s_new != NULL)					// chech node are created or not 
				{
					strcpy(m_new -> word,store);					// insert the word to the main node

				//	printf("Word = %s\n", m_new -> word);
					m_new -> main_link = NULL;							// update the main node link to null
					m_new -> sub_link = s_new;							// update the sub link to new sub node 
					m_new -> file_count = 1;							// update the file count to 1
					s_new -> word_count = 1;							// update the word count to 1
					strcpy(s_new -> file_name, temp -> file_name);		// copy the file name to the sub node
					s_new -> sub_link = NULL;							// update the link of the main node link to hash table index 
					hash_table[index].link = m_new;
		
				//	printf("File = %s\n", s_new -> file_name);
				//return SUCCESS;
				}
				else
				{
					return FAILURE;
				}

			}
			else
			{
				main_node *m_temp = hash_table[index].link; 		// create the temp variable and assing hash table of index to the temp 
				main_node *m_prev = NULL;							// create the prev to null
				int m_flag = 0;										// take the flag as 0
				while(m_temp)										// travers the m temp till null
				{
					if(!(strcmp(m_temp -> word, store)))			// store the word 
					{
						int s_flag = 0;
						sub_node *s_temp = m_temp -> sub_link;		// update the link 
						sub_node *s_prev = NULL;                        

						while(s_temp)								// travers sub node
						{		
							if(!(strcmp(s_temp -> file_name, temp -> file_name))) // compare the file present in the linked list and read file name is same or not 
							{
								(s_temp -> word_count)++;			// is the word is same update the wordcount 
								s_flag = 1;
								break;
							}
							s_prev = s_temp;					// update the temp to prev
							s_temp = s_temp -> sub_link;        // update the sub link to next sub link
						}
						if(s_flag == 0)
						{
							sub_node *s_new = creat_sub_node(temp -> file_name);  // create the sub node and insert the file name 
							s_prev -> sub_link = s_new;							// update the node link to new node
							(m_temp -> file_count)++;							// update the file count 

						}
						m_flag = 1; 
						break;
					}
					m_prev = m_temp;   // update the temp to prev
					m_temp = m_temp -> main_link; // update the main link to next main link
				}
				if(m_flag ==0)
				{
					main_node *m_new = creat_main_node(store);  // create the maim node and store  
					m_prev -> main_link = m_new;

					sub_node *s_new = creat_sub_node(temp -> file_name);  // create the sub node and store  
					m_new -> sub_link = s_new; // update the sub link to next sub link 
				}
			}
		}
		temp = temp -> link; // update the link to next node link 
	}
//	printf("im in creat database\n");
	return SUCCESS;
}

// function to craete the main node 
main_node *creat_main_node(char *word)
{
	main_node *m_new = malloc(sizeof(main_node));

	if(m_new == NULL)
		return NULL;

	m_new -> main_link = NULL;
	m_new -> file_count = 1;
	strcpy(m_new -> word, word);
	return m_new;
}

// function to craete the sub node. 
sub_node *creat_sub_node(char *name)
{
	sub_node *s_new = malloc(sizeof(sub_node));

	if(s_new == NULL)
		return NULL;

	s_new -> sub_link = NULL;
	s_new -> word_count = 1;
	strcpy(s_new -> file_name, name);
	return s_new;
}
