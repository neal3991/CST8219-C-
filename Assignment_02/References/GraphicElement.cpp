/*************************************************************************************************************************************
Filename :					GraphicElement.cpp
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
Purpose :					Contains the function definitions and the definitions for the overloaded operators in GraphicElement class
*************************************************************************************************************************************/

/*
* The #define _CRT_SECURE_NO_WARNINGS flag should be used in MS Visual Studio projects
* to suppress the warnings about using "unsafe" functions like fopen()
* and standard sting library functions defined in string.h.
* The define directive does not have any effect on other compiler projects(gcc, Borland).
*/
#define _CRT_SECURE_NO_WARNINGS

#include "Point.h"
#include "Line.h"
#include "GraphicElement.h"

/*************************************************************************************************************************************
* Function name:	Copy constructor for the GraphicElement class
* Purpose:			instantiates an object of GraphicElement which is a copy of the GraphicElement received as argument
* In parameters:	reference to the GraphicElement which needs to be copied
* Out parameters:	none
* Version:			1.0
* Author:			Arin Kumar Poray
*************************************************************************************************************************************/
GraphicElement::GraphicElement(GraphicElement& rGE) :numLines(rGE.numLines){
	strcpy(name, rGE.name);
	pLines = new Line[numLines];
	memcpy(pLines, rGE.pLines, sizeof(Line)*numLines);
}

/*************************************************************************************************************************************
* Function name:	3 argument constructor for the GraphicElement class
* Purpose:			instantiates an object of GraphicElement 
* In parameters:	pointer to an array of Line object,
*					pointer to an array of character array and
*					number of lines in the soon-to-be instantiated GraphicElement
* Out parameters:	none
* Version:			1.0
* Author:			Arin Kumar Poray
*************************************************************************************************************************************/
GraphicElement::GraphicElement(Line* lineRef, char* elementName, unsigned int lines) :numLines(lines){
	strcpy(name, elementName);
	pLines = new Line[numLines];
	memcpy(pLines, lineRef, sizeof(Line)*numLines);
}

/*************************************************************************************************************************************
* Function name:	Overloaded operator = for GraphicElement
* Purpose:			returns a reference to a Graphic Element which is a copy of the GraphicElement received as argument
* In parameters:	reference to a GraphicElement which needs to be copied
* Out parameters:	reference to a GraphicElement just copied into
* Version:			1.0
* Author:			Arin Kumar Poray
*************************************************************************************************************************************/
GraphicElement& GraphicElement::operator=(GraphicElement& rGE){
	delete[]pLines;
	strcpy(name, rGE.name);
	numLines = rGE.numLines;
	pLines = new Line[numLines];
	memcpy(pLines, rGE.pLines, sizeof(Line)*numLines);
	return *this;
}

/*************************************************************************************************************************************
* Function name:	Overloaded operator + for GraphicElement
* Purpose:			concatenating the GraphicElement received as argument with the GraphicElement
*					on which the function is called and returning the newly created GraphicElement
* In parameters:	reference to a GraphicElement in memory
* Out parameters:	a GraphicElement object
* Version:			1.0
* Author:			Arin Kumar Poray
*************************************************************************************************************************************/
GraphicElement GraphicElement::operator+(GraphicElement& rGE){
	GraphicElement temp;
	char tempName[256];
	strcpy(tempName, name);
	strcat(tempName, " ");
	strcat(tempName, rGE.name);
	strcpy(temp.name, tempName);
	temp.numLines = numLines + rGE.numLines;
	temp.pLines = new Line[temp.numLines];
	memcpy(temp.pLines, pLines, sizeof(Line)*numLines);
	memcpy(temp.pLines + numLines, rGE.pLines, sizeof(Line)*rGE.numLines);
	return temp;
}

/*************************************************************************************************************************************
* Function name:	Overloaded output stream for GraphicElement
* Purpose:			prints a GraphicElement object on the standard output (screen)
* In parameters:	reference to a standard output stream object
*					reference to a GraphicElement object in memory
* Out parameters:	reference to the same standard output stream object received as input
* Version:			1.0
* Author:			Arin Kumar Poray
*************************************************************************************************************************************/
ostream& operator<<(ostream& out, GraphicElement& rGE){
	out << "Graphic Element name : " << rGE.name << endl;
	for (unsigned int i = 0; i < rGE.numLines; i++){
		out << "Line " << i << ":" << endl << rGE.pLines[i] << endl;;
	}
	return out;
}