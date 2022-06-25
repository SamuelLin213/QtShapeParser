#ifndef POLYGON_H
#define POLYGON_H

/*! \file */
#include "Shapes.h"

class Polygon: public Shape
{
  public:
    /*!*****************************************************************
      *	@brief Constructor	Polygon:	Class Polygon
      *___________________________________________________________________
      *	Constructs a fully instantiated object of the polygon class.
      *___________________________________________________________________
      *	PRE-CONDITIONS
      *   int id - id of the shape
      *   ShapeType type - type of shape
      *
      *	POST-CONDITIONS
      *	This function creates a Polygon object of type POLYGON.

      * @param id - id of the shape
      * @param type - type of shape
      *******************************************************************/
    Polygon(int id = -1, ShapeType type = NONE);

    /*!*****************************************************************
    *	@brief	Destructor	~Polygon:	Class Polygon
    *___________________________________________________________________
    *	Destructs the polygon object.
    *___________________________________________________________________
    *	PRE-CONDITIONS
    *	<none>
    *
    *	POST-CONDITIONS
    *	This function destructs the outstanding pointers in polygon.
    *******************************************************************/
    ~Polygon() {};

    /*!*****************************************************************
    *	@brief Method	draw:	Class Polygon
    *___________________________________________________________________
    *	This virtual method will draw a polygon on the canvas.
    *   Returns nothing.
    *___________________________________________________________________
    *	PRE-CONDITIONS
    *	<none>
    *
    *	POST-CONDITIONS
    *	<none>
    *******************************************************************/
    void draw(QPainter* shape) override;


    /*!*****************************************************************
    *	@brief Method	move:	Class Polygon
    *___________________________________________________________________
    *	This virtual method will move a polygon on the canvas.
    *   Returns nothing.
    *___________________________________________________________________
    *	PRE-CONDITIONS
    *	int[] - array of integers holding coordinates
    *
    *	POST-CONDITIONS
    *	<none>
      @param int[] array of integers holding coordinates
    *******************************************************************/
    void move(int[]) override;

    /*!*****************************************************************
    *	@brief Method	perimeter:	Class Polygon
    *___________________________________________________________________
    *	This virtual method will calculate the perimeter of a polygon and
    *   return the perimeter as an integer.
    *___________________________________________________________________
    *	PRE-CONDITIONS
    *	<none>
    *
    *	POST-CONDITIONS
    *	Returns integer perimeter of Polygon
      @return integer perimeter of Polygon
    *******************************************************************/
    int perimeter() override;


    /*!*****************************************************************
    *	@brief Method	area:	Class Polygon
    *___________________________________________________________________
    *	This virtual method will calculate the area of a polygon and
    *   return the area as an integer.
    *___________________________________________________________________
    *	PRE-CONDITIONS
    *	<none>
    *
    *	POST-CONDITIONS
    *	Returns integer area of Polygon
      @return integer area of Polygon
    *******************************************************************/
    int area() override;
};

#endif // POLYGON_H
