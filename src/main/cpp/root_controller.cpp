#include "root_controller.h"

using namespace Murl;

App::RootController::RootController(Logic::IFactory *factory)
    : BaseProcessor(factory) {}

App::RootController::~RootController() {}

Bool App::RootController::OnInit(const Logic::IState *state) {
  if (!AreGraphNodesValid()) {
    return false;
  }
  return true;
}
