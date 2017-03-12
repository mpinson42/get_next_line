#include "get_next_line.h"

int ft_check_static(t_env *e, char **line)
{
	int i;

	i = 0;

	if(ft_strchr(e->str, '\n') != NULL)
	{
		while(e->str[i] && e->str[i] != '\n')
			i++;
		line[0] = ft_strjoin(line[0], ft_strsub(e->str, 0, i));
		e->str = ft_strsub(e->str, i + 1, BUFF_SIZE);
		return(1);
	}
	else
	{
		line[0] = ft_strjoin(line[0], e->str);
		e->str = NULL;
	}
	return(0);
}

int ft_check_fd(t_env *e, int fd)
{

	while(fd != e->fd)
	{
		if(fd == e->fd)
			return(0);
		if(e->next)
			e = e->next;
		else
			break;
	}
	if(!(e->next = (t_env *)malloc(sizeof(t_env))))
		return(-1);
	e = e->next;
	e->fd = fd;
	if(!(e->str = (char *)malloc(sizeof(char))))
		return(-1);
	return(0);
}

int get_next_line(const int fd, char **line)
{
	static t_env *e = NULL;
	char str[BUFF_SIZE + 1];
	int test;
	int i;

	i = 0;
	test = 0;
	if(fd < 0 || line == NULL)
		return(-1);
	if(!e)
	{
		if(!(e = (t_env *)malloc(sizeof(t_env))))
			return(-1);
		e->str = NULL;
		e->fd = fd;
		e->bol = 0;
	}
	line[0] = ft_strdup("");
	if(e->str && ft_check_static(e, line) == 1)
		return(1);
	ft_bzero(str, BUFF_SIZE + 1);
	while((test = read(fd, str, BUFF_SIZE)) > 0)
	{
		if(ft_strchr(str, '\n') != NULL)
		{
			while(str[i] != '\0' && str[i] != '\n')
				i++;
			line[0] = ft_strjoin(line[0], ft_strsub(str, 0, i));
			e->str = ft_strsub(str, i + 1, BUFF_SIZE);
			return(1);
		}
		else
			line[0] = ft_strjoin(line[0], str);
		ft_bzero(str, BUFF_SIZE + 1);
	}
	if(fd < 0 || test == - 1)
		return(-1);
	if(line[0][0] != 0 && e->bol == 0)
	{
		e->bol = 1;
		line[0] = ft_strjoin(line[0], str);
		return(1);
	}
	return(0);
}














