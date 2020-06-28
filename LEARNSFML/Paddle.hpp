#pragma once
#include<SFML/Graphics.hpp>
#include"defs.hpp"

class Paddle
{
public:
	Paddle(sf::Vector2f size, std::pair<sf::Keyboard::Key, sf::Keyboard::Key> controls, sf::Vector2f initPos);
	~Paddle();

	void Update(float dt);

	void Render(sf::RenderWindow& window);

	sf::FloatRect getGB();

private:
	sf::RectangleShape body;

	sf::Keyboard::Key UP;
	sf::Keyboard::Key DOWN;
};

