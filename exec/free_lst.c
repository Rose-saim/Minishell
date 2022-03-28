#include "pipe.h"

void	free_lst(t_pipe *head)
{
	t_pipe	*pipe;

	pipe = head->next;
	while (pipe)
	{
		free(head);
		head = pipe;
		pipe = pipe->next;
	}
	free(head);
}