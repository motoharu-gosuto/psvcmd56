#pragma once

#include "IF00DService.h"

namespace f00d
{
   class UpdateService : public IF00DService
   {
   public:
      UpdateService(std::string service_name)
         : IF00DService(service_name)
      {
      }

      virtual ~UpdateService(){}

   public:
      int dispatch(int service_id, int* f00d_resp, void* ctx, int size) const override;

   private:
      int service_10002(int* f00d_resp, void* ctx, int size) const;

      int service_20002(int* f00d_resp, void* ctx, int size) const;

      int service_30002(int* f00d_resp, void* ctx, int size) const;

      int service_40002(int* f00d_resp, void* ctx, int size) const;

      int service_50002(int* f00d_resp, void* ctx, int size) const;

      int service_60002(int* f00d_resp, void* ctx, int size) const;

      int service_70002(int* f00d_resp, void* ctx, int size) const;

      int service_80002(int* f00d_resp, void* ctx, int size) const;

      int service_90002(int* f00d_resp, void* ctx, int size) const;

      int service_A0002(int* f00d_resp, void* ctx, int size) const;

      int service_B0002(int* f00d_resp, void* ctx, int size) const;

      int service_C0002(int* f00d_resp, void* ctx, int size) const;

      int service_D0002(int* f00d_resp, void* ctx, int size) const;
   };
}
