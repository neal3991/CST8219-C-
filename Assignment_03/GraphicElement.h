// GraphicElement.h

#ifndef GRAPHICELEMENT
#define GRAPHICELEMENT

class GraphicElement
{	
	vector<Line> Lines;	// a vectorof Lines	
protected:
	string name;
public:
	GraphicElement(){};
	GraphicElement(string s) :name(s){}
	GraphicElement(vector<Line>, string);
	GraphicElement(GraphicElement&);
	virtual~GraphicElement(){}
	friend ostream& operator<<(ostream&, GraphicElement&);
	virtual void IntensifyColour() = 0;
};

#endif