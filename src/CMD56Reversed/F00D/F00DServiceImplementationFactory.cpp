#include "F00DServiceImplementationFactory.h"

#include "GcAuthMgrService.h"
#include "RmAuthService.h"
#include "EncDecWPortabilityService.h"
#include "KprxAuthService.h"

using namespace f00d;

std::shared_ptr<IF00DService> F00DServiceImplementationFactory::create(std::string name)
{
   if(name == GC_AUTH_MGR_SERVICE)
   {
      return std::make_shared<GcAuthMgrService>(name);
   }
   else if(name == RM_AUTH_SM_SERVICE)
   {
      return std::make_shared<RmAuthService>(name);
   }
   else if(name == ENCDEC_W_PORTABILITY_SERVICE)
   {
      return std::make_shared<EncDecWPortabilityService>(name);
   }
   else if(name == KPRX_AUTH_SERVICE)
   {
      return std::make_shared<KprxAuthService>(name);
   }
   else
   {
      throw std::runtime_error("unexpected F00D service name value");
   }
}