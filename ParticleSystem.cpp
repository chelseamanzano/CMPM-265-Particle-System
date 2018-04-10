#include "ParticleSystem.h"

ParticleSystem::ParticleSystem() {

}

ParticleSystem::ParticleSystem(Vector2f position, int emissionAngle, Texture particleTexture) {
	pointEmitter = position; 
	emissionAngleRange = Vector2i(-1 * emissionAngle - 90, emissionAngle - 90);
	for (int i = 0; i < 110; i++) {
		Particle* p = new Particle(pointEmitter, emissionAngleRange, particleTexture);
		aliveParticles.push_back(p);
		aliveParticles[i]->init();
		if (i >= 0 && i < minCount) {
			aliveParticles[i]->setActive(true);
			aliveCount++;
		}
	}
	cout << aliveParticles.size() << endl;
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
		p->lifetime -= dt;

		if (p->lifetime <= 0)
			p->resetParticle();

		p->update(dt);
	}

	//check for key presses
	if (Keyboard::isKeyPressed(Keyboard::Add) && aliveCount < maxCount && !isAddPressed) {
		addParticles(10);
		isAddPressed = true;
	}
	else if(!Keyboard::isKeyPressed(Keyboard::Add) && isAddPressed)
		isAddPressed = false;
	if (Keyboard::isKeyPressed(Keyboard::Subtract) && aliveCount > minCount && !isSubtractPressed) {
		reduceParticles(10);
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