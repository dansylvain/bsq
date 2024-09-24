/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:34:35 by dsylvain          #+#    #+#             */
/*   Updated: 2024/09/24 11:21:14 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "gnl.h"

typedef struct map
{
	int		map_size_y;
	int		map_size_x;
	char	empty;
	char	obstacle;
	char	full;
}	t_map;

int	ft_atoi(const char *nptr);
int	ft_isdigit(char str);

#endif