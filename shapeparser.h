#ifndef SHAPEPARSER_H
#define SHAPEPARSER_H

#include <QPainter>
#include <Qt>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include "Shapes.h"
#include "Line.h"
#include "Polyline.h"
#include "Polygon.h"
#include "Rectangle.h"
#include "Ellipse.h"
#include "Text.h"

using std::getline;
using std::string;
using std::cin;
using std::cout;
using std::ifstream;
using std::istringstream;
using std::remove;
/*! \file */
/*! \file ShapeParser.h */
/** @file ShapeParser.h */

/*!
    @brief The types of shapes are defined through an enum here
*/

//Unique functions for loading each shape type.

/*! @brief Loads a line.

    Passed the input file stream object so it can read from the shapes.txt file
    and the line id.
    Reads in the remaining line information needed from the file
    and returns a pointer to a line object created within the function.

    @param ifsteam& The input file stream object
    @param id The line id

    @return a pointer to a line object
*/
void LoadLine(QTextStream&, class Line* shapePtr);

/*! @brief Loads a polyline.

    Passed the input file stream object so it can read from the shapes.txt file
    and the polyline id.
    Reads in the remaining polyline information needed from the file
    and returns a pointer to a polyline object created within the function.

    @param ifsteam& The input file stream object
    @param id The polyline id

    @return a pointer to a polyline object
*/
void LoadPolyline(QTextStream&, class Polyline* shapePtr);

/*! @brief Loads a polygon.

    Passed the input file stream object so it can read from the shapes.txt file
    and the polygon id.
    Reads in the remaining polygon information needed from the file
    and returns a pointer to a polygon object created within the function.

    @param ifsteam& The input file stream object
    @param id The polygon id

    @return a pointer to a polygon object
*/
void LoadPolygon(QTextStream&, class Polygon* shapePtr);

/*! @brief Loads a rectangle.

    Passed the input file stream object so it can read from the shapes.txt file
    and the rectangle id.
    Reads in the remaining rectangle information needed from the file
    and returns a pointer to a rectangle object created within the function.

    @param ifsteam& The input file stream object
    @param id The rectangle id

    @return a pointer to a rectangle object
*/
void LoadRectangle(QTextStream&, class Rectangle* shapePtr);

/*! @brief Loads a square.

    Passed the input file stream object so it can read from the shapes.txt file
    and the square id.
    Reads in the remaining square informGlobalation needed from the file
    and returns a pointer to a square object created within the function.

    @param ifsteam& The input file stream object
    @param id The square id

    @return a pointer to a square object
*/
void LoadSquare(QTextStream&, class Rectangle* shapePtr);

/*! @brief Loads a ellipse.

    Passed the input file stream object so it can read from the shapes.txt file
    and the ellipse id.
    Reads in the remaining ellipse information needed from the file
    and returns a pointer to a ellipse object created within the function.

    @param ifsteam& The input file stream object
    @param id The ellipse id

    @return a pointer to a ellipse object
*/
void LoadEllipse(QTextStream&, class Ellipse* shapePtr);

/*! @brief Loads a circle.

    Passed the input file stream object so it can read from the shapes.txt file
    and the circle id.
    Reads in the remaining circle information needed from the file
    and returns a pointer to a circle object created within the function.

    @param ifsteam& The input file stream object
    @param id The circle id

    @return a pointer to a circle object
*/
void LoadCircle(QTextStream&, class Ellipse* shapePtr);


/*! @brief Loads a text.

    Passed the input file stream object so it can read from the shapes.txt file
    and the text id.
    Reads in the remaining text information needed from the file
    and returns a pointer to a text object created within the function.

    @param ifsteam& The input file stream object
    @param id The text id

    @return a pointer to a text object
*/
void LoadText(QTextStream&, class Text* shapePtr);

/*! @brief Getter functions to convert the string input from the shapes.txt file
   into the QT GlobalColor being passed into the setter functions for each shape.

    @param string String input to be parsed
  */
Qt::GlobalColor getColor(const QString&);
/*! @brief Getter functions to convert the string input from the shapes.txt file
   into the QT PenStyle being passed into the setter functions for each shape.

   @param string String input to be parsed
  */
Qt::PenStyle getPenStyle(const QString&);
/*! @brief Getter functions to convert the string input from the shapes.txt file
   into the QT PenCapStyle being passed into the setter functions for each shape.

   @param string String input to be parsed
  */
Qt::PenCapStyle getPenCapStyle(const QString&);
/*! @brief Getter functions to convert the string input from the shapes.txt file
   into the Q PenJoinStyle being passed into the setter functions for each shape.

   @param string String input to be parsed
  */
Qt::PenJoinStyle getPenJoinStyle(const QString&);
/*! @brief Getter functions to convert the string input from the shapes.txt file
   into the QT BrushStyle being passed into the setter functions for each shape.

   @param string String input to be parsed
  */
Qt::BrushStyle getBrushStyle(const QString&);
/*! @brief Getter functions to convert the string input from the shapes.txt file
   into the QT AlignmentFlag being passed into the setter functions for each shape.

   @param string String input to be parsed
  */
Qt::Alignment getAlignment(const QString&);
/*! @brief Getter functions to convert the string input from the shapes.txt file
   into the QFont Style being passed into the setter functions for each shape.

   @param string String input to be parsed
  */
QFont::Style getFontStyle(const QString&);
/*! @brief Getter functions to convert the string input from the shapes.txt file
   into the QFont Weight being passed into the setter functions for each shape.

   @param string String input to be parsed
  */
QFont::Weight getFontWeight(const QString&);

/*! @brief Function to return a vector of shape* using the shapes.txt file as input.
*/
std::vector<Shape*> LoadFile();

#endif // SHAPEPARSER_H
