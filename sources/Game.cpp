
#include <iostream>
#include "game.hpp"
#include "player.hpp"

using namespace std;

namespace ariel {
    Game::Game(Player player1, Player player2) {
        this->p1 = player1;
        this->p2 = player1;
    }

    void Game::playTurn() {}

    void Game::printLastTurn() {}

    void Game::playAll(){}

    void Game::printWiner(){}

    void Game::printLog(){}

    void Game::printStats(){}
}