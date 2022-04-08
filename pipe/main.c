#include "pipe.h"

int main(int ac, char **av, char **env)
{
	t_pipe  *pipex;
	t_mng	mng;
	int		i;
	int		door_fd[2];

	if (ac < 5)
		write(1, "Number of arguments is wrong\n", 29);
	else if (is_empty(av) == 1)
		write(1, "Argument is empty\n", 29);
	else
	{
		i = 2;
		pipex = NULL;
		pipex = create_lst(ac, pipex, &mng);
		drive_fd(door_fd[0], av[1], 0);
		drive_fd(door_fd[1], av[ac - 1], 1);
		exec_cmds(pipex, ac, av, env);
		free_lst(pipex);
	}
	return (0);
}