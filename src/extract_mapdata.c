/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_mapdata.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:55:37 by dsylvain          #+#    #+#             */
/*   Updated: 2024/09/25 09:29:29 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	get_bsq_len(char *str);
size_t	ft_strlcpy(char *dst, const char *src, unsigned int len);

void	handle_line(int i[], int *j, t_map **map, char *str)
{
	if (i[0] == 0)
	{
		(*map)->map_size_y = ft_atoi(str);
		*j = 0;
		while (ft_isdigit(str[*j]))
			(*j)++;
		printf("%s\n", &str[*j]);
		ft_strlcpy((*map)->charset, &str[*j], 4);
		(*map)->empty = str[*j];
		(*map)->obstacle = str[*j + 1];
		(*map)->full = str[*j + 2];
	}
	else
	{
		if ((*map)->map_size_x == 0)
			(*map)->map_size_x = get_bsq_len(str);
		*j = 0;
		while (*j < (*map)->map_size_x - 2)
		{
			(*map)->map[i[1]][*j] = str[*j];
			(*j)++;
		}
		i[1]++;
	}
}

void	extract_map_data(t_map *map)
{
	char	*str;
	int		i[2];
	int		j;

	str = "";
	i[0] = 0;
	i[1] = 0;
	while (str)
	{
		str = get_next_line(map->fd);
		if (str)
		{
			handle_line(i, &j, &map, str);
			free(str);
		}
		i[0]++;
	}
}
