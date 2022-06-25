#ifndef RECTANGLE_H
#define RECTANGLE_H

/*! \file */
#include "Shapes.h"
#include <QPaintDevice>
//using namespace std;

class Rectangle: public Shape
{
  public:
    /*!*****************************************************************
    *	@brief Constructor	Rectangle:	Class Rectangle
    *___________________________________________________________________
    *	Constructs a fully instantiated object of the rectangle class.
    *___________________________________________________________________
    *	PRE-CONDITIONS
    *   int id - id of the shape
    *   ShapeType type - type of shape
    *
    *	POST-CONDITIONS
    *	This function creates a Rectangle object of type RECTANGLE.
    @param id - id of the shape
    @param type - type of shape
    *******************************************************************/
    Rectangle(int id = -1, ShapeType type = NONE);

    /*!*****************************************************************
    *	@brief Constructor	Rectangle:	Class Rectangle
    *___________________________________________________________________
    *	Creates the default instance of the rectangle class.
    *___________________________________________________________________
    *	PRE-CONDITIONS
    *	<none>
    *
    *	POST-CONDITIONS
    *	This function creates a Rectangle object of type RECTANGLE.
    *******************************************************************/
    Rectangle();

    /*!*****************************************************************
    *	@brief Destructor	~Rectangle:	Class Rectangle
    *___________________________________________________________________
    *	Destructs the rectangle object.
    *___________________________________________________________________
    *	PRE-CONDITIONS
    *	<none>
    *
    *	POST-CONDITIONS
    *	This function destructs the outstanding pointers in Rectangle.
    *******************************************************************/
    ~Rectangle() {};

    /*!*****************************************************************
    *	@brief Method	isSquare:	Class Rectangle
    *___________________________________________________________________
    *	This method will check if a rectangle is also a square.
    *   Returns bool value.
    *___________________________________________________________________
    *	PRE-CONDITIONS
    *	<none>
    *
    *	POST-CONDITIONS
    *	Returns bool which determines if rectangle is square.
    @return Returns bool which determines if rectangle is square.
    *******************************************************************/
    bool isSquare(); //checks if shape is square

    /*!*****************************************************************
    *	@brief Method	draw:	Class Rectangle
    *___________________________________________________________________
    *	This method will draw a Rectangle on the canvas. Returns nothing.
    *___________________________________________________________________
    *	PRE-CONDITIONS
    *	<none>
    *
    *	POST-CONDITIONS
    *	Returns nothing. Draws shape on canvas.
    *******************************************************************/
    void draw(QPainter* shape) override;

    /*!*****************************************************************
    *	@brief Method	move:	Class Rectangle
    *___________________________________________________________________
    *	This method will move a Rectangle on the canvas. Returns nothing.
    *___________________________________________________________________
    *	PRE-CONDITIONS
    *	int[] - array of integers with new coordinates
    *
    *	POST-CONDITIONS
    *	Returns nothing. Draws shape on canvas.
    @param int[] array of integers with new coordinates
    *******************************************************************/
    void move(int[]) override;

    /*!*****************************************************************
    *	@brief Method	perimeter:	Class Rectangle
    *___________________________________________________________________
    *	This virtual method will calculate the perimeter of a Rectangle,
    *   which adds up the length of each side.
    *___________________________________________________________________
    *	PRE-CONDITIONS
    *	<none>
    *
    *	POST-CONDITIONS
    *	Returns integer perimeter for Rectangle
    @return Returns integer perimeter for Rectangle
    *******************************************************************/
    int perimeter() override;

    /*!*****************************************************************
    *	@brief Method	area:	Class Rectangle
    *___________________________________________________________________
    *	This virtual method will calculate the area of a Rectangle,
    *   which multiplies the width by the height.
    *___________________________________________________________________
    *	PRE-CONDITIONS
    *	<none>
    *
    *	POST-CONDITIONS
    *	Returns integer area for Rectangle
    @return Returns integer area for Rectangle
    *******************************************************************/
    int area() override;
};

#endif // RECTANGLE_H
