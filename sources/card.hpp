
#pragma once 

#include <string>
#include <iostream>

using namespace std;

namespace ariel {
    class Card
    {
        int number; // 1-13 (11=prince, 12=queen, 13=king)
        string sign; // clubs (♣), diamonds (♦), hearts (♥), and spades (♠)

        public:

        Card();

        Card(const Card& card);

        Card(int number, int sign);

        ~Card();

        int getNumber();

        string getSign();

        string toString();
    };
}