#include "F00DServiceDispatcher.h"
#include "F00DServiceImplementationFactory.h"

using namespace f00d;

F00DServiceDispatcher::F00DServiceDispatcher()
{
   m_current_id = 0;
}

int F00DServiceDispatcher::start(std::string service_name, int* id)
{  
   //allocate new id for corresponding service name
   m_ids.insert(std::make_pair(m_current_id, service_name));
   *id = m_current_id;
   m_current_id++;
   return 0;
}

int F00DServiceDispatcher::dispatch(int id, int service_id, int* f00d_resp, void* ctx, int size)
{
   //find allocated service name by id of operation
   auto it = m_ids.find(id);
   if(it == m_ids.end())
      return -1;

   //get service name
   std::string service_name = it->second;

   //try to find service instance in cache
   auto cached_service = m_service_cache.find(service_name);
   if(cached_service == m_service_cache.end())
   {
      //create instance of a service by name
      auto new_service = F00DServiceImplementationFactory::create(service_name);
      auto insert_it_pair = m_service_cache.insert(std::make_pair(service_name, new_service));
      cached_service = insert_it_pair.first;
   }

   //call specific service by service id
   if(cached_service->second->dispatch(service_id, f00d_resp, ctx, size) < 0)
      return -1;

   return 0;
}

int F00DServiceDispatcher::stop(int id)
{
   m_ids.erase(id);
   return 0;
}