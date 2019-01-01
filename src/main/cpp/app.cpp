#include "murl_app.h"
#include "shooter_app.h"

using namespace Murl;

IApp *App::CreateApp() { return new ShooterApp; }

void App::DestroyApp(IApp *app) { Util::Release(app); }
