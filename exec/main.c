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
	else
		execve(path, args, env);
}

void    redir(t_pipe *pipex, char *av, char **env, int out)
{
	pipex->child = fork();
	if (pipex->child < 0)
		write(1, "error\n", 6);
	if (pipex->child == 0)
	{
		close(pipex->array->tab[0]);
		dup2(out, STDOUT_FILENO);
		close(out);
		exec(av, env);
	}
	else
	{
		close(out);
		dup2(pipex->array->tab[0], STDIN_FILENO);
		close(pipex->array->tab[0]);
		waitpid(pipex->child, NULL, 0);
	}
}

void	nbr(t_pipe *pipex, int ac, char **av, char **env)
{
	int	i;

	i = 2;
	while (i < ac - 2)
	{
		if (pipe(pipex->array->tab) < 0)
			return ;
		redir(pipex, av[i], env, pipex->array->tab[1]);
		++i;
	}
	redir(pipex, av[i], env, pipex->fd_out);

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
	t_pipe  pipex;
	t_mng	mng;
	// t_pipe  head;
	int		i;
	int		door_fd[2];

	i = 2;
	create_lst(ac, &pipex, &mng);
	drive_fd(door_fd[0], av[1], 0);
	drive_fd(door_fd[1], av[ac - 1], 1);
	nbr(&pipex, ac, av, env);
	return (0);
}