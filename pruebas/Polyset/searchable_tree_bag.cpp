#include "searchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag(){}

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag &stb):tree_bag(stb){}

searchable_tree_bag &searchable_tree_bag::operator=(const searchable_tree_bag &stb)
{
	if (this != &stb)
		tree_bag::operator=(stb);

	return *this;
}

searchable_tree_bag::~searchable_tree_bag(){}

bool searchable_tree_bag::search_tree(node *tree, const int x) const
{

	if (!tree)
		return false;
	if (tree->value == x)
		return true;
	if (tree->value > x)
		return search_tree(tree->l, x);
	else if (tree->value < x)
		return search_tree(tree->r,x);
	return false;
}

bool searchable_tree_bag::has(int x) const
{
	return search_tree(this->tree, x);
}

