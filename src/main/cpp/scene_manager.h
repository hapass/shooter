#pragma once

#include "murl_app_types.h"
#include "murl_logic_base_processor.h"
#include "murl_map.h"

namespace Murl {
namespace App {

class GameScene;

/**
 * This class manages scenes and packages in the game. OnInit and ctor are executed on wrong thread, so 
 **/
class SceneManager : public Logic::BaseProcessor {
private:
  static const SInt32 StateInit = 0;
  static const SInt32 StateLoading = 1;
  static const SInt32 StateSceneInProgress = 2;

  static const SInt32 ScenePreloader = 0;
  static const SInt32 SceneMain = 1;

public:
  using Logic::BaseProcessor::BaseProcessor;

protected:
  virtual void OnProcessTick(const Logic::IState *state);

private:
  Map<SInt32, String> scenePackages;
  Map<String, SInt32> packageReferenceCounters;

  GameScene *gameScene = nullptr;

  SInt32 managerState = 0;
  SInt32 currentScene = 0;
};

}
}
