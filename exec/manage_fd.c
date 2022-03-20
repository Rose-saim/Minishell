#include "pipe.h"

int    open_file(char *av, int mode)
{
	if (mode == 0)
	{
		if (access(av, F_OK))
		{
			write(1, "Inexist fd\n", 11);
			return (-1);
		}
		else
			return(open(av, O_RDONLY));
	}
	else
		return (open(av, O_CREAT | O_WRONLY | O_TRUNC,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH));
}

void    drive_fd(int fd, char *file, int mode)
{

	if (mode == 0)
	{
		fd = open_file(file, mode);
		if (dup2(fd, mode) == -1)
		{
			puts("error fd");
			return ;
		}
		close(fd);
	}
	else
	{
		fd = open_file(file, mode);
		if (dup2(fd, mode) == -1)
		{
			puts("error fd2");
			return ;
		}
		close(fd);
	}
}