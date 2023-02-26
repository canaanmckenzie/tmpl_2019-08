#include "game.h"
#include "surface.h"
#include <cstdio> //printf
#include <cassert>
#include "template.h"

//constexpr auto PARTICLES = 4096u; //c++ 11 and up, compile time constant

namespace Tmpl8
{
	Surface tiles("assets/nc2tiles.png");
	Sprite tank(new Surface("assets/ctankbase.tga"), 16);
	int px = 32, py = 32;

	// -----------------------------------------------------------
	// Initialize the application
	// -----------------------------------------------------------
	void Game::Init() {}

	// -----------------------------------------------------------
	// Close down application
	// -----------------------------------------------------------
	void Game::Shutdown() {}

	char map[48][30]{
		"kcXkcXkcXkcXkcXkcXkcXkcXkcXkc","kcXfb-fb-fb-kc-kc-kcXkcXkcXkc","kcXfb-fb-fb-fb-fb-kcXkcXkcXkc",
		"kcXkcXkcXkcXkcXkcXkcXkcXkcXkc","kcXkc-kc-lcXlcXlcXkcXkcXkcXkc","kcXkcXkcXkcXkcXkcXkcXkcXkcXkc",
		"kcXkcXkcXkcXkcXkcXkcXkcXkcXkc","kcXfb-fb-fb-fb-fb-kcXkcXkcXkc","kcXlcXlcXfb-fb-fb-kcXkcXkcXkc",
		"kcXkcXkcXkcXkcXkcXkcXkcXkcXkc","kcXkcXkcXkcXkcXkcXkcXkcXkcXkc","kcXfb-fb-fb-kc-kc-kcXkcXkcXkc",
		"kcXkcXkcXkcXkcXkcXkcXkcXkcXkc","kcXlcXlcXfb-fb-fb-kcXkcXkcXkc","kcXkc-kc-lcXlcXlcXkcXkcXkcXkc",
		"kcXkcXkcXkcXkcXkcXkcXkcXkcXkc","kcXkc-kc-lcXlcXlcXkcXkcXkcXkc","kcXfb-fb-fb-kc-kc-kcXkcXkcXkc",
		"kcXkcXkcXkcXkcXkcXkcXkcXkcXkc","kcXlcXlcXfb-fb-fb-kcXkcXkcXkc","kcXkc-kc-lcXlcXlcXkcXkcXkcXkc",
		"kcXkcXkcXkcXkcXkcXkcXkcXkcXkc","kcXfb-fb-fb-kc-kc-kcXkcXkcXkc","kcXfb-fb-fb-fb-fb-kcXkcXkcXkc",
		"kcXlcXlcXfb-fb-fb-kcXkcXkcXkc","kcXkc-kc-lcXlcXlcXkcXkcXkcXkc","kcXkc-kc-lcXlcXlcXkcXkcXkcXkc",
		"kcXkc-kc-lcXlcXlcXkcXkcXkcXkc","kcXkc-kc-lcXlcXlcXkcXkcXkcXkc","kcXkc-kc-lcXlcXlcXkcXkcXkcXkc",
		"kcXkc-kc-lcXlcXlcXkcXkcXkcXkc","kcXfb-fb-fb-kc-kc-kcXkcXkcXkc","kcXfb-fb-fb-fb-fb-kcXkcXkcXkc",
		"kcXlcXlcXfb-fb-fb-kcXkcXkcXkc","kcXkc-kc-lcXlcXlcXkcXkcXkcXkc","kcXkcXkcXkcXkcXkcXkcXkcXkcXkc",
		"kcXfb-fb-fb-kc-kc-kcXkcXkcXkc","kcXfb-fb-fb-fb-fb-kcXkcXkcXkc","kcXlcXlcXfb-fb-fb-kcXkcXkcXkc",
		"kcXkc-kc-lcXlcXlcXkcXkcXkcXkc","kcXkc-kc-lcXlcXlcXkcXkcXkcXkc","kcXkc-kc-lcXlcXlcXkcXkcXkcXkc",
		"kcXkc-kc-lcXlcXlcXkcXkcXkcXkc","kcXkc-kc-lcXlcXlcXkcXkcXkcXkc","kcXkc-kc-lcXlcXlcXkcXkcXkcXkc",
		"kcXkc-kc-lcXlcXlcXkcXkcXkcXkc","kcXkc-kc-lcXlcXlcXkcXkcXkcXkc","kcXkc-kc-lcXlcXlcXkcXkcXkcXkc"
	};

	char map2[48][30]{
		"fb-fb-fb-fb-fb-fb-fb-fb-fb-fb","fb-fb-fb-fb-fb-fb-fb-fb-fb-fb","fb-fb-fb-fb-fb-fb-fb-fb-fb-fb",
		"fb-fb-fb-fb-fb-fb-fb-fb-fb-fb","fb-fb-fb-fb-fb-fb-fb-fb-fb-fb","fb-fb-fb-fb-fb-fb-fb-fb-fb-fb",
		"fb-fb-fb-fb-fb-fb-fb-fb-fb-fb","fb-fb-fb-fb-fb-fb-fb-fb-fb-fb","fb-fb-fb-fb-fb-fb-fb-fb-fb-fb",
		"fb-fb-fb-fb-fb-fb-fb-fb-fb-fb","fb-fb-fb-fb-fb-fb-fb-fb-fb-fb","fb-fb-fb-fb-fb-fb-fb-fb-fb-fb",
		"fb-fb-fb-fb-fb-fb-fb-fb-fb-fb","fb-fb-fb-fb-fb-fb-fb-fb-fb-fb","fb-fb-fb-fb-fb-fb-fb-fb-fb-fb",
		"fb-fb-fb-fb-fb-fb-fb-fb-fb-fb","fb-fb-fb-fb-fb-fb-fb-fb-fb-fb","fb-fb-fb-fb-fb-fb-fb-fb-fb-fb",
		"fb-fb-fb-fb-fb-fb-fb-fb-fb-fb","fb-fb-fb-fb-fb-fb-fb-fb-fb-fb","fb-fb-fb-fb-fb-fb-fb-fb-fb-fb",
		"fb-fb-fb-fb-fb-fb-fb-fb-fb-fb","fb-fb-fb-fb-fb-fb-fb-fb-fb-fb","fb-fb-fb-fb-fb-fb-fb-fb-fb-fb",
		"fb-fb-fb-fb-fb-fb-fb-fb-fb-fb","fb-fb-fb-fb-fb-fb-fb-fb-fb-fb","fb-fb-fb-fb-fb-fb-fb-fb-fb-fb",
		"fb-fb-fb-fb-fb-fb-fb-fb-fb-fb","fb-fb-fb-fb-fb-fb-fb-fb-fb-fb","fb-fb-fb-fb-fb-fb-fb-fb-fb-fb",
		"fb-fb-fb-fb-fb-fb-fb-fb-fb-fb","fb-fb-fb-fb-fb-fb-fb-fb-fb-fb","fb-fb-fb-fb-fb-fb-fb-fb-fb-fb",
		"fb-fb-fb-fb-fb-fb-fb-fb-fb-fb","fb-fb-fb-fb-fb-fb-fb-fb-fb-fb","fb-fb-fb-fb-fb-fb-fb-fb-fb-fb",
		"fb-fb-fb-fb-fb-fb-fb-fb-fb-fb","fb-fb-fb-fb-fb-fb-fb-fb-fb-fb","fb-fb-fb-fb-fb-fb-fb-fb-fb-fb",
		"fb-fb-fb-fb-fb-fb-fb-fb-fb-fb","fb-fb-fb-fb-fb-fb-fb-fb-fb-fb","fb-fb-fb-fb-fb-fb-fb-fb-fb-fb",
		"fb-fb-fb-fb-fb-fb-fb-fb-fb-fb","fb-fb-fb-fb-fb-fb-fb-fb-fb-fb","fb-fb-fb-fb-fb-fb-fb-fb-fb-fb",
		"fb-fb-fb-fb-fb-fb-fb-fb-fb-fb","fb-fb-fb-fb-fb-fb-fb-fb-fb-fb","fb-fb-fb-fb-fb-fb-fb-fb-fb-fb"
	};

	void DrawTile(int tx, int ty, Surface* screen, int x, int y) {
		Pixel* src = tiles.GetBuffer() + 1 + tx * 33 + (1 + ty * 33) * 595;
		Pixel* dst = screen->GetBuffer() + x + y * 800;
		for (int i = 0; i < 32; i++, src += 595, dst += 800) {
			for (int j = 0; j < 32; j++) {
				dst[j] = src[j];
			}
		}
	}

	class Tank {

	public:
		Tank() {
			x = 0;
			y = 0;
			rotation = 0;
		}
		void Tank::MoveRight(Surface* gamescreen) {
			x++;
			if (x > 800) {
				x = 0;
			}
			tank.Draw(gamescreen, x, y);
			tank.SetFrame(4);
		}
		void Tank::MoveDown(Surface* gamescreen) {
			y++;
			if (y > 512) {
				y = 0;
			}
			tank.Draw(gamescreen, x, y);
			tank.SetFrame(8);

		}
		int x, y, rotation;

	};

	bool CheckPos(int x, int y) {
		int tx = x / 32, ty = y / 32;
		return map2[ty][tx * 3 + 2] != 'X';
	}

	//add tank to map
	Tank mytank;

	//float x[200], y[200];
	// -----------------------------------------------------------
	// Initialize the application
	// -----------------------------------------------------------
	
	//dynamic particle movement across screen
	//int x[PARTICLES], y[PARTICLES]; //added for array set


		/* //random particles
		for (int i = 0; i < PARTICLES; i++) {
			x[i] = IRand(800), y[i] = IRand(512);
		}
		*/


	// -----------------------------------------------------------
	// Close down application
	// -----------------------------------------------------------

	// ---------------------------------------------------------
	// Main application tick function
	// -----------------------------------------------------------

	//Sprite theSprite(new Surface("assets/ball.png"), 1);
	
	/*
	int spriteX = 0;
	int spriteY = 100;
	int speed = 1;
	int speedX = 5;
	*/
	
	void Game::Tick(float deltaTime)
	{	

		screen->Clear(0);
		for (int y = 0; y < 16; y++) {
			for (int x = 0; x < 25; x++) {
				int tx = map2[y][x * 3] - 'a';
				int ty = map2[y][x * 3 + 1] - 'a';
				DrawTile(tx, ty, screen, x * 32, y * 32);
			}
		}

		/* //controls
		int nx = px, ny = py;
		if (GetAsyncKeyState(VK_LEFT)) { nx--; tank.SetFrame(12); }
		if (GetAsyncKeyState(VK_RIGHT)) { nx++; tank.SetFrame(4); }
		if (GetAsyncKeyState(VK_UP)) { ny--; tank.SetFrame(0); }
		if (GetAsyncKeyState(VK_DOWN)) { ny++; tank.SetFrame(8); }
		if (CheckPos(nx, ny) && CheckPos(nx + 30, ny + 30) &&
			CheckPos(nx + 30, ny) && CheckPos(nx, ny + 30)) {
			px = nx, py = ny;
		}
		*/

		//automate tank
		mytank.MoveDown(screen);



		// move a cross hairs with mouse, chase a white pixel around viewport
		/*
		screen->Clear(0);
		screen->Line(mousex, 0, mousex, 511, 0xff0000);
		screen->Line(0, mousey, 799, mousey, 0xff0000);
		*/

		/*
		for (int i = 0; i < PARTICLES; i++) {
			x[i] = (x[i] + 800 + (((i & 1) * 2) - 1)) % 800;
			y[i] = (y[i] + 512 + ((((i >> 2) & 1) * 2) - 1)) & 511;
			screen->GetBuffer()[x[i] + y[i] * 800] = 0xffffff;
		}
		*/
		/*
		for (int i = 0; i < 500; i++) {
			int dx = x[i] - mousex, dy = y[i] - mousey;
			int dist = sqrt(dx * dx + dy * dy);
			if (dist < 50 && dist != 0) {
				(int)x[i] += dx / dist * 2, (int)y[i] += dy / dist * 2;
			}
			screen->Plot((int)x[i], (int)y[i], 0xffffff);
		}
		*/
		//draw a grid
		/*
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
		*/
	
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

