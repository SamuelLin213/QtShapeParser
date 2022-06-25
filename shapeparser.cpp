#include "shapeparser.h"
#include <QFile>


const QMap<QString, Shape::ShapeType> SHAPE_TYPE_CONV
{
    {"Line", Shape::ShapeType::LINE},
    {"Polyline", Shape::ShapeType::POLYLINE},
    {"Polygon", Shape::ShapeType::POLYGON},
    {"Rectangle", Shape::ShapeType::RECTANGLE},
    {"Square", Shape::ShapeType::SQUARE},
    {"Ellipse", Shape::ShapeType::ELLIPSE},
    {"Circle", Shape::ShapeType::CIRCLE},
    {"Text", Shape::ShapeType::TEXT}
};

std::vector<Shape*> LoadFile()
{
    QString qPath = ":/shapes.txt";
    QFile file(qPath);

    if(!file.exists())
    {
        qCritical() << "File not found";
        return {};
    }

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qCritical() << file.errorString();
        return {};
    }

    //myVector<Shape*> shapeList;
    std::vector<Shape*> shapeList;
    int id;
    QString shapeType_s;
    int shapeType;

    QString shapeCat = "";

    QTextStream fin(&file);

    while(!fin.atEnd())
    {
        //Read in the shape's unique id
        fin >> shapeCat;
        fin >> id;

        //Read in the type of the shape
        fin >> shapeCat;
        fin >> shapeType_s;

        shapeType = SHAPE_TYPE_CONV[shapeType_s];

        //Depending on the type of the shape, call the appropriate Load... function to load said shape
        switch(shapeType)
        {
        case Shape::ShapeType::LINE:
            shapeList.push_back(new class Line(id, Shape::LINE));
            LoadLine(fin, dynamic_cast<Line*>(shapeList[shapeList.size()-1]));
            break;

        case Shape::ShapeType::POLYLINE:
            shapeList.push_back(new class Polyline(id, Shape::POLYLINE));
            LoadPolyline(fin, dynamic_cast<Polyline*>(shapeList[shapeList.size()-1]));
            break;

        case Shape::ShapeType::POLYGON:
            shapeList.push_back(new class Polygon(id, Shape::POLYGON));
            LoadPolygon(fin, dynamic_cast<Polygon*>(shapeList[shapeList.size()-1]));
            break;

        case Shape::ShapeType::RECTANGLE:
            shapeList.push_back(new class Rectangle(id, Shape::RECTANGLE));
            LoadRectangle(fin, dynamic_cast<Rectangle*>(shapeList[shapeList.size()-1]));
            break;

        case Shape::ShapeType::SQUARE:
            shapeList.push_back(new class Rectangle(id, Shape::SQUARE));
            LoadSquare(fin, dynamic_cast<Rectangle*>(shapeList[shapeList.size()-1]));
            break;

        case Shape::ShapeType::ELLIPSE:
            shapeList.push_back(new class Ellipse(id, Shape::ELLIPSE));
            LoadEllipse(fin, dynamic_cast<Ellipse*>(shapeList[shapeList.size()-1]));
            break;

        case Shape::ShapeType::CIRCLE:
            shapeList.push_back(new class Ellipse(id, Shape::CIRCLE));
            LoadCircle(fin, dynamic_cast<Ellipse*>(shapeList[shapeList.size()-1]));
            break;

        case Shape::ShapeType::TEXT:
            shapeList.push_back(new class Text(id, Shape::TEXT));
            LoadText(fin, dynamic_cast<Text*>(shapeList[shapeList.size()-1]));
            break;
        }//end switch(shapeType)
        if(fin.atEnd())
        {
            break;
        }
    }//end while(fin)


    file.close();

    return shapeList;
}

void LoadLine(QTextStream& fin, class Line* shapePtr)
{
    int tempInt;
    QString dimensions_s;
    QString penColor;
    int penWidth;
    QString penStyle;
    QString penCapStyle;
    QString penJoinStyle;

    QString shapeCat = "";

    //Read in a string of ints for line dimensions in format x1, y1, x2, y2
    fin >> shapeCat;
    dimensions_s = fin.readLine();

    string dimension = dimensions_s.toStdString();

    //Remove the commas from the string of numbers
    dimension.erase(remove(dimension.begin(), dimension.end(), ','), dimension.end());

    //Create an input string stream object using the string of numbers in format x1 y1 x2 y2
    istringstream sstr(dimension);

    //Read in pen color
    fin >> shapeCat;
    fin >> penColor;

    //Read in pen width
    fin >> shapeCat;
    fin >> penWidth;

    //Read in pen style
    fin >> shapeCat;
    fin >> penStyle;

    //Read in pen cap style
    fin >> shapeCat;
    fin >> penCapStyle;

    //Read in pen join style
    fin >> shapeCat;
    fin >> penJoinStyle;

    //Set the values of the new line being returned by the function
    shapePtr->setColor(getColor(penColor));
    shapePtr->setWidth(penWidth);
    shapePtr->setStyle(getPenStyle(penStyle));
    shapePtr->setCapStyle(getPenCapStyle(penCapStyle));
    shapePtr->setJoinStyle(getPenJoinStyle(penJoinStyle));

    while(sstr >> tempInt)
    {
        shapePtr->addDimension(tempInt);
    }
    shapePtr->setLine();
}

void LoadPolyline(QTextStream& fin, class Polyline* shapePtr)
{
    int tempInt;
    QString dimensions_s;
    QString penColor;
    int penWidth;
    QString penStyle;
    QString penCapStyle;
    QString penJoinStyle;

    QString shapeCat =   "";

    //Read in a string of ints for line dimensions in format x1, y1, x2, y2
    fin >> shapeCat;
    dimensions_s = fin.readLine();

    string dimension = dimensions_s.toStdString();

    //Remove the commas from the string of numbers
    dimension.erase(remove(dimension.begin(), dimension.end(), ','), dimension.end());

    //Create an input string stream object using the string of numbers in format x1 y1 x2 y2
    istringstream sstr(dimension);

    //Read in pen color
    fin >> shapeCat;
    fin >> penColor;

    //Read in pen width
    fin >> shapeCat;
    fin >> penWidth;

    //Read in pen style
    fin >> shapeCat;
    fin >> penStyle;

    //Read in pen cap style
    fin >> shapeCat;
    fin >> penCapStyle;

    //Read in pen join style
    fin >> shapeCat;
    fin >> penJoinStyle;

    //Set the values of the new polyline being returned by the function
    shapePtr->setColor(getColor(penColor));
    shapePtr->setWidth(penWidth);
    shapePtr->setStyle(getPenStyle(penStyle));
    shapePtr->setCapStyle(getPenCapStyle(penCapStyle));
    shapePtr->setJoinStyle(getPenJoinStyle(penJoinStyle));

    //Read in the ints from the sstr object into tempInt, and then pass
    while(sstr >> tempInt)
    {
    shapePtr->addDimension(tempInt);
    }
}

void LoadPolygon(QTextStream& fin, class Polygon* shapePtr)
{
    int tempInt;
    QString dimensions_s;
    QString penColor;
    int penWidth;
    QString penStyle;
    QString penCapStyle;
    QString penJoinStyle;
    QString brushColor;
    QString brushStyle;

    QString shapeCat =   "";

    //Read in a string of ints for line dimensions in format x1, y1, x2, y2
    fin >> shapeCat;
    dimensions_s = fin.readLine();

    string dimension = dimensions_s.toStdString();

    //Remove the commas from the string of numbers
    dimension.erase(remove(dimension.begin(), dimension.end(), ','), dimension.end());

    //Create an input string stream object using the string of numbers in format x1 y1 x2 y2
    istringstream sstr(dimension);

    //Read in pen color
    fin >> shapeCat;
    fin >> penColor;

    //Read in pen width
    fin >> shapeCat;
    fin >> penWidth;

    //Read in pen style
    fin >> shapeCat;
    fin >> penStyle;

    //Read in pen cap style
    fin >> shapeCat;
    fin >> penCapStyle;

    //Read in pen join style
    fin >> shapeCat;
    fin >> penJoinStyle;

    //Read in brush color
    fin >> shapeCat;
    fin >> brushColor;

    //Read in brush style
    fin >> shapeCat;
    fin >> brushStyle;

    //Set the values of the new polyline being returned by the function
    shapePtr->setColor(getColor(penColor));
    shapePtr->setWidth(penWidth);
    shapePtr->setStyle(getPenStyle(penStyle));
    shapePtr->setCapStyle(getPenCapStyle(penCapStyle));
    shapePtr->setJoinStyle(getPenJoinStyle(penJoinStyle));
    shapePtr->setBrush(getColor(brushColor), getBrushStyle(brushStyle));

    //Read in the ints from the sstr object into tempInt, and then pass
    while(sstr >> tempInt)
    {
    shapePtr->addDimension(tempInt);
    }
}

void LoadRectangle(QTextStream& fin, class Rectangle* shapePtr)
{
    //Rectangle* shapePtr = new class Rectangle(id, Shape::RECTANGLE);

    int tempInt;
    QString dimensions_s;
    QString penColor;
    int penWidth;
    QString penStyle;
    QString penCapStyle;
    QString penJoinStyle;
    QString brushColor;
    QString brushStyle;

    QString shapeCat =   "";

    //Read in a string of ints for line dimensions in format x1, y1, x2, y2
    fin >> shapeCat;
    dimensions_s = fin.readLine();

    string dimension = dimensions_s.toStdString();

    //Remove the commas from the string of numbers
    dimension.erase(remove(dimension.begin(), dimension.end(), ','), dimension.end());

    //Create an input string stream object using the string of numbers in format x1 y1 x2 y2
    istringstream sstr(dimension);

    //Read in pen color
    fin >> shapeCat;
    fin >> penColor;

    //Read in pen width
    fin >> shapeCat;
    fin >> penWidth;

    //Read in pen style
    fin >> shapeCat;
    fin >> penStyle;

    //Read in pen cap style
    fin >> shapeCat;
    fin >> penCapStyle;

    //Read in pen join style
    fin >> shapeCat;
    fin >> penJoinStyle;

    //Read in brush color
    fin >> shapeCat;
    fin >> brushColor;

    //Read in brush style
    fin >> shapeCat;
    fin >> brushStyle;

    //Set the values of the new polylinlengthe being returned by the function
    shapePtr->setColor(getColor(penColor));
    shapePtr->setWidth(penWidth);
    shapePtr->setStyle(getPenStyle(penStyle));
    shapePtr->setCapStyle(getPenCapStyle(penCapStyle));
    shapePtr->setJoinStyle(getPenJoinStyle(penJoinStyle));
    shapePtr->setBrush(getColor(brushColor), getBrushStyle(brushStyle));

    //Read in the ints from the sstr object into tempInt, and then pass
    while(sstr >> tempInt)
    {
    shapePtr->addDimension(tempInt);
    }
}

void LoadSquare(QTextStream& fin, class Rectangle* shapePtr)
{
    int tempInt;
    QString dimensions_s;
    QString penColor;
    int penWidth;
    QString penStyle;
    QString penCapStyle;
    QString penJoinStyle;
    QString brushColor;
    QString brushStyle;

    QString shapeCat =   "";

    //Read in a string of ints for line dimensions in format x1, y1, x2, y2
    fin >> shapeCat;
    dimensions_s = fin.readLine();

    string dimension = dimensions_s.toStdString();

    //Remove the commas from the string of numbers
    dimension.erase(remove(dimension.begin(), dimension.end(), ','), dimension.end());

    //Create an input string stream object using the string of numbers in format x1 y1 x2 y2
    istringstream sstr(dimension);

    //Read in pen color
    fin >> shapeCat;
    fin >> penColor;

    //Read in pen width
    fin >> shapeCat;
    fin >> penWidth;

    //Read in pen style
    fin >> shapeCat;
    fin >> penStyle;

    //Read in pen cap style
    fin >> shapeCat;
    fin >> penCapStyle;

    //Read in pen join style
    fin >> shapeCat;
    fin >> penJoinStyle;

    //Read in brush color
    fin >> shapeCat;
    fin >> brushColor;

    //Read in brush style
    fin >> shapeCat;
    fin >> brushStyle;

    //Set the values of the new polyline being returned by the function
    shapePtr->setColor(getColor(penColor));
    shapePtr->setWidth(penWidth);
    shapePtr->setStyle(getPenStyle(penStyle));
    shapePtr->setCapStyle(getPenCapStyle(penCapStyle));
    shapePtr->setJoinStyle(getPenJoinStyle(penJoinStyle));
    shapePtr->setBrush(getColor(brushColor), getBrushStyle(brushStyle));

    //Read in the ints from the sstr object into tempInt, and then pass
    while(sstr >> tempInt)
    {
    shapePtr->addDimension(tempInt);
    }
}

void LoadEllipse(QTextStream& fin, class Ellipse* shapePtr)
{
    int tempInt;
    QString dimensions_s;
    QString penColor;
    int penWidth;
    QString penStyle;
    QString penCapStyle;
    QString penJoinStyle;
    QString brushColor;
    QString brushStyle;

    QString shapeCat =   "";

    //Read in a string of ints for line dimensions in format x1, y1, x2, y2
    fin >> shapeCat;
    dimensions_s = fin.readLine();

    string dimension = dimensions_s.toStdString();

    //Remove the commas from the string of numbers
    dimension.erase(remove(dimension.begin(), dimension.end(), ','), dimension.end());

    //Create an input string stream object using the string of numbers in format x1 y1 x2 y2
    istringstream sstr(dimension);

    //Read in pen color
    fin >> shapeCat;
    fin >> penColor;

    //Read in pen width
    fin >> shapeCat;
    fin >> penWidth;

    //Read in pen style
    fin >> shapeCat;
    fin >> penStyle;

    //Read in pen cap style
    fin >> shapeCat;
    fin >> penCapStyle;

    //Read in pen join style
    fin >> shapeCat;
    fin >> penJoinStyle;

    //Read in brush color
    fin >> shapeCat;
    fin >> brushColor;

    //Read in brush style
    fin >> shapeCat;
    fin >> brushStyle;

    //Set the values of the new polyline being returned by the function
    shapePtr->setColor(getColor(penColor));
    shapePtr->setWidth(penWidth);
    shapePtr->setStyle(getPenStyle(penStyle));
    shapePtr->setCapStyle(getPenCapStyle(penCapStyle));
    shapePtr->setJoinStyle(getPenJoinStyle(penJoinStyle));
    shapePtr->setBrush(getColor(brushColor), getBrushStyle(brushStyle));

    //Read in the ints from the sstr object into tempInt, and then pass
    while(sstr >> tempInt)
    {
    shapePtr->addDimension(tempInt);
    }
}

void LoadCircle(QTextStream& fin, class Ellipse* shapePtr)
{
    int tempInt;
    QString dimensions_s;
    QString penColor;
    int penWidth;
    QString penStyle;
    QString penCapStyle;
    QString penJoinStyle;
    QString brushColor;
    QString brushStyle;

    QString shapeCat =   "";

    //Read in a string of ints for line dimensions in format x1, y1, x2, y2
    fin >> shapeCat;
    dimensions_s = fin.readLine();

    string dimension = dimensions_s.toStdString();

    //Remove the commas from the string of numbers
    dimension.erase(remove(dimension.begin(), dimension.end(), ','), dimension.end());

    //Create an input string stream object using the string of numbers in format x1 y1 x2 y2
    istringstream sstr(dimension);

    //Read in pen color
    fin >> shapeCat;
    fin >> penColor;

    //Read in pen width
    fin >> shapeCat;
    fin >> penWidth;

    //Read in pen style
    fin >> shapeCat;
    fin >> penStyle;

    //Read in pen cap style
    fin >> shapeCat;
    fin >> penCapStyle;

    //Read in pen join style
    fin >> shapeCat;
    fin >> penJoinStyle;

    //Read in brush color
    fin >> shapeCat;
    fin >> brushColor;

    //Read in brush style
    fin >> shapeCat;
    fin >> brushStyle;

    //Set the values of the new polyline being returned by the function
    shapePtr->setColor(getColor(penColor));
    shapePtr->setWidth(penWidth);
    shapePtr->setStyle(getPenStyle(penStyle));
    shapePtr->setCapStyle(getPenCapStyle(penCapStyle));
    shapePtr->setJoinStyle(getPenJoinStyle(penJoinStyle));
    shapePtr->setBrush(getColor(brushColor), getBrushStyle(brushStyle));

    //Read in the ints from the sstr object into tempInt, and then pass
    while(sstr >> tempInt)
    {
    shapePtr->addDimension(tempInt);
    }
}

void LoadText(QTextStream& fin, class Text* shapePtr)
{
    int tempInt;
    QString dimensions_s;
    QString text_s;
    QString textColor;
    QString textAlignment;
    qreal textPointSize;
    QString textFontFamily;
    QString textFontStyle;
    QString textFontWeight;

    QString shapeCat =   "";

    //Read in a string of ints for line dimensions in format x1, y1, x2, y2
    fin >> shapeCat;
    dimensions_s = fin.readLine();

    string dimension = dimensions_s.toStdString();

    //Remove the commas from the string of numbers
    dimension.erase(remove(dimension.begin(), dimension.end(), ','), dimension.end());

    //Create an input string stream object using the string of numbers in format x1 y1 x2 y2
    istringstream sstr(dimension);

    //Read in pen color
    fin >> shapeCat;
    text_s = fin.readLine();

    //Read in pen width
    fin >> shapeCat;
    fin >> textColor;

    //Read in pen style
    fin >> shapeCat;
    fin >> textAlignment;

    //Read in pen cap style
    fin >> shapeCat;
    fin >> textPointSize;

    //Read in pen join style
    fin >> shapeCat;
    textFontFamily = fin.readLine();

    //Read in brush color
    fin >> shapeCat;
    fin >> textFontStyle;

    //Read in brush style
    fin >> shapeCat;
    fin >> textFontWeight;

    //Set the values of the new polyline being returned by the function
    shapePtr->setText(text_s);
    shapePtr->setTColor(getColor(textColor));
    shapePtr->setAlignment(getAlignment(textAlignment));
    shapePtr->setPointSize(textPointSize);
    shapePtr->setFontFamily(textFontFamily);
    shapePtr->setFontStyle(getFontStyle(textFontStyle));
    shapePtr->setFontWeight(getFontWeight(textFontWeight));

    //Read in the ints from the sstr object into tempInt, and then pass
    while(sstr >> tempInt)
    {
        shapePtr->addDimension(tempInt);
    }
}

Qt::GlobalColor getColor(const QString& objColor)
{
    if(objColor == "white")
    {
        return Qt::white;
    }
    else if(objColor == "black")
    {
        return Qt::black;
    }
    else if(objColor == "red")
    {
        return Qt::red;
    }
    else if(objColor == "green")
    {
        return Qt::green;
    }
    else if(objColor == "blue")
    {
        return Qt::blue;
    }
    else if(objColor == "cyan")
    {
        return Qt::cyan;
    }
    else if(objColor == "magenta")
    {
        return Qt::magenta;
    }
    else if(objColor == "yellow")
    {
        return Qt::yellow;
    }
    return Qt::gray;
}

Qt::PenStyle getPenStyle(const QString& style){
    if(style == "NoPen")
    {
        return Qt::NoPen;
    }
    else if(style == "SolidLine")
    {
        return Qt::SolidLine;
    }
    else if(style == "DashLine")
    {
        return Qt::DashLine;
    }
    else if(style == "DotLine")
    {
        return Qt::DotLine;
    }
    else if(style == "DashDotLine")
    {
        return Qt::DashDotLine;
    }
    return Qt::DashDotDotLine;
}

Qt::PenCapStyle getPenCapStyle(const QString& style){
    if(style == "FlatCap")
    {
        return Qt::FlatCap;
    }
    else if(style == "SquareCap")
    {
        return Qt::SquareCap;
    }
    return Qt::RoundCap;
}

Qt::PenJoinStyle getPenJoinStyle(const QString& style){
    if(style == "MiterJoin")
    {
        return Qt::MiterJoin;
    }
    else if(style == "BevelJoin")
    {
        return Qt::BevelJoin;
    }
    return Qt::RoundJoin;
}

Qt::BrushStyle getBrushStyle(const QString& style){
    if(style == "SolidPattern")
    {
        return Qt::SolidPattern;
    }
    else if(style == "HorPattern")
    {
        return Qt::HorPattern;
    }
    else if(style == "VerPattern")
    {
        return Qt::VerPattern;
    }
    return Qt::NoBrush;
}

Qt::Alignment getAlignment(const QString& alignment)
{
    if(alignment == "AlignLeft")
    {
        return Qt::AlignLeft;
    }
    else if(alignment == "AlignRight")
    {
        return Qt::AlignRight;
    }
    else if(alignment == "AlignTop")
    {
        return Qt::AlignTop;
    }
    else if(alignment == "AlignBottom")
    {
        return Qt::AlignBottom;
    }
    return Qt::AlignCenter;
}

QFont::Style getFontStyle(const QString& style){
    if(style == "StyleNormal")
    {
        return QFont::StyleNormal;
    }
    else if(style == "StyleItalic")
    {
        return QFont::StyleItalic;
    }
    return QFont::StyleOblique;
}

QFont::Weight getFontWeight(const QString& style){
    if(style == "Thin")
    {
        return QFont::Thin;
    }
    else if(style == "Light")
    {
        return QFont::Light;
    }
    else if(style == "Normal")
    {
        return QFont::Normal;
    }
    return QFont::Bold;
}

