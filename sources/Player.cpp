
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
}

