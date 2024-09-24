/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 17:01:31 by dsylvain          #+#    #+#             */
/*   Updated: 2024/09/24 20:17:08 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_putstr(char str[])
{
	write(1, &str, ft_strlen(str));
}

void	display_map(t_map *map, int y)
{
	int	i;

	i = y;
	while (i < map->map_size_y)
	{
		write(1, &map->map[i], ft_strlen(map->map[i]));
		write (1, "\n", 1);
		i++;
	}
}

// void	display_data(t_map *map)
// {
// 	printf("%c%c%c | %i : %i\n", map->empty, map->obstacle,
// 		map->full, map->map_size_x, map->map_size_y);
// }
