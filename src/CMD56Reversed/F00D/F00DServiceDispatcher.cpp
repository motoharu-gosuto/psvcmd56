#include "F00DServiceDispatcher.h"

using namespace f00d;

F00DServiceDispatcher::F00DServiceDispatcher()
{
   m_current_id = 0;
}

int F00DServiceDispatcher::start(std::string service_name, int* id)
{  
   m_ids.insert(std::make_pair(m_current_id, service_name));
   m_current_id++;
   return 0;
}

int F00DServiceDispatcher::dispatch(int id, int service_id, int* f00d_resp, void* ctx, int size)
{
   auto it = m_ids.find(id);
   if(it == m_ids.end())
      return -1;

   std::string service_name = it->second;

   //call service by url here

   f00d_resp = 0;

   return 0;
}

int F00DServiceDispatcher::stop(int id)
{
   m_ids.erase(id);
   return 0;
}