#include<iostream>
using std::cout; using std::endl; using std::ostream;
#include<string>
using std::string;

#include "lab13_singlelink.h"

int main () {

  SingleLink<string>sl;
  sl.append_back("beds");
  cout<<sl<<endl;
  
}
