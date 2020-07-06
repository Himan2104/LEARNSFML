#pragma once
#include"defs.hpp"
#include"State.hpp"
#include"MainMenu.hpp"
#include"Game.hpp"
#include"SplashScreen.hpp"

class MainApplication
{
public:
	MainApplication();
	~MainApplication();

	void run();

	void closeApplication();

private:
	sf::RenderWindow window;
	sf::Clock clk;
	float dt;

	SplashScreen spl;
	Game game;
	MainMenu mainmenu;

	void changeState();
	State* cState;
	int StateID;
	int prevState;
	/*
	-1 : close;
	0  : SplashScreen;
	1  : MainMEnu;
	2  : GameState;
	*/
	
};

