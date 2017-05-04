/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 19:43:57 by doriol            #+#    #+#             */
/*   Updated: 2017/04/21 07:54:53 by doriol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

int		ft_tetrifit(char **tab, char **map, int x, int y);
int		solve_algo(char **map, int nb, char ***tab, int tetri);
void	place_on_map(char **map, char **tab, int x, int y);
void	ft_print_map(char **map, int size);
char	**ft_create_map(int size);
void	ft_print_map(char **map, int size);
char	***ft_display_file(int nb);
char	***ft_display_file2(char **tab, int i);
char	*piece_to_char(char *str);
void	print_table(char ***tab2, char *str);
void	ft_putstr(char const *s);
void	ft_putchar(char c);
char	**ft_strsplit(char const *s, char c);
size_t	ft_strlen(const char *s);
int		ft_verif_forme(char *av);
int		ft_error(char *s);
int		ft_check_error(char *av);
int		ft_verif_block(char *av);
int		ft_verif_line(char *av);
int		ft_verif_tetri(char *av);
char	**ft_cleaner(char **tab, int len);
void	to_up_left(char **tab);
int		ft_sqrt(int nb);

#endif
