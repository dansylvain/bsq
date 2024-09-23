/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:04:46 by dsylvain          #+#    #+#             */
/*   Updated: 2024/09/23 12:19:51 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	**handle_user_input(int *argc, char ***argv);
int		define_index(char **tab, int *argc);
void	free_tab(char **tab);
void	error_msg(char *str);
int		read_bsq_maps(int fd, int i, int argc, char **argv);

int	main(int argc, char **argv)
{
	int		fd;
	int		i;
	char	**tab;

	fd = 0;
	tab = handle_user_input(&argc, &argv);
	i = define_index(tab, &argc);
	if (read_bsq_maps(fd, i, argc, argv) == 0)
		return (error_msg("memory allocation for bsq map failed"), 1);
	if (tab)
		free_tab(tab);
	return (0);
}
