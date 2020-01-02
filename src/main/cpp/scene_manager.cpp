#include "scene_manager.h"
#include "game_scene.h"

using namespace Murl;

void App::SceneManager::OnProcessTick(const Logic::IState *state) {
  auto loader = state->GetLoader();
  switch (managerState)
  {
    case StateInit:
    {
      gameScene = new GameScene(state->GetFactory());
      scenePackages.Add(1, "root.murlres");

      currentScene = 1;
      managerState = StateLoading;
      return;
    }
    case StateLoading:
    {
      SInt32 sceneIndex = scenePackages.Find(currentScene);
      if (!scenePackages.IsIndexValid(sceneIndex))
      {
        return;
      }

      if (loader->GetPackage(scenePackages[sceneIndex]) == nullptr)
      {
        loader->AddPackage(scenePackages[sceneIndex], ILoader::LOAD_MODE_ON_DEMAND);
        return;
      }

      if (loader->GetPackage(scenePackages[sceneIndex])->IsBusy())
      {
        return;
      }

      if (loader->GetPackage(scenePackages[sceneIndex])->IsUnloaded())
      {
        loader->LoadPackage(scenePackages[sceneIndex]);
        return;
      }

      if (loader->GetPackage(scenePackages[sceneIndex])->IsLoaded())
      {
        SInt32 counterIndex = packageReferenceCounters.Find(scenePackages[sceneIndex]);
        if (scenePackages.IsIndexValid(counterIndex))
        {
          packageReferenceCounters[counterIndex]++;
        }
        else
        {
          packageReferenceCounters.Add(scenePackages[sceneIndex], 0);
        }

        InitAddChild(state, gameScene->GetProcessor());
        managerState = StateSceneInProgress;
        return;
      }
    }
    case StateSceneInProgress:
    {
      return;
    }
  }
}
