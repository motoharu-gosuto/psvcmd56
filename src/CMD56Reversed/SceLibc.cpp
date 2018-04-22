#include <memory>

#include "Constants.h"
#include "SceThreadmgr.h"
#include "SceProcessmgr.h"
#include "SceLibKernel.h"

//=========================================================

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

struct create_mutex_local_ctx
{
  char *mutex_name;
};

struct ctx_83B7F3BC_holder
{
  int (__cdecl *unk0)();
};

struct module_start_local_ctx
{
  int (*some_callback)();
};

//=========================================================

//globals

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

SceKernelLwMutexWork g_83B7E5A0; // global array of mutex locks

create_mutex_local_ctx g_83B7D924; // global array of mutex names - HOW IS THIS INITIALIZED?

int* g_83B7F410;

int g_83B7F404; //stdin
int g_83B7F408; //stdout
int g_83B7F40C; //stderr

int g_83B7E54C;

int g_83B7D208;
int* g_83B7D20C;
int* g_83B7D1CC;
int* g_83B7D1D0;
int g_83B7D308;
int* g_83B7D30C;
int* g_83B7D2CC;
int* g_83B7D2D0;
int g_83B7D408;
int* g_83B7D40C;
int* g_83B7D3CC;
int* g_83B7D3D0;

int g_83B7D0A0;
int g_83B7CFA0;
int g_83B7CEA0;

SceKernelLwMutexWork g_83B7E568;

SceKernelLwMutexWork g_83B7D1E8; //SceLibcFileStdin mutex
SceKernelLwMutexWork g_83B7D2E8; //SceLibcFileStdout mutex
SceKernelLwMutexWork g_83B7D3E8; //SceLibcFileStderr mutex

SceKernelLwCondWork g_83B7E590; //SceLibcCxaguard cond
SceKernelLwMutexWork g_83B7E620; //SceLibcCxaguard mutex

int g_83B7F414;

int g_83B7D944; //related to some global init?

void(*g_83B7F650)(void*);
void * (*g_83B7F654)(int);
int (*g_83B7F658)(void);
int g_83B7F65C;
int(*g_83B7F660)();
int(*g_83B7F664)();
void* (*g_83B7F668)(int);
void(*g_83B7F66C)(void*);
int (*g_83B7F670)(int,int);
int (*g_83B7F674)(int,int);
int (*g_83B7F678)(int,int);
int (*g_83B7F67C)(int,int,int);
int (*g_83B7F680)(int);
int (*g_83B7F684)(int);
int (*g_83B7F688)(int);

void*(*g_83B7F0E4)(int);
void*(*g_83B7F0E8)(int);
void*(*g_83B7F0EC)(int);
void*(*g_83B7F0F0)(int, const nothrow_t *nothrow);
void*(*g_83B7F0F4)(void*);
int (*g_83B7F0F8)(void*);
int (*g_83B7F0FC)(void*);
int (*g_83B7F100)(void*, const nothrow_t *nothrow);

//=========================================================

//Libc functions

int* SceLibc__cxa_set_dso_handle_main_bfe02b3a(int* dso_handle_ptr)
{
  g_83B7CE94 = dso_handle_ptr;
  return dso_handle_ptr;
}

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

   if (lockno < g_83B7D920 )
      result = w_sceKernelLockLwMutex_87094984(&g_83B7E5A0 + lockno);
   return result;
}

int SceLibc__Unlocksyslock_64da2c47(int lockno)
{
  int result = 0x80010016;

  if (lockno < g_83B7D920)
      result = w_sceKernelUnlockLwMutex_870949A2(&g_83B7E5A0 + lockno);
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

//=========================

int w_some_global_init_87090038()
{
  return 0;
}

int w_some_global_deinit_87090052()
{
  return 0;
}

void* w_mspace_malloc_8709005A(int a1)
{
  return 0;
}

void w_mspace_free_8709006E(void* a1)
{
}

int w_mspace_calloc_87090082(int a1, int a2)
{
  return 0;
}

int w_mspace_realloc_87090098(int a1, int a2)
{
  return 0;
}

int w_mspace_memalign_870900AE(int a1, int a2)
{
  return 0;
}

int w_mspace_reallocalign_870900C4(int a1, int a2, int a3)
{
  return 0;
}

int w_mspace_malloc_stats_870900DA(int a1)
{
  return 0;
}

int w_mspace_malloc_stats_fast_870900EE(int a1)
{
  return 0;
}

int w_mspace_malloc_usable_size_87090102(int a1)
{
  return 0;
}

//============

void* w_malloc_870ACF80(int size)
{
   return 0;
}

void* w_malloc_with_cookie_870ACFB8(int size)
{
   return 0;
}

void* w_operator_new_870ACF44(int size)
{
   return 0;
}

void* w_operator_new_no_throw_870ACF5C(int size, const nothrow_t *nothrow)
{
   return 0;
}

void* w_free_870AAAA8(void *result)
{
   return 0;
}

int w_operator_delete_870AAAC8(void *ptr)
{
   return 0;
}

int w_operator_delete_870AAA64(void *a1)
{
   return 0;
}

int w_operator_delete_no_throw_870AAA84(void *ptr, const nothrow_t *nothrow)
{
   return 0;
}

//============

int initialize_callback_tables_870ACDE4(mem_callback_table2 * cbt)
{
   signed int v1;
   void*(*mc)(int);

   v1 = 0;
   if ( cbt
      && ((mc = cbt->malloc) != 0
      || cbt->malloc_with_cookie
      || cbt->operator_new
      || cbt->operator_new_no_throw
      || cbt->free
      || cbt->operator_delete0
      || cbt->operator_delete1
      || cbt->operator_delete_no_throw) )
   {
      if ( mc
         && cbt->malloc_with_cookie
         && cbt->operator_new
         && cbt->operator_new_no_throw
         && cbt->free
         && cbt->operator_delete0
         && cbt->operator_delete1
         && cbt->operator_delete_no_throw )
      {
         g_83B7F0E4 = cbt->malloc;
         g_83B7F0E8 = cbt->malloc_with_cookie;
         g_83B7F0EC = cbt->operator_new;
         g_83B7F0F0 = cbt->operator_new_no_throw;
         g_83B7F0F4 = cbt->free;
         g_83B7F0F8 = cbt->operator_delete0;
         g_83B7F0FC = cbt->operator_delete1;
         g_83B7F100 = cbt->operator_delete_no_throw;
      }
      else
      {
         printf("SceLibc new replace failed.\n");
         v1 = -1;
      }
   }
   else
   {
     g_83B7F0E4 = w_malloc_870ACF80;
     g_83B7F0E8 = w_malloc_with_cookie_870ACFB8;
     g_83B7F0EC = w_operator_new_870ACF44;
     g_83B7F0F0 = w_operator_new_no_throw_870ACF5C;
     g_83B7F0F4 = w_free_870AAAA8;
     g_83B7F0F8 = w_operator_delete_870AAAC8;
     g_83B7F0FC = w_operator_delete_870AAA64;
     g_83B7F100 = w_operator_delete_no_throw_870AAA84;
   }

   return v1;
}

int initialize_mem_callback_tables_8708FC60()
{
   mem_callback_table1 *cbt1;
   mem_callback_table2 *cbt2;
   mem_callback_table0 *cbt0;
   process_param *param;
   local_8708FC60_ctx_holder *ctx_holder;
   signed int v5;
   int (*v6)(void);
   signed int v7;
   int (*ginit)();
   signed int result;

   cbt1 = 0;
   cbt2 = 0;
   cbt0 = 0;
   param = SceProcessmgr_sceKernelGetProcessParam_2be3e066();
   if ( param )
   {
      if ( param->unk8 >= 5u )
      {
         ctx_holder = param->hldr_2C;
         if ( ctx_holder )
         {
            if ( ctx_holder->unk0 >= 0x28u )
            {
               cbt1 = ctx_holder->callback_table1;
               cbt2 = ctx_holder->callback_table2;
               if ( ctx_holder->unk0 >= 0x38u )
                  cbt0 = ctx_holder->callback_table0;
            }
         }
      }
   }
   
   v5 = 0;
   if ( cbt0 && ((v6 = cbt0->unk8) != 0 || cbt0->unkC || cbt0->malloc || cbt0->free) )
   {
      if ( v6 && cbt0->unkC && cbt0->malloc && cbt0->free )
      {
         g_83B7F658 = cbt0->unk8;
         g_83B7F65C = cbt0->unkC;
         g_83B7F654 = cbt0->malloc;
         g_83B7F650 = cbt0->free;
      }
      else
      {
         printf("SceLibc malloc_for_tls replace failed.\n", 0);
         v5 = -1;
      }
   }
   else
   {
      g_83B7F658 = 0;
      g_83B7F65C = 0;
      g_83B7F654 = (void * (*)(int))malloc;
      g_83B7F650 = free;
   }

   v7 = v5;
   if ( v5 < 0 )
      return v7;
   v7 = 0;

   if ( cbt1
      && ((ginit = cbt1->some_global_init) != 0
      || cbt1->some_global_deinit
      || cbt1->mspace_malloc
      || cbt1->mspace_free
      || cbt1->mspace_calloc
      || cbt1->mspace_realloc
      || cbt1->mspace_memalign
      || cbt1->mspace_reallocalign
      || cbt1->mspace_malloc_stats
      || cbt1->mspace_malloc_stats_fast
      || cbt1->mspace_malloc_usable_size) )
   {
      if ( ginit
         && cbt1->some_global_deinit
         && cbt1->mspace_malloc
         && cbt1->mspace_free
         && cbt1->mspace_calloc
         && cbt1->mspace_realloc
         && cbt1->mspace_memalign
         && cbt1->mspace_reallocalign
         && cbt1->mspace_malloc_stats
         && cbt1->mspace_malloc_stats_fast
         && cbt1->mspace_malloc_usable_size )
      {
         g_83B7F660 = cbt1->some_global_init;
         g_83B7F664 = cbt1->some_global_deinit;
         g_83B7F668 = cbt1->mspace_malloc;
         g_83B7F66C = cbt1->mspace_free;
         g_83B7F670 = cbt1->mspace_calloc;
         g_83B7F674 = cbt1->mspace_realloc;
         g_83B7F678 = cbt1->mspace_memalign;
         g_83B7F67C = cbt1->mspace_reallocalign;
         g_83B7F680 = cbt1->mspace_malloc_stats;
         g_83B7F684 = cbt1->mspace_malloc_stats_fast;
         g_83B7F688 = cbt1->mspace_malloc_usable_size;  
      }
      else
      {
         printf("SceLibc malloc replace failed.\n");
         v7 = -1;
      }
   }
   else
   {
      g_83B7F658 = 0;
      g_83B7F65C = 0;
      g_83B7F660 = w_some_global_init_87090038;
      g_83B7F664 = w_some_global_deinit_87090052;
      g_83B7F668 = w_mspace_malloc_8709005A;
      g_83B7F654 = w_mspace_malloc_8709005A;
      g_83B7F66C = w_mspace_free_8709006E;
      g_83B7F650 = w_mspace_free_8709006E;
      g_83B7F670 = w_mspace_calloc_87090082;
      g_83B7F674 = w_mspace_realloc_87090098;
      g_83B7F678 = w_mspace_memalign_870900AE;
      g_83B7F67C = w_mspace_reallocalign_870900C4;
      g_83B7F680 = w_mspace_malloc_stats_870900DA;
      g_83B7F684 = w_mspace_malloc_stats_fast_870900EE;
      g_83B7F688 = w_mspace_malloc_usable_size_87090102;
   }

   if ( v7 < 0 )
      return v7;

   if (initialize_callback_tables_870ACDE4)
   {
      initialize_callback_tables_870ACDE4(cbt2);
      if ( v7 < 0 )
      return v7;
   }

   if (!g_83B7F658 || (g_83B7D944 = 0, g_83B7F658(), (result = g_83B7D944) == 0) )
   {
      g_83B7D944 = 0;
      g_83B7F660();
      result = g_83B7D944;
      if (!g_83B7D944)
         return v7;
   }

   return result;
}

int w_sceKernelCreateLwMutex_87094934(SceKernelLwMutexWork *work, char *mutex_name)
{
   bool check;
   char *mutex_name_local;
   const char *mutex_name_final;
   int result;

   mutex_name_local = mutex_name;
   check = mutex_name == 0;
   mutex_name_final = "SceLibc";
   if (!check )
      mutex_name_final = mutex_name_local;

   if (!work )
      return 0x80010016;

   result = SceLibKernel_sceKernelCreateLwMutex_da6ec8ef(work, mutex_name_final, 0x2002u, 0, 0);
   if ( result >= 0 )
      result = 0;
   return result;
}

int w_sceKernelCreateLwCond_870948D0(SceKernelLwCondWork *cond_work, char *cond_name, SceKernelLwMutexWork *mutex_work)
{
   SceKernelLwMutexWork *mutex_work_local;
   signed int v4;

   mutex_work_local = mutex_work;
   v4 = -0x80010016;
   if(cond_work && mutex_work_local)
      v4 = SceLibKernel_sceKernelCreateLwCond_48c7eae6(cond_work, cond_name, 0x2000u, mutex_work_local, 0);
   return v4;
}

int initialize_global_mutexes_and_conds_8708C99C()
{
   int result = w_sceKernelCreateLwMutex_87094934(&g_83B7D1E8, "SceLibcFileStdin");
   if (result < 0)
      return result;

   result = w_sceKernelCreateLwMutex_87094934(&g_83B7D2E8, "SceLibcFileStdout");
   if (result < 0)
      return result;

   result = w_sceKernelCreateLwMutex_87094934(&g_83B7D3E8, "SceLibcFileStderr");
   if (result < 0)
      return result;

   create_mutex_local_ctx * create_ctx = &g_83B7D924;
   SceKernelLwMutexWork * work = &g_83B7E5A0;
   int lockno = 0;

   do
   {
      result = w_sceKernelCreateLwMutex_87094934(work, create_ctx->mutex_name);
      if ( result < 0 )
         break;

      ++lockno;
      ++work;
      ++create_ctx;
   }
   while (lockno < 6);

   g_83B7D920 = lockno; //lockno
   if ( result >= 0 )
      result = w_sceKernelCreateLwCond_870948D0(&g_83B7E590, "SceLibcCxaguard", &g_83B7E620);
   
   return result;
}

int w_SceLibcLdTlsModuleInfo_sceKernelCreateLwMutex_87088F28()
{
   int result;
   result = SceLibKernel_sceKernelCreateLwMutex_da6ec8ef(&g_83B7E568, "SceLibcLdTlsModuleInfo", 0x2000u, 0, 0);
   if (result >= 0)
      result = 0;
   return result;
}

void initialize_pointers_8708850C()
{
   g_83B7D208 = 0;
   g_83B7D20C = &g_83B7CEA0;
   g_83B7D1CC = &g_83B7CEA0;
   g_83B7D1D0 = &g_83B7CEA0;

   g_83B7D308 = 0;
   g_83B7D30C = &g_83B7CFA0;
   g_83B7D2CC = &g_83B7CFA0;
   g_83B7D2D0 = &g_83B7CFA0;

   g_83B7D408 = 0;
   g_83B7D40C = &g_83B7D0A0;
   g_83B7D3CC = &g_83B7D0A0;
   g_83B7D3D0 = &g_83B7D0A0;
}

//============================

int SceLibc___exp_module_start_935cd196()
{
   g_83B7F410 = (int*)&g_83B7F410;

   int res0 = initialize_mem_callback_tables_8708FC60();
   if (res0 )
   {
      printf("Initialize malloc : Failed (err=0x%08x)\n", res0);
      SceThreadmgrCoredumpTime_sceKernelExitThread_0c8a38e1(2);
   }

   int res1 = initialize_global_mutexes_and_conds_8708C99C();
   if (res1 < 0)
   {
      printf("Initialize lock : Failed (err=0x%08x)\n", res1);
      SceThreadmgrCoredumpTime_sceKernelExitThread_0c8a38e1(2);
   }

   int res2 = w_SceLibcLdTlsModuleInfo_sceKernelCreateLwMutex_87088F28();
   if (res2 < 0)
   {
      printf("Initialize tls mutex : Failed (err=0x%08x)\n", res2);
      SceThreadmgrCoredumpTime_sceKernelExitThread_0c8a38e1(2);
   }

   initialize_pointers_8708850C();

   int res3 = 0;

   g_83B7F404 = SceProcessmgr_sceKernelGetStdin_c1727f59();
   if (g_83B7F404 < 0)
      res3 = -1;

   g_83B7F408 = SceProcessmgr_sceKernelGetStdout_e5aa625c();
   if (g_83B7F408 < 0)
      res3 = -1;

   int res4 = SceProcessmgr_sceKernelGetStderr_fa5e3ada();
   g_83B7F40C = res4;
   if (res4 < 0 || res3 < 0)
      printf("openStdio : failed\n");

   module_start_local_ctx *start_ctx = (module_start_local_ctx *)0x83B7E500;

   do
   {
      if (start_ctx->some_callback)
         start_ctx->some_callback();
      ++start_ctx;
   }
   while ((unsigned int)start_ctx < g_83B7E54C);

   SceThreadmgrCoredumpTime_sceKernelExitThread_0c8a38e1(0);
   return 0;
}

//============================

int w_sceKernelDeleteLwMutex_8709496A(SceKernelLwMutexWork *work)
{
   int result;

   if (!work)
      return 0x80010016;

  result = SceLibKernel_sceKernelDeleteLwMutex_244e76d2(work);

  if (result >= 0)
    result = 0;

  return result;
}

int w_sceKernelDeleteLwCond_870948F4(SceKernelLwCondWork *pWork)
{
  unsigned int result; // r1

  result = 0x80010016;
  if ( pWork )
    result = SceLibKernel_sceKernelDeleteLwCond_721f6cb3(pWork);
  return result;
}

int delete_mutexes_8708C92C()
{
   int mutex_count = g_83B7D920;
   w_sceKernelDeleteLwCond_870948F4(&g_83B7E590); //SceLibcCxaguard
   g_83B7D920 = 0;

   if (mutex_count)
   {
      SceKernelLwMutexWork *work = &g_83B7E5A0; //mutex table
      int index = 0;
      do
      {
         if (w_sceKernelDeleteLwMutex_8709496A(work) < 0 )
            break;

         ++index;
         ++work;
      }
      while (index < mutex_count);
   }

   int result = w_sceKernelDeleteLwMutex_8709496A(&g_83B7D3E8); //SceLibcFileStderr
   if (result < 0)
      return result;

   result = w_sceKernelDeleteLwMutex_8709496A(&g_83B7D2E8); //SceLibcFileStdout
   if (result < 0)
      return result;

   return w_sceKernelDeleteLwMutex_8709496A((SceKernelLwMutexWork *)&g_83B7D1E8); //SceLibcFileStdin
}

//============================

int SceLibc___exp_module_exit_913482a9()
{
   /*
   int v1; // r0
   if (g_83B7F414)
      return sub_870844AC(1);

   SceLibc_SceLibc__exp___cxa_finalize_b538bf48(g_83B7F410);
   sub_870844AC(0);
   sub_87088F58();
   v1 = delete_mutexes_8708C92C();
   return sub_8708FF8A(v1);
   */

   return 0;
}