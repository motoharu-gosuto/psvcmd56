#pragma once

#include "IF00DService.h"

namespace f00d
{
   class RmAuthService : public IF00DService
   {
   public:
      RmAuthService(std::string service_name)
         : IF00DService(service_name)
      {
      }

      virtual ~RmAuthService(){}

   public:
      int dispatch(int service_id, int* f00d_resp, void* ctx, int size) const override;
   };
}