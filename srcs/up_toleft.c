/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_toleft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 03:51:56 by doriol            #+#    #+#             */
/*   Updated: 2017/04/21 10:28:28 by doriol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	rm_position_col(char **tab, int position)
{
	int	i;
	int	j;

	j = -1;
	while (++j < position && position < 4)
	{
		i = -1;
		while (++i < 4)
		{
			tab[i][j] = tab[i][position];
			tab[i][position] = '.';
		}
		++position;
	}
}

void	rm_position_line(char **tab, int position)
{
	int	i;
	int	j;

	i = -1;
	while (++i < position && position < 4)
	{
		j = -1;
		while (++j < 4)
		{
			tab[i][j] = tab[position][j];
			tab[position][j] = '.';
		}
		++position;
	}
}

int		get_position_col(char **tab)
{
	int	i;
	int	j;

	j = -1;
	while (++j < 4)
	{
		i = -1;
		while (++i < 4)
			if (tab[i][j] != '.')
				return (j);
	}
	return (j);
}

int		get_position_line(char **tab)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			if (tab[i][j] != '.')
				return (i);
	}
	return (i);
}

void	to_up_left(char **tab)
{
	int position;

	position = get_position_line(tab);
	if (position > 0)
		rm_position_line(tab, position);
	position = get_position_col(tab);
	if (position > 0)
		rm_position_col(tab, position);
}
