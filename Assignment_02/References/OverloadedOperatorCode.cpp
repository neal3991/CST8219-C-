//: C12:OperatorOverloadingSyntax.cpp extended
// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
#include <iostream>
using namespace std;

class Integer {
public:
	int i;
	//Integer():i(0){}	// not needed
	Integer(int ii=0) : i(ii) {} // default argument makes default constructor
	
	Integer operator+(const Integer& rv) const 
	{
		cout << "operator+" << endl;
		cout << "this->i = " <<i<< endl;
		cout << "rv.i = " << rv.i << endl;
		return Integer(i + rv.i);
	}

	Integer& operator+=(const Integer& rv) 
	{
		cout << "operator+=" << endl;
		cout << "this->i = " <<i<< endl;
		cout << "rv.i = " << rv.i << endl;
		i += rv.i;
		return *this;
	 }
};

int main() {
  cout << "**** built-in types****" << endl;
  int i = 1, j = 2, k = 3;
  j += i + k;
  cout<<"j = "<<j<<endl;
  //cout<<"***************"<<endl;
  cout <<endl<<"***** user-defined types *****"<< endl;
  Integer ii(1), jj(2), kk(3), ll;
  
  cout <<endl<< "***** Add plus Add with assign ******"<<endl;
  jj += ii + kk;
  cout<<"From  jj += ii + kk;   jj.i = "<<jj.i<<endl;
  jj.operator+=(ii.operator+(kk));
  cout << "From  jj.operator+=(ii.operator+(kk));   jj.i = " << jj.i << endl;
  cout <<endl<< "***** End Add plus Add with assign ******"<<endl;

  cout <<endl<< "***** Chaining *****"<<endl;
  ll += kk += ii + jj + kk; 
  cout << " Finally the output: " <<endl;
  cout<<"ll.i = "<<ll.i<<endl;
  cout << "***** End Chaining *****"<<endl;
  
  cout << endl << " ***** Even More *****" << endl;
  cout<<"answer = "<<(ll=jj+(kk += ii + jj)).i<<endl;
  cout<<endl<<"..and with casting: "<<endl;
  ll=ii+jj+kk+=(Integer)k+kk;
 
  cout<<"ll.i ="<<ll.i<<endl;
  
} ///:~



OUTPUT

**** built-in types****
j = 6

***** user-defined types *****

***** Add plus Add with assign ******
operator+
this->i = 1
rv.i = 3
operator+=
this->i = 2
rv.i = 4
From  jj += ii + kk;   jj.i = 6
operator+
this->i = 1
rv.i = 3
operator+=
this->i = 6
rv.i = 4
From  jj.operator+=(ii.operator+(kk));   jj.i = 10

***** End Add plus Add with assign ******

***** Chaining *****
operator+
this->i = 1
rv.i = 10
operator+
this->i = 11
rv.i = 3
operator+=
this->i = 3
rv.i = 14
operator+=
this->i = 0
rv.i = 17
 Finally the output:
ll.i = 17
***** End Chaining *****

 ***** Even More *****
operator+
this->i = 1
rv.i = 10
operator+=
this->i = 17
rv.i = 11
operator+
this->i = 10
rv.i = 28
answer = 38

..and with casting:
operator+
this->i = 3
rv.i = 28
operator+
this->i = 1
rv.i = 10
operator+
this->i = 11
rv.i = 28
operator+=
this->i = 39
rv.i = 31
ll.i =70
Press any key to continue . . .