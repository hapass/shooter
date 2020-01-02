#pragma once

#include "murl_app_types.h"
#include "murl_logic_base_processor.h"

namespace Murl {
namespace App {

class GameScene : public Logic::BaseProcessor {
public:
  using Logic::BaseProcessor::BaseProcessor;

protected:
  virtual Bool OnInit(const Logic::IState* state);
  virtual void OnProcessTick(const Logic::IState *state);

private:
  Real otherFieldOfView;
  Logic::TransformNode cameraTransform;
  Logic::CameraNode camera;
  Logic::Vector cameraXAxis;
  Logic::Vector cameraYAxis;
  Logic::Vector cameraZAxis;
  Logic::Vector cameraPosition;
};

}
}
