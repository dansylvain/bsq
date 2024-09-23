/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:23:41 by dsylvain          #+#    #+#             */
/*   Updated: 2024/09/23 14:09:47 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "header.h"

char	*get_next_line(int fd);
void	free_tab(char **tab);
char	*ft_strdup(const char *s);
void	solve_map(t_map map);
int		ft_atoi(const char *nptr);
int		ft_isdigit(char str);

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

void	extract_map_data(char *str, t_map *map)
{
	int	i;

	map->map_size = ft_atoi(str);
	// printf("parse moi ca: %i\n", ft_atoi(str));
	i = 0;
	while (ft_isdigit(str[i]))
		str[i++];
	map->empty = *&str[i++];
	map->obstacle = *&str[i++];
	map->full = *&str[i++];
	// printf("reste de la string: %c\n", *&str[i++]);
	// printf("reste de la string: %c\n", *&str[i++]);
	// printf("reste de la string: %c\n", *&str[i]);
}

int	get_file_size(char **argv, int *i, t_map *map)
{
	int		fd;
	int		j;
	char	*str;

	if (open_file(&fd, argv, i) == 0)
		return (-1);
	j = 0;
	str = "";
	while (str)
	{
		str = get_next_line(fd);
		if(j == 0)
			extract_map_data(str, map);
		j++;
		free(str);
	}
	close (fd);
	return (j);
}

int	alloc_map_tab(char ***map, int j)
{
	*map = NULL;
	*map = (char **)malloc(sizeof(char *) * (j - 1));
	if (*map == NULL)
		return (0);
	(*map)[j - 2] = NULL;
	return (1);
}

int	fill_map_tab(char **argv, int *i, char ***map)
{
	int		fd;
	int		j;
	char	*str;

	if (open_file(&fd, argv, i) == 0)
		return (0);
	j = 0;
	str = "";
	while (str)
	{
		str = get_next_line(fd);
		if (str && j != 0)
		{
			(*map)[j - 1] = ft_strdup(str);
		}
		free(str);
		j++;
	}
	close (fd);
	return (1);
}

int	read_bsq_maps(int fd, int i, int argc, char **argv)
{
	char	*str;
	int		j;
	t_map	map;
	int		k;

	while (i < argc)
	{
		j = get_file_size(argv, &i, &map);
		if (j == -1)
			continue ;
		if (alloc_map_tab(&map.map, j) == 0)
			return (0);
		if (fill_map_tab(argv, &i, &map.map) == 0)
			return (0);
		solve_map(map);
		free_tab(map.map);
		i++;
	}
	return (1);
}
