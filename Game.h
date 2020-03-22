#ifndef GAME_H__
#define GAME_H__
#include<iostream>
#include<string>
#include<array>
#include <cstdlib>
#include "Definitions.h"

using namespace std;

class Game
{
private:
	int numOfPlayers;
	int gameStarter;
	bool endGame;


	//Deck deck;
	//Dealer dealer;

public:
	int x;
	int y = 0;

	Game();
	Game(int numOfPlayers);
	Game(int numOfPlayers, int gameStarter);
	Game(int numOfPlayers, int gameStarter, bool endGame);

	int randomGameStarter(int numberOfPlayers);
	void setGameStarter(int gameStarter);


	int getGameStarter();

	void gameRules();
	void cardInstructions();
	void gameOver();




};

#endif // GAME_H__
