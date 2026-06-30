#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostrem>

class vect2
{
	private:
		int	_x;
		int	_y;
	public:
		vect2();
                vect2(int x, int y);
                vect2(const vect2 &v);
                vect2 &operator=(const vect2 &v);
		~vect2();
		vect2 operator+(const vect2 &v) const;
                vect2 operator-(const vect2 &v) const;
		vect2 operator-() const;
                vect2 operator*(int n) const;
		vect2 operator+(int n) const;
                vect2 operator-(int n) const;
                vect2 operator*(const vect2 &v) const;
                vect2 operator/(const vect2 &v) const;
		vect2 &operator+=(const vect2 &v);
                vect2 &operator-=(const vect2 &v);
                vect2 &operator*=(const vect2 &v);
                vect2 &operator/=(const vect2 &v);
		int operator[](int p) const;
		int &operator[](int p);
		vect2 &operator++();
		vect2 operator++(int n);
                vect2 &operator--();
                vect2 operator--(int n);
		bool operator==(const vect2 &v) const;
		bool operator!=(const vect2 &v) const;
};

vect2 operator*(int n, const vect2 &v);
std::ostream operator<<(ostream &os, const vect2 &v);

#endif

