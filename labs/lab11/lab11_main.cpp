#include<iostream>
using std::cout; using std::endl; using std::cin;
#include<fstream>
using std::ifstream;
#include<string>
using std::string; using std::stoi;
#include<sstream>
using std::getline; using std::istringstream; using std::ostringstream;
#include<list>
using std::list; using std::next;
#include<stdexcept>
using std::runtime_error;


#include "lab11_arrays.h"

size_t fill_from_file(long* (& ary), string f_name){
	
	ifstream in_file (f_name);
	int array_size;
	if(in_file.is_open()){
		//first line in file is array_size
		in_file >> array_size;
		cout<<"array size: "<<array_size<<endl;
		//initialize array size
		ary = new long[array_size];
		//fill array with remaing ints in_file
		for(int i=0; i < array_size; ++i){
			in_file >> ary[i];
		}
	}
	//if file doesn't exist, throw runtime error
	else{
		throw runtime_error("Error");
	}
	return array_size;
}

void print_array(long ary[], size_t sz, ostream& out){
	ostringstream oss;
	for(auto i=0; i < sz; ++i){
		oss<<ary[i]<<' ';
	}
	oss<<endl;
	out<<oss.str()<<endl;
}

int main(){
    long *ary;
    long ary2[] ={10,11,12,13,14};
    size_t ary2_sz = 5;

    print_array(ary2, ary2_sz, cout);
    cout << endl;
    
    size_t sz_file = fill_from_file(ary, "tables.txt");
    print_array(ary, sz_file, cout);
    cout << endl;
    
    //size_t sz_concat = concatenate(ary, sz_file, ary2, ary2_sz);
    //print_array(ary, sz_concat, cout);
    //cout << endl;
    
    //pair<long*, size_t> p = copy_evens(ary, sz_concat);
    //print_array(p.first, p.second, cout);
    //cout << endl;
    // add code to delete dynamic memory after this
    delete [] ary;
    //delete [] p.first;
}
