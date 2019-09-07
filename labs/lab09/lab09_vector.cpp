#include <iostream>
using std::cout; using std::endl;
#include <string>
using std::string;
#include <sstream>
using std::ostringstream;
#include <cmath>
using std::sqrt; using std::pow;

#include "lab09_vector.h"


string vec_to_str(const MathVector &v){
		ostringstream oss;
		oss<<v.x<<":"<<v.y;
		return oss.str();
}

MathVector::MathVector(long xx, long yy){
	x=xx;
	y=yy;
}



MathVector MathVector::add (const MathVector &v){
	auto x_add = x + v.x;
	auto y_add = y + v.y;
	return MathVector(x_add, y_add);
	
}

MathVector MathVector::mult(long n){
	auto x_mult = x*n;
	auto y_mult = y*n;
	return MathVector(x_mult, y_mult);
}

long MathVector::mult(const MathVector &v){
	long x_cross = (x*v.x)+(y*v.y);
	return x_cross;
}

double MathVector::magnitude(){
	double temp;
	temp = sqrt(pow(x,2)+pow(y,2));
	return temp;
}
