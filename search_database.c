#include "main.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Status search_database(HT * hash, char *buffer)
{
	int index; // to store the index value we declare the index variable 
    
	if (buffer[0] >= 'A' && buffer[0] <= 'Z')		// the first varaible that its is lower case if not then convert it to the lowercase 
	{
		index = buffer[0] % 65;   // to convert lower case
	}

	else if (buffer[0] >= 'a' && buffer[0] <= 'z')	
	{
		index = buffer[0] % 97;
	}
	else
	{
		index = 26;				// else to store the spical character. 
	}
	
	if(hash[index].link != NULL)	// chech the hash table is null no not 
	{
		main_node *mtemp = hash[index].link;	// create the temp varible and assign hash table index value 
		while(mtemp)
		{
			if(strcmp(mtemp -> word,buffer) == SUCCESS) // condiion to check to check word is same in buffer
			{
				sub_node *stemp = mtemp -> sub_link; // upadte the main node sub link part to link with sub node 
				while(stemp)
				{
					printf("[WORD] = %s\t [FILECOUNT] = %d\t [WORDCOUNT] = %d\t [FILENAME] = %s\n", buffer, mtemp -> file_count, stemp -> word_count, stemp -> file_name); // print the content of the file 
					stemp  = stemp -> sub_link;	// update the sub node to next node
				}
				return SUCCESS;
			}
			mtemp = mtemp -> main_link;					// update the main node to next node 
		}
	}
	else
	{
		return FAILURE;     // else return failure to main function 
	}
}
