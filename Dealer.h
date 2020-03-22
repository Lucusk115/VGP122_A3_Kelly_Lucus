#ifndef DEALER_H__
#define DEALER_H__
#include<iostream>
#include<string>
#include<array>
#include "Definitions.h"
#include "Deck.h"
#include "Sprite.h"


using namespace std;


class Dealer
{
private:


    Sprite draw();
    string chosenCard;
    Deck deck;


public:
    static const int usedCards{ 52 };
    static const int handSize{ 16 };


    //int to check if card has been dealt
    int x = 0;
    int y = 0;
    bool final = false;
    int winCount1 = 0;
    int winCount2 = 0;
    char keypress = ' ';

    Dealer();
    Dealer(string chosenCard);
    void shuffle();
    void deal() const;
    void topCard();
    void playerDeal();
    void displayHand();

    void setChosenCard(string chosenCard);
    string getChosenCard();
    string playCard(string chosenCard);
    string crazyEight(string chosenCard);
    void playTwo(string chosenCard);
    void playJack(string chosenCard);

    void lastCard();
    void restart();

    array<Card, usedCards> discard;
    array<Card, handSize> hand;
};

#endif

