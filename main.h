#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>

// enums for the status
typedef enum {
SUCCESS = 0,
FAILURE = -1
}Status;


// structure for the project
typedef struct node
{
	char file_name[20];
	struct node * link;	
}Slist;

typedef struct main_node
{
	int file_count;
	char word[10];
	struct sub_node * sub_link;
	struct main_node *main_link;
}main_node;

typedef struct sub_node
{
	int word_count;
	char file_name[20];
	struct sub_node * sub_link;
}sub_node;

typedef struct hash
{
	int index;
	struct main_node * link;
}HT;


// funtion prototype
Status check_empty(char * );
Status check_file(char *);
void create_hashtable(HT *);
Status insert_last(Slist ** , char *);

main_node *creat_main_node(char *);
sub_node *creat_sub_node(char *);

Status read_and_validate(int argc, char *argv[], Slist **head);
Status create_database(HT *hash_table, Slist *head);
Status display_database(HT *);
Status search_database(HT *, char *);
Status save_database(HT *);
Status update_database(HT *, char*);


#endif
