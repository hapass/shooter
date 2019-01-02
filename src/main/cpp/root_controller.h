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
  Logic::TransformNode cameraTransform;
};
} // namespace App
} // namespace Murl
