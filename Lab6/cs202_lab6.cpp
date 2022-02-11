#include "shape.h"

//These are the operators you will be overloading
Point Point::operator + (const Point& p) const
{
    Point newP;
    newP.x = x + p.x;
    newP.y = y + p.y;
    return newP;
}

Point& Point::operator += (const Point& p)
{
    x += p.x;
    y += p.y;
    return *this;
}

bool Point::operator == (const Point& p) const
{
    if (x == p.x && y == p.y) return true;
    return false;    
}

ostream& operator << (ostream& out, const Point& p)
{
    out << "(" << p.x << "," << p.y << ")";
    return out;
}

Shape& Shape::operator = (const Shape& s)
{
    if (*this == s) return *this;
    center = s.center;
    color = s.color;
    return *this;
}

Shape& Shape::operator += (const Point& p)
{
    center += p;
    return *this;    
}

ostream& operator << (ostream& out, const Shape& s)
{
    out << "Center: " << s.center << " Color: " << s.color;
    return out;
}

Shape Shape::operator + (const Shape & s) const
{
    Shape newS(s);
    newS += center;
    return newS;
}

Point operator + (const Point& p, const Shape& s)
{
    Point newP(p);
    newP += s.center;
    return newP;
}

Point operator + (const Shape& s, const Point& p)
{
    return p + s;
}

Circle operator + (const Point& p, const Circle& c)
{
    Circle newC(c);
    newC += p;
    return newC;
}

Circle operator + (const Circle& c, const Point& p)
{
    return p + c;
}

Circle& Circle::operator = (const Circle& c)
{
    if (*this == c) return *this;
    this -> Shape::operator=(c);
    radius = c.radius;
    return *this;
}


