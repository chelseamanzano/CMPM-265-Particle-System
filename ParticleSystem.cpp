#include "ParticleSystem.h"

ParticleSystem::ParticleSystem() {
	pointEmitter = Vector2f(400, 550);
	int aliveCount = 0;
	for (int i = 0; i < 10; i++) {
		Particle* p = new Particle(pointEmitter);
		aliveParticles.push_back(p);
		aliveParticles[i]->init();
	}
}


void ParticleSystem::update(float dt) {
	for (int i = 0; i < aliveParticles.size(); i++) {
		Particle* p = aliveParticles[i];
		p->lifetime -= dt;

		if (p->lifetime <= 0)
			p->resetParticle();

		p->update(dt);
	}
}
void ParticleSystem::draw(RenderWindow & window) {
	for (size_t i = 0; i < aliveParticles.size(); i++) {
		Particle* p = aliveParticles[i];
		p->draw(window);
	}
}