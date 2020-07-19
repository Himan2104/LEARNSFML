#include "Ball.hpp"

Ball::Ball(sf::Vector2f ballSpeed) : rect(0,0,10,10)
{
	body.setSize({ 20.0f, 20.0f });
	
	body.setOrigin(body.getGlobalBounds().width / 2.0f, body.getGlobalBounds().height / 2.0f);

	body.setFillColor(color);

	txr.loadFromFile("ball.png");

	body.setTexture(&txr);
	body.setTextureRect(rect);

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

void Ball::Update(sf::Vector2f& ballSpeed, float dt, bool impact)
{
	if (body.getPosition().y - body.getSize().y/2.0f < 0.0f) ballSpeed.y = -ballSpeed.y;
	if (body.getPosition().y + body.getSize().y/2.0f > Vmode.height) ballSpeed.y = -ballSpeed.y;

	body.move(ballSpeed.x * dt, ballSpeed.y * dt);

	if (impact) rect.left = 10;
	else rect.left = 0;

	body.setTextureRect(rect);
}

void Ball::Render(sf::RenderTarget& window)
{
	window.draw(body);
}
