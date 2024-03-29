#ifndef SINGLELINK_H
#define SINGLELINK_H

#include<iostream>
using std::ostream; using std::cout; using std::endl;
#include<sstream>
using std::ostringstream;

template <typename T>
struct Node{
public:
    Node *next_;
    T data_;
    
Node() : data_( T() ), next_(nullptr) {};
Node(T d) : data_(d), next_(nullptr) {};
};

template <typename T>
class SingleLink{
private:
    Node<T> *head_;
    Node<T> *tail_;
  
public:
  SingleLink() = default;         
  SingleLink(T dat);    
  void append_back(T);
  
  friend ostream& operator<<(ostream &out, SingleLink<T>& s){
	out<<s;
	return out;
  };
  
  bool del(T val);
  Node<T>operator[](size_t index);
  
  // Rule of three stuff, if you get time. Look at 21.2
  ~SingleLink();
  SingleLink(const SingleLink &);
  SingleLink& operator=(SingleLink);
  
};


template <typename T>
void  SingleLink<T>::append_back(T dat){
	cout<<"!!APPEND!!"<<endl;
	Node<T>* n = new Node<T>(dat);
	if (tail_ != nullptr){
		tail_->next_ = n;
		tail_ = n;
    }
    else {
		head_=n;
		tail_=n;
    }

}

template <typename T>
SingleLink<T>::SingleLink(T dat){
	Node<T>* ptr = new Node<T>(dat);
    head_ = ptr;
    tail_ = ptr;
}

template<typename T>
SingleLink<T>::~SingleLink(){
    Node<T>* to_del = head_;
    while (to_del != nullptr){
		head_ = head_->next_;
		delete to_del;
		to_del = head_;
    }
    head_ = nullptr;
    tail_ = nullptr;
}

#endif
  
