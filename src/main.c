#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

char	*get_next_line(int fd);


int	main(int argc, char **argv)
{
	int		fd;
	char	*str;

	fd = 0;
	str = "";
	if (argc = 2)
		fd = open(argv[1], O_RDONLY);
	while (str)
	{
		str = get_next_line(fd);
		if (str)
			printf("%s", str);
		free(str);
	}
	// write(1, "Welcome to the Jungle\n", 23);
	return (0);
}