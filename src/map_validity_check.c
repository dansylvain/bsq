/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansylvain <dansylvain@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 21:01:42 by dsylvain          #+#    #+#             */
/*   Updated: 2024/09/25 00:30:34 by dansylvain       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
void	error_msg(char *str);
int		open_file(int argc, t_map *map, char *file_name);
void	close_file(int fd);

int	check_lines_length(t_map *map)
{
	int		i;
	char	*str;
	int		is_valid;

	i = 0;
	is_valid = 1;
	str = "";
	while (str)
	{
		str = get_next_line(map->fd);
		if (i == 1 && !str)
			is_valid = -1;
		if (str && i > 0)
		{
			int toto = ft_strlen(str);
			if (toto != map->map_size_x + 1)
				is_valid = -1;
		}
		free(str);
		i++;
	}
	return (is_valid);
}

int	has_only_valid_chars(t_map *map)
{
	return (1);
	
}


int	check_map_validity(t_map *map, int argc, int i)
{
	int	is_valid;
	int	fd;
	
	fd = 0;
	is_valid = 1;
	fd = open_file(argc, map, map->my_argv[i - 2]);
	if (fd == -1)
	{
		is_valid = 0;		
	}
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
	close_file(fd);

	return (is_valid);
}
