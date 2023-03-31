#include <iostream>
#include "sources/game.hpp"
#include "sources/card.hpp"
#include "sources/player.hpp"

using namespace ariel;
using namespace std;

int main() {
    Player p1("p1");
    Player p2("p2");
    Game game(p1, p2);
    // cout << p1.getName() << "," << p1.getStack().size() << endl;
    cout << p1.getName() << ", " << p1.getStack().back().toString() << endl;
}
