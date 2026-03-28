#include "PlayScene.hpp"
#include "Game.hpp"
#include "raylib.h"

int main()
{

	InitWindow(1280, 720, "Friday Night Funkin'");
	InitAudioDevice();

	SetTargetFPS(GetMonitorRefreshRate(GetCurrentMonitor()) * 2);

	funkin::Game::start(std::make_unique<funkin::scenes::PlayScene>());

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(WHITE);
		funkin::Game::update(GetFrameTime());
		EndDrawing();
	}


	CloseAudioDevice();
	CloseWindow();

	return 0;
}