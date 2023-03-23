
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

        Game(Player player1, Player player2);

        Game::Game(const Game& game);

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
