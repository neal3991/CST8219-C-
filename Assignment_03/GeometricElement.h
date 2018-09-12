// GeometricElement.h


#ifndef GEOMETRICELEMENT
#define GEOMETRICELEMENT

class GeometricElement : public GraphicElement
{
	coloref colour;
public:
	GeometricElement():GraphicElement(){}
	GeometricElement(string s) :GraphicElement(s){}
	GeometricElement(coloref c,vector<Line> v,string s):GraphicElement(v,s),colour(c) {}
	GeometricElement(GeometricElement& RGE) :GraphicElement(RGE), colour(RGE.colour){}
	friend ostream& operator<<(ostream&, GeometricElement&);
	void IntensifyColour();
};


#endif