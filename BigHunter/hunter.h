#pragma once

#include <SFML/Graphics.hpp>

enum struct Direction
{
	NONE,
	UP,
	DOWN,
	LEFT,
	RIGHT
};

struct Hunter
{
	sf::CircleShape shape;
	Direction direction;
};

void initializeHunter(Hunter & hunter);
void updateHunter(Hunter & hunter, float elapsedTime);
bool handleHunterKeyPress(const sf::Event::KeyEvent &event, Hunter &hunter);
bool handleHunterKeyRelease(const sf::Event::KeyEvent &event, Hunter &hunter);