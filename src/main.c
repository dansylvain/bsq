/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:04:46 by dsylvain          #+#    #+#             */
/*   Updated: 2024/09/24 11:23:02 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	open_file(char *map_name)
{
	int	fd;
	
	fd = open(map_name, O_RDONLY);
	return (fd);
}
int	main(int argc, char **argv)
{
	t_map map;
	int	fd;
	int	i;
	int	j;
	char *str;

	// open file
	if (argc == 2)
		fd = open_file(argv[1]);
			if (fd == -1)
				return (printf("could not open file\n"), 1);
			
	// copy file content
	str = "";
	i = 0;
	while (str)
	{
		str = get_next_line(fd);
		if(str)
		{
			if (i == 0)
			{
				map.map_size_y = ft_atoi(str);
				printf("%i", map.map_size_y);
				j = 0;
				while (ft_isdigit(str[j]))
					j++;
				map.empty = str[j];
				map.obstacle = str[j + 1];
				map.full = str[j + 2];
				
				printf("%c%c%c\n", map.empty, map.obstacle, map.full);
			}
			else
				printf("%s", str);
			free(str);
		}
		i++;
	}	


	if (fd != -1)
	{
		close (fd);
		printf("file closed\n");
	}
	printf("Welcome to the Jungle\n");
	return (0);
}
