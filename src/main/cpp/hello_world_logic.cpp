// Copyright 2012 Spraylight

#include "hello_world_logic.h"

using namespace Murl;

App::HelloWorldLogic::HelloWorldLogic(Logic::IFactory* factory)
: BaseProcessor(factory)
{
}

App::HelloWorldLogic::~HelloWorldLogic()
{
}

Bool App::HelloWorldLogic::OnInit(const Logic::IState* state)
{
    if (!AreGraphNodesValid())
    {
        return false;
    }
    Math::Clamp(10, 11,12);
    state->SetUserDebugMessage("Hello World");  
    return true;
}
