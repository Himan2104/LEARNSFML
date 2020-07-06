#include "Game.hpp"

Game::Game() : ball(ballSpeed), 
left(default_paddle_size, std::make_pair(sf::Keyboard::W, sf::Keyboard::S), {10.0f, 300.0f}),
right(default_paddle_size, std::make_pair(sf::Keyboard::Up, sf::Keyboard::Down), {790.0f, 300.0f}),
midLine({2.0f, 600.0f})
{

	midLine.setPosition(400.0f, 0.0f);

	ballSpeed = sf::Vector2f(100.0f, 100.0f);

	isServing = true;
	
	ball.setPos({400.0f, 300.0f});

	scoreA = 0;
	scoreB = 0;

	switchFrame = true;

	font.loadFromFile("C:/Windows/Fonts/arial.ttf");
	score.setFont(font);
	score.setCharacterSize(30);

	midLine.setFillColor(color);
	score.setFillColor(color);
}

Game::~Game()
{
}

void Game::init()
{
}

void Game::update(float dt, sf::Vector2f mpos, int& StateID)
{
	if (isServing)
	{
		ball.setPos({ 400.0f, 300.0f });
		isServing = false;
		aniClk.restart().asSeconds();
	}

	if (aniClk.getElapsedTime().asSeconds() > 0.5f)
	{
		switchFrame = true;
		aniClk.restart().asSeconds();
	}
	else switchFrame = false;

	left.Update(dt, switchFrame);
	right.Update(dt, switchFrame);

	if (left.getGB().intersects(ball.getGB()))
	{
		ballSpeed.x = -ballSpeed.x;
		impact = true;
		bclk.restart().asSeconds();
	}
	else if (right.getGB().intersects(ball.getGB()))
	{
		ballSpeed.x = -ballSpeed.x;
		impact = true;
		bclk.restart().asSeconds();
	}

	else
	{
		if (bclk.getElapsedTime().asSeconds() > 1.0f) impact = false;
	}

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

	ball.Update(ballSpeed, dt, impact);


	score.setString(std::to_string(scoreA) + "\t" + std::to_string(scoreB));
	score.setOrigin(score.getGlobalBounds().width / 2.0f, score.getGlobalBounds().height / 2.0f);
	score.setPosition(400.0f, 20.0f);
}

void Game::render(sf::RenderTarget& target)
{
	ball.Render(target);
	left.Render(target);
	right.Render(target);
	target.draw(score);
	target.draw(midLine);
}
