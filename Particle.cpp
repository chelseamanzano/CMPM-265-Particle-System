#include "Particle.h"

Particle::Particle() {
	position = Vector2f(0, 0);
	velocity = rand() % 30 + minVelocity;
	size = Vector2f(rand() % 20 + minSize, rand() % 20 + minSize);
	emissionAngleRange = Vector2f(rand() % minAngle, rand() % maxAngle);
	lifetime = rand() % 10 + 1;
	particleTexture.loadFromFile("resources/smoke-particle.png");
}

Particle::Particle(Vector2f position) {
	this->position = position;
	velocity = rand() % 30 + minVelocity;
	size = Vector2f(rand() % 20 + minSize, rand() % 20 + minSize);
	emissionAngleRange = Vector2f(rand() % minAngle, rand() % maxAngle);
	lifetime = rand() % 10 + 1;
	particleTexture.loadFromFile("resources/smoke-particle.png");
	bool angleWithinRange = false;
    angle = rand() % 120 - 60;
	direction.x = cos(angle);
	direction.y = sin(angle);
}

void Particle::init() {
	particle.setSize(size);
	particle.setOrigin(size.x / 2, size.y / 2);
	particle.setFillColor(Color::White);
	particle.setTexture(&particleTexture);
	particle.setPosition(position);
	bounds = particle.getGlobalBounds();
}

void Particle::update(float dt) {
	particle.move(direction.x*velocity*dt, direction.y*velocity*dt);
}

void Particle::draw(RenderWindow & window) {
	window.draw(particle);
}

void Particle::resetParticle() {
	particle.setPosition(position);
	lifetime = rand() % 10 + 1;
}