#pragma once
#include "pch.h"

struct Particle {
	Vector2 pos;
	Vector2 vel;
	Colour colour;
};


class Game {
public:
	//void handleEvents(); do i need this?
	void init	(u16 windowX, u16 windowY);
	void update	();
	void render	();
	void clean	();


	inline bool isRunning() { return runGame; }
private:
	inline f32 getDist(Vector2 pos) {};
	bool runGame;


	
	u16 windowX, windowY;
	vector<Particle> particles;
};