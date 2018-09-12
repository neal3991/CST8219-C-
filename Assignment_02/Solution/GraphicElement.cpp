/********************************************************************************************************************
Filename:				VectorGraphic.cpp																			*
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
#include <vector>
#include <string.h>
#include <vld.h>
using namespace std;
#include "Point.h"
#include "Line.h"
#include "GraphicElement.h"
#include "VectorGraphic.h"

/********************************************************************************
Function name			GraphicElement - Constructor_01							*
Purpose:				Assigns the designated name for the Graphical Element	*
In parameters:			char* alt_name											*
Out parameters:			GraphicElement											*
Version:				1														*
Author:					Niladri Sengupta										*
*********************************************************************************/
GraphicElement::GraphicElement(char* alt_name) {
	this->name = new char[(strlen(alt_name) + 1)];
	strcpy_s(this->name, ((strlen(alt_name)) + 1), alt_name);
}

/********************************************************************************************
Function name			GraphicElement - Constructor_02										*
Purpose:				Assigns the designated name and vector for the Graphical Element	*
In parameters:			vector<Line> ln, char* alt_name										*
Out parameters:			GraphicElement														*
Version:				1																	*
Author:					Niladri Sengupta													*
*********************************************************************************************/
GraphicElement::GraphicElement(vector<Line> ln, char* alt_name) {
	this->name = new char[(strlen(alt_name) + 1)];
	strcpy_s(this->name, ((strlen(alt_name)) + 1), alt_name);
	Lines.assign(ln.begin(), ln.end());
}

/********************************************************************************************
Function name			GraphicElement - Constructor_02 - Copy constructor					*
Purpose:				Copies the entire constructor to the desginated constructor			*
In parameters:			GraphicElement& alt_name											*
Out parameters:			GraphicElement														*
Version:				1																	*
Author:					Niladri Sengupta													*
*********************************************************************************************/
GraphicElement::GraphicElement(GraphicElement& alt) {
	if (this->name != nullptr){
		this->name = new char[(strlen(alt.name) + 1)];
		strcpy_s(this->name, ((strlen(alt.name)) + 1), alt.name);
	}
	Lines.assign((alt.Lines).begin(), (alt.Lines).end());
}

/********************************************************************************************
Function name			operator=															*
Purpose:				Overloading the equal operator for GraphicElement objects			*
In parameters:			GraphicElement& alt													*
Out parameters:			GraphicElement&														*
Version:				1																	*
Author:					Niladri Sengupta													*
*********************************************************************************************/
GraphicElement& GraphicElement::operator=(GraphicElement& alt){
	if (alt.name != nullptr){
		this->name = new char[strlen(alt.name) + 1];
		strcpy_s(this->name, ((strlen(alt.name)) + 1), alt.name);
	}
	for (unsigned int i = 0; i < ((alt.Lines).size()); i++){
		Lines.push_back(alt.Lines[i]);
	}
	return *this;
}

/********************************************************************************************
Function name			operator<<															*
Purpose:				Overloading the cout operator for GraphicElement objects			*
In parameters:			GraphicElement& alt													*
Out parameters:			ostream&															*
Version:				1																	*
Author:					Niladri Sengupta													*
*********************************************************************************************/
ostream& operator<<(ostream& out, GraphicElement& alt) {
	//cout << "Test_01";
	out << "Graphic Element name : " << alt.name << endl;
	for (unsigned int i = 0; i < ((alt.Lines).size()); i++){
		out << "Line #" << i << ":" << alt.Lines[i] << endl;
	}
	return out;
}

