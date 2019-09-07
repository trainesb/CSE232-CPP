#include<iostream>
using std::cout; using std::cin; using std::endl;
#include<iomanip>
using std::boolalpha;
#include<string>
using std::string;
#include<stdexcept>
using std::runtime_error;


#include "lab10_circbuf.h"

CircBuf::CircBuf(size_t s){
	sz_ = s;
	cnt_ = 0;
	for(auto i=0; i < s; ++i){
			buf_[i] = 0;
	}
	head_ = 0;
	tail_ = 0;
}

CircBuf::CircBuf(initializer_list<long> l, size_t buf){
	if(l.size()<buf){
		throw runtime_error("Error");
	}
	else{
		sz_ = buf;
		buf_.insert(buf_.end(), l.begin(), l.end());
		if(l.size()<buf){
			for(int j=(buf-l.size()); j > 0; --j){
				buf_.push_back(0);
			}
		}
	}
}
		

long CircBuf::front() const{
	if(buf_.empty()){
		throw runtime_error("Error");
	}
	else{
		long result;
		result = buf_.at(head_);
		return result;
	}
}

long CircBuf::back() const{
	if(buf_.empty()){
		throw runtime_error("Error");
	}
	else{
		head_ += 1;
		long result;
		result = buf_.at(tail_-1);
		return result;
	}
		
}

void CircBuf::remove(){
	if(buf_.empty()){
		throw runtime_error("Error");
	}
	else{
		head_ += 1;
	}
}

void CircBuf::add(long n){
	if(buf_.full()){
		throw runtime_error("Error");
	}
	else{
		buf_.at(tail_) = n;
		tail_ += 1;
	}
}


bool CircBuf::empty() const{
	if(buf_.size()==1)
		return true;
	else
		return false;
}

bool CircBuf::full() const{
	if(buf_.max_size()==tail_)
		return true;
	else
		return false;
}

ostream & operator<<(ostream &out, const CircBuf &cb){
  cout << "op<< function"<<endl;
  out << "Head:"<<cb.head_<<", tail:"
      <<cb.at(tail_-1)<<", cnt:"<<cb.cnt_<<", buf"
      <<cb.buf_;
  return out;
}
