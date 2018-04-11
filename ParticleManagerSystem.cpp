#include "ParticleSystemManager.h"

ParticleSystemManager::ParticleSystemManager() {
	smoke.loadFromFile("resources/smoke-particle-1.png");
	explosion.loadFromFile("resources/explosion-particle-1.png");
	fire.loadFromFile("resources/fire-particle-1.png");
	ParticleSystem* ps1 = new ParticleSystem(Vector2f(200, 500), 20, smoke);
	particleSystems.push_back(ps1);
	ParticleSystem* ps2 = new ParticleSystem(Vector2f(600, 500), 90, explosion);
	particleSystems.push_back(ps2);
	ParticleSystem* ps3 = new ParticleSystem(Vector2f(1000, 500), 45, fire);
	particleSystems.push_back(ps3);
	initCigarette();
	initCandle();
	initDragon();
}

void ParticleSystemManager::initCigarette() {
	cigaretteTexture.loadFromFile("resources/cigarette.png");
	cigarette.setSize(Vector2f(100, 100));
	cigarette.setOrigin(50, 50);
	cigarette.setFillColor(Color::White);
	cigarette.setTexture(&cigaretteTexture);
	cigarette.setPosition(235, 505);
}

void ParticleSystemManager::initCandle() {
	candleTexture.loadFromFile("resources/sparkling-candle.png");
	candle.setSize(Vector2f(100, 100));
	candle.setOrigin(50, 50);
	candle.setFillColor(Color::White);
	candle.setTexture(&candleTexture);
	candle.setPosition(610, 550);
}

void ParticleSystemManager::initDragon() {
	dragonTexture.loadFromFile("resources/dragon.png");
	dragon.setSize(Vector2f(100, 100));
	dragon.setOrigin(50, 50);
	dragon.setFillColor(Color::White);
	dragon.setTexture(&dragonTexture);
	dragon.setPosition(1000, 530);
}

void ParticleSystemManager::update(float dt) {
	for (int i = 0; i < particleSystems.size(); i++) {
		particleSystems[i]->update(dt);
	}
}

void ParticleSystemManager::draw(RenderWindow & window) {
	for (int i = 0; i < particleSystems.size(); i++) {
		particleSystems[i]->draw(window);
	}
	window.draw(cigarette);
	window.draw(candle);
	window.draw(dragon);
}