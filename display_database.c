#include "main.h"
#include <stdio.h>
Status display_database(HT *hash)
{
	main_node *mtemp;					// declare the main node temp variable 
	sub_node *stemp;					// dealare the sub node temp varibale 
	int flag = 0;						//  delcare the flag == 0

	printf("[INDEX]\t    	   [WORD]    %17s %15s %25s\n", "Filecount", "Filename", "WordCount");	// display the content using the stdio formats 
	for(int i = 0; i < 27; i++)										// loop to travers with till end of the hash table 
	{
		if(hash[i].link != NULL)									// check for the hash table index is null or not 
		{
			mtemp = hash[i].link;									// assign the temp varible to the hash table of index value .

			while(mtemp)											// travers the main node temp  till the null 
			{
				printf(" [%-2d] %17s %17d ", i, mtemp -> word, mtemp -> file_count);		// print the content in the given format 
				stemp = mtemp -> sub_link;													// upadte the sub temp with the main node sub link part 
				while(stemp)																// travers the sub node part till the null
				{
					printf("%20s %20d", stemp -> file_name, stemp -> word_count);			// display the sub nide content 
					stemp = stemp -> sub_link;												// upadte the sub node part to next sub node part. 
				}
				printf("\n");																// print the new line part 
				mtemp = mtemp -> main_link;													// update the main node to next main node part 
			}
			
			flag = 1;																		// if the  hash table index is not equal to null then the flag  is 1
		}
	}
	if(flag == 0)																			// chech the flag part is 1 or 0
	{
		return FAILURE;																		// if flag is 0 then return failure 
	}
	else
	{
		return SUCCESS;																		// if the flag is 1 then return success
	}
}
