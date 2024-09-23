/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_bsq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:23:21 by dsylvain          #+#    #+#             */
/*   Updated: 2024/09/23 22:24:05 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "header.h"
#include <unistd.h>

void	mark_bsq_on_map(t_map *map);
void	display_bsq(t_map *map);

void	calculate_square_len(t_map *map, int *x, int *y, int *max_len)
{
	int	i;
	int	j;
	int	k;

	k = 1;
	while (*y + k <= map->map_size && *x + k <= map->map_size)
	{
		i = 0;
		while (i < k)
		{
			j = 0;
			while (j < k)
			{
				if (map->map[*y + j][*x + i] == map->obstacle)
				{
					if (k - 1 > *max_len)
					{
						*max_len = k - 1;
						map->x = *x;
						map->y = *y;
					}
					return ;
				}
				j++;
			}
			i++;
		}
		k++;
	}
	if (k - 1 > *max_len)
	{
		*max_len = k - 1;
		map->x = *x;
		map->y = *y;
	}
}

void	solve_map(t_map *map)
{
	int	i;
	int	j;
	int	max_len;

	max_len = 0;
	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			calculate_square_len(map, &i, &j, &max_len);
			j++;
		}
		i++;
	}
	map->map_size = max_len;
	printf("bsq len: %i\ncoor: %i, %i\n", max_len, map->x, map->y);
	mark_bsq_on_map(map);
	display_bsq(map);
	map->map_size = max_len;
}
