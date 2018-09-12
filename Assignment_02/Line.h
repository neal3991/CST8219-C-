// Line.h
#ifndef LINE
#define LINE

class Line
{
	Point start;
	Point end;
public:
	Line() :start(), end(){}
	Line(Point start, Point end) :start(start), end(end){}
	friend ostream& operator<<(ostream&, Line&);
};

#endif