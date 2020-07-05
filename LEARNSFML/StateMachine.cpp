#include "pch.h"
#include "StateMachine.hpp"

StateMachine::StateMachine()
{
}

StateMachine::~StateMachine()
{
}

Ustate StateMachine::currentState()
{
    return states.top();
}
