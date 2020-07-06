#pragma once
#include<SFML/Graphics.hpp>
#include"defs.hpp"

class Paddle
{
public:
	Paddle(sf::Vector2f size, std::pair<sf::Keyboard::Key, sf::Keyboard::Key> controls, sf::Vector2f initPos);
	~Paddle();

	void Update(float dt, bool switchFrame);

	void Render(sf::RenderTarget& window);

	sf::FloatRect getGB();

private:
	sf::Texture txr;
	sf::RectangleShape body;

	sf::IntRect rect;

	sf::Keyboard::Key UP;
	sf::Keyboard::Key DOWN;
};

