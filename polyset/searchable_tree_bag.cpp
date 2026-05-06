#include "searchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag(){}

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag &stb):tree_bag(stb){}

searchable_tree_bag &searchable_tree_bag::operator=(const searchable_tree_bag &stb)
{
	if (this != &stb)
		tree_bag::operator=stb;

	return *this;
}

searchable_tree_bag::~searchable_tree_bag(){}

bool search(node* node, const int x) const
{
	if (!node)
		return false;
	if (node->value == x)
	       return true;
	else if (node->value > x)
		return (search(node->l, x));
	else 
		return (search(node->r, x));	
}

bool searchable_tree_bag::has(int x) const
{
	return search(this->tree, x);

}
