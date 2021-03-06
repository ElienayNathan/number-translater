#ifndef TRANSLATE_HPP_INCLUDED
#define TRANSLATE_HPP_INCLUDED

#include "manipulation.hpp"
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

string turn_bin (string value) {
    int n = stoi(value);
    string bin_value;

    while (n != 0) {
        int bit = n % 2;
        bin_value += to_string(bit);

        n = n / 2;
        bit = 0;
    }

    bin_value = reverse(bin_value);
    return "0b" + bin_value;
}

string turn_octal (string value) {
    int n = stoi(value);
    n = (n / 8) * 10 + n % 8;

    return '0' + to_string(n);
}

string turn_hex (string value) {
    char list[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    string hex_value;
    int n = stoi(value);

    while (n != 0) {
        int temp = n % 16;
        hex_value += list[temp];

        n = n / 16;
        temp = 0;
	}

    hex_value = reverse(hex_value);
    return "0x" + hex_value;
}

class Binary {
    public:
        string binary (string value) {
            return value;
        }

        string octal (string value) {
            value = decimal(value);
            
            return turn_octal(value);
        }

        string decimal (string value) {
            int dec_number = 0; // Número decimal

            value = remove_id(value, 2); // Removendo o '0b'
            value = reverse(value); // Invertendo o número

            // Transformando em decimal
            for (int bit_pos = 0; bit_pos < value.length(); bit_pos++)
                dec_number += (value[bit_pos] - '0') * pow(2, bit_pos);

            value = to_string(dec_number); // Transformando em String

            return value;
        }

        string hex (string value) {
            value = decimal(value);

            return turn_hex(value);
        }
};

class Octal {
    public:
        string binary (string value) {
            value = decimal(value);

            return turn_bin(value);
        }

        string octal (string value) {
            return value;
        }

        string decimal (string value) {
            int dec_number = 0; // Número decimal

            value = remove_id(value, 1); // Removendo o '0'
            value = reverse(value); // Invertendo o número

            // Transformando em decimal
            for (int oc_pos = 0; oc_pos < value.length(); oc_pos++)
                dec_number += (value[oc_pos] - '0') * pow(8, oc_pos);

            value = to_string(dec_number); // Transformando em String

            return value;
        }

        string hex (string value) {
            value = decimal(value);

            return turn_hex(value);
        }
};

class Decimal {
    public:
        string binary (string value) {
            return turn_bin(value);
        }

        string octal (string value) {
            return turn_octal(value);
        }

        string decimal (string value) {
            return value;
        }

        string hex (string value) {
            return turn_hex(value);
        }
};

class Hex {
    public:
        string binary (string value) {
            value = decimal(value);

            return turn_bin(value);
        }

        string octal (string value) {
            value = decimal(value);

            return turn_octal(value);
        }

        string decimal (string value) {
            int dec_number = 0; // Número decimal

            value = remove_id(value, 2); // Removendo o '0'
            value = reverse(value); // Invertendo o número

            // Transformando em decimal
            for (int hex_pos = 0; hex_pos < value.length(); hex_pos++)
                dec_number += (hex_to_dec(value[hex_pos])) * pow(16, hex_pos);

            value = to_string(dec_number); // Transformando em String

            return value;
        }

        string hex (string value) {
            return value;
        }

    private:
        // Convertendo um caractere hexadecimal para um número decimal
        int hex_to_dec (char hex) {
            switch(hex) {
                case 'A':
                    return 10;
                case 'B':
                    return 11;
                case 'C':
                    return 12;
                case 'D':
                    return 13;
                case 'E':
                    return 14;
                case 'F':
                    return 15;
            }

            return hex - '0';
        }
};

class Translator {
    public:
        // Função para traduzir
        string trans_value (string data, char data_type, char trans_type) {
            switch (data_type) {
                case 'b':
                    return trans_bin(data, trans_type);

                case 'o':
                    return trans_octal(data, trans_type);

                case 'd':
                    return trans_dec(data, trans_type);

                case 'x':
                    return trans_hex(data, trans_type);
            };

            return data; // Medida de prevenção para caso haja algum erro
        }

    private:
        Binary bin; // Tipo primitivo original binário
        Octal octal; // Tipo primitivo original octal
        Decimal dec; // Tipo primitivo original decimal
        Hex hex; // Tipo primitivo original hexadecimal

        // Função para traduzir valores originalmente binários
        string trans_bin (string data, char type) {
            switch (type) {
                case 'b':
                    return bin.binary(data);

                case 'o':
                    return bin.octal(data);

                case 'd':
                    return bin.decimal(data);

                case 'x':
                    return bin.hex(data);
            };

            return data; // Medida de prevenção para caso haja algum erro
        }

        string trans_octal (string data, char type) {
            switch (type) {
                case 'b':
                    return octal.binary(data);

                case 'o':
                    return octal.octal(data);

                case 'd':
                    return octal.decimal(data);

                case 'x':
                    return octal.hex(data);
            };

            return data; // Medida de prevenção para caso haja algum erro
        }

        string trans_dec (string data, char type) {
            switch (type) {
                case 'b':
                    return dec.binary(data);

                case 'o':
                    return dec.octal(data);

                case 'd':
                    return dec.decimal(data);

                case 'x':
                    return dec.hex(data);
            };

            return data; // Medida de prevenção para caso haja algum erro
        }

        string trans_hex (string data, char type) {
            switch (type) {
                case 'b':
                    return hex.binary(data);

                case 'o':
                    return hex.octal(data);

                case 'd':
                    return hex.decimal(data);

                case 'x':
                    return hex.hex(data);
            };

            return data; // Medida de prevenção para caso haja algum erro
        }
};

#endif