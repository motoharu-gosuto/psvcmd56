#pragma once

#include <memory>

#include "F00DServiceDispatcher.h"

namespace f00d
{
   class F00DServiceDispatcherService
   {
   public:
      static std::shared_ptr<F00DServiceDispatcher> get();
   };
}