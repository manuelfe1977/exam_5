#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class BigInt
{
	private:
		std::vector<int>	_digits;
		bool				_is_negative;
	public:
		BigInt();
		BigInt(int n);
		BigInt(const BigInt &num);
		BigInt &operator=(const BigInt &num);
		BigInt operator+(const BigInt &num) const;
		BigInt operator-(const BigInt &num) const;
		BigInt &operator+=(const BigInt &num);
		BigInt operator++(int num);
		BigInt &operator++();
		BigInt operator<<(unsigned int shift) const;
		BigInt operator>>(unsigned int shift) const;
		BigInt &operator<<=(unsigned int shift);
		BigInt &operator>>=(unsigned int shift);
		bool operator<(const BigInt &num) const;
		bool operator>(const BigInt &num) const;
		bool operator>=(const BigInt &num) const;
		bool operator<=(const BigInt &num) const;
		bool operator==(const BigInt &num) const;
		bool operator!=(const BigInt &num) const;
		~BigInt();


		const std::vector<int>	&getDigits() const;
		std::vector<int>		&getDigits();
		bool				getSign() const;
		void				setSign(bool sign);
};
BigInt ft_addition(const BigInt& a, const BigInt& b);
std::ostream& operator<<(std::ostream& os, const BigInt& obj);
BigInt ft_substraction(const BigInt& a, const BigInt& b);

#endif
