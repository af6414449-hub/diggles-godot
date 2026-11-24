
/* Library Function - Single Match
    void * __cdecl try_get_function(enum `anonymous namespace'::function_id,char const * const,enum
   A0x9d0f8d90::module_id const * const,enum A0x9d0f8d90::module_id const * const)
   
   Library: Visual Studio 2019 Release */

void * __cdecl
try_get_function(function_id param_1,char *param_2,module_id *param_3,module_id *param_4)

{
  int *piVar1;
  void *pvVar2;
  HINSTANCE__ *hModule;
  FARPROC pFVar3;
  
  piVar1 = (int *)(&DAT_00769b28 + param_1 * 4);
  pvVar2 = (void *)*piVar1;
  if (pvVar2 != (void *)0xffffffff) {
    if (pvVar2 != (void *)0x0) {
      return pvVar2;
    }
    hModule = try_get_first_available_module(param_3,param_4);
    if ((hModule != (HINSTANCE__ *)0x0) &&
       (pFVar3 = GetProcAddress(hModule,param_2), pFVar3 != (FARPROC)0x0)) {
      LOCK();
      *piVar1 = (int)pFVar3;
      UNLOCK();
      return pFVar3;
    }
    LOCK();
    *piVar1 = -1;
    UNLOCK();
  }
  return (void *)0x0;
}

