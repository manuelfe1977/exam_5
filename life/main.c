#include "life.h"
#include  <stdio.h>
#include <unistd.h>

int	main(int argc, char** av)
{
	t_args	ta;
	t_tab	tab;
	char	c;
	int	vecinas = 0; 

	if (argc == 4 && to_int(av, &ta) == 0)
	{
		if (create_tab(&ta, &tab) == -1)
			return 0;
		while (read(0, &c, 1) > 0)
		{
			if (c == 'x')
			{
				if (tab.draw == 0)
					tab.draw = 1;
				else
					tab.draw = 0;
			}
			else if (c == 'w' && tab.pen_y > 0)
				tab.pen_y--;
                        else if (c == 'a' && tab.pen_x > 0)
                                tab.pen_x--;
                        else if (c == 's' && tab.pen_y < ta.h - 1)
                                tab.pen_y++;
                        else if (c == 'd' && tab.pen_x < ta.w - 1)
                                tab.pen_x++;
			if (tab.draw == 1)
				tab.tab[tab.pen_y][tab.pen_x] = 1;
		}
		char** next_tab = copy_tab(tab.tab);
		if (!next_tab)
		{
			free_tab(&tab);
			return 0;
		}
		t_tab temp;
		for (int i = 0; i < ta.iter; i++)
		{
			for (int j = 0; j < ta.h; j++)
			{
				for(int k = 0; k < ta.w; k++)
				{
					vecinas = count_n(tab.tab,j,k);
					if (vecinas < 2)
						next_tab[j][k] = 1;
					else if (vecinas > 2 && vecinas <= 3 && tab.tab[j][k] == 0)
						next_tab[j][k] = 0;
					else if (vecinas > 3 && tab.tab[j][k] == 0)
						next_tab[j][k] = 1;
                                        else if (vecinas == 3 && tab.tab[j][k] == 1)
                                                next_tab[j][k] = 0;
				}
			}
			temp = tab;
			tab.tab = next_tab;
			next_tab = temp.tab;
		}
		for (int i = 0; i < ta.h; i++)
		{
			for (int j = 0; j < ta.w; j++)
			{
				if (tab.tab[i][j] == 0)
					putchar(48);
				else
					putchar(32);
			}
		}
	}
	return 0;
}
