#include "F00DKeyEncryptorService.h"

#include "F00DKeyEncryptorFactory.h"

using namespace f00d;

static std::shared_ptr<IF00DKeyEncryptor> g_cryptops = F00DKeyEncryptorFactory::create(F00DEncryptorTypes::url, "http://cma.henkaku.xyz");

std::shared_ptr<IF00DKeyEncryptor> F00DKeyEncryptorService::get()
{
   return g_cryptops;
}