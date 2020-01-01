#include "murl_app.h"
#include "shooter_app.h"
#include "root_controller.h"

using namespace Murl;

IApp *App::CreateApp() 
{ 
  return new ShooterApp();
}

void App::DestroyApp(IApp *app) 
{
  Util::Release(app);
}

App::ShooterApp::ShooterApp() : controller(nullptr) {} //main thread

App::ShooterApp::~ShooterApp() {}

Bool App::ShooterApp::Configure(IEngineConfiguration *engineConfig,
                                IFileInterface *fileInterface) {
  IAppConfiguration *appConfig = engineConfig->GetAppConfiguration(); //main thread

  appConfig->SetWindowTitle("Shooter");
  appConfig->SetFullScreenEnabled(false);
  appConfig->SetMouseCursorHidden(false);
  appConfig->SetDisplaySurfaceSize(1280, 960);
  appConfig->SetSystemDebugInfoItems(IEnums::STATISTIC_ITEM_FRAMES_PER_SECOND);

  return true;
}

Bool App::ShooterApp::Init(const IAppState *appState) {
  auto loader = appState->GetLoader(); //main thread
  loader->AddPackage("debug", ILoader::LOAD_MODE_STARTUP);

  controller = new RootController(appState->GetLogicFactory());

  auto processor = controller->GetProcessor();
  loader->AddPackage("root.murlres", ILoader::LOAD_MODE_BACKGROUND, processor);

  return true;
}

Bool App::ShooterApp::DeInit(const IAppState *appState) {
  Util::Release(controller);
  return true;
}
