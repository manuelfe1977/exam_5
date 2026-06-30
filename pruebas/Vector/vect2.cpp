#include "vect2.hpp"

vect2::vect2()
{
	_x = 0;
	_y = 0;
}

vect2::vect2(int x, int y)
{
        _x = x;
        _y = y;
}

vect2::vect2(const vect2 &v)
{
	_x = v._x;
	_y = v._y;
}

vect2	&vect2::operator=(const vect2 &v)
{
	if (this != &v)
	{
        	_x = v._x;
        	_y = v._y;
	}
	return *this;
}

vect2::~vect2(){}

vect2 vect2::operator+(const vect2 &v) const
{
	vect2 res;
	res._x = _x + v._x;
	res._y = _y + v._y;
	return res;
}

vect2 vect2::operator-(const vect2 &v) const
{
        vect2 res;
        res._x = _x - v._x;
        res._y = _y - v._y;
        return res;
}

vect2 vect2::operator*(const vect2 &v) const
{
        vect2 res;
        res._x = _x * v._x;
        res._y = _y * v._y;
        return res;
}

vect2 vect2::operator/(const vect2 &v) const
{
        vect2 res;
	if (v._x != 0) 
        	res._x = _x / v._x;
	if (v._y != 0)
        	res._y = _y / v._y;
        return res;
}

vect2	&vect2::operator+=(const vect2 &v)
{
        _x = _x + v._x;
        _y = _y + v._y;
        return *this;:
}

vect2	&vect2::operator-=(const vect2 &v)
{
        _x = _x - v._x;
        _y = _y - v._y;
        return *this;
}

vect2	&vect2::operator*=(const vect2 &v)
{
        _x = _x * v._x;
        _y = _y * v._y;
        return *this;
}

vect2	&vect2::operator/=(const vect2 &v)
{
        
        if (v._x != 0)
                _x = _x / v._x;
        if (v._y != 0)
                _y = _y / v._y;
        return *this;
}

int vect2::operator[](int p) const
{
	if (p == 0)
		return _x;
	else
		return _y;
}

int &vect2::operator[](int p)
{
        if (p == 0)
                return _x;
        else
                return _y;

}

vect2 &vect2::operator++()
{
	_x++;
	_y++;
	return *this;	
}

vect2 vect2::operator++(int n)
{
	vect2 cpy = *this;
	(void) n;
	_x++;
	_y++;
	return cpy;
}

vect2 &vect2::operator--()
{
        _x--;
        _y--;
        return *this;
}

vect2 vect2::operator++(int n)
{
        vect2 cpy = *this;
        (void) n;
        _x--;
        _y--;
        return cpy;
}

bool vect2::operator==(const vect2 &v) const
{
	if (_x == v._x && _y == v._y)
		return true;
	else
		return false;
}

bool vect2::operator!=(const vect2 &v) const
{
        if (_x != v._x || _y != v._y)
                return true;
        else
                return false;
}

vect2 vect2::operator-() const
{
	vect2 res;
	res._x = _x * -1;
	res._y = _y * -1;

	return res;
}

vect2 vect2::operator+(int n) const
{
	vect2 res;
	res._x = _x + n;
	res._y = _y + n;

	return res;
}

vect2 vect2::operator-(int n) const
{
        vect2 res;
        res._x = _x - n;
        res._y = _y - n;
 
        return res;
}

vect2 vect2::operator*(int n) const
{
        vect2 res;
        res._x = _x * n;
        res._y = _y * n;

        return res;
}

std::ostream vect2::operator<<(ostream &os, const vect2 &v)
{
	os << "{" << v[0] << ", " << v[1] << "}";
	return os;
}

vect2 vect2::operator*(int n, const vect2 &v)
{
	res = v * n;
	return res;
}
