#ifndef LIFE_H
#define LIFE_H

typedef struct	s_args{
	int	w;
	int	h;
	int	iter;
}t_args;

typedef struct	t_tab{
	int	pen_x;
	int	pen_y;
	int	draw;
	char**	tab;
}t_tab;

int     to_int(char** ar, t_args *ta);
int     create_tab(t_args *ta, t_tab *tab);
void    free_tab(t_tab *t);

#endif



