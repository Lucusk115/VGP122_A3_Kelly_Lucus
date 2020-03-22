#include "Game.h"
#include "Definitions.h"
#include <string>
#include <iomanip>
#include <iostream>
#include <sstream>
using namespace std;

Game::Game()
{
	int numOfPlayers = 0;
	int gameStarter = 0;
	bool endGame = false;

}

Game::Game(int numOfPlayers)
{
	this->numOfPlayers = numOfPlayers;
}

Game::Game(int numOfPlayers, int gameStarter)
{
	this->numOfPlayers = numOfPlayers;
	this->gameStarter = gameStarter;
}

Game::Game(int numOfPlayers, int gameStarter, bool endGame)
{
	this->numOfPlayers = numOfPlayers;
	this->gameStarter = gameStarter;
	this->endGame = endGame;
}

int Game::randomGameStarter(int numberOfPlayers)
{
	int gameStarter = 1 + rand() % numOfPlayers;
	return gameStarter;
}

void Game::setGameStarter(int gameStarter)
{
	this->gameStarter = gameStarter;
}

int Game::getGameStarter()
{
	return gameStarter;
}

void Game::gameRules()
{
	cout << "Welcome to Crazy-Eights\n A card game for a night of fun for the whole family\n\n"
		<< "*** GAME RULES ***\n\n" << "To win get rid of all cards in your hand.\n"
		<< "To get rid of cards match either the face or suit of a card\n"
		<< " to that of the top card on the discard pile.\n"
		<< "If you have no playable card that match, draw the top card from the deck.\n"
		<< "The game contains wild cards as follow:\n"
		<< "Crazy-Eight:  Play any Eight and change the suit to your choice.\n"
		<< "Jacks:  Drop a jack to skip the next players turn.\n"
		<< "2's:  Discard one or more 2's to cause the next player to pick 2x the 2's dropped\n"
		<< "The game ends when someone gets rid of their last card or the deck runs out.\n"
		<< endl;
}

void Game::cardInstructions()
{
	cout << "\nTo play a card input the number to the right of the card you want to play:\n"
		<< "If you have no valid card to play.\n Press the 'd' key to draw a card:\n"
		<< "Hit 'w' to play last card for the WIN\n"
		<< endl;

}

/*void Game::gameOver()
{
	char keypress = ' ';

	cout << "Play another game y/n?\n" << endl;
	cin >> keypress;

	if (keypress == 'y')
	{
		int x = 0;
		int y = 0;
		endGame = false;
		deck.deck[x].cardStatus = 0;
		dealer.hand[x].positionStatus = 0;


	}

	else if (keypress == 'n')
	{
		if (winCount1 > winCount2)
		{
			cout << "Player 1 WINS\n";
		}
		else if (winCount2 > winCount1)
		{
			cout << "Player 2 WINS\n";
		}

		cout << "Thanks for Playing" << endl;
	}
	else
	{
		cout << "Invalid Keypress\n" << endl;
	}
}*/
