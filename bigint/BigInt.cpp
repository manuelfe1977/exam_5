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

BigInt ft_substraction(const BigInt& a, const BigInt& b)
{
	BigInt	result;
	BigInt	copy_a;
	BigInt	copy_b;
	BigInt	swap;

	swap = a;
	copy_a = a;
	copy_b = b;
	if (&a >= &b)
		result._is_negative = false;
	else
	{
		result._is_negative = true;
		swap = copy_a;
		copy_a = copy_b;
		copy_b = swap;
	}

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
		if (this > &num)
			result = this - &num;
		else
			result = &num - this;
	}
	return result;
}

BigInt BigInt::operator-(const BigInt &num) const
{
	BigInt	result;
	BigInt	copy_num;

	if (!this->_is_negative && !num._is_negative)
		result = ft_substraction(*this, num);
	if (!this->_is_negative && num._is_negative)
	{
		copy_num = BigInt(num);
		result = *this + copy_num;
	}
	if (this->_is_negative && !num._is_negative)
	{
		copy_num = BigInt(*this);
		copy_num._is_negative = false;
		result = copy_num + num;
		result._is_negative = true;
	}
	if (this->_is_negative && num._is_negative)
		result = num - *this;
	return result;
}

bool ft_comparation(std::vector<int> a, std::vector<int> b)
{
	bool	res = false;
	int		i = 0;

	if (a.size() > b.size())
		res = true;
	else if (a.size() < b.size())
		res = false;
	else
	{
		while (i >= a.size() - 1)
		{
			if (a[i] > b[i])
			{
				res = true;
				break;
			}
			else if (a[i] < b[i])
			{
				res = false;
				break;
			}
			i++;
		}
	}
	return res;
}

bool BigInt::operator>(const BigInt &num)
{
	bool	res = false;

	if ((this->_is_negative && num._is_negative) || (!this->_is_negative && !num._is_negative))
		res = ft_comparation(this->_digits, num._digits);
	else if (!this->_is_negative && num._is_negative)
		res = true;
	return res;
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



