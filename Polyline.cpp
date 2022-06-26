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

    int xVal = points[0].x();
    int yVal = points[0].y();

    for(int x = 0; x < points.size(); x++)
    {
        if(points[x].x() < xVal)
        {
            xVal = points[x].x();
        }
        if(points[x].y() > yVal)
        {
            yVal = points[x].y();
        }
    }
    yVal += 20;

    shape->drawText(xVal, yVal, QString::fromStdString("Shape Id: ") + QString::number(getId()));

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
