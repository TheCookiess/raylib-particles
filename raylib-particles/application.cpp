#pragma once
#include "pch.h"
#include "application.h"

SetRandomSeed(GetTime());
const u64 particleSize = 10000;


InitWindow(screenWidth, screenHeight, "raylib example!");
SetTargetFPS(60);