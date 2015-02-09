#include "GLWidget.h"
#include "Window.h"
#include "MainWindow.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDesktopWidget>
#include <QApplication>

Window::Window(MainWindow *mw) : mainWindow(mw)
{
    glWindow = new GLWidget;
	connect(glWindow, SIGNAL(mouseMoved(int, int)), this->mainWindow, SLOT(updateStatusLabel(int, int)));

	connect(this, SIGNAL(printCallFromMW()), glWindow, SLOT(togglePrintDialog()));

	connect(this, SIGNAL(drawDialogLineFromMW()), glWindow, SLOT(drawDialogLine()));
	connect(this, SIGNAL(drawMouseLineFromMW()), glWindow, SLOT(drawMouseLine()));
	connect(this, SIGNAL(drawMousePolyLineFromMW()), glWindow, SLOT(drawMousePolyline()));
	connect(this, SIGNAL(drawMousePolygonFromMW()), glWindow, SLOT(drawMousePolygon()));

    connect(this, SIGNAL(drawBowtieFromMW()), glWindow, SLOT(drawBowtie()));
    connect(this, SIGNAL(drawHouseFromMW()), glWindow, SLOT(drawHouse()));

    connect(this, SIGNAL(chooseColorFromMW()), glWindow, SLOT(chooseColor()));

    connect(this,SIGNAL(drawLineStyleFromMW()),glWindow,SLOT(styleDialog()));
	

	QVBoxLayout* mainLayout = new QVBoxLayout;
	QHBoxLayout* container = new QHBoxLayout;
	
	container->addWidget(glWindow);

	//Create widget to hold everything else in this widget
    QWidget* w = new QWidget;
	w->setLayout(container);
	mainLayout->addWidget(w);
    setLayout(mainLayout);
	
    setWindowTitle(tr("Computer Graphics 4610/7610: Assignment 1 By Siman Huang"));
}
