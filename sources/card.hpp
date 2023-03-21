
#include <string.h>
#include <iostream>

using namespace std;

namespace ariel {
    class Card
    {
        int number; // 1-13 (11=prince, 12=queen, 13=king)
        string sign; // clubs (♣), diamonds (♦), hearts (♥), and spades (♠)

        public:

        Card(int number, int sign);

        int getNumber();

        string getSign();

        string to_string();
    };
}