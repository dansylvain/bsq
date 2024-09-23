/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:19:48 by dansylvain        #+#    #+#             */
/*   Updated: 2024/09/22 09:31:26 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int	ft_isdigit(char str);
int	ft_strlen(char *str);

int	ft_atoi(const char *nptr)
{
	long int	res;
	int			i;
	int			sign;

	i = 0;
	sign = 1;
	res = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i++] == '-')
			sign *= -1;
	}
	if (ft_strlen((char *)nptr) > 11 && sign > 0)
		return (INT_MAX);
	if (ft_strlen((char *)nptr) > 11 && sign < 0)
		return (INT_MIN);
	while (nptr[i] && ft_isdigit(nptr[i]))
		res = res * 10 + (nptr[i++] - '0');
	if (res * sign > INT_MAX || res * sign < INT_MIN)
		return (0);
	return (res * sign);
}
