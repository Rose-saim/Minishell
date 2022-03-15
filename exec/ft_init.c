#include "pipe.h"

t_pipe	*create_lst(int ac, t_pipe *lst_pipex)
{
	int	count_cmd;
	t_pipe	*node;
	t_pipe	*drive_lst;

	int	i = 1;
	if (!lst_pipex)
	{
		lst_pipex = (t_pipe *)malloc(sizeof(t_pipe));
		if (!lst_pipex)
			return (NULL);
		lst_pipex->id = i++;
		lst_pipex->next = NULL;
	}
	drive_lst = lst_pipex;
	count_cmd = ac - 3;
	while (count_cmd - 1 > 0)
	{
		node = (t_pipe *)malloc(sizeof(t_pipe));
		node->id = i;
		node->fd_in = i;
		node->next = NULL;
		drive_lst->next = node;
		drive_lst = drive_lst->next;
		--count_cmd;
	}
	return(lst_pipex);
}

void	loop_fd(t_pipe *pipex, int ac)
{
	t_pipe  *head;
	int		 ret;
	int     i;

	i = 0;
	head = pipex;
	while (i < ac - 3)
	{
		ret = pipe(head->door);
		if (ret < 0)
			printf("eror redir");
		++i;
		head = head->next;
	}
}