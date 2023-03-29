
#include "card.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>

using namespace std;

namespace ariel
{
    Card::Card() {}

    Card::Card(int number, signs sign) // constructor
    {
        try
        {
            if (number < 1 || number > 13)
            {
                throw invalid_argument("Either number or sign are invalid");
            }
            else
            {
                this->number = number;
                this->sign = sign;
            }
        }
        catch (const exception &e)
        {
            cout << e.what() << endl;
        }
    }

    Card::Card(const Card &card) noexcept
    {
        try
        {
            this->number = card.number;
            this->sign = card.sign;
        }
        catch (const logic_error &e)
        {
            cerr << e.what() << endl;
        }
    }

    Card &Card::operator=(const Card &other) { return *this; }

    Card &Card::operator=(Card &&other) noexcept { return *this; } // move assignment operator

    Card::Card(Card &&other) noexcept {}

    Card::~Card() {} // distructor

    int Card::getNumber() const
    {
        return stoi(this->number);
    }

    signs Card::getSign() const
    {
        return this->sign;
    }

    string Card::toString()
    {
        ostringstream s;
        s << this->number << " of " << this->sign;
        return s.str();
    }
}