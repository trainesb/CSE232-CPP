/*
 * Project 08
 * 
 * Bool player.buy() checks the player if they have enough cash and if the
 * stock and date exists.  It then finds the price and updates the 
 * players stocks.
 * 
 * bool player.sell() checks the players stocks if they have the stock
 * and correct ammount to sell. If they do then the player's stocks are 
 * updated along with their cash
 * 
 * player.to_str() takes the players cash and stocks and prints them in 
 * a user friendly way.
 * 
 * player.combine() takes two players stocks and cash and combines them
 * making a new player.
 */

#include<string>
using std::string; 
#include<iostream>
using std::cout; using std::endl; 
#include<sstream>
using std::ostringstream;
#include<algorithm>
using std::transform;
#include<iomanip>
using std::setprecision; using std::fixed;

#include "proj08_market.h"
#include "proj08_player.h"

bool Player::buy(Market &m, string stock, long date, long quantity){
	double price;
	//valid stock
	//if Stock is valid
	price = m.get_price(stock, date);
	if(price != -1.0){
	
		//has enough cash for purchase
		
		price = price*quantity;
		if(cash > price){
			//cout<<"true, Price: "<<price<<" Cash: "<<cash<<endl;
			cash -= price;
			//cout<<"new cash: "<<cash<<endl;
			stocks[stock] += quantity;
		
			/*for(auto ii=stocks.begin(); ii!=stocks.end(); ++ii){
			cout<<(*ii).first<<": "<<(*ii).second;
			cout<<endl<<endl;
			} */
		
			return true;
		
		}
		//Doesn't have enough cash
		else{
			//cout<<"false, Price: "<<price<<" Cash: "<<cash<<endl;
			return false;
		}
	}
	//stock doesn't exist
	else{
		return false;
	}
}

bool Player::sell(Market &m, string stock, long date, long quantity){
	//has stock to sell
	long owne;
	double price;
	if(stocks.count(stock)){
		//cout<<"has stock to sell"<<endl;
		//has quantity indicated
		owne = stocks[stock];
		if(owne >= quantity){
			price = m.get_price(stock, date);
			if(price != -1.0){
				price = price*quantity;
				cash += price;
				stocks[stock] -= quantity;
				return true;
			}
			else{
				return false;
			}
		}
		
	}
	return false;
}

string Player::to_str(){
	ostringstream oss;
	oss<<fixed<<setprecision(2)<<cash<<",";
	for(auto ii=stocks.begin(); ii!=stocks.end(); ++ii){
		oss<<(*ii).first<<":"<<setprecision(2)<<(*ii).second<<",";
	}
	string s = oss.str();
	int i = s.length()-1;
	string a = s.substr(0, i);
	return a;
}

Player Player::combine(Player &p2){
	
	cash = cash + p2.cash;
	Player new_player(cash);
	//cout<<"cash: "<<cash<<endl;
	for(auto& it: p2.stocks){
		//cout<<it.first<<" : "<<it.second<<endl;
		new_player.stocks[it.first]+=it.second;
		for(auto& i: stocks){
			//cout<<i.first<<" : "<<i.second<<endl;
			new_player.stocks[i.first]+=i.second;
		}
	}
	cash = 0;
	p2.cash = 0;
	stocks.clear();
	p2.stocks.clear();
	//cout<<"clear: "<<to_str()<<endl;
	//cout<<"p2: "<<p2.to_str()<<endl;
	return new_player;
	
	
}
