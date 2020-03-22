#include "Deck.h"
#include "Definitions.h"
#include<iostream>
#include<iomanip>
#include<array>
#include<cstdlib>
#include<ctime>
using namespace std;

Deck::Deck()
{

	static string suit[suits]{ "Clubs", "Hearts", "Spades", "Diamonds" };

	static string face[faces]{ "Ace", "2", "3", "4", "5", "6", "7", "8", "9",
	"10", "Jack", "Queen", "King" };

	int cardStatus = 0;

}

void Deck::buildDeck()
{

	static string suit[suits]{ "Clubs", "Hearts", "Spades", "Diamonds" };

	static string face[faces]{ "Ace", "2", "3", "4", "5", "6", "7", "8", "9",
	"10", "Jack", "Queen", "King" };


	for (size_t i = 0; i < deck.size(); ++i)
	{
		deck[i].face = face[i % faces];
		deck[i].suit = suit[i / faces];

	}

	
	srand(static_cast<size_t>(time(nullptr)));

}

void Deck::setNumberOfCards(int numberOfCards)
{
	numberOfCards = numberOfCards;
}

int Deck::getNumberOfCards()
{
	return numberOfCards;
}
