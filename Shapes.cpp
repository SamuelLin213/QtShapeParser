#include "Shapes.h"
//using namespace std;

class Shape;

// **Constructor**
Shape::Shape(int id, ShapeType type)
  :id{id}, shape{type}
{
  pen = Qt::SolidLine;
  brush = Qt::NoBrush;
  qpainter.setPen(pen);
  qpainter.setBrush(brush);
}
//Accessors
QPainter& Shape::getPainter()
{
    return qpainter;
}

std::vector<int>& Shape::getDimensions()
{
    return dimensions;
}

Shape::ShapeType Shape::getShape() const
{
  return shape;
}

const QPen& Shape::getPen() const
{
  return pen;
}

const QBrush& Shape::getBrush() const
{
  return brush;
}
int Shape::getId()
{
    return id;
}

//Modifiers
void Shape::setPen(Qt::GlobalColor newColor)
{
  pen = QPen(newColor);
  qpainter.setPen(pen);
}

void Shape::setBrush(Qt::GlobalColor newColor, Qt::BrushStyle newStyle)
{
  brush = QBrush(newColor, newStyle);
  qpainter.setBrush(brush);
}

void Shape::setShape(ShapeType shape)
{
  this->shape = shape;
}

void Shape::addDimension(int dim)
{
    dimensions.push_back(dim);
}
void Shape::setColor(QColor color)
{
    pen.setColor(color);
}
void Shape::setWidth(int width)
{
    pen.setWidth(width);
}
void Shape::setStyle(Qt::PenStyle style)
{
    pen.setStyle(style);
}
void Shape::setCapStyle(Qt::PenCapStyle capStyle)
{
    pen.setCapStyle(capStyle);
}
void Shape::setJoinStyle(Qt::PenJoinStyle style)
{
    pen.setJoinStyle(style);
}
void Shape::setBrushColor(QColor color)
{
    brush.setColor(color);
}
void Shape::setBrushStyle(Qt::BrushStyle style)
{
    brush.setStyle(style);
}

//Overloaded operators
bool Shape::operator==(const Shape& rhs) const
{
    return(this->id == rhs.id);
}
bool Shape::operator<(const Shape& rhs) const
{
    return(this->id < rhs.id);
}
