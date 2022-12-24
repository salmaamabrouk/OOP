#include <iostream>

using namespace std;
class Stack
{
private:

    int tos;
    int sizeOfStack;
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


void operator = (const Stack &s);
    void push(int);
    int pop();
    void print();

};

void Stack :: operator = (const Stack &s)
    {
        delete[] this->st;
        this->tos=s.tos;
        this->sizeOfStack=s.sizeOfStack;
        this->st = new int[sizeOfStack];
        for (int i = 0; i < tos; i++)
        {
            this->st[i] = s.st[i];
        }
    };

void Stack::push(int n)
{
    if (tos == sizeOfStack)
    {
        cout<<"Stack is full"<<endl;

    }
    else
    {

        st[tos] = n;
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
   Stack s1(9);
   s1.push(8);
   s1.push(7);

   cout<<"s1 is : ";
   s1.print();
   Stack s2(8);
   s2 = s1;
   cout<<"s2 is : ";
   s2.print();

    return 0;
}
