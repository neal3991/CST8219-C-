/********************************************************************************************************************
Filename:				Line.cpp																					*
Author:					Niladri Sengupta																			*
Student No:  			040777969																					*
Course Name/Number:		CST8219																						*
lab Sect:				310																							*
Assignment #:			02																							*
Assignment name:		Vector Graphic with Overloaded Operators													*
Due Date:				18th March 2017																				*
Submission Date			18th March 2017																				*
Professor:				Andrew Tyler																				*
Purpose:				To manipulate Vector Graphics in elements using C++ by overloading operators				*
*********************************************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "Point.h"
#include "Line.h"
/********************************************************************************************
Function name			operator<<															*
Purpose:				Overloading the cout operator for Line objects						*
In parameters:			ostream& out, Line& ln												*
Out parameters:			ostream&															*
Version:				1																	*
Author:					Niladri Sengupta													*
*********************************************************************************************/
ostream& operator<<(ostream& out, Line& ln){
	out << "start is :" << ln.start;
	out << "end is :" << ln.end << endl;
	return out;
}