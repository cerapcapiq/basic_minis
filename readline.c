 #include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include <readline/readline.h>
#include <readline/history.h>
#include <string.h>

char *lineptr;

char *ft_advance(char *str)
{

  str++;
  return (str);
}

void ft_quote(char *lineptr)
{
  int i;
  char *str;
  i =  strlen(lineptr);

  str= lineptr;

  int j = 0;

  while (str[j] != '\0')
  {
    if (str[j] == '"')
     str = ft_advance(str);
     //j++;
   write(1, &str[j], 1);
   j++;
  }
  printf("okay\n");
}

void delete(char string[], char substr[])
{
  int i = 0;

  int string_length = strlen(string);
  int substr_length = strlen(substr);
  
  while (i < string_length)
  {
    if (strstr(&string[i], substr) == &string[i])
    {
      string_length -= substr_length;
      for (int j = i; j < string_length; j++)
        string[j] = string[j + substr_length];
    }
    else i++;
  }
  string[i] = '\0'; 
}



void ft_echo(char *lineptr) 
{
  char *str;
    delete(lineptr, "echo ");

  str = lineptr;
  int j = 0;

  while (str[j] != '\0')
  {
    if (str[j] == '"')
      str = ft_advance(str);
    write(1, &str[j], 1);
    j++;
  }
}

char *ft_var(char * lineptr)
{
  char *str[3];
  char *last ;
  int i = 0;


  str[0] = strtok(lineptr, "=");
  while (str[i] != NULL)
  {
    i++;
    str[i]=strtok(NULL," ");
  }

  printf("\n");
  last = str[i-1];
  return (last);
}

int main()
{
  char *str;
    while (1)
    {
        lineptr = readline("minishell>");
        if (strlen(lineptr)>0) {add_history(lineptr);}
       if (strstr(lineptr, "echo ") || (strstr(lineptr, "echo ") && strstr(lineptr, "\""))) { ft_echo(lineptr);}
       // if (strstr(lineptr, "\"") && strstr(lineptr, "echo ") == 0) {ft_quote(lineptr);}
        if (strstr(lineptr, "=")) { str = ft_var(lineptr)
;
        printf("arg return is %s\n", str);
        }
        if(!strcmp(lineptr, "exit")) { break; }
	}
}