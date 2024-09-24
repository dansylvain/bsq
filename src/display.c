/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 17:01:31 by dsylvain          #+#    #+#             */
/*   Updated: 2024/09/24 17:01:41 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
