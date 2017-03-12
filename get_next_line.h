#ifndef GNL_H
#define GNL_H

#include "libft/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define BUFF_SIZE 64



typedef struct s_env
{
	int fd;
	char *str;
	int bol;
	int bol2;
	struct s_env *next;

}				t_env;

int get_next_line(const int fd, char **line);

#endif