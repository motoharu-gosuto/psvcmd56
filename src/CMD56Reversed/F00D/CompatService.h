#pragma once

#include "IF00DService.h"

namespace f00d
{
   class CompatService : public IF00DService
   {
   public:
      CompatService(std::string service_name)
         : IF00DService(service_name)
      {
      }

      virtual ~CompatService(){}

   public:
      int dispatch(int service_id, int* f00d_resp, void* ctx, int size) const override;

   private:
      int service_0x10006(int* f00d_resp, void* ctx, int size) const;

      int service_0x20006(int* f00d_resp, void* ctx, int size) const;
   };
}
