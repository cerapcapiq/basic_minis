#include <stdio.h>
#include <string.h>
/*
char *ft_env(char *line)
{
    char * s1 = strdup(line);
    return s1;
}


char *remove_quote(char *line)
{
int j = 0;
int lineLength = strlen(line);
for (int i = 0; i < lineLength; i++)
{
    if (line[i] == '$')
    {
        
            break;
    }
    else if (line[i] != '"' || line[i] != '\'')
        line[j++] = line[i];
}
line[j] = '\0';
return line;
}

/*int parser_delegator(char *input, t_data *data, int piped)
{
	int		i;

	i = 0
	while (input[i])
	{
		if (input[i] == '"')
		{
			i++;
            if (input[i] == '"')

			while (input[i] != '"')
			{
				slash_count = 0;
				while (input[i] == '\\' && ++i)
					slash_count++;
				if (input[i] == '$' && !(slash_count % 2))
					check_env_variable(&input, &i, data);
				if (slash_count && !(slash_count % 2))
					i--;
				i++;
			}
		}
		if (check_special(&input, &i, data))
			return (0);
	}
	return (handle_basic(input, data, piped));
}
*/

int ft_detect_dollar(char* s1)
{
    int i = 0;
    while (s1[i])
    { 
        if (s1[i] == '$')
        return 1;
        i++;
    }
    return 0;

}

char *remove_real(char *s1)
{
    int i = 0;
    if (s1[i] == '"' && s1[strlen(s1) - 1] == '"' && !ft_detect_dollar(s1)) 
    {
        s1[strlen(s1) - 1] = '\0';
        return s1 + 1;
    }
    else if (s1[0] == '\'' && s1[strlen(s1) - 1] == '\'')
    {
        s1[strlen(s1) - 1] = '\0';
        return s1 + 1;
    }
    return s1;
}



int main()
{
    char str[] = "\"$HEllo World\"";
    char s2[] = "\'USER\'";
    char *cpy;
    char *cpy2;
    printf("%s\n", str);
    printf("%s\n", s2);
    cpy = remove_real(str);
    cpy2 = remove_real(s2);
    printf("%s\n", cpy);
     printf("%s\n", cpy2);
}



//if (single quote) -> arg -> strip remove_quote

//if (double quote) -> if $ -> exec(env)
                //-> else -> arg -> strip remove_quote