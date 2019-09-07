#include<string>
using std::string;
#include "lab08_functions.h"
/*
  input is a positive (1 or greater) integer
  returns the next collatz number
  if number is 0 or less, throws range_error;
 */

long collatz_next(long n){
	int next;
	if(n%2==0){
		next = n/2;
	}
	else{
		next = (3*n)+1;
	}
	if(n<=0){
		throw 0;
	}
	return next;

}

/*
  input is a Collatz pair (pair<long, vector<long > >)
  output is a string of the format
     number: sequence (comma separated) ending in 1
     no trailing comma
*/
string Collatz_to_string(const Collatz &p){
	string k, v, s;
	k=p.first;
	v=p.second;
	s=k+","+v;
	return s;
}

/*
  input is a collatz map (map<long, vector<long> >)and a long
  if the number exists as a key in the map
     returns the Collatz_to_string of that pair
  otw returns an empty string
*/
string sequence_in_map_to_string(map<long, vector<long> > &m, long number){
	
}
