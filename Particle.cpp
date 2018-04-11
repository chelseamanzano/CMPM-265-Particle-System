#include "Particle.h"

Particle::Particle() {
}

Particle::Particle(Vector2f position, Vector2i emissionAngleRange, Texture particleTexture, Behavior * behavior) {
	startPosition = position;
	initVelocity = rand() % 20 + minVelocity;
	currVelocity = initVelocity;
	initSize = Vector2f(30,30);
	currSize = initSize;
	initLifetime = rand() % 5 + 1;
	currLifetime = initLifetime;
	decreaseAlpha = alphaValue / initLifetime;
	this->emissionAngleRange = emissionAngleRange;
    angle = rand() % (emissionAngleRange.y + 1 - emissionAngleRange.x) + emissionAngleRange.x;
	direction = Vector2f(cos(angle*M_PI / 180), sin(angle*M_PI / 180));
	this->particleTexture = particleTexture;
	this->behavior = behavior;
}

void Particle::init() {
	particle.setSize(initSize);
	particle.setOrigin(initSize.x / 2, initSize.y / 2);
	particle.setFillColor(Color::White);
	particle.setTexture(&particleTexture);
	particle.setPosition(startPosition);
}

void Particle::setActive(bool state) {
	isActive = state;
}

void Particle::update(float dt) {
	if (alphaValue > 0) {
		alphaValue -= decreaseAlpha*dt;
		particle.setFillColor(Color(255, 255, 255, alphaValue));
	}
	currSize.x += behavior->behavior_at_time(currSize.x / maxSize, initLifetime, currLifetime)*dt;
	currSize.y += behavior->behavior_at_time(currSize.y / maxSize, initLifetime, currLifetime)*dt;
	currVelocity += behavior->behavior_at_time(currVelocity / maxVelocity, initLifetime, currLifetime)*dt;
	particle.setOrigin(currSize.x / 2, currSize.y / 2);
	particle.setSize(currSize);
	particle.rotate(currVelocity*dt);
	particle.move(direction.x*currVelocity*dt, direction.y*currVelocity*dt);
}

void Particle::draw(RenderWindow & window) {
	if(isActive)
		window.draw(particle);
}

void Particle::resetParticle() {
	particle.setPosition(startPosition);
	particle.setFillColor(Color::White);
	alphaValue = 255;
	initLifetime = rand() % 5 + 1;
	currLifetime = initLifetime;
	angle = rand() % (emissionAngleRange.y + 1 - emissionAngleRange.x) + emissionAngleRange.x;
	decreaseAlpha = alphaValue / initLifetime;
	currSize = initSize;
	particle.setOrigin(currSize.x / 2, currSize.y / 2);
	currVelocity = initVelocity;
}