#include "hunter.h"

static const sf::Color HUNTER_COLOR = sf::Color::Red;
static const float HUNTER_SPEED = 20.f;
static const sf::Vector2f HUNTER_INITIAL_POSITION = { 100, 500 }; // pixels.

void initializeHunter(Hunter &hunter)
{
	hunter.direction = Direction::NONE;
	hunter.shape.setRadius(20);
	hunter.shape.setFillColor(HUNTER_COLOR);
	hunter.shape.setPosition(HUNTER_INITIAL_POSITION);
}

void updateHunter(Hunter &hunter, float eleapsedTime)
{
	const float step = HUNTER_SPEED * eleapsedTime;
	sf::Vector2f position = hunter.shape.getPosition();
	switch (hunter.direction)
	{
	case Direction::UP:
		position.y -= step;
		break;
	case Direction::DOWN:
		position.y += step;
		break;
	case Direction::LEFT:
		position.x -= step;
		break;
	case Direction::RIGHT:
		position.x += step;
		break;
	case Direction::NONE:
		break;
	}
	hunter.shape.setPosition(position);
}

bool handleHunterKeyPress(const sf::Event::KeyEvent &event, Hunter &hunter)
{
	bool handled = true;
	switch (event.code)
	{
	case sf::Keyboard::Up:
		hunter.direction = Direction::UP;
		break;
	case sf::Keyboard::Down:
		hunter.direction = Direction::DOWN;
		break;
	case sf::Keyboard::Left:
		hunter.direction = Direction::LEFT;
		break;
	case sf::Keyboard::Right:
		hunter.direction = Direction::RIGHT;
		break;
	default:
		handled = false;
		break;
	}
	return handled;
}

bool handleHunterKeyRelease(const sf::Event::KeyEvent &event, Hunter &hunter)
{
	bool handled = true;
	switch (event.code)
	{
	case sf::Keyboard::Up:
		if (hunter.direction == Direction::UP)
		{
			hunter.direction = Direction::NONE;
		}
		break;
	case sf::Keyboard::Down:
		if (hunter.direction == Direction::DOWN)
		{
			hunter.direction = Direction::NONE;
		}
		break;
	case sf::Keyboard::Left:
		if (hunter.direction == Direction::LEFT)
		{
			hunter.direction = Direction::NONE;
		}
		break;
	case sf::Keyboard::Right:
		if (hunter.direction == Direction::RIGHT)
		{
			hunter.direction = Direction::NONE;
		}
		break;
	default:
		handled = false;
		break;
	}
	return handled;
}


