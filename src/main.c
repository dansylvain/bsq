/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:04:46 by dsylvain          #+#    #+#             */
/*   Updated: 2024/09/24 23:13:18 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	display_map(t_map *map, int y);
void	find_largest_square(t_map *map);
void	mark_bsq_on_map(t_map *map);
void	extract_map_data(t_map *map);
void	display_data(t_map *map);
void	initialize_data(t_map *map);
int		open_file(int argc, t_map *map, char *file_name);
void	close_file(int fd);
size_t	ft_strcpy(char *dst, const char *src);
char	**ft_split(char *str, char *cs);
void	error_msg(char *str);
int		get_bsq_len(char *str);

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
		free_tab(map->my_argv);
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
		}
		i++;
		free(str);
		
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

int	main(int argc, char **argv)
{
	t_map	map;
	int		i;
	int		fd;
	int		flag;

	flag = 0;
	initialize_data(&map);
	handle_user_input(argc, argv, &map);
	i = 1;
	while (i < map.myargc || i < argc) // je suspecte cette condition
	{
		if (open_file(argc, &map, map.my_argv[i++]) == -1)
		{
			flag = 1;
			continue ;
		}
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
	free_all(argc, &map);
	return (0);
}
