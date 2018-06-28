#pragma once

#include "IF00DService.h"

#include <memory>
#include <string>

namespace f00d
{
   class F00DServiceImplementationFactory
   {
   public:
      static std::shared_ptr<IF00DService> create(std::string name);
   };
}