#include <iostream>

using namespace std;

string name_in(string str_var) {
    cout << "\nEnter a name: ";
    cin >> str_var;
    cout << str_var << endl;
    return str_var;
}

int num_in(int num) {
    cout << "Enter an integer: ";
    cin >> num;
    cout << num << endl;
    return num;
}

int main() {
    string str_var;
    int num;
    name_in(str_var);
    num_in(num);
    return 0;
}

// Compile: g++ -o some_name filename.cpp
// Run: ./some_name