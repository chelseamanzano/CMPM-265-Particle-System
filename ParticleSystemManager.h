#pragma once
#include <SFML/Graphics.hpp>
#include "ParticleSystem.h"

using namespace sf;
using namespace std;

class ParticleSystemManager {
private:
	Texture smoke, explosion, fire;
	Texture cigaretteTexture, candleTexture, dragonTexture;
	RectangleShape cigarette, candle, dragon;
	vector<ParticleSystem*> particleSystems;

public:
	ParticleSystemManager();
	void initCigarette();
	void initCandle();
	void initDragon();
	void update(float dt);
	void draw(RenderWindow & window);
};