#pragma once
#include "pch.h"

struct Particle {
	//Color colour;
    Vector2 pos;
    Vector2 vel;

    Particle(f32 _posX, f32 _posY, f32 _velX, f32 _velY/*, Color _colour*/) {
        pos = { _posX, _posY };
        vel = { _velX, _velY };
        //colour = _colour;
    }
};


class Game {
public:
    Game();
    ~Game();

	void init	(u16 windowX, u16 windowY, u32 particleCount);
	void update	(Vector2 cursorPos, f32 friction, f32 multiplier);
    void render	();
	void clean	();


	inline bool isRunning() { return runGame; }

private:
	bool runGame;
	
	u16 width, height;
	vector<Particle> particles;
};