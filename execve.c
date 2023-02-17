
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>


char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = (char *)malloc(sizeof(*s1) * (strlen(s1) + strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str[j++] = s2[i];
		i++;
	}
	str[j] = 0;
	return (str);
}

size_t	ft_strlcpy(char *dst, char const *src, size_t size)
{
	size_t			i;
	unsigned int	res;

	i = 0;
	res = 0;
	while (src[i] != '\0')
		i++;
	if (size != 0)
	{
		while (src[res] != '\0' && res < (size - 1))
		{
			dst[res] = src[res];
			res++;
		}
		dst[res] = '\0';
	}
	return (i);
}

static char	**ft_malloc_error(char **tab)
{
	unsigned int	i;
	i = 0;

	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static unsigned int	ft_get_nb_strs(char const *s, char c)
{
	unsigned int	i;
	unsigned int	nb_strs;

	i = 0;
	nb_strs = 0;
	if (!s[0])
		return (0);
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			nb_strs++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		nb_strs++;
	return (nb_strs);
}


static void	ft_get_next_str(char **next_str, unsigned int *next_str_len, char c)
{
	unsigned int	i;

	*next_str += *next_str_len;
	*next_str_len = 0;
	i = 0;
	while (**next_str && **next_str == c)
		(*next_str)++;
	while ((*next_str)[i])
	{
		if ((*next_str)[i] == c)
			return ;
		(*next_str_len)++;
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char			**tab;
	char			*next_str;
	unsigned int	next_str_len;
	unsigned int	nb_strs;
	unsigned int	i;

	if (!s)
		return (NULL);
	nb_strs = ft_get_nb_strs(s, c);
	if (!(tab = malloc(sizeof(char *) * (nb_strs + 1))))
		return (NULL);
	i = 0;
	next_str = (char *)s;
	next_str_len = 0;
	while (i < nb_strs)
	{
		ft_get_next_str(&next_str, &next_str_len, c);
		if (!(tab[i] = malloc(sizeof(char) * (next_str_len + 1))))
			return (ft_malloc_error(tab));
		ft_strlcpy(tab[i], next_str, next_str_len + 1);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}


int	it_works(char *cmd_path)
{
	struct stat	buffer;

	if (stat(cmd_path, &buffer) != 0)
		return (0);
	if ((buffer.st_mode & S_IFMT) == S_IFDIR)
		return (0);
	if ((buffer.st_mode & S_IXUSR))
		return (1);
	return (0);
}


char *ft_getpath(char **av)
{
	char **split;
	int i = 0;
	split = NULL;

       printf("not okay\n");

	char *path = getenv("PATH");

	split = ft_split(path + 5, ':');
	while (split[i] != NULL)
	{
		split[i] = ft_strjoin(split[i], "/");
		split[i] = ft_strjoin(split[i], av[0]);
		if (it_works(split[i]) == 1)
        {
            return (split[i]);
			break;
        }
		i++;
	}

}
	
int ft_ex(char **argv, char **envp, int i)
{
	int	res;

    printf("okay\n");
	int pid = fork();
	if (!pid)
	{
		argv[i] = 0;
		execve(*argv, argv, envp);
		return printf("error");
	}
	if (waitpid(pid, &res, 0) == -1)
		return printf("error");
	return WIFEXITED(res) && WEXITSTATUS(res);
}

int call_cmd(char **av)
{
	int i = 0;
	int j = 0;
	char *env[100];

	printf("av is %s\n", *av);
	*env = ft_getpath(av);

    printf("env is %s", )

	while (av[i] && av[++i])
	{
		av = av + i;
		i = 0;
		while (av[i])
			i++;
		if (i)
			j = ft_ex(av, env, i);

	}
	return j;
}

int main(int argc, char **argv)
{
    int i = 0;
    while (argv[1][i] && argv[1][i++])
    {
	    call_cmd(&argv[1]);
        
    }
    printf("why is %s \n", *argv);

}
