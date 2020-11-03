#ifndef NUMBER_HPP_INCLUDED
#define NUMBER_HPP_INCLUDED

#include <string>

using namespace std;

class Number {
    public:
        void get_value (data) {
            value = data;
            type = check_type();
            cout << endl << "O numero " << value << " tem o tipo primitivo " << type;
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

                default:
                    return 'd';
            }
        }
};

#endif