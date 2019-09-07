/* project08
 * 
 * Market is a structure that reads a file and populates a map with the
 * key as the date, and the value is a vector of prices.
 * 
 * get_price takes a date and a stock name as a parmater. It searches
 * the map if the date exits and the stock. If they do it reutrns the
 * stocks price, otherwise it returns -1.0
 * 
 * high_low_year() takes a year and a stock. It searches the map for all
 * the years that match the input and finds the highest and lowest price
 * for the stock durign that year. It returns a pair {high,low} or 
 * {-1.0,-1.0} if there is an error. 
 */

#include<map>
using std::map;
#include<vector>
using std::vector;
#include<string>
using std::string; using std::to_string;
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

Market::Market(string s){
	ifstream in_file (s);
	string line, word;
	long date;
	double price;
	//map<long, vector<double>> stocks;
	
	while(getline(in_file, line)){
		istringstream iss(line);
		iss>>date;
		//cout<<"date: "<<date<<endl;
		iss>>price;
		//cout<<"price: "<<price<<endl;
		stocks.insert(pair<long, vector<double>>(date, 
								vector<double>()));
				
		stocks[date].push_back(price);
			while(iss>>price){
				stocks[date].push_back(price);
			}
	}
	
	/*for(map<long, vector<double>>::iterator ii=stocks.begin();
								ii!=stocks.end(); ++ii){
		cout<<(*ii).first<<": ";
		vector<double> v = (*ii).second;
		for(unsigned j=0; j<v.size(); j++){
			cout<<v[j]<<" ";
		}	
		cout<<endl<<endl;
	} */

}


double Market::get_price(string stock, long date) const{
	
	//if date is valid
	auto d = stocks.find(date);
	if( d != stocks.end()){
		
		//if Stock is valid
		auto i = find(symbol_list.begin(), symbol_list.end(), stock);
		if( i != symbol_list.end()){
			auto pos = distance(symbol_list.begin(), i);
			//cout<<"found stock in symbol_list: "<< *i <<" : "<< pos<< endl;
		
			//return price of stock
			auto price = stocks.at(date).at(pos);
			//cout<<"date: "<<date<<" stock: "<<stock<<" price: "<<price<<endl;
			return price;
		}
		//if Stock not valid
		else {
			return -1.0;
		}
	}
	//date is not valid
	else{
		return -1.0;
	}
	
}

pair<double, double> Market::high_low_year(long year, string symbol){
	pair<double, double> result;
	double hprice = 0, lprice=100, price, cnt=0;
	for(map<long, vector<double>>::iterator ii=stocks.begin();
								ii!=stocks.end(); ++ii){
		string date = to_string((*ii).first);
		date = date.substr(0, 4);
		string syear = to_string(year);
		//collect all dates that match year
		if(date==syear){
			cnt = 1;
			vector<double> v = (*ii).second;
			//if Symbol is valid
			auto i = find(symbol_list.begin(), symbol_list.end(), symbol);
			if( i != symbol_list.end()){
				auto pos = distance(symbol_list.begin(), i);
				//cout<<"found stock in symbol_list: "<< *i <<" : "<< pos<< endl;
				//cout<<"Stock: "<<symbol<<" Price: "<<v[pos]<<endl;
				price = v[pos];
				if(price > hprice){
					hprice = price;
				}
				if(price < lprice){
					lprice = price;
				}
				
			}
			//symbol not found
			else{
				result = {-1.0,-1.0};
				return result;
			}
		}
	}
	
	//if date doesn't exist
	if(cnt==0){
		result = {-1.0,-1.0};
		return result;
	}
	
	//cout<<"Date: "<<year<<" hprice: "<<hprice<<" lprice: "<<lprice<<endl;
	result = {hprice, lprice};
	//cout<<result.first<<" : "<<result.second<<endl;
	return result;
}


