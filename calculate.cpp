//Calculate.cpp
//By: Sophia Moore
//Created on: 10/22/20

#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char *argv[])
{
    int number_1 = atoi(argv[1]);
    int number_2 = atoi(argv[3]);
    char *function = argv[2];

    if(argc == 4) //counting the operator as an argument
    {
        if( (*function == '%') && (number_2 == 0) )
        {
            cerr << "Cannot divide by zero.\n";
        }

        else if(*function == '+')
        {
            int add = number_1 + number_2;
            cout << add << endl;
        }

        else if(*function == 'x')
        {
            int multiply = number_1 * number_2;
            cout << multiply << endl;
        }
        
        else if(*function == '%')
        {
            int modulo = number_1 % number_2;
            cout << modulo << endl;
        }

        else // a function other than +x% is used
        {
            cerr << "Bad operation choice.\n";
        }
    }

    else // (argc != 4)
    {
        cerr << "Number of arguments is incorrect.\n";
    }

    return 0;
}
