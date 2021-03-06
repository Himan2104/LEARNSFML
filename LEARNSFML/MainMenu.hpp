#pragma once
#include"defs.hpp"
#include"State.hpp"

class MainMenu : public State
{
public:
	MainMenu();
	~MainMenu();

	void init() override;
	void update(float dt, sf::Vector2f mpos, int& StateID) override;
	void render(sf::RenderTarget& target) override;

private:
	sf::Font font;
	sf::Text Heading;
	sf::Text play;
	sf::Text quit;
};

