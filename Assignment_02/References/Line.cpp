/*************************************************************************************************************************************
Filename :					Line.cpp
Version :					1.0
Author / Student name :		Arin Kumar Poray
Student number :			040797800
Course name and number :	C++ programming  ( CST8219 )
Lab section number :		300
Assignment number :			1
Assignment name :			Vector Graphic
Due date :					12th November, 2016
Submission date :			12th November, 2016
Professor's name :			Andrew Tyler
Purpose :					Contains the definition for the overloaded operator in Line class
*************************************************************************************************************************************/

#include "Point.h"
#include "Line.h"

/*************************************************************************************************************************************
* Function name:	Overloaded output stream for Line
* Purpose:			prints a Line object on the standard output (screen)
* In parameters:	reference to a standard output stream object
*					reference to a Line object in memory
* Out parameters:	reference to the same standard output stream object received as input
* Version:			1.0
* Author:			Arin Kumar Poray
*************************************************************************************************************************************/
ostream& operator<<(ostream& out, Line& rL){
	out << "start Point :" << rL.start;
	out << "end Point :" << rL.end << endl;
	return out;
}