
#include <iostream>
#include <string>
#include "player.hpp"

using namespace std;

namespace ariel {

    Player::Player() {}

    Player::Player(string name) {}

    Player::Player(const Player& player) {}

    Player::~Player() {}

    string getName() {return "!";}

    int Player::stacksize() {return 1;}

    int Player::cardesTaken() {return 1;}
}

