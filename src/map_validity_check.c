/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 21:01:42 by dsylvain          #+#    #+#             */
/*   Updated: 2024/09/24 21:03:06 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
void	error_msg(char *str);

int	check_lines_length(t_map *map)
{
	int		i;
	char	*str;

	i = 0;
	str = "";
	while (str)
	{
		str = get_next_line(map->fd);
		if (str && i > 0)
		{
			int toto = ft_strlen(str);
			if (toto != map->map_size_x + 1)
				return (-1);
			free(str);
		}
		i++;
	}
	return (1);
}

int	at_least_one_line_one_box(t_map *map)
{
	
}

int	has_line_breaks(t_map *map)
{
	
}

int	has_only_valid_chars(t_map *map)
{
	
}


int	check_map_validity(t_map *map)
{
	int	is_valid;

	is_valid = 1;
	if (check_lines_length(map) == -1)
		is_valid = -1;
	if (at_least_one_line_one_box(map) == -1)
		is_valid = -1;
	if (has_line_breaks(map) == -1)
		is_valid = -1;
	if (has_only_valid_chars(map) == -1)
		is_valid = -1;
	if (is_valid == -1)
		error_msg("map error\n");
	return (is_valid);
}