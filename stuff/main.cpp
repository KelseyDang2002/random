#include <iostream>

using namespace std;

// function asks for user string input
void name_in(string str_var) {
    cout << "\nEnter a name: ";
    getline(cin, str_var);
    cout << "Hello, " << str_var << ". ";
}

// function asks for user integer input
void num_in(int num1) {
    cout << "Enter an integer: ";
    cin >> num1;
    cout << "You entered the number " << num1 << ".\n";
}

// driver
int main() {
    string str_var;
    string jdm[] = {"Honda", "Toyota", "Mazda", "Nissan", "Subaru"};
    string euro[] = {"BMW", "Mercedes", "Audi", "Porsche", "Volkswagen"};
    string us[] = {"Ford", "Chevrolet", "Dodge", "Cadillac", "Tesla"};
    int num1, num2, num3;
    name_in(str_var);
    num_in(num1);
    cout << "Enter an integer(1-3): ";
    cin >> num2;
    cout << "You entered " << num2 << ".\n";
    cout << "Enter another integer(0-4): ";
    cin >> num3;
    cout << "You entered " << num3 << ".\n";

    if (num3 < 0 || num3 > 4) {
        cout << "Invalid input.\n";
        return -1;
    }

    if(num2 == 1) {
        cout << "Your car is a " << jdm[num3] << "!\n";
    }
    else if (num2 == 2) {
        cout << "Your car is a " << euro[num3] << "!\n";
    }
    else if (num2 == 3) {
        cout << "Your car is a " << us[num3] << "!\n";
    }
    else {
        cout << "Invalid input.\n";
        return -1;
    }

    return 0;
}

// Compile: g++ -o some_name filename.cpp
// Run: ./some_name