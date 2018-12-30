// Copyright 2012 Spraylight

#include "hello_world_app.h"
#include "hello_world_logic.h"

using namespace Murl;

App::HelloWorldApp::HelloWorldApp()
: mLogic(0)
{
}

App::HelloWorldApp::~HelloWorldApp()
{
}

Bool App::HelloWorldApp::Configure(IEngineConfiguration* engineConfig, IFileInterface* fileInterface)
{
    IAppConfiguration* appConfig = engineConfig->GetAppConfiguration(); 

    appConfig->SetWindowTitle("Hello World powered by Murl Engine");
    appConfig->SetFullScreenEnabled(false);
    
    return true;
}

Bool App::HelloWorldApp::Init(const IAppState* appState)
{
    mLogic = new HelloWorldLogic(appState->GetLogicFactory());
    ILoader* loader = appState->GetLoader();
    loader->AddPackage("debug", ILoader::LOAD_MODE_STARTUP, mLogic->GetProcessor());
    return true;
}

Bool App::HelloWorldApp::DeInit(const IAppState* appState)
{
    Util::Release(mLogic);
    return true;
}
