#include "fillit.h"

void	ft_rmoffset_line(char tab[4][4], int offset)
{
	int i;
	int j;

	i = -1;
	while (++i < offset && offset < 4)
	{
		j = -1;
		while (++j < 4)
		{
			tab[i][j] = tab[offset][j];
			tab[offset][j] = '.';
		}
		++offset;
	}
}

void	ft_rmoffset_col(char tab[4][4], int offset)
{
	int i;
	int j;

	i = -1;
	while (++i < offset && offset < 4)
	{
		j = -1;
		while (++j < 4)
		{
			tab[j][i] = tab[j][offset];
			tab[j][offset] = '.';
		}
		++offset;
	}
}

int		ft_get_offset_line(char tab[4][4])
{
	int i;
	int j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			if (tab[i][j] != '.')
				return (i);
	}
	return (i);
}

int		ft_get_offset_col(char tab[4][4])
{
	int i;
	int j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			if (tab[j][i] != '.')
				return (i);
	}
	return (i);
}

void	ft_up_left(char tab[4][4])
{
	int offset;

	offset = ft_get_offset_line(tab);
	if (offset > 0)
		ft_rmoffset_line(tab, offset);
	offset = ft_get_offset_col(tab);
	if (offset > 0)
		ft_rmoffset_col(tab, offset);
}
