#ifndef PIPE_H
# define PIPE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct s_mng
{
	int	tab[2];
}t_mng;

typedef struct s_pipe
{
	int	id;
	int fd_in;
	int fd_out;
	t_mng	*array;
	pid_t   child;
	struct s_pipe *next;
}               t_pipe;


int	ft_strcmp(char *s1, char *s2);

int    open_file(char *av, int mode);

t_pipe	*create_lst(int ac, t_pipe *lst_pipex, t_mng *mng);

void    drive_fd(int fd, char *file, int mode);
void	exec(char *av, char **env);
void	loop_fd(t_pipe *pipex, int ac);

char	**ft_split(char const *s, char c);
char	*ft_strjoin_l(char *path, char *cmd);

#endif