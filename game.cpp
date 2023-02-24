#include "game.h"
#include "surface.h"
#include <cstdio> //printf
#include <cassert>

namespace Tmpl8
{
	// -----------------------------------------------------------
	// Initialize the application
	// -----------------------------------------------------------
	void Game::Init()
	{
	}
	// -----------------------------------------------------------
	// Close down application
	// -----------------------------------------------------------
	void Game::Shutdown()
	{
	}

	static Sprite rotatingGun(new Surface("assets/aagun.tga"), 36);
	static int frame = 0;

	Surface image("assets/ball.png");
	// -----------------------------------------------------------
	// Main application tick function
	// -----------------------------------------------------------

	void Game::DrawI(int x, int y) {
		screen->Line(100 + x, 50 + y, 200 + x, 50 + y, 0xffffff);
		screen->Line(150 + x, 50 + y, 150 + x, 300 + y, 0xffffff);
		screen->Line(100 + x, 300 + y, 200 + x, 300 + y, 0xffffff);
	}
	//Sprite theSprite(new Surface("assets/ball.png"), 1);
	
	/*
	int spriteX = 0;
	int spriteY = 100;
	int speed = 1;
	int speedX = 5;
	*/
	
	void Game::Tick(float deltaTime)
	{	
		//clear graphics window
		screen->Clear(0);
	
		//draw a grid
		for (int x = 15; x < 800; x += 16) {
			for (int y = 6; y < 480; y += 12) {
				Pixel p = image.GetBuffer()[x / 16 + (y / 12) * 50];
				int red = p & 0xff0000;
				int green = p & 0x00ff00;
				int blue = p & 0x0000ff;
				//assert(y < 400);
				screen->Bar(x, y, x + 12, y + 2, red);
				screen->Bar(x, y + 4, x + 12, y + 6, green);
				screen->Bar(x, y +8, x + 12, y + 10, blue);
			}
		}
	
		/*
		//ball in a box
		theSprite.Draw(screen, spriteX, spriteY); //add ball to screen
		spriteY += speed;
		spriteX += speedX;
		speed++;
		bool hitBottom = spriteY > (512 - 50);
		bool hitTop = spriteY < (0);
		bool hitRight = spriteX > (812 - 50);
		bool hitLeft = spriteX < (0);
		//printf("hitBottom: %i\n", hitBottom);

		if (hitBottom) {
			spriteY = 512 - 50;
			speed = -speed;
			theSprite.Draw(screen, spriteX, spriteY);
		}
		else if (hitTop){
			spriteY = 0;
			speed = - 0.5 * speed;
			theSprite.Draw(screen, spriteX, spriteY);
		}
		if (hitRight) {
			spriteX = 812 - 50;
			speedX = -speedX;
			theSprite.Draw(screen, spriteX, spriteY);
		}
		else if (hitLeft) {
			spriteX = 0;
			speedX = -speedX;
			theSprite.Draw(screen, spriteX, spriteY);
		}
		*/
		
	}
};

