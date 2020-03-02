#include "main_scene.h"
#include "game_scene.h"

using namespace Murl;

Bool App::MainScene::OnInit(const Logic::IState *state) {
  scene = new GameScene();
  state->GetLoader()->AddPackage("game.murlres", ILoader::LOAD_MODE_ON_DEMAND, scene->GetProcessor());
  return true;
}

void App::MainScene::OnProcessTick(const Logic::IState *state) {
  IPackage *gamePackage = state->GetLoader()->GetPackage("game.murlres");
  if (gamePackage->IsBusy()) {
    return;
  }

  auto deviceHandler = state->GetDeviceHandler();

  if (deviceHandler->IsRawKeyboardAvailable()) {
    if (deviceHandler->IsRawKeyPressed(RawKeyCode::RAWKEY_LEFT_CONTROL) &&
        deviceHandler->IsRawKeyPressed(RawKeyCode::RAWKEY_R)) {
      if (gamePackage->IsLoaded()) {
        gamePackage->Unload();
      }
    }
  }

  if (gamePackage->IsUnloaded()) {
    gamePackage->Load();
  }
}