#include "MainApplication.hpp"
#include"MainMenu.hpp"
#include"Game.hpp"

MainApplication::MainApplication()
{
	window.create(Vmode, "Pomg");
	window.setFramerateLimit(frameRate);

	dt = 0;
	StateID = 0;
	prevState = 0;
	changeState();
}

MainApplication::~MainApplication()
{
}

void MainApplication::run()
{
	while (window.isOpen())
	{
		if (prevState != StateID) changeState();
		prevState = StateID;

		dt = clk.restart().asSeconds();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
		}

		cState->update(dt, sf::Vector2f(sf::Mouse::getPosition(window)), StateID);

		window.clear();
		cState->render(window);
		window.display();
	}
}

void MainApplication::closeApplication()
{
	window.close();
}

void MainApplication::changeState()
{
	switch (StateID)
	{
	case -1: window.close();
		break;
	case 0: cState = &spl;
		break;
	case 1: cState = &mainmenu;
		break;
	case 2: cState = &game;
		break;
	default:
		break;
	}
}
