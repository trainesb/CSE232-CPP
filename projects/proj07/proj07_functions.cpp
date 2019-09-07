#include <iostream>
using std::endl; using std::cout; using std::cin; using std::ostream;
using std::boolalpha;
#include <map>
using std::map;
#include <string>
using std::string; using std::getline; using std::stol;
#include <vector>
using std::vector;
#include <set>
using std::set;
#include <algorithm>
using std::set_union; using std::set_intersection; using std::set_difference;
using std::transform; using std::copy; using std::copy_if;
#include <fstream>
using std::ifstream;
#include <sstream>
using std::ostringstream;
#include <utility>
using std::pair; using std::make_pair;
#include <iterator>
using std::ostream_iterator;

template<typename k, typename v>
string pair_to_string(pair<k,v> p){
	ostringstream oss;
	oss << p.first <<": ";
	for(auto elem: p.second)
		oss<< elem<<" ";
	return oss.str();
}

template<typename k, typename v>
void print_map( map<k, v>& m){
	transform(m.begin(), m.end() ,ostream_iterator<string>(cout, ", "),
	pair_to_string<k,v>
	);
}

template<typename T>
string set_to_string(set<T>& s){
	ostringstream oss;
	for(auto element: s)
		oss << element <<", ";
	string result = oss.str();
	return result;
}


bool AddConnection(map<string, set<string>> &sd, string sn, string un){
	for(pair<string, set<string>> element : sd){
		cout << pair_to_string(element )<<", ";
	}
	cout<<endl;
	cout<<endl;
	print_map(sd);
	cout<<endl;
	
	map<string, set<string>>::iterator itr;
	itr = sd.find(sn);
	
	/*if key is in map */
	if (itr != sd.end()){
		for(pair<string, set<string>> element : sd){
			for(auto elem: element.second){
				if(elem == un){
					return false;
				}
			}
		}
		pair<set<string>::iterator, bool> result;
		pair<string, set<string>> element =*(itr);
		result = element.second.insert(un);
		if(result.second){
			cout<<"succseful: "<<endl;
			print_map(sd);
			result = element.second.insert(un);
		}
		
	}
	
	
	/*if key is not in the map*/
	else{
		set<string> n = {un};
		sd[sn]=n;
		return true;
	}
	print_map(sd);
}


bool DeleteConnection(map<string, set<string>> &sd, string sn, string un){
	map<string, set<string>>::iterator iter;
	map<string, set<string>>::iterator itr;
	itr=sd.find(un);
	if(itr != sd.end()){
		return false;
	}
	for(itr=sd.begin();iter!=sd.end();){
		if(itr->first==un)
			itr=sd.erase(itr);
	}
	return true;
}



int main(){
	map<string, set<string>> sd{ {"Rusty", {"Ben", "Boo", "Brian"}},
								{"Ann", {"Cassiy", "Sawyer", "collin"}}};
								
	string sn = "Ann";
	string un = "Ben";
	AddConnection(sd, sn, un);
}



 
