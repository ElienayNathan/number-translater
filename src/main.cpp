#include <iostream>

#include "number.hpp"

using namespace std;

int main () {
    Number number;

    cout << "Escreva um número: ";
    cin >> number.get_value();

    system("pause > nul");
    
    return 0;
}