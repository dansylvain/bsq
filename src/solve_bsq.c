/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_bsq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:23:21 by dsylvain          #+#    #+#             */
/*   Updated: 2024/09/23 19:22:13 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "header.h"
#include <unistd.h>

void	solve_map(t_map *map)
{
	int	i;
	int	j;
	
	printf("\n[%i], [%c], [%c], [%c]\n", map->map_size, map->empty,
		map->obstacle, map->full);

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			write (1, &map->map[i][j], 1);
			j++;
		}
		i++;
	}
	printf("\n");
}
