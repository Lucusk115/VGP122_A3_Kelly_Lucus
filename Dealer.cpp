#include "Dealer.h"
#include "Deck.h"
#include "Player.h"
#include "Definitions.h"
#include<iostream>
#include<iomanip>
#include<string>
#include<cstdlib>
#include<ctime>
#include<array>
using namespace std;

Dealer::Dealer()
{
	string chosenCard;
	string suit;
	string face;
	int cardstatus;
	deck.buildDeck();

}

Dealer::Dealer(string chosenCard)
{
	this->chosenCard = chosenCard;
}

void Dealer::shuffle()
{
	for (size_t i = 0; i < deck.getNumberOfCards(); ++i)
	{
		int j{ rand() % deck.getNumberOfCards() };
		Card temp = deck.deck[i];
		deck.deck[i] = deck.deck[j];
		deck.deck[j] = temp;
	}
}

void Dealer::deal() const
{
	for (size_t i = 0; i < deck.deck.size(); ++i)
	{
		cout << right << setw(5) << deck.deck[i].face << " of "
			<< left << setw(8) << deck.deck[i].suit
			<< ((i + 1) % 2 ? '\t' : '\n');

	}
	cout << "\nThis is used for testing purposes\n\n" << endl;
}

void Dealer::topCard()
{
	//deals one card onto the discard pile as the topcard 
	discard[y].face = deck.deck[x].face;
	discard[y].suit = deck.deck[x].suit;

	cout << "\n\nTop Card is: " << discard[y].face << " of "
		<< discard[y].suit << "\n" << endl;

	// changes status of card to be in the discard pile
	deck.deck[x].cardStatus = 3;
	Sprite* draw();
	++x;

}

void Dealer::playerDeal()
{
	{
		for (size_t i = 0; i < hand.size(); i++)
		{
			hand[i].positionStatus = 0;
		}

		for (size_t i = 0; i < 8; ++i)
		{
			if (deck.deck[x].cardStatus == 1)
			{
				++x;
				--i;
			}

			//copies cards dealt from the deck array into the player 1 hand array
			hand[i].face = deck.deck[x].face;
			hand[i].suit = deck.deck[x].suit;


			//set element positionStatus to filled
			hand[i].positionStatus = 1;

			//changes the status of the card so it is in player 1 hand
			deck.deck[x].cardStatus = 1;
			++x;


			//prints out player 1 hand
			cout << right << setw(5) << hand[i].face << " of "
				<< left << setw(8) << hand[i].suit
				<< ((i + 1) % 2 ? '\t' : '\n');


		}
	}
}

void Dealer::displayHand()
{
	for (size_t i = 0; i < hand.size(); ++i)
	{
		if (deck.deck[i].cardStatus == 1)
		{
			//print hand and card positions
			cout << right << setw(8) << hand[i].face << " of "
				<< left << setw(8) << hand[i].suit << '\t' << i << endl;
			hand[i].positionStatus = 1;

		}
	}
	//cout << "Debug" << endl;
}

void Dealer::setChosenCard(string chosenCard)
{
	this->chosenCard = chosenCard;
}

string Dealer::getChosenCard()
{
	return chosenCard;
}


string Dealer::playCard(string chosenCard)
{

	displayHand();
	//value for position in hand
	int z = 0;

	//enter card to be played
	cout << "\nPress card to be played" << endl;
	cin >> keypress;

	if (keypress == 'w')
	{
		final = true;
		cin >> keypress;
	}

	switch (keypress)
	{
	case '0':
		if (hand[0].face == discard[y].face || hand[0].suit == discard[y].suit)
		{
			++y;
			discard[y].face = hand[0].face;
			discard[y].suit = hand[0].suit;

			cout << discard[y].face << " of " << discard[y].suit
				<< " played" << endl;

			//mark card for discard pile
			hand[0].cardStatus = 3;
			hand[0].positionStatus = 0;

			hand[0].face = ' ';
			hand[0].suit = ' ';
		}
		else
			cout << "Invalid card" << endl;

		break;

	case '1':
		if (hand[1].face == discard[y].face || hand[1].suit == discard[y].suit)
		{
			++y;
			discard[y].face = hand[1].face;
			discard[y].suit = hand[1].suit;

			cout << discard[y].face << " of " << discard[y].suit
				<< " played" << endl;

			//mark card for discard pile
			hand[1].cardStatus = 3;
			hand[1].positionStatus = 0;

			hand[1].face = ' ';
			hand[1].suit = ' ';
		}
		else
			cout << "Invalid card" << endl;

		break;

	case '2':
		if (hand[2].face == discard[y].face || hand[2].suit == discard[y].suit)
		{
			++y;
			discard[y].face = hand[2].face;
			discard[y].suit = hand[2].suit;

			cout << discard[y].face << " of " << discard[y].suit
				<< " played" << endl;

			//mark card for discard pile
			hand[2].cardStatus = 3;
			hand[2].positionStatus = 0;

			hand[2].face = ' ';
			hand[2].suit = ' ';
		}
		else
			cout << "Invalid card" << endl;

		break;

	case '3':
		if (hand[3].face == discard[y].face || hand[3].suit == discard[y].suit)
		{
			++y;
			discard[y].face = hand[3].face;
			discard[y].suit = hand[3].suit;

			cout << discard[y].face << " of " << discard[y].suit
				<< " played" << endl;

			//mark card for discard pile
			hand[3].cardStatus = 3;
			hand[3].positionStatus = 0;

			hand[3].face = ' ';
			hand[3].suit = ' ';
		}
		else
			cout << "Invalid card" << endl;

		break;

	case '4':
		if (hand[4].face == discard[y].face || hand[4].suit == discard[y].suit)
		{
			++y;
			discard[y].face = hand[4].face;
			discard[y].suit = hand[4].suit;

			cout << discard[y].face << " of " << discard[y].suit
				<< " played" << endl;

			//mark card for discard pile
			hand[4].cardStatus = 3;
			hand[4].positionStatus = 0;

			hand[4].face = ' ';
			hand[4].suit = ' ';
		}
		else
			cout << "Invalid card" << endl;

		break;

	case '5':
		if (hand[5].face == discard[y].face || hand[5].suit == discard[y].suit)
		{
			++y;
			discard[y].face = hand[5].face;
			discard[y].suit = hand[5].suit;

			cout << discard[y].face << " of " << discard[y].suit
				<< " played" << endl;

			//mark card for discard pile
			hand[5].cardStatus = 3;
			hand[5].positionStatus = 0;

			hand[5].face = ' ';
			hand[5].suit = ' ';
		}
		else
			cout << "Invalid card" << endl;

		break;

	case '6':
		if (hand[6].face == discard[y].face || hand[6].suit == discard[y].suit)
		{
			++y;
			discard[y].face = hand[6].face;
			discard[y].suit = hand[6].suit;

			cout << discard[y].face << " of " << discard[y].suit
				<< " played" << endl;

			//mark card for discard pile
			hand[6].cardStatus = 3;
			hand[6].positionStatus = 0;

			hand[6].face = ' ';
			hand[6].suit = ' ';
		}
		else
			cout << "Invalid card" << endl;

		break;

	case '7':
		if (hand[7].face == discard[y].face || hand[7].suit == discard[y].suit)
		{
			++y;
			discard[y].face = hand[7].face;
			discard[y].suit = hand[7].suit;

			cout << discard[y].face << " of " << discard[y].suit
				<< " played" << endl;

			//mark card for discard pile
			hand[7].cardStatus = 3;
			hand[7].positionStatus = 0;

			hand[7].face = ' ';
			hand[7].suit = ' ';
		}
		else
			cout << "Invalid card" << endl;

		break;

	case '8':
		if (hand[8].face == discard[y].face || hand[8].suit == discard[y].suit)
		{
			++y;
			discard[y].face = hand[8].face;
			discard[y].suit = hand[8].suit;

			cout << discard[y].face << " of " << discard[y].suit
				<< " played" << endl;

			//mark card for discard pile
			hand[8].cardStatus = 3;
			hand[8].positionStatus = 0;

			hand[8].face = ' ';
			hand[8].suit = ' ';
		}
		else
			cout << "Invalid card" << endl;

		break;

	case '9':
		if (hand[9].face == discard[y].face || hand[9].suit == discard[y].suit)
		{
			++y;
			discard[y].face = hand[9].face;
			discard[y].suit = hand[9].suit;

			cout << discard[y].face << " of " << discard[y].suit
				<< " played" << endl;

			//mark card for discard pile
			hand[9].cardStatus = 3;
			hand[9].positionStatus = 0;

			hand[9].face = ' ';
			hand[9].suit = ' ';
		}
		else
			cout << "Invalid card" << endl;

		break;


	case 'd':
		for (size_t i = 0; i < hand.size(); i++)
		{
			if (hand[i].positionStatus == 0 || hand[i].cardStatus == 3)
			{
				++z;
				//place top card of deck into player hand
				hand[i].face = deck.deck[x].face;
				hand[i].suit = deck.deck[x].suit;

				deck.deck[x].cardStatus = 1;
				hand[i].positionStatus = 1;

				++x;

				cout << "\n" << hand[i].face << " of " << hand[i].suit
					<< " drawn\n" << endl;
				break;
			}
			setChosenCard(discard[y].face);
		}
		break;

	default:
		cout << "\nInvalid Keypress\n" << endl;
	}

	system("pause");
	system("cls");


	cout << "\nNew top card is:\n"
		<< discard[y].face << " of " << discard[y].suit << "\n" << endl;
	return chosenCard;
}
void Dealer::lastCard()
{

	while (final == false)
	{
		playCard(chosenCard);
		crazyEight(getChosenCard());
		playTwo(getChosenCard());
		playJack(getChosenCard());

	}

	if (final == true)
	{
		winCount1 = winCount1 + 1;
		final != true;
	}

	/*else if (player1Win == true)
	{
		winCount2 = winCount2 + 1;
		player1Win = false;
	}*/
	cout << "player1 win count = " << winCount1 << "\n" << endl;
	//cout << "player2 win count = " << winCount2 << "\n" << endl;
}

string Dealer::crazyEight(string chosenCard)
{
	getChosenCard();
	if (chosenCard == "8")
	{
		cout << "Crazy Eight!\n" << "Change suit by pressing 0,1,2, or 3\n"
			<< "0 = Hearts\n" << "1 = Diamonds\n" << "2 = Clubs\n" << "3 = Spades\n"
			<< endl;

		cin >> keypress;

		switch (keypress)
		{
		case '0':
			discard[y].suit = "Hearts";
			break;
		case '1':
			discard[y].suit = "Diamonds";
			break;
		case '2':
			discard[y].suit = "Clubs";
			break;
		case '3':
			discard[y].suit = "Spades";
			break;

		default:
			cout << "Invalid Keypress\n" << endl;
			break;
		}
	}
	setChosenCard(discard[y].suit);
	return chosenCard;
}

void Dealer::playTwo(string chosenCard)
{
	if (discard[y].face == "2")
	{
		for (size_t i = 0; i < hand.size(); ++i)
		{
			if (hand[i].positionStatus == 0 || hand[i].cardStatus == 3)
			{
				//place top card of deck into player hand
				hand[i].face = deck.deck[x].face;
				hand[i].suit = deck.deck[x].suit;

				deck.deck[x].cardStatus = 1;
				hand[i].positionStatus = 1;

				++x;
			}
			break;
		}

		//place second card into player hand
		for (size_t i = 0; i < hand.size(); ++i)
		{
			if (hand[i].positionStatus == 0 || hand[i].cardStatus == 3)
			{
				hand[i].face = deck.deck[x].face;
				hand[i].suit = deck.deck[x].suit;

				deck.deck[x].cardStatus = 1;
				hand[i].positionStatus = 1;

				++x;
			}
			break;
		}

	}
}

void Dealer::playJack(string chosenCard)
{
	cout << "\nSkip the next player's turn.\n" << endl;
}

void Dealer::restart()
{
	char keypress = ' ';

	cout << "Play another game y/n?\n" << endl;
	cin >> keypress;

	if (keypress == 'y')
	{
		int x = 0;
		int y = 0;
		final = false;
		deck.deck[x].cardStatus = 0;
		hand[x].positionStatus = 0;


		deck.buildDeck();
		shuffle();
		deal();
		playerDeal();
		topCard();
		lastCard();
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
}