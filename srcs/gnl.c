#include "gnl.h"

void ft_check_static(t_env *e, char **line)
{

}

int get_next_line(const int fd, char **line)
{
	static t_env *e = NULL;
	char *str;
	int i;

	i = 0;
	ft_check_static(e, line);
	if(!e)
		e = (t_env *)malloc(sizeof(t_env));
	e->str = NULL;
	if(!line[0])
	{
		line[0] = (char *)malloc(sizeof(char));
		line[0][0] = 0;
	}
	while(read(fd, str, BUFF_SIZE) > 0)
	{
		if(ft_strchr(str, '\n') != NULL)
		{
			while(str[i] && str[i] != '\n')
				i++;
			line[0] = ft_strjoin(line[0], ft_strsub(str, 0, i));
			i = i + 2;
			e->str = ft_strsub(str, i, ft_strlen(str));
			//printf("%s\n", e->str);




			printf("%s\n", line[0]);
			return(1);
		}
		else
		{
			line[0] = ft_strjoin(line[0], str);
			//printf("%s", str);
		}
		//printf("la -> %s", str);
	}


	return(0);
}



















int main(int argc, char **argv)
{
	int fd;
	char *str;

	fd = open(argv[1], O_RDONLY);
	while(get_next_line(fd, &str) == 1)
	{
		//ft_putstr("non");
		//printf("%s\n", str);
	}

	return(0);
}