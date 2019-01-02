#include "root_controller.h"

using namespace Murl;

App::RootController::RootController(Logic::IFactory *factory)
    : BaseProcessor(factory) {
      this->cameraXAxis = Vector(1, 0, 0, 0);
      this->cameraYAxis = Vector(0, 1, 0, 0);
      this->cameraZAxis = Vector(0, 0, 1, 0);
      this->cameraPosition = Vector(0, 0, 800, 1);
    }

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

  if (deviceHandler->IsRawKeyPressed(RawKeyCode::RAWKEY_D)) {
    cameraPosition = cameraPosition.Add(cameraXAxis * 10);
  }

  if (deviceHandler->IsRawKeyPressed(RawKeyCode::RAWKEY_A)) {
    cameraPosition = cameraPosition.Subtract(cameraXAxis * 10);
  }

  if (deviceHandler->IsRawKeyPressed(RawKeyCode::RAWKEY_W)) {
    cameraPosition = cameraPosition.Subtract(cameraZAxis * 10);
  }

  if (deviceHandler->IsRawKeyPressed(RawKeyCode::RAWKEY_S)) {
    cameraPosition = cameraPosition.Add(cameraZAxis * 10);
  }

  cameraTransform->SetPosition(cameraPosition);

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

    Matrix matrix;
    matrix.SetRotationComponent(-xRadians, cameraYAxis);
    cameraXAxis = matrix.Rotate(cameraXAxis);
    cameraZAxis = matrix.Rotate(cameraZAxis);

    cameraTransform->SetRotation(totalRotationAroundX, currentRotationAroundY - xRadians, 0);
  }
}
