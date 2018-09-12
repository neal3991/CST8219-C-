/********************************************************************************************************************
Filename:				VectorGraphic.cpp																			*
Author:					Niladri Sengupta																			*
Student No:  			040777969																					*
Course Name/Number:		CST8219																						*
lab Sect:				310																							*
Assignment #:			01																							*
Assignment name:		Vector Graphic in C++																		*
Due Date:				18th Feb 2017																				*
Submission Date			19th Feb 2017																				*
Professor:				Andrew Tyler																				*
Purpose:				To manipulate Vector Graphics in elements using C++ with the help of Stash2.h and Stash2.cpp*
*********************************************************************************************************************/
/* Headers */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string.h>
#include "Line.h"
#include "Stash2.h"
#include "GraphicElement.h"
#include "VectorGraphic.h"
#include <vld.h>
using namespace std;

/********************************************************************************
Function name			AddGraphicElement										*
Purpose:				Purpose is to add a new Graphic Element					*
In parameters:			N/A														*
Out parameters:			N/A														*
Version:				1														*
Author:					Niladri Sengupta										*
*********************************************************************************/
void VectorGraphic::AddGraphicElement(){
	/* Temporary element to be added later to Elements*/
	Line lines;
	/* To get the total number of lines in one element*/
	int num_lines = 0;
	int counter = (int) numElements;
	/* Temporary char to get the name */
	char temp_name[256];
	/* If maximum capacity is reached - return */
	if (numElements == MAX_ELEMENTS){
		cout << "Maximum elements have reached. No space left." << endl;
		return;
	}
	/* Entering a new Graphical Element into index.*/
	cin.clear();
	cout << "Please enter the name of the new GraphicElement(<256 characters): ";
	cin >> temp_name;
	std::cin.getline(temp_name, 256);
	cout << "How many lines are there in the  new GraphicElement? ";
	cin >> num_lines;
	for (int i = 0; i < num_lines; i++) {
		cout << "Please enter the x coord of the start point of line index " << i << " " ;
		cin >> lines.start.x;
		cout << "Please enter the y coord of the start point of line index " << i << " ";
		cin >> lines.start.y;
		cout << "Please enter the x coord of the end point of line index " << i << " ";
		cin >> lines.end.x;
		cout << "Please enter the y coord of the end point of line index " << i << " ";
		cin >> lines.end.y;
		/* Adding the current line to the Element in the designated location*/
		((Elements[counter].GetLines()).add(&lines));
	}
	/* Adding Name of the element to the designated space*/
	((Elements[counter].GetName())) = (char *)malloc(((strlen(temp_name)) + 1)*sizeof(char));
	strcpy_s((Elements[counter].GetName()), ((strlen(temp_name)) + 1), temp_name);
	numElements++;
}

/********************************************************************************
Function name			ReportVectorGraphic										*
Purpose:				Purpose is to print out all the Graphic Elements		*
In parameters:			N/A														*
Out parameters:			N/A														*
Version:				1														*
Author:					Niladri Sengupta										*
*********************************************************************************/
void VectorGraphic::ReportVectorGraphic(){
	//GraphicElement temp[MAX_ELEMENTS];
	/* Setting numElements to a temporary int*/
	int counter = (int) numElements;
	/* If numELements is negative - return*/
	if (numElements < 0){
		cout << "No Elements found." << endl;
		return;
	}

	int j;
	cout << "VectorGraphic Report " << endl;
	/* Loop for printing the report */
	for (int i = 0; i < (counter); i++){
		cout << "Reporting Graphic Element #" << i << endl;
		/* Getting the name of the individual Element */
		cout << "Graphic Element name: " << ((Elements[i].GetName())) << endl;
		/* Loop for printing the individual lines*/
		for (j = 0; j < (Elements[i].GetLines()).count(); j++)
		{
			/* Fetching individual lines of the Element */
			Line * temp_lines = (Line*)((Elements[i].GetLines()).fetch(j));
			cout << "Line #" << j << " start x: " << temp_lines->start.x << endl;
			cout << "Line #" << j << " start y: " << temp_lines->start.y << endl;
			cout << "Line #" << j << " end x: " << temp_lines->end.x << endl;
			cout << "Line #" << j << " end y: " << temp_lines->end.y << endl;
		}
	}

}