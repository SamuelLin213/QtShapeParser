#ifndef TESTIMONIALWINDOW_H
#define TESTIMONIALWINDOW_H
/*! \file */
#include <QLabel>
#include <QtGui>
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <iostream>
#include <fstream>
using std::getline;
using std::string;
using std::cin;
using std::cout;
using std::ifstream;
using std::ofstream;
using std::remove;

class testimonialWindow: public QDialog
{
    Q_OBJECT
    public:
    /*!*****************************************************************
    *	@brief Constructor	testimonialWindow:	Class testimonialWindow
    *___________________________________________________________________
    *	Constructs a fully instantiated object of the testimonialWindow class.
    *___________________________________________________________________
    *	PRE-CONDITIONS
    *   QDialog* parent
    *
    *	POST-CONDITIONS
    *	This function creates a testimonialWindow object.
    * @param parent - parent of the dialog
    *******************************************************************/
        explicit testimonialWindow(QDialog *parent = 0);

    struct Testimony{
       private:
       /*! the author */
       string author;
       /*! the email address */
       string description;
       public:
       /*! @brief Default constructor
          initializes the testimony object
          preconditions: none
          postconditions: initializes everything to empty

       */
       Testimony():author(""),description(""){}
          /*! @brief Overloaded constructor
          initializes the testimony object
          preconditions: string author, string email, string description
          postconditions: initializes everything to empty

          @param authors the author
          @param emails the email address
          @param descriptions the testimony description
       */
       Testimony(string authors,string descriptions):author(authors),description(descriptions){}
       /*! @brief access the author
          @return The author of the testimony
       */
       string getAuthor(){return author;}
        /*! @brief access the description of the testimony

          @return The description of the testimony
       */
       string getDescription(){return description;}
        /*! @brief prints the testimony

          @return All the data in the testimony object as a string
       */
       string print(){return author + " " +description + "\n";}

    };

     /*! @brief Loads a user testimony
         Passed the input file stream object so it can read from the testimonies.txt file
         and the author.
         Reads in the remaining line information needed from the file
         and returns the description.
         @param author The testimony's author's email
         @return a string containing the description of the testimony
     */
      Testimony LoadTestimony(string name);

    public slots:
      /*!*****************************************************************
      *	@brief Method	submit:	Class testimonialWindow
      *___________________________________________________________________
      *	This method will allow the user to submit a testimonial.
      *___________________________________________________________________
      *	PRE-CONDITIONS
      *	<none>
      *
      *	POST-CONDITIONS
      *	Returns nothing.
      *******************************************************************/
         void submit();

        bool writeFile();

    private:
    QLabel *nameLabel;
    QLineEdit *name;
    string author;
    QPushButton *submitButton;
    QPushButton *cancelButton;
    QLabel *messageLabel;
    QLineEdit *message;
    string description;
    QPainter painter;
};

#endif // TESTIMONIALWINDOW_H
