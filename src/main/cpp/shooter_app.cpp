#include "shooter_app.h"
#include "main_scene.h"
#include "murl_app.h"

using namespace Murl;

IApp *App::CreateApp() { return new ShooterApp(); }

void App::DestroyApp(IApp *app) { Util::Release(app); }

App::ShooterApp::ShooterApp() : scene(nullptr) {}

App::ShooterApp::~ShooterApp() {}

Bool App::ShooterApp::Configure(IEngineConfiguration *engineConfig,
                                IFileInterface *fileInterface) {
  auto appConfig = engineConfig->GetAppConfiguration();

  appConfig->SetWindowTitle("Shooter");
  appConfig->SetFullScreenEnabled(false);
  appConfig->SetMouseCursorHidden(false);
  appConfig->SetDisplaySurfaceSize(1280, 960);
  appConfig->SetSystemDebugInfoItems(IEnums::STATISTIC_ITEM_FRAMES_PER_SECOND);

  return true;
}

Bool App::ShooterApp::Init(const IAppState *appState) {
  scene = new MainScene(appState->GetLogicFactory());
  appState->GetLoader()->AddPackage("debug", ILoader::LOAD_MODE_STARTUP);
  appState->GetLoader()->AddPackage("main.murlres", ILoader::LOAD_MODE_STARTUP,
                                    scene->GetProcessor());
  return true;
}

Bool App::ShooterApp::DeInit(const IAppState *appState) {
  Util::Release(scene);
  return true;
}
