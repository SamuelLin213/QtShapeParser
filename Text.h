#ifndef TEXT_H
#define TEXT_H

/*! \file */
#include "Shapes.h"
//using namespace std;

class Text: public Shape
{
  public:
    /*! @brief overloaded constructor
         Passes in shape, id, and type and instantiates a text
         @param id The id
         @param type the shape type
     */
    Text(int id = -1, ShapeType type = NONE);
    /*! @brief default constructor
        Instantiates a text
    */
    Text();
    /*! @brief destructor
      destroys the object
   */
    ~Text();

    /*! @brief draws the text
        */
    void draw(QPainter* shape) override;
    /*! @brief moves the text
    @param int[] indicates how much the text should move
  */
    void move(int[]) override;
    /*! @brief returns the perimeter of the object
          @return the perimeter of the object
       */
    int perimeter() override { return 0; }
    /*! @brief returns the area of the object
          @return the area of the object
       */
    int area() override { return 0; }

    /*! @brief Sets the text
        @param Text The QString object that the text needs to be set to
       */
    void setText(const QString &Text);
    /*! @brief Sets the text color
        @param c The QColor object that the color needs to be set to
       */
    void setTColor(const QColor &c);
    /*! @brief Sets the allignment
        @param a The QT Allignment object that the allignment needs to be set to
       */
    void setAlignment(Qt::Alignment a);
    /*! @brief Sets the point size
         @param s The point size to set to
        */
    void setPointSize(qreal s);
    /*! @brief Sets the font family
         @param fontFamily The QT String object that the fontFamily should be
        */
    void setFontFamily(const QString &fontFamily);
    /*! @brief Sets the font style
         @param style The QFont Style object that the style needs to be set to
        */
    void setFontStyle(QFont::Style style);
    /*! @brief Sets the font weight
         @param a The font weight to be set to
        */
    void setFontWeight(QFont::Weight weight);

    /*! @brief Gets the font
        @return the QFont of this Text object
       */
    QFont getFont();
    /*! @brief Gets the text
    @return the QTextEdit string of this object
   */
    QTextEdit& getText();
  private:
    /*! @brief The text of the object */
    QTextEdit text;
    /*! @brief The font of the object */
    QFont font;
};

#endif // TEXT_H
