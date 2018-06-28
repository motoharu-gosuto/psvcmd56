#pragma once

#include <memory>

#include "IF00DKeyEncryptor.h"

namespace f00d
{
   class F00DKeyEncryptorService
   {

   public:
      static std::shared_ptr<IF00DKeyEncryptor> get();
   };
}