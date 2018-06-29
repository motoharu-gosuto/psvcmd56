#pragma once

#include "IF00DService.h"

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