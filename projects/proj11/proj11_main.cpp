#include<iostream>
using std::cout; using std::endl; using std::boolalpha;
#include<string>
using std::string;
#include<sstream>
using std::ostringstream;

#include "proj11_mapset.h"

int main (){
	cout << boolalpha;


	MapSet<string,long> m({ {"bill",1},{"alan",22},{"abby",3} });
	cout<<"m: "<<m<<endl;
	
	MapSet<string,long> m1({ {"collin",99}, {"ben",12}, {"zack", 12}, {"sww",21} });
	cout<<"m1: "<<m1<<endl;

	MapSet<string,long> m2({ {"bill",100},{"alan",2},{"collin",12}, {"b",12}, {"zack", 192}, });
	cout<<"m2: "<<m2<<endl;
	
	
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
/*
	cout<<endl<<endl<<endl<<"intersection m.intersect(m)"<<endl;
	MapSet<string,long> in = m.mapset_intersection(m);
	cout<<endl<<endl<<endl<<"in: "<<in<<endl;
	
	cout<<endl<<endl<<endl<<"intersection m.intersect(m1)"<<endl;
	MapSet<string,long> in1 = m.mapset_intersection(m1);
	cout<<endl<<endl<<endl<<"in1: "<<in1<<endl;
	*/
	cout<<endl<<endl<<endl<<"intersection m.intersect(m2)"<<endl;
	MapSet<string,long> in3 = m.mapset_intersection(m2);
	cout<<endl<<endl<<endl<<"in3: "<<in3<<endl;
/*
	cout<<endl<<endl<<endl<<"intersection m1.intersect(m)"<<endl;
	MapSet<string,long> in4 = m1.mapset_intersection(m);
	cout<<endl<<endl<<endl<<"in4: "<<in4<<endl;
	
	cout<<endl<<endl<<endl<<"intersection m1.intersect(m1)"<<endl;
	MapSet<string,long> in5 = m1.mapset_intersection(m1);
	cout<<endl<<endl<<endl<<"in5: "<<in5<<endl;
	
	cout<<endl<<endl<<endl<<"intersection m1.intersect(m2)"<<endl;
	MapSet<string,long> in6 = m1.mapset_intersection(m2);
	cout<<endl<<endl<<endl<<"in6: "<<in6<<endl;
	
	cout<<endl<<endl<<endl<<"intersection m2.intersect(m)"<<endl;
	MapSet<string,long> in7 = m2.mapset_intersection(m);
	cout<<endl<<endl<<endl<<"in7: "<<in7<<endl;
	
	cout<<endl<<endl<<endl<<"intersection m2.intersect(m1)"<<endl;
	MapSet<string,long> in8 = m2.mapset_intersection(m1);
	cout<<endl<<endl<<endl<<"in8: "<<in8<<endl;
	
	cout<<endl<<endl<<endl<<"intersection m2.intersect(m2)"<<endl;
	MapSet<string,long> in9 = m2.mapset_intersection(m2);
	cout<<endl<<endl<<endl<<"in9: "<<in9<<endl;
*/

}
