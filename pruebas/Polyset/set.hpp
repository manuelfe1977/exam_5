#ifndef SET_HPP
#define SET_HPP

#include "searchable_bag.hpp"

class set
{
	private:
		searchable_bag	&_data;
	public:
		set();
		set(searchable_bag &b);
		set(const set &s);
		set &operator=(const set &s);
		~set();
		bool has(int x) const;
		void insert(const int v);
		void insert(const int *arr, unsigned int size);
		void print() const;
		void clear();
		const searchable_bag &get_bag() const;
};

#endif

