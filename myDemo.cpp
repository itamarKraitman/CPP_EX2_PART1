#include <iostream>
#include "sources/game.hpp"
#include "sources/card.hpp"
#include "sources/player.hpp"

using namespace ariel;
using namespace std;

int main() {
    Card c(4, Spades);
    cout << c.toString();
    Player p1("p1");
    Player p2("p2");
    Game g(p1, p2);
}
