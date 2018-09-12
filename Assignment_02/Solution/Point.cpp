/********************************************************************************************************************
Filename:				VectorGraphic.cpp																			*
Author:					Niladri Sengupta																			*
Student No:  			040777969																					*
Course Name/Number:		CST8219																						*
lab Sect:				310																							*
Assignment #:			02																							*
Assignment name:		Vector Graphic in C++																		*
Due Date:				18th March 2017																				*
Submission Date			18th March 2017																				*
Professor:				Andrew Tyler																				*
Purpose:				To manipulate Vector Graphics in elements using C++ by overloading operators				*
*********************************************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "Point.h"
/********************************************************************************************
Function name			operator<<															*
Purpose:				Overloading the cout operator for Point objects						*
In parameters:			ostream& out, Line& ln												*
Out parameters:			ostream&															*
Version:				1																	*
Author:					Niladri Sengupta													*
*********************************************************************************************/
ostream& operator<<(ostream& out, Point& p) {
	out << " x = " << p.x << ",";
	out << " y = " << p.y << ".";
	return out;
}