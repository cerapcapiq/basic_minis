 #include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include <readline/readline.h>
#include <readline/history.h>
#include <string.h>
#include <signal.h>

char *lineptr;

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
	char cmd[] = "/bin/ls";

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
	char *arg[] = {"/usr/bin/wc",lineptr, NULL};
	char *env[] = {NULL};

	int pip = (*cmd);
	int pid = fork();

	if (!pid)
	{
		printf("%d\n", pid);
		execve(cmd, arg, env);
		kill(0, SIGKILL);
		
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
		kill(0, SIGKILL);
		
	}

	printf("error");

}

int built_inls(char *lineptr)
{
	int fd;
	int fds[2];
	int res;

	char cmd[] = "/bin/ls";
	char *arg[] = {"ls", NULL};
	char *env[] = {NULL};

	int pip = (*cmd);
	int pid = fork();

	if (!pid)
	{
		printf("%d\n", pid);
		execve(cmd, arg, env);
		kill(0, SIGKILL);
		
	}
	if (waitpid(pid, &res, 0) == -1)
	printf("error");
  return WIFEXITED(res) && WEXITSTATUS(res);
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

int main()
{
  char s[100];

    while (1)
    {
        lineptr = readline("minishell>");
        if (strlen(lineptr)>0) {add_history(lineptr);}
        if (!strcmp(lineptr, "cd")) {chdir("..");printf("kekl\n");}
     if (!strcmp(lineptr, "ls")) {built_inls(lineptr);}
        if (strstr(lineptr, "wc")) {ft_wc(lineptr);}
        if (strstr(lineptr, "cat ")) {ft_cat(lineptr);}
      //if (!strcmp(lineptr, "ls")) {normal_ls(lineptr);} //  without fork
       
        if (!strcmp(lineptr, "pwd")) {printf("%s\n", getcwd(s, 100));}
        if (strstr(lineptr, "echo ")) { ft_echo(lineptr);}
        if(!strcmp(lineptr, "exit")) { break; }
	}
}