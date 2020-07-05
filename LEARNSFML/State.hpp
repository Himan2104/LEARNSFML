#pragma once
#include"defs.hpp"

class State
{
public:
	virtual void init() = 0;
	virtual void update(float dt, sf::Vector2f mpos) = 0;
	virtual void render(sf::RenderTarget& target) = 0;
};
