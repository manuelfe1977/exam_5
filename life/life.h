#ifndef LIFE_H
#define LIFE_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_args{
	int	w;
	int	h;
	int	it;
} t_args;

typedef struct s_square{
	char	**grid;
	int	x;
	int	y;
	int	d;
} t_square;

int	read_args(int argc, char **av, t_args *ta);
int	play_init(t_args *ta, t_square *sq);
void     play_iter(t_args *ta, t_square *sq);
void    print_square(t_args *ta, t_square *sq);
void    free_square(char **sq);

#endif
