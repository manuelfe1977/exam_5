#include "Bigint.hpp"

int	main(void)
{

	const Bigint a(0);
	Bigint b(21), c, d(1333333337), e(1333333336) ;

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;
	std::cout << "e = " << e << std::endl;
	std::cout << "a + b = " << a + b << std::endl;
	std::cout << "(c += a) = " << (c += a) << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "++b = " << ++b << std::endl;
	std::cout << "b++ = " << b++ << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "(b + 42) << 0 = " << ((b + 42) << 0) << std::endl;
	std::cout << "(d <<= 4) = " << (d <<= 4) << std::endl;
	std::cout << "(d >>= 2) = " << (d >>= 2) << std::endl;
        std::cout << "(d >>= 2) = " << (d >>= (const Bigint)2) << std::endl;
	std::cout << "e =" << e << std::endl;
	std::cout << "d =" << e << std::endl;
	std::cout << "(d < e) = " << (d < e) << std::endl;
	std::cout << "(d <= e) = " << (d <= e) << std::endl;
	std::cout << "(d > e) = " << (d > e) << std::endl;
	std::cout << "(d >= e) = " << (d >= e) << std::endl;
	std::cout << "(d == e) = " << (d == e) << std::endl;
	std::cout << "(d != e) = " << (d != e) << std::endl;
	return 0;
}
