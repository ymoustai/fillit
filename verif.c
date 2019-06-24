/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 11:25:02 by mmounchi          #+#    #+#             */
/*   Updated: 2018/12/29 11:25:10 by mmounchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			verif_contact(char *str)
{
	int		i;
	int		bloc;

	i = 0;
	bloc = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if ((i + 1) < 20 && str[i + 1] == '#')
				bloc++;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				bloc++;
			if ((i + 5) < 20 && str[i + 5] == '#')
				bloc++;
			if ((i - 5) >= 0 && str[i - 5] == '#')
				bloc++;
		}
		i++;
	}
	return (bloc == 6 || bloc == 8);
}

int			verif_compte(char *str, int count)
{
	int		i;
	int		blocs;

	i = 0;
	blocs = 0;
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (!(str[i] == '#' || str[i] == '.'))
				return (1);
			if (str[i] == '#' && ++blocs > 4)
				return (2);
		}
		else if (str[i] != '\n')
			return (3);
		i++;
	}
	if (count == 21 && str[20] != '\n')
		return (4);
	if (!verif_contact(str))
		return (5);
	return (0);
}

t_tetri		*ft_read(int fd)
{
	int		r;
	char	buff[22];
	int		i;
	t_tetri	*tetris;

	i = 0;
	tetris = NULL;
	while ((r = read(fd, buff, 21)))
	{
		buff[r] = '\0';
		if (verif_compte(buff, r))
			return (NULL);
		if (tetris == NULL)
			tetris = tet_new('A', cord(buff));
		else
			tet_add(tetris, tet_new('A' + i, cord(buff)));
		i++;
	}
	if (r == 0 && buff[20] != '\0')
		return (NULL);
	if (i > 26)
		return (NULL);
	return (tetris);
}
