#ifndef TRANSLATE_HPP_INCLUDED
#define TRANSLATE_HPP_INCLUDED

#include "manipulation.hpp"
#include <string>
#include <math.h>

using namespace std;

class Binary {
    public:
        string binary (string value) {
            return value;
        }

        string octal (string value) {
            return "?";
        }

        string decimal (string value) {
            int dec_number = 0; // Número decimal

            value = remove_id(value, 2); // Removendo o '0b'
            value = reverse(value); // Invertendo o número

            // Transformando em decimal
            for (int bit_pos = 0; bit_pos < value.length(); bit_pos++) {
                if (value[bit_pos] == '1')
                    dec_number += pow(2, bit_pos);
            }

            dec_number -= 1;
            value = to_string(dec_number); // Transformando em String

            return value;
        }

        string hex (string value) {
            return "?";
        }
};

class Octal {
    public:
        string binary (string value) {
            return "?";
        }

        string octal (string value) {
            return value;
        }

        string decimal (string value) {
            return "?";
        }

        string hex (string value) {
            return "?";
        }
};

class Decimal {
    public:
        string binary (string value) {
            return "?";
        }

        string octal (string value) {
            return "?";
        }

        string decimal (string value) {
            return value;
        }

        string hex (string value) {
            return "?";
        }
};

class Hex {
    public:
        string binary (string value) {
            return "?";
        }

        string octal (string value) {
            return "?";
        }

        string decimal (string value) {
            return "?";
        }

        string hex (string value) {
            return value;
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