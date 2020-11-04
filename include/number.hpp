#ifndef NUMBER_HPP_INCLUDED
#define NUMBER_HPP_INCLUDED

#include "translate.hpp"

#include <string>

using namespace std;

class Number {
    public:
        // Função para definir um valor
        void set_value (string data) {
            value = data;
            type = set_type();
        }

        // Função para pegar um valor
        string get_value () {
            return value; // Caso queira o valor original
        }

        // Função para pegar o tipo do valor
        char get_type () {
            return type;
        }

        // Função para retornar um valor traduzido
        string trans (string data, char data_type, char new_type) {
            return translator.trans_value(data, data_type, new_type);
        }

    private:
        string value; // Valor
        char type; // Tipo do valor original
        Translator translator; // Tradutor de tipos primitivos

        // Função para definir o tipo do valor
        char set_type () {
            switch (value[1]) {
                case 'b':
                    return 'b';

                case 'x':
                    return 'x';
            }

            if (value[0] == '0')
                return 'o';

            return 'd';
        }
};

#endif