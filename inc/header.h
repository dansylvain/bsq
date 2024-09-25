/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:34:35 by dsylvain          #+#    #+#             */
/*   Updated: 2024/09/25 13:20:36 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "gnl.h"
# include <errno.h>
# include <stdio.h>
# include <string.h>

typedef struct map
{
	char	**my_argv;
	char	charset[5];
	int		myargc;
	int		fd;
	int		bsq_size;
	int		bsq_x;
	int		bsq_y;
	int		map_size_y;
	int		map_size_x;
	char	empty;
	char	obstacle;
	char	full;
	char	map[1500][1500];
}	t_map;

void	ft_putstr(char str[]);
int		ft_atoi(const char *nptr);
int		ft_isdigit(char str);
void	*ft_memset(void *s, int c, size_t n);
void	error_msg(char *str);
int		get_bsq_len(char *str);
void	display_map(t_map *map, int y);
void	find_largest_square(t_map *map);
void	mark_bsq_on_map(t_map *map);
void	extract_map_data(t_map *map);
void	initialize_data(t_map *map);
int		open_file(int argc, t_map *map, char *file_name);
void	close_file(int fd);
size_t	ft_strlcpy(char *dst, const char *src, unsigned int len);
char	**ft_split(char *str, char *cs);
int		check_map_validity(t_map *map, int argc, int i);
void	handle_line(int i[], int *j, t_map **map, char *str);
void	handle_user_input(int argc, char **argv, t_map *map);
void	free_tab(char **tab);
void	free_all(int argc, t_map *map);
int		check_str(t_map *map);

#endif