// Attributes.h

#ifndef ATTRIBUTES
#define ATTRIBUTES

class coloref
{
	unsigned char red;
	unsigned char green;
	unsigned char blue;
public:
	coloref() :red(0), green(0), blue(0){}
	coloref(unsigned char red,unsigned char green, unsigned char blue) :red(red), green(green), blue(blue){}
	coloref(coloref& c): red(c.red), green(c.green), blue(c.blue){}
	coloref& operator=(coloref& RCR);	
	void operator++();
	friend ostream& operator<<(ostream&, coloref&);
};

class texture
{
	string textureFileName;
	coloref bkgColour;
public:
	texture(){}
	texture(string s, coloref c = coloref()):textureFileName(s),bkgColour(c){}
	texture(texture& t):textureFileName(t.textureFileName),bkgColour(t.bkgColour){}
	void IntensifyColour(int);
	friend ostream& operator<<(ostream&, texture&);
};

class Point
{
	int x, y;
public:
	Point() :x(0), y(0){}
	Point(int x, int y) :x(x), y(y){}
	friend ostream& operator<<(ostream&, Point&);
};

#endif