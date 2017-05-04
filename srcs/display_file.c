/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 20:09:50 by doriol            #+#    #+#             */
/*   Updated: 2017/04/22 01:25:49 by doriol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*piece_to_char(char *str)
{
	int		i;
	int		n;
	char	letter;

	letter = 'A';
	i = 0;
	n = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			str[i] = letter;
		}
		if (str[i] == '\n')
			n++;
		if (n == 5)
		{
			letter++;
			n = 0;
		}
		i++;
	}
	return (str);
}

char	***ft_display_file2(char **tab, int i)
{
	int		k;
	char	***tab2;

	k = 0;
	if (!(tab2 = malloc(sizeof(char ***) * (i + 1))))
		return (NULL);
	i = 0;
	while (tab[i])
	{
		if (!(tab2[k] = malloc(sizeof(char **) * 5)))
			return (NULL);
		if (!(tab2[k++] = ft_strsplit(tab[i++], '\n')))
			return (NULL);
	}
	tab2[k] = 0;
	k = -1;
	while (tab[++k])
	{
		to_up_left(tab2[k]);
	}
	return (tab2);
}

char	***ft_display_file(int nb)
{
	char	c;
	char	str[10000];
	int		i;
	char	**tab;

	i = 0;
	while (read(nb, &c, 1) != '\0')
		str[i++] = c;
	str[i] = '\0';
	if (ft_check_error(str) == 1)
	{
		i = 0;
		while (str[i += 20])
			if (str[i] != '\0')
				str[i++] = '%';
		*str = *piece_to_char(str);
		tab = ft_strsplit(str, '%');
		i = 0;
		while (tab[i])
			i++;
		return (ft_display_file2(tab, i));
		ft_cleaner(tab, i);
	}
	return (0);
}
