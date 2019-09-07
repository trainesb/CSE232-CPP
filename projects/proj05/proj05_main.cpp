#include<string>
using std::string;
#include<iostream>
using std::endl; using std::cout; using std::cin;

#include "proj05_functions.h"

int main(){
	string s="Test String";
	cout<<"Pre: "<<s<<endl;
	cout<<"Post: "<<clean_string(s)<<endl;
	
}
