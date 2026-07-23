#include "bsq.h"

int	main(int argc, char** argv)
{
	int	i = 1;

	if (argc > 1)
	{
		while (i < argc)
		{
			if (exec_bsq(argv[i]) == -1)
				fprintf(stderr, "map error\n");
			if (i < argc - 1)
				fprintf(stdout, "\n");
			i++;
		}
	}
	else
		if(resolution_map(stdin) == -1)
			fprintf(stderr, "map error\n");
	return 0;
}
