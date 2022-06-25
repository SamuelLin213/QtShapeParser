#include "Text.h"
//using namespace std;

class Text;

Text::Text(int id, ShapeType type)
    :Shape(id, type)
{
}
Text::~Text()
{}

void Text::draw(QPainter* shape)
{
    shape->save(); //save original state of qpainter
    shape->setPen(getPen());
    shape->setBrush(getBrush());
    shape->drawText(getDimensions()[0], getDimensions()[1], getDimensions()[2], getDimensions()[3], 0, text.toPlainText());
    shape->restore(); //restore to the original state of qpainter
}
QFont Text::getFont()
{
    return font;
}
QTextEdit& Text::getText()
{
    return text;
}
void Text::move(int dims_[])
{
    getDimensions()[0] = dims_[0];
    getDimensions()[1]= dims_[1];
}

void Text::setText(const QString &text_)
{
  text.setText(text_);
}
void Text::setTColor(const QColor &c)
{
  text.setTextColor(c);
}
void Text::setAlignment(Qt::Alignment a)
{
  text.setAlignment(a);
}
void Text::setPointSize(qreal s)
{
  text.setFontPointSize(s);
}
void Text::setFontFamily(const QString &fontFamily)
{
  text.setFontFamily(fontFamily);
}
void Text::setFontStyle(QFont::Style style)
{
  font.setStyle(style);
}
void Text::setFontWeight(QFont::Weight weight)
{
  text.setFontWeight(weight);
}
