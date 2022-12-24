#include <iostream>

using namespace std;

class Point
{
    int x;
    int y;

public:

    Point()
    {
        cout<<"Default point constructor"<<endl;
    }
    Point(int a, int b)
    {
        cout<<"Second point constructor"<<endl;
    }
    ~Point()
    {
        cout<<"destructor Point"<<endl;
    }
    void setX(int a)
    {
        x=a;
    }
    void setY(int b)
    {
        y=b;
    }
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
};
class Line
{
    Point start;
    Point endP;

public:

    Line() : start(), endP()
    {
        cout<<"Constructor line"<<endl;
    }
    Line(int x1, int y1, int x2, int y2) : start(x1,y1), endP(x2,y2)
    {
        cout<<"second line constructor"<<endl;
    }
    ~Line()
    {
        cout<<"Destructor line"<<endl;
    }
    void draw()
    {
        Line(start.getX(), start.getY(), endP.getX(),endP.getY());
    }
};

class Rectangle
{
    Point ul;
    Point lr;
public:
    Rectangle() : ul(), lr()
    {
        cout<<"rect constructor"<<endl;
    }
    Rectangle(int x1, int y1, int x2, int y2) : ul(x1,y1), lr(x2,y2)
    {
        cout<<"rect second constructor"<<endl;
    }
    ~Rectangle()
    {
        cout<<"rect destructor"<<endl;
    }
    void draw()
    {
        Rectangle(ul.getX(), ul.getY(), lr.getX(), lr.getY());
    }
};
class Circle
{
    Point centre;
    int rad;

public:

    Circle() : centre()
    {
        rad = 0;
        cout<<"Circle constructor"<<endl;
    }
    Circle(int a, int b, int r) : centre(a,b)
    {
        rad = r;
        cout<<"Second circle destructor"<<endl;
    }
    ~Circle()
    {
        cout<<"Circle destructor"<<endl;
    }
    void draw()
    {
        Circle(centre.getX(),centre.getY,rad);
    }

};

class Picture
{
    int cNum;
    int rNum;
    int lNum;
    Circle *pCircle;
    Rectangle *pRect;
    Line *pLine;

public:

    Picture()
    {
        cNum = 0;
        rNum = 0;
        lNum = 0;
        pCircle = NULL;
        pRect = NULL;
        pLine = NULL;
        cout<<"Default picture constructor"<<endl;
    }
    Picture(int cn, int rn, int ln, Circle *pC, Rectangle *pR, Line *pL)
    {
        cNum = cn;
        rNum = rn;
        lNum = ln;
        pCircle = pC;
        pRect = pR;
        pLine = pL;
        cout<<"Second picture constructor"<<endl;
    }
    ~Picture()
    {
        cout<<"picture destructor"<<endl;
    }
    void setCircle (int c, Circle *ptrcircle)
    {
        cNum = c;
        pCircle = ptrcircle;

    }
    void setRect (int r, Rect *ptrrect)
    {
        rNum = r;
        pRect = ptrrect;

    }
    void setLine (int l, Line *ptrline)
    {
        lNum = l;
        pLine = ptrline;

    }
    void paint()
    {
        int i;
        for (i = 0; i < cNum; i++)
        {
            pCircle[i].draw();
        }
        for (i = 0; i < rNum; i++)
        {
            pRect[i].draw();
        }
        for (i = 0; i < lNum; i++)
        {
            pLine[i].draw();
        }
    }
};

int main()
{

Picture mypic;
Circle cArr[3]={Circle(50,50,50), Circle(200,100,100), Circle(420,50,30)};
Rect rArr[2]={Rect(30,40,170,100), Rect(420,50,500,300)};
Line lArr[2]={Line(420,50,300,300), Line(40,500,500,400)};
mypic.setCircle(3,cArr);
mypic.setRect(2,rArr);
mypic.setLine(2,lArr);
mypic.paint();
    return 0;
}
