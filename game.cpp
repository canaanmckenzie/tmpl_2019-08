#include "game.h"
#include "surface.h"
#include <cstdio> //printf
#include <cassert>
#include "template.h"
#include <windows.h>

#define TILESIZE 32
#define MAPSIZEX 800
#define MAPSIZEY 512

namespace Tmpl8
{
	Surface tiles("assets/nc2tiles.png");
	Sprite tank(new Surface("assets/ctankbase.tga"), 16);
	int px = 64, py = 32;

	// -----------------------------------------------------------
	// Initialize the application
	// -----------------------------------------------------------
	void Game::Init() {}

	// -----------------------------------------------------------
	// Close down application
	// -----------------------------------------------------------
	void Game::Shutdown() {}

	char map[16][75]{
		"ec-fe-fe-fe-fe-fe-fe-fe-fe-fe-fe-fe-fe-fe-fe-fe-fe-fe-fe-fe-fe-fe-fe-fe-fc",
		"fa-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fa",
		"fa-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fa",
		"fa-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fa",
		"fa-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fa",
		"fa-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fa",
		"fa-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fa",
		"fa-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fa",
		"fa-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fa",
		"fa-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fa",
		"fa-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fa",
		"fa-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fa",
		"fa-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fa",
		"fa-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fa",
		"fa-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fb-fa",
		"ed-fe-fe-fe-fe-fe-fe-fe-fe-fe-fe-fe-fe-fe-fe-fe-fe-fe-fe-fe-fe-fe-fe-fe-fd",
	};

	void DrawTile(int tx, int ty, Surface* screen, int x, int y) {
		Pixel* src = tiles.GetBuffer() + 1 + tx * (TILESIZE+1) + (1 + ty * (TILESIZE+1)) * 595;
		Pixel* dst = screen->GetBuffer() + x + y * MAPSIZEX;
		for (int i = 0; i < TILESIZE; i++, src += 595, dst += MAPSIZEX) {
			for (int j = 0; j < TILESIZE; j++) {
				dst[j] = src[j];
			}
		}
	}

	class Tank {

	public:
		Tank() {
			x = 0;
			y = 200;
			rotation = 0;
		}
		void Tank::MoveRight(Surface* gamescreen) {
			x++;
			if (x > MAPSIZEX) {
				x = 0;
			}
			tank.Draw(gamescreen, x, y);
			tank.SetFrame(4);
		}
		void Tank::MoveDown(Surface* gamescreen) {
			y++;
			if (y > MAPSIZEY) {
				y = 0;
			}
			tank.Draw(gamescreen, x, y);
			tank.SetFrame(8);

		}
		void Tank::MoveUp(Surface* gamescreen) {
			y--;
			if (y < 0) {
				y = MAPSIZEY;
			}
			tank.Draw(gamescreen, x, y);
			tank.SetFrame(0);
		}
		void Tank::MoveLeft(Surface* gamescreen) {
			x--;
			if (x < 0) {
				x = MAPSIZEX;
			}
			tank.Draw(gamescreen, x, y);
			tank.SetFrame(12);
		}
		int x, y, rotation;

	};

	bool CheckPos(int x, int y) {
		int tx = x / TILESIZE, ty = y / TILESIZE;
		return map[ty][tx * 3 + 2] != 'X';
	}

	//add tank to map
	Tank mytank;

	void Game::Tick(float deltaTime)
	{	

		screen->Clear(0);
		for (int y = 0; y < MAPSIZEY/TILESIZE; y++) {
			for (int x = 0; x < MAPSIZEX/TILESIZE; x++) {
				int tx = map[y][x * 3] - 'a';
				int ty = map[y][x * 3 + 1] - 'a';
				DrawTile(tx, ty, screen, x * TILESIZE, y * TILESIZE);
			}
		}

		/* //user controls
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
		mytank.MoveRight(screen);


	}
};

