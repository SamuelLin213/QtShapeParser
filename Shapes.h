#ifndef SHAPES_H
#define SHAPES_H
/*! \file */
//general includes
#include <iostream>
#include <iomanip>
#include <string>

//for Shape class
#include <Qt>
#include <QPainter>
#include <QPaintDevice>
#include <QPen>

//for Text class
#include <QTextEdit>
#include <QString>
#include <QColor>
#include <QFont>

//for Polyline class
#include <QPoint>

class Shape
{
    public:
      enum ShapeType {LINE, POLYLINE, POLYGON, RECTANGLE, SQUARE, ELLIPSE, TEXT, CIRCLE, NONE};

      //constructors
      /*!*****************************************************************
      *	@brief Constructor	Shape:	Class Shape
      *___________________________________________________________________
      *	Constructs a fully instantiated object of the shape class.
      *___________________________________________________________________
      *	PRE-CONDITIONS
      *   int id - id of the shape
      *   ShapeType type - type of shape
      *
      *	POST-CONDITIONS
      *	This function creates a Shape object of type NONE.
      @param id id of the shape
      @param type type of shape
      *******************************************************************/
      Shape(int id = -1, ShapeType type = NONE);

      /*!*****************************************************************
      *	@brief Constructor	Shape:	Class Shape
      *___________________________________________________________________
      *	Creates the default instance of the shape class.
      *___________________________________________________________________
      *	PRE-CONDITIONS
      *	<none>
      *
      *	POST-CONDITIONS
      *	This function creates a Shape object of type NONE.
      *******************************************************************/
      Shape();

      //destructor
      /*!*****************************************************************
      *	@brief Destructor	~Shape:	Class Shape
      *___________________________________________________________________
      *	Destructs the shape object.
      *___________________________________________________________________
      *	PRE-CONDITIONS
      *	<none>
      *
      *	POST-CONDITIONS
      *	This function destructs the outstanding pointers in Shape.
      *******************************************************************/
      virtual ~Shape() {}

      //pure virtual functions
      /*!*****************************************************************
      *	@brief Method	draw:	Class Shape
      *___________________________________________________________________
      *	This method will draw a shape on the canvas. Returns nothing.
      *___________________________________________________________________
      *	PRE-CONDITIONS
      *	<none>
      *
      *	POST-CONDITIONS
      *	Returns nothing. Draws shape on canvas.
      *******************************************************************/
      virtual void draw(QPainter*) = 0;

      /*!*****************************************************************
      *	@brief Method	move:	Class Shape
      *___________________________________________________________________
      *	This method will move a shape on the canvas. Returns nothing.
      *___________________________________________________________________
      *	PRE-CONDITIONS
      *	int[] - array of integers with new coordinates
      *
      *	POST-CONDITIONS
      *	Returns nothing. Moves shape on canvas.
      @param int[] array of integers with new coordinates
      *******************************************************************/
      virtual void move(int[]) = 0;

      /*!*****************************************************************
      *	@brief Method	perimeter:	Class Shape
      *___________________________________________________________________
      *	This virtual method will calculate the perimeter of a Shape,
      *   which adds up the length of each side.
      *___________________________________________________________________
      *	PRE-CONDITIONS
      *	<none>
      *
      *	POST-CONDITIONS
         @return Returns integer perimeter for Shape
      *******************************************************************/
      virtual int perimeter() = 0;

      /*!*****************************************************************
      *	@brief Method	area:	Class Shape
      *___________________________________________________________________
      *	This virtual method will calculate the area of a Shape,
      *   which multiplies the width by the height.
      *___________________________________________________________________
      *	PRE-CONDITIONS
      *	<none>
      *
      *	POST-CONDITIONS
      *	Returns integer area for Shape
      @return Returns integer area for Shape
      *******************************************************************/
      virtual int area() = 0;

      //overloaded operators
      /*!*****************************************************************
      *	Method	operator == :	Class Shape
      *___________________________________________________________________
      *	This method is an overloaded version of the operator ==; the
      *	purpose of this method is to compare one shape to another to
      *	determine whether they share the same values.
      *___________________________________________________________________
      *	PRE-CONDITIONS
      *	Two shapes
      *
      *	POST-CONDITIONS
      *	bool is returned to represent shape similarity
      @param rhs The other shape
       @return bool is returned to represent shape similarity
      *******************************************************************/
      bool operator==(const Shape& rhs) const;


      /*!*****************************************************************
      *	@brief Method	operator < :	Class Shape
      *___________________________________________________________________
      *	This method is an overloaded version of the operator <; the
      *	purpose of this method is to compare if one shape's id is smaller
      * than the id of the other.
      *___________________________________________________________________
      *	PRE-CONDITIONS
      *	Two shapes
      *
      *	POST-CONDITIONS
      *	bool is returned to represent shape similarity
      @param rhs The other shape
      @return bool is returned to represent shape similarity
      *******************************************************************/
      bool operator<(const Shape& rhs) const;

      //accessors
      /*!*****************************************************************
      *	@brief Method	getPen:	Class Shape
      *___________________________________________________________________
      *	This method will return the QPen address of the calling shape.
      *___________________________________________________________________
      *	PRE-CONDITIONS
      *	<none>
      *
      *	POST-CONDITIONS
      *	Returns const QPen& pen.
      @return Returns const QPen& pen.
      *******************************************************************/
      const QPen& getPen() const;

      /*!*****************************************************************
      *	@brief Method	getBrush:	Class Shape
      *___________________________________________________________________
      *	This method will return the QBrush address of the calling shape.
      *___________________________________________________________________
      *	PRE-CONDITIONS
      *	<none>
      *
      *	POST-CONDITIONS
      *	Returns const QBrush& brush.
      @return Returns const QBrush& brush.
      *******************************************************************/
      const QBrush& getBrush() const;


      /*!*****************************************************************
      *	@brief Method	getShape:	Class Shape
      *___________________________________________________________________
      *	This method will return the ShapeType of the calling shape.
      *___________________________________________________________________
      *	PRE-CONDITIONS
      *	<none>
      *
      *	POST-CONDITIONS
      *	Returns ShapeType type.
      @return Returns ShapeType type.
      *******************************************************************/
      ShapeType getShape() const;

      /*!*****************************************************************
      *	@brief Method	getDimensions:	Class Shape
      *___________________________________________________________________
      *	This method will return the vector of ints which stores the
      * dimensions of the calling shape.
      *___________________________________________________________________
      *	PRE-CONDITIONS
      *	<none>
      *
      *	POST-CONDITIONS
      *	Returns vector<int>& vector.
      @return Returns vector<int>& vector.
      *******************************************************************/
      std::vector<int>& getDimensions();

      /*!*****************************************************************
      *	@brief Method	getPainter:	Class Shape
      *___________________________________________________________________
      *	This method will return the QPainter& of the calling shape.
      *___________________________________________________________________
      *	PRE-CONDITIONS
      *	<none>
      *
      *	POST-CONDITIONS
      *	Returns QPainter& painter.
      @return Returns QPainter& painter.
      *******************************************************************/
      QPainter& getPainter();

      /*!*****************************************************************
       *	@brief Method	getId:	Class Shape
       *___________________________________________________________________
       *	This method will return the int id of the calling shape.
       *___________________________________________________________________
       *	PRE-CONDITIONS
       *	<none>
       *
       *	POST-CONDITIONS
       *	Returns int id.
       @return Returns int id.
       *******************************************************************/
      int getId();

      //mutators
      /*!*****************************************************************
      *	@brief Method	setPen:	Class Shape
      *___________________________________________________________________
      *	This method will set the pen of the calling shape using parameter
      * global color.
      *___________________________________________________________________
      *	PRE-CONDITIONS
      *	Qt::GlobalColor - color of the pen
      *
      *	POST-CONDITIONS
      *	<none>
      @param QtGlobalColor color of the pen
      *******************************************************************/
      void setPen(Qt::GlobalColor);

      /*!*****************************************************************
      *	@brief Method	setBrush:	Class Shape
      *___________________________________________________________________
      *	This method will set the brush of the calling shape using parameter
      * brush style and color.
      *___________________________________________________________________
      *	PRE-CONDITIONS
      *	Qt::GlobalColor - color of the brush
      * Qt::BrushStyle - style of the brush
      *
      *	POST-CONDITIONS
      *	<none>
      @param QtGlobalColor color of the brush
      @param QtBrushStyle style of the brush
      *******************************************************************/
      void setBrush(Qt::GlobalColor, Qt::BrushStyle);

      /*!*****************************************************************
      *	@brief Method	setShape:	Class Shape
      *___________________________________________________________________
      *	This method will set the type of shape using the parameter ShapeType
      *___________________________________________________________________
      *	PRE-CONDITIONS
      *	ShapeType shape - type of shape
      *
      *	POST-CONDITIONS
      *	<none>
      @param shape type of shape
      *******************************************************************/
      void setShape(ShapeType shape);

      //shape properties mutators
      /*!*****************************************************************
      *	@brief Method	addDimension:	Class Shape
      *___________________________________________________________________
      *	This method will add another dimension to the dimensions vector.
      * Returns nothing.
      *___________________________________________________________________
      *	PRE-CONDITIONS
      *	int dim - new dimension to be added
      *
      *	POST-CONDITIONS
      *	<none>
      @param dim new dimension to be added
      *******************************************************************/
      void addDimension(int dim);

      /*!*****************************************************************
      *	@brief Method	setColor:	Class Shape
      *___________________________________________________________________
      *	This method will set the color of the shape.
      * Returns nothing.
      *___________________________________________________________________
      *	PRE-CONDITIONS
      *	QColor color - new color
      *
      *	POST-CONDITIONS
      *	<none>
      @param color new color
      *******************************************************************/
      void setColor(const QColor color);

      /*!*****************************************************************
      *	@brief Method	setWidth:	Class Shape
      *___________________________________________________________________
      *	This method will set the width of the shape.
      * Returns nothing.
      *___________________________________________________________________
      *	PRE-CONDITIONS
      *	int width - new width
      *
      *	POST-CONDITIONS
      *	<none>
      @param width new width
      *******************************************************************/
      void setWidth(int width);


      /*!*****************************************************************
      *	@brief Method	setStyle:	Class Shape
      *___________________________________________________________________
      *	This method will set the pen style of the shape.
      * Returns nothing.
      *___________________________________________________________________
      *	PRE-CONDITIONS
      *	Qt::PenStyle style - new pen style
      *
      *	POST-CONDITIONS
      *	<none>
      @param style new pen style
      *******************************************************************/
      void setStyle(Qt::PenStyle style);

      /*!*****************************************************************
      *	@brief Method	setCapStyle:	Class Shape
      *___________________________________________________________________
      *	This method will set the cap style of the pen.
      * Returns nothing.
      *___________________________________________________________________
      *	PRE-CONDITIONS
      *	Qt::PenCapStyle capStyle - new pen cap style
      *
      *	POST-CONDITIONS
      *	<none>
      @param capStyle new pen cap style
      *******************************************************************/
      void setCapStyle(Qt::PenCapStyle capStyle);

      /*!*****************************************************************
      *	@brief Method	setJoinStyle:	Class Shape
      *___________________________________________________________________
      *	This method will set the join style of the pen.
      * Returns nothing.
      *___________________________________________________________________
      *	PRE-CONDITIONS
      *	Qt::PenJoinStyle style - new pen join style
      *
      *	POST-CONDITIONS
      *	<none>
      @param style new pen join style
      *******************************************************************/
      void setJoinStyle(Qt::PenJoinStyle style);

      /*!*****************************************************************
      *	@brief Method	setBrushColor:	Class Shape
      *___________________________________________________________________
      *	This method will set the brush color.
      * Returns nothing.
      *___________________________________________________________________
      *	PRE-CONDITIONS
      *	QColor color - new color
      *
      *	POST-CONDITIONS
      *	<none>
      *******************************************************************/
      void setBrushColor(QColor color);

      /*!*****************************************************************
      *	@brief Method	setBrushStyle:	Class Shape
      *___________________________________________________________________
      *	This method will set the brush style.
      * Returns nothing.
      *___________________________________________________________________
      *	PRE-CONDITIONS
      *	Qt::BrushStyle style - new style
      *
      *	POST-CONDITIONS
      *	<none>
      @param style - new style
      *******************************************************************/
      void setBrushStyle(Qt::BrushStyle style);

      //disabling copy constructor and copy assignment operator
      Shape(const Shape &s) = delete;
      Shape& operator=(const Shape &s) = delete;

    private:
       /* The qpainter for the shape */
      QPainter qpainter;
         /* the shape id*/
      int id;
       /*the shape type*/
      ShapeType shape;
      /* the pen for the shape */
      QPen pen;
      /* the brush for the shape */
      QBrush brush;
            /* vector of ints for the dimensions */
      std::vector<int> dimensions; //vector of ints
            /* the index */
      int index {0}; //defaults to 0
};

#endif // SHAPES_H
