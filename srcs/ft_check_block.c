/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_block.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 03:55:07 by doriol            #+#    #+#             */
/*   Updated: 2017/04/22 02:02:11 by doriol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		verif_tetri2(char *av, int i, int y, int count)
{
	while (av[++i])
	{
		if (i % 21 == 0 && i != 0)
		{
			if (count != 4 && count != 0)
				return (ft_error("error"));
			y++;
			count = 0;
		}
		if (av[i] == ('A' + y))
			if (count++ > 0 && ((av[i - 5] != ('A' + y))
						&& (av[i - 1] != ('A' + y))))
				if (((av[i + 1] != ('A' + y)) || (av[i - 4] != ('A' + y)))
					&& ((av[i + 2] != ('A' + y)) || (av[i - 3] != ('A' + y))))
					return (ft_error("error"));
	}
	if (count != 4)
		return (ft_error("error"));
	return (1);
}

int		ft_verif_tetri(char *av)
{
	int	count;
	int	i;
	int	y;

	y = 0;
	i = -1;
	count = 0;
	av = piece_to_char(av);
	return (verif_tetri2(av, i, y, count));
}

int		ft_verif_line(char *av)
{
	int	x;
	int	j;

	x = 0;
	while (av[x])
	{
		j = 0;
		while (av[x] != '\n' && av[x])
		{
			x++;
			j++;
		}
		if (j != 4 && av[x - 1] != '\n')
			return (ft_error("error"));
		x++;
	}
	return (1);
}

int		ft_verif_block(char *av)
{
	int	i;
	int	y;

	i = 0;
	while (av[i])
	{
		y = 0;
		while (y < 4 && av[i] && av[i] != '\n')
		{
			i += 5;
			y++;
		}
		if ((av[i] == '.' || av[i] == '#') && av[i])
			return (ft_error("error"));
		if (av[i] == '\n' && av[i])
		{
			if (av[i - 2] == '\n')
				return (ft_error("error"));
			i++;
		}
	}
	return (1);
}

int		ft_check_error(char *av)
{
	int	i;

	i = -1;
	while (av[++i])
		if (av[i] != '.' && av[i] != '#' && av[i] != '\n')
			return (ft_error("error"));
	if ((av[i - 1] == '\n' && av[i - 2] == '\n') || av[i - 1] != '\n')
		return (ft_error("error"));
	if (ft_verif_line(av) == 1)
	{
		if (ft_verif_block(av) == 1 && ft_verif_tetri(av) == 1)
			return (1);
	}
	return (0);
}
