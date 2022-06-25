#include "Polygon.h"
#include <cmath>
//using namespace std;

Polygon::Polygon(int id, ShapeType type)
    :Shape(id, type)
{
}

void Polygon::draw(QPainter *shape)
{
    QVector<QPoint> points;
    for(int x = 0; x < int(getDimensions().size()); x+=2)
    {
        points.push_back(QPoint(getDimensions()[x], getDimensions()[x+1]));
    }

    shape->save(); //save original state of qpainter

    shape->setPen(getPen());
    shape->setBrush(getBrush());

    shape->drawPolygon(points);

    shape->restore(); //restore to the original state of qpainter
}
void Polygon::move(int dims_[])
{
    int elementNum = getDimensions().size();
    for(int i = 0; i < elementNum; i++)
    {
        getDimensions()[i] = dims_[i];
    }
}
int Polygon::perimeter()
{
    int perimeter = 0;
    int elementNum = getDimensions().size();
    for(int i = 0; i < elementNum-2; i+=2)
    {
        perimeter += (int)(sqrt(pow(getDimensions()[i+2] - getDimensions()[i], 2) + pow(getDimensions()[i+3] - getDimensions()[i+1], 2)) );
    }
    return perimeter;
}
int Polygon::area()
{
    int numSides = (getDimensions().size()/2);
    double theta = 360/2*numSides;
    double apothem = (perimeter()/numSides/tan(theta));

    int area = (int)(0.5 * apothem * perimeter());
    return area;
}
