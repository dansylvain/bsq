/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansylvain <dansylvain@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 01:00:09 by dansylvain        #+#    #+#             */
/*   Updated: 2024/09/22 22:25:59 by dansylvain       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	func3(char *cs, char c)
{
	while (*cs)
		if (*cs++ == c)
			return (1);
	return (0);
}

int	func2(char **tab, int nbr, int j)
{
	if (j == 0)
		return (42);
	tab[nbr] = (char *)malloc(sizeof(char) * (j + 1));
	if (tab[nbr] == 0)
	{
		while (nbr)
			free(tab[nbr--]);
		return (free(tab), 0);
	}
	tab[nbr][j] = '\0';
	return (1);
}

int	func(char *str, char *cs, char **tab, int i[])
{
	i[2] = 0;
	i[0] = 0;
	while (str[i[0]])
	{
		i[1] = 0;
		while (str[i[0]] && func3(cs, str[i[0]]))
			i[0]++;
		if (!str[i[0]])
			break ;
		while (str[i[0]] && !func3(cs, str[i[0]]))
		{
			if (i[3])
				tab[i[2]][i[1]] = str[i[0]];
			i[0]++;
			i[1]++;
		}
		if (tab && !i[3])
			if (func2(tab, i[2], i[1]) == 0)
				return (-1);
		if (!str[i[0]] || func3(cs, str[i[0]]))
			i[2]++;
	}
	return (i[2]);
}

char	**ft_split(char *str, char *cs)
{
	char	**tab;
	int		i[5];

	i[3] = 0;
	i[4] = func(str, cs, NULL, i);
	tab = (char **)malloc(sizeof(char *) * (i[4] + 1));
	if (tab == NULL)
		return (NULL);
	if (func(str, cs, tab, i) == 0)
		return (free(tab), NULL);
	i[3] = 1;
	if (func(str, cs, tab, i) == 0)
		return (free(tab), NULL);
	return (tab[i[4]] = NULL, tab);
}
