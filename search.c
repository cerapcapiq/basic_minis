#include "link.h"


void deleteEnd (struct node *head)
{
  struct node *temp = head;
  struct node *previous;

  // if there are no nodes in Linked List can't delete
  if (head == NULL)
    {
      printf ("Linked List Empty, nothing to delete");
      return;
    }

  // if Linked List has only 1 node
  if (temp->nxtpointer == NULL)
    {
      printf ("%s deleted\n", (head)->data);
      head = NULL;
      return;
    }

  // else traverse to the last node
  while (temp -> nxtpointer != NULL)
    {
      // store previous link node as we need to change its nxtpointer val
      previous = temp;
      temp = temp->nxtpointer;
    }
  // Curr assign 2nd last node's nxtpointer to Null
  previous ->nxtpointer = NULL;
  // delete the last node
  printf ("%s deleted\n", temp->data);
  free (temp);
  // 2nd last now becomes the last node
}

void delete_first(struct node* head)
{
    struct node *delete;

    if (head == NULL)
        printf("error");
  
    // Move the head pointer to the nxtpointer node
    else {

    
    delete = head;
    head = head->nxtpointer;
    }
    free(delete);
    //display_node();
}


void searchList(struct node *head)
 {
        char *contactName;
        int i = 1;

        contactName = readline("what is : ");
        struct node *temp = head;
        printf("\nSearch Contact : \n");
        while (temp != NULL)
        {
            if (strcmp(temp->data, contactName) == 0)
            {
                printf("Contact Name : %s\n",temp->data);
                printf("saved in the %d th place\n", i);
            }
            temp = temp->nxtpointer;
            i++;
        }
 }


void delete_node(char *lineptr, struct node *head)
{
    if (head == NULL)
        return;
    struct node* temp = head; // Creating a temporary
                              // variable pointing to head
    int j;
    int i;
    printf(" is %s", lineptr);
    j = atoi(lineptr);

    if (j == 1) 
    {
        printf("\nFirst element deleted is : %s\n", temp->data);
        head = temp->nxtpointer; // Advancing the head pointer
        //temp->nxtpointer = NULL;
        free(temp); // Node is deleted
    }
    else {
        for (i = 2; i < j; i++) {
            temp = temp->nxtpointer;
        }
        // Now temp pointer points to the previous node of
        // the node to be deleted
        struct node* del
            = temp->nxtpointer; // del pointer points to the node
                          // to be deleted
        temp->nxtpointer = temp->nxtpointer->nxtpointer;
        printf("\nElement deleted is : %s\n", del->data);
        del->nxtpointer = NULL;
        free(del); // Node is deleted
    }
    printf("\nUpdated Linked List is : \n");
    return;
}