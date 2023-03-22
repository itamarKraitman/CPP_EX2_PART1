#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>
#include "doctest.h"
#include "sources/card.hpp"
#include "sources/game.hpp"
#include "sources/player.hpp"
#include <random>

using namespace ariel;
using namespace std;

// testing Card

TEST_CASE("invalid number throws invalid argument exception")
{
    for (int i = 0; i < 100; i++)
    {
        int number = rand() % 100;
        if (i % 5 == 0) // check negative inputs every 5'th enrty
        {
            number *= -1;
        }
        if (number < 1 || number > 13)
        {
            CHECK_THROWS(Card(number, 1));
        }
    }
}

TEST_CASE("invalid sign throws invalid argument exception")
{
    for (int i = 0; i < 100; i++)
    {
        int sign = rand() % 100;
        if (i % 5 == 0) // check negative inputs every 5'th enrty
        {
            sign *= -1;
        }
        if (sign < 1 || sign > 4)
        {
            CHECK_THROWS(Card(1, sign));
        }
    }
}

TEST_CASE("Card's getNumber returns matching value")
{
    for (int i = 1; i <= 13; i++)
    {
        Card card(i, 1);
        CHECK_EQ(card.getNumber(), i);
    }
}

TEST_CASE("Card's getSign returns matching value")
{
    for (int i = 1; i <= 4; i++)
    {
        Card card(1, i);
        CHECK_EQ(card.getSign(), i);
    }
}

TEST_CASE("Cards's to_String returns matchig string")
{
    // check for each number and sign combination
    for (int i = 1; i <= 13; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            Card card(i, j);
            stringstream s;
            CHECK_EQ(card.to_string(), s << "number: " << i << "sign: " << j);
        }
    }
}

// test Player

TEST_CASE("Player is constructed as expected")
{
    Player player("Moshe");
    CHECK_EQ(player.cardesTaken(), 0); // in the beggining of the game each player has 28 cards and did'nt take any
    CHECK_EQ(player.stacksize(), 28);
}

// test Game

Player p1("Moshe");
Player p2("Avi");
Game game(p1, p2);

// test both playAll and getWinner
TEST_CASE("Game stopped when one player wins- he has all the cards (56)")
{
    for (int i = 0; i < 100; i++)
    {
        game.playAll(); 
        Player winner = game.getWinner();
        CHECK_EQ(game.getWinner().stacksize(), 56);
    }
}




