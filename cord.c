/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cord.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 11:04:30 by mmounchi          #+#    #+#             */
/*   Updated: 2018/12/29 11:26:34 by mmounchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri		*tet_new(char letter, t_point *cor)
{
	t_tetri	*result;

	result = malloc(sizeof(t_tetri));
	result->next = NULL;
	result->letter = letter;
	result->cor = cor;
	return (result);
}

void		tet_add(t_tetri *first, t_tetri *added)
{
	t_tetri	*temp;

	temp = first;
	while (temp->next)
		temp = temp->next;
	temp->next = added;
}

int			tet_size(t_tetri *first)
{
	int count;
	int i;

	count = 0;
	i = 2;
	while (first)
	{
		first = first->next;
		count++;
	}
	count *= 4;
	while (i * i < count)
		i++;
	return (i);
}

t_point		*cord(char *p)
{
	t_point	*final;
	int		i;
	int		j;
	int		o[2];

	final = malloc(sizeof(t_point) * 4);
	i = 0;
	j = 0;
	while (j < 4)
	{
		while (p[i] != '#')
			i++;
		if (j == 0)
		{
			o[0] = i % 5;
			o[1] = i / 5;
		}
		final[j].x = i % 5 - o[0];
		final[j].y = i / 5 - o[1];
		j++;
		i++;
	}
	return (final);
}
