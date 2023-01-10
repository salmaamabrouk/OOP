#include <iostream>

using namespace std;

class GeoShape
{
protected:
    float d1;
    float d2;

public:
    GeoShape()
    {
        d1 = d2 = 0;
    }
    GeoShape(float x)
    {
        d1 = d2 = x;
    }
    GeoShape(float x, float y)
    {
        d1 = x;
        d2 = y;
    }
    void setD1(float x)
    {
        d1 = x;
    }
    int getD1()
    {
        return d1;
    }
    void setD2(float y)
    {
        d2 = y;
    }
    int getD2()
    {
        return d2;
    }
    float calculateArea()
    {
        return 0;
    }
};

class Triangle : public GeoShape
{
public:
    Triangle(float x, float y) : GeoShape (x, y)
    {
        cout<<"Triangle: default constructor"<<endl;
    }
    float calculateArea()
    {
        return 0.5*d1 * d2;
    }
    ~Triangle()
    {
        cout<<"Triangle end"<<endl;
    }
};

class Rect : public GeoShape
{
public:
    Rect()
    {
        cout<<"Rectangle: default constructor"<<endl;
    }
    Rect(float x, float y) : GeoShape (x, y)
    {

    }
    float calculateArea()
    {
        return d1*d2;
    }
    ~Rect()
    {
        cout<<"Rectangle end"<<endl;
    }
};

class Circle : private GeoShape
{
public:
    Circle()
    {
        cout<<"Circle: default constructor"<<endl;
    }
    Circle(float x) : GeoShape (x)
    {

    }
    void setRadius(float r)
    {
        d1 = d2 = r;
    }
    float getRadius()
    {
        return d1;
    }
    float calculateArea()
    {
        return 22.0/7 * d1 * d1;
    }
    ~Circle()
    {
        cout<<"Circle end"<<endl;
    }
};

class Square : private Rect
{
public:
    Square()
    {
        cout<<"Square: other constructor"<<endl;
    }
    Square(float x) : Rect(x, x)
    {

    }
    void setSquareDim (float x)
    {
        d1 = d2 = x;
    }
    float setSquareDim ()
    {
        return d1;
    }
    float calculateArea()
    {
        return Rect::calculateArea();
    }
    ~Square()
    {
        cout<<"Square end"<<endl;
    }
};



int main()
{
    Triangle t1(4, 2);
    cout<<"Area is : "<<t1.calculateArea()<<endl;
    Rect r1(5, 7);
    cout<<"Area is : "<<r1.calculateArea()<<endl;
    Circle c1(6);
    cout<<"Circle area is "<<c1.calculateArea()<<endl;
    Square sq1;
    sq1.setSquareDim(2);
    cout<<"Square area is : "<<sq1.calculateArea()<<endl;

    return 0;
}
