#include <memory>

#include "Constants.h"

typedef void (exit_callback_t)(int);

struct atexit_ctx_t
{
  atexit_ctx_t *next;
  exit_callback_t* cookie_protected_exit_callback;
  int exit_argument;
  int dso_handle;
};

typedef void (quick_exit_callback_t)(int);

struct quick_exit_ctx_t
{
  quick_exit_ctx_t *next;
  quick_exit_callback_t* cookie_protected_exit_callback;
  int exit_argument;
  int dso_handle;
};

int* g_83B7CE94; //dso handle ptr

int g_83B7D920; // lockno counter ?

int g_83B7D950; //atexit item counter for preallocated items

int g_83B7D954; //atexit item counter for all items

atexit_ctx_t* g_83B7E8A0; //table of preallocated atexit items

atexit_ctx_t* g_83B7D94C; //linked list of allocated atexit items

int g_83B7D95C; //quick exit item counter for preallocated items

int g_83B7D960; //quick exit item counter for all items

quick_exit_ctx_t* g_83B7E6A0; //table of preallocated quick atexit items

quick_exit_ctx_t* g_83B7D958; //linked list of allocated quick atexit items

int* SceLibc__cxa_set_dso_handle_main_bfe02b3a(int* dso_handle_ptr)
{
  g_83B7CE94 = dso_handle_ptr;
  return dso_handle_ptr;
}

typedef struct	SceKernelLwMutexWork {
	SceInt64 data[4];
} SceKernelLwMutexWork;

//other functions

int SceLibKernel_sceKernelLockLwMutex_46e7be7b(SceKernelLwMutexWork *pWork, int lockCount, unsigned int *pTimeout)
{
   return 0;
}

int SceLibKernel_sceKernelUnlockLwMutex_91fa6614(SceKernelLwMutexWork *pWork, int unlockCount)
{
   return 0;
}

int SceProcessmgr_sceKernelCallAbortHandler_eb6e50bb(int, int)
{
   return 0;
}

int SceLibKernel_sceKernelCallModuleExit_15e2a45d(int)
{
   return 0;
}

void* SceLibKernel_sceKernelGetTLSAddr_b295eb61(int key)
{
   return 0;
}

//Libc functions

int w_sceKernelLockLwMutex_87094984(SceKernelLwMutexWork *pWork)
{
   if (!pWork)
    return 0x80010016;

   int result = SceLibKernel_sceKernelLockLwMutex_46e7be7b(pWork, 1, 0);
   if ( result >= 0 )
      return 0;
   else
      return result;
}

int w_sceKernelUnlockLwMutex_870949A2(SceKernelLwMutexWork *pWork)
{
   if (!pWork)
      return 0x80010016;

   int result = SceLibKernel_sceKernelUnlockLwMutex_91fa6614(pWork, 1);
   if (result >= 0)
      return 0;
   else
      return result;
}

int SceLibc__Locksyslock_7dbc0575(int lockno)
{
  int result = 0x80010016;

  if ((unsigned int)lockno < g_83B7D920 )
    result = w_sceKernelLockLwMutex_87094984((SceKernelLwMutexWork*)(sizeof(SceKernelLwMutexWork) * lockno - 0x7C481A60));
  return result;
}

int SceLibc__Unlocksyslock_64da2c47(int lockno)
{
  int result = 0x80010016;
  if (lockno < g_83B7D920)
    result = w_sceKernelUnlockLwMutex_870949A2((SceKernelLwMutexWork *)(sizeof(SceKernelLwMutexWork) * lockno - 0x7C481A60));
  return result;
}

int w_sceKernelGetTLSAddr_7_value_8708438E()
{
  return *(int*)SceLibKernel_sceKernelGetTLSAddr_b295eb61(7);
}

int SceLibc__cxa_atexit_33b83b70(exit_callback_t* exit_callback, int exit_argument, int *dso_handle_ptr)
{
   //lock

   SceLibc__Locksyslock_7dbc0575(3);

   atexit_ctx_t * exit_ctx = 0;

   // check if all items are used

   if (g_83B7D950 >= 0x40u)
   {
      exit_ctx = 0;
   }
   else
   {
      // try to find first unused item

      exit_ctx = g_83B7E8A0;

      int index = 0;
      while (exit_ctx->cookie_protected_exit_callback)
      {
         ++index;
         ++exit_ctx;

         if (index >= 0x40)
         {
            exit_ctx = 0;
            break;
         }
      }

      if(exit_ctx) //inc counter for preallocated items
         ++g_83B7D950;
   }

   //handle case where no preallocated items are available

   atexit_ctx_t* unused_exit_ctx = exit_ctx;

   if (!unused_exit_ctx) //if all items are used
   {
      //try to allocate new item

      unused_exit_ctx = (atexit_ctx_t *)malloc(sizeof(atexit_ctx_t));

      if(!unused_exit_ctx) //if failed to allocate new item
      {
         //unlock and exit

         SceLibc__Unlocksyslock_64da2c47(3);
         return 1;
      }
   }

   //link to previous item in linked list

   unused_exit_ctx->next = g_83B7D94C;

   //initialize new item

   //assign exit argument
   
   unused_exit_ctx->exit_argument = exit_argument;

   //assign cookie protected exit callback

   int tls_cookie = w_sceKernelGetTLSAddr_7_value_8708438E();
   unused_exit_ctx->cookie_protected_exit_callback = (exit_callback_t*)(tls_cookie ^ (int)exit_callback);

   //assign dso handle

   int* dso_handle_ptr_local = dso_handle_ptr;
   if (!dso_handle_ptr_local)
      dso_handle_ptr_local = g_83B7CE94;
   unused_exit_ctx->dso_handle = *dso_handle_ptr_local;

   //link this item in linked list

   g_83B7D94C = unused_exit_ctx;

   //inc counter for all items

   ++g_83B7D954;
   
   //unlock and exit

   SceLibc__Unlocksyslock_64da2c47(3);
   return 0;
}

int SceLibc__aeabi_atexit_edc939e1(int exit_argument, exit_callback_t* exit_callback, int *dso_handle_ptr)
{
  return SceLibc__cxa_atexit_33b83b70(exit_callback, exit_argument, dso_handle_ptr);
}

int SceLibc___at_quick_exit_ba2ef93e(quick_exit_callback_t* exit_callback, int exit_argument, int *dso_handle_ptr)
{
   //lock

   SceLibc__Locksyslock_7dbc0575(3);

   // check if all items are used

   quick_exit_ctx_t* quick_exit_item = 0;

   if (g_83B7D95C >= 0x20u)
   {
      quick_exit_item = 0;
   }
   else
   {
      quick_exit_item = (quick_exit_ctx_t *)g_83B7E6A0;

      int index = 0;
      while (quick_exit_item->cookie_protected_exit_callback)
      {
         ++index;
         ++quick_exit_item;

         if (index >= 0x20)
         {
            quick_exit_item = 0;
            break;
         }
      }

      if(quick_exit_item)
         ++g_83B7D95C;
   }

   //handle case where no preallocated items are available

   quick_exit_ctx_t* quick_exit_item_unused = quick_exit_item;

   if(!quick_exit_item_unused)
   {
      quick_exit_item_unused = (quick_exit_ctx_t*)malloc(sizeof(quick_exit_ctx_t));

      if(!quick_exit_item_unused)
      {
         SceLibc__Unlocksyslock_64da2c47(3);
         return 1;
      }
   }

   //link to previous item in linked list

   quick_exit_item_unused->next = g_83B7D958;

   //initialize new item

   //assign exit argument

   quick_exit_item_unused->exit_argument = exit_argument;

   //assign cookie protected exit callback

   int tls_cookie = w_sceKernelGetTLSAddr_7_value_8708438E();
   quick_exit_item_unused->cookie_protected_exit_callback = (quick_exit_callback_t*)(tls_cookie ^ (int)exit_callback);

   //assign dso handle
   int* dso_handle_ptr_local = dso_handle_ptr;
   if ( !dso_handle_ptr_local )
      dso_handle_ptr_local = g_83B7CE94;
   quick_exit_item_unused->dso_handle = *dso_handle_ptr_local;

   //link this item in linked list

   g_83B7D958 = quick_exit_item_unused;
   
   //inc counter for all items
   
   ++g_83B7D960;

   //unlock and exit

   SceLibc__Unlocksyslock_64da2c47(3);
   return 0;
}

int SceLibc___cxa_finalize_b538bf48(int* dso_handle_ptr)
{
   if (!dso_handle_ptr)
      return 0;

   if (g_83B7D94C)
   {
      #pragma region

      SceLibc__Locksyslock_7dbc0575(3);

      atexit_ctx_t * exit_item1 = g_83B7D94C;
      atexit_ctx_t * exit_item2 = g_83B7D94C;

      int exit_item_count1 = g_83B7D954;
      int exit_item_count2 = g_83B7D954;

      atexit_ctx_t * current_exit_item = 0;
      atexit_ctx_t* next_exit_item;

      do
      {
         next_exit_item = exit_item2->next;

         if (exit_item2->dso_handle == *dso_handle_ptr)
         {
            
            if (exit_item2 == exit_item1)
            {
               g_83B7D94C = exit_item2->next;
            }
            else
            {
               current_exit_item->next = next_exit_item;
            }

            exit_callback_t* cooked_callback = exit_item2->cookie_protected_exit_callback;
            int exit_argument = exit_item2->exit_argument;

            if ((unsigned int)exit_item2 > 0x83B7EC90 || (unsigned int)exit_item2 < 0x83B7E8A0)
            {
               free(exit_item2);
            }
            else
            {
               exit_item2->cookie_protected_exit_callback = 0;
               --g_83B7D950;
            }

            SceLibc__Unlocksyslock_64da2c47(3);

            int tls_cookie = w_sceKernelGetTLSAddr_7_value_8708438E();

            ((exit_callback_t*)((int)cooked_callback ^ tls_cookie))(exit_argument);

            SceLibc__Locksyslock_7dbc0575(3);
            exit_item_count1 = g_83B7D954;
            exit_item1 = g_83B7D94C;
         }
         else
         {
            current_exit_item = exit_item2;
         }

         if ( exit_item_count2 != exit_item_count1 )
         {
            next_exit_item = exit_item1;
            exit_item_count2 = exit_item_count1;
         }

         exit_item2 = next_exit_item;
      }
      while(next_exit_item);

      #pragma endregion
   }

   SceLibc__Unlocksyslock_64da2c47(3);

   //====================

   if (g_83B7D958)
   {
      SceLibc__Locksyslock_7dbc0575(3);

      quick_exit_ctx_t * quick_exit_item = g_83B7D958;
      quick_exit_ctx_t * next_quick_exit_item;
      quick_exit_ctx_t * current_quick_exit_item = 0;
      
      do
      {
         next_quick_exit_item = quick_exit_item->next;

         if ( quick_exit_item->dso_handle == *dso_handle_ptr )
         {
            if ( quick_exit_item == g_83B7D958)
            {
               g_83B7D958 = quick_exit_item->next;
            }
            else
            {
               current_quick_exit_item->next = next_quick_exit_item;
            }

            if ((unsigned int)quick_exit_item > 0x83B7E890 || (unsigned int)quick_exit_item < 0x83B7E6A0 )
            {
               free(quick_exit_item);
            }
            else
            {
               quick_exit_item->cookie_protected_exit_callback = 0;
               --g_83B7D95C;
            }
         }
         else
         {
            current_quick_exit_item = quick_exit_item;
         }
         
         quick_exit_item = next_quick_exit_item;
      }
      while (next_quick_exit_item);
   }

   SceLibc__Unlocksyslock_64da2c47(3);

   //====================
   
   return 0;
}

int SceLibc__Exit_b53b345b(int status)
{
   return 0;
}

int SceLibc_exit_826bbbaf(int status)
{
   int abort_handler_arg = 0x103;
   if ( status == 0 )
      abort_handler_arg = 0x102;

   SceProcessmgr_sceKernelCallAbortHandler_eb6e50bb(abort_handler_arg, 0);
   SceLibKernel_sceKernelCallModuleExit_15e2a45d(1);
   SceLibc___cxa_finalize_b538bf48(g_83B7CE94);
   return SceLibc__Exit_b53b345b(status);
}