#pragma once
#include <SFML/Graphics.hpp>
#include "ParticleSystem.h"

using namespace sf;
using namespace std;

class ParticleSystemManager {
private:
	Texture smoke, explosion;
	Texture cigaretteTexture, candleTexture;
	RectangleShape cigarette, candle;
	vector<ParticleSystem*> particleSystems;

public:
	ParticleSystemManager();
	void initCigarette();
	void initCandle();
	void update(float dt);
	void draw(RenderWindow & window);
};