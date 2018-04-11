#pragma once
#include <SFML/Graphics.hpp>
#include "Particle.h"
#include "Behavior.h"
#include "LinearBehavior.h"
#include "QuarticBehavior.h"
#include "QuadraticBehavior.h"
#include "SinusoidalBehavior.h"

using namespace sf;
using namespace std;

class ParticleSystem {
private:
	vector<Particle*> aliveParticles;
	Behavior * behavior;
	Vector2f pointEmitter;
	Vector2i emissionAngleRange;
	RectangleShape cigarette;
	Texture cigaretteTexture;
	bool isAddPressed, isSubtractPressed = false;
	int aliveCount = 0;
	int minCount = 50;
	int maxCount = 10000;

public:
	ParticleSystem();
	ParticleSystem(Vector2f position, int emissionAngle, Texture particleTexture);
	~ParticleSystem();
	void addParticles(int count);
	void reduceParticles(int count);
	void update(float dt);
	void draw(RenderWindow & window);
};