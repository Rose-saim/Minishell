#include "pipe.h"

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
