
#include "splitter-functions.h"

void split(const string& s, vector<string>& v, char delim){
		string::size_type start=0;
		v.clear();
		auto pos = s.find(delim, start);
		while(pos != string::npos){
				v.push_back(s.substr(start, pos - start));
				start = pos+1;
				pos = s.find(delim, start);
		}
		if (start != s.size())
			v.push_back(s.substr(start));
}


void print_vector (ostream& out, const vector<string>& v){
	for(auto element: v){
		out<<element<<endl;
	}
}

