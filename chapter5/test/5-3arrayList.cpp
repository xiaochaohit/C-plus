#include <iostream>
#include <stdlib.h>
#include <sstream>	//包含ostringstream
#include <algorithm>//包含find函数	
#include <iterator>//ostream_iterator
#include <string>
//类arrayList


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
		//返回元素theElement第一次出现时的元素
	virtual void erase (int theIndex) = 0;
		//删除索引为theIndex的元素
	virtual void insert(int theIndex, const T& theElement) = 0;
		//在 theIndex位置插入元素theElement
	virtual void output() const = 0;

};

template <class T>
class arrayList :public linearList<T>
{
public:
	//构造函数
	arrayList(int initialCapacity = 10);
	arrayList(const arrayList<T>&);
	~arrayList() {delete [] element;}
	bool empty() const {return listSize == 0;}
	int size() const {return listSize;}
	T& get (int theIndex) const;
	int indexOf(const T &theElement) const;
	void erase (int theIndex);
	void insert(int theIndex, const T &theElement);
	void output() const;
	template <typename U>
	friend std::ostream & operator<<(std::ostream &out, arrayList<U> x);	
	int capacity() const {return arrayLength;}

protected:
	void checkIndex(int theIndex) const;
	T* element;			//存储线性表元素的一位数组
	int arrayLength;	//一维数组的容量
	int listSize;		//线性表元素的个数
};

template <typename T>
std::ostream & operator<<(std::ostream &out,arrayList<T> x)
{
	x.output();
	return out;
}

int main()
{
	linearList<double> *x = new arrayList<double>(10);		//x为抽象类linearList的指针，则*x为linearList的一个实例
	arrayList<int> y(2), z;
	arrayList<double> w(*((arrayList<double> *)x));

	//首先(arrayList<double> *)将x强制转化为派生类arrayList的指针，然后再用解释符*，使其成为一个实例，则可将此实例传给构造函数（复制函数））
/*	//验证构造函数
	std::cout << x -> arrayLength << " "
		<< y.arrayLength << " "
		<< z.arrayLength <<std::endl;*/
	std::cout << "***************************************************************" << std::endl;
	//验证构造函数
	std::cout << "the capacity of y,z and w :"
			//<< x->capacity() << " "			//x为抽象类linearList的指针，不能访问派生类中的保护变量
			<< y.capacity() << " "
			<< z.capacity() << " "
			<< w.capacity() << std::endl;
	//验证empty函数
	std::cout << "the four array x,y,z and w is empty?" << std::endl;
	if(x ->empty()) {std::cout << "is empty"<< std::endl;}
	if(y.empty()) {std::cout << "is empty"<< std::endl;} 
	if(z.empty()) {std::cout << "is empty" << std::endl;}

	//验证size()函数
	std::cout << "the size of x,y,z and w :" 
		<< x->size() << " "
		<< y.size() << " "
		<< z.size() << std::endl;

	//验证insert函数和indexOf函数
	x -> insert(0,0);
	x -> insert(0,1.1);
	x -> insert(0,2.2);
	x -> insert(0,3);
	std::cout << x -> indexOf(2.2) << std::endl;

	//验证erase函数和get函数
	x -> erase(1);
	std::cout << x -> get(1) << std::endl;

	//验证outpu函数以及重载
	y.insert(0,4);
    y.insert(0,5);
    y.insert(0,6);
    y.insert(0,7);
    y.output();
    if(y.empty()) {std::cout << "is empty"<< std::endl;} 
    std::cout << y;
	return 0;
}

template <typename T>
arrayList<T>::arrayList(int initialCapacity)
{//构造函数
	if (initialCapacity <1)
	{
		std::ostringstream s;
		s << "Initial capacity = " << initialCapacity << " Must be > 0"; 	//把各种格式的数据赋值给输出流s
		std::cout << s.str() << std::endl;
	}
	arrayLength = initialCapacity;
	element = new T[arrayLength];
	listSize = 0;
}

template <typename T>
arrayList<T>::arrayList(const arrayList<T>& theList)
{//复制构造函数
	arrayLength = theList.arrayLength;
	listSize = theList.listSize;
	element = new T [arrayLength];
	//std::cout << theList.element << std::endl;
	//std::cout << arrayLength << std::endl;
	std::copy(theList.element, theList.element + listSize, element);
}

template <typename T>
void arrayList<T>::checkIndex(int theIndex) const
{
	if(theIndex <0 || theIndex >listSize)
	{
		std::ostringstream s;
		s <<"index = " << theIndex <<"size = " << listSize;
		std::cout << s.str() << std::endl;
		exit(0);
	}
}

template <typename T>
T& arrayList<T>::get(int theIndex) const
{//若存在返回theIndex的元素
 //若不存在返回输出异常
	checkIndex(theIndex);
	return element[theIndex];
}

template <typename T>
int arrayList<T>::indexOf(const T& theElement) const
{
	int theIndex = (int) (std::find(element,element + listSize, theElement)-element);
	if(theIndex == listSize)
		//没有找到
		 return -1;
	else return theIndex;
}

template <typename T>
void arrayList<T>::erase(int theIndex)
{
	checkIndex(theIndex);

	std::copy(element + theIndex + 1, element + listSize, element + theIndex);

	element[--listSize].~T();
}

template<typename T>
void changeLength1D(T* a,int oldLength, int newLength)
{
	if(newLength < 0);
		//throw illegalParameterValue("new length must be >= 0");

	T* temp = new T[newLength];
	int number = std::min(newLength, oldLength);
	std::copy(a, a+number, temp);
	a = temp;	
	delete [] temp;
}

template <typename T>
void arrayList<T>::insert(int theIndex, const T& theElement)
{
	checkIndex(theIndex);

	if(listSize == arrayLength)
	{//数组已满，则将数组扩展为两倍大小
		changeLength1D(element, arrayLength, 2 * arrayLength);
		arrayLength *= 2;
	}
	//把theIndex之后的元素都右移一个位置
	std::copy_backward(element + theIndex, element + listSize, element + listSize + 1);
	element[theIndex] = theElement;
	listSize++;
}

template<typename T>
void arrayList <T> ::output() const
{
	for (int i = 0; i < listSize; i++)
	{
		std::cout << *(element+i) << " ";
	}
		std::cout << std::endl;
}











