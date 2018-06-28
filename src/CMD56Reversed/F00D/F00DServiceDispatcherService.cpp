#include "F00DServiceDispatcherService.h"

using namespace f00d;

static std::shared_ptr<F00DServiceDispatcher> g_dispatcher = std::make_shared<F00DServiceDispatcher>(); 

std::shared_ptr<F00DServiceDispatcher> F00DServiceDispatcherService::get()
{
   return g_dispatcher;
}