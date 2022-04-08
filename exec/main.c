#include "execute.h"

char	**get_path(char **env)
{
	char	**paths;

	while (ft_strncmp("PATH", *env, 4))
		++env;
	paths = ft_split(*env + 5, ':');
	return (paths);
}

char	*get_cmd_opt(char *cmd, char **env)
{
	char	**paths;
	char	*good_path;

	paths = get_path(env);
	while (*paths)
	{
		good_path = ft_strjoin_l(*paths, cmd);
		if (access(good_path, 0) == 0)
        	return (good_path);
        free(good_path);
		++paths;
	}
	return (NULL);
}

int main(int ac, char **av, char **env)
{
	int	i = 0;
    char    *path;
    char    *cmd[3];

	if (ac < 2)
	{
		write(1, "Number of arguments is wrong\n", 29);
		exit(2);
	}
	while (i < ac)
	{
		cmd[i] = av[i + 1];
		++i;
	}
    cmd[i] = NULL;
    path = get_cmd_opt(av[1], env);
    if  (!execve(path, cmd, env))
        write(1, "NULL\n", 5);
    return (0);
}