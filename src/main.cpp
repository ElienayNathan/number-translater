#include <iostream>

#include "number.hpp"

using namespace std;

int main () {
    Number number;
    string user_number;

    cout << "Escreva um numero: ";
    cin >> user_number;
    number.set_value(user_number);

    system("pause > nul");
    
    return 0;
}