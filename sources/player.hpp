#pragma once 

#include <iostream>
#include <string>
#include <vector>
#include "card.hpp"

using namespace std;

namespace ariel{
    class Player {
        private:

        string name;
        vector<Card> stack;
        int stackSize;
        int taken;
        bool isRegistred;
        double winRate;
        int wins;
        int cardsWon;
        double drawRate;
        int drawsHappened;

        public:

        Player(string name); // constructor

        Player(const Player& player) noexcept; // copy constructor

        Player& operator=(const Player& other); // copy assignment operator

        Player(Player&& other) noexcept; // move constructor

        Player& operator=(Player&& other) noexcept; // move assignment operator

        ~Player();

        string getName();

        bool registred();

        int stacksize();

        int cardesTaken();

        Card putCard(); // puts the next card in player's deck

        void addCardsToPlayerTaken(int amountToAdd);

        void setStack(int numOfCardsToReduce); // number of cards

        void setStack(Card card); // add card to stack

        double getWinRate();

        void setWinRate();

        double getDrawRate();

        void setDrawRate();

        int getNumberOfDraws();

        void setNumberOfDraws();

        int getWins();

        void setWins();
    };
}