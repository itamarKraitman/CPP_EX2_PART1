
#include <iostream>
#include "game.hpp"
#include "player.hpp"

using namespace std;

namespace ariel {
    Game::Game(Player player1, Player player2) {}

    Game::Game(const Game& game) {}

    Game::~Game() {}

    void Game::playTurn() {}

    void Game::printLastTurn() {}

    void Game::playAll(){}

    void Game::printWiner(){}

    void Game::printLog(){}

    void Game::printStats(){}
    
    Player Game::getWinner() {return Player("Moshe");}

}