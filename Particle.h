#pragma once
#define _USE_MATH_DEFINES
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "Behavior.h"

using namespace sf;
using namespace std;

class Particle {
private:
	RectangleShape particle;
	Behavior * behavior;
	FloatRect bounds;
	float initVelocity;
	float currVelocity;
	float minVelocity = 20;
	float maxVelocity = 100;
	float minSize = 30;
	float maxSize = 200;
	float angle;
	float alphaValue = 255;
	float decreaseAlpha;
	bool isActive = false;
	Vector2f startPosition;
	Vector2f initSize;
	Vector2f currSize;
	Vector2f direction;
	Vector2i emissionAngleRange;
	Texture particleTexture;

public:
	Particle();
	Particle(Vector2f position, Vector2i emissionAngleRange, Texture particleTexture, Behavior * behavior);
	float initLifetime;
	float currLifetime;
	void init();
	void setActive(bool state);
	void update(float dt);
	void draw(RenderWindow & window);
	void resetParticle();
};