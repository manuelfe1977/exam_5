#ifndef BSQ_H
#define BSQ_H
#include <stdio.h>
#include <stdlib.h>

typedef struct s_elements{
	int	l;
	char	e;
	char	o;
	char	f;
}t_elements;

typedef struct s_map{
	char**	grid;
	int	w;
	int	h;
}t_map;

typedef struct s_res
{
	int	size;
	int	i;
	int	j;
}t_res;


int	exec_bsq(char* file);
int	resolution_map(FILE* file, t_elements* e);


#endif
