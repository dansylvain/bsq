/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_bsq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:23:21 by dsylvain          #+#    #+#             */
/*   Updated: 2024/09/23 22:58:30 by dsylvain         ###   ########.fr       */
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
	while (*y + k - 1 < map->map_size && *x + k - 1 < map->map_size) // Vérification des limites
	{
		i = 0;
		while (i < k)
		{
			j = 0;
			while (j < k)
			{
			 // Vérification des limites avant d'accéder à la carte
				if (*y + j < map->map_size && *x + i < map->map_size
					&& map->map[*y + j][*x + i] == map->obstacle)
				{
					// Si un obstacle est trouvé, vérifie la taille maximale
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
	// Vérification finale après la fin de la boucle
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
		while (map && map->map && map->map[i] && map->map[i][j] && map->map[i][j] != '\n')
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
