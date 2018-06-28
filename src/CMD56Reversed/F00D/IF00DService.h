#pragma once

#include <string>

namespace f00d
{
   class IF00DService
   {
   private:
      std::string m_service_name;

   public:
      IF00DService(std::string service_name)
         : m_service_name(service_name)
      {
      }

      virtual ~IF00DService()
      {
      }

   public:
      virtual int dispatch(int service_id, int* f00d_resp, void* ctx, int size) const = 0;
   };
}