#pragma once
#include"defs.hpp"
#include"State.hpp"

class SplashScreen : public State
{
public:
	SplashScreen();
	~SplashScreen();

	void init() override;
	void update(float dt, sf::Vector2f mpos, int& StateID) override;
	void render(sf::RenderTarget& target) override;

private:
	sf::Texture txr;
	sf::Sprite sp;
	uint8_t alpha;
	sf::Clock clk;
};

