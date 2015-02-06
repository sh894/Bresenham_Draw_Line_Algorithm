/*
	GLWidget.h - GLWidget class declaration. 
	Class for widget doing OpenGL drawing for CS 4610/7610.
	Written by:
	Anoop Haridas
*/

#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <qgl.h>
#include <QGLWidget>
#include <QString>

class PrintDialog;
class LineDialog;

/*
Note:  When an QGLWidget type is created the following happens immediately in this order:\

1)Everything in the constructor is completed
2)initializeGL is called - just the one time for this QGLWidget instance
3)resizeGL is called - NOTE that its called FIRST, BEFORE paintGL, like this at the beginning
4)paintGL is called - for the first time

*/

/*=========================GLWidget========================
This class is widget containing the OpenGL context for drawing the graphics
*/
class GLWidget : public QGLWidget
{
  
  // The Q_OBJECT macro MUST be placed like this, at the beginning of ALL Qt classes that handle signals and slots, 
  // and/or have GUI elements. This macro signals that Qt's meta-object compiler (moc) must be called for this class.
  Q_OBJECT

public:
  
  //Constructor
  GLWidget(QWidget *parent = 0);
  
  //Destructor
  ~GLWidget();

  /*------------------drawLine, Version 1------------------
  /* Draws a DDA line
  Input: 
    int x1 - the starting x coord
	int y1 - the starting y coord
	int x2 - the ending x coord
	int y1 - the ending y coord
  */
  void drawLine(int x1, int y1, int x2, int y2);

  /*------------------drawLine, Version 2------------------
  /* Draws a DDA line
  Input: 
    int x - the beginning x coord
	int y - the beginning y coord
	int l - the length of the line
  */
  void drawLine(int x, int y, int l);
  
  /*------------------minimumSizeHint----------------------
  Suggests the smallest size for the window
  */
  QSize minimumSizeHint() const;
  
  /*----------------------sizeHint-------------------------
  Suggests the size for the window
  */
  QSize sizeHint() const;

  /*------------------setDrawingMode-----------------------
  Sets which mode of drawing is currently active
  */
  void setDrawingMode(int mode);

  /*------------------setShapeMode-------------------------
  Sets which shape is currently active
  */
  void setShapeMode(int mode);

  //Set of static variables to represent the drawing mode
  static const int NONE;
  static const int MOUSE;
  static const int DIALOG;

  //Set of static variables to represent the shapes 
  static const int CLEAR;
  static const int LINE;
  static const int CIRCLE;
  static const int ELLIPSE;
  static const int POLYLINE;
  static const int POLYGON;
  static const int BOWTIE;
  static const int HOUSE;
 
public slots:
  
  /*---------------------togglePrintDialog------------------
  Invokes the print dialog for displaying results
  */
  void togglePrintDialog();

  /*---------------------drawDialogLine---------------------
  Invokes the line input dialog, then enables line drawing
  */
  void drawDialogLine();

  /*---------------------updateDialogLine-------------------
  Updates the line variables from dialog
  Input: int x1, y1, x2, y2: the line endpoints
  */
  void updateDialogLine(int x1, int y1, int x2, int y2);

  /*---------------------drawMouseLine----------------------
  Enables interactive line drawing
  */
  void drawMouseLine();

  /*---------------------drawMousePolyline------------------
  Enables interactive polyline drawing
  */
  void drawMousePolyline();

  /*---------------------drawMousePolygon-------------------
  Enables interactive polygon drawing
  */
  void drawMousePolygon();

 
  /*----------------------clearWindow-----------------------
  Clears the render window
  */
  void clearWindow();
  
  /*----------------------drawBowtie-----------------------
  Draw a bowtie
  */
  void drawBowtie();

  /*----------------------drawHouse-----------------------
  Draw a house
  */
  void drawHouse();

  /*----------------------chooseColor-----------------------
  Launches a color picker to set the line color
  */
  void chooseColor();

signals:
  /*---------------------mouseMoved-------------------------
  This signal is responsible for sending the current mouse
  position back to the MainWindow.
  */
  void mouseMoved(int x, int y);

protected:
  /*-----------------------initializeGL--------------------
  Initializes the GL window by doing operations such as setting
  the clear color, the lighting model, shading properties, etc.
  */
  virtual void initializeGL();

  /*-----------------------resizeGL------------------------
  Called every time the GL widget is resized
  */
  virtual void resizeGL(int w, int h);

  /*-----------------------paintGL-------------------------
  All graphics drawing is done (or called) from in here
  */
  virtual void paintGL();

  /*--------------------MouseMoveEvent---------------------
  Captures mouse movement events
  */
  virtual void mouseMoveEvent(QMouseEvent* e);
 
  /*--------------------MousePressEvent--------------------
  Captures mouse click events
  */
  virtual void mousePressEvent(QMouseEvent* e);


private:
  /*-------------------ClearShapeVariables-----------------
  Clears the variables containing the shape coordinates
  */
  void clearShapeVariables();

  //The end point coordinates for the DDA line
  int startX, startY, finishX, finishY;

  //The current line color
  GLubyte lineColor[3];

  //Counter for number of mouse clicks 
  int clickCounter; 
  
  //The current drawing mode (either dialog or mouse selection)
  int drawMode;

  //The current shape being drawn (line, circle or ellipse)
  int shapeMode;
  
  //Have the shape variables been cleared out?
  bool areShapesClear;
  
  //Need a variable to ensure output is only printed once per shape
  bool printOnce;

  PrintDialog* printDiag;
  LineDialog* lineDiag;
};

#endif

