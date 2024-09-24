/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_mapdata.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:55:37 by dsylvain          #+#    #+#             */
/*   Updated: 2024/09/24 17:04:46 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	get_bsq_len(char *str);

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
