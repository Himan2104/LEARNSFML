#pragma once
#include<stack>
#include<memory>
#include"defs.hpp"
#include"State.hpp"


typedef std::unique_ptr<State> Ustate;

class StateMachine
{
public:
	StateMachine();
	~StateMachine();

	Ustate currentState();

private:
	std::stack<Ustate> states;
};

