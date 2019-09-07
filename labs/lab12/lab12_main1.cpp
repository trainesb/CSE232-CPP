
#include <iostream>
using std::cout;
using std::endl;
#include "lab12_vector.h"
using student::vector;

int main ()
{
    vector<long> v;
    cout << "Size     : " << v.size() << endl;
    cout << "Capacity : " << v.capacity() << endl<<endl<<endl;
    
    vector<char> v_c={'a','b','c','d'};
    cout << "Size     : " << v_c.size() << endl;
    cout << "Capacity : " << v_c.capacity() << endl<<endl<<endl;
    
    for(auto i = 0l; i < 12; i++) {
        v.push_back(i);
    }
    cout << "Size     : " << v.size() << endl;
    cout << "Capacity : " << v.capacity() << endl;

}

