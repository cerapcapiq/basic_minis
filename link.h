#ifndef LINK_H
# define LINK_H

#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <string.h>



struct node
{
  char *data;
  struct node *nxtpointer;
};//*head = NULL;

//struct node *head = NULL;

//static void createList(int nodes);
 //void display_node();
void searchList(struct node *head);
void delete_first(struct node* head);
void deleteEnd(struct node *head);

void delete_node(char *lineptr, struct node* head);

#endif