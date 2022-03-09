#include "pipe.h"

int    open_file(char *av, int mode)
{
	int	fd;

	if (mode == 0)
	{
		if (access(av, F_OK))
		{
			write(1, "Inexist fd\n", 13);
		}
		else
		{
			fd = open(av, O_RDONLY);
			printf("SUCESS %d\n", fd); 
		}
	}
	else
	{
		fd = open(av, O_CREAT | O_WRONLY | O_TRUNC,
									 S_IRUSR, S_IWUSR, S_IRGRP, S_IWGRP, S_IROTH);
		printf("%d\n", fd); 
	}
	dup2(fd, mode);
	close(fd);
	return (fd);
}

char	**get_path(char **env)
{
	char	**paths;

	while (!ft_strncmp(env, "PATH" + 4))
		++env;
	paths = ft_split(env, ':');
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
		if (access(*paths, F_OK))
			return (good_path);
		free(good_path);
		++paths;
	}
	return (NULL);
}

void	exec(char *av, char **env)
{
	char	*path;
	char	**args;

	args = ft_split(av, ' ');
	path = get_cmd_opt(args[0], env);
	if (!path)
		//Error
	execve(path, args, env);
}

void    redir(t_pipe *pipex, char *av, char **env)
{
	int door[2];
	int ret;

	ret = pipe(door);
	if (ret < 0)
		printf("eror");
	pipex->child = fork();
	if (pipex->child == 0)
	{
		close(door[0]);
		dup2(door[1], 1);
		close(door[1]);
		exec(av, env);
	}
	else
	{
		close(door[1]);
		dup2(door[0], 0);
		close(door[0]);
	}
}

int main(int ac, char **av, char **env)
{
	int fd_in;
	int fd_out;
	t_pipe  pipe;
	int     i;

	i = 0;
	fd_in = open_file(av[0], 0);
	redir(&pipe, av[i], env);
	fd_out = open_file(av[ac - 1], 1);
	return (0);
}