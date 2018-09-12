// GraphicElement.h
#ifndef GRAPHICELEMENT
#define GRAPHICELEMENT

class GraphicElement
{	
	char* name;
	vector<Line> Lines;	// a vectorof Lines	
public:
	GraphicElement():name(nullptr){};
	GraphicElement(char*);
	GraphicElement(vector<Line>, char*);
	GraphicElement(GraphicElement&);
	~GraphicElement()
	{
		if (name)
			delete []name;
	}

	GraphicElement& operator=(GraphicElement&);
	friend ostream& operator<<(ostream&, GraphicElement&);
};

#e