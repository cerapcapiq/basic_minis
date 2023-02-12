#include "link.h"

static void createList(int nodes, struct node * head);
 static void display_node();
struct node *head;
int main()
{
  int numbernode;
  char *lineptr;

  printf ("how many arg");
  scanf("%d", &numbernode);
  createList(numbernode, head);
  display_node();
  lineptr = readline("delete what number : ?");
  delete_node(lineptr, head);
//else 
//printf("not yet\n");
display_node();

}

static void createList(int nodes, struct node *head)
{
  struct node *new;
  struct node *buffer;

  int nodecounter;
  //alloc memory for first node
 head = (struct node*)malloc(sizeof(struct node));


  printf("input data for arg 1: ");
  
 char * nodedata = readline("env var =" );

  
  head->data = nodedata; // save input from scanf to head
  head->nxtpointer = NULL; // next pointer to null (as there is no next for now)
  buffer = head;  // keep address to link to next node

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
    
    searchList(head);
}


/* void display_node()
{
    printf("entering diplay ...\n");
    struct node *buffer;
    int i = 1;
    
        buffer = head;
        //check if the current node is empty
        if (buffer == NULL)
            buffer = buffer->nxtpointer;
        while (buffer != NULL)
        {
            //PRINT THE DATA OF CRRENT NODE
            printf("DATA %d is : %s \n",i, buffer->data);
            //go to the next node
            buffer = buffer->nxtpointer;
            i++;
        }
    }


*/

void display_node()
{
    printf("ada\n");
    struct node* temp; // Creating a temporary pointer to
                       // the structure
    temp = head; // temp points to head;
    if (temp == NULL)
        printf("NULL\n\n");
    while (temp != NULL) {
        if (temp->nxtpointer == NULL) {
            printf(" %s->NULL", temp->data);
        }
        else {
            printf(" %s->", temp->data);
        }
        temp = temp->nxtpointer; // Traversing the List till end
    }
    printf("\n");
    return;
}


