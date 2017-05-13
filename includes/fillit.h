#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define TRUE 1
# define FALSE 0
# define BUF_SIZE 21

int		ft_puterror(void);
int		ft_get_tetri(char *av, char tab[26][4][4]);

int		ft_count(char buf[BUF_SIZE]);
int		ft_check_file(int fd, char tab[26][4][4]);
int		ft_content(char buf[BUF_SIZE]);
int		ft_check_tetri(char buf[BUF_SIZE], int n_read, int i);
int		ft_char(char c);

void	ft_up_left(char	tab[4][4]);
int		ft_get_offset_col(char tab[4][4]);
int		ft_get_offset_line(char tab[4][4]);
void	ft_rmoffset_line(char tab[4][4], int offset);
void	ft_rmoffset_col(char tab[4][4], int offset);

int		ft_strlen(char *str);
void	ft_stock_tetri(char buf[BUF_SIZE], char tab[4][4], int pos);

void	ft_rm_tetri(char **map, int size, char c);
int		ft_tetri_left(char **map, int size, int nb_total);
int		ft_finished(char **map, int nb_tetri, char tab[26][4][4], int tetris);
int		ft_solve_print(char **map, int nb_total, char tab[26][4][4]);

int		ft_next_alpha(int j, char tab[4]);
void	ft_init(int *check, int *i, int *j);
int		ft_checknext(char c, int *pos_i, int *pos_j);
int		ft_tetrifit(char tab[4][4], char **map, int m_i, int m_j);

void	ft_free_map(char **map, int size);
void	ft_addtomap(char **map, char tab[4][4], int k, int l);
int		ft_sqrt(int nb);
char	**ft_sqmap_dotalloc(int len);
void	ft_print_map(char **grid, int len);

#endif
