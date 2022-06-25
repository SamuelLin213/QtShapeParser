#ifndef CONTACTWINDOW_H
#define CONTACTWINDOW_H

#include <QLabel>
#include <QtGui>
#include <QDialog>
#include <QPushButton>
/*! \file */
class contactWindow: public QDialog
{
    Q_OBJECT
    public:
    /*!*****************************************************************
    *	@brief Constructor	contactWindow:	Class contactWindow
    *___________________________________________________________________
    *	Constructs a fully instantiated object of the contactWindow class.
    *___________________________________________________________________
    *	PRE-CONDITIONS
    *   QDialog* parent
    *
    *	POST-CONDITIONS
    *	This function creates a contactWindow object.
    * @param parent - parent of the dialog
    *******************************************************************/
        explicit contactWindow(QDialog *parent = 0);

    private:
        QLabel *teamLabel;
        QPushButton *okButton;
        QImage *logo;
        QPainter painter;
};

#endif // CONTACTWINDOW_H
