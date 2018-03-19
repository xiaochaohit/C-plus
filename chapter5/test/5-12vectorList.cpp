#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

template <typename T>
//抽象类
class linearList
{
public:
	virtual ~linearList() {};
	virtual bool empty() const = 0;
		//返回true，当线性表为空时
	virtual int size() const = 0;
		//返回线性表元素个数
	virtual T& get(int theIndex) const = 0;
		//返回索引为theIndex的元素
	virtual int indexOf(const T &theElement) const = 0;
		//返回元素theElement第一次出现时的元素*/
	virtual void erase (int theIndex) = 0;
		//删除索引为theIndex的元素
	virtual void insert(int theIndex, const T& theElement) = 0;
		//在 theIndex位置插入元素theElement
	virtual void output() const = 0;

};

template <typename T>
class vectorList : public linearList<T>
{
public:
	//构造函数、复制函数、析构函数
	vectorList(int initialCapacity = 10);
	vectorList(const vectorList<T>& );
	~vectorList() {delete element;}
	//ADT
//	void erase (int theIndex);
	bool empty() const {return element->empty();}
	int size() const {return (int) element ->size();}
	T& get(int theIndex) const;
	int indexOf(const T& theElement) const;
	void erase (int theIndex);
	void insert(int theIndex, const T& theElement);
	void output() const;

	// additional method
      int capacity() const {return (int) element->capacity();}

	typedef typename vector<T>::iterator iterator;
	iterator begin() {return element -> begin();}
	iterator end() {return element -> end();}

protected:
	void checkIndex(int theIndex) const;
	vector<T>* element;

};

int main()
{
	// test constructor
   linearList<double> *x = new vectorList<double>(20);
   vectorList<int> y(2), z;

   // test capacity
   cout << "Capacity of x, y and z = "
        << ((vectorList<double>*) x)->capacity() << ", "
        << y.capacity() << ", "
        << z.capacity() << endl;

         // test size
   cout << "Initial size of x, y, and z = "
        << x->size() << ", "
        << y.size() << ", "
        << z.size() << endl;

   // test empty
   if (x->empty()) cout << "x is empty" << endl;
   else cout << "x is not empty" << endl;
   if (y.empty()) cout << "y is empty" << endl;
   else cout << "y is not empty" << endl;

   // test insert
   y.insert(0, 2);
   y.insert(1, 6);
   y.insert(0, 1);
   y.insert(2, 4);
   y.insert(3, 5);
   y.insert(2, 3);
   cout << "Inserted 6 integers, list y should be 1 2 3 4 5 6" << endl;
   cout << "Size of y = " << y.size() << endl;
   cout << "Capacity of y = " << y.capacity() << endl;
   if (y.empty()) cout << "y is empty" << endl;
   else cout << "y is not empty" << endl;
  // y.output();
   cout << endl << "Testing overloaded <<" << endl;
  // cout << y << endl;

   // test indexOf
   int index = y.indexOf(4);
   if (index < 0) cout << "4 not found" << endl;
   else cout << "The index of 4 is " << index << endl;

   index = y.indexOf(7);
   if (index < 0) cout << "7 not found" << endl;
   else cout << "The index of 7 is " << index << endl;

   // test get
   cout << "Element with index 0 is " << y.get(0) << endl;
   cout << "Element with index 3 is " << y.get(3) << endl;

   // test erase
   y.erase(1);
   cout << "Element 1 erased" << endl;
   cout << "The list is "  << y << endl;
   y.erase(2);
   cout << "Element 2 erased" << endl;
   cout << "The list is "  << y << endl;

   cout << "Size of y = " << y.size() << endl;
   cout << "Capacity of y = " << y.capacity() << endl;
   if (y.empty()) cout << "y is empty" << endl;
   else cout << "y is not empty" << endl;

 /*  try {y.insert(-3, 0);}
   catch (illegalIndex e)
   {
      cout << "Illegal index exception" << endl;
      cout << "Insert index must be between 0 and list size" << endl;
      e.outputMessage();
   }*/

/*   // test copy constructor
   vectorList<int> w(y);
   y.erase(0);
   y.erase(0);
   cout << "w should be old y, new y has first 2 elements removed" << endl;
   cout << "w is " << w << endl;
   cout << "y is " << y << endl;
   
   // a few more inserts, just for fun
   y.insert(0,4);
   y.insert(0,5);
   y.insert(0,6);
   y.insert(0,7);
   cout << "y is " << y << endl;

   // test iterator
   cout << "Ouput using forward iterators pre and post ++" << endl;
   for (vectorList<int>::iterator i = y.begin();
        i != y.end(); i++)
      cout << *i << "  ";
   cout << endl;
   for (vectorList<int>::iterator i = y.begin();
        i != y.end(); ++i)
      cout << *i << "  ";
   cout << endl;

   cout << "Ouput using backward iterators pre and post --" << endl;
   for (vectorList<int>::iterator i = y.end();
        i != y.begin(); cout << *(--i) << "  ");
   cout << endl;
   for (vectorList<int>::iterator i = y.end();
        i != y.begin();)
      {i--; cout << *i << "  "; *i += 1;} 
   cout << endl;
   cout << "Incremented by 1 list is " << y << endl;
   
   // try out some STL algorithms
   reverse(y.begin(), y.end());
   cout << "The reversed list is " << y << endl;
   int sum = accumulate(y.begin(), y.end(), 0);
   cout << "The sum of the elements is " << sum << endl;
   sort(y.begin(), y.end());
   cout << "The sorted list is " << y << endl;
   sort(y.begin(), y.end(), greater<int>());
   cout << "The list is descending order is " << y << endl;*/

	return 0;
}

template<typename T>
vectorList<T>::vectorList(int initialCapacity)
{
	if(initialCapacity < 1)
	{
		ostringstream s;
		s << "Initial capacity = " << initialCapacity <<"Must be >0";
//		throw illegalParameterValue(s.str());
	}
	element = new vector<T>;
	element -> reserve(initialCapacity);
}

template <typename T>
vectorList<T>::vectorList(const vectorList<T>& theList)
{
	element = new vector<T> (*theList.element);
}

template <typename T>
void vectorList<T>::checkIndex(int theIndex) const
{
	if(theIndex < 0 ||theIndex >= size())
	{
		cout << "index = " << theIndex <<" size = " << size();
	}

}

template <typename T>
T& vectorList<T>::get(int theIndex) const
{
	checkIndex(theIndex);
	return (*element)[theIndex];
}

template <typename T>
int vectorList<T>::indexOf(const T &theElement) const
{
	int theIndex = (int)(find(element->begin(), element->end(),
							theElement)
							-element->begin());
	if(theIndex == size())
		return -1;
	else 
		return theIndex;
}

template <typename T>
void vectorList<T>::erase (int theIndex)
{
	checkIndex(theIndex);
	element -> erase(begin() + theIndex);
}

template <typename T>
void vectorList<T>::insert(int theIndex, const T& theElement)
{
	checkIndex(theIndex);
	element -> insert(begin() + theIndex, theElement);
}

template <typename T>
void vectorList<T>::output() const
{
	for(int i = 0; i < size();i++)
		cout << (*element)[i] << ' ';
	cout << endl;
}

template <typename T>
ostream & operator <<(ostream &out, const vectorList<T>& x)
{
	x.output();
	return out;
}