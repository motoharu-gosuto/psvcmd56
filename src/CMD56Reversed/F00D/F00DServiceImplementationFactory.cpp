#include "F00DServiceImplementationFactory.h"

#include "KprxAuthService.h"
#include "ActService.h"
#include "AiMgrService.h"
#include "CompatService.h"
#include "EncDecWPortabilityService.h"
#include "GcAuthMgrService.h"
#include "PmService.h"
#include "QafService.h"
#include "RmAuthService.h"
#include "SpkgVerifierService.h"
#include "UpdateService.h"
#include "UTokenService.h"
#include "MgkmService.h"

using namespace f00d;

std::shared_ptr<IF00DService> F00DServiceImplementationFactory::create(std::string name)
{
   if(name == KPRX_AUTH_SERVICE)
   {
      return std::make_shared<KprxAuthService>(name);
   }
   else if(name == ACT_SERVICE)
   {
      return std::make_shared<ActService>(name);
   }
   else if(name == AIMGR_SERVICE)
   {
      return std::make_shared<AiMgrService>(name);
   }
   else if(name == COMPAT_SERVICE)
   {
      return std::make_shared<CompatService>(name);
   }
   else if(name == ENCDEC_W_PORTABILITY_SERVICE)
   {
      return std::make_shared<EncDecWPortabilityService>(name);
   }
   else if(name == GCAUTHMGR_SERVICE)
   {
      return std::make_shared<GcAuthMgrService>(name);
   }
   else if(name == PM_SERVICE)
   {
      return std::make_shared<PmService>(name);
   }
   else if(name == QAF_SERVICE)
   {
      return std::make_shared<QafService>(name);
   }
   else if(name == RMAUTH_SERVICE)
   {
      return std::make_shared<RmAuthService>(name);
   }
   else if(name == SPKG_VERIFIER_SERVICE)
   {
      return std::make_shared<SpkgVerifierService>(name);
   }
   else if(name == UPDATE_SERVICE)
   {
      return std::make_shared<UpdateService>(name);
   }
   else if(name == UTOKEN_SERVICE)
   {
      return std::make_shared<UTokenService>(name);
   }
   else if(name == MGKM_SERVICE)
   {
      return std::make_shared<MgkmService>(name);
   }
   else
   {
      throw std::runtime_error("unexpected F00D service name value");
   }
}