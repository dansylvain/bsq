/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:47:14 by dsylvain          #+#    #+#             */
/*   Updated: 2024/09/23 13:21:40 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(const char *str);
void	*ft_memset(void *s, int c, size_t n);
char	**ft_split(char *str, char *cs);
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

void	error_msg(char *str)
{
	write(2, "Error: ", 8);
	write(2, &str, ft_strlen(str));
	write(2, "\n", ft_strlen(str));
}

char	**handle_user_input(int *argc, char ***argv)
{
	char	buff[100];
	char	**tab;

	tab = NULL;
	ft_memset(buff, '\0', 100);
	if (*argc == 1)
	{
		read(1, buff, 100);
		tab = ft_split(buff, " \n	");
		*argv = tab;
	}
	return (tab);
}

int	define_index(char **tab, int *argc)
{
	int	i;

	i = 1;
	if (tab)
	{
		i = 0;
		*argc = 0;
		while (tab[*argc])
			(*argc)++;
	}
	return (i);
}
