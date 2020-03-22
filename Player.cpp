#include "Player.h"
#include "Definitions.h"
#include <string>
#include <iomanip>
#include <iostream>
#include <sstream>
using namespace std;

Player::Player()
{
	int numOfPlayers = 0;
	string name = "Default";
	int score = 0;
	bool win = false;
	int playerNumber = 0;
}

Player::Player(int numOfPlayers)
{
	this->numOfPlayers = numOfPlayers;
}

Player::Player(int numOfPlayers, string name)
{
	this->numOfPlayers = numOfPlayers;
	this->name = name;
}

Player::Player(int numOfPlayers, string name, int score)
{
	this->numOfPlayers = numOfPlayers;
	this->name = name;
	this->score = score;
}

Player::Player(int numOfPlayers, string name, int score, bool win)
{
	this->numOfPlayers = numOfPlayers;
	this->name = name;
	this->score = score;
	this->win = win;
}

void Player::setNumOfPlayers(int numOfPlayers)
{
	this->numOfPlayers = numOfPlayers;
}

void Player::setPlayerNumber(int playerNumber)
{
	this->playerNumber = playerNumber;
}


void Player::setName(string name)
{
	this->name = name;
}

void Player::setScore(int score)
{
	this->score = score;
}

int Player::getNumOfPlayers()
{
	return numOfPlayers;
}

int Player::getPlayerNumber()
{
	return playerNumber;
}


string Player::getName()
{
	return name;
}

int Player::getScore()
{
	return score;
}

void Player::enterName()
{

	cout << "Enter player: " << endl;
	cin >> name;
	setName(name);
	playerNumber += 1;
	setPlayerNumber(playerNumber);
}

void Player::enterPlayers()
{
	cout << "How many people are playing?" << endl;
	cin >> numOfPlayers;
	setNumOfPlayers(numOfPlayers);
}


void Player::displayScore()
{
	cout << "Player: " << getName() << "\nScore: " << getScore() << endl;
}

void Player::dealHand()
{
	cout << "\n This is: " << getName() << " hand\n" << endl;

}

void Player::displayHand()
{


}