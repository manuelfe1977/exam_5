#include "life.h"

int	main(int argc, char **av)
{
	t_args 		ta;
	t_square	sq;

	if (read_args(argc, av, &ta) != 0)
		return 1;
	if (play_init(&ta, &sq) != 0)
		return 1;
	play_iter(&ta, &sq);
	print_square(&ta, &sq);
	free_square(sq.grid);

	return 0;
}
