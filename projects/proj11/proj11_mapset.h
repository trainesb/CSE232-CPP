/*Project 11
 * 4/22/2018
 * 
 * Struct Node: A Node that is the element type in MapSet. has methods;
 * 	first: Key in the Node;
 * 	second: Value in the Node
 * 	*next: a pointer to nullptr, which will eventually point to the next
 * 	Node in MapSet.
 * 
 * Opertor<<: Takes an adress of a node as a paramater and then prints
 * as "first:second"
 * 
 * Node(K key, V value) Constructor: Key is set to first, and value to 
 * second, last Node pointer next was created and set to nullptr
 * 
 * Operator<: When two Nodes are compared using the < operator, if the 
 * first Node's "first" (key) is smaller then the Node its being compared
 * to, then return "true", else return "false"
 * 
 * Operator==: If two Nodes are compared using ==; if the two Node's 
 * first are equle, then return "true", else return "false"
 * 
 * 
 * 
 * 
 * Class MapSet: A list of Nodes that has methods;
 * 	head_: A pointer to the first Node in MapSet
 *	tail_: A pointer to the last Node in MapSet
 * 	sz: Numnber of Nodes in MapSet
 * 
 * 	Operator<<: Creates a type Node<K,V> pointer to the first Node in 
 * 	MapSet, loops until the pointer points to "nullptr", and after each 
 * 	loop, updates the pointer to the next node in MapSet.  Inside each 
 * 	loop; the dereferenced pointer is sent to the ostream, which is sent
 * 	to the Node Operator<<, followed by ", ". Beofre the MapSet is
 * 	printed, the last ", " is removed.
 * 
 * 	MapSet(intilaizer_list) Constructor: Takes a list of Nodes, and 
 * 	sends them to add() to be add to MapSet.
 * 
 * 	find_key(key): Recives a key, if that key exits in MapSet list then
 * 	return a pair of pointers to the first Node that equals key or just 
 * 	larger, and the Node just behind that Node. 
 * 
 * 	add(Node): Takes a Node and uses find_key to get a pointer where to 
 * 	add the Node. Adds it to the front, back, or middle respectively, 
 * 	and return true. If there is no list or the key is already in the 
 * 	list, false is returned.
 * 
 * 	size(): returns the size of MapSet
 * 
 * 	get(K): searches MapSet for Node with first= K, or default Node
 * 
 * 	update(K, V): Looks if K is the key for a Node in MapSet. If it is;
 * 	update that Node's value with the new one and return true, else
 * 	return false.
 * 
 * 	remove(K): Looks if K is the key of a Node in MapSet. If it is then 
 * 	removes it and returns true, else returns false.
 * 
 * 	compare(MapSet): Compares two MapSets Node by Node based off key. If
 * 	all equle, but first is shorter return -1, if longer -1. If when
 * 	comparing first is larger return 1, if smaller -1, if all same 0.
 * 
 * 	mapset_union(Mapset): Returns a new MapSet with all Nodes, if same 
 * 	key in both use the first one.
 * 
 * 	mapset_intersection(MapSet_: Returns a new MapSet with all common 
 * 	elements, if same key in both, use the first one.
 * 
 * 	Rule of 3:
 * 	operator=: copy or swap
 * 	~MapSet(): MapSet destructor
 * 	MapSet(const MapSet): copys a MapSet and returns a new one.
 * */
#ifndef MAP_SET
#define MAP_SET

#include<iostream>
using std::ostream;
#include<string>
using std::string;
#include<utility>
using std::pair; using std::make_pair;
#include<initializer_list>
using std::initializer_list;
#include<sstream>
using std::ostringstream;


//
// Node-
//
template<typename K, typename V>
struct Node {
	//Methods
  K first;
  V second;
  Node *next = nullptr;
  
  //Constructors
  Node() = default;
  Node(K,V);
  
  //Opertaions
  bool operator<(const Node&) const;
  bool operator==(const Node&) const;
  
  friend ostream& operator<<(ostream &out, const Node &n){
    out<< n.first<<":"<<n.second;
    return out;
  }
};

template<typename K, typename V>
Node<K,V>::Node(K key, V value){
	cout<<"Node(K key, V value) constructor"<<endl;
	cout<<"Paramaters; key: "<<key<<" value: "<<value<<endl<<"."<<endl<<"."<<endl<<"."<<endl;
	first = key;
	second = value;
	next = nullptr;
	cout<<"Node Created!!; first: "<<first<<" second: "<<second<<endl;
	
}

template<typename K, typename V>
bool Node<K,V>::operator<(const Node &n) const{
	if( first < n.first) {
		cout<<"operator<: first < n.first"<<endl;
		return true;
	}
	else{
		cout<<"operator<: first 'isn't <' n.first"<<endl;
		return false;
	}
}

template<typename K, typename V>
bool Node<K,V>::operator==(const Node &n) const{
	if(first == n.first){
		cout<<"operator==: "<<first<<" == "<<n.first<<endl;
		return true;
	}
	else{
		cout<<"operator==: "<<first<<" != "<<n.first<<endl;
		return false;
	}
}


//
// MapSet
// 
template<typename K, typename V>
class MapSet{
 private:
  Node<K,V>* head_ = nullptr;
  Node<K,V>* tail_ = nullptr;  
  size_t sz_ = 0;
  pair< Node<K, V>*, Node<K, V>* > find_key(K);

 public:
  MapSet()=default;
  MapSet(initializer_list< Node<K,V> >);
  MapSet (const MapSet&);
  MapSet operator=(MapSet);
  ~MapSet();
  size_t size();
  bool remove (K);  
  bool add(Node<K,V>);
  Node<K,V> get(K);
  bool update(K,V);  
  int compare(MapSet&);
  MapSet mapset_union (MapSet&);
  MapSet mapset_intersection(MapSet&);

  friend ostream& operator<<(ostream &out, const MapSet &ms){
    ostringstream oss;
    Node<K, V> *ptr;
    for(ptr = ms.head_; ptr != nullptr; ptr = ptr -> next){
			oss<<*ptr<<", ";
		}
		string s = oss.str();
		out<< s.substr(0, s.size() -2);
		return out;
  }  
};

template<typename K, typename V>
MapSet<K,V>::MapSet(initializer_list< Node<K,V> > il){
	cout<<endl<<"MapSet(initializer_list) Constructor: ";
	auto i = il.begin();
	cout<<"i: "<<*i<<":"<<i<<endl;
	cout<<"i.first: "<<i->first<<endl;
	
	head_ =  new Node<K, V>( (i->first), (i->second) );
	cout<<"head: "<<*head_<<":"<<head_<<endl;
	
	
	tail_ = head_;
	cout<<"tail: "<<*tail_<<":"<<tail_<<endl;
		
	sz_ = 1;
	cout<<"sz: "<<sz_<<endl;
	cout<<"first Node added to MapSet"<<endl<<endl<<endl<<endl<<endl<<endl;
	
	int num = 0;
	for(i = il.begin() ; i != il.end(); i++){
		num += 1;
		cout<<"loop num: "<<num<<endl;
		auto f = find_key(i->first);
		cout<<"found"<<endl<<endl<<endl<<endl;
		if(f.first != nullptr){
			cout<<"n can be added t0 MapSet: "<<*i<<endl<<endl;
			cout<<"f.first: "<<*f.first<<":"<<f.first<<endl;
			cout<<"n to add: "<<*i<<":"<<i<<endl;
			cout<<"f.first -> first: "<<f.first -> first<<endl;
			cout<<"n -> first: "<<i -> first<<endl;

			cout<<endl<<endl<<"f: "<<f.first<<":"<<f.second<<endl;
			cout<<"n not in Mapset: "<<*i<<endl;
			cout<<"ABOUT TO ADD: "<<*i<<endl<<endl;
			
			cout<<"head_: "<<*head_<<":"<<head_<<endl;
			cout<<"next: "<<head_ -> next<<endl;
			cout<<"ADDING: "<<endl;
				
				
				
			cout<<endl<<endl<<"what we are adding: "<<*i<<":"<<i<<endl;
			cout<<"sz_: "<<sz_<<endl;
				
				
			add(*i);
			cout<<"tail_: "<<*tail_<<":"<<tail_<<endl;
			cout<<endl<<"added"<<endl;
			
			cout<<endl<<endl<<endl<<"MapSet: "<<endl;
			cout<<"jafdhfij: head_ "<<*head_<<" : "<<head_<<endl;
			cout<<"tail_: "<<*tail_<<":"<<tail_<<endl;
			cout<<"MapSet: "<<endl;
		}
		else{
			cout<<"f.first == nullptr"<<endl;
			if(f.second != nullptr){
				cout<<"f.second != nullptr"<<endl;
				cout<<"ADD to back"<<endl<<endl<<endl;
				
				
				cout<<"n not in Mapset: "<<*i<<endl;
				cout<<"ABOUT TO ADD: "<<*i<<endl<<endl;
			
				cout<<"head_: "<<*head_<<":"<<head_<<endl;
				cout<<"head_ -> next: "<<head_ -> next<<endl;
				cout<<"ADDING: "<<endl;
				
				
				cout<<endl<<endl<<"what we are adding: "<<*i<<":"<<i<<endl;
				add(*i);
				cout<<"tail_: "<<*tail_<<":"<<tail_<<endl;
				cout<<endl<<"added"<<endl;
			
				cout<<endl<<endl<<endl<<"MapSet: "<<endl;
				

				
			}
		}
	}
	cout<<"all elements added"<<endl;
	cout<<"head_: "<<*head_<<":"<<head_<<endl;
	cout<<"head_ -> next: "<<head_ -> next<<endl;
	cout<<"tail_: "<<*tail_<<":"<<tail_<<endl;
	
}

template<typename K, typename V>
MapSet<K,V>::MapSet(const MapSet &ms){
	if(ms.head_ == nullptr){
		head_ = nullptr;
		tail_ = nullptr;
	}
	else{
		head_ = new Node<K, V>( (ms.head_ ->first), (ms.head_ ->second) );
		tail_ = head_;
		Node<K, V>* ms_ptr = ms.head_ -> next;
		Node<K, V>* new_node;
		while( ms_ptr != nullptr){
			new_node = new Node<K, V>( (ms_ptr -> first), (ms_ptr -> second) );
			tail_ -> next = new_node;
			ms_ptr = ms_ptr -> next;
			tail_ = new_node;
		}
	}
}

template<typename K, typename V>
MapSet<K,V> MapSet<K,V>::operator=(MapSet ms){
	swap(head_, ms.head_);
	swap(tail_, ms.tail_);
	return *this;
}	

// walk down the list, moving head_ but remember it in to_del
// delete each node in turn, the set head_ and tail_
template<typename K, typename V>
MapSet<K,V>::~MapSet(){
	Node<K, V>* to_del = head_;
	while(to_del != nullptr){
		head_ = head_ -> next;
		delete to_del;
		to_del = head_;
	}
	head_ = nullptr;
	tail_ = nullptr;
}

template<typename K, typename V>
size_t MapSet<K,V>::size(){
	return sz_;
}

template<typename K, typename V>
pair< Node<K, V>*, Node<K, V>* > MapSet<K,V>::find_key(K key){
	Node<K, V>* found = nullptr;
	Node<K, V>* before = nullptr;
	Node<K, V> new_node(key, 1);
	cout<<endl<<"find_key("<<key<<") new_node: "<<new_node<<endl<<endl;

	for(auto i=head_; i!=nullptr; i = i -> next){
		cout<<"Node comparing key to: "<<*i<<":"<<i<<endl;
		if(*i == new_node){
			cout<<"nodes =="<<endl;
			found = i;
			auto find_pair = make_pair(found, before);
			cout<<"find_pair: "<<find_pair.first<<":"<<find_pair.second<<endl;
			return find_pair;
		}
		else if( !(*i < new_node)){
			cout<<"new_node is smaller"<<endl;
			cout<<"before i: "<<before<<endl;
			cout<<"Return ptr to i: "<<*i<<":"<<i<<endl;
			found = i;
			
			if(sz_ == 1){
				cout<<"sz: "<<sz_<<" change before to: "<<*i<<":"<<i<<endl;
				cout<<"beofre og: "<<before<<endl;
				before = i;
				cout<<"beofre changed: "<<*before<<":"<<before<<endl;
			}
			if(sz_ == 2){
				cout<<"(i->first): "<<(i->first)<<endl;
				cout<<"key: "<<key<<endl;
				if( (i->first) != key ){
					cout<<"sz 2 but != "<<endl;
				}
				else{
					before = tail_;
				}
			}
			
			auto find_pair = make_pair(found, before);
			cout<<"find_pair: "<<find_pair.first<<":"<<find_pair.second<<endl<<endl;
			return find_pair;
		}
		else{
			if(head_ == tail_){
				cout<<"head == tail"<<endl;
				found = i;
				auto find_pair = make_pair(found, before);
				cout<<"find_pair: "<<find_pair.first<<":"<<find_pair.second<<endl;
				return find_pair;
			}
			before = i;
			cout<<"before i: "<<*before<<":"<<before<<endl;
			cout<<"i still small, continue.."<<endl<<endl;
		}
	} 
	cout<<"GOES AT THE END"<<endl;
	auto find_pair = make_pair(found, before);
	cout<<"find_pair: "<<find_pair.first<<":"<<find_pair.second<<endl<<endl;
	return find_pair;
}

template<typename K, typename V>
bool MapSet<K,V>::add(Node<K,V> n){
	cout<<endl<<"add()"<<endl;
	cout<<"sz_: "<<sz_<<endl;

	
	
	cout<<"n: "<<n<<":"<<&n<<endl;
	
	if(head_ != nullptr){
		cout<<endl<<"add() There are elements in the list"<<endl<<endl;
		auto find = find_key(n.first);
		cout<<"add() found"<<endl;
		
		
		if(find.first != nullptr){
			cout<<"can add MapSet not empty: "<<find.first<<" !=nullptr"<<endl<<endl;
			
			if(find.second == nullptr){
				
				if( (find.first -> first) == (n.first) ){
					cout<<"they are the same dont add"<<endl;
					return false;
				}
				cout<<endl<<"Add "<<n<<" to the back or front of MapSet"<<endl;
			
				Node<K, V>* find_first = new Node<K, V>( (n.first), (n.second));
				cout<<endl<<"Nodes are made: "<<*find_first<<" : "<<find_first<<endl<<endl;
						
				cout<<"(find_first ->first): "<<(find_first ->first)<<endl;
				cout<<"(find.first -> first): "<<(find.first -> first)<<endl;
				cout<<endl<<"find: "<<find.first<<":"<<*find.first<<" second: "<<find.second<<endl;
				if( (find_first ->first) < (find.first -> first) ){
					cout<<"add to the front"<<endl;
					find_first->next = head_;
					cout<<"n.next: "<<find_first->next<<endl;
					head_ = find_first;
					sz_ += 1;
					return true;
				}
			
			
				find_first->next = nullptr;
				cout<<"n.next: "<<n.next<<endl;
			

				cout<<endl<<"change tail_ -> next: "<<tail_->next<<endl;
				cout<<"Change tail_: "<<*tail_<<":"<<tail_<<endl;
				tail_ -> next = find_first;
				cout<<endl<<"Chnaged tail- -> next: "<<*(tail_ -> next)<<":"<<tail_ -> next<<endl;
				cout<<"Changed tail_: "<<*tail_<<":"<<tail_<<endl;
			
				tail_ = find_first;
				cout<<endl<<"tail should be end now: "<<*tail_<<":"<<tail_<<endl;
				cout<<endl<<"tail_ -> next: "<<tail_->next<<endl;
				cout<<"sz_: "<<sz_<<endl;
				sz_ += 1;
				return true;
				
			}
			else if( (find.first -> first) == (n.first) ){
					cout<<"they are the same dont add"<<endl;
					return false;
			}
			
			else if(head_ == find.first){
				cout<<"head_ == find.first: "<<endl;
				cout<<"head_: "<<*head_<<":"<<head_<<endl;
				cout<<"add to front"<<endl<<endl;
				
				if( (find.first -> first) == (n.first) ){
					cout<<"they are the same dont add"<<endl;
					return false;
				}
				
				Node<K, V>* find_first = new Node<K, V>( (n.first), (n.second));
				cout<<endl<<"Nodes are made: "<<*find_first<<" : "<<find_first<<endl<<endl;
				
				cout<<endl<<"head_: "<<*head_<<" != n: "<<n<<endl;
				cout<<"head_: "<<*head_<<":"<<head_<<endl;
				cout<<"head_ -> next: "<<head_-> next<<endl;
				find_first->next = head_;
				cout<<"n.next: "<<find_first->next<<endl;
				head_ = find_first;
				sz_ += 1;
				cout<<"head: "<<*head_<<":"<<head_<<endl;
				cout<<"tail: "<<*tail_<<":"<<tail_<<endl;
				cout<<"sz: "<<sz_<<endl;
				cout<<"head_ -> next: "<<head_-> next<<endl;
				cout<<"tail_ -> next: "<<tail_-> next<<endl;
				return true;
			}
			else{
				cout<<"add to the middle or end"<<endl;
				cout<<"find.first: "<<find.first<<endl;
				Node<K, V>* find_first = new Node<K, V>( (n.first), (n.second));
				find_first -> next = find.first;
				cout<<"find_first -> next: "<<(find_first -> next)<<endl;
				cout<<"n.next: "<<(find.second -> next)<<endl;
				find.second -> next = find_first;
				sz_ += 1;
				cout<<"find.second: "<<find.second<<endl;
				cout<<"tail_: "<<tail_<<endl;
				if(find.second == tail_){
					cout<<"add to the end"<<endl;
					tail_ = find_first;
				}
				cout<<"return"<<endl;
				return true;
			}
			cout<<"can't add they are =="<<endl;
			return false;
		}
		
		else if(find.second != nullptr){
			cout<<endl<<"Add "<<n<<" to the back of MapSet"<<endl;
			
			Node<K, V>* find_first = new Node<K, V>( (n.first), (n.second));
			cout<<endl<<"Nodes are made: "<<*find_first<<" : "<<find_first<<endl<<endl;

			
			find_first->next = nullptr;
			cout<<"n.next: "<<n.next<<endl;
			

			cout<<endl<<"change tail_ -> next: "<<tail_->next<<endl;
			cout<<"Change tail_: "<<*tail_<<":"<<tail_<<endl;
			tail_ -> next = find_first;
			cout<<endl<<"Chnaged tail- -> next: "<<*(tail_ -> next)<<":"<<tail_ -> next<<endl;
			cout<<"Changed tail_: "<<*tail_<<":"<<tail_<<endl;
			
			tail_ = find_first;
			cout<<endl<<"tail should be end now: "<<*tail_<<":"<<tail_<<endl;
			cout<<endl<<"tail_ -> next: "<<tail_->next<<endl;
			cout<<"sz_: "<<sz_<<endl;
			sz_ += 1;
			cout<<"sz_: "<<sz_<<endl;
			return true;
			
		}
	}
	else if(sz_ == 0){
		cout<<"MapSet empty"<<endl;
		
		head_ =  new Node<K, V>( (n.first), (n.second) );
		cout<<"head: "<<*head_<<":"<<head_<<endl;
	
	
		tail_ = head_;
		cout<<"tail: "<<*tail_<<":"<<tail_<<endl;
		
		sz_ = 1;
		return true;
	}
	
	
	return false;
}



template<typename K, typename V>
bool MapSet<K,V>::remove(K key){
	auto find = find_key(key);
	cout<<endl<<endl<<endl<<"Remove: "<<key<<endl;
	if( find.first != nullptr){
		if( (find.first -> first) == (key) ){
			cout<<"remove it!"<<endl;
			cout<<"find.second ->next : "<<(find.second ->next)<<endl;
			cout<<"find.first ->next: "<<(find.first ->next)<<endl;
			
			(find.second ->next) = (find.first ->next);
			
			cout<<endl<<endl<<endl<<"find.second ->next : "<<(find.second ->next)<<endl;
			cout<<"find.first ->next: "<<(find.first ->next)<<endl;

			return true;
		}
	}
	return false;
}


template<typename K, typename V>
Node<K,V> MapSet<K,V>::get(K key){
	auto find = find_key(key);
	cout<<endl<<endl<<endl<<"GET: "<<key<<endl;
	if( find.first != nullptr){
		if( (find.first -> first) == (key) ){
			cout<<(find.first -> first)<<" == "<<key<<endl;
			Node<K, V>* get_node = new Node<K, V>( (find.first -> first), (find.first -> second) );
			return *get_node;
		}
		else{
			cout<<" != "<<key<<endl;
			Node<K, V>* get_node = new Node<K, V>( "", 0 );
			return *get_node;
		}
	}
	Node<K, V>* get_node = new Node<K, V>( "", 0 );
	return *get_node;
}


template<typename K, typename V>
bool MapSet<K,V>::update(K key, V value){
	auto find = find_key(key);
	cout<<endl<<endl<<endl<<"update: "<<key<<":"<<value<<endl;
	if(find.first != nullptr){
		if( (find.first -> first) == (key) ){
			cout<<(find.first -> first)<<" == "<<key<<endl;
			cout<<"find.first -> second: "<<(find.first -> second)<<endl;
			find.first -> second = value;
			cout<<endl<<"find.first -> second: "<<(find.first -> second)<<endl;
			return true;
		}
	}
	return false;
}


template<typename K, typename V>
int MapSet<K,V>::compare(MapSet &ms){
	int n = 0;
	int num = 0;
	for(auto i=head_; i!= nullptr; i = i -> next){
		
		for(auto ii=ms.head_; ii!=nullptr; ii = ii -> next){
			
			if(i != nullptr && ii != nullptr){
			
				if(num != n){
					cout<<"dont compare yet"<<endl;
					cout<<"n: "<<n<<" num: "<<num<<endl;
					cout<<"sz: "<<sz_<<endl;
					num += 1;
					
					
					if(num >= ms.sz_){
						cout<<"second is short"<<endl;
						return 1;
					}
					
					
					else if((n+1) > sz_){
						cout<<"first -- short"<<endl;
						return -1;
					}
					continue;
				}
				n += 1;
				
				//compare Nodes
				if( *i == *ii ){
					cout<<"they the same so continue"<<endl;
					
					if(n == sz_){
						//compare size
						if(sz_ == ms.sz_){
							cout<<"size is the same"<<endl;
							return 0;
						}
						else if (sz_ > ms.sz_){
							cout<<"sz_ ? ms.sz_"<<endl;
							return 1;
						}
						else{
							return -1;
						}
					}
					num = 0;
					break;
				}
				else if( *i < *ii ){
					cout<<*i<<"<"<<*ii<<endl;
					return -1;
				}
				else{
					cout<<*i<<">"<<*ii<<endl;
					return 1;
				}
			}
		}
	}

}


template<typename K, typename V>
MapSet<K,V> MapSet<K,V>::mapset_union(MapSet<K,V> &ms){
	cout<<"make new MapSet: "<<endl;
	MapSet<K, V> u;
	cout<<"u made: "<<endl;
	for(auto i=head_; i != nullptr; i = i -> next){
		if(u.sz_ == 0){
			cout<<"u: "<<u<<endl;
			cout<<"u.sz: "<<u.sz_<<endl;
			u.head_ = new Node<K, V>((i->first),(i->second));
			u.tail_ = u.head_;
			u.sz_ += 1;
			cout<<endl<<endl<<"u.head_: "<<*u.head_<<endl;
		}
			cout<<endl<<"add first::"<<endl;
			u.add(*i);
			cout<<endl<<"u: "<<u<<endl;
	}
	for(auto ii=ms.head_; ii != nullptr; ii = ii -> next){
		u.add(*ii);
		cout<<endl<<"u: "<<u<<endl;
		cout<<"u.head_: "<<u.head_<<" u.tail_: "<<u.tail_<<endl;
	}
	cout<<"UNION: "<<endl;
	cout<<"u.head_: "<<u.head_<<endl;
	for(auto iii = u.head_; iii != nullptr; iii = iii -> next ){
		cout<<*iii<<":"<<iii<<endl;
	}
	return u;
}

template<typename K, typename V>
MapSet<K,V> MapSet<K,V>::mapset_intersection(MapSet<K,V> &ms){
	cout<<"intersection"<<endl<<endl;
	MapSet<K, V> in;
	int num = 0;
	int n = 0;
	for(auto i=head_; i!= nullptr; i = i -> next){

		for(auto ii=ms.head_; ii!=nullptr; ii = ii -> next){
	
			if(i != nullptr && ii != nullptr){

			
				
				
				cout<<endl<<endl<<"in: "<<endl;
				for(auto i=in.head_; i!=nullptr; i = i -> next){
					cout<<*i<<":"<<i<<endl;
				}
				cout<<"i && ii != nullptr"<<endl;
				cout<<"i: "<<*i<<endl;
				cout<<"II: "<<*ii<<endl;
				cout<<endl<<"num: "<<num<<" n: "<<n<<endl;


				if(num >= ms.sz_){
					cout<<"second is short"<<endl;
					return in;
				}
					
					
				else if((n+1) > sz_){
					cout<<"first -- short"<<endl;
					return in;
				}

				cout<<"(i->first): "<<(i->first)<<endl;
				cout<<"(ii->first): "<<(ii->first)<<endl;
				if( (i->first) == (ii->first) ){
					cout<<"add i: "<<*i<<endl;
					in.add(*i);
					cout<<"added: "<<endl;
					continue;
				}
				continue;
				n += 1;
				
				//compare Nodes
				if( *i == *ii ){
					cout<<"they the same so add"<<endl;
					in.add(*i);
					
					if(n == sz_){
						//compare size
						if(sz_ == ms.sz_){
							cout<<"size is the same"<<endl;
							return in;
						}
						else if (sz_ > ms.sz_){
							cout<<"sz_ ? ms.sz_"<<endl;
							return in;
						}
						else{
							return in;
						}
					}
					break;
				}
				else{
					cout<<"continue: "<<endl;
					return in;
				}
					cout<<"out1"<<endl;
			}
				cout<<"out2"<<endl;
		}
			num += 1;
			cout<<"out3"<<endl;
	}
	cout<<"out"<<endl;
	
	cout<<endl<<endl<<"in: "<<endl;
	for(auto i=in.head_; i!=nullptr; i = i -> next){
		cout<<*i<<":"<<i<<endl;
	}
	return in;
}



#endif
  
