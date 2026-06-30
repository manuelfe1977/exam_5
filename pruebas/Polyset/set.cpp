#include "set.hpp"

set::set(searchable_bag &b):_data(b){}

bool set::has(int x) const
{
	return _data.has(x);
}

void set::insert(const int v)
{
	if (!_data.has(v))
		_data.insert(v);
}

void set::insert(const int *arr, unsigned int size)
{
	for (unsigned int i = 0; i < size; i++)
		insert(arr[i]);
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
