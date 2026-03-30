#include "BigInt.hpp"

BigInt::BigInt()
{
	this->_is_negative = false;
	//this->_digits.push_back(0);
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
	int	max_len = std::max(a.getDigits().size(), b.getDigits().size());
	int	i = 0;
	int	sum1 = 0;
	int	sum2 = 0;
	int	res = 0;

	while (i < max_len)
	{
		if (i < a.getDigits().size())
			sum1 = a.getDigits()[i];
		else
			sum1 = 0;
		if (i < b.getDigits().size())
			sum2 = b.getDigits()[i];
		else
			sum2 = 0;
		res = sum1 + sum2 + carry;
		carry = res / 10;
		result.getDigits().push_back(res % 10);
		i++;
	}
	if (carry > 0)
		result.getDigits().push_back(carry);
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
		result.setSign(false);
	else
	{
		result.setSign(true);
		swap = copy_a;
		copy_a = copy_b;
		copy_b = swap;
	}

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

BigInt &BigInt::operator+=(const BigInt &num)
{
	*this = *this + num;
	return *this;
}

BigInt &BigInt::operator++()
{
    *this = *this + 1;
    return *this;
}

BigInt BigInt::operator++(int num)
{
	BigInt temp;

	(void)num;
	temp = *this;
	*this = *this + 1;
	return temp;
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
		while (i >= (int)a.size() - 1)
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

bool BigInt::operator<=(const BigInt &num)
{
	int	i = (int) this->_digits.size() - 1;

	if (this->_is_negative && !num._is_negative)
		return true;
	else if (!this->_is_negative && num._is_negative)
		return false;
	else
	{
		if ((this->_digits.size() > num._digits.size()) && this->_is_negative)
			return true;
		else if ((this->_digits.size() > num._digits.size()) && !this->_is_negative)
			return false;
		else if ((this->_digits.size() < num._digits.size()) && this->_is_negative)
			return false;
		else if ((this->_digits.size() < num._digits.size()) && !this->_is_negative)
			return true;
		else if (this->_digits.size() == num._digits.size())
		{
			while (i >= 0)
			{
				if ((this->_digits[i] > num._digits[i]) && !this->_is_negative)
					return false;
				else if ((this->_digits[i] > num._digits[i]) && this->_is_negative)
					return true;
				else if ((this->_digits[i] < num._digits[i]) && !this->_is_negative)
					return true;
				else if ((this->_digits[i] < num._digits[i]) && this->_is_negative)
					return false;
				i--;
			}
		}
		if (i == -1)
			return true;
	}
}

bool BigInt::operator>=(const BigInt &num)
{
	return &num <= this;
}

bool BigInt::operator==(const BigInt &num)
{
	int	i = (int) this->_digits.size() - 1;

	if ((this->_is_negative == num._is_negative || !this->_is_negative == !num._is_negative)
		&& (this->_digits.size() == num._digits.size()))
	{
		while (i >= 0)
		{
			if (this->_digits[i] != num._digits[i])
				return false;
			i--;
		}
		if (i == -1)
			return true;
	}
	else
		return false;
}

bool BigInt::operator!=(const BigInt &num)
{
	return !(this == &num);
}

BigInt	BigInt::operator<<(unsigned int shift) const
{
	BigInt copy;

	if (this->_digits.size() == 0 && this->_digits[0] == 0)
		return BigInt(0);
	else
	{
		copy = *this;
		copy._digits.insert(copy._digits.begin(), shift, 0);
		return copy;
	}
}

BigInt	BigInt::operator>>(unsigned int shift) const
{
	BigInt copy;

	if ((this->_digits.size() == 0 && shift > 0) || shift > this->_digits.size())
		return BigInt(0);
	else
	{
		copy = *this;
		copy._digits.erase(copy._digits.begin(),copy._digits.begin() + shift);
		return copy;
	}
}

BigInt	&BigInt::operator<<=(unsigned int shift)
{
	BigInt copy;

	if (this->_digits.size() == 0 && this->_digits[0] == 0)
		return *this;
	this->_digits.insert(this->_digits.begin(), shift, 0);
	return *this;
}

BigInt::~BigInt(){}


std::vector<int>	BigInt::getDigits() const
{
	return this->_digits;
}

bool	BigInt::getSign() const
{
	return this->_is_negative;
}

void	BigInt::setSign(bool sign)
{
	this->_is_negative = sign;
}

std::ostream& operator<<(std::ostream& os, const BigInt& obj)
{
	if (obj.getSign() && !(obj.getDigits().size() == 1 && obj.getDigits()[0] == 0))
		os << '-';
	for (int i = obj.getDigits().size() - 1; i >= 0; --i)
		os << obj.getDigits()[i];
	os << '\n';

	return os;
}
