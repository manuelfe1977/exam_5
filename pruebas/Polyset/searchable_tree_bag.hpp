#ifndef SEARCHABLETREEBAG_HPP
#define SEARCHABLETREEBAG_HPP

#include "tree_bag.hpp"
#include "searchable_bag.hpp"

class searchable_tree_bag:public tree_bag, public searchable_bag
{
	private:
		bool search_tree(node *tree, const int x) const;
	public:
		searchable_tree_bag();
		searchable_tree_bag(const searchable_tree_bag &stb);
		searchable_tree_bag &operator=(const searchable_tree_bag &stb);
		~searchable_tree_bag();
		bool has(int) const;
};

#endif
