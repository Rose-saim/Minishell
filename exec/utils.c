#include "pipe.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

char	*ft_strjoin_l(char *path, char *cmd)
{
	char	*ret_path;

	ret_path = (char *)malloc(sizeof(char) * ft_strlen(path) + ft_strlen(cmd) + 2);
	if (!ret_path)
		return (NULL);
	int	i;

	i = 0;
	while (path[i])
	{
		ret_path[i] = path[i];
		++i;
	}
	ret_path[i++] = '/';
	int	j;
	
	j = 0;
	while (cmd[j])
	{
		ret_path[i + j] = cmd[j];
		++j;
	}
	ret_path[i + j] = '\0';
	return (ret_path);
}