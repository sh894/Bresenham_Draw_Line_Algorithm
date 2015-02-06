/*
	MainWindow.h - MainWindow class declaration. 
	Written by:
	Anoop Haridas
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QLineEdit>
#include <QSlider>
#include <QLabel>

class GLWidget;
class Window;
class QAction;
class QMenu;
class QToolBar;

/*=========================MainWindow=======================
Main container for all the widgets
*/
class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  
  MainWindow(); 
  
public slots:

  /*
  A slot to change the status bar when the mouse moves
  */
  void updateStatusLabel(int x, int y);

private:
  /*
  Creates the actions triggered by the popup menus and toolbar icons
  */
  void createActions();
  
  /*
  Creates the popup menus 
  */
  void createMenus();

  /*
  Creates the toolbar and icon buttons
  */
  void createToolBar();

  //The menus
  QMenu* fileMenu;
  QMenu* graphicsMenu;
  QMenu* drawMenu;     
  QMenu* rasterizeMenu; 
  QMenu* transformMenu;
  QMenu* optionsMenu;
  
  //The toolbar
  QToolBar* interactToolBar;

  //The actions triggered by the menu and toolbar
  QAction* printAct;
  QAction* exitAct;

  QAction* colorAct;

  QAction* diagLineAct;
  QAction* mouseLineAct;  
  QAction* mousePolylineAct;
  QAction* mousePolygonAct;

  QAction* drawBowtieAct;
  QAction* drawHouseAct;

  Window* childWindow;
  //GLWidget* glWindow;

private slots:

};

#endif
