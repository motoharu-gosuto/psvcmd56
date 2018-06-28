#pragma once

#include <string>
#include <unordered_map>

#define GC_AUTH_MGR "gcauthmgr_sm"
#define GC_AUTH_MGR_1000B 0x1000B

#define RM_AUTH_SM "rmauth_sm"
#define RM_AUTH_SM_1C 0x1C

namespace f00d
{
   class F00DServiceDispatcher
   {
   private:
      std::unordered_map<int, std::string> m_ids;
      int m_current_id;

   public:
      F00DServiceDispatcher();

   public:
      int start(std::string service_name, int* id);
      int dispatch(int id, int service_id, int* f00d_resp, void* ctx, int size);
      int stop(int id);
   };
}