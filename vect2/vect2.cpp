#include "vect2.hpp"

vect2::vect2()
{
	_vector[0] = 0;
	_vector[1] = 0;
}

vect2::vect2(const int &n0, const int &n1)
{
	_vector[0] = n0;
	_vector[1] = n1;
}

vect2::vect2(const vect2 &v)
{
	_vector[0] = v._vector[0];
	_vector[1] = v._vector[1];
}

vect2	&vect2::operator=(const vect2 &v)
{
	if (this != &v)
	{
		_vector[0] = v._vector[0];
		_vector[1] = v._vector[1];
	}
	return *this;	
}

int vect2::operator[](int i) const
{

	return _vector[i];
}

int &vect2::operator[](int i)
{

       return _vector[i];
}

vect2 vect2::operator*(int i) const
{
	vect2 res;

	res._vector[0] = _vector[0] * i;
	res._vector[1] = _vector[1] * i;

	return res;
}

vect2 vect2::operator-() const
{
	vect2 res;

        res._vector[0] = _vector[0] * (-1);
        res._vector[1] = _vector[1] * (-1);

        return res;
}

vect2 vect2::operator+(const vect2 &v) const
{
	vect2 res;

	res._vector[0] = v._vector[0] + _vector[0];
	res._vector[1] = v._vector[1] + _vector[1];

	return res;
}

const int* vect2::get_vector() const
{
	return _vector;
}

std::ostream &operator<<(std::ostream &os, const vect2 &v)
{
	const int* vector = v.get_vector();
	os << vector[0] << ", " << vector[1] << std::endl;

	return os;	
}

vect2::~vect2(){}


