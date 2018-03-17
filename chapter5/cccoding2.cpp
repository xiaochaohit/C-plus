//public/private/protected访问控制权限的区别
//时间：2016/8/16
//(一)修饰成员：
//public：   在类内、类外都能使用 。
//protected: 在类内、继承的子类中使用 。
//private:   只能在类的内部使用 。

//(二)修饰继承关系：
//public：  子类的成员可以访问父类的public/protected的成员。
//          子类的对象可以访问父类的public成员。
//private:  子类的成员可以访问父类的public/protected的成员。
//          子类的对象不可以访问父类的任何成员。
//protected:子类的成员可以访问父类的public/protected的成员。
//          子类的对象不可以访问父类的任何成员。
//#include "stdafx.h"
#include "iostream"
using namespace std;

class Parent
{
public :
    int a;//老爹的名字
protected:
    int b;//老爹的银行密码
private:
    int c;//老爹的情人
};

//保护继承，家族的。
class Child1 :protected Parent
{
public:
protected:
public:
    void useVar() {
        a = 0;//公共的ok
        b = 0;//保护的ok
        //c = 5;//私有的不ok
    }
};

//私有继承,共有的。
class Child2 :private Parent
{
public:
    void useVar()
    {
        a = 0;//公共的ok
        b = 0;//保护的ok
        //c = 0;//私有的不ok
    }
};
//公共继承,共有的。
class Child3 :public Parent
{
public:
    void useVar()
    {
        a = 0;//公共的ok
        b = 0;//保护的ok
        //c = 0;//私有的不ok
    }
};
int main()
{
    Child1 c1;//保护继承，家族的。
    Child2 c2;//私有继承,共有的。
    Child3 c3;//公共继承,共有的。

   //cout << c1.b;//私有的不ok
    //c2.a = 6;//保护的不ok
    c3.a = 6;  //公共的ok
    return 0;
}