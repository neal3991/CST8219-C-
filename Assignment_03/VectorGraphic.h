// VectorGraphic.h

#ifndef VECTORGRAPHIC
#define VECTORGRAPHIC

class VectorGraphic
{	
	GraphicElement** Elements;	

public:
	unsigned int numElements;	
	VectorGraphic():numElements(0),Elements(nullptr){}
	~VectorGraphic()
	{
		for (int i = 0; i < numElements; i++)
			delete Elements[i];
		delete[] Elements;
	}
	void AddGraphicElement();
	void DeleteGraphicElement();
	void IntensifyColour();

	friend ostream& operator<<(ostream&, VectorGraphic&);
};

#endif