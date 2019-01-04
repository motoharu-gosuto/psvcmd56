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

   private:
      int service_0x1000B(int* f00d_resp, void* ctx, int size) const;

      int service_0x1000B_04(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const;

      int service_0x1000B_07(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const;

      int service_0x1000B_0C(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const;

      int service_0x1000B_0D(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const;

      int service_0x1000B_0E(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const;

      int service_0x1000B_10(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const;

      int service_0x1000B_11(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const;

      int service_0x1000B_12(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const;

      int service_0x1000B_14(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const;

      int service_0x1000B_15(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const;

      int service_0x1000B_16(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const;

      int service_0x1000B_17(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const;

      int service_0x1000B_18(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const;

      int service_0x1000B_19(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const;

      int service_0x1000B_1B(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const;

      int service_0x1000B_1C(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const;

      int service_0x1000B_1D(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const;

      int service_0x1000B_1E(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const;

      int service_0x1000B_1F(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const;

      int service_0x1000B_20(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const;

      int service_0x1000B_21(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const;

      int service_0x1000B_22(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const;

      int service_0x1000B_23(int* f00d_resp, SceSblSmCommGcAuthMgrData_1000B* ctx, int size) const;
   };
}

