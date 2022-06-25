#include "Polyline.h"

class Polyline;

Polyline::Polyline(int id, ShapeType type)
    :Shape(id, type)
{
}

void Polyline::draw(QPainter* shape)
{
    QVector<QPoint> points;
    for(int x = 0; x < int(getDimensions().size()); x+=2)
    {
        points.push_back(QPoint(getDimensions()[x], getDimensions()[x+1]));
    }

    shape->save(); //save original state of qpainter

    shape->setPen(getPen());
    shape->setBrush(getBrush());

    shape->drawPolyline(points);

    shape->restore(); //restore to the original state of qpainter
}
void Polyline::move(int dims_[])
{
    int elementNum = getDimensions().size();
    for(int i = 0; i < elementNum; i++)
    {
        getDimensions()[i] = dims_[i];
    }
}
