#pragma once
#include"defs.hpp"
#include"State.hpp"

class MainApplication
{
public:
	MainApplication();
	~MainApplication();

	void run();

private:
	sf::RenderWindow window;

	float dt;

	State* gameState;


	sf::Clock clk;
};

