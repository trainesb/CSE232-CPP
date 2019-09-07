#include<iostream>
using std::endl; using std::cout; using std::cin;
#include<string>
using std::string;
#include<algorithm>
using std::sort;
#include<cmath>
using std::pow;

long loc_to_dec(string loc){
	sort(loc.begin(), loc.end());
	int i, power=0, sum=0;
	int x=loc.length();
	for(i=0; i<x; i++){
			power = loc[i]-'a';
			sum += pow(2, power);
	}
	return sum;
}

string abbreviate(string loc){
		sort(loc.begin(), loc.end());
		char n;
		int i, new_letter;
		int x=loc.length();
		for(i=1; i<x; i++){
				n = loc[i-1];
				if(n==loc[i]){
						new_letter = loc[i]+1;
						loc[i]=new_letter;
						loc = loc.substr(0,(i-1))+loc.substr(i);
						i = 0;
				}
		}
		sort(loc.begin(), loc.end());
		return loc;
}

string dec_to_loc(long dec){
			int i;
			string str(dec,'a');
			str = abbreviate(str);
			return str;
}

long add_loc(string loc1, string loc2){
	string str;
	str = loc1 +loc2;
	str = abbreviate(str);
	return loc_to_dec(str);
}

int main(){
	string location;
	long num;
	cin>>location>>num;
	cout<<"new: "<<abbreviate(location)<<endl;
	cout<<loc_to_dec(location)<<" "<<abbreviate(location);
	cout<<" "<<dec_to_loc(num)<<" "<<add_loc(location, location)<<endl;
	
	
}
