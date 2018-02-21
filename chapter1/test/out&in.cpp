//test ostream & istream
#include<iostream>


class Test
{
    friend std::ostream & operator<<(std::ostream &out, Test &obj);
    friend std::istream & operator >> (std::istream &in, Test &obj);
public:
    Test(int a = 0, int b = 0)
    {
        this->a = a;
        this->b = b;
    }
    void display()
    {
        std::cout << "a:" << a << " b:" << b << std::endl;
    }

private:
    int a;
    int b;
};
std::ostream & operator<<(std::ostream &out, Test &obj)
{
    out << obj.a << " " << obj.b;
    //std::cout << "a:" << " b:" << std::endl;
    //obj.display();
    return out;
}
std::istream & operator>>(std::istream &in, Test &obj)
{
    in >> obj.a>> obj.b;
    if (!in)
    {
        obj = Test();
    }
    return in;
}
int main()
{
    Test t1(1, 2);
    std::cout << t1 << std::endl;
    std::cout << "请输入两个int属性:";
    std::cin >> t1;
    std::cout << t1 << std::endl;;
    std::cout << "hello world!\n";
    return 0;
}