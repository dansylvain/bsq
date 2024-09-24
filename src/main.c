/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:04:46 by dsylvain          #+#    #+#             */
/*   Updated: 2024/09/24 18:17:15 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	display_map(t_map *map, int x, int y);
void	find_largest_square(t_map *map);
void	mark_bsq_on_map(t_map *map);
void	extract_map_data(int fd, t_map *map);
void	display_data(t_map *map);
void	initialize_data(t_map *map);
int		open_file(int argc, int *fd, char *file_name);
void	close_file(int fd);

int	main(int argc, char **argv)
{
	t_map	map;
	int		fd;
	char	*str;
	int		i;
	int		j;

	initialize_data(&map);
	open_file(argc, &fd, argv[1]);
	extract_map_data(fd, &map);
	close_file(fd);
	find_largest_square(&map);
	mark_bsq_on_map(&map);
	display_map(&map, 0, 0);
	return (0);
}
