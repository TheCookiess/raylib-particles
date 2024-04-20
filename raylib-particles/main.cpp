#pragma once
#include "pch.h"
#include "game.h"

int main(int, char**) {
	constexpr u16 screenWidth = 800;
	constexpr u16 screenHeight = 640;
    constexpr u64 particleCount = 200000;
    constexpr f32 friction = 0.99f;
    f32 multiplier = 1.f;

	SetRandomSeed(GetTime());

	InitWindow(screenWidth, screenHeight, "raylib particle-sim!");
	SetTargetFPS(60);

	Game* game = new Game();
	game->init(screenWidth, screenHeight, particleCount);


	while (game->isRunning() || !WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(RAYWHITE);

        multiplier += (f32)GetMouseWheelMove() / 10.f;
        Vector2 cursorPos = GetMousePosition();
		game->update(cursorPos, friction, multiplier);

        string cursorPosStr     = "Cursor Pos: " + to_string((u64)cursorPos.x) + " | " + to_string((u64)cursorPos.y);
        string multiplierStr    = "Multiplier: " + to_string(multiplier);
        string particleCountStr = "Particle Count: " + to_string(particleCount);
        string fpsStr           = "FPS: " + to_string(GetFPS());
        DrawText(cursorPosStr.c_str()       , 10, 10, 20, BLACK);
        DrawText(multiplierStr.c_str()      , 10, 35, 20, BLACK);
        DrawText(particleCountStr.c_str()   , 10, 60, 20, BLACK);
		DrawText(fpsStr.c_str()             , 10, 85, 20, BLACK);

        EndDrawing();
	}

	CloseWindow();

	return 0;
}
