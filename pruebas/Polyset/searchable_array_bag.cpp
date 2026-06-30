#include "searchable_array_bag.hpp"

searchable_array_bag::searchable_array_bag(){}

searchable_array_bag::searchable_array_bag(const searchable_array_bag &sab):array_bag(sab){}

searchable_array_bag &searchable_array_bag::operator=(const searchable_array_bag &sab)
{
	if (this != &sab)
		array_bag::operator=(sab);

	return *this;
}

searchable_array_bag::~searchable_array_bag(){}

bool searchable_array_bag::has(int x) const
{
	for (int i = 0; i < this->size; i++)
	{
		if (this->data[i] == x)
			return true;
	}

	return false;
}
