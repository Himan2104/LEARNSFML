#include"pch.h"
#include<iostream> 
#include<SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window({ 800,600 }, "Ponmg");
	window.setFramerateLimit(120);

	sf::RectangleShape midLine;
	midLine.setSize(sf::Vector2f(2.0f, 600.0f));
	midLine.setPosition(400.0f, 0.0f);

	sf::RectangleShape paddleLeft;
	paddleLeft.setSize(sf::Vector2f(10.0f, 100.0f));
	paddleLeft.setOrigin(paddleLeft.getGlobalBounds().width/2.0f, paddleLeft.getGlobalBounds().height / 2.0f);
	sf::RectangleShape paddleRight(paddleLeft);
	
	paddleLeft.setPosition(10.0f, 300.0f);
	paddleRight.setPosition(790.0f, 300.0f);

	sf::CircleShape ball(10.0f);
	ball.setOrigin(ball.getGlobalBounds().width / 2.0f, ball.getGlobalBounds().height / 2.0f);
	ball.setPosition(400.0f, 300.0f);

	unsigned int scoreA = 0, scoreB = 0;
	
	sf::Font font;
	font.loadFromFile("C:/Windows/Fonts/arial.ttf");
	sf::Text score;
	score.setFont(font);
	score.setString(std::to_string(scoreA) + "\t" + std::to_string(scoreB));
	score.setOrigin(score.getGlobalBounds().width / 2.0f, score.getGlobalBounds().height / 2.0f);
	score.setPosition(400.0f, 20.0f);

	//physics vars
	float paddleSpeed = 5.0f;
	sf::Vector2f ballSpeed(-2.5f, 2.5f);

	bool isServing = true;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && paddleRight.getPosition().y - 25.0f > 0.0f ) paddleRight.move(0.0f, -paddleSpeed);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && paddleRight.getPosition().y + 25.0f < 600.0f) paddleRight.move(0.0f, paddleSpeed);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && paddleLeft.getPosition().y - 25.0f > 0.0f) paddleLeft.move(0.0f, -paddleSpeed);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && paddleLeft.getPosition().y + 25.0f < 600.0f) paddleLeft.move(0.0f, paddleSpeed);


		if (isServing)
		{
			ball.setPosition(400.0f, 300.0f);
			isServing = false;
		}

		if (ball.getPosition().y + ball.getRadius() > 600.0f) ballSpeed.y = -ballSpeed.y;
		if (ball.getPosition().y - ball.getRadius() < 0.0f) ballSpeed.y = -ballSpeed.y;

		if (ball.getPosition().x > 800.0f)
		{
			scoreA++;
			isServing = true;
		}
		if (ball.getPosition().x < 0.0f)
		{
			scoreB++;
			isServing = true;
		}

		if (paddleLeft.getGlobalBounds().intersects(ball.getGlobalBounds())) ballSpeed.x = -ballSpeed.x;
		if (paddleRight.getGlobalBounds().intersects(ball.getGlobalBounds())) ballSpeed.x = -ballSpeed.x;
		
		ball.move(ballSpeed);

		score.setString(std::to_string(scoreA) + "\t" + std::to_string(scoreB));
		score.setOrigin(score.getGlobalBounds().width / 2.0f, score.getGlobalBounds().height / 2.0f);
		score.setPosition(400.0f, 20.0f);

		window.clear();
		window.draw(midLine);
		window.draw(paddleLeft);
		window.draw(paddleRight);
		window.draw(ball);
		window.draw(score);
		window.display();
	}
	return 0;
}
