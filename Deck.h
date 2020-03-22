#ifndef DECK_H__
#define DECK_H__
#include<iostream>
#include<string>
#include<array>




using namespace std;

struct Card
{
	string face;
	string suit;
	int cardStatus;
	int positionStatus;
	
};

class Deck
{
public:

	//araays for deck
	static const int numberOfCards{ 52 };
	static const int faces{ 13 };
	static const int suits{ 4 };

	Deck();
	void buildDeck();
	void setNumberOfCards(int numberOfCards);
	int getNumberOfCards();


	array<Card, numberOfCards> deck;

private:


};


#endif // DECK_H__

