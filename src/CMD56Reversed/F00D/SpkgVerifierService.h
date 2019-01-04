#pragma once

#include "IF00DService.h"

namespace f00d
{
   class SpkgVerifierService : public IF00DService
   {
   public:
      SpkgVerifierService(std::string service_name)
         : IF00DService(service_name)
      {
      }

      virtual ~SpkgVerifierService(){}

   public:
      int dispatch(int service_id, int* f00d_resp, void* ctx, int size) const override;

   private:
      int service_0xE0002(int* f00d_resp, void* ctx, int size) const;
   };
}