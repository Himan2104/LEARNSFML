#include "pch.h"
#include "MainApplication.hpp"
#include"MainMenu.hpp"
#include"Game.hpp"

MainApplication::MainApplication()
{
	window.create(Vmode, "Pomg");
	window.setFramerateLimit(60);

	dt = 0;

	gameState = new MainMenu();
	gameState->init();
}

MainApplication::~MainApplication()
{
}

void MainApplication::run()
{
	while (window.isOpen())
	{
		dt = clk.restart().asSeconds();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
		}

		gameState->update(dt, sf::Vector2f(sf::Mouse::getPosition(window)));

		window.clear();
		gameState->render(window);
		window.display();
	}
}
