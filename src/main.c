#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

char	*get_next_line(int fd);
void	*ft_memset(void *s, int c, size_t n);
char	**ft_split(char *str, char *cs);

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*str;
	int		i;
	char	buff[100];
	char	**tab;

	fd = 0;
	str = "";
	i = 1;
	tab = NULL;

	ft_memset(buff, '\0', 100);
	if (argc == 1)
	{
		read(1, buff, 100);
		tab = ft_split(buff, " \n	");
		i = 0;
		argv = tab;
	}
	i = 1;
	if (tab)
	{
		i = 0;
		argc = 0;
		while (tab[argc])
			argc++;
	}
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
		{
			printf("could not open file %s\n", argv[i]);
			i++;
			continue ;
		}
		while (str)
		{
			str = get_next_line(fd);
			if (str)
				printf("%s", str);
			free(str);
		}
		printf("\n");
		close (fd);
		str = "";
		i++;
	}
	if (tab)
		free_tab(tab);
	return (0);
}