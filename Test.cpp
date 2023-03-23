#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <random>
#include "doctest.h"
#include "sources/card.hpp"
#include "sources/game.hpp"
#include "sources/player.hpp"

using namespace ariel;
using namespace std;

// testing Card

TEST_CASE("Card's methods do not throw errors")
{
    CHECK_NOTHROW(Card(1,1));
    Card card(1,1);
    CHECK_NOTHROW(card.getNumber());
    CHECK_NOTHROW(card.getSign());
    CHECK_NOTHROW(card.toString());
}

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
        CHECK_EQ(card.getSign(), to_string(i));
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
            s << "number: " << i << "sign: " << j;
            CHECK_EQ(card.toString(), s.str());
        }
    }
}

// test Player

TEST_CASE("Player is constructed as expected")
{
    CHECK_NOTHROW(Player("Moshe"));
    Player player("Moshe");
    CHECK_NOTHROW(player.cardesTaken());
    CHECK_EQ(player.cardesTaken(), 0); // in the beggining of the game each player has 28 cards and did'nt take any
    CHECK_NOTHROW(player.stacksize());
    CHECK_EQ(player.stacksize(), 28);
}


// test Game

TEST_CASE("All Game's methods do not throw errors")
{
    Player p1("Moshe");
    Player p2("Avi");
    CHECK_NOTHROW(Game(p1,p2));
    Game game(p1, p2);
    SUBCASE("player can be registred onlly to one game")
    {
        Player p3("Amit");
        CHECK_THROWS_MESSAGE(Game(p1,p3), "Player can be registred only to one game!");
    }
    CHECK_NOTHROW(game.playTurn());
    CHECK_NOTHROW(game.printLastTurn());
    CHECK_NOTHROW(game.playAll());
    CHECK_NOTHROW(game.printWiner());
    CHECK_NOTHROW(game.printLog());
    CHECK_NOTHROW(game.printStats());
}

// test both playAll and getWinner
TEST_CASE("Game stopped when one player wins- he has all the cards (56)")
{
    Player p1("Moshe");
    Player p2("Avi");
    Game game(p1, p2);
    for (int i = 0; i < 100; i++)
    {
        game.playAll(); 
        Player winner = game.getWinner();
        CHECK_EQ(game.getWinner().stacksize(), 52);
    }
}

TEST_CASE("After each turn the amount of cards is changed for both players")
{
    Player p1("Moshe");
    Player p2("Avi");
    Game game(p1, p2);
    game.playTurn();
    bool a1 = p1.cardesTaken() > 0;
    bool a2 = p2.cardesTaken() > 0;
    bool a = a1 || a2; 
    CHECK(a);
    bool b1 = p1.stacksize() < 26;
    bool b2 = p2.stacksize() < 26;
    bool b = b1 || b2;
    CHECK(b);
}



