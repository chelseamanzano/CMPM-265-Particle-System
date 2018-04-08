#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include "ParticleSystem.h"

using namespace sf;
using namespace std;

void update_state(float dt, ParticleSystem & ps);
void render_frame(RenderWindow & window, ParticleSystem & ps);

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "CMPM-265 | Particle System | Chelsea Manzano");

	srand(static_cast<unsigned>(time(NULL)));

	ParticleSystem ps;

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
		update_state(dt, ps);
		render_frame(window, ps);
		window.display();
	}

	return 0;
}

void update_state(float dt, ParticleSystem & ps) {
	ps.update(dt);
}

void render_frame(RenderWindow & window, ParticleSystem & ps) {
	window.clear(Color::Black);
	ps.draw(window);
}
