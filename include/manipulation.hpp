#ifndef MANIPULATION_HPP_INCLUDED
#define MANIPULATION_HPP_INCLUDED

#include <iostream>
#include <string>

using namespace std;

// Função para remover o identificador de um número
string remove_id (string number, int identifiers_number) {
    string new_number = "";

    for (int i = identifiers_number; i < number.length(); i++)
        new_number += number[i];

    return new_number;
}

// Função para inverter um número
string reverse (string number) {
    string new_number;

    for (int i = 0; i < number.length(); i++)
        new_number = number[i] + new_number;

    return new_number;
}

#endif