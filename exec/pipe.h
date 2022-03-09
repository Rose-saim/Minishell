#ifndef PIPE_H
# define PIPE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_pipe
{

    pid_t   child;
    struct s_pipe child;
}               t_pipe;

int	ft_strcmp(char *s1, char *s2);
char	**ft_split(char const *s, char c);

#endif