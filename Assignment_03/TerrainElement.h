// TerrainElement.h

#ifndef TERRAINELEMENT
#define TERRAINELEMENT


class TerrainElement: public GraphicElement
{
	texture terrain;
public:
	TerrainElement() :GraphicElement(){}
	TerrainElement(string s) :GraphicElement(s){}
	TerrainElement(texture t, vector<Line> v, string s) :GraphicElement(v,s), terrain(t){}
	TerrainElement(TerrainElement& t) :GraphicElement(t),terrain(t.terrain){}
	friend ostream& operator<<(ostream&, TerrainElement&);
	void IntensifyColour();
};
#endif