#include "Rectangle.h"

class Rectangle;

Rectangle::Rectangle(int id, ShapeType type)
    :Shape(id, type)
{
}
void Rectangle::draw(QPainter* shape)
{
    shape->save(); //save original state of qpainter

    shape->setPen(getPen());
    shape->setBrush(getBrush());
    if(isSquare())
        shape->drawRect(getDimensions()[0],getDimensions()[1],getDimensions()[2],getDimensions()[2]);
    else
        shape->drawRect(getDimensions()[0],getDimensions()[1],getDimensions()[2],getDimensions()[3]);

    shape->restore(); //restore to the original state of qpainter
}
void Rectangle::move(int dims[])
{
    getDimensions()[0] = dims[0];
    getDimensions()[1]= dims[1];
}
int Rectangle::perimeter()
{
    if(!isSquare())
        return((2 * getDimensions()[2]) + (2 * getDimensions()[3]));
    else
        return(4 * getDimensions()[2]);
}
int Rectangle::area()
{
    if(!isSquare())
        return (getDimensions()[2] * getDimensions()[3]);
    else
        return (pow(getDimensions()[2], 2));
}
bool Rectangle::isSquare()
{
    if(getDimensions().size() == 3 || this->getShape() == Shape::SQUARE)
    {
        return true;
    }
    return false;
}
