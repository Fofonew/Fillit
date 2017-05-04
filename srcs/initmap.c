/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 06:48:29 by doriol            #+#    #+#             */
/*   Updated: 2017/04/21 09:26:16 by doriol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_create_map(int size)
{
	char	**map;
	int		x;
	int		y;

	x = -1;
	if (!size)
		return (NULL);
	if (!(map = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	while (++x < size)
	{
		if (!(map[x] = (char *)malloc(sizeof(char) * (size + 1))))
			return (NULL);
		y = -1;
		while (++y < size)
			map[x][y] = '.';
		map[x][y] = 0;
	}
	map[size] = 0;
	return (map);
}

void	place_on_map(char **map, char **tab, int x, int y)
{
	int		i;
	int		j;
	int		is_ok;

	i = 0;
	is_ok = 0;
	while (map[x] && is_ok < 4)
	{
		j = -1;
		while (++j < 4)
			if (map[x][y + j] == '.' && (tab[i][j] >= 'A' && tab[i][j] <= 'Z'))
			{
				map[x][y + j] = tab[i][j];
				++is_ok;
			}
		++i;
		++x;
	}
}

int		ft_sqrt(int nb)
{
	int i;

	i = 1;
	while (i * i < nb)
		++i;
	return (i);
}
