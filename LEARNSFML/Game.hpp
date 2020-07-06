#pragma once
#include<SFML/Graphics.hpp>
#include"defs.hpp"
#include"Ball.hpp"
#include"Paddle.hpp"
#include"State.hpp"

class Game : public State
{
public:
	Game();
	~Game();

	void init() override;
	void update(float dt, sf::Vector2f mpos, int& StateID) override;
	void render(sf::RenderTarget& target) override;
	

private:
	sf::RectangleShape midLine;

	Ball ball;

	Paddle left, right;

	unsigned int scoreA, scoreB;

	sf::Vector2f ballSpeed;

	sf::Font font;
	sf::Text score;

	bool isServing;
};

