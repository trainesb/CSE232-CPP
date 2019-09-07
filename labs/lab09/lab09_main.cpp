#include <iostream>
using std::cout; using std::endl;
#include <string>
using std::string;
#include <cmath>
using std::sqrt; using std::pow;
#include "lab09_vector.h"

int main() {
	MathVector v, a,d,e;
	v.x=10;
	v.y=20;
	a.x=5;
	a.y=10;
	cout<<"v: "<<vec_to_str(v)<<endl;
	cout<<endl;
	d = v.add(a);
	cout<<"d: "<<vec_to_str(d)<<endl;
	cout<<endl;
	e = d.mult(2);
	cout<<"e: "<<vec_to_str(e)<<endl;
	cout<<endl;
}
