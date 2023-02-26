#include "game.h"
#include "surface.h"
#include <cstdio> //printf
#include <cassert>
#include "template.h"
#include <windows.h>

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

		/*
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


	}
};

