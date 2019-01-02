#include "shooter_app.h"
#include "root_controller.h"

using namespace Murl;

App::ShooterApp::ShooterApp() : controller(0) {}

App::ShooterApp::~ShooterApp() {}

Bool App::ShooterApp::Configure(IEngineConfiguration *engineConfig,
                                IFileInterface *fileInterface) {
  IAppConfiguration *appConfig = engineConfig->GetAppConfiguration();

  appConfig->SetWindowTitle("Shooter");
  appConfig->SetFullScreenEnabled(true);
  appConfig->SetMouseCursorHidden(true);
  appConfig->SetSystemDebugInfoItems(IEnums::STATISTIC_ITEM_FRAMES_PER_SECOND);

  return true;
}

Bool App::ShooterApp::Init(const IAppState *appState) {
  auto loader = appState->GetLoader();
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
