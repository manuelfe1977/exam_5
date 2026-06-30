#include "bsq.h"
#include <stdio.h>

int	main(int argc, char** argv)
{
	int	i = 1;

	if (argc > 1)
	{
		while (i < argc)
		{
			if (exec_bsq(argv[i]) == 0)
				printf("mapa procesado");
			printf("\n");
			i++;
		}
	}
	else
		if(execute_bsq(stdin) == -1)
			fprintf(stderr, "map error\n");
	return 0;
}
