#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>

class vect2
{
	private:
		int	_vector[2];
	public:
		vect2();
		vect2(const int &n0, const int &n1);
		vect2(const vect2 &v);
		vect2 &operator=(const vect2 &v);
		int operator[](int i) const;
		int &operator[](int i);
		vect2 operator*(int i) const;
		vect2 operator-() const;
		vect2 operator+(const vect2 &v) const;
		vect2 operator-(const vect2 &v) const;
		vect2 operator*(const vect2 &v) const;
		vect2 operator/(const vect2 &v) const;
		vect2 &operator*=(int n);
		vect2 &operator+=(const vect2 &v);
		vect2 &operator-=(const vect2 &v);
		vect2 &operator*=(const vect2 &v);
		vect2 &operator/=(const vect2 &v);
		vect2 &operator++();
		vect2 operator++(int n);
		vect2 &operator--();
		vect2 operator--(int n);
		bool operator==(const vect2 &v) const;
		bool operator!=(const vect2 &v) const;
		const int* get_vector() const;
		~vect2();
};

vect2 operator*(int i, const vect2 &v);
std::ostream &operator<<(std::ostream &os, const vect2 &v);

#endif
