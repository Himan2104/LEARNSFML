#include "pch.h"
#include "Paddle.hpp"

Paddle::Paddle(sf::Vector2f size, std::pair<sf::Keyboard::Key, sf::Keyboard::Key> controls, sf::Vector2f initPos)
{
	body.setSize(size);
	body.setPosition(initPos);
	body.setOrigin(body.getGlobalBounds().width / 2.0f, body.getGlobalBounds().height / 2.0f);
	UP = controls.first;
	DOWN = controls.second;
	body.setFillColor(color);
}

Paddle::~Paddle()
{
}

void Paddle::Update(float dt)
{
	if (sf::Keyboard::isKeyPressed(UP) && body.getPosition().y - body.getGlobalBounds().height/2.0f > 0.0f) body.move(0.0f, -paddleSpeed * dt);
	if (sf::Keyboard::isKeyPressed(DOWN) && body.getPosition().y + body.getGlobalBounds().height / 2.0f < 600.0f) body.move(0.0f, paddleSpeed * dt);
}

void Paddle::Render(sf::RenderWindow& window)
{
	window.draw(body);
}

sf::FloatRect Paddle::getGB()
{
	return body.getGlobalBounds();
}
