//chain.h

#ifndef chain_
#define chain_
#include <iostream>
#include <sstream>		//including the ostringstream 
#include <string>
#include "linearList.h"
#include "../../官方答案及解决方法网址/codes/myExceptions.h" //use the Exceptions Example

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
	//function of initialing the chainNode
	if(initialCapacity < 1)
	{
		ostringstream s;
		s << "Initial capacity = " << initialCapacity << "Must be > 0";
		throw illegalParameterValue(s.str());
	}
	firstNode = NULL;
	listSize = 0;
	//使用链表构造线性表时，其实不需要声明其大小，但是为了保持函数的一致性，也定义initialCapacity变量，但不去实际使用
}

template <typename T>
chain<T>::chain(const chain<T> & theList)
{
	//copy the input chain
	listSize = theList.listSize;
	if(0 == listSize)
	{
		firstNode = NULL;
		return;
	}


	chainNode<T> *sourceNode = theList.firstNode;			//use a parament save the input firstNode
	firstNode = new chainNode<T>(sourceNode -> element);	//assignment the first input element to the firstNode
	sourceNode = sourceNode -> next;						
	chainNode<T> *targetNode = firstNode;					//use the targetNode to save the rest element
	//by now, the adress of targetNode->next is same as the adress of firstNode->next.
	//So the firtNode can visit all the element of the targetNode chain

	while(sourceNode -> next != NULL)
	{
		targetNode = new chainNode<T>(sourceNode->element);
		sourceNode = sourceNode -> next;
		targetNode = targetNode -> next;
	}

}

template <typename T>
chain<T>::~chain()
{
	while(firstNode->next != NULL)
	{
		chainNode<T> * nextNode = firstNode->next;	//Save the chain pointer
		delete firstNode;					
		firstNode = nextNode;
	}

}

template<typename T>
T& chain<T>::get(int theIndex) const
{
	//check the index
	checkIndex(theIndex);
	int i = 0;
	chainNode<T> *getNode = firstNode;
	while(i < theIndex)
	{
		getNode = getNode->next;
		i++;
	}

	return getNode->element;
}

template<typename T>
void chain<T>::checkIndex(int &theIndex) const
{
	if(theIndex > listSize || theIndex < 0)
	{
		ostringstream s;
		s << "theIndex is out of the range of listSize" << endl;
		throw illegalIndex( s.str() );
	}

}

template <typename T>
int chain<T>::indexof(const T& theElement) const
{
	chainNode<T> *findNode = firstNode;
	int i = 0;
	while(findNode->next != NULL)
	{
		if(findNode->element == theElement)
			return i;
		else
			findNode = findNode->next;
		i++;
	}
}

template <typename T>
void chain<T>::erase(int theIndex)
{
	checkIndex(theIndex);
	chainNode<T> *findNode = firstNode;

	if(theIndex == 0)
	{
		findNode = firstNode->next;
		delete findNode;
	}
	else
	{
		for(int i = 0; i < theIndex - 1; i++)
			findNode = findNode->next;

		chainNode<T> *tempNode = findNode;
		findNode = findNode->next;
		tempNode->next = findNode->next;
		delete findNode;
	}
	listSize--;
}

template <typename T>
void chain<T>::insert(int theIndex, const T& theElement)
{
	checkIndex(theIndex);
	chainNode<T> *insertNode = firstNode;
	if(theIndex == 0)
	{
		firstNode = new chainNode<T>(theElement, firstNode);
	}
	else
	{
		for(int i = 0; i < theIndex-1; i++)
			insertNode = insertNode->next;
		insertNode->next = new chainNode<T>(theElement, insertNode->next);
	}
	listSize++;
}

template<typename T>
void chain<T>::output(ostream &out) const
{// Put the list into the stream out.
   for (chainNode<T>* currentNode = firstNode;
                      currentNode != NULL;
                      currentNode = currentNode->next)
      out << currentNode->element << "  ";
}

// overload <<
template <class T>
ostream& operator<<(ostream& out, const chain<T>& x)
   {x.output(out); return out;}



#endif


















