#pragma once
#include<SFML/Graphics.hpp>
#include"defs.hpp"

class Ball
{
public:
	Ball(sf::Vector2f ballSpeed);
	~Ball();

	void setPos(sf::Vector2f pos);

	sf::FloatRect getGB();

	sf::Vector2f getPos();

	void Update(sf::Vector2f& ballSpeed, float dt);

	void Render(sf::RenderTarget& window);

private:
	sf::RectangleShape body;
};

