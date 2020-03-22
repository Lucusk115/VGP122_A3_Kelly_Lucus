#ifndef SPRITE_H
#define SPRITE_H

#include "Definitions.h"

class Sprite
{
public:
	Sprite(const char* filename, int facenum, int suitnum, int posx, int posy, SDL_Renderer* renderer);
	//Sprite(const char* filename, int xpos, int ypos, int width, int height, SDL_Renderer* renderer);
	Sprite(const char* filename, int xpos, int ypos, int width, int height, 
		int x2pos, int y2pos, int width2, int height2, SDL_Renderer* renderer);
	~Sprite();
	
	void animate(Uint16 startFrame, Uint16 endFrame);
	void move(int deltaX, int deltaY);
	void draw();
	

	void setCurrentFrame(Uint16 frame);
	void setRow(Uint16 row);
	Uint16 getRow();
	Uint16 getCurrentFrame();

	SDL_Texture* getImage();
	int getWidth();
	int getHeight();
	int getXPos();
	int getYPos();
	bool isVisible();

	void setWidth(int width);
	void setHeight(int height);
	void setXPos(int x);
	void setYPos(int y);
	void setVisible(bool visible);

	//Destination setters
	int getWidth2();
	int getHeight2();
	int getX2Pos();
	int getY2Pos();

	void setWidth2(int width2);
	void setHeight2(int height2);
	void setX2Pos(int x);
	void setY2Pos(int y);

	void setSuitnum(int suitnum);
	void setFacenum(int facenum);
	void setPosX(int PosX);
	void setPosY(int PosY);

	int getSuitnum();
	int getFacenum();
	int getPosX();
	int getPosY();

	

private:
	void load(const char* filename);

	SDL_Texture* image;
	SDL_Rect rect, dest;
	int xpos, ypos, x2pos, y2pos, suitnum, facenum, posX, posY;
	bool visible;
	SDL_Renderer* renderer;
};


#endif //SPRITE_H

