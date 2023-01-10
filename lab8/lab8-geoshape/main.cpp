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
    virtual float calculateArea()
    {
        return 3;
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
        return 0.5 * d1 * d2;
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
        return d1 * d2;
    }
    ~Rect()
    {
        cout<<"Rectangle end"<<endl;
    }
};

class Circle : public GeoShape
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

class Square : public Rect
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
    float getSquareDim ()
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

float sumofAreas(GeoShape *, GeoShape *, GeoShape *);

int main()
{
    Triangle t1(4, 2);
    cout<<"Triangle area = "<<t1.calculateArea()<<endl;
    Rect r1(5, 7);
    cout<<"Rectangle area = "<<r1.calculateArea()<<endl;
    Circle c1(2);
    cout<<"Circle area = "<<c1.calculateArea()<<endl;
    cout<<"The sum of all areas = "<<sumofAreas(&r1, &c1, &t1)<<endl;

    return 0;
}

float sumofAreas(GeoShape *p1, GeoShape *p2, GeoShape *p3)
{
    return p1->calculateArea() + p2->calculateArea() + p3->calculateArea();
}
