#ifndef ELLIPSE_H
#define ELLIPSE_H

/*! \file */
#include "Shapes.h"

class Ellipse: public Shape
{
  public:
    /*!*****************************************************************
    *	@brief Constructor	Ellipse:	Class Ellipse
    *___________________________________________________________________
    *	Constructs a fully instantiated object of the Ellipse class.
    *___________________________________________________________________
    *	PRE-CONDITIONS
    *   int id - id of the shape
    *   ShapeType type - type of shape
    *
    *	POST-CONDITIONS
    *	This function creates a Ellipse object of type ELLIPSE.
    @param id - id of the shape
    @param type - type of shape
    *******************************************************************/
    Ellipse(int id = -1, ShapeType type = NONE);


    /*!*****************************************************************
    *	@brief Constructor	Ellipse:	Class Ellipse
    *___________________________________________________________________
    *	Creates the default instance of the ellipse class.
    *___________________________________________________________________
    *	PRE-CONDITIONS
    *	<none>
    *
    *	POST-CONDITIONS
    *	This function creates a Ellipse object of type ELLIPSE.
    *******************************************************************/
    Ellipse();

    /*!*****************************************************************
    *	@brief Destructor	~Ellipse:	Class Ellipse
    *___________________________________________________________________
    *	Destructs the ellipse object.
    *___________________________________________________________________
    *	PRE-CONDITIONS
    *	<none>
    *
    *	POST-CONDITIONS
    *	This function destructs the outstanding pointers in ellipse.
    *******************************************************************/
    ~Ellipse() {}


    /*!*****************************************************************
    *	@brief Method	isCircle:	Class Ellipse
    *___________________________________________________________________
    *	This method will check if a ellipse is also a circle.
    *   Returns bool value.
    *___________________________________________________________________
    *	PRE-CONDITIONS
    *	<none>
    *
    *	POST-CONDITIONS
    *	Returns bool which determines if ellipse is circle.
    @return Returns bool which determines if ellipse is circle.
    *******************************************************************/
    bool isCircle(); //checks if ellipse is circle

    /*!*****************************************************************
    *	@brief Method	draw:	Class Ellipse
    *___________________________________________________________________
    *	This method will draw an ellipse on the canvas. Returns nothing.
    *___________________________________________________________________
    *	PRE-CONDITIONS
    *	<none>
    *
    *	POST-CONDITIONS
    *	Returns nothing. Draws shape on canvas

    *******************************************************************/
    void draw(QPainter* shape) override;


    /*!*****************************************************************
    *	@brief Method	move:	Class Ellipse
    *___________________________________________________________________
    *	This method will move an ellipse using the integer array passed
    *   as a parameter to update the existing dimensions of the ellipse.
    *___________________________________________________________________
    *	PRE-CONDITIONS
    *	int[] - array of ints with new coordinates for points
    *
    *	POST-CONDITIONS
    *	Returns nothing. Moves shape on canvas.
    *******************************************************************/
    void move(int[]) override;

    /*!*****************************************************************
    *	@brief Method	perimeter:	Class Ellipse
    *___________________________________________________________________
    *	This virtual method will calculate the perimeter of an ellipse.
    *___________________________________________________________________
    *	PRE-CONDITIONS
    *	<none>
    *
    *	POST-CONDITIONS
    *	Returns integer perimeter of ellipse.
    @return Returns integer perimeter of ellipse.
    *******************************************************************/
    int perimeter() override;

    /*!*****************************************************************
    *	@brief Method	area:	Class Ellipse
    *___________________________________________________________________
    *	This virtual method will calculate the area of a ellipse,
    *   which is always zero.
    *___________________________________________________________________
    *	PRE-CONDITIONS
    *	<none>
    *
    *	POST-CONDITIONS
    *	Returns integer area of ellipse.
    @return	Returns integer area of ellipse.
    *******************************************************************/
    int area() override;
};
#endif //ELLIPSE_H
