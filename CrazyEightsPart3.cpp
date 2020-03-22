//Crazy-Eights Game
#include <iostream>
#include <string>
#include <array>
#include <cstdlib>
#include "Game.h"
#include "Player.h"
#include "Deck.h"
#include "Dealer.h"
#include "Definitions.h"

int main(int argc, char** argv)
{
	string chosenCard;
	Game game;
	Deck deck;
	Dealer dealer;
	Player player1, player2;

	/** Inialize Game Variables */
	bool			done = false;
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	/** Initialize Event Variables */
	SDL_Event		event;

	/** Initialize timer variables */
	Uint32			deltaT = 75;			// defines delay in time for updating game loop
	Uint32			updatedTime = 0;			// used to determine if frame rate interval has elapsed

	/** Initialize joystick handling variables */
	SDL_Joystick* joy = nullptr;

	

	
	int x = 1;
	/*const static int numberOfSprites{ 52 };
	array<Sprite*, numberOfSprites> cardSprite;*/

	
	/** Initialize sprite variables */
	Sprite* background = nullptr;
	Sprite* card1 = nullptr;
	Sprite* card2 = nullptr;
	Sprite* card3 = nullptr;
	Sprite* card4 = nullptr;
	Sprite* card5 = nullptr;
	Sprite* card6 = nullptr;
	Sprite* card7 = nullptr;
	Sprite* card8 = nullptr;
	Sprite* card9 = nullptr;
	Sprite* card10 = nullptr;
	Sprite* card11 = nullptr;
	Sprite* card12 = nullptr;
	Sprite* card13 = nullptr;
	Sprite* card14 = nullptr;
	Sprite* card15 = nullptr;
	Sprite* card16 = nullptr;
	Sprite* card17 = nullptr;
	

	/** Initialize SDL */
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0)
	{
		cerr << "Unable to init SDL: " << SDL_GetError() << endl;
		return 1;
	}
	// Close SDL at program end
	atexit(SDL_Quit);

	/** Create Window for Project */
	window = SDL_CreateWindow("Crazy Eights", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (!window)
	{
		cerr << "SDL_CreateWindow Error: " << SDL_GetError() << endl;
		return 1;
	}

	/** Create Renderer to draw to */
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!renderer)
	{
		cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << endl;
		return 1;
	}

	/** Initialize sprite properties */
	background = new Sprite("Images/DeckSpriteSheet.png", 0, 0, 1024, 600,
		0, 475, 1024, 125, renderer);
	card1 = new Sprite("Images/DeckSpriteSheet.png", 25, 25, 75, 100,
		9, 109, 75, 100, renderer);
	card2 = new Sprite("Images/DeckSpriteSheet.png", 105, 25, 75, 100,
		84, 109, 75, 100, renderer);
	card3 = new Sprite("Images/DeckSpriteSheet.png", 185, 25, 75, 100,
		235, 209, 75, 100, renderer);
	card4 = new Sprite("Images/DeckSpriteSheet.png", 265, 25, 75, 100,
		160, 110, 75, 100, renderer);
	card5 = new Sprite("Images/DeckSpriteSheet.png", 345, 25, 75, 100,
		160, 210, 75, 100, renderer);
	card6 = new Sprite("Images/DeckSpriteSheet.png", 430, 25, 75, 100,
		909, 310, 75, 100, renderer);
	card7 = new Sprite("Images/DeckSpriteSheet.png", 510, 25, 75, 100,
		759, 210, 75, 100, renderer);
	card8 = new Sprite("Images/DeckSpriteSheet.png", 590, 25, 75, 100,
		235, 110, 75, 100, renderer);
	card9 = new Sprite("Images/DeckSpriteSheet.png", 919, 475, 75, 100,
		909, 310, 75, 100, renderer);
	card10 = new Sprite("Images/DeckSpriteSheet.png", 839, 475, 75, 100,
		684, 210, 75, 100, renderer);
	card11 = new Sprite("Images/DeckSpriteSheet.png", 760, 475, 75, 100,
		909, 110, 75, 100, renderer);
	card12 = new Sprite("Images/DeckSpriteSheet.png", 680, 475, 75, 100,
		609, 310, 75, 100, renderer);
	card13 = new Sprite("Images/DeckSpriteSheet.png", 600, 475, 75, 100,
		309, 9, 75, 100, renderer);
	card14 = new Sprite("Images/DeckSpriteSheet.png", 520, 475, 75, 100,
		534, 310, 75, 100, renderer);
	card15 = new Sprite("Images/DeckSpriteSheet.png", 440, 475, 75, 100,
		459, 10, 75, 100, renderer);
	card16 = new Sprite("Images/DeckSpriteSheet.png", 360, 475, 75, 100,
		309, 110, 75, 100, renderer);
	card17 = new Sprite("Images/DeckSpriteSheet.png", 450, 250, 75, 100,
		9, 9, 75, 100, renderer);
	
	//Display rules and enter player names
	/*game.gameRules();
	player1.enterName();
	player2.enterName();
	deck.buildDeck();
	dealer.topCard();*/
	/** Keep game running until done is 'true' */
	while (!done)
	{
		/** Update game loop */
		if (SDL_GetTicks() - updatedTime >= deltaT)
		{
			/** Poll for Events */
			while (SDL_PollEvent(&event))
			{
				switch (event.type)
				{
					/** Check if user tries to quit the window */
				case SDL_QUIT:
					done = true;		// Break out of loop to end game
					break;

					/**	Check if the ESC key was pressed */
				case SDL_KEYDOWN:

					/**	Check if 'ESC' was pressed */
					if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
					{
						done = true;	// Break out of loop to end game
					}
					break;
				}
			}


			//Mouse handling examples
			int mouseX, mouseY;
			if (SDL_GetMouseState(&mouseX, &mouseY) & SDL_BUTTON(1))
			{
				cout << "Mouse Button 1(left)is pressed." << mouseX << "at" << mouseY << endl;
			}

			/** Check for mouseclick on card */
			if ((SDL_GetMouseState(&mouseX, &mouseY) == SDL_PRESSED) && card1 &&
				CollisionDetection::isColliding(mouseX, mouseY, card1) && card1->isVisible())
			{
				card1->setVisible(false);
				cout << "Card click" << endl;

				/** Delete the card once it is clicked */
				delete card1;
				card1 = nullptr;
			}

			/** Update card and other animations */
	
			/** Check if coin exists before drawing */
			if (background)

				/** Draw all sprites */
				background->draw();

			

			/** Check if coin exists before drawing */
			
				card1->draw();
				card2->draw();
				card2->draw();
				card3->draw();
				card4->draw();
				card5->draw();
				card6->draw();
				card7->draw();
				card8->draw();
				card9->draw();
				card10->draw();
				card11->draw();
				card12->draw();
				card13->draw();
				card14->draw();
				card15->draw();
				card16->draw();
				card17->draw();

			//luigi->draw();

			/** Update display */
			SDL_RenderPresent(renderer);

			/** update time */
			updatedTime = SDL_GetTicks();
		}
	game.gameRules();
	player1.enterName();
	player2.enterName();
	deck.buildDeck();
	dealer.shuffle();
	dealer.deal();
	dealer.topCard();
	dealer.playerDeal();
	//player1.dealHand();
	//player2.dealHand();

	
	//player1.displayHand();
	//player2.displayHand();
	game.cardInstructions();
	dealer.lastCard();
	dealer.restart();
	}
	/** Free memory used for sprites */
	delete background;
	delete card1;
	delete card2;
	delete card3;
	delete card4;
	delete card5;
	delete card6;
	delete card7;
	delete card8;
	delete card9;
	delete card10;
	delete card11;
	delete card12;
	delete card13;
	delete card14;
	delete card15;
	delete card16;
	delete card17;
	//delete luigi;
	
	
	
	
	/** Free SDL resources */
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	return 0;
}
