
#include "card.hpp"
#include <iostream>
#include <string>

using namespace std;

namespace ariel {
    
    Card::Card(int number, int sign) {} // constructor

    Card::Card(const Card& card) {}

    Card::~Card() {} // distructor
    
    int Card::getNumber() {return 1;}

    string Card::getSign() {return "1";}

    string Card::toString() {return "1";}
}