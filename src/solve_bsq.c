/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_bsq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:23:21 by dsylvain          #+#    #+#             */
/*   Updated: 2024/09/23 20:05:23 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "header.h"
#include <unistd.h>

void	calculate_square_len(t_map *map, int *i, int *j, int *max_len)
{
	
}

void	solve_map(t_map *map)
{
	int	i;
	int	j;
	int	max_len;

	printf("\n[%i], [%c], [%c], [%c]\n", map->map_size, map->empty,
		map->obstacle, map->full);
	max_len = 0;
	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			calculate_square_len(map, &i, &j, &max_len);	
			write (1, &map->map[i][j], 1);
			j++;
		}
		i++;
	}
	printf("\n");
	printf("bsq len: %i\n", max_len);
}
