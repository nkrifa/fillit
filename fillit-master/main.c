#include "fillit.h"

int		ft_puterror(void)
{
	write(1, "error\n", 6);
	return (1);
}

int		ft_get_tetri(char *av, char tab[26][4][4])
{
	int		fd;
	int		i;

	fd = open(av, O_RDONLY);
	if (fd < 0)
		return (FALSE);
	i = ft_check_file(fd, tab);
	close(fd);
	return (i);
}

int		main(int ac, char **av)
{
	char	tab[26][4][4];
	char	**map;
	int		nb_tetri;
	int		size;

	if (ac != 2)
		return (ft_puterror());
	nb_tetri = ft_get_tetri(av[1], tab);
	if (nb_tetri == FALSE)
		return (ft_puterror());
	size = ft_sqrt(nb_tetri * 4);
	map = ft_sqmap_dotalloc(size);
	while (!ft_finished(map, nb_tetri, tab, 0))
	{
		ft_free_map(map, size);
		++size;
		map = ft_sqmap_dotalloc(size);
	}
	ft_print_map(map, size);
	ft_free_map(map, size);
	return (0);
}
