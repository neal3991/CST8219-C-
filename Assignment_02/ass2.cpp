// ass2 W17 

#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC	// need this to get the line identification
//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF); // in main, after local declarations
//NB must be in debug build
#include <crtdbg.h>

#include <iostream>
#include <vector>
using namespace std;
#include "Point.h"
#include "Line.h"
#include "GraphicElement.h"
#include "VectorGraphic.h"

	enum{ RUNNING = 1 };	
		
	VectorGraphic Image;
	
	int main()
	{
		char response;
		_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

		while (RUNNING)
		{
			cout<<endl<<"Please select an option:\n"<<endl;
			cout<<"1. Add a Graphic Element\n";
			cout<<"2. Delete a Graphic Element\n";
			cout<<"3. Report a Graphic Element\n";
			cout<<"4. List the Graphic Elements\n";
			cout<<"5. Edit a Graphic Elements\n";
			cout<<"q. Quit\n";
			cout<<"CHOICE: ";
			cin>>response;

			switch (response)
			{
			case '1':Image.AddGraphicElement(); break;
			case '2':Image.DeleteGraphicElement(); break;
			case '3':
				int index;
				cout << "Please enter the index of the Graphic Element: ";
				cin >> index;
				cout << Image[index];
				break;
			case '4':Image.ReportVectorGraphic(); break;
			case '5':Image.EditGraphicElement(); break;
			case 'q':return 0;
			default:cout<<"Please enter a valid option\n";
			}
			cout<<endl;
		}
		return 0;
	}

	