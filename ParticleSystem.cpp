#include "ParticleSystem.h"

ParticleSystem::ParticleSystem() {

}

ParticleSystem::ParticleSystem(Vector2f position, int emissionAngle, Texture particleTexture) {
	pointEmitter = position;
	emissionAngleRange = Vector2i(-1 * emissionAngle - 90, emissionAngle - 90);
	for (int i = 0; i < 10100; i++) {
		int behaviorType = rand() % 5 + 1;
		if (behaviorType == 1)
			behavior = new LinearBehavior();
		else if (behaviorType == 2)
			behavior = new QuarticBehavior();
		else if (behaviorType == 3)
			behavior = new QuadraticBehavior();
		else if (behaviorType == 4)
			behavior = new SinusoidalBehavior();
		else if (behaviorType == 5)
			behavior = new ExponentialBehavior();
		Particle* p = new Particle(pointEmitter, emissionAngleRange, particleTexture, behavior);
		aliveParticles.push_back(p);
		aliveParticles[i]->init();
		if (i >= 0 && i < minCount) {
			aliveParticles[i]->setActive(true);
			aliveCount++;
		}
	}
}

ParticleSystem::~ParticleSystem() {
	for (int i = 0; i < aliveParticles.size(); i++) {
		delete aliveParticles[i];
		aliveParticles[i] = nullptr;
	}
}

void ParticleSystem::addParticles(int count) {
	for (int i = 0; i < count; i++) {
		aliveParticles[aliveCount+i]->resetParticle();
		aliveParticles[aliveCount+i]->setActive(true);
		aliveCount++;
		cout << aliveCount << endl;
	}
}

void ParticleSystem::reduceParticles(int count) {
	for (int i = 0; i < count; i++) {
		aliveParticles[aliveCount-i-1]->setActive(false);
		aliveCount--;
		cout << aliveCount << endl;
	}
}

void ParticleSystem::update(float dt) {
	for (int i = 0; i < aliveCount; i++) {
		Particle* p = aliveParticles[i];
		p->currLifetime += dt;

		if (p->currLifetime >= p->initLifetime)
			p->resetParticle();

		p->update(dt);
	}

	//check for key presses
	if (Keyboard::isKeyPressed(Keyboard::Add) && aliveCount < maxCount && !isAddPressed) {
		addParticles(50);
		isAddPressed = true;
	}
	else if(!Keyboard::isKeyPressed(Keyboard::Add) && isAddPressed)
		isAddPressed = false;
	if (Keyboard::isKeyPressed(Keyboard::Subtract) && aliveCount > minCount && !isSubtractPressed) {
		reduceParticles(50);
		isSubtractPressed = true;
	}
	else if(!Keyboard::isKeyPressed(Keyboard::Subtract) && isSubtractPressed)
		isSubtractPressed = false;
}

void ParticleSystem::draw(RenderWindow & window) {
	for (int i = 0; i < aliveCount; i++) {
		Particle* p = aliveParticles[i];
		p->draw(window);
	}
}