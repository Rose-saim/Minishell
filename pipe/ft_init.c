#include "pipe.h"

t_pipe	*create_lst(int ac, t_pipe *lst_pipex, t_mng *mng)
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
		lst_pipex->array = mng;
		lst_pipex->next = NULL;
	}
	drive_lst = lst_pipex;
	count_cmd = ac - 3;
	while (count_cmd - 1 > 0)
	{
		node = (t_pipe *)malloc(sizeof(t_pipe));
		node->array = mng;
		node->id = i;
		node->fd_in = i;
		node->next = NULL;
		drive_lst->next = node;
		drive_lst = drive_lst->next;
		--count_cmd;
		++i;
	}
	return(lst_pipex);
}
