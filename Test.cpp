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
    CHECK_NOTHROW(Card(1, 1));
    Card card(1, 1);
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
    CHECK_NOTHROW(Game(p1, p2));
    Game game(p1, p2);
    SUBCASE("player can be registred onlly to one game")
    {
        Player p3("Amit");
        // should threw an error because p1 is already registred to a game (p1.isRegistred = true)
        CHECK_THROWS_MESSAGE(Game(p1, p3), "Player can be registred only to one game!");
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
        SUBCASE("printWinner prints the actuall winner name")
        {
            stringstream actuallWinner;
            streambuf *winnerPrinted = cout.rdbuf();
            cout.rdbuf(actuallWinner.rdbuf());
            game.printWiner();
            cout.rdbuf(winnerPrinted); // store the message printed from printWiner
            CHECK(actuallWinner.str() == winner.getName());
        }
    }
}

TEST_CASE("After each turn the amount of cards is changed for both players")
{
    Player p1("Moshe");
    Player p2("Avi");
    Game game(p1, p2);
    game.playTurn();
    bool p1CardsTaken = p1.cardesTaken() > 0;
    bool p2CardsTaken = p2.cardesTaken() > 0;
    bool onePlayerWonCards = p1CardsTaken || p2CardsTaken;
    CHECK(onePlayerWonCards);
    bool p1StackSize = p1.stacksize() < 26;
    bool p2StackSize = p2.stacksize() < 26;
    bool bothPlayerStackLower = p1StackSize && p2StackSize;
    CHECK(bothPlayerStackLower);
}

TEST_CASE("Player with higher card wins the turn")
{
    Card c1(1, 1);
    Card c2(4, 1); // should win
    Player p1("Moshe");
    Player p2("Ori");
    Game g1(p1, p2);
    p1.setStack(c1);
    p2.setStack(c2); // p1 has higher card in the head of his deck
    SUBCASE("No cards left in main deck")
    {
        g1.setDeck(0); // remove all card form main deck
        g1.playAll();
        CHECK(g1.getWinner().getName() == "");
        CHECK(p1.cardesTaken() == 0);
        CHECK(p2.cardesTaken() == 0);
    }
    int p2CardsTeaken = p2.cardesTaken();
    int p1CardsTeaken = p1.cardesTaken();
    g1.playTurn();
    CHECK(p2CardsTeaken < p2.cardesTaken()); // p2 took the cards, so his cards Ttaken stack should be bigger now
    CHECK(p1CardsTeaken == p1.cardesTaken());
}

TEST_CASE("PrintLastTurn prints the correct turn log")
{
    Card c1(1, 1);
    Card c2(4, 1); // should win
    Player p1("Moshe");
    Player p2("Ori");
    Game g1(p1, p2);
    g1.playTurn();
    string printedMaeesage = "Moshe played Ace of Diamonds Ori played 4 of Diamonds. Ori wins.";
    stringstream actuallPrinted;
    streambuf *printed = cout.rdbuf();
    cout.rdbuf(actuallPrinted.rdbuf());
    g1.printLastTurn();
    cout.rdbuf(printed); // store the messgae printed from printLastTrun
    CHECK(actuallPrinted.str() == printedMaeesage);
}

TEST_CASE("War scenario")
{
    Card c1(1, 1);
    Card c2(1, 2);
    Card c3(2, 1);
    Card c4(3, 2);
    Card c5(2, 3);
    Card c6(3, 4);
    Player p1("Moshe");
    Player p2("Ori");
    Game g1(p1, p2);
    p1.setStack(c5);
    p2.setStack(c6);
    p1.setStack(c3);
    p2.setStack(c4);
    p1.setStack(c1);
    p2.setStack(c2);
    // stack look like this:
    // p1: head = 1 (war!) -> 2 (upsidedwon) -> 2 (loos)
    // p2: head = 1 (war!) -> 3 (upsidedwon) -> 3 (win)
    int p1Stack = p1.stacksize();
    int p2Stack = p2.stacksize();
    int p2Taken = p2.cardesTaken(); // should be increased by 6 after playing next turn
    // at this moment, p1 and p2 have cards with the same number in the head of their decks- draw should be called once and then p2 wins
    g1.playTurn();
    CHECK(p2.cardesTaken() == p2Taken + 6); // 2 cards from first draw, 2 upsidedwon, and 2 more.
    bool p1StackChanged = p1.stacksize() == p1Stack - 3;
    bool p2StackChanged = p2.stacksize() == p2Stack - 3;
    bool bothTrue = p1StackChanged && p2StackChanged;
    CHECK(bothTrue);
}

TEST_CASE("PrintLog works")
{
    Card c1(1, 0);
    Card c2(1, 2);
    Card c3(2, 1);
    Card c4(3, 3);
    Player p1("Moshe");
    Player p2("Ori");
    Game game(p1, p2);
    p1.setStack(c4);
    p2.setStack(c3);
    p1.setStack(c2);
    p2.setStack(c1);
    string logMessage = "Moshe played Ace of Hearts, Ori played Ace of Clubs. Draw. Moshe played 3 of Spades, Ori played 2 of Diamonds. Modhe wins."; // should be printed
    stringstream actuallPrinted;
    streambuf *printed = cout.rdbuf();
    cout.rdbuf(actuallPrinted.rdbuf());
    game.printLastTurn();
    cout.rdbuf(printed); // store the messgae printed from printStats
    CHECK(actuallPrinted.str() != "");
    CHECK(actuallPrinted.str() == logMessage);
}

TEST_CASE("printStats works")
{
    Player p1("Moshe");
    Player p2("Ori");
    Game game(p1, p2);
    SUBCASE("player runs out of cards during a war") {
        p1.setStack(0); // p1 has no cards
        Card c1(1, 0);
        Card c2(1, 2);
        Card c3(2, 1);
        Card c4(3, 3);
        p1.setStack(c4);
        p2.setStack(c3);
        p1.setStack(c2); // now p1 has two cards
        p2.setStack(c1); 
        // should by a draw, and then p1 run out of cards after the upsidedown card
        CHECK_THROWS_MESSAGE(game.playTurn(),"p1 is running out of cards");
        CHECK(game.getWinner().getName() == "Ori"); // p1 (Moshe) run out of cards so p2 (Ori) wins
    }
    string statsMessage = "Moshe: win rate: 0, cards won : 0, draw rate: 0, draws happened: 0\nOri: win rate: 0, cards won : 0, draw rate: 0, draws happened: 0"; // should be printed
    stringstream actuallPrinted;
    streambuf *printed = cout.rdbuf();
    cout.rdbuf(actuallPrinted.rdbuf());
    game.printLastTurn();
    cout.rdbuf(printed); // store the messgae printed from printStats
    CHECK(actuallPrinted.str() != "");
    CHECK(actuallPrinted.str() == statsMessage);
}


