#pragma once

#include "murl_app_types.h"
#include "murl_logic_base_processor.h"

namespace Murl {
namespace App {
class RootController : public Logic::BaseProcessor {
public:
  RootController(Logic::IFactory *factory);
  virtual ~RootController();

protected:
  virtual Bool OnInit(const Logic::IState *state);
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
} // namespace App
} // namespace Murl
