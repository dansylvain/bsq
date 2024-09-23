/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:04:46 by dsylvain          #+#    #+#             */
/*   Updated: 2024/09/23 22:18:23 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "header.h"
#include <unistd.h>

char	**handle_user_input(int *argc, char ***argv);
int		define_index(char **tab, int *argc);
void	free_tab(char **tab);
void	error_msg(char *str);
int		read_bsq_maps(t_map *map, int i, int argc, char **argv);

void	mark_bsq_on_map(t_map *map)
{
	int	x;
	int	y;

	printf ("map->y: %i, map->x: %i, map->max_size: %i\n", map->y,
		map->x, map->map_size);
	y = map->y;
	while (y < map->y + map->map_size)
	{
		x = map->x;
		while (x < map->x + map->map_size)
		{
			map->map[y][x] = map->full;
			x++;
		}
		y++;
	}
	printf ("map->y: %i, map->x: %i, map->max_size: %i\n", map->y,
		map->x, map->map_size);
}

void	display_bsq(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			write(1, &map->map[y][x], 1);
			x++;
		}
		y++;
	}
}

int	main(int argc, char **argv)
{
	t_map	map;
	int		fd;
	int		i;
	char	**tab;

	map.map_size = 0;
	tab = handle_user_input(&argc, &argv);
	i = define_index(tab, &argc);
	if (read_bsq_maps(&map, i, argc, argv) == 0)
		return (error_msg("memory allocation for bsq map failed"), 1);
	if (map.map_size)
		printf("biggest square is at %i, %i (max_len: %i)\n",
			map.x, map.y, map.map_size);
	if (tab)
		free_tab(tab);
	return (0);
}
