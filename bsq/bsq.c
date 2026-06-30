#include "bsq.h"


int	read_elements(FILE* file, t_elements* e)
{
	int read = fscanf(file, "%d %c %c %c", &(e->l), &(e->o), &(e->e), &(e->f));
	if (read != 4)
		return -1;
	if (e->l <= 0)
		return -1;
	else if (e->o == e->e || e->o == e->f || e->e == e->f)
		return -1;
	else if (e->o < 32 || e->o > 126)
		return -1;
        else if (e->e < 32 || e->e > 126)
                return -1;
        else if (e->f < 32 || e->f > 126)
                return -1;
	return 0;
}

void	free_map(t_map *map)
{
	int i = 0;

	if (map->grid)
	{
		while(map->grid[i] != NULL)
		{
			if (map->grid[i])
				free(map->grid[i]);
			i++;
		}
		free(map->grid);
	}
}

char*	ft_substr(char* source, int s, int l)
{
	char *str= malloc(sizeof(char) * l +1);
	if (!str)
		return NULL;
	int i = 0;
	int j = 0;
	while (source[i] && source[i] != '\0')
	{
		if (i >=s && j < l)
		{
			str[j] = source[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return str;
}


int	read_map(FILE* file, t_elements* e, t_map* map)
{
	map->h = e->l;
	map->grid = (char**)malloc(sizeof(char*) * map->h + 1);
	map->grid[map->h] = NULL;

	char *line = NULL;
	size_t l = 0;
	if (getline(&line, &l, file) == -1)
	{
		free_map(map);
		return -1;
	}
	printf("aqui\n");
	for (int i = 0; i < map->h; i++)
	{
//		printf("aqui %i\n", i);
		int read = getline(&line, &l, file);
		if (read == -1)
		{
			free_map(map);
			free(line);
			return -1;
		}
//                printf("aqui %i\n", i);

		if (line[read-1] == '\n')
			read--;
		else
		{
                        free_map(map);
                        free(line);
                        return -1;
		}
                printf("aqui %i\n", i);
		map->grid[i] = ft_substr(line, 0, read);
		if (!map->grid[i])
		{
                        free_map(map);
                        free(line);
                        return -1;
		}
		if (i == 0)
			map->w = read;
		else
		{
			if (read != map->w)
			{
				free_map(map);
                        	free(line);
                        	return -1;
			}
		}
		int j = 0;
		while (map->grid[i][j] != '\0')
		{
			if (map->grid[i][j] != e->o && map->grid[i][j] != e->e)
			{
		                printf("aqui no deberia %i\n", i);

				free_map(map);
                                free(line);
                                return -1;
			}
			j++;
		}
	        fputs(line,stdout);
	}
	free (line);
	return 0;
}	

int	resolution_map(FILE* file, t_elements* e)
{
	int res_read_ele;

	if (read_elements(file, e) != 0)
		return -1;
	t_map map;
	if (read_map(file, e, &map) != 0)
		return -1;

}


int	exec_bsq(char* sfile)
{
	int		res;
	FILE*		file;
	t_elements	e;

	printf("%s\n", sfile);

	file = fopen(sfile, "r");
	if (!file)
		return -1;
	if (resolution_map(file, &e) != 0)
		return -1;

	return 0;

}
