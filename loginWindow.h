#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H
/*! \file */
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>


class loginWindow : public QDialog
{
         Q_OBJECT
public:
    /*!*****************************************************************
    *	@brief Constructor	loginWindow:	Class loginWindow
    *___________________________________________________________________
    *	Constructs a fully instantiated object of the loginWindow class.
    *___________________________________________________________________
    *	PRE-CONDITIONS
    *   QDialog* parent
    *
    *	POST-CONDITIONS
    *	This function creates a loginWindow object.
    * @param parent - parent of the dialog
    *******************************************************************/
         explicit loginWindow(QDialog *parent = 0);

public slots:
    /*!*****************************************************************
    *	@brief Method	login:	Class loginWindow
    *___________________________________________________________________
    *	This method will allow the user to log in as an admin.
    *___________________________________________________________________
    *	PRE-CONDITIONS
    *	<none>
    *
    *	POST-CONDITIONS
    *	Returns nothing.
    *******************************************************************/
         void login();
private:
         QLabel *usernameLabel;
         QLabel *passwordLabel;
         QLineEdit *username;
         QLineEdit *password;
         QPushButton *loginButton;
         QPushButton *exitButton;
};

#endif
