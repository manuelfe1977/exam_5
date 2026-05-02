#include "Bigint.hpp"

Bigint::Bigint()
{
	this->_digits.push_back(0);
}

Bigint::Bigint(unsigned int num)
{
	while (num > 9)
	{
		this->_digits.push_back(num % 10);
		num = num / 10;
	}
	this->_digits.push_back(num);
}

Bigint::Bigint(const Bigint &num)
{
	this->_digits = num._digits;
}

Bigint &Bigint::operator=(const Bigint &num)
{
	if (this != &num)
		this->_digits = num._digits;
	return *this;
}

Bigint Bigint::operator+(const Bigint &num) const
{
	size_t	digitos = 0;
	Bigint	result;
	int	acarreo = 0;
	int	suma = 0;
	size_t	i = 0;

	result._digits.clear();
	if (this->_digits.size() > num._digits.size())
		digitos = this->_digits.size() - 1;
	else
		digitos = num._digits.size() - 1;
	while (i <= digitos)
	{
		if (i < num._digits.size() && i < this->_digits.size())
			suma = this->_digits[i] + num._digits[i] + acarreo;
		else if (i < num._digits.size() && i >= this->_digits.size())
			suma = num._digits[i] + acarreo;
		else
			suma = this->_digits[i] + acarreo;
		if (suma > 9)
		{
			result._digits.push_back(suma % 10);
			acarreo = 1;
		}
		else
		{
			result._digits.push_back(suma);
			acarreo = 0;
		}
		i++;
	}
	if (acarreo > 0)
		result._digits.push_back(acarreo);
	return result;
}

Bigint &Bigint::operator+=(const Bigint &num)
{
	*this = *this + num;
	return *this;
}

Bigint::~Bigint(){}

Bigint &Bigint::operator++()
{
	Bigint a(1);
	*this += a;
	return *this;
}

Bigint Bigint::operator++(int num)
{
	Bigint temp;
	Bigint a(1);
	(void)num;

	temp = *this;
	*this += a;
	return temp;

}

Bigint Bigint::operator<<(size_t shift) const
{
	Bigint result = *this;

	if (result._digits.size() == 1 && result._digits[0] == 0)
		return result;
	result._digits.insert(result._digits.begin(), shift, 0);
	return result;
}

Bigint &Bigint::operator<<=(size_t shift)
{
        if (this->_digits.size() == 1 && this->_digits[0] == 0)
                return *this;
        this->_digits.insert(this->_digits.begin(), shift, 0);

	return *this;
}

Bigint Bigint::operator>>(size_t shift) const
{
	Bigint result = *this;

	if (shift >= this->_digits.size())
	{
		result._digits.clear();
		result._digits.push_back(0);
	}
	else
		result._digits.erase(result._digits.begin(), result._digits.begin() + shift);
	return result;

}

Bigint &Bigint::operator>>=(const size_t shift)
{
	if (shift >= this->_digits.size())
        {
                this->_digits.clear();
                this->_digits.push_back(0);
        }
        else
                this->_digits.erase(this->_digits.begin(), this->_digits.begin() + shift);
        return *this;
}

static long long big_to_int(const Bigint &num)
{
	long long	shift = 0;
	size_t	power = 1;

	for (int i = 0; i < (int)num.get_digits().size(); i++)
	{
		shift += num.get_digits()[i] * power;
		power *= 10;
	}
	return shift;
}

Bigint &Bigint::operator>>=(const Bigint &shift)
{
	size_t s;

	s = big_to_int(shift);
	return (*this>>=s);

}

Bigint &Bigint::operator<<=(const Bigint &shift)
{
        size_t s;

        s = big_to_int(shift);

        return (*this<<=s);

}

bool Bigint::operator>(const Bigint &num) const
{
	if (this->_digits.size() > num._digits.size())
		return true;
	else if (this->_digits.size() < num._digits.size())
		return false;
	else
	{
		for(int i = (int)this->_digits.size() - 1; i >= 0; i--)
		{
			if (this->_digits[i] > num._digits[i])
				return true;
			else if (this->_digits[i] < num._digits[i])
				return false;
		}
	}
	return false;
}

bool Bigint::operator<(const Bigint &num) const
{
	return !(*this>=num);
}

bool Bigint::operator>=(const Bigint &num) const
{
       if (this->_digits.size() > num._digits.size())
                return true;
        else if (this->_digits.size() < num._digits.size())
                return false;
        else
        {
                for(int i = (int)this->_digits.size() - 1; i >= 0; i--)
                {
                        if (this->_digits[i] > num._digits[i])
                                return true;
                        else if (this->_digits[i] < num._digits[i])
                                return false;
                }
        }
        return true;
}

bool Bigint::operator<=(const Bigint &num) const
{
	return !(*this>num);
}

bool Bigint::operator==(const Bigint &num) const
{
       if (this->_digits.size() > num._digits.size())
                return false;
        else if (this->_digits.size() < num._digits.size())
                return false;
        else
        {
                for(int i = (int)this->_digits.size() - 1; i >= 0; i--)
                {
                        if (this->_digits[i] != num._digits[i])
                                return false;
                }
        }
        return true;

}

bool Bigint::operator!=(const Bigint &num) const
{
	return !(*this == num);
}

const std::vector<int> &Bigint::get_digits() const
{
	return this->_digits;
}

std::vector<int> &Bigint::get_digits()
{
	return this->_digits;
}

std::ostream& operator<<(std::ostream& os, const Bigint &n)
{
	for(int i =(int) n.get_digits().size() - 1; i >= 0; i--)
		os << n.get_digits()[i];
	return os;
}
