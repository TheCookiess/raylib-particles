//  https://vscode.dev/github/codemaker4/raylib-particle-toy/tree/master
#pragma once
#include "pch.h"
#include "application.h"

int main(int, char**) {
	const u32 screenWidth = 800;
	const u32 screenHeight = 640;

	InitWindow(screenWidth, screenHeight, "raylib particle-sim!");

	Game* game = new Game();
	game->init(screenWidth, screenHeight);
	while (game->isRunning()) {   // Detect window close button or ESC key
		Vector2 mouse = GetMousePosition();
	}
}