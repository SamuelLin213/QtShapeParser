#ifndef MAINWINDOW_H
#define MAINWINDOW_H
/*! \file */
#include <QWidget>
#include <QPushButton>
#include "loginWindow.h"
#include "contactWindow.h"
#include "testimonialWindow.h"
#include "Shapes.h"
#include "Line.h"
#include "Polyline.h"
#include "Polygon.h"
#include "Rectangle.h"
#include "Ellipse.h"
#include "Text.h"
#include <vector>

class canvas;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    /*!*****************************************************************
    *	@brief Constructor	MainWindow:	Class MainWindow
    *___________________________________________________________________
    *	Constructs a fully instantiated object of the MainWindow class.
    *___________________________________________________________________
    *	PRE-CONDITIONS
    *   QWidget* parent
    *
    *	POST-CONDITIONS
    *	This function creates a MainWindow object.
    * @param parent - parent of the widget
    *******************************************************************/
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    /*!*****************************************************************
    *	@brief Method	drawLine:	Class mainwindow
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
    *	@brief Method	drawPolyline:	Class mainwindow
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
    *	@brief Method	drawPolygon:	Class mainwindow
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
    *	@brief Method	drawRectangle:	Class mainwindow
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
    *	@brief Method	drawSquare:	Class mainwindow
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
    *	@brief Method	drawEllipse:	Class mainwindow
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
    *	@brief Method	drawCircle:	Class mainwindow
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
    *	@brief Method	drawText:	Class mainwindow
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
    *	@brief Method	login:	Class mainwindow
    *___________________________________________________________________
    *	This method will allow the user to log in
    *___________________________________________________________________
    *	PRE-CONDITIONS
    *	<none>
    *
    *	POST-CONDITIONS
    *	<none>
    *******************************************************************/
    void login();

    /*!*****************************************************************
    *	@brief Method	contactUs:	Class mainwindow
    *___________________________________________________________________
    *	This method will allow the user to view team contact info
    *___________________________________________________________________
    *	PRE-CONDITIONS
    *	<none>
    *
    *	POST-CONDITIONS
    *	<none>
    *******************************************************************/
    void contactUs();

    /*!*****************************************************************
    *	@brief Method	testimonial:	Class mainwindow
    *___________________________________________________________________
    *	This method will allow the user to leave a testimonial
    *___________________________________________________________________
    *	PRE-CONDITIONS
    *	<none>
    *
    *	POST-CONDITIONS
    *	<none>
    *******************************************************************/
    void testimonal();

    /*!*****************************************************************
    *	@brief Method	move:	Class mainwindow
    *___________________________________________________________________
    *	This method will allow the user to move the shape
    *___________________________________________________________________
    *	PRE-CONDITIONS
    *	<none>
    *
    *	POST-CONDITIONS
    *	<none>
    *******************************************************************/
    void move();

    /*!*****************************************************************
    *	@brief Method	remove:	Class mainwindow
    *___________________________________________________________________
    *	This method will allow the user to remove the shape
    *___________________________________________________________________
    *	PRE-CONDITIONS
    *	<none>
    *
    *	POST-CONDITIONS
    *	<none>
    *******************************************************************/
    void remove();

    //checks whether inputted id is valid
    int checkId(int id_);

private:
    canvas *renderArea;
    QPushButton *buttonContact;
    QPushButton *buttonTestimonial;
    QPushButton *buttonLine;
    QPushButton *buttonPolyline;
    QPushButton *buttonPolygon;
    QPushButton *buttonRectangle;
    QPushButton *buttonSquare;
    QPushButton *buttonEllipse;
    QPushButton *buttonCircle;
    QPushButton *buttonText;
    QPushButton *buttonLogin;
    QPushButton *buttonMove;
    QPushButton *buttonRemove;
};
#endif // MAINWINDOW_H
