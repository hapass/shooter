#pragma once

#include "murl_app_types.h"
#include "murl_logic_base_processor.h"

namespace Murl {
namespace App {

class GameScene;

class MainScene : public Logic::BaseProcessor {
public:
  using Logic::BaseProcessor::BaseProcessor;

protected:
  virtual Bool OnInit(const Logic::IState *state);
  virtual void OnProcessTick(const Logic::IState *state);

private:
  GameScene *scene;
};

} // namespace App
} // namespace Murl
