
#include "card.hpp"
#include <iostream>
#include <string>

using namespace std;

namespace ariel {

    Card::Card() {}
    
    Card::Card(int number, int sign) {} // constructor

    Card::Card(const Card& card) noexcept {}

    Card& Card::operator=(const Card& other) {return *this;}

    Card& Card::operator=(Card&& other) noexcept {return *this;} // move assignment operator

    Card::Card(Card&& other) noexcept{}

    Card::~Card() {} // distructor
    
    int Card::getNumber() {return 1;}

    string Card::getSign() {return "1";}

    string Card::toString() {return "1";}
}