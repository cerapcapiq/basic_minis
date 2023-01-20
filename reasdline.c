#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#define _XOPEN_SOURCE 600
#include <sys/wait.h>

#include <readline/readline.h>
#include <readline/history.h>
#include <string.h>
#include <signal.h>

//char *lineptr;

char* ft_join ( char *s1,  char *s2)
{
	char *result = malloc(strlen(s1) + strlen(s2) + 1);

	if (result)
	{
		strcpy(result, s1);
		strcat(result, s2);
	}
	return result;
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
    delete(lineptr, "echo ");
    printf("%s\n", lineptr);
}

void normal_ls(char *lineptr)
{
	char cmd[] = "usr//bin/ls";

	char *arg[] = {"ls", NULL};
	char *env[] = {NULL};
	
	printf("execve %s\n", cmd);
	execve(cmd, arg, env);

	printf("oop");
   lineptr = readline("minishell>");

}


void built_inwc(char *lineptr)
{
	int fd;
	int fds[2];
	int res;

	char cmd[] = "/usr/bin/wc";
	char *arg[] = {"wc",lineptr, NULL};
	char *env[] = {NULL};

	int pip = (*cmd);
	int pid = fork();

	if (!pid)
	{
		printf("%d\n", pid);
		execve(cmd, arg, env);
		//kill(0, SIGKILL);
		
	}
	if (waitpid(pid, &res, 0) == -1)
	printf("error");
}



void built_ingrep(char *lineptr)
{
	char cmd[] = "/usr/bin/grep";

	char *arg[] = {"grep","/Users/abasarud/desktop/mine_testing/text.txt", NULL};
	char *env[] = {NULL};
	
	printf("execve %s\n", cmd);
	if (execve(cmd, arg, env) == -1)
			{
			perror("error");
			}
	printf("oop");

}

void built_incat(char *path)
{
	int fd;
	int fds[2];
	int res;
	int pidd = getpid();

	char cmd[] = "/bin/cat";
	char *arg[] = {"/bin/cat",path, NULL};
	char *env[] = {NULL};

	printf("this is parent pid , so not zero => %d\n", pidd);
	int pip = (*cmd);
	int pid = fork();

	if (!pid)
	{
		printf("if inside child process should be zero => %d\n", pid);
		execve(cmd, arg, env);
		//kill(0, SIGKILL);
		
	}

	printf("error");

}

void ft_cat(char *lineptr) 
{
    delete(lineptr, "cat ");
   built_incat(lineptr);
    
}

void ft_wc(char *lineptr) 
{
    delete(lineptr, "wc ");
   built_inwc(lineptr);
    
}

void getenv_ls(char *lineptr)
{
char    *str;
char ** res  = NULL;
char *  p ;
int n_spaces = 0, i;

char *path;

 path = getenv("PATH");
    str = strdup(path);



p    = strtok (str, ":");

while (p) {
  res = realloc (res, sizeof (char*) * ++n_spaces);

  if (res == NULL)
    exit (-1);

  res[n_spaces-1] = p;

  p = strtok (NULL, ":");
}

res = realloc (res, sizeof (char*) * (n_spaces+1));
res[n_spaces] = 0;
for (i = 0; i < (n_spaces); ++i)
{
	res[i] = ft_join(res[i], "/");
  printf ("res[%d] = %s\n", i, res[i]);
}


char *cmd;
char *cpy;
char *argv[] = {lineptr, NULL};
char *env[] = {NULL};

	int pip = (*cmd);
	int pid = fork();

	if (!pid)
	{
		printf("%d\n", pid);
		for (i = 0; i < (n_spaces); i++)
		{
			cpy = strcat(res[i], lineptr);
			char *cmd = cpy;
		if (execve(cmd, argv, env))
		//	printf("this is the %s", cmd);
		printf ("res[%d] = %s\n", i, res[i]);
	
	
		
	}
	free(res);
}
}


int main()
{
	char *lineptr;
  char s[100];

    while (1)
    {
        lineptr = readline("minishell>");
        if (strlen(lineptr)>0) {add_history(lineptr);}
        if (!strcmp(lineptr, "cd")) {chdir("..");printf("kekl\n");}
     if (!strcmp(lineptr, "ls")) {getenv_ls(lineptr);}
        if (strstr(lineptr, "wc")) {ft_wc(lineptr);}
        if (strstr(lineptr, "cat ")) {ft_cat(lineptr);}
      //if (!strcmp(lineptr, "ls")) {normal_ls(lineptr);} //  without fork
       
        if (!strcmp(lineptr, "pwd")) {printf("%s\n", getcwd(s, 100));}
        if (strstr(lineptr, "echo ")) { ft_echo(lineptr);}
        if(!strcmp(lineptr, "exit")) { break; }
	}
}