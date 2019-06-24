/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 11:27:29 by mmounchi          #+#    #+#             */
/*   Updated: 2018/12/29 11:27:32 by mmounchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int argc, char **argv)
{
	int		fd;
	char	**tab;
	t_tetri	*tetris;
	int		size;

	if (argc != 2)
	{
		write(1, "Usage: ./fillit <fichier>\n", 26);
		return (1);
	}
	tab = tabgen();
	fd = open(argv[1], O_RDONLY);
	if (!(tetris = ft_read(fd)))
	{
		write(1, "error\n", 6);
		return (1);
	}
	close(fd);
	size = tet_size(tetris);
	inittab(tab, size);
	back(tetris, tab, size);
	printtab(tab);
	return (0);
}
