#include <iostream>

using namespace std;

template <class T>
class Stack
{
private:
    int tos;
    int Size;
    T *ptr;
    static int counter;

public:
    Stack();
    Stack(int n);
    ~Stack();
    static int getCounter();
    void push(T);
    T pop(T);
    bool ifexists (int a);
    void print();
};

template <class T>
int Stack<T>::counter = 0;

template <class T>
Stack<T>::Stack()
{
    tos = 0;
    Size = 10;
    ptr = new T[Size];
    counter++;
};

template <class T>
Stack<T>::Stack(int n)
{
    cout<<"The default constructor"<<endl;
    ptr = new T[Size];
    Size = n;
    tos =- 1;
    counter++;
    cout<<"CONSTRUCTOR --- Stack object number "<<counter<<endl;
}

template <class T>
Stack<T>::~Stack()
{
    delete[] ptr;
    counter--;
    cout<<"DESTRUCTOR --- Stack object number "<<counter+1<<" will be terminated."<<endl;
};

template <class T>
void Stack<T>::push(T a)
{
    if (tos == Size)
    {
        cout<<"Stack overflow."<<endl;
    }
    else
    {
        tos++;
        ptr[tos] = a;
        cout<<"Element "<<a<<" is inserted."<<endl;
    }
};

template <class T>
T Stack<T>::pop(T a)
{
    if (ifexists(a))
    {
        int pop;
        if (tos == -1)
        {
            cout<<"Stack is empty."<<endl;
            return -1;
        }
        else
        {
            (tos)--;
            pop = ptr[tos];
            cout<<"Element "<<pop<<" is popped."<<endl;
            return pop;
        }
    }
    else
    {
        cout<<"Invalid element."<<endl;
    }
};


template <class T>
int Stack<T>::getCounter()
{
    return counter;
}

template <class T>
bool Stack<T>::ifexists (int a)
{
    for (int i = 0; i <= Size; i++)
    {
        if (ptr[i] == a)
        {
            return true;
        }
    }
    return false;
}

template <class T>
void Stack<T>::print()
{
    if (-1 == tos)
    {
        cout<<"Stack is empty."<<endl;
    }
    else
    {
        for (int i = 0; i <= tos; i++)
        {
            cout<<ptr[i]<<endl;
        }
    }
}

int main()
{
    Stack<int> s1(5);
    cout<<"Number of integer stack= "<<Stack<int>::getCounter()<<endl;

    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    s1.print();
    s1.pop(30);
    s1.pop(50);
    s1.print();

    return 0;
}
