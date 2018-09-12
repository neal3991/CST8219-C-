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
#include <ostream>
#include <vector>
#include <string.h>
#include <vld.h>
using namespace std;
#include "Point.h"
#include "Line.h"
#include "GraphicElement.h"
#include "VectorGraphic.h"

/********************************************************************************
Function name			operator[]												*
Purpose:				Find the proper index of Elements and return 			*
In parameters:			int index												*
Out parameters:			GraphicElement&											*
Version:				1														*
Author:					Niladri Sengupta										*
*********************************************************************************/
GraphicElement& VectorGraphic::operator[](int index){
	GraphicElement* temp = nullptr;
	if (index >= (int)numElements){
		return *temp;
	}
	return *Elements[index];
}

/********************************************************************************
Function name			operator<<												*
Purpose:				Part - 1 of reporting a graphical element	 			*
In parameters:			ostream& out, VectorGraphic& vg							*
Out parameters:			ostream&												*
Version:				1														*
Author:					Niladri Sengupta										*
*********************************************************************************/
ostream& operator<<(ostream& out, VectorGraphic& vg){
	if (vg.numElements == 0){
		out << "No GraphicElement to report" << endl;
		return out;
	}
	for (unsigned int i = 0; i < vg.numElements; i++){
		out << "Reporting Graphic Element " << i << endl << vg.Elements[i];
	}
	return out;
}

/********************************************************************************
Function name			AddGraphicElement										*
Purpose:				Adding a graphical element to Elements[x] (the heap		*
In parameters:			N/A														*
Out parameters:			N/A														*
Version:				1														*
Author:					Niladri Sengupta										*
*********************************************************************************/
void VectorGraphic::AddGraphicElement(){
	/* Declarations */
	int i = 0;
	int xStart = 0, yStart = 0;
	int xEnd = 0, yEnd = 0;
	int num_lines;
	char* temp_name = new char[256];
	vector<Line> v;
	Point Start, End;
	Line lines;
	/* Temp */
	GraphicElement** temp = Elements;
	Elements = new GraphicElement*[sizeof(GraphicElement*)*numElements];
	/* Resizing */
	if (numElements > 1){
		for (unsigned int i = 0; i < numElements; i++){
			Elements[i] = temp[i];
		}
		delete[] temp;
	}
	/* Element name */
	cout << "ADDING A Graphic Element\n";
	cout << "Please enter the name of the new GraphicElement(<256 characters): ";
	cin.ignore();
	cin.getline(temp_name, 256);
	/* Number of lines in that element */
	cout << "How many lines are there in the  new GraphicElement? ";
	cin >> num_lines;
	/* For loop for lines */
	for (i = 0; i < num_lines; i++) {
		cout << "Please enter the x coord of the start point of line index " << i << " ";
		cin >> xStart;
		cout << "Please enter the y coord of the start point of line index " << i << " ";
		cin >> yStart;
		cout << "Please enter the x coord of the end point of line index " << i << " ";
		cin >> xEnd;
		cout << "Please enter the y coord of the end point of line index " << i << " ";
		cin >> yEnd;
		Start = Point(xStart, yStart);
		End = Point(xEnd, yEnd);
		lines = Line(Start, End);
		v.push_back(lines);
	}
	GraphicElement* tempElement = new GraphicElement(v, temp_name);
	Elements[numElements] = tempElement;
	numElements++;

}

/********************************************************************************
Function name			DeleteGraphicElement									*
Purpose:				Deleting a graphical element with the respetive index	*
In parameters:			N/A														*
Out parameters:			N/A														*
Version:				1														*
Author:					Niladri Sengupta										*
*********************************************************************************/
void VectorGraphic::DeleteGraphicElement(){
	unsigned int numDel;
	if (numElements > 0){
		cout << "Please enter the index for the element to delete, between 0 and " << numElements;
		cin >> numDel;
		if (numDel <= numElements){
			numElements--;
			GraphicElement** tempElements = Elements;
			Elements = new GraphicElement*[sizeof(GraphicElement*)*numElements];
			for (unsigned int i = 0; i < numElements; i++){
				if (i  < numDel){
					Elements[i] = tempElements[i];
				}
				else if (i > numDel){
					if (i == numDel){
						delete Elements[i];
					}
					Elements[i - 1] = tempElements[i];
				}
			}
			delete[] tempElements;
		}
	}
}
void VectorGraphic::ReportVectorGraphic(){
	for (unsigned int i = 0; i < numElements; i++){
		cout << *(Elements[i]) << endl;
	}
}

/********************************************************************************
Function name			EditGraphicElement										*
Purpose:				Editing the respectiv graphical element in the heap		*
In parameters:			N/A														*
Out parameters:			N/A														*
Version:				1														*
Author:					Niladri Sengupta										*
*********************************************************************************/
void VectorGraphic::EditGraphicElement(){
	unsigned int edit;
	char* temp_name = new char[256];
	unsigned int numLines;
	int xStart, yStart;
	int xEnd, yEnd;
	cout << "EDIT A GRAPHIC ELEMENT" << endl;
	cout << "Please enter the index for the element to edit, between 0 and " << (numElements - 1);
	cin >> edit;
	cout << "Please enter the new name of the GraphicElement(<256 characters): ";
	cin >> temp_name;
	cout << "How many lines are there in the GraphicElement? ";
	cin >> numLines;
	vector<Line>tempLines(numLines);
	for (unsigned int i = 0; i < numLines; i++){
		cout << "Please enter the x coord of the start point of line index " << i << " ";
		cin >> xStart;
		cout << "Please enter the y coord of the start point of line index " << i << " ";
		cin >> yStart;
		cout << "Please enter the x coord of the end point of line index " << i << " ";
		cin >> xEnd;
		cout << "Please enter the y coord of the end point of line index " << i << " ";
		cin >> yEnd;
		tempLines[i] = Line(Point(xStart, yStart), Point(xStart, yStart));
	}
	GraphicElement newElement(tempLines, temp_name);
	Elements[numElements] = &newElement;
}