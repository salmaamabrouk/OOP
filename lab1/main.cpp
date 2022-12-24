#include <iostream>

using namespace std;

class Complex
{
    float real, imag;

public:

    void setReal(float r)
    {
        real = r;
    }

    void setImag(float i)
    {
        imag = i;
    }

    float getReal()
    {
        return real;
    }

    float getImag()
    {
        return imag;
    }

    void print()
    {
        if (imag < 0)
        {
            cout<<real<<imag<<"i"<<endl;
        }
        else
        {
            cout<<real<<"+"<<imag<<"i"<<endl;
        }
    }

    void add_1(Complex temp1, Complex temp2)
    {
        real = temp1.getReal() + temp2.getReal();
        imag = temp1.getImag() + temp2.getImag();
    }

    void sub_1(Complex temp1, Complex temp2)
    {
        real = temp1.getReal() - temp2.getReal();
        imag = temp1.getImag() - temp2.getImag();
    }

    Complex add_2(Complex comp1)
    {
        Complex result;
        result.setReal(real + comp1.getReal());
        result.setImag(imag + comp1.getImag());
        return result;
    }

    Complex sub_2(Complex comp1)
    {
        Complex result;
        result.setReal(real - comp1.getReal());
        result.setImag(imag - comp1.getImag());
        return result;
    }
};


void swap_value(int, int);

void swap_reference(int &, int &);

void swap_address(int *, int *);

int main()
{

    Complex myComp1, myComp2, resultComp;
    float r_inp, i_inp;

    cout<<"Please enter real number, enter imaginary number"<<endl;
    cin>>r_inp>>i_inp;
    myComp1.setReal(r_inp);
    myComp1.setImag(i_inp);
    myComp1.print();
    cout<<endl;
    cout<<"Please enter real number, enter imaginary number"<<endl;
    cin>>r_inp>>i_inp;
    myComp2.setReal(r_inp);
    myComp2.setImag(i_inp);
    myComp2.print();
    cout<<"-----------------------------------------------------------"<<endl;
    resultComp.add_1(myComp1,myComp2);
    resultComp.print();
    cout<<"-----------------------------------------------------------"<<endl;
    resultComp = myComp1.add_2(myComp2);
    resultComp.print();
    cout<<"-----------------------------------------------------------"<<endl;
    resultComp.sub_1(myComp1,myComp2);
    resultComp.print();
    resultComp = myComp1.sub_2(myComp2);
    resultComp.print();
    cout<<"-----------------------------------------------------------"<<endl;
    int a = 5,b = 7;
    cout<<a<<"\n"<<b<<endl;
    swap_value(a, b);

    swap_reference(a, b);

    swap_address(&a, &b);
    return 0;
}

void swap_value(int a, int b)
{
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<endl<<"Swap by value"<<endl<<a<<"\n"<<b<<endl;
    int temp = a;
    a = b;
    b = temp;
    cout<<"\n"<<b<<endl;
}

void swap_reference(int &a, int &b)
{
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<endl<<"Swap by reference"<<endl<<a<<"\n"<<b<<endl;
    int temp = a;
    a = b;
    b = temp;
    cout<<a<<"\n"<<b<<endl;
}

void swap_address(int *a, int *b)
{
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<endl<<"Swap by address"<<endl<<*a<<"\n"<<*b<<endl;
    int temp = *a;
    *a = *b;
    *b = temp;
    cout<<*a<<"\n"<<*b<<endl;
}
