#include "BigInt.hpp"


int	main(void)
{

	BigInt a;
	BigInt b = 10;
	BigInt c(-15);
	BigInt d;
	
	a = b;
	d = a + c;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << (a < a) << std::endl;
	return 0;
}
