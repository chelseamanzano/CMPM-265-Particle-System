#pragma once
#include <SFML/Graphics.hpp>
#include "Particle.h"

using namespace sf;
using namespace std;

class ParticleSystem {
private:
	vector<Particle*> aliveParticles;
	Vector2f pointEmitter;
	int aliveCount;
	int initialCount = 10;
	int maxCount = 30;

public:
	ParticleSystem();
	void update(float dt);
	void draw(RenderWindow & window);
};