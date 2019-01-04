#pragma once

#include "IF00DService.h"

namespace f00d
{
   class QafService : public IF00DService
   {
   public:
      QafService(std::string service_name)
         : IF00DService(service_name)
      {
      }

      virtual ~QafService(){}

   public:
      int dispatch(int service_id, int* f00d_resp, void* ctx, int size) const override;

   private:
      int service_0x1(int* f00d_resp, void* ctx, int size) const;

      int service_0x2(int* f00d_resp, void* ctx, int size) const;

      int service_0xC(int* f00d_resp, void* ctx, int size) const;

      int service_0xD(int* f00d_resp, void* ctx, int size) const;
   };
}