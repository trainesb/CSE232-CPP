#include<iostream>
using std::cout; using std::endl; using std::boolalpha;
#include<string>
using std::string;
#include<sstream>
using std::ostringstream;

#include "proj10_mapset.h"

int main (){
	cout << boolalpha;
	MapSet<string,long> ms1({ {"bill",1},{"alan",2},{"abby",3} });
	cout<<"ms1: "<<ms1<<endl;
	MapSet<string,long> ms2({ {"alan",4},{"abby", 5},{"john",7} });
	cout<<"ms2: "<<ms2<<endl;
	MapSet<string,long> ms3({ {"abby",5}, {"alan",17} });
	cout<<"ms3: "<<ms3<<endl;

	cout<<"ms1.Mapset_union(ms2)"<<endl;
	MapSet<string, long> ms_union = ms1.mapset_union(ms2);
	cout<<"ms_union: "<<endl;
	
	cout<<"ms2.mapset_union(ms1): "<<endl;
	ms_union = ms2.mapset_union(ms1);
	cout<<"ms_union done"<<endl;
	
  
}

