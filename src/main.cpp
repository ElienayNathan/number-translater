#include <iostream>
#include "number.hpp"

using namespace std;

int main () {
    Number number;
    string user_number;

    cout << "Escreva um numero: ";
    cin >> user_number;
    number.set_value(user_number);

    cout << endl << endl << "Em binario, isso vale: "
        << number.trans(number.get_value(), number.get_type(), 'b');

    cout << endl << "Em octal, isso vale: "
        << number.trans(number.get_value(), number.get_type(), 'o');

    cout << endl << "Em decimal, isso vale: "
        << number.trans(number.get_value(), number.get_type(), 'd');

    cout << endl << "Em hexadecimal, isso vale: "
        << number.trans(number.get_value(), number.get_type(), 'x');

    system("pause > nul");
    
    return 0;
}