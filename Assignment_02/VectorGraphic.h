// VectorGraphic.h
#ifndef VECTORGRAPHIC
#define VECTORGRAPHIC

class VectorGraphic
{	
	GraphicElement** Elements;	// elements on the heap
	unsigned int numElements;	// how many
public:
	VectorGraphic():numElements(0),Elements(nullptr){}
	~VectorGraphic()
	{
		for (int i = 0; i < numElements; i++)
			delete Elements[i];
		delete[] Elements;
	}
	void AddGraphicElement();
	void DeleteGraphicElement();
	void ReportVectorGraphic();
	void EditGraphicElement();
	GraphicElement& operator[](int);
	friend ostream& operator<<(ostream&, VectorGraphic&);
};

#endif