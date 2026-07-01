#include "life.h"

#include <stdlib.h>

int	to_int(char** ar, t_args *ta)
{
	ta->w = atoi(ar[1]);
        ta->h = atoi(ar[2]);
        ta->iter = atoi(ar[3]);
	if (ta->w <= 0 || ta->h <=0 || ta->iter <=0)
		return -1;
	else
		return 0;	
}

void	free_tab(t_tab *t)
{
	if (t != NULL)
	{
		if (t->tab != NULL)
		{
			int i = 0;
			while (t->tab[i])
			{
				free(t->tab[i]);
				i++;
			}
			free(t->tab);
		}
	}
}


int	create_tab(t_args *ta, t_tab *tab)
{
	tab->pen_x = 0;
	tab->pen_y = 0;
	tab->draw = 0;
	tab->tab = (char**)calloc(sizeof(char*), ta->h + 1);
	if (!tab->tab)
		return -1;
	tab->tab[ta->h] = NULL;
	for (int i = 0; i < ta->h; i++)
	{
		tab->tab[i] = (char*)malloc(sizeof(char) * (ta->w + 1));
		if (!tab->tab[i])
		{
			free_tab(tab);
			return -1;
		}
		int k = 0;
		while (k < ta->w)
		{
			tab->tab[i][k] = 0;
			k++;
		}
		tab->tab[i][k] = '\0';
	}
	return 0;
}
