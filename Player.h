#ifndef PLAYER_H__
#define PLAYER_H__
#include<iostream>
#include<string>
#include<array>
#include "Definitions.h"
#include "Deck.h"
#include "Dealer.h"

using namespace std;

class Player
{
private:
	int numOfPlayers;
	string name;
	int score;
	bool win;
	int playerNumber;


	//Deck deck;
	//Dealer dealer;


public:

	//static const int handSize{ 16 };

	Player();
	Player(int numOfPlayers);
	Player(int numOfPlayers, string name);
	Player(int numOfPlayers, string name, int score);
	Player(int numOfPlayers, string name, int score, bool win);

	void setNumOfPlayers(int numOfPlayers);
	void setPlayerNumber(int playerNumber);
	void setName(string name);
	void setScore(int score);

	int getNumOfPlayers();
	int getPlayerNumber();
	string getName();
	int getScore();

	void enterPlayers();
	void displayScore();
	void enterName();
	void dealHand();
	void displayHand();

	//array<Card, handSize> hand;


};

#endif //PLAYER_H__