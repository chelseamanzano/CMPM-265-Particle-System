#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include "ParticleSystemManager.h"

using namespace sf;
using namespace std;

void update_state(float dt, ParticleSystemManager & psm);
void render_frame(RenderWindow & window, ParticleSystemManager & psm);

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 600), "CMPM-265 | Particle System | Chelsea Manzano");

	srand(static_cast<unsigned>(time(NULL)));

	ParticleSystemManager psm;

	Clock clock;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		float dt = clock.restart().asSeconds();

		window.clear();
		update_state(dt, psm);
		render_frame(window, psm);
		window.display();
	}

	return 0;
}

void update_state(float dt, ParticleSystemManager & psm) {
	psm.update(dt);
}

void render_frame(RenderWindow & window, ParticleSystemManager & psm) {
	window.clear(Color::Black);
	psm.draw(window);
}
