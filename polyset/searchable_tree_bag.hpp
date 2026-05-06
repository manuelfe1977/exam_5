#include "tree_bag.hpp"
#include "searchable_bag.hpp" 

class searchable_tree_bag:public tree_bag, public_searchable_bag
{
	searchable_tree_bag();
	searchable_tree_bag(const searchable_tree_bag &stb);
	searchable_tree_bag &operator=(const searchable_tree_bag &stb);
	bool has(int x) const;
	~searchable_tree_bag();
};
