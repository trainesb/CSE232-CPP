#include<map>
using std::map;
#include<vector>
using std::vector;
#include<string>
using std::string;
#include<utility>
using std::pair;
#include<iostream>
using std::cout; using std::endl; 
#include<fstream>
using std::ifstream; using std::ofstream;
#include<sstream>
using std::getline; using std::istringstream; using std::ostringstream; 
#include<iterator>
using std::ostream_iterator;
#include<algorithm>
using std::transform; using std::find; using std::distance;


#include "proj08_market.h"
#include "proj08_player.h"

int main(){
	Market my_mrkt("dow.txt");
	Player my_player(1000);
	Player p2(1000);
	my_player.buy(my_mrkt, "AA", 20120831, 5);
	my_player.buy(my_mrkt, "AXP", 20120831, 5);
	p2.buy(my_mrkt, "BA", 20120831, 10);
	cout<<"p1: "<<my_player.to_str()<<endl;
	cout<<"p2: "<<p2.to_str()<<endl;
	auto p = my_player.combine(p2);
	cout<<"new p1: "<<my_player.to_str()<<endl;
	string s = p.to_str();
	cout<<endl;
	cout<<"s: "<<s<<endl;
	
	
	
}
