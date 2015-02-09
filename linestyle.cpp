#include "linestyle.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>


LineStyle::LineStyle(QWidget *parent) : QDialog(parent)
{
    //This code builds a dialog box with 2 buttons and a set of labelled
    //lineEdits (text boxes).  It also connects the action of pushing
    //the buttons to the code (ie. slots) handling the outcome

    //Make two push buttons
         QPushButton *drawButton;
         drawButton = new QPushButton("Line Thickness", this);
    //When the draw buton is clicked the getValues SLOT is called
         connect(drawButton, SIGNAL(clicked()), this, SLOT(getValues()));
         connect(drawButton,SIGNAL(clicked()),this,SLOT(close()));
    //Create labeels
         QLabel *labelX;
             labelX = new QLabel("Input the line thickness:", this);
    //Create LineEdits
             editX = new QLineEdit(this);
    //The following code is used to layout the buttons, labels and line edits.
    //The QVBoxLayout is like an invisible container for stacking GUI objects vertically
            QVBoxLayout *vLay = new QVBoxLayout(this);
    //The QHBoxLayout is similar but stacks them horizontally
             QHBoxLayout *h1 = new QHBoxLayout();
             h1->addSpacing(10);        //Add space between widget
             h1->addWidget(labelX);     //Add label
             h1->addWidget(editX,5);    //Add lineEdit

             QHBoxLayout *h5 = new QHBoxLayout();
             h5->addSpacing(10);
             h5->addWidget(drawButton); //Add the draw button
             h5->addStretch(5);
    //Add all the horizontal layouts we created to the vertical layout
             vLay->addLayout(h1);
             vLay->addLayout(h5);
}

LineStyle::~LineStyle()
{

}

void LineStyle::getValues()

{

   //Whenever then draw button is pushed this signal is called
    //The input format is text, so using the toDouble() change the input format to DOUBLE type
    if((editX->text().toInt()==0))
        {
            QMessageBox::warning(NULL,"warning","Please input the thickness of the line",QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes);
        }

        else emit stylevaluesUpdated(editX->text().toInt());
}


