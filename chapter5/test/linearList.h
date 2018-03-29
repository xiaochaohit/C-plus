//linearList.h

#ifndef linearList_
#define linearList_
#include <iostream>

using namespace std;

template <typename T>
class linearList
{
public:
	virtual ~linearList() {};

	//ADT
	virtual bool empty() const = 0;
	virtual int size() const = 0;
	virtual T & get(int theIndex) const = 0;
	virtual int indexof(const T& theElement) const = 0;
	virtual void erase(int theIndex)  = 0; 
	virtual void insert(int theIndex, const T& theElement)  = 0;
	virtual void output(ostream &out) const = 0;
};

#endif