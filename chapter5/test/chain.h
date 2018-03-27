//chain.h

#ifndef chain_
#define chain_
#include <iostream>
#include "linearList.h"

using namespace std;

template<typename T>
struct chainNoed
{
	T element;
	chainNoed<T> *next;

	//ADT
	chainNoed() {}
	chainNoed(const T& element)
	{
		this->element = element;
	}
	chainNoed(const T& element, chainNoed<T> *next)
	{
		this->element = element;
		this->next = next;
	}
};

template <typename T>
class chain : public linearList<T>
{
public:
	chain(int initialCapacity = 0);
	chain(const chain<T> &);
	~chain();

	//ADT
	bool empty() const {return listSize == 0;}
	int size() const {return listSize;}
	T& get(int theindex) const;
	int indexof(const T& theElement) const;
	void erase(int theindex) const;
	void insert(int theindex, const T& theElement) const;
	void output(ostream &out) const;

protected:
	void checkIndex(int &theindex) const;
	chainNoed<T> *firstNode;
	int listSize;
	
};



#endif