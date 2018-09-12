
/********************************************************************************************************************
Filename:				ass0.cpp																					*
Author:					Niladri Sengupta																			*
Student No:  			040777969																					*
Course Name/Number:		CST8219																						*
lab Sect:				310																							*
Assignment #:			0																							*
Assignment name:		Vector Graphic in C																			*
Due Date:				28th Jan 2017																				*
Submission Date			29th Jan 2017																				*
Professor:				Andrew Tyler																				*
Purpose:				To manipulate Vector Graphics in elements using dynamic memory allocation for its data.		*
*********************************************************************************************************************/
// ass0.cpp
#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC	// need this to get the line identification
//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF); // in main, after local declarations
//NB must be in debug build
/* Include Statements */
#include <string.h>
#include <crtdbg.h>
#include <stdio.h>
//Un-comment if plug-in is available
//#include <vld.h>
#include "CLib.h"

enum{ RUNNING = 1 };

/* Structures - Given */
struct Point
{
	int x, y;
};

struct Line
{
	Point start;
	Point end;
};

struct GraphicElement
{
	enum{ SIZE = 256 };
	char name[SIZE];
	CStash Lines;	// a Stash of Lines
};

struct VectorGraphic
{
	CStash Elements;	// a Stash of GraphicElements
};

/* Function Declarations */
void AddGraphicElement(VectorGraphic*);
void ReportVectorGraphic(VectorGraphic*);
void CleanUpVectorGraphic(VectorGraphic*);

/* Main Object */
VectorGraphic Image;

/* Main - Given */
int main()
{
	char response;
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // it's a Stash of GraphicElements

	initialize(&(Image.Elements), sizeof(GraphicElement));

	while (RUNNING)
	{
		printf("\nPlease select an option:\n");
		printf("1. Add a Graphic Element\n");
		printf("2. List the Graphic Elements\n");
		printf("q. Quit\n");
		printf("CHOICE: ");
		fflush(stdin);
		scanf("%c", &response);

		switch (response)
		{
		case '1':AddGraphicElement(&Image); break;
		case '2':ReportVectorGraphic(&Image); break;
		case 'q':CleanUpVectorGraphic(&Image); return 0;
		default:printf("Please enter a valid option\n");
		}
		printf("\n");
	}
	return 0;
}

/********************************************************************************
Function name			AddGraphicElement										*
Purpose:				Purpose is to add a new Graphic Element to the CStash	*
In parameters:			VectorGraphic											*
Out parameters:			N/A														*
Version:				1														*
Author:					Niladri Sengupta										*
*********************************************************************************/

void AddGraphicElement(VectorGraphic* s){
	/* Counters and temps*/
	int i = 0, counter = 0;
	int num_Lines = 0;
	GraphicElement temp;
	Line lines;
	initialize(&(temp.Lines), sizeof(Line));
	printf("Adding A Graphic Element\n");
	/* Name ofthe Graphical Element */
	printf("Please enter the name of the new GraphicElement(<256 characters): ");
	fflush(stdin);
	scanf("\n%[^\n]s", &(temp.name));
	fflush(stdin);
	/* Number of lines in the graphical element*/
	printf("How many lines are there in the  new GraphicElement? ");
	fflush(stdin);
	scanf("%d", &num_Lines);
	fflush(stdin);
	/* Input lines from the user*/
	for (i = 0; i < num_Lines; i++){
		printf("Please enter the x coord of the start point of line index %d:", counter);
		fflush(stdin);
		scanf("%d", &(lines.start.x));
		fflush(stdin);
		printf("Please enter the y coord of the start point of line index %d:", counter);
		scanf("%d", &(lines.start.y));
		fflush(stdin);
		printf("Please enter the x coord of the end point of line index %d:", counter);
		scanf("%d", &(lines.end.x));
		fflush(stdin);
		printf("Please enter the y coord of the end point of line index %d:", counter);
		scanf("%d", &(lines.end.y));
		fflush(stdin);
		/* Adding the line to temp */
		add(&temp.Lines, &lines);
	}
	/* Adding the entire temp to Elements*/
	add(&(s->Elements), &temp);
}

/****************************************************************
Function name			ReportVectorGraphic						*
Purpose:				Prints all the elements of the CStash	*
In parameters:			VectorGraphic							*
Out parameters:			N/A										*
Version:				1										*
Author:					Niladri Senupta							*
*****************************************************************/
void ReportVectorGraphic(VectorGraphic* s){
	int i, j;
	printf("VectorGraphic Report \n");
	/* Loop for printing the report */
	for (i = 0; i < count(&(s->Elements)); i++){
		printf("Reporting Graphic Element #%d\n", i);
		/* Fetching the elements*/
		GraphicElement * temp = (GraphicElement *)fetch(&(s->Elements), i);
		printf("Graphic Element name: %s \n", temp->name);
		/* Loop for printing the individual lines*/
		for (j = 0; j < count(&(temp->Lines)); ++j)
		{
			Line * line_temp = (Line *)fetch(&(temp->Lines), j);
			printf("Line #%d start x: %d\n", j, line_temp->start.x);
			printf("Line #%d start y: %d\n", j, line_temp->start.y);
			printf("Line #%d end x: %d\n", j, line_temp->end.x);
			printf("Line #%d end y: %d\n", j, line_temp->end.y);
		}
	}	
}

/************************************************************************
Function name			CleanUpVectorGraphic							*
Purpose:				Releases all the dynamically allocated memory	*
In parameters:			VectorGraphic									*
Out parameters:			N/A												*
Version:				1												*
Author:					Niladri Senupta									*
*************************************************************************/
void CleanUpVectorGraphic(VectorGraphic* s){
	//cleanup(&temp.Lines);
	/* Cleaning up lines*/
	cleanup(&(s->Elements));
}
