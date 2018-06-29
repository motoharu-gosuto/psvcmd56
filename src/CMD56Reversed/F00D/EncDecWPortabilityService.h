#pragma once

#include <memory>

#include "IF00DService.h"

namespace f00d
{
   class EncDecWPortabilityService : public IF00DService
   {
   public:
      EncDecWPortabilityService(std::string service_name)
         : IF00DService(service_name)
      {
      }

      virtual ~EncDecWPortabilityService(){}

   public:
      int dispatch(int service_id, int* f00d_resp, void* ctx, int size) const override;
   };
}