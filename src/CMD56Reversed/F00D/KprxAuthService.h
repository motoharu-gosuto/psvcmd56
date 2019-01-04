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

   public:
      int dispatch(int service_id, int* f00d_resp, void* ctx, int size) const override;

   private:
      int service_0x10001(int* f00d_resp, void* ctx, int size) const;

      int service_0x20001(int* f00d_resp, void* ctx, int size) const;

      int service_0x30001(int* f00d_resp, void* ctx, int size) const;

      int service_0x40001(int* f00d_resp, void* ctx, int size) const;

      int service_0x50001(int* f00d_resp, void* ctx, int size) const;

      int service_0x60001(int* f00d_resp, void* ctx, int size) const;

      int service_0x70001(int* f00d_resp, void* ctx, int size) const;

      int service_0x80001(int* f00d_resp, void* ctx, int size) const;
   };
}