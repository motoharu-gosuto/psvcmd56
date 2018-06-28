#include "F00DServiceImplementationFactory.h"

#include "GcAuthMgrService.h"
#include "RmAuthService.h"

using namespace f00d;

std::shared_ptr<IF00DService> F00DServiceImplementationFactory::create(std::string name)
{
   if(name == GC_AUTH_MGR)
   {
      return std::make_shared<GcAuthMgrService>(name);
   }
   else if(name == RM_AUTH_SM)
   {
      return std::make_shared<RmAuthService>(name);
   }
   else
   {
      throw std::runtime_error("unexpected F00D service name value");
   }
}