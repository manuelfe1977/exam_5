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

BigInt ft_addition(const BigInt& a, const BigInt& b)
{
	BigInt	result;
	int	carry = 0;
	int	max_len = max(a._digits.size(), b._digits.size());
	int	i = 0;
	int	sum1 = 0;
	int	sum2 = 0;
	int	res = 0;

	while (i < max_len)
	{
		if (i < a._digits.size())
			sum1 = a._digits[i];
		else
			sum1 = 0;
		if (i < b._digits.size())
			sum2 = b._digits[i];
		else
			sum2 = 0;
		res = sum1 + sum2 + carry;
		carry = res / 10;
		result._digits.push_back(res % 10);
		i++;
	}
	if (carry > 0)
		result._digits.push_back(carry);
	return result;
}

BigInt BigInt::operator+(const BigInt &num) const
{
	BigInt	result;

	if (this->_is_negative && num._is_negative)
	{
		result = ft_addition(*this, num);
		result._is_negative = true;
	}
	if (!this->_is_negative && !num._is_negative)
	{
		result = ft_addition(*this, num);
		result._is_negative = false;
	}
	if (this->_is_negative != num._is_negative)
	{
		/* code */
	}

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



