/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:04:46 by dsylvain          #+#    #+#             */
/*   Updated: 2024/09/24 13:38:14 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
void	display_map(t_map *map);

int	open_file(char *map_name)
{
	int	fd;
	
	fd = open(map_name, O_RDONLY);
	return (fd);
}

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
		if(str)
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
				if(map->map_size_x == 0)
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

void	display_map(t_map *map)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < map->map_size_y)
	{
		j = 0;
		while (j < map->map_size_x)
		{
			write (1, &map->map[i][j], 1);
			j++;
		}
		write (1	, "\n", 1);
		i++;
	}
		
}

void	display_data(t_map *map)
{
	printf("%c%c%c | %i : %i\n", 	map->empty, map->obstacle,
									map->full, map->map_size_x,
									map->map_size_y);		
}

int	main(int argc, char **argv)
{
	t_map map;
	int	fd;
	int	i;
	int	j;
	char *str;

	// open file
	if (argc == 2)
		fd = open_file(argv[1]);
			if (fd == -1)
				return (printf("could not open file\n"), 1);
	
	initialize_data(&map);
	// extract map data
	extract_map_data(fd, &map);
	display_data(&map);
	display_map(&map);


	if (fd != -1)
	{
		close (fd);
		printf("file closed\n");
	}
	printf("Welcome to the Jungle\n");
	return (0);
}
