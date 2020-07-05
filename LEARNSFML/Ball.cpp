#include "pch.h"
#include "Ball.hpp"

Ball::Ball(sf::Vector2f ballSpeed)
{
	body.setSize({ 10.0f, 10.0f });
	
	body.setOrigin(body.getGlobalBounds().width / 2.0f, body.getGlobalBounds().height / 2.0f);

	body.setFillColor(color);
}

Ball::~Ball()
{
}

void Ball::setPos(sf::Vector2f pos)
{
	body.setPosition(pos);
}

sf::Vector2f Ball::getPos()
{
	return body.getPosition();
}

sf::FloatRect Ball::getGB()
{
	return body.getGlobalBounds();
}

void Ball::Update(sf::Vector2f& ballSpeed, float dt)
{
	if (body.getPosition().y - body.getSize().y/2.0f < 0.0f) ballSpeed.y = -ballSpeed.y;
	if (body.getPosition().y + body.getSize().y/2.0f > 600.0f) ballSpeed.y = -ballSpeed.y;

	body.move(ballSpeed.x * dt, ballSpeed.y * dt);
}

void Ball::Render(sf::RenderTarget& window)
{
	window.draw(body);
}
