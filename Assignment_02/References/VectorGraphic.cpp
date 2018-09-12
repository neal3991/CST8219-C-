/*************************************************************************************************************************************
Filename :					VectorGraphic.cpp
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
Purpose :					Contains the function definitions and the definitions for the overloaded operators in VectorGraphic class
*************************************************************************************************************************************/

#include "Point.h"
#include "Line.h"
#include "GraphicElement.h"
#include "VectorGraphic.h"

/*************************************************************************************************************************************
* Function name:	Overloaded operator [] for VectorGraphic
* Purpose:			returns a reference to a GraphicElement object in memory at stored at an index in an array of GraphicElements 
*					(pElements) in a VectorGraphic object
* In parameters:	index of a GraphicElement object in the array pElements, whose reference user needs to return
* Out parameters:	reference to a GraphicElement object in memory
* Version:			1.0
* Author:			Arin Kumar Poray
*************************************************************************************************************************************/
GraphicElement& VectorGraphic::operator[](int index){
	GraphicElement* temp = nullptr;
	if (index >= (int)numGraphicElements){
		return *temp;
	}
	return pElements[index];
}

/*************************************************************************************************************************************
* Function name:	Overloaded operator += for VectorGraphic
* Purpose:			adds a GraphicElement at the end of an array of GraphicElements (pElements) in a VectorGraphic object,
*					hence increasing the size of the array by one
* In parameters:	reference to a GraphicElement object in memory
* Out parameters:	none
* Version:			1.0
* Author:			Arin Kumar Poray
*************************************************************************************************************************************/
void VectorGraphic::operator+=(GraphicElement& rGE){

	unsigned int i;
	GraphicElement* temp = new GraphicElement[numGraphicElements + 1];

	for (i = 0; i < numGraphicElements; i++){
		temp[i] = pElements[i];
	}

	temp[numGraphicElements] = rGE;

	if (pElements){
		delete[] pElements;
	}
	pElements = temp;
	numGraphicElements++;
}

/*************************************************************************************************************************************
* Function name:	Overloaded output stream for VectorGraphic
* Purpose:			prints a VectorGrahic object on the standard output (screen)
* In parameters:	reference to a standard output stream object
*					reference to a VectorGraphic object in memory
* Out parameters:	reference to the same standard output stream object received as input
* Version:			1.0
* Author:			Arin Kumar Poray
*************************************************************************************************************************************/
ostream& operator<<(ostream& out, VectorGraphic& rVG){
	if (rVG.numGraphicElements == 0){
		out << "No GraphicElement to report" << endl;
		return out;
	}
	for (unsigned int i = 0; i < rVG.numGraphicElements; i++){
		out << "Reporting Graphic Element " << i << endl << rVG.pElements[i];
	}
	return out;
}

/*************************************************************************************************************************************
* Function name:	AddGraphicElement
* Purpose:			adds one GraphicElement per call
*                   when more than one GraphicElements exists in the memory,
*                   then instantiates a new array of GraphicElement objects dynamically, one more than the current array,
*                   copies all the GraphicElement objects from the current array into the new array,
*                   delete the current array,
*                   stores the new GraphicElement object at the last index of the new array,
*                   sets the new array to be the current array
* In parameters:	none
* Out parameters:	none
* Version:			1.0
* Author:			Arin Kumar Poray
*************************************************************************************************************************************/
void VectorGraphic::AddGraphicElement(){

	/* Variable declaration */
	unsigned int i;				// loop counter for iterating through an array of GraphicElement objects
	unsigned int add_offset;	// variable to store the index at which the new GraphicElement will be added
	GraphicElement* temp;		// temporary pointer to a GraphicElement

	char elementName[256];		// temorary array of characters for storing a string (name) of the new GraphicElement to be added
	Line* lineRef = nullptr;	// temporary pointer to a array of Line objects in the new GraphicElement
	unsigned int numLines;		// temporary variable for storing number of lines in the new GraphicElement
	int x;						// temporary variable to store the X-Coordinate of a Point
	int y;						// temporary variable to store the Y-Coordinate of a Point

	if (numGraphicElements > 0){ // for adding the second or more GraphicElements
		add_offset = numGraphicElements; // Storing the index at which the new graphic element will be added
		temp = new GraphicElement[numGraphicElements + 1]; // instantiating a temporary array of GraphicElement objects
		for (i = 0; i < numGraphicElements; i++){ // copying all the GraphicElement objects from the current array into the temporary array
			temp[i] = pElements[i];
		}
		if (pElements){
			delete[]pElements; // deleting the current array of GraphicElement objects
		}
	}
	else{ // for adding the first GraphicElement
		add_offset = 0; // setting the index at which the first GraphicElement will be added, to 0
		temp = new GraphicElement[1]; // instantiating an array of GraphicElement objects of size 1
	}

	cout << "ADDING A Graphic Element" << endl;
	cout << "Please enter the name of the new GraphicElement(<256 characters) : "; // Prompts user to enter the name of a new GraphicElement
	cin >> elementName;
	cout << "How many lines are there in the  new GraphicElement? : "; // Prompts user to enter the number of lines in the new GraphicElement
	cin >> numLines;
	lineRef = new Line[numLines]; // instantiating an array of Line objects
	for (i = 0; i < numLines; i++){ // Prompts user to enter the x and y coordinates of the start and the end of each line in the new GraphicElement object
		cout << "Please enter the x coord of the start point of line index " << i << ": ";
		cin >> x;
		cout << "Please enter the y coord of the start point of line index " << i << ": ";
		cin >> y;
		Point start(x, y); // instantiating a Point object as the start of a Line object
		cout << "Please enter the x coord of the end point of line index " << i << ": ";
		cin >> x;
		cout << "Please enter the y coord of the end point of line index " << i << ": ";
		cin >> y;
		Point end(x, y); // instantiating a Point object as the end of a Line object
		lineRef[i] = Line(start, end); // instantiating a Line object with the two Point objects created and adding it to the 
									   // array of Line objects in the new GraphicElement
	}
	GraphicElement newElement(lineRef, elementName, numLines); // instantiating the new GraphicElement object
	if (lineRef){
		delete[]lineRef;	// deleting the temorary pointer to an array of Line objects
	}
	temp[add_offset] = newElement; // adding the new GraphicElement at the last index of the temporary array of GraphicElements
	pElements = temp;	// assigning the temprary array of GraphicElements to pElement, thereby making it the current array 
	numGraphicElements++; // Incrementing numOfGraphicElements by 1
}

void VectorGraphic::DeleteGraphicElement(){

	unsigned int i; // loop counter for iterating through an array of GraphicElement objects
	unsigned int j; // secondary loop counter for iterating through an array of GraphicElement objects
	unsigned int deleteIndex; // to hold the index value, GraphicElement at which in an array that has to deleted
	GraphicElement* temp = nullptr; // a temporay pointer to a GraphicElement

	if (numGraphicElements > 0){ // checks TRUE if numGraphicElement is more than 0
		cout << "Deleting a Graphic Element" << endl;
		cout << "Please enter the index of the Graphic Element you wish to delete" << endl; // prompts user to enter the index, 
																							// GraphicElement at which in the array 
																							// user wants to delete
		cin >> deleteIndex;

		if (deleteIndex >= numGraphicElements){ // checks TRUE if deleteIndex is valid (i.e. 0 <= deleteIndex < numGraphicElements)
			cout << "No GraphicElement at index " << deleteIndex << endl;
		}
		else{
			if (numGraphicElements > 1){ // checks correct if numGraphicElement is more than 1 i.e. 2 or more
				temp = new GraphicElement[numGraphicElements - 1]; // instantiating a temporary array of GraphicElement objects, 
																   // one size less than the current array
				for (i = 0, j = 0; i < numGraphicElements; i++, j++){
					if (i == deleteIndex){ // checks TRUE if deleteIndex is equal to the index of the current GraphicElement 
						                   // in the array
						if (i == numGraphicElements - 1){ // checks TRUE in the GraphicElement to be deleted in 
							                              // the last GraphicElement in the array
							break; // breaks out of the for loop since all the GraphicElements had already been copied 
							       // except the one to be deleted
						}
						i++; // skips the current GraphicElement, to point to the next GraphicElement in the array to be copied
					}
					temp[j] = pElements[i];
				}
				if (pElements){
					delete[]pElements; // deleting the current array of GraphicElement objects
				}
				pElements = temp;
				numGraphicElements--; // decrementing the numGraphicElements by 1
			}
			else{ // checks TRUE if numGraphicElement is equal to 1
				numGraphicElements--; // decrementing numGraphicElements by ONE, making it 0 
				if (pElements){
					delete[]pElements; // deleting the current array of GraphicElement objects, 
									   // having only the ONE GraphicElement in it
				}
				pElements = nullptr; // setting it to point to a nullptr
			}
		}
	}
	else{ // checks TRUE in numGraphicElements is equal to 0
		cout << "No GraphicElement to delete" << endl;
	}
}