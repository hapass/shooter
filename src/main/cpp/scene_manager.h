#pragma once

#include "murl_app_types.h"
#include "murl_logic_base_processor.h"

namespace Murl {
namespace App {

/**
 * This class manages scenes and packages in the game. OnInit and ctor are executed on wrong thread, so 
 **/
class SceneManager : public Logic::BaseProcessor {
public:
  using Logic::BaseProcessor::BaseProcessor;

protected:
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
