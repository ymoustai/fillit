/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 09:44:10 by mmounchi          #+#    #+#             */
/*   Updated: 2018/12/29 11:33:40 by mmounchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <fcntl.h>

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_tetri
{
	char			letter;
	t_point			*cor;
	struct s_tetri	*next;
}					t_tetri;

int					verif_compte(char *str, int count);
int					verif_contact(char *str);
t_tetri				*ft_read(int fd);
char				**tabgen(void);
void				inittab(char **tab, int size);
void				printtab(char **tab);
t_point				*cord(char *p);
t_tetri				*tet_new(char letter, t_point *cor);
void				tet_add(t_tetri *first, t_tetri *added);
void				point(t_point *point);
int					ft_place(t_tetri *tet, char **p, int x, int y);
int					ft_unplace(t_tetri *tet, char **map, int x, int y);
int					back(t_tetri *tet, char **map, int size);
int					tet_size(t_tetri *first);

#endif
