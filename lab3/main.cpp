#include <iostream>

using namespace std;
class Stack
{
    int tos;
    int sizeOfStack;
    int *st;
    static int constructor_counter;
    static int destructor_counter;
public:
    Stack(int n)
    {
        tos = 0;
        sizeOfStack = n;
        st = new int[sizeOfStack];
        constructor_counter++;
        cout<<"Number of calls of constructor : "<<Stack::getConstructorCounter()<<endl;
    }
    ~Stack()
    {
        destructor_counter++;
        delete [] st;
        cout<<"Number of calls of destructor : "<<Stack::getDestructorCounter()<<endl;
        cout<<"Object died"<<endl;
    }

    Stack(Stack &z)
    {
        tos = z.tos;
        sizeOfStack = z.sizeOfStack;
        st = new int[sizeOfStack];
        for(int i = 0 ; i < sizeOfStack ; i++)
        {
            st[i] = z.st[i];
        }
        constructor_counter++;
        cout<<"Number of calls of constructor : "<<Stack::getConstructorCounter()<<endl;
    }
    static int getDestructorCounter ()
    {
        return destructor_counter;
    }
    static int getConstructorCounter ()
    {
        return constructor_counter;
    }
    void push (int num)
    {
        if (tos < sizeOfStack)
        {
            st[tos] = num;
            tos++;
        }
        else
        {
            cout<<"stack is full"<<endl;
        }
    }
    int pop ()
    {
        if (tos > 0)
        {
            tos--;
            return st[tos];
        }
        else
        {
            cout<<"stack is empty"<<endl;
        }
    }
    friend void viewContent(Stack obj);
};
int Stack::constructor_counter = 0;
int Stack::destructor_counter = 0;


void viewContent(Stack obj)
{
    for(int i = 0; i < obj.sizeOfStack; i++)
    {
        cout<<"element "<<i<<": "<<obj.st[i]<<endl;
    }
}
int main()
{
    int sizeOfStack;
    cout<<"Please enter size of stack"<<endl;
    cin>>sizeOfStack;
    Stack s(sizeOfStack);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    viewContent(s);
    return 0;
}
