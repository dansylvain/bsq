/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:04:46 by dsylvain          #+#    #+#             */
/*   Updated: 2024/09/24 16:03:19 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	display_map(t_map *map, int x, int y);

int	get_bsq_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

void	initialize_data(t_map *map)
{
	int	i;

	map->map_size_y = 0;
	map->map_size_x = 0;
	map->empty = 0;
	map->obstacle = 0;
	map->full = 0;
	i = 0;
	while (i < 1000)
		ft_memset(map->map[i++], '\0', 1000);
}

void	extract_map_data(int fd, t_map *map)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	str = "";
	i = 0;
	k = 0;
	while (str)
	{
		str = get_next_line(fd);
		if (str)
		{
			if (i == 0)
			{
				map->map_size_y = ft_atoi(str);
				j = 0;
				while (ft_isdigit(str[j]))
					j++;
				map->empty = str[j];
				map->obstacle = str[j + 1];
				map->full = str[j + 2];
			}
			else
			{
				if (map->map_size_x == 0)
					map->map_size_x = get_bsq_len(str);
				j = 0;
				while (j < map->map_size_x)
				{
					map->map[k][j] = str[j];
					j++;
				}
				k++;
			}
			free(str);
		}
		i++;
	}
}

void	display_map(t_map *map, int x, int y)
{
	int	i;
	int	j;

	i = y;
	while (i < map->map_size_y)
	{
		j = x;
		while (j < map->map_size_x)
		{
			write (1, &map->map[i][j], 1);
			j++;
		}
		write (1, "\n", 1);
		i++;
	}
	write (1, "\n", 1);
}

void	display_data(t_map *map)
{
	printf("%c%c%c | %i : %i\n", map->empty, map->obstacle,
		map->full, map->map_size_x, map->map_size_y);
}

void	close_file(int fd)
{
	if (fd != -1)
	{
		close (fd);
		printf("file closed\n");
	}
}

int	open_file(int argc, int *fd, char *file_name)
{
	if (argc == 2)
		*fd = open(file_name, O_RDONLY);
	if (*fd == -1)
		return (printf("could not open file\n"), 1);
}

int	find_bsq(t_map *map, int x, int y, int size)
{
	int	i;
	int	j;

	if (x + size > map->map_size_x || y + size > map->map_size_y)
		return (size - 1);
	i = y;
	while (i < y + size)
	{
		j = x;
		while (j < x + size)
		{
			if (map->map[i][j] == map->obstacle)
				return (size - 1);
			j++;
		}
		i++;
	}
	return (find_bsq(map, x, y, size + 1));
}

void	find_largest_square(t_map *map)
{
	int	y;
	int	x;
	int	size;

	map->bsq_size = 0;
	y = 0;
	while (y < map->map_size_y)
	{
		x = 0;
		while (x < map->map_size_x)
		{
			size = find_bsq(map, x, y, 1);
			if (size > map->bsq_size)
			{
				map->bsq_size = size;
				map->bsq_x = x;
				map->bsq_y = y;
			}
			x++;
		}
		y++;
	}
}

void	mark_bsq_on_map(t_map *map)
{
	int	y;
	int	x;

	y = map->bsq_y;
	while (y < map->bsq_size + map->bsq_y)
	{
		x = map->bsq_x;
		while (x < map->bsq_size + map->bsq_x)
		{
			map->map[y][x] = map->full;
			x++;
		}
		y++;
	}
}

int	main(int argc, char **argv)
{
	t_map	map;
	int		fd;
	char	*str;
	int		i;
	int		j;

	initialize_data(&map);
	open_file(argc, &fd, argv[1]);
	extract_map_data(fd, &map);
	close_file(fd);
	display_data(&map);
	find_largest_square(&map);
	mark_bsq_on_map(&map);
	display_map(&map, 0, 0);
	printf("Biggest square found at x: %d, y: %d with size: %d\n",
		map.bsq_x, map.bsq_y, map.bsq_size);
	printf("Welcome to the Jungle\n");
	return (0);
}
