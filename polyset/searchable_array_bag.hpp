#include "array_bag.hpp"
#include "searchable_bag"

class searchable_array_bag : public array_bag, public searchable_bag
{
	searchable_array_bag();
	searchable_array_bag(const searchable_array_bag &sab);
	searchable_array_bag &operator=(const searchable_array_bag &sab);
	~searchable_array_bag();
	bool has(int) const;
};

