
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

        Card(const Card& card) noexcept; // copy constructor

        Card& operator=(const Card& other); // copy assignment operator

        Card(int number, int sign); // constructor

        Card(Card&& other) noexcept; // move constructor

        Card& operator=(Card&& other) noexcept; // move assignment operator

        ~Card();

        int getNumber();

        string getSign();

        string toString();
    };
}