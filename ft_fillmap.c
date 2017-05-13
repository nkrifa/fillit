/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkrifa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 18:56:44 by nkrifa            #+#    #+#             */
/*   Updated: 2017/05/13 18:56:46 by nkrifa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_next_alpha(int j, char tab[4])
{
	while (j < 4)
	{
		if (tab[j] != '.')
			return (j);
		++j;
	}
	return (j);
}

int		ft_tetrifit(char tab[4][4], char **map, int m_i, int m_j)
{
	int i;
	int j;
	int check;

	i = 0;
	j = 0;
	check = 0;
	while (check < 4 && i < 4)
	{
		j = ft_next_alpha(j, tab[i]);
		if (j < 4)
		{
			if (++check < 4 && tab[i][j + 1] == '.')
			{
				if (!(map[m_i + i] && map[m_i + i][m_j + j] == '.'))
					return (FALSE);
				j = 0 * (++i);
			}
			else if (!(map[m_i + i] && map[m_i + i][m_j + j++] == '.'))
				return (FALSE);
		}
	}
	return (TRUE);
}
