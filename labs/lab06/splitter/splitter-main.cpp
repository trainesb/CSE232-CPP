#include<iostream>
#include<string>
#include<vector>

using std::cout;using std::endl;using std::cin;
using std::vector;
using std::string; using std::getline;

#include"splitter-functions.h"

int main() {
    string input;
    char c;
    vector<string> vector;
    getline(cin, input);
    cin>>input>>std::noskipws>>c;
    split(input, vector, c);
    print_vector(cout, vector);
}
