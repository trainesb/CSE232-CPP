#ifndef VECOPS_H
#define	VECOPS_h
#include<string>
using std::string;
#include<vector>
using std::vector; using std::size_type;
#include<iostream>
using std::ostream; using std::endl;

vector<long> vector_ops(const vector<long>& v1, const vector<long>& v2,
						char op);
void print_vector (ostream &out, const vector<long> &v);

#endif	/* VECOPS_H */
