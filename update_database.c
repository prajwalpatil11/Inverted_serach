#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
int update_database(HT *hash, char *file)
{
	char ch;								// variable decleartion 
	FILE *fptr = fopen(file, "r");		    //  open the file using the file input method
	fread(&ch, 1,1,fptr);			    	//	fread reads the char by char. 
	if( ch == '#' )							// check the ch contain #  	
	{
		char buffer[100]; 										// buffer to store the one full line.
		while( fscanf(fptr, "%s", buffer) != EOF)				// to scan the file are using fscanf till the eof 
		{
			int key = atoi(strtok(buffer, "#;"));				// extract the key using the strtok 
			char word[20];										// word is used to store actual word from the buffer 
			char file_name[20];									// to store the file name from the buffer
			if( hash[key].link == NULL )						// chech for the hash table link equal to null.
			{
				strcpy( word, strtok(NULL, ";"));					// copy the next content using the strtok 
				main_node *m_new = creat_main_node(word);			// insert the word in the main node
				m_new -> file_count = atoi(strtok(NULL, ";"));      // exract the file count from the buffer
				hash[key].link = m_new;                             // extablisb the link between the hash table and the main mode.
				strcpy(file_name, strtok(NULL, ";"));				// extract the file name form the buffer. 
				sub_node *s_new = creat_sub_node(file_name);		// insert the file name in the sub node 
				sub_node *s_temp = s_new;							// table the temp variable 
				m_new -> sub_link = s_new;							// establish the link between the sub node to the main node. 
				s_new -> word_count = atoi(strtok(NULL, ";"));		// extract the word count 
				s_temp -> sub_link = s_new;							// update the link of the sub node with new node.
				s_temp = s_new;										// update the temp link with the new sub node 
				for(int i=1; i < m_new -> file_count; i++)			// for loop to create the sub nodes 
				{
					strcpy(file_name, strtok(NULL, ";"));			// extract the file name 
					sub_node *s_new = creat_sub_node(file_name);	// create the sub node insert the file name 
					s_new -> word_count = atoi(strtok(NULL, ";"));	// extract word count 
					s_temp -> sub_link = s_new;						// establish the link  with thw sub node
					s_temp = s_new;									// stemp with sub node.
				}
				s_temp -> sub_link = NULL;							// update the sun link with null
			}
			else													// if the head is not equal to null
			{
				main_node *m_temp = hash[key].link;					// create temp variable 
				main_node *m_prev = m_temp;							// create prev varible assign to the temp 
				while(m_temp)										// travers the mptemp not equal to null
				{
					if(m_temp -> main_link == NULL)					// check the main link is eqaul  null
					{
						strcpy( word, strtok(NULL, ";"));						// extract the word 
						main_node *m_new = creat_main_node(word);				// insert the word extracted 	
						m_new -> file_count = atoi(strtok(NULL, ";")); 			// extract the file count and store
						strcpy(file_name, strtok(NULL, ";"));					// extract the file name	
						sub_node *s_new = creat_sub_node(file_name);			// create the sub node and insert the file name 
						sub_node *s_temp = s_new;								// assign the temp to sub node
						m_new -> sub_link = s_new;								// assign the sub node to the main node. 
						s_new -> word_count = atoi(strtok(NULL, ";"));			// extract the word count 
						s_temp -> sub_link = s_new;								// update the temp with the sub node to new node
						s_temp = s_new;											// update temp  to sub node 
						for(int i=1; i < m_new -> file_count; i++)			// for loop to create the sub nodes 
						{
							strcpy(file_name, strtok(NULL, ";"));			// extract the file name 
							sub_node *s_new = creat_sub_node(file_name);	// create the sub node insert the file name 
							s_new -> word_count = atoi(strtok(NULL, ";"));	// extract word count 
							s_temp -> sub_link = s_new;						// establish the link  with thw sub node
							s_temp = s_new;									// stemp with sub node.
						}
						s_temp -> sub_link = NULL;							// update the sun link with null

						s_temp -> sub_link = NULL ; // update the sub link with the null
						break; 						// break to come out of the loop 
					}
					m_temp = m_temp -> main_link; // update the temp with the main link. 
				}
			}
		}
		return SUCCESS;
	}
}
