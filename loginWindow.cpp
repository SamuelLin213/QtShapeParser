#include "loginWindow.h"
#include <QMessageBox>

loginWindow::loginWindow(QDialog *parent) :
    QDialog(parent)
{
        this->setWindowTitle(tr("Login"));

        usernameLabel = new QLabel(this);
        usernameLabel->move(50,80);
        usernameLabel->setText("Username:");

        username = new QLineEdit(this);
        username->move(120,80);
        username->setPlaceholderText(tr("Enter user name!"));

        passwordLabel = new QLabel(this);
        passwordLabel->move(50,130);
        passwordLabel->setText("Password:");

        password = new QLineEdit(this);
        password->move(120,130);
        password->setPlaceholderText("Enter password!");
        password->setEchoMode(QLineEdit::Password);

        loginButton = new QPushButton(this);
        loginButton->move(80,200);
        loginButton->setText("Login");

        exitButton = new QPushButton(this);
        exitButton->move(170,200);
        exitButton->setText("Cancel");

        connect(loginButton,&QPushButton::clicked,this,&loginWindow::login);
        connect(exitButton,&QPushButton::clicked,this,&loginWindow::close);


}

void loginWindow::login()
{
    if(username->text().trimmed() == tr("admin") && password->text() == tr("password"))
    {
               accept();
    }
    else
    {
        QMessageBox::warning(this, tr("Error"),tr("Wrong username or password!"),QMessageBox::Ok);

        username->clear();
        password->clear();

        username->setFocus();
    }
}
