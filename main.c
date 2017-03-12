#include "get_next_line.h"







int main(int argc, char **argv)
{
	int fd;
	char *str;
	int i;

	(void)argc;
	i = 0;
	fd = open(argv[1], O_RDONLY);
	str = NULL;
	while(get_next_line(fd, &str) > 0 && i < 55555)
	{
		i++;
		//ft_putstr("non\n");
		printf("%s\n", str);
	}
	//printf("%s\n", str);
	printf("%d", i);
	close(fd);
	return(0);
}