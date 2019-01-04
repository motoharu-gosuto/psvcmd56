#pragma once

#include "IF00DService.h"

namespace f00d
{
   class ActService : public IF00DService
   {
   public:
      ActService(std::string service_name)
         : IF00DService(service_name)
      {
      }

      virtual ~ActService(){}

   public:
      int dispatch(int service_id, int* f00d_resp, void* ctx, int size) const override;

   private:
      int service_0x2(int* f00d_resp, void* ctx, int size) const;

      int service_0x4(int* f00d_resp, void* ctx, int size) const;

      int service_0x5(int* f00d_resp, void* ctx, int size) const;

      int service_0x7(int* f00d_resp, void* ctx, int size) const;

      int service_0xA(int* f00d_resp, void* ctx, int size) const;

      int service_0xB(int* f00d_resp, void* ctx, int size) const;
   };
}
