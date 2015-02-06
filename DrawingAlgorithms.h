/*
	DrawingAlgorithms.h - DrawingAlgorithms class declaration. 
	Written by:
	Anoop Haridas
*/

#ifndef DRAWINGALGORITHMS_H
#define DRAWINGALGORITHMS_H
  
#include <QVector>

class DrawingAlgorithms
{
public:
	
    // Draws a line using 2 points to start and end using the DDA Algorithm

	/* Input:
      int xa - the x coord of the start point
	  int ya - the y coord of the start point
	  int xb - the x coord of the end point
	  int yb - the y coord of the end point
	Output:
	  QVector<QString> - a list of the output points formatted as strings
	*/
	static QVector<QString> dda(int xa, int ya, int xb, int yb);

	/*<<<<<<<<<<<<<<<<<<<<<drawLine>>>>>>>>>>>>>>>>>>>>>>>>
    Insert your comments here
	*/
	static QVector<QString> drawLine(int xa, int ya, int xb, int yb);
    static QVector<QString> drawLineDouble(double xa, double ya, double xb, double yb);

	/*<<<<<<<<<<<<<<<<<<<<<<<<<round2f>>>>>>>>>>>>>>>>>>>
    Global function to round floats to nearest integers
    */
    static int roundf2(float f);   

private:
	/*<<<<<<<<<<<<<<<<<<convertCoordsToString>>>>>>>>>>>>>>>
    Converts the X and Y coordinates to a formated string output
	Input:
      int num - the point count number
      int x - the x coord
	  int y - the y coord
	Output:
	  QString - the formatted output
	*/
	static QString convertCoordsToString(int num, int x, int y);

};
#endif
