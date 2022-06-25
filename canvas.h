#ifndef CANVAS_H
#define CANVAS_H
/*! \file */
#include <QMainWindow>
#include <QtGui>
#include <QList>
#include <QObject>
#include <QtCore>
#include <QWidget>
#include "Shapes.h"

class canvas : public QWidget
{
    Q_OBJECT

public:
    /*!*****************************************************************
    *	@brief Constructor	canvas:	Class canvas
    *___________________________________________________________________
    *	Constructs a fully instantiated object of the canvas class.
    *___________________________________________________________________
    *	PRE-CONDITIONS
    *   QWidget* parent
    *
    *	POST-CONDITIONS
    *	This function creates a canvas object.
    * @param parent - parent of the widget
    *******************************************************************/
    explicit canvas(QWidget *parent = nullptr);

    /*!*****************************************************************
    *	@brief Method	drawLine:	Class canvas
    *___________________________________________________________________
    *	This method will draw a line
    *___________________________________________________________________
    *	PRE-CONDITIONS
    *	<none>
    *
    *	POST-CONDITIONS
    *	<none>
    *******************************************************************/
    void drawLine();

    /*!*****************************************************************
    *	@brief Method	drawPolyline:	Class canvas
    *___________________________________________________________________
    *	This method will draw a polyline
    *___________________________________________________________________
    *	PRE-CONDITIONS
    *	<none>
    *
    *	POST-CONDITIONS
    *	<none>
    *******************************************************************/
    void drawPolyline();

    /*!*****************************************************************
    *	@brief Method	drawPolygon:	Class canvas
    *___________________________________________________________________
    *	This method will draw a polygon
    *___________________________________________________________________
    *	PRE-CONDITIONS
    *	<none>
    *
    *	POST-CONDITIONS
    *	<none>
    *******************************************************************/
    void drawPolygon();

    /*!*****************************************************************
    *	@brief Method	drawRectangle:	Class canvas
    *___________________________________________________________________
    *	This method will draw a rectangle
    *___________________________________________________________________
    *	PRE-CONDITIONS
    *	<none>
    *
    *	POST-CONDITIONS
    *	<none>
    *******************************************************************/
    void drawRectangle();

    /*!*****************************************************************
    *	@brief Method	drawSquare:	Class canvas
    *___________________________________________________________________
    *	This method will draw a square
    *___________________________________________________________________
    *	PRE-CONDITIONS
    *	<none>
    *
    *	POST-CONDITIONS
    *	<none>
    *******************************************************************/
    void drawSquare();

    /*!*****************************************************************
    *	@brief Method	drawEllipse:	Class canvas
    *___________________________________________________________________
    *	This method will draw an ellipse
    *___________________________________________________________________
    *	PRE-CONDITIONS
    *	<none>
    *
    *	POST-CONDITIONS
    *	<none>
    *******************************************************************/
    void drawEllipse();

    /*!*****************************************************************
    *	@brief Method	drawCircle:	Class canvas
    *___________________________________________________________________
    *	This method will draw a circle
    *___________________________________________________________________
    *	PRE-CONDITIONS
    *	<none>
    *
    *	POST-CONDITIONS
    *	<none>
    *******************************************************************/
    void drawCircle();

    /*!*****************************************************************
    *	@brief Method	drawText:	Class canvas
    *___________________________________________________________________
    *	This method will draw a text
    *___________________________________________________________________
    *	PRE-CONDITIONS
    *	<none>
    *
    *	POST-CONDITIONS
    *	<none>
    *******************************************************************/
    void drawText();

    /*!*****************************************************************
    *	@brief Method	moveShape:	Class canvas
    *___________________________________________________________________
    *	This method will allow the user to move the shape
    *___________________________________________________________________
    *	PRE-CONDITIONS
    *	<none>
    *
    *	POST-CONDITIONS
    *	<none>
    *******************************************************************/
    void moveShape();

    /*!*****************************************************************
    *	@brief Method	removeShape:	Class canvas
    *___________________________________________________________________
    *	This method will allow the user to remove the shape
    *___________________________________________________________________
    *	PRE-CONDITIONS
    *	<none>
    *
    *	POST-CONDITIONS
    *	<none>
    *******************************************************************/
    void removeShape();

    /*!*****************************************************************
    *	@brief Method	addShape:	Class canvas
    *___________________________________________________________________
    *	This method will allow the user to add a shape to the canvas
    *___________________________________________________________________
    *	PRE-CONDITIONS
    *	<none>
    *
    *	POST-CONDITIONS
    *	<none>
    *******************************************************************/
    void addShape();

    /*!*****************************************************************
    *	@brief Method	getPainter:	Class canvas
    *___________________________________________________________________
    *	This method will return the QPainter*
    *___________________________________________________________________
    *	PRE-CONDITIONS
    *	<none>
    *
    *	POST-CONDITIONS
    *	<none>
    *******************************************************************/
    QPainter* getPainter();

    //checks whether inputted id is valid
    int checkId(int id_);

    //myVector<Shape*> shapeList;
    std::vector<Shape*> shapeList;
protected:
    // Function used to close an event
    void paintEvent(QPaintEvent *e) override;
    QPainter *painter;

    QVector<QPoint> points;
    QVector<QPoint> points2;
};

#endif // CANVAS_H
