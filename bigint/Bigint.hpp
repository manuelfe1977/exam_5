#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Bigint
{
	private:
		std::vector<int>	_digits;
	public:
		Bigint();
		Bigint(unsigned int num);
		Bigint(const Bigint &num);
		Bigint &operator=(const Bigint &num);
		Bigint operator+(const Bigint &num) const;
		Bigint &operator+=(const Bigint &num);
		Bigint operator++(int num);
		Bigint &operator++();
		Bigint operator>>(size_t shift) const;
		Bigint &operator>>=(const size_t shift);
		Bigint operator<<(size_t shift) const;
		Bigint &operator<<=(const size_t shift);
		Bigint &operator>>=(const Bigint &shift);
		Bigint &operator<<=(const Bigint &shift);
		bool operator>(const Bigint &num) const;
		bool operator<(const Bigint &num) const;
		bool operator>=(const Bigint &num) const;
		bool operator<=(const Bigint &num) const;
		bool operator==(const Bigint &num) const;
		bool operator!=(const Bigint &num) const;
		const std::vector<int> &get_digits() const;
		std::vector<int> &get_digits();
		~Bigint();
};

std::ostream& operator<<(std::ostream& os, const Bigint &n);

#endif
