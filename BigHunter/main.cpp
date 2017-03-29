#include <SFML/Graphics.hpp>
#include "hunter.h"

void handleEvents(sf::RenderWindow & window, Hunter &hunter)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
		else if (event.type == sf::Event::KeyPressed)
		{
			handleHunterKeyPress(event.key, hunter);
		}
		else if (event.type == sf::Event::KeyReleased)
		{
			handleHunterKeyRelease(event.key, hunter);
		}
	}
}

void update(sf::Clock &clock, Hunter &hunter)
{
	const float elapsedTime = clock.getElapsedTime().asSeconds();
	clock.restart();
	updateHunter(hunter, elapsedTime);
}


void render(sf::RenderWindow & window, const Hunter &hunter)
{
	window.clear();
	window.draw(hunter.shape);
	window.display();
}

int main(int, char *[])
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "BIG HUNTER");
	Hunter hunter;
	initializeHunter(hunter);

	sf::Clock clock;

	while (window.isOpen())
	{
		handleEvents(window, hunter);
		update(clock, hunter);
		render(window, hunter);
	}
	return 0;
}