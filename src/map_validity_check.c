/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 21:01:42 by dsylvain          #+#    #+#             */
/*   Updated: 2024/09/25 10:11:28 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/**========================================================================
 *                           has_invalid_char
 *========================================================================**/
int	has_invalid_char(t_map *map, char *str)
{
	while (*str)
	{
		if (*str != map->empty && *str != map->obstacle && *str != '\n')
		{
			printf("%c", *str);
			return (-1);
		}
		str++;
	}
	return (1);
}

/**========================================================================
 *                           check_str
 *========================================================================**/
int	check_str(t_map *map)
{
	char	*str;
	int		j;
	int		is_valid;
	int		len;

	j = 0;
	str = "";
	while (str)
	{
		str = get_next_line(map->fd);
		if (j == 1 && !str)
			is_valid = -1;
		if (str && j > 0)
		{
			if (has_invalid_char(map, str) == -1)
				is_valid = -1;
			len = ft_strlen(str);
			if (len != map->map_size_x + 1)
				is_valid = -1;
		}
		free(str);
		j++;
	}
	return (1);
}

/**========================================================================
 *                           check_map_validity
 *========================================================================**/
int	check_map_validity(t_map *map, int argc, int i)
{
	int		is_valid;
	int		fd;

	fd = 0;
	is_valid = 1;
	fd = open_file(argc, map, map->my_argv[i - 2]);
	if (fd == -1)
	{
		is_valid = 0;
	}
	is_valid = 1;
	if (check_str(map) == -1)
		is_valid = -1;
	if (get_bsq_len(map->charset) != 3)
		is_valid = -1;
	if (is_valid == -1)
		error_msg("map error\n");
	close_file(fd);
	return (is_valid);
}
