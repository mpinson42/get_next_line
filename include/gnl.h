#ifndef GNL_H
#define GNL_H

#include "libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define BUFF_SIZE 8



typedef struct s_env
{
	int fd;
	char *str;
	struct s_env *next;

}				t_env;

#endif