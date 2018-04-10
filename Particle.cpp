#include "Particle.h"

Particle::Particle() {
}

Particle::Particle(Vector2f position, Vector2i emissionAngleRange, Texture particleTexture) {
	startPosition = position;
	velocity = rand() % 20 + minVelocity;
	size = Vector2f(30,30);
	lifetime = rand() % 10 + 1;
	decreaseAlpha = alphaValue / lifetime;
	this->emissionAngleRange = emissionAngleRange;
    angle = rand() % (emissionAngleRange.y + 1 - emissionAngleRange.x) + emissionAngleRange.x;
	direction = Vector2f(cos(angle*M_PI / 180), sin(angle*M_PI / 180));
	this->particleTexture = particleTexture;
}

void Particle::init() {
	particle.setSize(size);
	particle.setOrigin(size.x / 2, size.y / 2);
	particle.setFillColor(Color::White);
	particle.setTexture(&particleTexture);
	particle.setPosition(startPosition);
	bounds = particle.getGlobalBounds();
}

void Particle::setActive(bool state) {
	isActive = state;
}

void Particle::update(float dt) {
	if (alphaValue >= 0) {
		alphaValue -= decreaseAlpha*dt;
		particle.setFillColor(Color(255, 255, 255, alphaValue));
	}
	particle.move(direction.x*velocity*dt, direction.y*velocity*dt);
}

void Particle::draw(RenderWindow & window) {
	if(isActive)
		window.draw(particle);
}

void Particle::resetParticle() {
	particle.setPosition(startPosition);
	particle.setFillColor(Color::White);
	alphaValue = 255;
	lifetime = rand() % 10 + 1;
	angle = rand() % (emissionAngleRange.y + 1 - emissionAngleRange.x) + emissionAngleRange.x;
	decreaseAlpha = alphaValue / lifetime;
}