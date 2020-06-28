#pragma once
#include<SFML/Graphics.hpp>
#include"defs.hpp"
#include"Ball.hpp"
#include"Paddle.hpp"

class Game
{
public:
	Game();
	~Game();

	void run();

private:
	sf::RenderWindow window;

	sf::RectangleShape midLine;

	Ball ball;

	Paddle left, right;

	unsigned int scoreA, scoreB;

	float dt;

	sf::Vector2f ballSpeed;

	sf::Clock clk;

	sf::Font font;
	sf::Text score;

	bool isServing;
};

