#include "SplashScreen.hpp"

SplashScreen::SplashScreen()
{
	init();
}

SplashScreen::~SplashScreen()
{
}

void SplashScreen::init()
{
	txr.loadFromFile("goat.png");
	sp.setTexture(txr);
	clk.restart().asSeconds();
	alpha = 0;
}

void SplashScreen::update(float dt, sf::Vector2f mpos, int& StateID)
{
	if (alpha >= 255) StateID = 1;

	if (clk.getElapsedTime().asSeconds() > 0.005f)
	{
		alpha++;
		sp.setColor(sf::Color(255, 0, 255, alpha));
		clk.restart().asSeconds();
	}
}

void SplashScreen::render(sf::RenderTarget& target)
{
	target.draw(sp);
}
