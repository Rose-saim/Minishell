#include "pipe.h"

void	exec_cmds(t_pipe *pipex, int ac, char **av, char **env)
{
	t_pipe	*head;
	int	i;

	i = 2;
	head = pipex;
	while (i < ac - 2)
	{
		if (pipe(pipex->array->tab) < 0)
			return ;
		redir(pipex, av[i], env, pipex->array->tab[1]);
		pipex = pipex->next;
		++i;
	}
	redir(pipex, av[i], env, 3);
	wait_lst(head);
}

void    redir(t_pipe *pipex, char *av, char **env, int out)
{
	pipex->child = fork();
	if (pipex->child < 0)
		write(1, "error\n", 6);
	if (pipex->child == 0)
	{
		close(pipex->array->tab[0]);
		if (out != 3)
		{
			verif_dup2(out, STDOUT_FILENO);
			close(out);
		}
		exec(av, env);
	}
	else
	{
		close(out);
		verif_dup2(pipex->array->tab[0], STDIN_FILENO);
		close(pipex->array->tab[0]);
	}
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
		puts("eror path");
		return ;
	}
	else
		execve(path, args, env);
}

void	wait_lst(t_pipe *pipex)
{
	while (pipex)
	{
		waitpid(pipex->child, NULL, 0);
		pipex = pipex->next;
	}
}
