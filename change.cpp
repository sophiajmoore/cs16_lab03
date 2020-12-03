//Change.cpp
//By: Sophia Moore
//Created on: 10/22/20

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void compute_coins(int amount);
//Pre_condition: takes the user amount in cents
//Post_condition: returns the user amount in number of coins

int main() 
{
    int user_cents(0);

    cout << "Enter number of cents (or zero to quit):\n";
    cin >> user_cents;

    while (user_cents != 0) // quits if user_cents != 0
    {
        if( (user_cents > 0) && (user_cents <= 99 ) ) 
        {
            compute_coins(user_cents);
            
            cout << "Enter number of cents (or zero to quit):\n";
            cin >> user_cents;
        }

        else // ( (user_cents < 0) || (user_cents >= 99 ) ) 
        {
            cout << "Amount is out of bounds. Must be between 1 and 99.\n";

            cout << "Enter number of cents (or zero to quit):\n";
            cin >> user_cents;
        } 
    }

    return 0;
}

void compute_coins(int amount) 
{

    int quarters(0), dimes(0), nickels(0), pennies(0), amount_new(0);
    string q_string, d_string, n_string, p_string, amount_string;

    quarters = amount/25; //this will be an int because that's the variable type
    amount_new = amount - quarters*25; //this subtracts the amount of quarters in $$ from the OG amount after finding the # of quarters

    dimes = amount_new/10; //using the new amount after subtracting the amount of quarters
    amount_new = amount_new - dimes*10;

    nickels = amount_new/5;
    amount_new = amount_new - nickels*5;

    pennies = amount_new;

    //quarters: determining if plural or singular
    if (quarters > 1) 
    {
        if ( (dimes > 0) || (nickels > 0) || (pennies > 0))
        {
            q_string = to_string(quarters) + " quarters, ";
        }
        else //the rest are 0, so it ends in a period
        {
            q_string = to_string(quarters) + " quarters.";
        }
    }

    else if (quarters == 1)
    {
        if ( (dimes > 0) || (nickels > 0) || (pennies > 0))
        {
            q_string = to_string(quarters) + " quarter, ";
        }
        else //the rest are 0
        {
            q_string = to_string(quarters) + " quarter.";
        }
    }
    
    //dimes
    if (dimes > 1)
    {
        if ( (nickels > 0) || (pennies > 0))
        {
            d_string = to_string(dimes) + " dimes, ";
        }
        else //the rest are 0
        {
            d_string = to_string(dimes) + " dimes.";
        }
    }

    else if (dimes == 1)
    {
        if ( (nickels > 0) || (pennies > 0))
        {
            d_string = to_string(dimes) + " dime, ";
        }
        else //the rest are 0
        {
            d_string = to_string(dimes) + " dime.";
        }
    }

    //nickels
    if (nickels > 1)
    {
        if (pennies > 0)
        {
            n_string = to_string(nickels) + " nickels, ";
        }
        else //the rest are 0
        {
            n_string = to_string(nickels) + " nickels.";
        }
    }

    else if (nickels == 1)
    {
        if (pennies > 0)
        {
            n_string = to_string(nickels) + " nickel, ";
        }
        else //the rest are 0...
        {
            n_string = to_string(nickels) + " nickel.";
        }
    }

    //pennies
    if (pennies > 1)
    {
        p_string = to_string(pennies) + " pennies."; //pennies will always end in a period because it's last in line
    }

    else if (pennies == 1)
    {
        p_string = to_string(pennies) + " penny.";
    }

    if (amount == 1)
    {
        cout << amount << " cent can be given in "
             << q_string 
             << d_string
             << n_string
             << p_string << endl;
    }

    else if (amount != 1)
    {
        cout << amount << " cents can be given in "
             << q_string 
             << d_string
             << n_string
             << p_string << endl;
    }
    return;
}


