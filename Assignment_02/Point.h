// Point.h
#ifndef POINT
#define POINT

class Point
{
	int x, y;
public:
	Point() :x(0), y(0){}
	Point(int x, int y) :x(x), y(y){}
	friend ostream& operator<<(ostream&,Point&);
};

#endif