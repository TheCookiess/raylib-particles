#pragma once
#include "pch.h"
#include "game.h"

Game::Game() {};
Game::~Game() {};

void Game::init(u16 newWidth, u16 newHeight, u32 particleCount) {
	runGame = true;
	width  = newWidth;
	height = newHeight;

	particles.clear();
	particles.reserve(particleCount);

    //Color particleColour = { 30, 30, 30, 125 };
	for (u64 i = 0; i < particleCount; i++) {
        particles.emplace_back((float)GetRandomValue(0, newWidth - 1)
                              ,(float)GetRandomValue(0, newHeight - 1)
                              ,(float)GetRandomValue(-100, 100) / 100.f
                              ,(float)GetRandomValue(-100, 100) / 100.f
                              /*, particleColour*/);
	}
}

float getDist(Vector2 v1, Vector2 v2) {
    const float dx = v1.x - v2.x;
    const float dy = v1.y - v2.y;
    return sqrt((dx * dx) + (dy * dy));
}

Vector2 getNormal(Vector2 v1, Vector2 v2, f32 dist) {
    //float dist = getDist(v1, v2);
    if (dist == 0.0f) dist = 1;
    const float x = (v1.x - v2.x) * (1 / dist);
    const float y = (v1.y - v2.y) * (1 / dist);
    return { x,y };
}

void Game::update(Vector2 cursorPos, f32 friction, f32 multiplier) {
    for (auto& p : particles) {
        //f32 dist = Vector2Distance(p.pos, cursorPos);
        //Vector2 normal = Vector2Multiply(Vector2Normalize(Vector2Subtract(p.pos, cursorPos)), {multiplier, multiplier});
        f32 dist = getDist(p.pos, cursorPos);
        Vector2 normal = Vector2Multiply(getNormal(p.pos, cursorPos, dist), { multiplier,multiplier } );

        if (dist > multiplier / 2) {
            p.vel.x -= (normal.x / dist);
            p.vel.y -= (normal.y / dist);
        } else {
            if (p.vel.x < 0) p.vel.x++;
            else p.vel.x--;
            if (p.vel.y < 0) p.vel.y++;
            else p.vel.y--;
        }

        p.vel.x *= friction;
        p.vel.y *= friction;
          
        p.pos.x += p.vel.x;
        p.pos.y += p.vel.y;

        //if (p.pos.x < 0 || p.pos.x >= width)  p.vel.x *= -1;
        //if (p.pos.y < 0 || p.pos.y >= height) p.vel.y *= -1;

        if (p.pos.x < 0)        p.pos.x += width;
        if (p.pos.x >= width)   p.pos.x -= width;
        if (p.pos.y < 0)        p.pos.y += height;
        if (p.pos.y >= height)  p.pos.y -= height;

        DrawPixelV(p.pos, { 30, 30, 30, 125 });
    }
}