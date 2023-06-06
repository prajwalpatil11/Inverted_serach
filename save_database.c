#include <stdio.h>
#include <string.h>
#include "main.h"
Status save_database(HT *hashtable)
{
	char file[20];									// declare the char array 
	printf("Enter the Filename : ");				// print the statment
	scanf("%s", file);								// read the file name 

	if(!(strcmp(strstr(file,"."), ".txt")))			// check file is txt file  
	{
		FILE *fptr = fopen(file, "w");  			// open file using the file ponter 
		
		for(int i = 0; i <= 26; i++)				// loop to travers through the hash table  
		{
			if(hashtable[i].link != NULL)			// chech for the hash table index is not equal to null 
			{
				main_node *mtemp = hashtable[i].link;	// create the variabe temp and give the hash index to the temp 
				sub_node * stemp = mtemp -> sub_link;	// create the temp for the sub node  and assign the sub node link from the main node link 
				while(mtemp)							// travers through the main node tiil the null
				{
					fprintf(fptr,"#%d;%s;%d;", i, mtemp -> word, mtemp -> file_count);	// to print the the content of the main node 
					while(stemp) 														// travers the sub node till the null 
					{
						fprintf(fptr,"%s;%d;", stemp -> file_name, stemp -> word_count);	// print the content of the sub node 

						stemp = stemp -> sub_link;									// update the sub to next node
					}
					fprintf(fptr,"#\n");											// print the new line 
					mtemp = mtemp -> main_link;										// update the main node to the next main node
				}
			}
		}
		fclose(fptr);															// close the file opened before the return 
		return SUCCESS;
	}
	else
	{
		printf("ERROR : File Doesn't Exist");									// to print if file dosent exist.
	}
}
