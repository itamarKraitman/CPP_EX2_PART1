
#include "player.hpp"
#include <iostream>
#include <string>

using namespace std;

namespace ariel {
    class Game {
        Player p1;
        Player p2;

        public:

        Game(Player player1, Player p2);

        void playTurn();

        void printLastTurn();

        void playAll();

        void printWiner();

        void printLog();

        void printStats();
    };
}