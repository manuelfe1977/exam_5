#include "BigInt.hpp"

BigInt::BigInt()
{
	this->_is_negative = false;
	this->_digits.push_back(0);
}

BigInt::BigInt(int n)
{
	if (n < 0)
	{
		this->_is_negative= true;
		n = n * - 1;
	}
	else
		this->_is_negative = false;
	while (n > 9)
	{
		this->_digits.push_back(n % 10);
		n = n / 10;
	}
	this->_digits.push_back(n);
}

BigInt::BigInt(const BigInt &num)
{
	this->_is_negative = num._is_negative;
	this->_digits = num._digits;
}

BigInt &BigInt::operator=(const BigInt &num)
{
	if (this != &num)
	{
		this->_is_negative = num._is_negative;
		this->_digits = num._digits;
	}
	return *this;
}

BigInt::operator+(const BigInt &num) const
{
	BigInt	result;
	int	carry = 0;
	int	max_len = max(this->_digits.size(), num._digits.size());
}


BigInt::~BigInt(){}

std::ostream& operator<<(std::ostream& os, const BigInt& obj)
{
	if (obj._is_negative && !(obj._digits.size() == 1 && obj._digits[0] == 0))
		os << '-';
	for (int i = obj._digits.size() - 1; i >= 0; --i)
		os << obj._digits[i];
	os << '\n';

	return os;
}
                


