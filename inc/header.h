/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:34:35 by dsylvain          #+#    #+#             */
/*   Updated: 2024/09/23 20:10:54 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct map
{
	char	**map;
	int		map_size;
	char	empty;
	char	obstacle;
	char	full;
	int		x;
	int		y;
}	t_map;
