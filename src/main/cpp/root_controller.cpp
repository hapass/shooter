#include "root_controller.h"

using namespace Murl;

App::RootController::RootController(Logic::IFactory *factory)
    : BaseProcessor(factory) {}

App::RootController::~RootController() {}

Bool App::RootController::OnInit(const Logic::IState *state) {
  auto root = state->GetGraphRoot();
  AddGraphNode(cameraTransform.GetReference(root, "camera_transform"));

  if (!AreGraphNodesValid()) {
    return false;
  }
  return true;
}

void App::RootController::OnProcessTick(const Logic::IState *state) {
  auto deviceHandler = state->GetDeviceHandler();

  auto position = cameraTransform->GetPosition();

  if (deviceHandler->IsRawKeyPressed(RawKeyCode::RAWKEY_D)) {
    cameraTransform->SetPosition(position.Add(Vector(10, 0, 0, 0)));
  }

  if (deviceHandler->IsRawKeyPressed(RawKeyCode::RAWKEY_A)) {
    cameraTransform->SetPosition(position.Add(Vector(-10, 0, 0, 0)));
  }

  if (deviceHandler->IsRawKeyPressed(RawKeyCode::RAWKEY_W)) {
    cameraTransform->SetPosition(position.Add(Vector(0, 0, -10, 0)));
  }

  if (deviceHandler->IsRawKeyPressed(RawKeyCode::RAWKEY_S)) {
    cameraTransform->SetPosition(position.Add(Vector(0, 0, 10, 0)));
  }

  if (deviceHandler->WasMouseMoved()) {
    Logic::Real x = 0;
    Logic::Real y = 0;
    deviceHandler->GetRawMouseDelta(x, y);

    Logic::Real yRadians = (y / 10) * (Math::PI * 2 / 360);
    Logic::Real xRadians = (x / 10) * (Math::PI * 2 / 360);

    Logic::Real currentRotationAroundX = cameraTransform->GetRotationX();
    Logic::Real currentRotationAroundY = cameraTransform->GetRotationY();

    Logic::Real totalRotationAroundX = 0;
    if(currentRotationAroundX + yRadians < Math::PI * 2 && 
       currentRotationAroundX + yRadians > -Math::PI * 2) {
      totalRotationAroundX = yRadians + currentRotationAroundX;
    }

    cameraTransform->SetRotation(totalRotationAroundX, -xRadians + currentRotationAroundY, 0);
  }
}
