#pragma once
#define _USE_MATH_DEFINES
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

using namespace sf;
using namespace std;

class Particle {
private:
	RectangleShape particle;
	FloatRect bounds;
	float velocity;
	float minVelocity = 10;
	float minSize = 30;
	float angle;
	float alphaValue = 255;
	float decreaseAlpha;
	bool isActive = false;
	Vector2f startPosition;
	Vector2f size;
	Vector2f direction;
	Vector2i emissionAngleRange;
	Texture particleTexture;

public:
	Particle();
	Particle(Vector2f position, Vector2i emissionAngleRange, Texture particleTexture);
	float lifetime;
	void init();
	void setActive(bool state);
	void update(float dt);
	void draw(RenderWindow & window);
	void resetParticle();
};