#pragma once

#include <memory>

#include "IF00DService.h"

namespace f00d
{
   class KprxAuthService : public IF00DService
   {
   public:
      KprxAuthService(std::string service_name)
         : IF00DService(service_name)
      {
      }

      virtual ~KprxAuthService(){}

   private:
      int service_0x50001(int* f00d_resp, void* ctx, int size) const;

      int service_0x60001(int* f00d_resp, void* ctx, int size) const;

   public:
      int dispatch(int service_id, int* f00d_resp, void* ctx, int size) const override;
   };
}