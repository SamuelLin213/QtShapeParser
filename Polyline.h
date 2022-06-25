#ifndef POLYLINE_H
#define POLYLINE_H

/*! \file */
#include "Shapes.h"

class Polyline: public Shape
{
  public:


    /*!*****************************************************************
    *	@brief Constructor	Polyline:	Class Polyline
    *___________________________________________________________________
    *	Constructs a fully instantiated object of the polyline class.
    *___________________________________________________________________
    *	PRE-CONDITIONS
    *   int id - id of the shape
    *   ShapeType type - type of shape
    *
    *	POST-CONDITIONS
    *	This function creates a Polyline object of type POLYLINE.
    *
    * @param id - id of the shape
    * @param type - type of shape
    *******************************************************************/
    Polyline(int id = -1, ShapeType type = NONE);

    /*!*****************************************************************
    *	@brief Constructor	Polyline:	Class Polyline
    *___________________________________________________________________
    *	Creates the default instance of the polyline class.
    *___________________________________________________________________
    *	PRE-CONDITIONS
    *	<none>
    *
    *	POST-CONDITIONS
    *	This function creates a Polyline object of type POLYLINE.
    *******************************************************************/
    Polyline();


    /*!*****************************************************************
    *	@brief Destructor	~Polyline:	Class Polyline
    *___________________________________________________________________
    *	Destructs the polyline object.
    *___________________________________________________________________
    *	PRE-CONDITIONS
    *	<none>
    *
    *	POST-CONDITIONS
    *	This function destructs the outstanding pointers in polyline.
    *******************************************************************/
    ~Polyline() {}

    /*!*****************************************************************
     *	@brief Method	draw:	Class Polyline
     *___________________________________________________________________
     *	This method will draw a polyline using the QPoint pointer
     *   stored in Polyline.
     *___________________________________________________________________
     *	PRE-CONDITIONS
     *	<none>
     *
     *	POST-CONDITIONS
     *	Returns nothing. Draws shape on canvas.
     *******************************************************************/
    void draw(QPainter* shape) override;


    /*!*****************************************************************
    *	@brief Method	move:	Class Polyline
    *___________________________________________________________________
    *	This method will move a polyline using the integer array passed
    *   as a parameter to update the existing dimensions of the Polyline.
    *___________________________________________________________________
    *	PRE-CONDITIONS
    *	int[] - array of ints with new coordinates
    *
    *	POST-CONDITIONS
    *	Returns nothing. Moves shape on canvas.
      @param int[] array of ints with new coordinates
    *******************************************************************/
    void move(int[]) override;

    /*!*****************************************************************
    *	@brief Method	perimeter:	Class Polyline
    *___________________________________________________________________
    *	This virtual method will calculate the perimeter of a polyline,
    *   which is always zero unless it wraps around to create another
    *   shape.
    *___________________________________________________________________
    *	PRE-CONDITIONS
    *	<none>
    *
    *	POST-CONDITIONS
    *	Returns integer perimeter(always 0 for Polyline)
      @return integer perimeter(always 0 for Polyline)
    *******************************************************************/
    int perimeter() override { return 0;}

    /*!*****************************************************************
    *	@brief Method	area:	Class Polyline
    *___________________________________________________________________
    *	This virtual method will calculate the area of a polyline,
    *   which is always zero unless it wraps around to create another
    *   shape.
    *___________________________________________________________________
    *	PRE-CONDITIONS
    *	<none>
    *
    *	POST-CONDITIONS
    *	Returns integer area(always 0 for Polyline)
      @return integer area(always 0 for Polyline)
    *******************************************************************/
    int area() override { return 0; }

  private:
    /* the points in the polyline */
    QPoint* points;
    /* the amount of points in the polyline */
    int pointCount;

};
#endif //POLYLINE_H
