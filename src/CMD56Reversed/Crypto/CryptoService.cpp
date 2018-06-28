#include "CryptoService.h"

#include "CryptoOperationsFactory.h"

static std::shared_ptr<ICryptoOperations> g_cryptops = CryptoOperationsFactory::create(CryptoOperationsTypes::libtomcrypt);

std::shared_ptr<ICryptoOperations> CryptoService::get()
{
   return g_cryptops;
}