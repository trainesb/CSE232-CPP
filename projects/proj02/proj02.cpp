/*
Project02
wfp 01/28/2018
Takes three inputs from the user, the frist and second dictate a range
of numbers. The third is a 0 or 1.  The program finds the range of
numbers between the two. The usses the Juggler Sequence and pints it for
each number in the range.  If the first number enterd is less then the 
second, an error is printed. if input one and two are less then two an
error is printed. If the third input is 1 the program displays the range
with its respective sequence, if 0 this is hidden.  Lastly the program 
prints the range with the longes sequence with the length as well as 
largest number in the sequence.
*/

#include<iostream>
using std::endl; using std::cout; using std::cin;
#include<cmath>
using std::floor; using std::pow; using std::sqrt;

int main() {
	long input01, input02, input03, max_range=0, max_count=0, max_num=0;
	cin>>input01;
	cin>>input02;
	cin>>input03;
	
	if(input01<2){
		cout<<"Error"<<endl;
		return 0;
	}
	else if(input02<2){
		cout<<"Error"<<endl;
		return 0;
	}
	else if(input01>input02){
		cout<<"Error"<<endl;
		return 0;
	}
	
	int i, j=input02;
	for(i=input01; i <= j; ++i){
		if(input03!=0)
			cout<<i<<": ";
		long num = i, count=0, max=0;
		while(num!=1){
			if(num%2==0){
				num = floor(sqrt(num));
				count += 1;
				if(num>max)
					max=num;
				if(input03!=0){	
					if(num!=1)
						cout<<num<<',';
					else
						cout<<num;
				}
				continue;
			}
			else{
				num = floor(sqrt(pow(num,3)));
				count += 1;
				if(num>max)
					max=num;
				if(input03!=0)
					cout<<num<<',';
				continue;
			}
		}
		cout<<endl;	
		if(count>max_count){
			max_count = count;
			max_range = i;
			max_num = max;
		}
	}
	cout<<max_range<<", "<<max_count<<endl;
	cout<<max_range<<", "<<max_num<<endl;
}
