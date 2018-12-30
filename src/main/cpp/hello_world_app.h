// Copyright 2012 Spraylight

#ifndef __HELLO_WORLD_APP_H__
#define __HELLO_WORLD_APP_H__

#include "murl_app_base.h"

namespace Murl
{
    namespace App
    {
        class HelloWorldLogic;
        
        class HelloWorldApp :  public AppBase
        {
        public:
            HelloWorldApp();
            virtual ~HelloWorldApp();
            
            virtual Bool Configure(IEngineConfiguration* engineConfig, IFileInterface* fileInterface); 
            virtual Bool Init(const IAppState* appState);
            virtual Bool DeInit(const IAppState* appState);
                
        protected:
            HelloWorldLogic* mLogic;
        };
    }
}

#endif  // __HELLO_WORLD_APP_H__
