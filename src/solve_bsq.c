/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_bsq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:23:21 by dsylvain          #+#    #+#             */
/*   Updated: 2024/09/23 17:03:41 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "header.h"

void	solve_map(t_map map)
{
	int	i;

	i = 0;
	while (map.map[i])
	{
		printf("%s", map.map[i++]);
	}
	printf("\n[%i], [%c], [%c], [%c]\n", map.map_size, map.empty,
		map.obstacle, map.full);
	printf("\n");
}
