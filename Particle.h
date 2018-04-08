#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Particle {
private:
	RectangleShape particle;
	FloatRect bounds;
	float velocity;
	float minVelocity = 10;
	float minSize = 30;
	int minAngle = -30;
	int maxAngle = 30;
	float angle;
	Vector2f position;
	Vector2f size;
	Vector2f direction;
	Vector2f emissionAngleRange;
	Texture particleTexture;

public:
	Particle();
	Particle(Vector2f position);
	float lifetime;
	void init();
	void update(float dt);
	void draw(RenderWindow & window);
	void resetParticle();
};