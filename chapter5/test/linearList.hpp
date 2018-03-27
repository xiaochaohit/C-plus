//linearList.hpp

#ifndef linearList_
#define linearList_
#include <iostream>

using namespace std;

template <typename T>
class linearList
{
public:
	linearList();
	~linearList();

	//ADT
	virtual bool empty() const = 0;
	virtual int size() const = 0;
	virtual T & get(int theindex) const = 0;
	virtual int indexof(const T& theElement) const = 0;
	virtual void erase(int theindex) const = 0; 
	virtual void insert(int theindex, const T& theElement) const = 0;
	virtual void output(ostream &out) const = 0;
};

#endif