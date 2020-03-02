#pragma once

#include "murl_app_base.h"

namespace Murl {
namespace App {

class GameScene;

class ShooterApp : public AppBase {
public:
  ShooterApp();
  virtual ~ShooterApp();

  virtual Bool Configure(IEngineConfiguration *engineConfig,
                         IFileInterface *fileInterface);
  virtual Bool Init(const IAppState *appState);
  virtual Bool DeInit(const IAppState *appState);

private:
  GameScene *controller;
};

}
}