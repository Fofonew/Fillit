/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 20:10:04 by doriol            #+#    #+#             */
/*   Updated: 2017/04/22 02:19:18 by doriol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	solve(char ***tab)
{
	int		size;
	int		nb_tetri;
	char	**map;

	nb_tetri = 0;
	while (tab[nb_tetri])
		nb_tetri++;
	size = ft_sqrt(nb_tetri * 4);
	map = ft_create_map(size);
	while (!solve_algo(map, nb_tetri, tab, 0))
	{
		ft_cleaner(map, size);
		size += 1;
		map = ft_create_map(size);
	}
	ft_print_map(map, size);
	ft_cleaner(map, size);
}

int		main(int argc, char **argv)
{
	int		disp;
	char	***tab;

	if (argc != 2)
		return (ft_error("error"));
	disp = open(argv[1], O_RDONLY);
	if (!(tab = ft_display_file(disp)))
		return (-1);
	solve(tab);
	close(disp);
	return (0);
}
