
#include <iostream>
#include "game.hpp"
#include "player.hpp"

using namespace std;

namespace ariel {

    Game::Game() {}

    Game::Game(Player player1, Player player2) {}

    Game::Game(const Game& game) noexcept{}

    Game& Game::operator=(const Game& other) {return *this;} // copy assignment operator

    Game& Game::operator=(Game&& other) noexcept {return *this;} // move assignment operator

    Game::Game(Game&& other) noexcept {} // move constructor

    Game::~Game() {}

    void Game::playTurn() {}

    void Game::printLastTurn() {}

    void Game::playAll(){}

    void Game::printWiner(){}

    void Game::printLog(){}

    void Game::printStats(){}
    
    Player Game::getWinner() {return Player("Moshe");}

    int Game::getDeck() {return 1;}

    void Game::setDeck(int newAmount) {}

}