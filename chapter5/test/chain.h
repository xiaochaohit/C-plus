//chain.h

#ifndef chain_
#define chain_
#include <iostream>
#include <sstream>
#include <string>
#include "linearList.h"
#include "../../官方答案及解决方法网址/codes/myExceptions.h"

using namespace std;

template<typename T>
struct chainNode
{
	T element;
	chainNode<T> *next;

	//ADT
	chainNode() {}
	chainNode(const T& element)
	{
		this->element = element;
	}
	chainNode(const T& element, chainNode<T> *next)
	{
		this->element = element;
		this->next = next;
	}
};

template <typename T>
class chain : public linearList<T>
{
public:
	chain(int initialCapacity = 10);
	chain(const chain<T> &);
	~chain();

	//ADT
	bool empty() const {return listSize == 0;}
	int size() const {return listSize;}
	T& get(int theIndex) const;
	int indexof(const T& theElement) const;
	void erase(int theIndex);
	void insert(int theIndex, const T& theElement);
	void output(ostream &out) const;

protected:
	void checkIndex(int &theIndex) const;
	chainNode<T> *firstNode;
	int listSize;
	
};

template <typename T>
chain<T>::chain(int initialCapacity)
{
	if(initialCapacity < 1)
	{
		ostringstream s;
		s << "Initial capacity = " << initialCapacity << "Must be > 0";
		throw illegalParameterValue(s.str());
	}
	firstNode = NULL;
	listSize = 0;
}

template <typename T>
chain<T>::chain(const chain<T> & theList)
{
	listSize = theList.listSize;
	if(0 == listSize)
	{
		firstNode = NULL;
		return;
	}
	chainNode<T> *sourceNode = theList.firstNode;
	firstNode = new chainNode<T>(sourceNode -> element);
	sourceNode = sourceNode -> next;
	chainNode<T> *targetNode = firstNode;

	while(sourceNode -> next != NULL)
	{
		targetNode = new chainNode<T>(sourceNode->element);
		sourceNode = sourceNode -> next;
		targetNode = targetNode -> next;
	}


}






#endif