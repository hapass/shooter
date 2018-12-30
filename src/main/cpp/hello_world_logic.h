// Copyright 2012 Spraylight

#ifndef __HELLO_WORLD_LOGIC_H__
#define __HELLO_WORLD_LOGIC_H__

#include "murl_app_types.h"
#include "murl_logic_base_processor.h"

namespace Murl
{
    namespace App
    {
        class HelloWorldLogic : public Logic::BaseProcessor
        {
        public:
            HelloWorldLogic(Logic::IFactory* factory);
            virtual ~HelloWorldLogic();
            
        protected:
            virtual Bool OnInit(const Logic::IState* state);
        };
    }
}

#endif  // __HELLO_WORLD_LOGIC_H__
