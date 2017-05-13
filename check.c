/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkrifa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 18:56:34 by nkrifa            #+#    #+#             */
/*   Updated: 2017/05/13 18:56:35 by nkrifa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_char(char c)
{
	return (c == '.' || c == '#' || c == '\n' ? TRUE : FALSE);
}

int		ft_count(char buf[BUF_SIZE])
{
	int i;
	int n;

	n = 0;
	i = -1;
	while (++i < 20)
		if (buf[i] == '#')
			++n;
	return (n == 4 ? TRUE : FALSE);
}

int		ft_content(char buf[BUF_SIZE])
{
	int i;
	int check;
	int prev;

	i = -1;
	check = 0;
	while (++i < 20 && check < 3)
	{
		prev = check;
		if (buf[i] == '#')
		{
			if (buf[i + 1] == '#')
				++check;
			if (buf[i + 5] == '#')
				++check;
			if (prev == 2 && check == 2)
				continue ;
			else if (prev == check)
				return (FALSE);
		}
	}
	return (check != 3 ? FALSE : TRUE);
}

int		ft_check_tetri(char buf[BUF_SIZE], int n_read, int i)
{
	while (i < n_read)
		if (ft_char(buf[i++]) == FALSE)
			return (FALSE);
	if (n_read == 21 && buf[i - 1] != '\n')
		return (FALSE);
	n_read == 21 ? --i : i;
	while (i > 0)
	{
		if (buf[i - 1] != '\n')
			return (FALSE);
		i -= 5;
	}
	if (ft_count(buf) == FALSE)
		return (FALSE);
	return (ft_content(buf) == FALSE ? FALSE : TRUE);
}

int		ft_check_file(int fd, char tab[26][4][4])
{
	char	buf[BUF_SIZE];
	int		n_read;
	int		prev;
	int		pos;

	pos = 0;
	while ((n_read = read(fd, buf, BUF_SIZE)) == 21 || n_read == 20)
	{
		if ((ft_check_tetri(buf, n_read, 0)) == FALSE)
			return (FALSE);
		ft_stock_tetri(buf, tab[pos], pos);
		++pos;
		if (pos > 25)
			return (FALSE);
		prev = n_read;
	}
	return (n_read != 0 || prev != 20 ? FALSE : pos);
}
