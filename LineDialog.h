/*
	LineDialog.h - LineDialog class declaration. 
	Dialog for line endpoint input and management.
	Written by:
	Anoop Haridas
*/

#ifndef LINEDIALOG_H
#define LINEDIALOG_H

#include <QLineEdit>
#include <QDialog>

/************************LineDialog***************************
// A dialog box that for entering pairs of points to draw the beginning and ending of the line
*/
class LineDialog : public QDialog 
{
  Q_OBJECT

public:
  
  LineDialog(QWidget *parent = 0); 
  
  ~LineDialog(); 

signals:
  /*
  A signal to indicate when the values are updated
  */
  void valuesUpdated(int x1, int y1, int x2, int y2);
  
private:
  QLineEdit *editX1, *editX2, *editY1, *editY2;

private slots:
  /*<
  Hide this dialog
  */
  void hideDialog();

  /*
  Gets the values from the LineEdits and sends the valuesUpdated signal
  */
  void getValues();
};

#endif