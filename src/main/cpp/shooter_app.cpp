#include "shooter_app.h"
#include "root_controller.h"

using namespace Murl;

App::ShooterApp::ShooterApp() : controller(0) {}

App::ShooterApp::~ShooterApp() {}

Bool App::ShooterApp::Configure(IEngineConfiguration *engineConfig,
                                IFileInterface *fileInterface) {
  IAppConfiguration *appConfig = engineConfig->GetAppConfiguration();

  appConfig->SetWindowTitle("Shooter");
  appConfig->SetFullScreenEnabled(false);

  return true;
}

Bool App::ShooterApp::Init(const IAppState *appState) {
  controller = new RootController(appState->GetLogicFactory());
  appState->GetLoader()->AddPackage("debug", ILoader::LOAD_MODE_STARTUP,
                                    controller->GetProcessor());
  return true;
}

Bool App::ShooterApp::DeInit(const IAppState *appState) {
  Util::Release(controller);
  return true;
}
