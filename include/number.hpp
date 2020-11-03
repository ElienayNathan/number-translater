#ifndef NUMBER_HPP_INCLUDED
#define NUMBER_HPP_INCLUDED

#include <string>

using namespace std;

class Number {
    public:
        void set_value (string data) {
            value = data;
            type = check_type();
            cout << endl << "O numero " << value << " tem o tipo primitivo " << type;
        }

        string get_value () {
            return value;
        }

    private:
        string value;
        char type;

        char check_type () {
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