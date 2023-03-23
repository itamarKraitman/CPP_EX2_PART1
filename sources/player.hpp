#pragma once 

#include <iostream>
#include <string>

using namespace std;

namespace ariel{
    class Player {
        string name;
        int stack;
        int taken;
        double winRate;
        int cardsWon;
        double drawRate;
        int amountOfDraws;

        public:
        
        Player();

        Player(string name); // constructor

        Player(const Player& player) noexcept; // copy constructor

        Player& operator=(const Player& other); // copy assignment operator

        Player(Player&& other) noexcept; // move constructor

        Player& operator=(Player&& other) noexcept; // move assignment operator

        ~Player();

        string getName();

        int stacksize();

        int cardesTaken();
    };
}