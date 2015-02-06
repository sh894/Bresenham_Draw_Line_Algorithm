/*
	DrawingAlgorithms.h - DrawingAlgorithms class implementation. 
	Written by:
	Anoop Haridas
    Changed by:
    Siman Huang(14227642)
    Date: Feb 4th, 2015
*/

#include "DrawingAlgorithms.h"
#include <math.h>
#include <stdlib.h>
#include <qgl.h>
#include<math.h>
#include <iostream>
using namespace std;


QVector<QString> DrawingAlgorithms::dda(int xa, int ya, int xb, int yb) 
{
   QVector<QString> output;
   float xIncrement, yIncrement, x, y;
   int dx, dy, steps, k;
   
   // Find the distance from the start and end points in the x and y direction
   dx = xb - xa;
   dy = yb - ya;
   
   // Initialize the start point
   x = xa;
   y = ya;

   // If the absolute distance in the x direction is greater than the y direction
   // then take x number of steps otherwise take dy steps
   if (abs(dx) > abs(dy))
      steps = abs(dx);
   else  
      steps = abs(dy);
   
   // Determine the increments needed for the number of steps
   xIncrement = dx / (float)steps;
   yIncrement = dy / (float)steps;
   
   glBegin(GL_POINTS);
     //Convert the coords to a string and add to the output list
     output.append(DrawingAlgorithms::convertCoordsToString(0, roundf2(x), roundf2(y)));
     glVertex2i( roundf2(x),  roundf2(y));
   glEnd();
   
   for ( k=0; k<steps; k++) 
   {
      //Increase a little in the x and y direction each step
      //By rounding the values then you get the result of staying
      //At the current pixel coord or moving to the next pixel coord
	  x += xIncrement;
      y += yIncrement;
      
      glBegin(GL_POINTS);
	    //Convert the coords to a string and add to the output list
	    output.append(DrawingAlgorithms::convertCoordsToString(k+1, roundf2(x), roundf2(y)));
        glVertex2i( roundf2(x),  roundf2(y));
      glEnd();
   }

   output.append("----------\n");

   return output;
}

/*<<<<<<<<<<<<<<<<<<<<<drawLine>>>>>>>>>>>>>>>>>>>>>>>>*/
//Bresenham Line Drawing Algorithm with INTEGER input value
//All cases into considerate
QVector<QString> DrawingAlgorithms::drawLine(int xa, int ya, int xb, int yb)
{
  QVector<QString> output;
  double x, y;
  double dx,dy;
  // Find the distance from the start and end points in the x and y direction
  // Calculate the constants Δx, Δy, 2Δy, and (2Δy - 2Δx)
  // And get the first value for the decision parameter as:p0 =2Δy−Δx
  dx=abs(xb-xa);
  dy=abs(yb-ya);
  if(dx >= dy)
  {
      int p0 = 2*dy-dx;
      int d_1 = 2*dy;
      int d_2 = 2*(dy-dx);
      int k = 0;
      if(xa < xb)
      {
          x = xa;
          y = ya;
      }
      else
      {
          x = xb;
          y = yb;
          xb=xa;
          yb=ya;
      }
      glBegin(GL_POINTS);
      glVertex2i( roundf2(x),  roundf2(y));
      output.append(DrawingAlgorithms::convertCoordsToString(k, roundf2(x), roundf2(y)));
      glEnd();
      while(x < xb)
      {
          if(p0 < 0)
              p0 = p0 + d_1;
          else
          {
              if(y < yb)
              {
                  y++;
                  p0 = p0 + d_2;
              }
              else
              {
                  y--;
                  p0 = p0 + d_2;
              }
          }
          x++;
          k++;
          glBegin(GL_POINTS);
          glVertex2i(roundf2(x),roundf2(y));
          output.append(DrawingAlgorithms::convertCoordsToString(k, roundf2(x), roundf2(y)));
          glEnd();
      }
  }

  else
  {
      int p0 = 2*dx - dy;
      int d_1 = 2*dx;
      int d_2 = 2*(dx-dy);
      int k = 0;
      if(ya < yb)
      {
          x = xa;
          y = ya;
      }
      else
      {
          x = xb;
          y = yb;
          yb = ya;
          xb = xa;
      }
      glBegin(GL_POINTS);
      glVertex2i(roundf2(x),roundf2(y));
      glEnd();
      while( y < yb)
      {
          if(p0 < 0)
          {
              p0 = p0 + d_1;
          }
          else
          {
              if(x > xb)
              {
                  x--;
                  p0 = p0 + d_2;
              }
              else
              {
                  x++;
                  p0 = p0 + d_2;
              }
          }
          y++;
          k++;
          glBegin(GL_POINTS);
          glVertex2i(roundf2(x),roundf2(y));
          output.append(DrawingAlgorithms::convertCoordsToString(k, roundf2(x), roundf2(y)));
          glEnd();
      }
  }

      output.append("----------\n");
  return output;
}

/*<<<<<<<<<<<<<<<<<<<<<drawLinDoublee>>>>>>>>>>>>>>>>>>>>>>>>*/
//Bresenham Line Drawing Algorithm with DOUBLE input value
//All cases into considerate
QVector<QString> DrawingAlgorithms::drawLineDouble(double xa, double ya, double xb, double yb)
{
  QVector<QString> output;
  double x, y;
  double dx,dy;
  // Find the distance from the start and end points in the x and y direction
  // Calculate the constants Δx, Δy, 2Δy, and (2Δy - 2Δx)
  // And get the first value for the decision parameter as:p0 =2Δy−Δx
  dx=fabs(xb-xa);
  dy=fabs(yb-ya);
  if(dx >= dy)
  {
      int p0 = 2*dy-dx;
      int d_1 = 2*dy;
      int d_2 = 2*(dy-dx);
      int k = 0;
      if(xa < xb)
      {
          x = xa;
          y = ya;
      }
      else
      {
          x = xb;
          y = yb;
          xb=xa;
          yb=ya;
      }
      glBegin(GL_POINTS);
      glVertex2f( roundf2(x),  roundf2(y));
      output.append(DrawingAlgorithms::convertCoordsToString(k, roundf2(x), roundf2(y)));
      glEnd();
      while(x < xb)
      {
          if(p0 < 0)
              p0 = p0 + d_1;
          else
          {
              if(y < yb)
              {
                  y++;
                  p0 = p0 + d_2;
              }
              else
              {
                  y--;
                  p0 = p0 + d_2;
              }
          }
          x++;
          k++;
          glBegin(GL_POINTS);
          glVertex2f(roundf2(x),roundf2(y));
          output.append(DrawingAlgorithms::convertCoordsToString(k, roundf2(x), roundf2(y)));
          glEnd();
      }
  }

  else
  {
      int p0 = 2*dx - dy;
      int d_1 = 2*dx;
      int d_2 = 2*(dx-dy);
      int k = 0;
      if(ya < yb)
      {
          x = xa;
          y = ya;
      }
      else
      {
          x = xb;
          y = yb;
          yb = ya;
          xb = xa;
      }
      glBegin(GL_POINTS);
      glVertex2f(roundf2(x),roundf2(y));
      glEnd();
      while( y < yb)
      {
          if(p0 < 0)
          {
              p0 = p0 + d_1;
          }
          else
          {
              if(x > xb)
              {
                  x--;
                  p0 = p0 + d_2;
              }
              else
              {
                  x++;
                  p0 = p0 + d_2;
              }
          }
          y++;
          k++;
          glBegin(GL_POINTS);
          glVertex2f(roundf2(x),roundf2(y));
          output.append(DrawingAlgorithms::convertCoordsToString(k, roundf2(x), roundf2(y)));
          glEnd();
      }
  }

      output.append("----------\n");
  return output;
}
/*<<<<<<<<<<<<<<<<<<<<<<<<<round2f>>>>>>>>>>>>>>>>>>>*/
int DrawingAlgorithms::roundf2(float f)
{
  if (f >= 0)
    return ( ((int) (f+0.5)));
  else 
    return ( ((int) (f-0.5)));
}

/*<<<<<<<<<<<<<<<<<<convertCoordsToString>>>>>>>>>>>>>>>*/
QString DrawingAlgorithms::convertCoordsToString(int num, int x, int y)
{
	return QString::number(num) + ": X: " + QString::number(x) + ", Y: " + QString::number(y);  
}
