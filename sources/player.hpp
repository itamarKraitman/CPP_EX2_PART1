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

        Player::Player(const Player& player);

        ~Player();

        string getName();

        int stacksize();

        int cardesTaken();
    };
}