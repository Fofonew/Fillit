/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 07:10:04 by doriol            #+#    #+#             */
/*   Updated: 2017/04/21 08:17:58 by doriol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		next_tetri(int j, char *tab)
{
	while (j < 4)
	{
		if (tab[j] != '.')
			return (j);
		++j;
	}
	return (j);
}

int		ft_tetrifit(char **tab, char **map, int x, int y)
{
	int	i;
	int	j;
	int	is_ok;

	i = 0;
	j = 0;
	is_ok = 0;
	while (is_ok < 4 && i < 4)
	{
		j = next_tetri(j, tab[i]);
		if (j < 4)
		{
			if (++is_ok < 4 && tab[i][j + 1] == '.')
			{
				if (!(map[x + i] && map[x + i][y + j] == '.'))
					return (0);
				j = 0 * (++i);
			}
			else if (!(map[x + i] && map[x + i][y + j++] == '.'))
				return (0);
		}
	}
	return (1);
}

void	backup(char **map, int size, char letter)
{
	int	x;
	int	y;
	int	is_ok;

	x = -1;
	is_ok = 0;
	while (++x < size && is_ok < 4)
	{
		y = -1;
		while (++y < size && is_ok < 4)
			if (map[x][y] == letter)
			{
				map[x][y] = '.';
				++is_ok;
			}
	}
}

int		nbr_of_tetri(char **map, int size, int nb_total)
{
	int	nb;
	int	x;
	int	y;

	x = -1;
	nb = 0;
	while (++x < size)
	{
		y = -1;
		while (++y < size)
			if (map[x][y] >= 'A' && map[x][y] <= 'Z')
				++nb;
	}
	return (nb_total * 4 - nb);
}

int		solve_algo(char **map, int nb, char ***tab, int tetri)
{
	int	x;
	int	y;
	int	size;

	size = ft_strlen(map[0]);
	x = -1;
	if (!nbr_of_tetri(map, size, nb))
		return (1);
	y = size * size - 1;
	while (++x < y)
		if (ft_tetrifit(tab[tetri], map, x / size, x % size))
		{
			place_on_map(map, tab[tetri], x / size, x % size);
			if (solve_algo(map, nb, tab, tetri + 1) == 1)
				return (1);
			backup(map, size, tetri + 'A');
		}
	return (0);
}
