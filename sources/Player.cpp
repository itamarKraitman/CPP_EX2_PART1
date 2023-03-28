
#include <iostream>
#include <string>
#include <vector>
#include "player.hpp"

using namespace std;

namespace ariel
{

    Player::Player(string name)
    {
        this->name = name;
        this->stackSize = 26;
        this->taken = 0;
        this->isRegistred = true;
        this->winRate = 0;
        this->cardsWon = 0;
        this->drawRate = 0;
        this->drawsHappened = 0;
    }

    Player::Player(const Player &player) noexcept {}

    Player &Player::operator=(const Player &other) { return *this; } // copy assignment operator

    Player::Player(Player &&other) noexcept {} // move constructor

    Player &Player::operator=(Player &&other) noexcept { return *this; } // move assignment operator

    Player::~Player() {}

    string Player::getName() { return this->name; }

    int Player::stacksize() { return this->stackSize; }

    int Player::cardesTaken() { return this->taken; }

    Card Player::putCard()
    { // puts the next card from player's deck
        Card topCard;
        if (stackSize > 0)
        {
            stackSize--;
            topCard = stack[0];
            stack.erase(stack.begin()); // remove first element
        }
        else
        {
            cout << "No cards left in stack!";
        }
        return topCard;
    }

    void Player::addCardsToPlayerTaken(int amountToAdd) 
    {
        this->taken += amountToAdd;
    }

    void Player::setStack(int numOfCardsToReduce) 
    {
        this->stackSize -= numOfCardsToReduce;
    }

    void Player::setStack(Card card) 
    { 
        this->stack.insert(stack.begin(), card);
    }

    double Player::getWinRate() { return this->winRate; }

    void Player::setWinRate() 
    {
        this->winRate = this->wins / (this->wins + this->drawsHappened);
    }

    double Player::getDrawRate() { return this->drawRate; }

    void Player::setDrawRate() 
    {
        this->drawRate = this->drawsHappened / (this->wins + this->drawsHappened);
    }

    int Player::getNumberOfDraws() 
    { 
        return this->drawsHappened; 
    }

    void Player::setNumberOfDraws() 
    {
        this->drawsHappened++;
    }

    int Player::getWins() 
    {
        return this->wins;
    }

    void Player::setWins()
    {
        this->wins++;
    }
}
