#include <iostream>

using namespace std;


class Base
{
private:
    int a;
    int b;


public:
    Base()
    {
        a = b = 0;
    }
    Base(int n)
    {
        a = b = n;
    }
    Base(int x, int y)
    {
        a = x;
        b = y;
    }
    void setA(int x)
    {
        a = x;
    }
    void setB(int y)
    {
        b = y;
    }
    int getA()
    {
        return a;
    }
    int getB()
    {
        return b;
    }
    int productAB()
    {
        return a*b;
    }
    int calculateSumAB()
    {
        return a + b;
    }
};

class Derived : public Base
{
    int c;

public:
    Derived() : Base()
    {
        c = 0;
    }
    Derived(int n) : Base(n)
    {
        c = n;
    }
    Derived(int x, int y, int w) : Base (x,y)
    {
        c = w;
    }
    void setC(int z)
    {
        c = z;
    }
    int getC()
    {
        return c;
    }
    int productABC()
    {
        return productAB()*c;
    }
    int calculateSumABC()
    {
        return calculateSumAB() + c;
    }
};

class SecondDerived : public Derived
{
    int d;
public:
    SecondDerived() : Derived()
    {
        d = 0;
    }
    SecondDerived(int n) : Derived(n)
    {
        d = n;
    }
    SecondDerived(int x, int y, int w, int p) : Derived (x, y, w)
    {
        d = p;
    }
    void setD(int z)
    {
        d = z;
    }
    int getD()
    {
        return d;
    }
    int productABCD()
    {
        return productABC()*d;
    }
    int calculateSumABCD()
    {
        return calculateSumABC() + d;
    }
};


int main()
{

    Base b1(2,3);
    cout<<"b1: a + b = "<<b1.calculateSumAB()<<endl;

    Derived s1(2,3,2);
    cout<<"S1: a + b + c = "<<s1.calculateSumABC()<<endl;

    SecondDerived s2(2,3,3,2);
    cout<<"S2: a + b + c + d = "<<s2.calculateSumABCD()<<endl;


    return 0;
}
