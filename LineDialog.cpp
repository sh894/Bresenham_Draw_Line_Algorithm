/*
    LineDialog.cpp - LineDialog class implementation.
    Dialog for line endpoint input and management.
    Written by:
    Anoop Haridas
*/

#include "LineDialog.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>

LineDialog::LineDialog(QWidget *parent) : QDialog(parent)
  {

    //This code builds a dialog box with 2 buttons and a set of labelled
    //lineEdits (text boxes).  It also connects the action of pushing
    //the buttons to the code (ie. slots) handling the outcome

    //Make two push buttons
    QPushButton *drawButton, *hideButton;

    drawButton = new QPushButton("Draw", this);
    hideButton = new QPushButton("Hide", this);

    //When the draw buton is clicked the getValues SLOT is called
    connect(drawButton, SIGNAL(clicked()), this, SLOT(getValues()));

    //When the hide button is clicked the hideDialog SLOT is called
    connect(hideButton, SIGNAL(clicked()), this, SLOT(hideDialog()));

    //Create a set of labels
    QLabel *labelX1, *labelX2, *labelY1, *labelY2;
    labelX1 = new QLabel("X1:", this);
    labelY1 = new QLabel("Y1:", this);
    labelX2 = new QLabel("X2:", this);
    labelY2 = new QLabel("Y2:", this);

    //Create a set of LineEdits
    editX1 = new QLineEdit(this);
    editY1 = new QLineEdit(this);
    editX2 = new QLineEdit(this);
    editY2 = new QLineEdit(this);

    //The following code is used to layout the buttons, labels and line edits.

    //The QVBoxLayout is like an invisible container for stacking GUI objects vertically
    QVBoxLayout *vLay = new QVBoxLayout(this);

    //The QHBoxLayout is similar but stacks them horizontally
    QHBoxLayout *h1 = new QHBoxLayout();
    h1->addSpacing(10);			 //Add space between widget
    h1->addWidget(labelX1);		 //Add label
    h1->addWidget(editX1,5);	 //Add lineEdit

    QHBoxLayout *h2 = new QHBoxLayout();
    h2->addSpacing(10);
    h2->addWidget(labelY1);
    h2->addWidget(editY1,5);

    QHBoxLayout *h3 = new QHBoxLayout();
    h3->addSpacing(10);
    h3->addWidget(labelX2);
    h3->addWidget(editX2,5);

    QHBoxLayout *h4 = new QHBoxLayout();
    h4->addSpacing(10);
    h4->addWidget(labelY2);
    h4->addWidget(editY2,5);

    QHBoxLayout *h5 = new QHBoxLayout();
    h5->addSpacing(10);
    h5->addWidget(drawButton);  //Add draw button
    h5->addStretch(5);
    h5->addWidget(hideButton);   //Add hide button
    h5->addSpacing(10);

    //Add all the horizontal layouts we created to the vertical layout
    vLay->addLayout(h1);
    vLay->addLayout(h2);
    vLay->addLayout(h3);
    vLay->addLayout(h4);
    vLay->addLayout(h5);
  }

LineDialog::~LineDialog()
{

}

void LineDialog::hideDialog()
{
    hide();
}

void LineDialog::getValues()
{

   //Whenever then draw button is pushed this signal is called
    //The input format is text, so using the toDouble() change the input format to DOUBLE type
   emit valuesUpdated(editX1->text().toDouble(), editY1->text().toDouble(), editX2->text().toDouble(), editY2->text().toDouble());
}
