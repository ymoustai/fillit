/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 11:34:09 by mmounchi          #+#    #+#             */
/*   Updated: 2018/12/29 11:34:14 by mmounchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_place(t_tetri *tet, char **map, int x, int y)
{
	int		j;

	j = 0;
	while (j < 4)
	{
		if (y + tet->cor[j].y < 0 || x + tet->cor[j].x < 0)
			return (0);
		if (map[y + tet->cor[j].y][x + tet->cor[j].x] == '.')
			j++;
		else
			return (0);
	}
	j = 0;
	while (j < 4)
	{
		map[y + tet->cor[j].y][x + tet->cor[j].x] = tet->letter;
		j++;
	}
	return (1);
}

int			ft_unplace(t_tetri *tet, char **map, int x, int y)
{
	int		j;

	j = 0;
	while (j < 4)
	{
		map[y + tet->cor[j].y][x + tet->cor[j].x] = '.';
		j++;
	}
	return (1);
}

int			back(t_tetri *tet, char **map, int size)
{
	int		i;
	int		j;

	i = -1;
	while (map[++i][0] != '$' && (j = -1))
	{
		while (map[i][++j] != '$')
		{
			if (ft_place(tet, map, j, i))
			{
				if (!tet->next)
					return (1);
				if (back(tet->next, map, size))
					return (1);
				else
					ft_unplace(tet, map, j, i);
			}
		}
	}
	if (tet && tet->letter == 'A')
	{
		inittab(map, size + 1);
		back(tet, map, size + 1);
	}
	return (0);
}
