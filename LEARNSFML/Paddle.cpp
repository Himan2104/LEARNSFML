#include "Paddle.hpp"

Paddle::Paddle(sf::Vector2f size, std::pair<sf::Keyboard::Key, sf::Keyboard::Key> controls, sf::Vector2f initPos)
	:rect(0, 0, 10, 100)
{
	body.setSize(size);
	body.setPosition(initPos);
	body.setOrigin(body.getGlobalBounds().width / 2.0f, body.getGlobalBounds().height / 2.0f);
	UP = controls.first;
	DOWN = controls.second;
	body.setFillColor(color);

	txr.loadFromFile("paddle.png");
	body.setTexture(&txr);
	body.setTextureRect(rect);
}

Paddle::~Paddle()
{
}

void Paddle::Update(float dt, bool switchFrame)
{
	if (sf::Keyboard::isKeyPressed(UP) && body.getPosition().y - body.getGlobalBounds().height/2.0f > 0.0f) body.move(0.0f, -paddleSpeed * dt);
	if (sf::Keyboard::isKeyPressed(DOWN) && body.getPosition().y + body.getGlobalBounds().height / 2.0f < 720.0f) body.move(0.0f, paddleSpeed * dt);
	if (switchFrame)
	{
		if (rect.left == 90) rect.left = 0;
		rect.left += 10;
		body.setTextureRect(rect);
	}
}

void Paddle::Render(sf::RenderTarget& window)
{
	window.draw(body);
}

sf::FloatRect Paddle::getGB()
{
	return body.getGlobalBounds();
}
