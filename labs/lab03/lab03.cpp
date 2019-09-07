#include<iostream>
using std::cout; using std::cin; using std::endl;
#include<cmath>
using std::pow;
#include<iomanip>
using std::fixed; using std::setprecision;

double fn(double x){
		double answer;
		answer = -(6*pow(x,2))+(5*x)+3;
		return answer;
}

double integral(double x){
	double answer;
	answer = -(2*pow(x,3))+(2.5)*pow(x,2)+3*x;
	return answer;
}

double trapezoid(double a, double b, long n){
	double answer=0, distance, c, base;
	distance = (b-a)/n;
	c = a;
	base = ((b-a)/(2*n));
	while ((c) <= b){
		if (c == a || c == b){
			answer += base*fn(c);
		}
		else{
			answer += base*(2*fn(c));
		}
		c = c+distance;
	}
	return answer;

}


int main(){
	double answer, estimate, dif, tolerance, n;
	cin>>tolerance>>n;
	answer = integral(1)-integral(0);
	dif = answer - trapezoid(0,1,n);
	estimate = trapezoid(0,1,n);
	if(dif<=tolerance){
		cout<<fixed<<setprecision(6)<<n<<" "<<estimate<<" ";
		cout<<answer<<" "<<tolerance<<endl;
	}
	else{
		while(dif>tolerance){
			n = 2*n;
			dif = answer - trapezoid(0,1,n);
			estimate = trapezoid(0,1,n);
			continue;
		}
		cout<<n<<" "<<fixed<<setprecision(6)<<estimate<<" ";
		cout<<answer<<" "<<tolerance<<endl;	
	}
}
		

