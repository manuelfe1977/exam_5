#include "BigInt.hpp"


int	main(void)
{

	BigInt a;
	BigInt b = -10;
	BigInt c(15);
	BigInt d(c);
	
	a = b;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;

	return 0;
}
