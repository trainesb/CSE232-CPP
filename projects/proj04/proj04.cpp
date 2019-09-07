/*
Project04
wfp 02/10/2018
 
This project is made up of five functions and a main. The first function
reverse_string(), takes a string adn will reverse it from back to front 
and return it as a string
* 
The second function is_palindrome, takes a string argument and reverses 
the string. if the original and reversed strings are the same then the 
string is a palindrome and true is returned
* 
The third function id long_to_base(), which takes two arguments a long
to convert, and the base you want to convert it to.
* 
The fourth function is the is_prime() function that takes a long 
argument and returns true of the long is only divisible by one and 
itself otherwise it returns false
* 
The last function is the is_pal_prime(), which takes a long argument, 
and returns if the long is both prime and palindome in binary, decimal,
and hexa, or not at all.
*/
#include<iostream>
using std::cout; using std::cin; using std::endl; using std::boolalpha;
#include<string>
using std::string; using std::to_string;
#include<algorithm>
using std::reverse;
#include<cmath>

const string the_chars = "0123456789abcdef";

string reverse_string(string var){
	reverse(var.begin(),var.end());
	return var;
}

bool is_palindrome(string str){
	string str2 = reverse_string(str);
	if(str == str2)
		return true;
	else
		return false;
}

string long_to_base(long n, long base){
	string result;
	long remainder;
	while(n > 0){
		remainder = n % base;
		result += the_chars[remainder];
		n = n / base;
	}
	result = reverse_string(result);
	return result;
}

bool is_prime(long n){
	for(int i=1; i<=n; i++){
		if(n%i==0){
			if(i==1)
				continue;
			else if(i==n)
				continue;
			else
				return false;
		}
	}
	return true;	
}

string is_pal_prime(long n){
	string binary, decimal, hexa, result;
	bool bpal, dpal, hpal, prime;
	//string
	binary = long_to_base(n, 2);
	decimal = long_to_base(n, 10);
	hexa = long_to_base(n, 16);	
	
	//is pal
	bpal = is_palindrome(binary);
	dpal = is_palindrome(decimal);
	hpal = is_palindrome(hexa);
	
	//is prime
	prime = is_prime(n);

	if(prime){
		//binary-pal-prime
		if(bpal)
			result +="binary-pal-prime";
		//decimal-pal-prime
		else if(dpal)
			result +="decimal-pal-prime";
		//hex-pal-prime
		else if(hpal)
			result +="hex-pal-prime";
	}
	//not-pal-prime
	else
		return "not-pal-prime";
	return result;
	
}


int main(){
	cout<<boolalpha;
	cout<<endl;
	cout<<"long_to_base: "<<long_to_base(123, 2)<<endl;
	cout<<endl;
	
}
