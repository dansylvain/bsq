/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:04:46 by dsylvain          #+#    #+#             */
/*   Updated: 2024/09/24 19:58:54 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	display_map(t_map *map, int y);
void	find_largest_square(t_map *map);
void	mark_bsq_on_map(t_map *map);
void	extract_map_data(int fd, t_map *map);
void	display_data(t_map *map);
void	initialize_data(t_map *map);
int		open_file(int argc, int *fd, char *file_name);
void	close_file(int fd);
size_t	ft_strcpy(char *dst, const char *src);
char	**ft_split(char *str, char *cs);
void	error_msg(char *str);

void	free_tab(char **tab)

{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		tab[i++] = NULL;
	}
	free(tab);
	tab = NULL;
}

void	free_all(int argc, t_map *map)
{
	if (argc == 1)
	{
		free_tab(map->my_argv);
		// free (map);
	}
}

void	handle_user_input(int argc, char **argv, t_map *map)
{
	char	buff[1000];
	char	**tab;
	int		i;

	map->my_argv = NULL;
	ft_memset(buff, '\0', 1000);
	if (argc == 1)
	{
		ft_strcpy(buff, "./bsq  ");
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

int	main(int argc, char **argv)
{
	t_map	map;
	int		fd;
	int		i;

	initialize_data(&map);
	handle_user_input(argc, argv, &map);
	i = 1;
	while (i < map.myargc || i < argc)
	{
		if (open_file(argc, &fd, map.my_argv[i++]) == -1)
		{
			error_msg("file error\n");
			continue ;
			
		}
		extract_map_data(fd, &map);
		close_file(fd);
		find_largest_square(&map);
		mark_bsq_on_map(&map);
		display_map(&map, 0);
		
		// printf("%s\n", map.my_argv[i]);
	}

	
	if (argc == 1)
		free_tab(map.my_argv);
	return (0);
}
