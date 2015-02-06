/*
	PrintDialog.h - PrintDialog class declaration. 
	Class for printing text output
	Written by:
	Anoop Haridas
*/

#ifndef PRINTDIALOG_H
#define PRINTDIALOG_H

#include <QTextEdit>
#include <QDialog>
#include <QVector>

/*--------------------------PrintDialog---------------------------
A dialog box that displays the output from the drawing algorithms
*/
class PrintDialog : public QDialog
{

public:
  //Constructor
  PrintDialog(QWidget *parent = 0); 
  
  //Destructor
  ~PrintDialog(); 
 
  /*------------------------setContents--------------------------
  Sets the contents of the dialog
  Input:
    QVector<QString> list - a list of QStrings containing drawing output
  */
  void setContents(QVector<QString> list);

public slots:
  /*
  Clears the contents of the dialog box
  */
  void clear();

private:
  QTextEdit *displayWindow;
};

#endif