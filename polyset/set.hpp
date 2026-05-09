#include "searchable_bag.hpp"

class set
{
	private:
		searchable_bag &_data;
	public:
		set();
		set(searchable_bag &b);
		set(const set &s);
		set &operator=(const set &s);
		~set();

		bool has(int x) const;
		void insert(const int &x);
		void insert(const int *ar, int s);
		void print() const;
		void clear();
		const searchable_bag &get_bag() const;
};
