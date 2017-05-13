/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkrifa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 18:56:53 by nkrifa            #+#    #+#             */
/*   Updated: 2017/05/13 18:56:55 by nkrifa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	if (str)
		while (str[i])
			++i;
	return (i);
}

void	ft_stock_tetri(char buf[BUF_SIZE], char tab[4][4], int pos)
{
	int i;
	int j;
	int k;

	k = 0;
	i = -1;
	while (++i < 4 && k < 20)
	{
		j = -1;
		while (++j < 4)
		{
			if (buf[k] == '.')
				tab[i][j] = '.';
			else if (buf[k] == '#')
				tab[i][j] = 'A' + pos;
			if (k + 1 == 4 || k + 1 == 9 || k + 1 == 14)
				++k;
			++k;
		}
	}
	ft_up_left(tab);
}
