#pragma once

#include <memory>

#include "ICryptoOperations.h"

class CryptoService
{

public:
   static std::shared_ptr<ICryptoOperations> get();
};