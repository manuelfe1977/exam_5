#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <vector>
#include <math.h>

class BigInt
{
	private:
		std::vector<int>	_digits;
		bool			_is_negative;
	public:
		BigInt();
		BigInt(int n);
		BigInt(const BigInt &num);
		BigInt &operator=(const BigInt &num);
		BigInt operator+(const BigInt &num) const;
		BigInt operator-(const BigInt &num) const;
		BigInt operator+=(const BigInt &num);
		BigInt operator++(int num);
		BigInt operator++();
		BigInt operator<<(unsigned int shift) const;
		BigInt &operator<<=(unsigned int shift);
		BigInt &operator>>=(unsigned int shift);
		bool operator<(const BigInt &num);
		bool operator>(const BigInt &num);
		bool operator>=(const BigInt &num);
		bool operator<=(const BigInt &num);
		bool operator==(const BigInt &num);
		bool operator!=(const BigInt &num);
		~BigInt();

		friend std::ostream& operator<<(std::ostream& os, const BigInt& obj);
		friend BigInt ft_addition(const BigInt& a, const BigInt& b);
		friend BigInt ft_substraction(const BigInt& a, const BigInt& b);
};



#endif
