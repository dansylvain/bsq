/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 17:03:01 by dsylvain          #+#    #+#             */
/*   Updated: 2024/09/24 18:18:23 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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

	map->map_size_y = 0;
	map->map_size_x = 0;
	map->empty = 0;
	map->obstacle = 0;
	map->full = 0;
	i = 0;
	while (i < 2000)
		ft_memset(map->map[i++], '\0', 2000);
}

void	close_file(int fd)
{
	if (fd != -1)
	{
		close (fd);
	}
}

int	open_file(int argc, int *fd, char *file_name)
{
	if (argc == 2)
		*fd = open(file_name, O_RDONLY);
	if (*fd == -1)
		return (("could not open file\n"), 1);
}

void	error_msg(char *str)
{
	write (2, &str, ft_strlen(str));
}
