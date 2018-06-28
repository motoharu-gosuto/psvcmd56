#pragma once

#include "IF00DService.h"

#define GC_AUTH_MGR "gcauthmgr_sm"
#define GC_AUTH_MGR_1000B 0x1000B

namespace f00d
{
   class GcAuthMgrService : public IF00DService
   {
   public:
      GcAuthMgrService(std::string service_name)
         : IF00DService(service_name)
      {
      }

      virtual ~GcAuthMgrService(){}

   public:
      int dispatch(int service_id, int* f00d_resp, void* ctx, int size) const override;
   };
}