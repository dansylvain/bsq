/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 17:03:01 by dsylvain          #+#    #+#             */
/*   Updated: 2024/09/25 09:33:27 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	error_msg(char *str);

int	get_bsq_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

void	initialize_data(t_map *map)
{
	int	i;

	map->myargc = 0;
	map->bsq_x = 0;
	map->bsq_y = 0;
	map->map_size_y = 0;
	map->map_size_x = 0;
	map->empty = 0;
	map->obstacle = 0;
	map->full = 0;
	map->bsq_size = 0;
	map->fd = 0;
	i = 0;
	while (i < 1000)
		ft_memset(map->map[i++], '\0', 1000);
	ft_memset(map->charset, '\0', 5);
}

void	close_file(int fd)
{
	if (fd != -1)
	{
		close (fd);
	}
}

int	open_file(int argc, t_map *map, char *file_name)
{
	map->fd = open(file_name, O_RDONLY);
	if (map->fd == -1)
		error_msg("file error\n");
	return (map->fd);
}

void	error_msg(char *str)
{
	write (2, str, ft_strlen(str));
}
