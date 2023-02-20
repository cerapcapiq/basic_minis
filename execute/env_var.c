
#include "../include/minishell.h"




struct node* createList(struct node **head, char *lineptr)
{
  char *nodedata = lineptr;
  struct node *new = malloc(sizeof(struct node));
  new->data = nodedata;
  new->nxtpointer = NULL;

  if (*head == NULL)
    *head = new;
  else
  {
    struct node *last = *head;

    while (last->nxtpointer != NULL)
    {
        last = last->nxtpointer;
    }
   last->nxtpointer = new;  // keep address to link to next node
  }
  return (*head);
}

struct node* display_node(struct node *head)
{
    struct node* temp; 
    temp = head; // temp points to head;
    printf("\n");
    if (temp == NULL)
        printf(" NULL\n\n");
    while (temp != NULL) {
        if (temp->nxtpointer == NULL) {
            printf(" %s->NULL", temp->data);
        }
        else {
            printf(" %s->", temp->data);
        }
        temp = temp->nxtpointer; // Traversing the List till end
    }
    printf("\n\n");
    return head;
}

char *get_name(char *linestr)
{
    char *str = linestr;
    char *cpy;

    printf("%s\n", str);
    int i = 0;
    while (str[i] != '=')
        i++;
    cpy = ft_substr(str, 0, i);
    printf ("the $var is %s\n", cpy); 
    return (cpy);

}

void get_arg(char *lineptr)
{ 
    char *str = lineptr;
    char *arg = str;
    size_t j = 0;
    char after[j];

    if ((arg = ft_strchr(str, '='))) 
    {
        size_t len = ft_strlen (++arg);
        if (len > j - 1) 
        {
            printf("error");
        } 
        memcpy (after, arg, len + 1);
        printf ("the arg(value) is %s\n", arg);    
    }
}


void pass_to_linked(char *argv)
{
    struct node *temp = NULL;
    //if (head != NULL)
     //   temp = head;
     printf("in inked list\n");
     printf("data %s\n", head->data);
     printf("data  temp %s\n", temp->data);
    temp = createList(&head, argv);
    temp = display_node(temp);
}

/*
int ft_var_lmain(char *argv)
{
    struct node *head = NULL;

    head = ft_var(argv);
    return 1;
}*/


int ft_var_main(char *argv)
{
if (strstr(argv, "="))
    {
        get_name(argv);
        get_arg(argv);
        pass_to_linked(argv);
    }
    return 1;

}