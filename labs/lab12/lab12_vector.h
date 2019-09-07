#include<algorithm>
using std::copy;
#include<initializer_list>
using std::initializer_list;
#include<iostream>
using std::endl; using std::cout;


namespace student {
	template<typename T>
	class vector{
		private:
			//pointer to dynamically allocated memory
			T * data_;
			
			//how many elemetns vector can hold without having to grow
			size_t capacity_ = 10;
			
			//num of elements in vector
			size_t size_ = 0;
		public:
			//defualt constructor
			vector() = default;
			
			//constructor method with capacity
			vector(size_t c){
				//set capacity__ to the arg or 10
				capacity_ = c;
				
				//set size_ = 0
				size_ = 0;
				
				//set data_ ro point to memory element
				data_ = new T[capacity_];
				
			}
			
			//constructor with initializer-list
			vector(initializer_list<T> list){
				capacity_ = list.size();
				size_ = list.size();
				data_ = new T[size_];
				
				//copy values from initializer-list to data_
				copy(list.begin(),list.end(), data_);
			}
			
			size_t capacity(){
				return capacity_;
			}
			
			size_t size(){
				return size_;
			}
			
			void push_back(T val){
				if(size_ <= capacity_){			
					//append element to end of data_ if not at capacity
					cout<<"in here: "<<endl;
					copy(val, data_);
					//update size_
					size_ += 1;
				}
				//exceeds capacity
				else{
					vector<T> new_data;
					//create new memory with twice the size
					new_data.data_ = new T[(capacity_ * 2)];
					cout<<"almost"<<endl;
					//copy elements of data_ to new_data
					for(int i = 0; i <= size_; i++){
						new_data.data_[i] = data_[i];
					}
					cout<<"made it"<<endl;
					
					for(int d = 0; d <= size_; d++){
						cout<<"d: "<<new_data.data_[d]<<endl;
					}

					
				}
			}
			
			
			
			//T& operator[](size_t val);
		
	};
}


