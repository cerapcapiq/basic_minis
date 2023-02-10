#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <string.h>

char *nodedata;

struct node
{
  char *data;
  struct node *nxtpointer;
};

struct node *startnode;

static void createList(int nodes);
static void display_node();
void searchList();


int main()
{
  int numbernode;

  printf ("how many arg");
  scanf("%d", &numbernode);

  
  createList(numbernode);
  display_node();
 

}

static void createList(int nodes)
{
  struct node *new;
  struct node *buffer;

  //int nodedata;
  int nodecounter;

  //alloc memory for first node
  startnode = (struct node*)malloc(sizeof(struct node));


  printf("input data for arg 1: ");
  
  nodedata = readline("env var =" );

  
  startnode->data = nodedata; // save input from scanf to startnode
  startnode->nxtpointer = NULL; // next pointer to null (as there is no next for now)
  buffer = startnode;  // keep address to link to next node

  for(nodecounter = 2; nodecounter<=nodes; nodecounter++)
        {

            new = (struct node*)malloc(sizeof(struct node));

            //exit if new node cannot be allocated
            if(new == NULL)
            {
                printf("Memory cannot be allocated.");
                break;
            }
            else
            {
                printf("input data for arg %d: ",nodecounter);
                nodedata = readline("env var =");

                new->data = nodedata;
                new->nxtpointer = NULL;

                //Link the previous node to the current node
                buffer->nxtpointer = new;
                //copies address of current node
                buffer = buffer->nxtpointer;
            }

        }
    
   searchList();
}


static void display_node()
{
    struct node *buffer;
    buffer = startnode;
    //exit if it is empty
    if(buffer == NULL){
        printf("List is empyt");

    }
    else{
        //check if the current node is empty
        while (buffer != NULL)
        {
            //PRINT THE DATA OF CRRENT NODE
            printf("DATA: %s \n", buffer->data);
            //go to the next node
            buffer = buffer->nxtpointer;
        }
    }
}

void searchList()
    {
        char *contactName;
        int i = 1;

        contactName = readline("what is : ");
        struct node *temp = startnode;
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
        if (strstr(contactName, "unset"))
        {
            
        }
    }










