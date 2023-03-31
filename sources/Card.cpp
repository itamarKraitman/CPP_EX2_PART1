
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
                switch (number)
                {
                case 1:
                    this->number = "Ace";
                    break;
                case 11:
                    this->number = "Prince";
                    break;
                case 12:
                    this->number = "Queen";
                    break;
                case 13:
                    this->number = "King";
                    break;
                default:
                    this->number = to_string(number);
                }
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

    string Card::getNumber() const
    {
        return this->number;
    }

    signs Card::getSign() const
    {
        return this->sign;
    }

    string Card::toString() const
    {
        string sgn;
        switch (sign)
        {
        case signs::Clubs:
            sgn = "Clubs";
            break;
        case signs::Diamonds:
            sgn = "Diamonds";
            break;
        case signs::Hearts:
            sgn = "Hearts";
            break;
        case signs::Spades:
            sgn = "Spades";
            break;
        }

        return this->number + " of " + sgn;
        // stringstream s;
        // string signString = signsString(this->sign);
        // s << (this->number + " of " + signString);
        // return s.str();
    }

    // string Card::signsString(signs sign)
    // {
    //     switch (sign)
    //     {
    //     case Clubs:
    //         return "Clubs";
    //     case Diamonds:
    //         return "Diamonds";
    //     case Hearts:
    //         return "Hearts";
    //     case Spades:
    //         return "Spades";
    //     default:
    //         return "";
    //     }
    // }
}