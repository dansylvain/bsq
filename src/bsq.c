/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:51:38 by dsylvain          #+#    #+#             */
/*   Updated: 2024/09/25 10:12:09 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/**========================================================================
 *                           find_bsq
 *========================================================================**/
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

/**========================================================================
 *                           find_largest_square
 *========================================================================**/
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

/**========================================================================
 *                           mark_bsq_on_map
 *========================================================================**/
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
