
#include <iostream>
#include <string>
#include "player.hpp"

using namespace std;

namespace ariel {

    Player::Player() {}

    Player::Player(string name) {}

    Player::Player(const Player& player) noexcept {}

    Player& Player::operator=(const Player& other) {return *this;} // copy assignment operator

    Player::Player(Player&& other) noexcept {} // move constructor

    Player& Player::operator=(Player&& other) noexcept {return *this;} // move assignment operator

    Player::~Player() {}

    string Player::getName() {return "!";}

    int Player::stacksize() {return 1;}

    int Player::cardesTaken() {return 1;}

    void Player::putCard() {} // puts the next card in player's deck

    void Player::addCardsToPlayerDeck() {}

    void Player::setStack(int numOfCardsToReduce) {}

    void Player::setStack(Card card) {}

    double Player::getWinRate() {return this->winRate;}

    void Player::setWinRate() {}

    double Player::getDrawRate() {return this->drawRate;}

    void Player::setDrawRate() {}

    int Player::getNumberOfDraws() {return this->drawsHappened;}

    void Player::setNumberOfDraws() {}
}

