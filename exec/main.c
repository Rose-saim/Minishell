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

void	exec(char *av, char **env)
{
	int		ret;
	char	*path;
	char	**args;

	ret = 0;
	args = ft_split(av, ' ');
	path = get_cmd_opt(args[0], env);
	if (!path)	
	{
		//Error
		puts("eror path");
		return ;
	}
	if (execve(path, args, env) == -1)
	{
		puts("Error command");
		return ;
	}
}

void    redir(t_pipe *pipex, char *av, char **env)
{
	pipex->child = fork();
	if (pipex->child == 0)
	{
		close(pipex->door[0]);
		dup2(pipex->door[1], 1);
		close(pipex->door[1]);
		exec(av, env);
	}
	else
	{
		close(pipex->door[1]);
		dup2(pipex->door[0], 0);
		close(pipex->door[0]);
	}
}



void	last_child(t_pipe *pipex, int ac, char **av, char **env)
{
	int door[2];
	int ret;

	ret = pipe(door);
	if (ret < 0)
		printf("eror redir");
	pipex->child = fork();
	if (pipex->child == 0)
	{
		close(door[0]);
		dup2(pipex->fd_out, 1);
		close(pipex->fd_out);
		exec(av[ac - 2], env);
	}
	else
	{
		close(door[1]);
		dup2(door[0], 0);
		close(door[0]);
	}

}

void	free_lst(t_pipe *head)
{
	while (head)
	{
		free(head);
		head = head->next;
	}
}

void	wait_lst(t_pipe *pipex)
{
	while (pipex)
	{
		waitpid(pipex->child, NULL, 0);
		pipex = pipex->next;
	}
}

int main(int ac, char **av, char **env)
{
	t_pipe  *pipex;
	t_pipe  *head;
	int		i;
	int		fd_out;
	int		door_fd[2];

	pipex = NULL;
	i = 2;
	pipex = create_lst(ac, pipex);
	loop_fd(pipex, ac);
	puts("lol1");
	drive_fd(door_fd, av[1], 0);
	head = pipex;
	while (i < ac - 2)
	{
		redir(pipex, av[i], env);
		pipex = pipex->next;
		++i;
	}
	puts("lol2");
	drive_fd(door_fd, av[ac - 1], 1);
	last_child(pipex, ac, av, env);
	pipex = head;
	wait_lst(head);
	puts("lol3");
	free_lst(pipex);
	return (0);
}