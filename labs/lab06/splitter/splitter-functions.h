
#ifndef SPLITTER_FUNCTION_H
#define	SPLITTER_FUNCTION_H
#include<string>
using std::string; using std::getline;
#include<vector>
using std::vector;
#include<vector>
#include<string>
using std::vector;
using std::string;
#include<iostream>
using std::ostream; using std::endl;


void split(const string &s, vector<string> &v, char delim=' ');

void print_vector (ostream &out, const vector<string> &v);

#endif	/* SPLITTER-FUNCTION_H */
