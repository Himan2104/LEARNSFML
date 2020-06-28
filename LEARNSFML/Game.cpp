#include "pch.h"
#include "Game.hpp"

Game::Game() : ball(ballSpeed), 
left(default_paddle_size, std::make_pair(sf::Keyboard::W, sf::Keyboard::S), {10.0f, 300.0f}),
right(default_paddle_size, std::make_pair(sf::Keyboard::Up, sf::Keyboard::Down), {790.0f, 300.0f}),
midLine({2.0f, 600.0f})
{
	window.create(Vmode, "Pomg");
	window.setFramerateLimit(200);

	midLine.setPosition(400.0f, 0.0f);

	ballSpeed = sf::Vector2f(0.5f, 0.5f);

	isServing = true;
	
	ball.setPos({400.0f, 300.0f});

	dt = 0;

	scoreA = 0;
	scoreB = 0;

	font.loadFromFile("C:/Windows/Fonts/arial.ttf");
	score.setFont(font);
	score.setCharacterSize(30);

	midLine.setFillColor(color);
	score.setFillColor(color);
}

Game::~Game()
{
}

void Game::run()
{
	while (window.isOpen())
	{
		dt = clk.restart().asMilliseconds();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
		}

		if (isServing)
		{
			ball.setPos({ 400.0f, 300.0f });
			isServing = false;
		}

		left.Update(dt);
		right.Update(dt);

		if (left.getGB().intersects(ball.getGB())) ballSpeed.x = -ballSpeed.x;
		if (right.getGB().intersects(ball.getGB())) ballSpeed.x = -ballSpeed.x;

		if (ball.getPos().x < 0.0f)
		{
			scoreB++;
			isServing = true;
		}

		if (ball.getPos().x > 800.0f)
		{
			scoreA++;
			isServing = true;
		}

		ball.Update(ballSpeed, dt);
		

		score.setString(std::to_string(scoreA) + "\t" + std::to_string(scoreB));
		score.setOrigin(score.getGlobalBounds().width / 2.0f, score.getGlobalBounds().height / 2.0f);
		score.setPosition(400.0f, 20.0f);

		window.clear();
		ball.Render(window);
		left.Render(window);
		right.Render(window);
		window.draw(score);
		window.draw(midLine);
		window.display();
	}
}
