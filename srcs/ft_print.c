/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 01:34:43 by doriol            #+#    #+#             */
/*   Updated: 2017/04/22 00:26:04 by doriol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		ft_error(char *s)
{
	write(1, s, ft_strlen(s));
	write(1, "\n", 1);
	return (-1);
}

void	ft_print_map(char **map, int size)
{
	int	y;

	y = 0;
	while (y < size)
	{
		write(1, map[y], size);
		write(1, "\n", 1);
		y++;
	}
}
