/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:04:46 by dsylvain          #+#    #+#             */
/*   Updated: 2024/09/25 11:47:00 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/**========================================================================
 *                           main
 * ! remaining bugs:
 * ! - bsq marking overflows on the side 
 *========================================================================**/
int	main(int argc, char **argv)
{
	t_map	map;
	int		i;
	int		fd;

	initialize_data(&map);
	handle_user_input(argc, argv, &map);
	i = 1;
	while (i < map.myargc || i < argc)
	{
		if (open_file(argc, &map, map.my_argv[i++]) == -1)
			continue ;
		extract_map_data(&map);
		close_file(map.fd);
		map.fd = 0;
		if (check_map_validity(&map, argc, i + 1) == -1)
			continue ;
		find_largest_square(&map);
		mark_bsq_on_map(&map);
		display_map(&map, 0);
	}
	if (argc == 1)
		free_tab(map.my_argv);
	return (0);
}

/**========================================================================
 *                           initialize_data
 *========================================================================**/
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
	while (i < 2000)
		ft_memset(map->map[i++], '\0', 2000);
	ft_memset(map->charset, '\0', 5);
}

/**========================================================================
 *                           handle_user_input
 *========================================================================**/
void	handle_user_input(int argc, char **argv, t_map *map)
{
	char	buff[1000];
	char	**tab;
	int		i;

	map->my_argv = NULL;
	ft_memset(buff, '\0', 1000);
	if (argc == 1)
	{
		ft_strlcpy(buff, "./bsq  ", 7);
		read(1, &buff[6], 100);
		map->my_argv = ft_split(buff, " \n	");
		i = 0;
		while (map->my_argv[i])
			i++;
		map->myargc = i;
	}
	else
		map->my_argv = argv;
}
