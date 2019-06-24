/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 10:23:49 by mmounchi          #+#    #+#             */
/*   Updated: 2018/12/29 11:25:53 by mmounchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**tabgen(void)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	tab = (char**)malloc(sizeof(char *) * 21);
	tab[20] = NULL;
	while (i < 20)
	{
		j = 0;
		tab[i] = malloc(21);
		while (j < 20)
			tab[i][j++] = '$';
		tab[i][j] = '\0';
		i++;
	}
	return (tab);
}

void		inittab(char **tab, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			tab[i][j] = '.';
			j++;
		}
		i++;
	}
}

void		printtab(char **tab)
{
	int		i;
	int		j;

	i = 0;
	while (tab[i][0] != '$')
	{
		j = 0;
		while (tab[i][j] != '$')
			ft_putchar(tab[i][j++]);
		ft_putchar('\n');
		i++;
	}
}
