/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:23:41 by dsylvain          #+#    #+#             */
/*   Updated: 2024/09/23 10:25:46 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	**handle_user_input(int *argc, char ***argv)
{
	char	buff[100];
	char	**tab;

	tab = NULL;
	ft_memset(buff, '\0', 100);
	if (*argc == 1)
	{
		read(1, buff, 100);
		tab = ft_split(buff, " \n	");
		*argv = tab;
	}
	return (tab);
}

int	open_file(int *fd, char **argv, int *i)
{
	*fd = open(argv[*i], O_RDONLY);
	if (*fd == -1)
	{
		printf("could not open file %s\n", argv[*i]);
		(*i)++;
		return (0);
	}
	return (1);
}

int	define_index(char **tab, int *argc)
{
	int	i;

	i = 1;
	if (tab)
	{
		i = 0;
		*argc = 0;
		while (tab[*argc])
			(*argc)++;
	}
	return (i);
}

void	read_bsq_maps(int fd, int i, int argc, char **argv)
{
	char	*str;

	str = "";
	while (i < argc)
	{
		if (open_file(&fd, argv, &i) == 0)
			continue ;
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
}
