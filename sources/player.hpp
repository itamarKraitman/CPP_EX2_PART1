#include <iostream>
#include <string>

using namespace std;

namespace ariel{
    class Player {
        string name;
        int stack;
        int taken;

        public:
        
        Player();

        Player(string name); // constructor

        void stacksize();

        void cardsTaken();
    };
}