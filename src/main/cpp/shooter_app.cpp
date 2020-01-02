#include "murl_app.h"
#include "shooter_app.h"
#include "scene_manager.h"

using namespace Murl;

IApp *App::CreateApp() 
{ 
  return new ShooterApp();
}

void App::DestroyApp(IApp *app) 
{
  Util::Release(app);
}

App::ShooterApp::ShooterApp() : controller(nullptr) {}

App::ShooterApp::~ShooterApp() {}

Bool App::ShooterApp::Configure(IEngineConfiguration *engineConfig,
                                IFileInterface *fileInterface) {
  IAppConfiguration *appConfig = engineConfig->GetAppConfiguration();

  appConfig->SetWindowTitle("Shooter");
  appConfig->SetFullScreenEnabled(false);
  appConfig->SetMouseCursorHidden(false);
  appConfig->SetDisplaySurfaceSize(1280, 960);
  appConfig->SetSystemDebugInfoItems(IEnums::STATISTIC_ITEM_FRAMES_PER_SECOND);

  return true;
}

Bool App::ShooterApp::Init(const IAppState *appState) {
  appState->GetLoader()->AddPackage("debug", ILoader::LOAD_MODE_STARTUP);
  
  controller = new SceneManager(appState->GetLogicFactory());
  appState->GetLoader()->AddProcessor(controller->GetProcessor());
  return true;
}

Bool App::ShooterApp::DeInit(const IAppState *appState) {
  appState->GetLoader()->RemoveProcessor(controller->GetProcessor());
  Util::Release(controller);
  return true;
}
