#ifndef LINE_H
#define LINE_H

/*! \file */
#include "Shapes.h"
#include <QLine>

class Line: public Shape
{
  public:
    /*!*****************************************************************
    *	@brief Constructor	Line:	Class Line
    *___________________________________________________________________
    *	Constructs a fully instantiated object of the Line class.
    *___________________________________________________________________
    *	PRE-CONDITIONS
    *   int id - id of the shape
    *   ShapeType type - type of shape
    *
    *	POST-CONDITIONS
    *	This function creates a Line object of type LINE.
    * @param id - id of the shape
    * @param type - type of shape
    *******************************************************************/
    Line(int id = -1, ShapeType type = NONE);

    /*!*****************************************************************
    *	@brief Constructor	Line:	Class Line
    *___________________________________________________________________
    *	Creates the default instance of the line class.
    *___________________________________________________________________
    *	PRE-CONDITIONS
    *	<none>
    *
    *	POST-CONDITIONS
    *	This function creates a Line object of type LINE.
    *******************************************************************/
    Line();

    /*!*****************************************************************
    *	@brief Destructor	~Line:	Class Line
    *___________________________________________________________________
    *	Destructs the line object.
    *___________________________________________________________________
    *	PRE-CONDITIONS
    *	<none>
    *
    *	POST-CONDITIONS
    *	This function destructs the outstanding pointers in line.
    *******************************************************************/
    ~Line() {}

    //Accessors
    /*!*****************************************************************
    *	@brief Method	GetLine:	Class Line
    *___________________________________________________________________
    *	This method will return the address of a QLine line.
    *___________________________________________________________________
    *	PRE-CONDITIONS
    *	<none>
    *
    *	POST-CONDITIONS
    *	Returns QLine& of a line.
      @return Returns QLine& of a line.
    *******************************************************************/
    QLine& GetLine();

    //Mutators
    /*!*****************************************************************
    *	@brief Method	setLine:	Class Line
    *___________________________________________________________________
    *	This method will set the line using the points saved privately
    *   in Line.
    *___________________________________________________________________
    *	PRE-CONDITIONS
    *	<none>
    *
    *	POST-CONDITIONS
    *	Returns nothing.
    *******************************************************************/
    void setLine();

    /*!*****************************************************************
    *	@brief Method	draw:	Class Line
    *___________________________________________________________________
    *	This method will draw a line using the QLine line
    *   stored in Line.
    *___________________________________________________________________
    *	PRE-CONDITIONS
    *	<none>
    *
    *	POST-CONDITIONS
    *	Returns nothing. Draws shape on canvas.
    *******************************************************************/
    void draw(QPainter* shape) override;

    /*!*****************************************************************
    *	@brief Method	move:	Class Line
    *___________________________________________________________________
    *	This method will move a line using the integer array passed
    *   as a parameter to update the existing dimensions of the line.
    *___________________________________________________________________
    *	PRE-CONDITIONS
    *	int[] - array of ints with new coordinates for points
    *
    *	POST-CONDITIONS
    *	Returns nothing. Moves shape on canvas.
    @param int[] array of ints with new coordinates for points
    *******************************************************************/
    void move(int[]) override;

    /*!*****************************************************************
    *	@brief Method	area:	Class Line
    *___________________________________________________________________
    *	This virtual method will calculate the area of a line,
    *   which is always zero.
    *___________________________________________________________________
    *	PRE-CONDITIONS
    *	<none>
    *
    *	POST-CONDITIONS
    *	Returns integer area(always 0 for Line)
    @return Returns integer area(always 0 for Line)
    *******************************************************************/
    int area() override { return 0;}

    /*!*****************************************************************
    *	@brief Method	perimeter:	Class Line
    *___________________________________________________________________
    *	This virtual method will calculate the perimeter of a line,
    *   which is always zero.
    *___________________________________________________________________
    *	PRE-CONDITIONS
    *	<none>
    *
    *	POST-CONDITIONS
    *	Returns integer perimeter(always 0 for Line)
     @return Returns integer perimeter(always 0 for Line)
    *******************************************************************/
    int perimeter() override { return 0; }

  private:
     /*! the line object */
    QLine line;
        /* the beginning point of the line */
    QPoint beginPoint;
        /* the end point of the line */
    QPoint endPoint;
};

#endif // LINE_H
