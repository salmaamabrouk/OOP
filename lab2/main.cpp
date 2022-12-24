#include <iostream>

using namespace std;

class Stack
{
    int sizeOfStack;
    int tos;
    int *st;

public:

    Stack (int n)
    {
        st = new int[n];
        sizeOfStack = n;
        tos = 0;
        cout<<"CONSTRUCTOR"<<endl;
    };
    ~Stack()
    {
        delete[] st;
        cout<<"DESTRUCTOR"<<endl;
    };

    void push(int);
    int pop();
    void print();
};

void Stack::push(int n)
{
    if (tos == sizeOfStack)
    {
        cout<<"Stack is full"<<endl;

    }
    else
    {
        st[tos]=n;
        (tos)++;
    }
}
int Stack::pop()
{
    int retVal;

    if (tos == 0)
    {
        cout<<"Stack is empty"<<endl;
        retVal = -1;

    }
    else
    {
        (tos)--;
        retVal = st[tos];

    }
    return retVal;
}
void Stack::print()
{
    for (int i = 0; i < tos; i++)
    {
        cout<< st[i] <<endl;
    }
}

int main()
{
    Stack s(7);
    s.push(3);
    s.push(8);
    s.push(2);
    s.push(10);
    s.push(11);
    s.push(17);
    s.push(19);
    s.print();

    cout<<endl;

    for (int i=0; i<7; i++)
    {
        cout<<"The popped value is "<<s.pop()<<endl;
    }

    return 0;
}
