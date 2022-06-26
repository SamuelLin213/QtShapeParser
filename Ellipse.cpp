#include "Ellipse.h"
//using namespace std;

Ellipse::Ellipse(int id, ShapeType type)
    :Shape(id, type)
{
}

void Ellipse::draw(QPainter* shape)
{
    shape->save();

    shape->save(); //save original state of qpainter

    shape->setPen(getPen());
    shape->setBrush(getBrush());

    int xVal, yVal;

    if(isCircle())
    {
        shape->drawEllipse(getDimensions()[0],getDimensions()[1],getDimensions()[2],getDimensions()[2]);

        xVal = getDimensions()[0];
        yVal = getDimensions()[1] + getDimensions()[2] + 20;

        shape->drawText(xVal, yVal, QString::fromStdString("Shape Id: ") + QString::number(getId()));
    }
    else
    {
        shape->drawEllipse(getDimensions()[0],getDimensions()[1],getDimensions()[2],getDimensions()[3]);

        xVal = getDimensions()[0];
        yVal = getDimensions()[1] + getDimensions()[3] + 20;

        shape->drawText(xVal, yVal, QString::fromStdString("Shape Id: ") + QString::number(getId()));
    }
    shape->restore(); //restore to the original state of qpainter
}
void Ellipse::move(int dims_[])
{
    getDimensions()[0] = dims_[0];
    getDimensions()[1] = dims_[1];
}
int Ellipse::perimeter()
{
    if(!isCircle())
    {
        int a = getDimensions()[2];
        int b = getDimensions()[3];
        int h = pow(a-b, 2)/pow(a+b, 2);

        int perimeter = (int)(3.14 * (a + b) * (1 + ( (3 * h) / (10 + sqrt(4 - 3 * h)) ) ));
        return perimeter;
    }
    else
        return (int)(2 * 3.14 * getDimensions()[2]);
}
int Ellipse::area()
{
    if(!isCircle())
    {
        return (int)(3.14 * getDimensions()[2] * getDimensions()[3]);
    }
    else
        return (int)(3.14 * pow(getDimensions()[2], 2));

}
bool Ellipse::isCircle()
{
    if(getDimensions().size() == 3 || this->getShape() == Shape::CIRCLE)
    {
        return true;
    }
    return false;
}
