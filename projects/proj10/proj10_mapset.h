/*Project 10
 * 4/16/2018
 * 
 * Struct Node:
 * -2-arg constructor that is essentially a pair <key, value>
 * -operator< that compares the keys of the nodes and returns a bool
 * -operatro==, compares if keys are equale and returnd a bool
 * -operator<, prints the node as "key:value"
 * 
 * Class MapSet
 * -Node<K, V> ary_; essentiall aan arrya that has methods, .last_ which
 * was index of first unused spot in array, and capacity_; how many
 * elements the array can hold before it has to grow
 * -Find_key(): returns a pointer to the key in the array or to the end
 * -grow(): if the array needs to grow, it dounles its capacity_
 * -MapSet(sz): constructor that makes an array size sz, filled with 0
 * -MapSet(initializer_list): constructor that builds an array with the
 * elements from the initializer_list
 * -MapSet copy: copys one array to another
 * -opertor=: copys on array to another and then swaps the keys
 * -~MapSet(): destructur, that deletes ary_
 * -size(): returns the size of the array
 * -remove: removes a key from the array, and returns a bool
 * -add(): adds a node to an array in proper order
 * -get(): returns the copy of a node in an array given the key, or a
 * defualt node
 * -update(): upddates a keys value with a new value
 * -compare(): compares two MapSets and returns an int
 * -union(): returns a new MapSet with all elements
 * -Intersection(): returns a new MapSet with common elelments 
 * */

#ifndef MAP_SET
#define MAP_SET

#include<iostream>
using std::ostream;
#include<string>
using std::string;
#include<vector>
using std::vector;
#include<utility>
using std::pair;
#include<initializer_list>
using std::initializer_list;
#include<algorithm>
using std::sort; using std::lower_bound;
#include<sstream>
using std::ostringstream;
#include<array>
using std::array;
#include<algorithm>
using std::lower_bound; using std::copy;


//
// Node: Basically a STL pair
//
template<typename K, typename V>
struct Node {
	K first;
	V second;
  
	//constructors
	Node() = default;
	Node(K,V);
  
	//setters
	bool operator<(const Node&) const;
	bool operator==(const Node&) const;
  
	//operator<<
	friend ostream& operator<<(ostream &out, const Node &n){
		//print "first:second" to the ostream 
		out<<n.first<<":"<<n.second;
    
		return out;
	}
};

//2 arg constructor
template<typename K, typename V>
Node<K,V>::Node(K key, V value){
	first = key;
	second = value;
}

//operator<
template<typename K, typename V>
bool Node<K,V>::operator<(const Node &n) const{
	if(first < n.first){
		return true;
	}
	else{
		return false;
	}

}

//operator==
template<typename K, typename V>
bool Node<K,V>::operator==(const Node &n) const{
	if(first == n.first){
		return true;
	}
	else{
		return false;
	}
}

//
// MapSet
// 
template<typename K, typename V>
class MapSet{
	private:
		Node<K,V>* ary_;
		//index of first unused location in the array
		size_t last_;
		//#of nodes an array can hold before it has to grow
		size_t capacity_;
		Node<K,V>* find_key(K);
		void grow ();
	public:
		//constructors
		MapSet(int sz = 2);
		MapSet(initializer_list< Node<K,V> >);
		MapSet (const MapSet&);
		
		//copy and swap
		MapSet operator=(MapSet);
		
		//destructor
		~MapSet();
		
		//setters
		size_t size();
		
		//getters
		bool remove (K);  
		bool add(Node<K,V>);
		Node<K,V> get(K);
		bool update(K,V);  
		int compare(MapSet&);
		MapSet mapset_union (MapSet&);
		MapSet mapset_intersection(MapSet&);

		//operator<<
		friend ostream& operator<<(ostream &out, const MapSet &ms){
			/*prints the MapSet with "key:value, key:value, ..." */
			for(size_t i=0; i<(ms.last_); i++){
				if(i == (ms.last_ -1)){
					out<<ms.ary_[i];
				}
				else{
					out<<ms.ary_[i]<<", ";
				}
			}
			return out;
		}  
};


//1 arg constructor
template<typename K, typename V>
MapSet<K,V>::MapSet(int capacity){

	ary_ = new Node<K, V>[capacity]{};
	last_ = 0;
	capacity_ = capacity;
	//print the array
	
}

//initializer_list constructor
template<typename K, typename V>
MapSet<K,V>::MapSet(initializer_list< Node<K,V> > il){

	ary_ = new Node<K, V>[il.size()]{};
	last_ = 0;
	capacity_ = il.size();

	for(auto i=il.begin(); i != il.end(); i++){
		add(*i);
	}
}

//copy constructor
template<typename K, typename V>
MapSet<K,V>::MapSet(const MapSet &ms){
	//create a new array with the elements of the given array
	capacity_ = ms.capacity_;
	ary_ = new Node<K, V>[capacity_]{};
	last_ = 0;
	copy(ms.ary_, ms.ary_ +ms.last_, ary_);
}

// copy and swap
template<typename K, typename V>
MapSet<K,V> MapSet<K,V>::operator=(MapSet<K,V> ms){
	//look at examples code and videos
	copy(ms.ary_, ms.ary_ +ms.last_, ary_);
	swap(ary_, ms.ary_);	
}

//destructor
template<typename K, typename V>
MapSet<K,V>::~MapSet(){
	//look at examples code and videos
	delete [] ary_;
}


//size
template<typename K, typename V>
size_t MapSet<K,V>::size(){
	//size of the MapSet (# of Nodes)
	size_t size= last_;
	return size;
}

//grow
template<typename K, typename V>
void MapSet<K,V>::grow(){
	size_t new_capacity = capacity_*2;
	MapSet<K, V> new_ary(new_capacity);

	copy(ary_, ary_ + last_, new_ary.ary_);

	capacity_ = new_capacity;

	swap(ary_, new_ary.ary_);

	
}

//find_key
template<typename K, typename V>
Node<K,V>* MapSet<K,V>::find_key(K key){
	//return a pointer to Node<K, V>
	
	//use pointer arithmatic with lower_bound
		//for "lower_bound" to work must have "operator<" for Node
	
	V n;
	Node<K, V> search_node(key, n);
	Node<K,V>* i = lower_bound(ary_, ary_ + last_, search_node);
	return i;
}

//add
template<typename K, typename V>
bool MapSet<K,V>::add(Node<K,V> n){
	auto ptr = find_key(n.first);
	
	
	//if key is in MapSet
	if(ptr != (ary_ + last_)){
		
		
		//if key's arnt equale
		bool eq = (n == *ptr);

		if(eq == false){
			//if the array is to small
			if(last_ == capacity_){
				grow();
			}
			
			Node<K, V> new_node(n.first, n.second);
			MapSet<K, V> new_ary(capacity_);
			
			//if ptr == ary_
			if(ptr == ary_){
				new_ary.ary_[new_ary.last_] = n;
				new_ary.last_ += 1;
				copy(ary_, ary_ + last_, new_ary.ary_+new_ary.last_);
				new_ary.last_ += last_;
			}
			//else insert n in middle of array
			else{
				MapSet<K, V> new_ary(capacity_);
				cout<<"capacity_: "<<capacity_<<endl;
				cout<<"ADD IN THE MIDDLE"<<endl;
				cout<<"n: "<<n<<endl;
				cout<<"ptr: "<<ptr<<" *ptr: "<<*ptr<<endl;
				cout<<"ary_: "<<ary_<<" *ary_: "<<*ary_<<endl; 
				size_t cnt = 0;
				for(size_t i=0; i<capacity_; ++i){
					if(ary_[i] == *ptr){
						cout<<"!!!STOP"<<endl;
						continue;
					}
					cnt +=1;
					new_ary.ary_[i] = ary_[i];
					cout<<"coyL  "<<new_ary<<endl;
					Node<K, V> n;
					bool ans = (new_ary.ary_[i] == n);
					if(ans == false){
						new_ary.last_ += 1;
					}
				}
				cout<<"new_ary.last_: "<<new_ary.last_<<endl;
				auto split = new_ary.last_;
				cout<<"split: "<<split<<endl;
				new_ary.ary_[new_ary.last_] = n;
				new_ary.last_ += 1;
				
				
				copy(ary_+split, ary_+last_, new_ary.ary_+new_ary.last_);
				cout<<"new: "<<new_ary<<endl;
				cout<<"new_ary.last_: "<<new_ary.last_<<endl;
				cout<<"new_ary.capacity_: "<<new_ary.capacity_<<endl;
				cout<<"*ptr: "<<*ptr<<endl;
				cout<<ary_[split]<<endl;
				new_ary.ary_[new_ary.last_] = ary_[split];
				for(size_t i=0; i<new_ary.capacity_; ++i){
					cout<<"indx: "<<i<<" value: "<<new_ary.ary_[i]<<endl;
				}
			}
			last_ = new_ary.last_;

			swap(ary_, new_ary.ary_);
			cout<<"swaped"<<endl;
			return true;
			
			
		}
		//else
		else{
			//do nothing
			return false;
		}
	}
	//if key isn't in MapSet
	else{
		//if the array is to small
		if(last_ == capacity_){
			grow();
		}
		Node<K, V> new_node(n.first, n.second);
		ary_[last_] = new_node;
		last_ += 1;
		return true;
	} 
}


//remove
template<typename K, typename V>
bool MapSet<K,V>::remove(K key){
	//If key K is in MapSet; remove the Node, and return True
	//Else do nothing, return false
	Node<K, V> n(key,1);
	Node<K, V> n1("",0);
	MapSet<K, V> new_ary(capacity_);
	for(size_t i=0; i<last_; ++i){
		if(ary_[i] == n){
			copy(ary_, ary_ + i, new_ary.ary_);
			new_ary.last_ = i;
			copy((ary_ + (i+1)), ary_ + last_, new_ary.ary_+new_ary.last_);
			copy((ary_ + (i+1)), ary_ + last_, new_ary.ary_+new_ary.last_);
			swap(new_ary.ary_, ary_);
			last_ -=1;
			return true;
		
		}
	}
	return false;
}

//get
template<typename K, typename V>
Node<K,V> MapSet<K,V>::get(K key){
	//returns Node<K, V> that is either:
	//A copy of the Node that has the key K
	//Or a pair with defualt values {0, ""}
	size_t count = -1;
	auto ptr = find_key(key);
	//if key is in MapSet
	if(ptr != (ary_ + last_)){
		//indx of ptr in ary_
		for(size_t i=0; i<capacity_; ++i){
			count += 1;
			if(*ptr == ary_[i]){
				break;
			}
		}
		//if found at front of ary_
		Node<K, V> n(key, ary_[count].second);
		return n;
		
		
		
	}
	else{
		Node<K, V> n("",0);
		return n;
	}
}


//update
template<typename K, typename V>
bool MapSet<K,V>::update(K key, V value){
	/*If the kay K is in MapSet, tthen update that value with new value
	 * return true */
	//If not in MapSet, return false

	size_t count = -1;
	auto ptr = find_key(key);

	//if key in MapSet
	if(ptr != (ary_ + last_)){

		
		//indx of ptr in ary_
		for(size_t i=0; i<capacity_; ++i){
			count += 1;
			if(*ptr == ary_[i]){
				break;
			}
		}
		ary_[count].second = value;
		return true;
	}
	//not in MapSet
	else{
		return false;
	}
}

//compare
template<typename K, typename V>
int MapSet<K,V>::compare(MapSet &ms){
	//if arg >, return -1
	//else if all ==
		//if first is larger, return 1
		//else if secon larger, return -1
		//else, if same size; return 0
	size_t min_sz=ms.last_, max_sz = last_;
	bool a = true;

	if(min_sz > max_sz){
		size_t temp = min_sz;
		min_sz = max_sz;
		max_sz = temp;
		a = false;
	}
	for(size_t ii=0; ii<min_sz; ++ii){
		//if i < ii
		if(ary_[ii] < ms.ary_[ii]){
			return -1;
		}
		else{
			if(ary_[ii] == ms.ary_[ii]){
				continue;
			}
			return 1;
		}
	}
	if(min_sz != max_sz){
		//if ary_ is larger
		if(a){
			return 1;
		}
		else{
			return -1;
		}
	}
	else{
		return 0;
	}
}

//mapset_union
template<typename K, typename V>
MapSet<K,V> MapSet<K,V>::mapset_union(MapSet<K,V> &ms){
	/*return new MapSet, that is a union of the two given. If the two
	 * have the same key, but differnet values. Use the key-value of the
	 * calling MapSet*/
	cout<<"!!UNION!!"<<endl;
	MapSet<K, V> new_ary(capacity_);
	for(size_t i=0; i<last_; i++){
		cout<<"ary__"<<endl;
		cout<<"new_ary.add("<<ary_[i]<<")"<<endl;
		new_ary.add(ary_[i]);
	}
	cout<<"new_ary with all ary: "<<new_ary<<endl;
	
	for(size_t ii=0; ii<new_ary.last_; ii++){
		cout<<"other "<<endl;
		cout<<"new_ary.add("<<new_ary.ary_[ii]<<")"<<endl;
		ms.add(new_ary.ary_[ii]);
		cout<<"new_ary: "<<new_ary<<endl;
	}
	cout<<"cap: "<<new_ary.capacity_<<endl;
	cout<<"new_ary: "<<new_ary<<endl;
	cout<<"last_ "<<new_ary.last_<<endl;
	return ms;
}

//mapset_intersection
template<typename K, typename V>
MapSet<K,V> MapSet<K,V>::mapset_intersection(MapSet<K,V> &ms){
	/*Return a new MapSet, containg common keys, if the key's values
	 * are differnet. use the value from the calling MapSet*/
	MapSet<K, V> new_ary(capacity_);
	for(size_t i=0; i<ms.capacity_; i++){
		for(size_t ii=0; i<capacity_; ++ii){
			if(ms.ary_[i]== ary_[ii]){
				new_ary.add(ary_[ii]);
				break;
			}
		}
	}
	return new_ary;
}

#endif
  
