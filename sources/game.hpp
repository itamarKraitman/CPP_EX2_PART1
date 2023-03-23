
#pragma once 

#include "player.hpp"
#include <iostream>
#include <string>

using namespace std;

namespace ariel {
    class Game {
        Player p1;
        Player p2;
        string winner;

        public:

        Game();

        Game(Player player1, Player player2); // constructor

        Game(const Game& game) noexcept; // copy constructor

        Game& operator=(const Game& other); // copy assignment operator

        Game(Game&& other) noexcept; // move constructor

        Game& operator=(Game&& other) noexcept; // move assignment operator

        ~Game();

        void playTurn();

        void printLastTurn();

        void playAll();

        void printWiner();

        void printLog();

        void printStats();

        Player getWinner();
    };
}
