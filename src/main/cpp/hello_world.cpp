// Copyright 2012 Spraylight

#include "murl_app.h"
#include "hello_world_app.h"

using namespace Murl;

IApp* App::CreateApp()
{
    return new HelloWorldApp;
}

void App::DestroyApp(IApp* app)
{
    Util::Release(app);
}
