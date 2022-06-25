#include "mainwindow.h"
//#include "ui_mainwindow.h"
#include "testimonialWindow.h"
#include <QtWidgets>
#include "canvas.h"

int MainWindow::checkId(int id_)
{
    for(int i = 0; i < (int)(renderArea->shapeList.size()); i++)
    {
        if(renderArea->shapeList[i]->getId() == id_)
        {

            return i;
        }
    }
    QMessageBox::information(
        this,
        tr("Error: Invalid ID"),
        tr("The shape id inputted was not found. Please enter a valid ID.") );

    return -1;
}

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{

    setFixedSize(1200, 500);
    renderArea = new canvas;

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(renderArea, 0, 0, 16, 10);
    setLayout(mainLayout);

    buttonMove = new QPushButton(QString::fromStdString("Move shape"));
    buttonMove->setEnabled(false);
    mainLayout->addWidget(buttonMove, 10, 11, 1, 1);

    buttonRemove = new QPushButton(QString::fromStdString("Remove shape"));
    buttonRemove->setEnabled(false);
    mainLayout->addWidget(buttonRemove, 11, 11, 1, 1);

    buttonContact = new QPushButton(QString::fromStdString("Contact us"));
    buttonContact->setEnabled(true);
    mainLayout->addWidget(buttonContact, 14, 11, 1, 1);
    connect(buttonContact, &QPushButton::pressed, this, &MainWindow::contactUs);

    buttonTestimonial = new QPushButton(QString::fromStdString("Make a testimonial!"));
    buttonTestimonial->setEnabled(true);
    mainLayout->addWidget(buttonTestimonial, 13, 11, 1, 1);
    connect(buttonTestimonial, &QPushButton::pressed, this, &MainWindow::testimonal);

    buttonLine = new QPushButton(QString::fromStdString("Draw Line"));
    buttonLine->setEnabled(false);
    mainLayout->addWidget(buttonLine, 0, 11, 1, 1);

    buttonPolyline = new QPushButton(QString::fromStdString("Draw Polyline"));
    buttonPolyline->setEnabled(false);
    mainLayout->addWidget(buttonPolyline, 1, 11, 1, 1);

    buttonPolygon = new QPushButton(QString::fromStdString("Draw Polygon"));
    buttonPolygon->setEnabled(false);
    mainLayout->addWidget(buttonPolygon, 2, 11, 1, 1);

    buttonRectangle = new QPushButton(QString::fromStdString("Draw Rectangle"));
    buttonRectangle->setEnabled(false);
    mainLayout->addWidget(buttonRectangle, 3, 11, 1, 1);

    buttonSquare = new QPushButton(QString::fromStdString("Draw Square"));
    buttonSquare->setEnabled(false);
    mainLayout->addWidget(buttonSquare, 4, 11, 1, 1);

    buttonEllipse = new QPushButton(QString::fromStdString("Draw Ellipse"));
    buttonEllipse->setEnabled(false);
    mainLayout->addWidget(buttonEllipse, 5, 11, 1, 1);

    buttonCircle = new QPushButton(QString::fromStdString("Draw Circle"));
    buttonCircle->setEnabled(false);
    mainLayout->addWidget(buttonCircle, 6, 11, 1, 1);

    buttonText = new QPushButton(QString::fromStdString("Draw Text"));
    buttonText->setEnabled(false);
    mainLayout->addWidget(buttonText, 7, 11, 1, 1);

    buttonLogin = new QPushButton(QString::fromStdString("Login"));
    connect(buttonLogin, &QPushButton::pressed, this, &MainWindow::login);
    mainLayout->addWidget(buttonLogin, 15, 11, 1, 1);

}
void MainWindow::drawLine()
{
    renderArea->drawLine();
}
void MainWindow::drawPolyline()
{
    renderArea->drawPolyline();
}
void MainWindow::drawPolygon()
{
    renderArea->drawPolygon();
}
void MainWindow::drawRectangle()
{
    renderArea->drawRectangle();
}
void MainWindow::drawSquare()
{
    renderArea->drawSquare();
}
void MainWindow::drawEllipse()
{
    renderArea->drawEllipse();
}
void MainWindow::drawCircle()
{
    renderArea->drawCircle();
}
void MainWindow::drawText()
{
    renderArea->drawText();
}
void MainWindow::contactUs()
{
    contactWindow contactW;
    contactW.exec();
}
void MainWindow::testimonal()
{
    testimonialWindow testimonialW;
    testimonialW.exec();
}
void MainWindow::move()
{
    // Stores button value
    bool ok;
    int index = 0;
    int points = 1;
    std::vector<int> coords;

    int changeId = QInputDialog::getInt(this, tr("Move"),
                                        tr("Select id of shape:"),
                                        1, 1, 50, 1, &ok);
    if(!ok)
        return;

    index = checkId(changeId);

    if(index != -1)
    {
        if(renderArea->shapeList[index]->getShape() == Shape::LINE)
        {
                points = 2;
        }
        else if(renderArea->shapeList[index]->getShape() == Shape::POLYLINE || renderArea->shapeList[index]->getShape() == Shape::POLYGON)
        {
            points = QInputDialog::getInt(this, tr("Points"),
                                       tr("Number of points to move(default 1):"),
                                       1, 1, 50, 1, &ok);
            if(!ok)
                return;
        }

        for(int i = 1; i <= points; i++)
        {
            int newX = QInputDialog::getInt(this, tr("New Coordinates"),
                                                 tr("New X:"),
                                                 0, 0, 850, 1, &ok);
            if(!ok)
                return;
            int newY = QInputDialog::getInt(this, tr("New Coordinates"),
                                            tr("New Y:"),
                                            0, 0, 475, 1, &ok);
            if(!ok)
                return;
            coords.push_back(newX);
            coords.push_back(newY);
        }

        //loops through vector and assigns dimensions to int array
        int size = coords.size();
        int coordAr[size];
        for(int index = 0; index < size; index++)
        {
            coordAr[index] = coords[index];
        }

        //applies new coords
        renderArea->shapeList[index]->move(coordAr);

        renderArea->moveShape();
    }
}
void MainWindow::remove()
{
      //Stores button value
      bool ok;

      int selectId = QInputDialog::getInt(this, tr("Delete"),
                                            tr("Select id of shape:"),
                                            1, 1, 50, 1, &ok);
      if(!ok)
          return;

      int ind = checkId(selectId);
      if(ind != -1)
      {
          renderArea->shapeList.erase(renderArea->shapeList.begin() + ind);
          renderArea->removeShape();
      }
}
void MainWindow::login()
{
    loginWindow loginW;
    if(loginW.exec() == QDialog::Accepted)
    {
        buttonLine->setEnabled(true);
        connect(buttonLine, &QPushButton::pressed,
                this, &MainWindow::drawLine);

        buttonPolygon->setEnabled(true);
        connect(buttonPolygon, &QPushButton::pressed,
                this, &MainWindow::drawPolygon);

        buttonPolyline->setEnabled(true);
        connect(buttonPolyline, &QPushButton::pressed,
                this, &MainWindow::drawPolyline);

        buttonRectangle->setEnabled(true);
        connect(buttonRectangle, &QPushButton::pressed,
                this, &MainWindow::drawRectangle);

        buttonSquare->setEnabled(true);
        connect(buttonSquare, &QPushButton::pressed,
                this, &MainWindow::drawSquare);

        buttonEllipse->setEnabled(true);
        connect(buttonEllipse, &QPushButton::pressed,
                this, &MainWindow::drawEllipse);

        buttonCircle->setEnabled(true);
        connect(buttonCircle, &QPushButton::pressed,
                this, &MainWindow::drawCircle);

        buttonText->setEnabled(true);
        connect(buttonText, &QPushButton::pressed,
                this, &MainWindow::drawText);

        buttonMove->setEnabled(true);
        connect(buttonMove, &QPushButton::pressed, this, &MainWindow::move);

        buttonRemove->setEnabled(true);
        connect(buttonRemove, &QPushButton::pressed, this, &MainWindow::remove);
    }
}


MainWindow::~MainWindow()
{
    //delete ui;
}

