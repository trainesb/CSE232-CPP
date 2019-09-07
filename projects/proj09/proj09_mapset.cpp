/*
 * Project09 4/8/2018
 * 
 * Program desinges a class, MapSet and following methods
 * 
 * find_key(key), takes a key and returns an itr to where that key is in\
 * the MapSet. If its not in the MapSet the itr returns v_.end()
 * 
 * The Constructor, constructs the class using an initializer_list
 * of pairs.  usess the add method to add to the MapSet vector
 * 
 * Size() returns how many pairs are in the MapSet vector
 * 
 * get(key) returns a pair of from the MapSet with the key, if key isn't
 * in MapSet, method returns defult pair {"",0}
 * 
 * update(key, value) looks in the MapSet if the key is already in it.
 * If it is then it updates the value with the new value. If the key 
 * isnt in MapSet ignore and return False
 * 
 * remove(key) if the key is in MapSet, then remove the pair and return
 * true, else do nothign and return false
 * 
 * add(key, value)  if the key is in the MapSet, nothing happens and
 * false is returned. Otherwise creates pair<key,value> and adds it to 
 * MapSet
 * 
 * compare( MapSet) compares the keys of two maps. upon the first 
 * differnce, if v_->first is > then MapSet.v_->first; return 1, 
 * otherwise -1.  If no differences and one is shorter, then; 
 * size() > MapSet.size(); return 1, else -1
 * 
 * mapset_union(MapSet) takes two MapSets, adds all the elements of
 * both into a new MapSet and returns it.  If the ke is the same, but 
 * value diffrent, then use the v_->second value.
 * 
 * mapset_intersection(MapSet) takes two MapSets and returns a new 
 * MapSet with the common elements. If keys are the same but values are
 * diffrent, then use the v_->second value
 * 
 * ostream& operator<<(out, MapSet) Is an overloaded Operator, so that
 * when '<<' is used in cout stamtents, it will be able to print the 
 * MapSet
 */


#include<iostream>
using std::ostream; using std::cout; using std::endl;
#include<string>
using std::string; 
#include<vector>
using std::vector;
#include<utility>
using std::pair; using std::make_pair;
#include<initializer_list>
using std::initializer_list;
#include<algorithm>
using std::lower_bound;
#include<limits>
using std::numeric_limits;
#include<iterator>
using std::distance;


#include "proj09_mapset.h"


vector< pair <string, long> >::iterator MapSet::find_key(string key){
	/*returns an iterator to the pair<string, long> pointing to the 
	  first pair in the vector that >= key (by key), or v.end(). 
	  
	   lower_bound returns an iterator to the first element in a 
	   container that is >= the search value provided.
	   Container elementts must be in sorted order. */
	 
	 auto i = lower_bound(v_.begin(),v_.end(), 
				make_pair(key, numeric_limits<long>::min()));
	 //cout<<"FIND_KEY FUNCTION: ";
	 //if(i != v_.end())
		//cout<<"i: "<<i->first<<endl;
	 return i;
} 


MapSet::MapSet(initializer_list< pair<string,long> > list){
	//Place each pair in initializaer_list in v_
	/*initializer_list doesn't have to be sorted but v_ does after all
	elements are added (use add)*/
	for(auto i=list.begin(); i != list.end(); i++){
		string key = i->first;
		long value = i->second;
		auto p = make_pair(key,value);
		/*cout<<endl;
		cout<<"ctor: "<<endl;
		cout<<"Key: "<<key<<" Value: "<<value<<endl;
		cout<<"p: "<<p.first<<" : "<<p.second<<endl;	*/
		add(p);
		
	}
	
}


bool MapSet::add(pair<string,long> p){
	//string = key, if its in v_ do nothing and return false
	//else create a pair, and insert into v_ in sorted order, return T
	
	string key = p.first;
	long value = p.second;
	//cout<<"ADD FUNCTION"<<endl;
	//cout<<"key: "<<key<<" Value: "<<value<<endl;
	//cout<<"find_key("<<key<<")"<<endl;
	
	
	auto itr = find_key(key);
	

	//key is in v_
	if(itr != v_.end()){
		string name = itr->first;
		if(name == key){
			return false;
		}
		else{
			v_.insert(itr, make_pair(key,value));
			//for(auto itr = v_.begin(); itr != v_.end(); itr++){
				//cout<<"(add fn) v_: "<<itr->first<<" : "<<itr->second<<endl;
			//}
			//cout<<endl;
			return true;
		}
	}
	
	//key isn't in v_
	else{
		//cout<<"(add function) add key"<<endl<<endl;;
		v_.insert(itr, make_pair(key,value));
		//for(auto itr = v_.begin(); itr != v_.end(); itr++){
			//cout<<"(add fn) v_: "<<itr->first<<" : "<<itr->second<<endl;
		//}
		//cout<<endl;
		return true;
	}
	
	
}

size_t MapSet::size(){
	//number of pairs
	//cout<<"!!!!!!SIZE FUNCTION!!!!!!: "<<endl;
	size_t s = v_.size();
	//cout<<"size: "<<s<<endl<<endl;
	/*cout<<"    v_    "<<endl;
	for(auto itr = v_.begin(); itr != v_.end(); itr++){
		cout<<"v_: "<<itr->first<<" : "<<itr->second<<endl;
	}*/
		
	return s;
}

pair<string,long> MapSet::get(string key){
	//return a copy of pair that has string as key
	//or defualt {"",0}
	//cout<<endl<<"GET FUNCTION"<<endl;
	string k = "";
	long v = 0;
	auto itr = find_key(key);
	//key is in v_
	if(itr != v_.end()){
		k = itr->first;
		v = itr->second;
		auto p = make_pair(k,v);
		//cout<<"get pair: "<<p.first<<" : "<<p.second<<endl;
		return p;
	}
	//key not in v_
	else{
		auto p = make_pair(k,v);
		//cout<<"get no pair: "<<endl;
		//cout<<"pair: "<<p.first<<" : "<<p.second<<endl;
		return p;
	}
}

bool MapSet::update(string key,long value){
	//string = key, if key in v_; update pair to the value of the long
	//if key not in v_; do nothing and return False, otherwise True
	//cout<<endl<<"Update Function: "<<endl;
	auto itr = find_key(key);
	//key is in v_
	if(itr != v_.end()){
		string k = itr->first;
		//long v = itr->second;
		//cout<<"key in v_, update..."<<endl;
		//cout<<"key: "<<k<<" Value: "<<v<<endl;
		itr->second = value;
		
		//cout<<"Updated pair to be added: "<<itr->first<<" : "<<itr->second<<endl;
		return true;
	}
	//key not in v_
	else{
		//cout<<"key not in v_ "<<endl;
		return false;
	}
}

bool MapSet::remove(string key){
	//if key is in v_; remove the pair and return true
	//if key not in v_; do nothing and return false
	
	//cout<<endl<<"Remove Function: "<<endl;
	auto itr = find_key(key);
	//key in v_
	if(itr != v_.end()){
		//cout<<"Key in v_ (remove)"<<endl;
		v_.erase(itr);
		//cout<<"ERASED: "<<endl;
		return true;
	}
	//key not in v_
	else{
		//cout<<"Key not in v_ (remove)"<<endl;
		return false;
	}
	
}

int MapSet::compare(MapSet &m){
	/*compare both MapSet element by element, using key as comparison
	 * first dif in comparison determins result.
	 * if v_ is >, retun 1; if v_ is <, return -1
	 * if v_ =, but v_.size() >, return 1; if v_.size() <, return -1*/
	
	//cout<<endl<<"Compare Function: "<<endl;
	
	int count = 0, min_cnt = m.size();
	if(size() < m.size()){
		min_cnt = size();
	}
	//cout<<"min_cnt: "<<min_cnt<<endl;
	
	for(auto itr=v_.begin(); itr != v_.end(); itr++){
		string key, k;
		key = itr->first;
		//cout<<"compare: "<<key<<" : "<<itr->second;
		auto i=m.v_.begin() + count;
		
		
		k = i->first;
		//cout<<"   Vs.   "<<k<<" : "<<i->second<<endl;
		//cout<<"count: "<<count<<endl<<endl;
	
		//both keys aren't the same
		if(key != k){
			//if v_ >
			if(key > k){
				//cout<<"Key > k: "<<key<<" > "<<k<<endl;
				return 1;
			}
			//if v_ <
			else{
				//cout<<"Key is < k: "<<key<<" < "<<k<<endl;
				return -1;
			}	
		}
		
		
		//if m.size() is shorter
		else if((count + 1) == min_cnt){
			//if size() > m.size()
			if(size() > m.size()){
				//cout<<"size() > m.size(): "<<size()<<" > "<<m.size()<<endl;
				return 1;
			}
			//size() < m.size()
			else if(size() == m.size()){
				return 0;
			}
			else{
				//cout<<"size() < m.size(): "<<size()<<" < "<<m.size()<<endl;
				return -1;
			}
		}
		count += 1;
	}
	return 0;
}

MapSet MapSet::mapset_union (MapSet &m){
	//Return new MapSet that is union of the two
	//if maps have the same key but dif value, use vlaue for v_
	//cout<<endl<<"MAPSET_UNION FUNCTION"<<endl;
	MapSet new_map;
	
	int cnt = 0, min_cnt = m.size();
	if(size() < m.size()){
		min_cnt = size();
	}
	
	for(auto itr=v_.begin(); itr != v_.end(); itr++){
		string key, k;
		long value, v;
		key = itr->first;
		value = itr->second;
		//cout<<"union: "<<key<<" : "<<value;
		auto i=m.v_.begin() + cnt;
		k = i->first;
		v = i->second;
		//cout<<"   Vs.   "<<k<<" : "<<v<<endl;
		//cout<<"count: "<<cnt<<endl;
		
		
		//if the two keys are the same
		if(key == k){
			//add v_ to the new MapSet
			//cout<<"(mapset_union) keys are same"<<endl<<endl;
			new_map.add(get(key));
			//cout<<"(mapset_union) key added to new_map"<<endl;
			
			//if we get to the end of a MapSet
			//cout<<"(UNION FN) min_cnt: "<<min_cnt<<endl;
			if((cnt + 1) == min_cnt){
				int s, sz;
				s = size();
				sz = m.size();
			
				//if size() > m.size()
				if(s > sz){
					//cout<<"(UNION FN) size() > m.size()"<<endl;
					//cout<<"Count: "<<cnt<<" m.size(): "<<m.size()<<endl;
					//then add the rest of v_ to the new MapSet
					for(auto itt=itr; itt != v_.end(); itt++){
						string kk = itt->first;
						long vv = itt->second;
						auto p = make_pair(kk,vv);
						new_map.add(p);
					}
					return new_map;
				}
				//else if size() < m.size()
				else{
					//cout<<"(UNION FN) size() < m.size()"<<endl;
					//cout<<"Count: "<<cnt<<" size(): "<<size()<<endl;
					//then add the rest of m.v_ to the new MapSet
					for(auto itt = i; itt != m.v_.end(); itt++){
						string kk = itt->first;
						long vv = itt->second;
						auto p = make_pair(kk,vv);
						new_map.add(p);
					}
					return new_map;
				}
			}
			
		}
		//keys are not the same
		else{
			//cout<<"(mapset_union) keys are not same"<<endl<<endl;
			//add the pair(key,value) and pair(k,v)
			auto p = make_pair(key, value);
			auto p_ref = make_pair(k,v);
			new_map.add(p);
			new_map.add(p_ref);
			//cout<<"(mapset_union) add the pair(key,value) and pair(k,v)"<<endl;
			
			
			
			//if we get to the end of a MapSet
			//cout<<"(UNION FN) min_cnt: "<<min_cnt<<endl;
			if((cnt + 1) == min_cnt){
				int s, sz;
				s = size();
				sz = m.size();
			
				//if size() > m.size()
				if(s > sz){
					//cout<<"(UNION FN) size() > m.size()"<<endl;
					//cout<<"Count: "<<cnt<<" m.size(): "<<m.size()<<endl;
					//then add the rest of v_ to the new MapSet
					for(auto itt=itr; itt != v_.end(); itt++){
						string kk = itt->first;
						long vv = itt->second;
						auto p = make_pair(kk,vv);
						new_map.add(p);
					}
					return new_map;
				}
				//else if size() < m.size()
				else{
					//cout<<"(UNION FN) size() < m.size()"<<endl;
					//cout<<"Count: "<<cnt<<" size(): "<<size()<<endl;
					//then add the rest of m.v_ to the new MapSet
					for(auto itt = i; itt != m.v_.end(); itt++){
						string kk = itt->first;
						long vv = itt->second;
						auto p = make_pair(kk,vv);
						new_map.add(p);
					}
					return new_map;
				}
			}
		}
		cnt += 1;
	}
	return new_map;
}

MapSet MapSet::mapset_intersection(MapSet &m){
	//Return new MapSet, that's an intersection of the two being called
	//if key is same but value dif, use v_ value
	cout<<"MAPSET_INTERSECTION FUNCTION: "<<endl<<endl;
	MapSet new_map;
	
	int cnt = 0, min_cnt = m.size();
	if(size() < m.size()){
		min_cnt = size();
	}
	cout<<"min_cnt: "<<min_cnt<<endl<<endl;
	for(auto itr = v_.begin(); itr != v_.end(); itr++){
		cout<<"(INTER) cnt: "<<cnt<<endl;
		auto i = m.v_.begin() + cnt;
		string key, k;
		long value;
		key = itr->first;
		value = itr->second;
		k = i->first;
		
		//if the keys are the same
		if(key == k){
			//add to new_map
			cout<<"(INTERSECT) Keys are the same"<<endl;
			cout<<"(INTERSECT): "<<key<<" Vs. "<<k<<endl;
			auto p = make_pair(key, value);
			new_map.add(p);
			cout<<"(INTER) keys are the same added: "<<endl;
		}
		
		//if reaches the end of MapSet, then return new_map
		if((cnt+1) == min_cnt){
			cout<<"(INTERSECT) end of MapSet: "<<endl;
			return new_map;
		}
		cnt += 1;
	}
	return new_map;
}

ostream & operator<<(ostream &out, MapSet &m){
	for(auto it = m.v_.begin(); it != m.v_.end(); it++){
		string key = it->first;
		long value = it->second;
		if((it+1)==m.v_.end()){
			out <<key<<":"<<value;
		}
		else{
			out <<key<<":"<<value<<", ";
		}
	}
	return out;
}


/*
int main(){
	MapSet ms1 ({ {"bill",1},{"alan",2},{"abby",3} });
	//MapSet ms2 ({ {"alan",2},{"abby",3},{"john",4} });
	//MapSet ms3 ({ {"abby",5},{"alan",17} });
	
	auto pr = ms1.get("bill");
	cout<<"pr: "<<pr.first<<" : "<<pr.second<<endl;
	auto p = ms1.get("sara");
	cout<<"p: "<<p.first<<" : "<<p.second<<endl;
	
	//auto p = ms1.get("goe");
	//cout<<"p: "<<p.first<<" : "<<p.second<<endl;
	//auto l = ms1.get("abby");
	//cout<<"l: "<<l.first<<" : "<<l.second<<endl;


}*/
