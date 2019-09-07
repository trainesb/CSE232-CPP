/*
Project03
wfp 01/31/2018
Program is made up of five functions. the first is divisor_sum() which
takes one argument as a long.  the function finds all the divisors and
sums them, including the original number. The sum ir returned as a long.

The next function is gcd(), which finds the greatest common divisor of 
two numbers and returns it as a long.

The third function is the is_solitary() function.  Takes one number as 
a long and finds the divisor_sum(). It then finds the GCD of the number
and divisor_sum, if its one then the number is solitary and true is
returned, otherwise false is returned

The fourth function is the friendly_check() which takes two arguments.
The first argument is a check and the second is an upper limit.  The 
function finds the abundancy index of the check number and then also of
every number from 2 to the limit.  If the number has the same abundancy
index, numerator, and deonominator then the number is a friendly number
to the check.  The function returns the numerator, denominator, and 
friendly number if there is one or -1 instead to abIndex_friend() 

The abIndex_friend() function takes three arguments gained from 
friendly_check().  It puts them in the correct format and returns a
string.
*/

#include<iostream>
using std::cout; using std::cin; using std::endl; using std::boolalpha;
#include<cmath>
#include<string>
using std::to_string; using std::string;

string abIndex_friend(long ab_numerator, long ab_denominator, long f_pair){
  return to_string(ab_numerator) + "/" + to_string(ab_denominator) +
    ":" + to_string(f_pair);
}


long divisor_sum(long n){
	long sum=0;
	for(int i=1; i<=n; i++){
			if(n%i==0){
					sum += i;
			}
	}
	return sum;
}

long gcd(long a, long b){
		long out;
		for(int i=1; i<=a&&i<=b;i++){
				if(a%i==0 && b%i==0)
					out=i;
		}
		return out;
}

bool is_solitary(long num){
		long num_devisor_sum, check;
		num_devisor_sum = divisor_sum(num);
		check = gcd(num, num_devisor_sum);
		if(check==1)
			return true;
		else
			return false;
}

string friendly_check(int check, int upper){
		long ratio_check, gcd_check, gcd_i, ratio_i, num, denom;
		long other_num, other_denom, other;
		gcd_check = gcd(divisor_sum(check),check);
		ratio_check = (divisor_sum(check)/gcd_check)/(check/gcd_check);
		other_num = (divisor_sum(check)/gcd_check);
		other_denom = (check/gcd_check);
		for(int i=2; i<=upper; i++){
				gcd_i = gcd(divisor_sum(i),i);
				ratio_i = (divisor_sum(i)/gcd_i)/(i/gcd_i);
				num = (divisor_sum(i)/gcd_i);
				denom = (i/gcd_i);
				if(ratio_i == ratio_check){
					if(num == other_num){
							if(denom == other_denom){
								if(i!=check)
									return abIndex_friend(num, denom, i);
							}
					}
				}
		}
		other = -1;
		return abIndex_friend(other_num, other_denom, other);
}

int main(){
	long a=114, b=1000;
	cout<<endl;
	cout<<endl;
	cout<<"friendly_check: "<<friendly_check(a,b)<<endl;
	cout<<endl;
	
}
