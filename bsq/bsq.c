#include "bsq.h"


int	read_elements(FILE* file, t_elements* e)
{
	int read = fscanf(file, "%d %c %c %c", &(e->l), &(e->e), &(e->o), &(e->f));
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

	if (map->grid != NULL)
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
	char *str= (char*)malloc(sizeof(char) * (l + 1));
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
	char *line = NULL;
	size_t l = 0;
	if (getline(&line, &l, file) == -1)
	{
		free(line);
		return -1;
	}
	map->grid = (char**)calloc(sizeof(char*),  map->h + 1);
	if (!map->grid)
		return -1;
	map->grid[map->h] = NULL;
	for (int i = 0; i < map->h; i++)
	{
		int read = getline(&line, &l, file);
		if (read == -1)
		{
			free_map(map);
			free(line);
			return -1;
		}
		if (line[read-1] == '\n')
			read--;
		else
		{
			free_map(map);
			free(line);
			return -1;
		}
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
		while (map->grid[i] && map->grid[i][j] != '\0')
		{
			if (map->grid[i][j] != e->o && map->grid[i][j] != e->e)
			{
				free_map(map);
				free(line);
				return -1;
			}
			j++;
		}
	}
	free (line);
	return 0;
}

void	to_cero(int* arr, int size)
{
	for (int i = 0; i < size; i++)
		arr[i] = 0;
}

void print(int* arr, int size)
{
	for (int i = 0; i < size; i++)
		printf("%i", arr[i]);
}

int	ft_min(int a, int b, int c)
{
	int	min = a;
	if (b < a)
		min = b;
	if (c < min)
		min = c;
	return min;
}

void	find_square(t_map *map, t_elements *e, t_res *res)
{
	int *last = (int*)malloc(map->w * sizeof(int));
	int *current =(int*)malloc(map->w * sizeof(int));
	int* temp = NULL;
	//to_cero(last, map->w);
	for(int i = 0; i < map->h; i++)
	{
		for (int j = 0; j < map->w; j++)
		{
			if (map->grid[i][j] == e->o)
				current[j] = 0;
			else if (j == 0 || i == 0)
				current[j] = 1;
			else
				current[j] = 1 + ft_min(last[j], current[j-1], last[j-1]);
			if (current[j] > res->size)
			{
				res->size = current[j];
				res->i = i - current[j] + 1;
				res->j = j - current[j] + 1;
			}
		}
		temp = last;
		last = current;
		current = temp;
	}
	free(last);
	free(current);
}

void	print_map(t_map *map, t_elements *e, t_res *res)
{
	for(int r = res->i; r < res->i + res->size; r++)
		for(int c = res->j; c < res->j + res->size; c++)
		       map->grid[r][c] = e->f;
	int i = 0;
	while (map->grid[i] != NULL)
	{
		fputs(map->grid[i], stdout);
		fputs("\n", stdout);
		i++;
	}
}

int	resolution_map(FILE* file)
{
	t_elements	e;

	if (read_elements(file, &e) != 0)
		return -1;
	t_map map;
	if (read_map(file, &e, &map) != 0)
		return -1;
	t_res res;
	res.i = 0;
	res.j = 0;
	res.size = 0;
	find_square(&map, &e, &res);
	print_map(&map, &e, &res);
	free_map(&map);
	return 0;
}


int	exec_bsq(char* sfile)
{
	int		res = 0;
	FILE*		file;

	file = fopen(sfile, "r");
	if (!file)
		return -1;
	res = resolution_map(file);
	fclose(file);
	return res;
}
