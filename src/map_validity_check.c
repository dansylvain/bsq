/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 21:01:42 by dsylvain          #+#    #+#             */
/*   Updated: 2024/09/25 09:42:11 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	error_msg(char *str);
int		open_file(int argc, t_map *map, char *file_name);
void	close_file(int fd);
int		get_bsq_len(char *str);

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

int	check_lines_length(t_map *map)
{
	int		is_valid;

	return (is_valid);
}

int	has_only_valid_chars(t_map *map)
{
	return (1);
}

int	check_map_validity(t_map *map, int argc, int i)
{
	int		is_valid;
	int		fd;
	int		j;
	int		len;
	char	*str;

	fd = 0;
	is_valid = 1;
	fd = open_file(argc, map, map->my_argv[i - 2]);
	if (fd == -1)
	{
		is_valid = 0;
	}
	j = 0;
	is_valid = 1;
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
	printf("%s : %i\n", map->charset, get_bsq_len(map->charset));
	if (get_bsq_len(map->charset) != 3)
		is_valid = -1;
	if (has_only_valid_chars(map) == -1)
		is_valid = -1;
	if (is_valid == -1)
		error_msg("map error\n");
	close_file(fd);
	return (is_valid);
}
