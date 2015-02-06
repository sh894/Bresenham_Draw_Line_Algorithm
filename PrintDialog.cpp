/*
	PrintDialog.h - PrintDialog class declaration. 
	Class for printing text output
	Written by:
	Anoop Haridas
*/

#include "PrintDialog.h"

PrintDialog::PrintDialog(QWidget *parent) : QDialog(parent) 
{
  setWindowTitle(tr("Drawing Output"));

  displayWindow = new QTextEdit(this);    
  displayWindow->setMinimumSize(150, 500);
  setMinimumSize(150, 500);    
}

PrintDialog::~PrintDialog()
{
	
}

void PrintDialog::setContents(QVector<QString> list)
{
  for(int i = 0; i < (int)list.count(); i++)
  {
    displayWindow->append(list.at(i));
  }
}

void PrintDialog::clear()
{
	displayWindow->clear();
}
