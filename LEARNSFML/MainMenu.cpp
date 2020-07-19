#include "MainMenu.hpp"

MainMenu::MainMenu()
{
	init();
}

MainMenu::~MainMenu()
{
}

void MainMenu::init()
{
	font.loadFromFile("C:/Windows/Fonts/arial.ttf");
	
	Heading.setCharacterSize(200);
	Heading.setFont(font);
	Heading.setFillColor(color);
	Heading.setString("[ P O M G ]");
	Heading.setOrigin(Heading.getGlobalBounds().width / 2.0f, Heading.getGlobalBounds().height / 2.0f);

	play.setCharacterSize(100);
	play.setFont(font);
	play.setFillColor(color);
	play.setString("PLAY");
	play.setOrigin(play.getGlobalBounds().width / 2.0f, play.getGlobalBounds().height / 2.0f);
	
	quit.setCharacterSize(100);
	quit.setFont(font);
	quit.setFillColor(color);
	quit.setString("EXIT");
	quit.setOrigin(quit.getGlobalBounds().width / 2.0f, quit.getGlobalBounds().height / 2.0f);

	Heading.setPosition(Vmode.width / 2.0f, 100.0f);
	play.setPosition(Vmode.width / 2.0f, 400.0f);
	quit.setPosition(Vmode.width / 2.0f, 550.0f);
}

void MainMenu::update(float dt, sf::Vector2f mpos, int& StateID)
{
	if (play.getGlobalBounds().contains(mpos))
	{
		play.setFillColor(sf::Color::Green);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			StateID = 2;
		}
	}
	else play.setFillColor(color);

	if (quit.getGlobalBounds().contains(mpos))
	{
		quit.setFillColor(sf::Color::Green);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			StateID = -1;
		}
	}
	else quit.setFillColor(color);
}

void MainMenu::render(sf::RenderTarget& target)
{
	target.draw(Heading);
	target.draw(play);
	target.draw(quit);
}
