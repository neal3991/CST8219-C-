//: C12:IostreamOperatorOverloading.cpp extended
// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
// Example of non-member overloaded operators
//#include "../require.h"
#include <iostream>
#include <sstream> // "String streams"
#include <cstring>
using namespace std;

char q;

class IntArray {
  enum { sz = 5 };
  int i[sz];
public:
  IntArray() { memset(i, 0, sz* sizeof(*i)); }
  int& operator[](int x) {
     return i[x];
  }
  friend ostream&  operator<<(ostream& os, IntArray& ia);
  friend istream&  operator>>(istream& is, IntArray& ia);
};

ostream& operator<<(ostream& os, IntArray& ia) {
  for(int j = 0; j < ia.sz; j++) {
    os << ia.i[j];	// OK, this is the primitive way.
//  os << ia[j];	// Better, now we have overloaded indexing.
    if(j != ia.sz -1)
      os << ", ";
  }
  os << endl;
  return os;
}

istream& operator>>(istream& is, IntArray& ia){
  for(int j = 0; j < ia.sz; j++)
   // is >> ia.i[j];	// OK, this is the primitive way.
	is >> ia[j];	// Better, now we have overloaded indexing.
  return is;
}

int main() {
	// stringstream input("47 34 56 92 103");
	IntArray I, J;
	cin >> I >> J;			// chained input
	cout << I <<  J;		// chained output	
	cout << "**************************************************" << endl;
	I[4] = -1;				// Use overloaded operator[] - returns an l-value
	J[0] = 99;
	cout << I <<  J;
	cout << "**************************************************" << endl;
	I[0] = I[4];			// a returned r-value assigned to a returned l-value
	J[0] = I[1] = J[2];		// chained indexing
	cout << I <<  J;
	cout << "**************************************************" << endl;
	
	cout << endl << " The same code using explicit functions" << endl;
	operator>>(operator>>(cin, I), J);
	operator<<(operator<<(cout, I), J);
	cout << "**************************************************" << endl;	
	I.operator[](4) = -1;
	J.operator[](0) = 99;
	operator<<(operator<<(cout, I), J);
	cout << "**************************************************" << endl;	
	I.operator[](0) = I.operator[](4);	// a returned r-value assigned to a returned l-value
	J.operator[](0) = I.operator[](1) = J.operator[](2);		// chained indexing
	operator<<(operator<<(cout, I), J);	
	cout << "**************************************************" << endl;
	  
  	cin>>q;
} ///:~

/*
OUTPUT

0
1
2
3
4
5
6
7
8
9
0, 1, 2, 3, 4
5, 6, 7, 8, 9
**************************************************
0, 1, 2, 3, -1
99, 6, 7, 8, 9
**************************************************
-1, 7, 2, 3, -1
7, 6, 7, 8, 9
**************************************************

 The same code using explicit functions
0
1
2
3
4
5
6
7
8
9
0, 1, 2, 3, 4
5, 6, 7, 8, 9
**************************************************
0, 1, 2, 3, -1
99, 6, 7, 8, 9
**************************************************
-1, 7, 2, 3, -1
7, 6, 7, 8, 9
**************************************************
*/