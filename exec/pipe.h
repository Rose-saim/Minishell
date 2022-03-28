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


int		ft_strcmp(char *s1, char *s2);
char	**ft_split(char const *s, char c);
char	*ft_strjoin_l(char *path, char *cmd);

char	**get_path(char **env);
char	*get_cmd_opt(char *cmd, char **env);

int		open_file(char *av, int mode);
void	drive_fd(int fd, char *file, int mode);
void	loop_fd(t_pipe *pipex, int ac);

void	exec(char *av, char **env);
void	exec_cmds(t_pipe *pipex, int ac, char **av, char **env);
void    redir(t_pipe *pipex, char *av, char **env, int out);

t_pipe	*create_lst(int ac, t_pipe *lst_pipex, t_mng *mng);
void	free_lst(t_pipe *head);
void	wait_lst(t_pipe *pipex);

#endif