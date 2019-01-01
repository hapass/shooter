#include "root_controller.h"

using namespace Murl;

App::RootController::RootController(Logic::IFactory *factory)
    : BaseProcessor(factory) {}

App::RootController::~RootController() {}

Bool App::RootController::OnInit(const Logic::IState *state) {
  if (!AreGraphNodesValid()) {
    return false;
  }

  Math::Clamp(10, 11, 12);

  state->SetUserDebugMessage("Hello World");
  return true;
}
