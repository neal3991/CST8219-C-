/********************************************************************************************************************
Filename:				GraphicElement.cpp																			*
Author:					Niladri Sengupta																			*
Student No:  			040777969																					*
Course Name/Number:		CST8219																						*
lab Sect:				310																							*
Assignment #:			01																							*
Assignment name:		Vector Graphic in C++																		*
Due Date:				18th Feb 2017																				*
Submission Date			19th Feb 2017																				*
Professor:				Andrew Tyler																				*
Purpose:				To help VectorGraphic.cpp retrieving elements using getters/accessors						*
*********************************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include "Line.h"
#include "Stash2.h"
#include "GraphicElement.h"
using namespace std;

/********************************************************************************
Function name			GetName													*
Purpose:				Getter/accessors of 'name'								*
In parameters:			N/A														*
Out parameters:			N/A														*
Version:				1														*
Author:					Niladri Sengupta										*
*********************************************************************************/
char*& GraphicElement::GetName(){
	return this->name;
}

/********************************************************************************
Function name			GetLines												*
Purpose:				Getter/accessors of 'Lines'								*
In parameters:			N/A														*
Out parameters:			N/A														*
Version:				1														*
Author:					Niladri Sengupta										*
*********************************************************************************/
Stash& GraphicElement::GetLines(){
	return this->Lines;
}