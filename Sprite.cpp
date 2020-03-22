#include "Sprite.h"

Sprite::Sprite(const char* filename, int facenum, int suitnum, int posX, int posY, SDL_Renderer* renderer)
{
	this->renderer = renderer;

	rect.x = facenum * 75 + 9;
	rect.y = suitnum * 100 + 9;
	rect.h = 100; //image height
	rect.w = 75; //image width

	dest.x = posX * 75 + 150;
	dest.y = posY * 100 + 25;
	dest.h = 100;  //draw height
	dest.w = 75;  //draw width

	this->facenum = facenum;
	this->suitnum = suitnum;
	this->posX = posX;
	this->posY = posY;

	visible = true;
	load(filename);


}

//Sprite::Sprite(const char* filename, int xpos, int ypos, 
//	int width, int height, SDL_Renderer* renderer)
//{
//	this->renderer = renderer;
//
//	rect.x = 0;
//	rect.y = 0;
//	rect.h = height; //image height
//	rect.w = width; //image width
//
//	this->xpos = xpos;
//	this->ypos = ypos;
//
//	visible = true;
//	load(filename);
//}

Sprite::Sprite(const char* filename, int xpos, int ypos, int width, int height,
	int x2pos, int y2pos, int width2, int height2, SDL_Renderer* renderer)
{
	/** Set SDL_Renderer variable in Sprite class */
	this->renderer = renderer;

	/** Set SDL_Rect variable in Sprite class */
	rect.x = 0;
	rect.y = 0;
	rect.h = height; //image height
	rect.w = width; //image width

	dest.x = 0;
	dest.y = 0;
	dest.h = height2;  //draw height
	dest.w = width2;  //draw width

	/** Set position variable of Sprite class */
	this->xpos = xpos;
	this->ypos = ypos;
	this->x2pos = x2pos;
	this->y2pos = y2pos;

	/** Set visibility of Sprite class */
	visible = true;

	/** Load image to use for Sprite */
	load(filename);
}

Sprite::~Sprite()
{
	/** Delete any resources created */
	SDL_DestroyTexture(image);
}


void Sprite::load(const char* filename)
{
	/** Load picture for Sprite */
	image = IMG_LoadTexture(renderer, filename);

	/** Check if the Sprite was loaded */
	if (!image)
	{
		/** Bad stuff happened */
		cerr << "IMG_LoadTexture Error: " << IMG_GetError() << endl;
		exit(1);
	}
}

void Sprite::draw()
{
	/** Check if sprite should be drawn to the screen */
	if (this->visible)
	{
		/** Position sprite on Screen */
		SDL_Rect dest = { xpos, ypos, rect.w, rect.h };
		SDL_Rect rect = { x2pos, y2pos, dest.w, dest.h };

		/** Draw Sprite to Screen */
		SDL_RenderCopy(renderer, image, &rect, &dest);
	}
}

void Sprite::animate(Uint16 startFrame, Uint16 endFrame)
{
	/** Store current animation frame */
	Uint16 currentFrame = getCurrentFrame();

	/** Check if animation should be looped back to start */
	if (currentFrame < startFrame || currentFrame > endFrame)
		/** Set animation frame back to start animation frame */
		currentFrame = startFrame;
	else
	{
		/** Increment frame */
		++currentFrame;

		/** Check if animation is passed last animation frame */
		if (currentFrame > endFrame)
			/** Set animation frame back to start animation frame */
			currentFrame = startFrame;
	}

	/** Set current animation frame of Sprite */
	setCurrentFrame(currentFrame);
}

void Sprite::move(int deltaX, int deltaY)
{
	/** Most Sprite along X with appropriate value */
	xpos += deltaX;

	/** Most Sprite along Y with appropriate value */
	ypos += deltaY;
}

void Sprite::setCurrentFrame(Uint16 frame)
{
	/** Check if SDL_Rect was properly initialized */
	if (!rect.w)
		/** Not properly initialized so end function */
		return;

	/** Calculate current frame of animation */
	rect.x = rect.w * frame;
}

void Sprite::setRow(Uint16 row)
{
	/** Check if SDL_Rect was properly initialized */
	if (!rect.h)
		/** Not properly initialized so end function */
		return;

	/** Calculate current frame of animation */
	rect.y = rect.h * row;
}

Uint16 Sprite::getRow()
{
	/** Check if SDL_Rect was properly initialized */
	if (!rect.h)
		/** Not properly initialized so end function */
		return 0;

	/** Calculate current frame of animation */
	return rect.y / rect.h;
}

Uint16 Sprite::getCurrentFrame()
{
	/** Check if SDL_Rect was properly initialized */
	if (!rect.w)
		/** Not properly initialized so end function */
		return 0;

	/** Calculate current frame of animation */
	return rect.x / rect.w;
}

/** Create Getters and Setters for private variables */
SDL_Texture* Sprite::getImage()
{
	return this->image;
}

int Sprite::getWidth()
{
	return this->rect.w;
}

int Sprite::getHeight()
{
	return this->rect.h;
}

int Sprite::getXPos()
{
	return this->xpos;
}

int Sprite::getYPos()
{
	return this->ypos;
}

bool Sprite::isVisible()
{
	return this->visible;
}

void Sprite::setWidth(int width)
{
	this->rect.w = width;
}

void Sprite::setHeight(int height)
{
	this->rect.h = height;
}

void Sprite::setXPos(int x)
{
	this->xpos = x;
}

void Sprite::setYPos(int y)
{
	this->ypos = y;
}

void Sprite::setVisible(bool visible)
{
	this->visible = visible;
}

//Setters and Getters for the destination  size of the image
//Used to put get certain parts of image, size them and put them on the screen.

int Sprite::getWidth2()
{
	return this->dest.w;
}

int Sprite::getHeight2()
{
	return this->dest.h;
}

int Sprite::getX2Pos()
{
	return this->x2pos;
}

int Sprite::getY2Pos()
{
	return this->y2pos;
}

void Sprite::setWidth2(int width2)
{
	this->dest.w = width2;
}

void Sprite::setHeight2(int height2)
{
	this->dest.h = height2;
}

void Sprite::setX2Pos(int x)
{
	this->x2pos = x;
}

void Sprite::setY2Pos(int y)
{
	this->y2pos = y;
}

int Sprite::getFacenum()
{
	return this->facenum = facenum;
}

int Sprite::getSuitnum()
{
	return this->suitnum = suitnum;
}

int Sprite::getPosX()
{
	return this->posX = posX;
}

int Sprite::getPosY()
{
	return this->posY = posY;
}

void Sprite::setFacenum(int facenum)
{
	this->facenum = facenum;
}

void Sprite::setSuitnum(int suitnum) 
{
	this->suitnum = suitnum;
}

void Sprite::setPosX(int posX)
{
	this->posX = posX;
}

void Sprite::setPosY(int posY)
{
	this->posY = posY;
}


