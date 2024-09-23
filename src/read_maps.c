/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:23:41 by dsylvain          #+#    #+#             */
/*   Updated: 2024/09/23 23:22:28 by dsylvain         ###   ########.fr       */
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
void	solve_map(t_map *map);
int		ft_atoi(const char *nptr);
int		ft_isdigit(char str);
int		ft_strlen(const char *str);
int		get_len(char *str);

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

int	extract_map_data(char *str, t_map *map)
{
	int	i;

	map->map_size = ft_atoi(str);
	i = 0;
	if (map->map_size == 0)
		return (0);
	while (ft_isdigit(str[i]))
		str[i++];
	if (get_len(&str[i]) != 3)
		return (0);
	map->empty = *&str[i++];
	map->obstacle = *&str[i++];
	map->full = *&str[i++];
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
		if (j == 0)
			if (extract_map_data(str, map) == 0)
				return (free(str), -1);
		j++;
		free(str);
	}
	if (j != map->map_size + 2)
		return (-1);
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
		if (str && j > 0)
		{
			(*map)[j - 1] = ft_strdup(str);
		}
		free(str);
		j++;
	}
	(*map)[j - 1] = NULL;
	close (fd);
	return (1);
}

int	get_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int	is_valid_char(char c, t_map *map)
{
	return (c == map->empty || c == map->obstacle);
}

int	check_line(int j[], char *str, int *len, t_map *map)
{
	int	i;

	i = 0;
	if (j[0] == 1 && !str)
		return (0);
	if (j[0] == 1)
		*len = get_len(str);
	if (*str && j[0] > 0 && get_len(str) != *len)
		return (0);
	while (str[i])
	{
		if (j[0] != 0 && str[i] != '\n' && !is_valid_char(str[i], map))
			return (printf("%c", str[i]), 0);
		i++;
	}
	return (1);
}

int	get_file_len(char **argv, int *i, t_map *map)
{
	int		fd;
	int		j[2];
	char	*str;
	int		len;

	if (open_file(&fd, argv, i) == 0)
		return (-1);
	j[0] = 0;
	str = "";
	j[1] = 0;
	while (j[0] < map->map_size)
	{
		str = get_next_line(fd);
		if (check_line(j, str, &len, map) == 0)
			return (-1);
		j[0]++;
		if (str)
			free(str);
		j[1]++;
	}
	close (fd);
	return (j[0]);
}

int	read_bsq_maps(t_map *map, int i, int argc, char **argv)
{
	char	*str;
	int		size;
	int		len;
	int		k;

	while (i < argc)
	{
		size = get_file_size(argv, &i, map);
		if (size == -1)
			continue ;
		len = get_file_len(argv, &i, map);
		if (len == -1)
			continue ;
		if (alloc_map_tab(&map->map, size) == 0)
			return (0);
		if (fill_map_tab(argv, &i, &(map)->map) == 0)
			return (0);
		solve_map(map);
		free_tab(map->map);
		i++;
	}
	return (1);
}
