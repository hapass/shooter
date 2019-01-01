#pragma once

#include "murl_app_base.h"
#include "root_controller.h"

namespace Murl {
namespace App {
class ShooterApp : public AppBase {
public:
  ShooterApp();
  virtual ~ShooterApp();

  virtual Bool Configure(IEngineConfiguration *engineConfig,
                         IFileInterface *fileInterface);
  virtual Bool Init(const IAppState *appState);
  virtual Bool DeInit(const IAppState *appState);

protected:
  RootController *controller;
};
} // namespace App
} // namespace Murl