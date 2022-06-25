#include "canvas.h"
#include "Shapes.h"
#include "mainwindow.h"
#include "shapeparser.h"
#include <QPainter>
#include <QPainterPath>
#include <QTextEdit>
#include <QInputDialog>
#include <string>
#include <QtDebug>
#include <QFile>
#include <iostream>

canvas::canvas(QWidget *parent)
    : QWidget(parent)
    //, ui(new Ui::canvas)
{
    shapeList = LoadFile();
    qDebug() << "after copying shapeList: " << shapeList.size() << "\n";
    qInfo() << "after copying shapeList: " << shapeList.size() << "\n";

    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
}
void canvas::paintEvent(QPaintEvent *)
{
    painter = new QPainter(this);

    for(int i = 0; i < (int)(shapeList.size()); i++)
    {
        shapeList[i]->draw(painter);
    }
    painter->end();
}
QPainter* canvas::getPainter()
{
    return painter;
}
void canvas::drawLine()
{
    bool ok;
    int shapeId;
    std::vector<int> dimensionVector;

    shapeId = QInputDialog::getInt(this, tr("Add shape"),
                                      tr("Enter id of shape:"),
                                      1, 1, 50, 1, &ok);
    if(!ok)
        return;

    for(int i = 1; i <= 2; i++)
    {
        int newX = QInputDialog::getInt(this, tr("New Coordinates"),
                                             tr("New X:"),
                                             0, 0, 850, 1, &ok);
        if(!ok)
            return;
        int newY = QInputDialog::getInt(this, tr("New Coordinates"),
                                        tr("New Y:"),
                                        0, 0, 475, 1, &ok);
        if(!ok)
            return;
        dimensionVector.push_back(newX);
        dimensionVector.push_back(newY);
    }

    shapeList.push_back(new class Line(shapeId, Shape::LINE));
    //applies new coords
    for(int i = 0; i < 4; i++)
    {
        shapeList[shapeList.size()-1]->addDimension(dimensionVector[i]);
    }
    dynamic_cast<Line*>(shapeList[shapeList.size()-1])->setLine();

    update();
}
void canvas::drawPolyline()
{
    bool ok;
    int shapeId;
    int numPoints;
    std::vector<int> dimensionVector;

    shapeId = QInputDialog::getInt(this, tr("Add shape"),
                                      tr("Enter id of shape:"),
                                      1, 1, 50, 1, &ok);
    if(!ok)
        return;
    numPoints = QInputDialog::getInt(this, tr("Points"),
                                     tr("Number of points to move(default 1):"),
                                     1, 1, 50, 1, &ok);
    if(!ok)
        return;


    for(int i = 0; i < numPoints; i++)
    {
        int newX = QInputDialog::getInt(this, tr("New Coordinates"),
                                             tr("New X:"),
                                             0, 0, 850, 1, &ok);
        if(!ok)
            return;
        int newY = QInputDialog::getInt(this, tr("New Coordinates"),
                                        tr("New Y:"),
                                        0, 0, 475, 1, &ok);
        if(!ok)
            return;
        dimensionVector.push_back(newX);
        dimensionVector.push_back(newY);
    }

    shapeList.push_back(new class Polyline(shapeId, Shape::POLYLINE));
    //applies new coords
    for(int i = 0; i < (int)(dimensionVector.size()); i++)
    {
        shapeList[shapeList.size()-1]->addDimension(dimensionVector[i]);
    }

    update();
}
void canvas::drawPolygon()
{
    bool ok;
    int shapeId;
    int numPoints;
    std::vector<int> dimensionVector;

    shapeId = QInputDialog::getInt(this, tr("Add shape"),
                                      tr("Enter id of shape:"),
                                      1, 1, 50, 1, &ok);
    if(!ok)
        return;
    numPoints = QInputDialog::getInt(this, tr("Points"),
                                     tr("Number of points to move(default 1):"),
                                     1, 1, 50, 1, &ok);
    if(!ok)
        return;


    for(int i = 0; i < numPoints; i++)
    {
        int newX = QInputDialog::getInt(this, tr("New Coordinates"),
                                             tr("New X:"),
                                             0, 0, 850, 1, &ok);
        if(!ok)
            return;
        int newY = QInputDialog::getInt(this, tr("New Coordinates"),
                                        tr("New Y:"),
                                        0, 0, 475, 1, &ok);
        if(!ok)
            return;
        dimensionVector.push_back(newX);
        dimensionVector.push_back(newY);
    }

    shapeList.push_back(new class Polygon(shapeId, Shape::POLYGON));
    //applies new coords
    for(int i = 0; i < (int)(dimensionVector.size()); i++)
    {
        shapeList[shapeList.size()-1]->addDimension(dimensionVector[i]);
    }

    update();
}
void canvas::drawRectangle()
{
    bool ok;
    int shapeId;
    std::vector<int> dimensionVector;

    shapeId = QInputDialog::getInt(this, tr("Add shape"),
                                      tr("Enter id of shape:"),
                                      1, 1, 50, 1, &ok);
    if(!ok)
        return;

    int newX = QInputDialog::getInt(this, tr("New Coordinates"),
                                         tr("New X:"),
                                         0, 0, 850, 1, &ok);
    if(!ok)
        return;
    int newY = QInputDialog::getInt(this, tr("New Coordinates"),
                                    tr("New Y:"),
                                    0, 0, 475, 1, &ok);
    if(!ok)
        return;
    dimensionVector.push_back(newX);
    dimensionVector.push_back(newY);

    newX = QInputDialog::getInt(this, tr("New dimensions"),
                                             tr("New length:"),
                                             0, 0, 850, 1, &ok);
    if(!ok)
        return;
    newY = QInputDialog::getInt(this, tr("New dimensions"),
                                        tr("New width:"),
                                        0, 0, 475, 1, &ok);
    if(!ok)
        return;
    dimensionVector.push_back(newX);
    dimensionVector.push_back(newY);

    shapeList.push_back(new class Rectangle(shapeId, Shape::RECTANGLE));
    //applies new coords
    for(int i = 0; i < 4; i++)
    {
        shapeList[shapeList.size()-1]->addDimension(dimensionVector[i]);
    }

    update();
}
void canvas::drawSquare()
{
    bool ok;
    int shapeId;
    std::vector<int> dimensionVector;

    shapeId = QInputDialog::getInt(this, tr("Add shape"),
                                      tr("Enter id of shape:"),
                                      1, 1, 50, 1, &ok);
    if(!ok)
        return;

    int newX = QInputDialog::getInt(this, tr("New Coordinates"),
                                         tr("New X:"),
                                         0, 0, 850, 1, &ok);
    if(!ok)
        return;
    int newY = QInputDialog::getInt(this, tr("New Coordinates"),
                                    tr("New Y:"),
                                    0, 0, 475, 1, &ok);
    if(!ok)
        return;
    dimensionVector.push_back(newX);
    dimensionVector.push_back(newY);

    newX = QInputDialog::getInt(this, tr("New dimensions"),
                                             tr("New length:"),
                                             0, 0, 850, 1, &ok);
    if(!ok)
        return;
    dimensionVector.push_back(newX);
    dimensionVector.push_back(newX);

    shapeList.push_back(new class Rectangle(shapeId, Shape::SQUARE));
    //applies new coords
    for(int i = 0; i < 4; i++)
    {
        shapeList[shapeList.size()-1]->addDimension(dimensionVector[i]);
    }

    update();
}
void canvas::drawEllipse()
{
    bool ok;
    int shapeId;
    std::vector<int> dimensionVector;

    shapeId = QInputDialog::getInt(this, tr("Add shape"),
                                      tr("Enter id of shape:"),
                                      1, 1, 50, 1, &ok);
    if(!ok)
        return;

    int newX = QInputDialog::getInt(this, tr("New Coordinates"),
                                         tr("New X:"),
                                         0, 0, 850, 1, &ok);
    if(!ok)
        return;
    int newY = QInputDialog::getInt(this, tr("New Coordinates"),
                                    tr("New Y:"),
                                    0, 0, 475, 1, &ok);
    if(!ok)
        return;
    dimensionVector.push_back(newX);
    dimensionVector.push_back(newY);

    newX = QInputDialog::getInt(this, tr("New axis"),
                                             tr("New semi-major axis:"),
                                             0, 0, 850, 1, &ok);
    if(!ok)
        return;
    newY = QInputDialog::getInt(this, tr("New axis"),
                                        tr("New semi-minor axis:"),
                                        0, 0, 475, 1, &ok);
    if(!ok)
        return;
    dimensionVector.push_back(newX);
    dimensionVector.push_back(newY);

    shapeList.push_back(new class Ellipse(shapeId, Shape::ELLIPSE));
    //applies new coords
    for(int i = 0; i < 4; i++)
    {
        shapeList[shapeList.size()-1]->addDimension(dimensionVector[i]);
    }

    update();
}
void canvas::drawCircle()
{
    bool ok;
    int shapeId;
    std::vector<int> dimensionVector;

    shapeId = QInputDialog::getInt(this, tr("Add shape"),
                                      tr("Enter id of shape:"),
                                      1, 1, 50, 1, &ok);
    if(!ok)
        return;

    int newX = QInputDialog::getInt(this, tr("New Coordinates"),
                                         tr("New X:"),
                                         0, 0, 850, 1, &ok);
    if(!ok)
        return;
    int newY = QInputDialog::getInt(this, tr("New Coordinates"),
                                    tr("New Y:"),
                                    0, 0, 475, 1, &ok);
    if(!ok)
        return;
    dimensionVector.push_back(newX);
    dimensionVector.push_back(newY);

    newX = QInputDialog::getInt(this, tr("New dimension"),
                                             tr("New radius:"),
                                             0, 0, 850, 1, &ok);
    if(!ok)
        return;
    dimensionVector.push_back(newX);
    dimensionVector.push_back(newX);

    shapeList.push_back(new class Ellipse(shapeId, Shape::CIRCLE));
    //applies new coords
    for(int i = 0; i < 4; i++)
    {
        shapeList[shapeList.size()-1]->addDimension(dimensionVector[i]);
    }

    update();
}
void canvas::drawText()
{
    bool ok;
    int shapeId;
    std::vector<int> dimensionVector;

    shapeId = QInputDialog::getInt(this, tr("Add shape"),
                                      tr("Enter id of shape:"),
                                      1, 1, 50, 1, &ok);
    if(!ok)
        return;


    int newX = QInputDialog::getInt(this, tr("New Coordinates"),
                                         tr("New X:"),
                                         0, 0, 850, 1, &ok);
    if(!ok)
        return;
    int newY = QInputDialog::getInt(this, tr("New Coordinates"),
                                    tr("New Y:"),
                                    0, 0, 475, 1, &ok);
    if(!ok)
        return;
    dimensionVector.push_back(newX);
    dimensionVector.push_back(newY);

    newX = QInputDialog::getInt(this, tr("New dimensions"),
                                             tr("New length:"),
                                             0, 0, 850, 1, &ok);
    if(!ok)
        return;
    newY = QInputDialog::getInt(this, tr("New dimensions"),
                                        tr("New width:"),
                                        0, 0, 475, 1, &ok);
    if(!ok)
        return;
    dimensionVector.push_back(newX);
    dimensionVector.push_back(newY);

    shapeList.push_back(new class Text(shapeId, Shape::TEXT));
    //applies new coords
    for(int i = 0; i < 4; i++)
    {
        shapeList[shapeList.size()-1]->addDimension(dimensionVector[i]);
    }
    QString text = QInputDialog::getText(this, tr("Get message"),
                                         tr("Text to display:"), QLineEdit::Normal,
                                         tr("your message"), &ok);
    if(!ok)
        return;

    dynamic_cast<Text*>(shapeList[shapeList.size()-1])->setText(text);

    update();
}
void canvas::moveShape()
{
    update();
}
void canvas::removeShape()
{
    update();
}
void canvas::addShape()
{
    update();
}
