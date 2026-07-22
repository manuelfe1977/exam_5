#include "life.h"

int     read_args(int argc, char **av, t_args *ta)
{
	if (argc != 4)
		return 1;
	ta->w = atoi(av[1]);
	ta->h = atoi(av[2]);
	ta->it = atoi(av[3]);
	if (ta->w <= 0 || ta->h <= 0 || ta->it < 0)
		return 1;
	return 0;
}

int	create_tab(t_args *ta, t_square *sq)
{
	sq->grid = (char**)calloc(sizeof(char*), ta->h + 1);
	if (!sq->grid)
		return 1;
	sq->grid[ta->h] = NULL;
	for (int i = 0; i < ta->h; i++)
	{
		sq->grid[i] =(char*) calloc(sizeof(char), ta->w + 1);
		if (!sq->grid[i])
		{
			free_square(sq->grid);
			return 1;
		}
		int j = 0;
		while (j < ta->w)
		{
			sq->grid[i][j] = ' ';
			j++;
		}
		sq->grid[i][j] = '\0';
	}
	sq->x = 0;
	sq->y = 0;
	sq->d = 0;
	return 0;
}

int     play_init(t_args *ta, t_square *sq)
{
	char c;

	if (create_tab(ta, sq) != 0)
		return 1;
	while (read(0, &c, 1) == 1)
	{
		if (c == 'w')
		{
			if (sq->y > 0)
				sq->y--;
		}
		else if (c == 'a')
                {
                        if (sq->x > 0)
                                sq->x--;
                }
		else if (c == 's')
                {
                        if (sq->y < ta->h - 1)
                                sq->y++;
                }
		else if (c == 'd')
                {
                        if (sq->x < ta->w - 1)
                                sq->x++;
                }
		else if (c == 'x')
                        sq->d = !sq->d;
		else
			continue;
		if (sq->d && sq->y >= 0 && sq->y < ta->h && sq->x >= 0 && sq->x < ta->w)
			sq->grid[sq->y][sq->x] = 'O';
	}

	return 0;
}

char**	copy_grid(char** grid, int h, int w)
{
	char **copy = (char**)calloc(sizeof(char*), h + 1);
	if (!copy)
		return NULL;
	copy[h] = NULL;
	for (int i = 0; i < h; i++)
	{
		copy[i] = (char*)calloc(sizeof(char), w + 1);
		for(int j = 0; j < w; j++)
			copy[i][j] = grid[i][j];
		copy[i][w] = '\0';
	}
	return copy;
}

int	count_lives(t_args *ta, t_square *sq, int y, int x)
{
	int 	lives = 0;
	int	v_y = 0;
        int	v_x = 0;

	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (i== 0 && j == 0)
				continue;
			v_y = y + i;
			v_x = x + j;
			if (v_y >= 0 && v_y < ta->h && v_x >= 0 && v_x < ta->w)
			{
				if (sq->grid[v_y][v_x] == 'O')
					lives++;
			}
		}
	}


	return lives;
}

void     play_iter(t_args *ta, t_square *sq)
{
	int	n;
	char	**temp;
	char	**next;

	next = copy_grid(sq->grid, ta->h, ta->w);
	if (next)
	{
		for (int i = 0; i < ta->it; i++)
		{
			for (int k = 0; k < ta->h; k++)
			{
				for (int j = 0; j < ta->w; j++)
				{
					n = count_lives(ta, sq, k, j);
					if (sq->grid[k][j] == 'O')
					{
						if (n < 2)
							next[k][j] = ' ';
						else if (n >=2 && n <= 3)
							next[k][j] = 'O';
						else if (n > 3)
							next[k][j] = ' ';
					}
					else
					{
						if (n == 3)
							next[k][j] = 'O';
						else
							next[k][j] = ' ';
					}
				}
			}
			temp = next;
			next = sq->grid;
			sq->grid = temp;
		}
	}	
	free_square(next);
}

void     print_square(t_args *ta, t_square *sq)
{
	for (int i = 0; i < ta->h; i++)
	{
		for (int j = 0; j < ta->w; j++)
			putchar(sq->grid[i][j]);
		putchar('\n');
	}	
}

void     free_square(char **sq)
{
	if (sq)
	{
		int i = 0;
		while (sq[i])
		{
			free(sq[i]);
			i++;
		}
		free(sq);
	}
}
