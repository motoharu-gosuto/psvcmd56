#pragma once

#include <string>
#include <memory>

#include <unordered_map>

#include "IF00DService.h"

namespace f00d
{
   class F00DServiceDispatcher
   {
   private:
      std::unordered_map<int, std::string> m_ids;
      int m_current_id;

   private:
      std::unordered_map<std::string, std::shared_ptr<IF00DService> > m_service_cache;

   public:
      F00DServiceDispatcher();

   public:
      int start(std::string service_name, int* id);
      int dispatch(int id, int service_id, int* f00d_resp, void* ctx, int size);
      int stop(int id);
   };
}