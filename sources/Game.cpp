
#include <iostream>
#include <sstream>
#include "game.hpp"
#include "player.hpp"

using namespace std;

namespace ariel
{
    Game::Game(Player &player1, Player &player2) : p1(player1), p2(player2)
    {
        if (player1.registred() || player2.registred())
        {
            throw invalid_argument("Player can be registred only to one game!");
        }
        this->p1 = player1;
        this->p2 = player2;
        this->winner = "";
        this->p1.getStack().clear();
        this->p2.getStack().clear();
        vector<Card> p1Stack = p1.getStack();
        vector<Card> p2Stack = p2.getStack();
        generateDeckAndDeal(p1Stack, p2Stack);
    }

    Game::Game(const Game &game) noexcept : p1(game.p1), p2(game.p2) {}

    Game &Game::operator=(const Game &other) { return *this; } // copy assignment operator

    Game &Game::operator=(Game &&other) noexcept { return *this; } // move assignment operator

    Game::Game(Game &&other) noexcept : p1(other.p1), p2(other.p2) {} // move constructor

    Game::~Game() {}

    void Game::generateDeckAndDeal(vector<Card> &p1Stack, vector<Card> &p2Stack) // generates regular deck, shuffle it, and deal to players
    {
        vector<Card> deck;
        // generate cards and push into the deck
        for (int i = 1; i < 14; i++)
        {
            for (signs j = Clubs; j <= Spades; j = signs(j + 1))
            {
                Card newCard(Card(i, j));
                deck.push_back(newCard);
            }
        }

        for (Card c : deck)
        {
            std::cout << c.toString() << " ";
        }

        // shuffle the deck
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(deck.begin(), deck.end(), g);

        // // deal the deck
        for (int i = 0; i < 26; i++)
        {
            p1.pushToStack(deck.back());
            deck.pop_back();
            p2.pushToStack(deck.back());
            deck.pop_back();
        }
    }

    void Game::playTurn()
    {
        int numberOfCardsThrewInTurn = 2; // in each turn at least 2 cards are thrown
        // both players throw cards
        Card p1Card = p1.putCard();
        Card p2Card = p2.putCard();
        this->lastTurnLog << "p1 plays " << p1Card.getNumber() << " of " << p1Card.getSign() << " p2 plays " << p2Card.getNumber() << " of " << p2Card.getSign();
        while (p1Card.getNumber() == p2Card.getNumber()) // war scenario, until there is no draw so no war
        {
            this->lastTurnLog << " draw.";
            p1.setNumberOfDraws();
            p2.setNumberOfDraws();
            p1.setDrawRate();
            p2.setDrawRate();
            // both put card down- need to check if not causing data leak
            p1.putCard();
            p2.putCard();
            // both put card up
            p1Card = p1.putCard();
            p2Card = p2.putCard();
            // add playes to lastTurnLog
            this->lastTurnLog << "p1 plays " << p1Card.getNumber() << " of " << p1Card.getSign() << " p2 plays " << p2Card.getNumber() << " of " << p2Card.getSign();
            numberOfCardsThrewInTurn += 4;
        }
        // both stack-- if can, if player runs out of cards he looses- in putCard()
        // if p1 wins: add cards to taken, win rate++, update win rate
        if (p1Card.getNumber() > p2Card.getNumber())
        {
            p1.setWins();
            p1.setWinRate();
            p1.addCardsToPlayerTaken(numberOfCardsThrewInTurn);
            this->lastTurnLog << "p1 wins.\n";
        }
        else if (p2Card.getNumber() > p1Card.getNumber())
        {
            p2.setWins();
            p2.setWinRate();
            p2.addCardsToPlayerTaken(numberOfCardsThrewInTurn);
            this->lastTurnLog << "p2 wins.\n";
        }
        this->gameLog += lastTurnLog.str(); // add turn log to gameLog
        this->lastTurnLog << "";
    }

    void Game::printLastTurn()
    {
        cout << this->lastTurnLog.str() << endl;
    }

    void Game::playAll()
    {
        for (int i = 0; i < 26; i++)
        {
            playTurn();
        }
    }

    void Game::printWiner()
    {
        cout << this->winner;
    }

    void Game::printLog()
    {
        cout << this->gameLog << endl;
    }

    void Game::printStats() {} // TODO when tests come

    Player Game::getWinner() { return this->winner; }
}