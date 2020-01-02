#pragma once

#include "murl_app_base.h"

namespace Murl {
namespace App {

class SceneManager;

/**
 * Bootstrapper for the game. Operations in this class happen on main thread.
 **/
class ShooterApp : public AppBase {
public:
  ShooterApp();
  virtual ~ShooterApp();

  virtual Bool Configure(IEngineConfiguration *engineConfig,
                         IFileInterface *fileInterface);
  virtual Bool Init(const IAppState *appState);
  virtual Bool DeInit(const IAppState *appState);

private:
  SceneManager *controller;
};

}
}