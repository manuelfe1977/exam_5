#include "set.hpp"

set::set(searchable_bag &b):_data(b){}

bool	set::has(int x) const
{
	return _data.has(x);
}

void set::insert(const int &x)
{
	if (!_data.has(x))
		_data.insert(x);
}

void set::insert(const int *ar, int s)
{
	for(int i = 0; i < s - 1; i++)
		insert(ar[i]);
}

void set::print() const
{
	_data.print();
}

void set::clear()
{
	_data.clear();
}

const searchable_bag &set::get_bag() const
{
	return _data;
}

set::~set(){}
