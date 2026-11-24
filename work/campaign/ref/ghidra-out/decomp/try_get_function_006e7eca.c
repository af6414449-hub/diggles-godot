
/* Library Function - Single Match
    void * __cdecl try_get_function(enum `anonymous namespace'::function_id,char const * const,enum
   A0x391cf84c::module_id const * const,enum A0x391cf84c::module_id const * const)
   
   Library: Visual Studio 2019 Release */

void * __cdecl
try_get_function(function_id param_1,char *param_2,module_id *param_3,module_id *param_4)

{
  uint *puVar1;
  HINSTANCE__ *hModule;
  uint uVar2;
  byte bVar3;
  FARPROC pFVar4;
  
  puVar1 = &DAT_00769fd8 + param_1;
  bVar3 = (byte)DAT_0076700c & 0x1f;
  pFVar4 = (FARPROC)((DAT_0076700c ^ *puVar1) >> bVar3 | (DAT_0076700c ^ *puVar1) << 0x20 - bVar3);
  if (pFVar4 == (FARPROC)0xffffffff) {
    pFVar4 = (FARPROC)0x0;
  }
  else if (pFVar4 == (FARPROC)0x0) {
    hModule = try_get_first_available_module(param_3,param_4);
    if ((hModule == (HINSTANCE__ *)0x0) ||
       (pFVar4 = GetProcAddress(hModule,param_2), pFVar4 == (FARPROC)0x0)) {
      bVar3 = 0x20 - ((byte)DAT_0076700c & 0x1f) & 0x1f;
      LOCK();
      *puVar1 = (0xffffffffU >> bVar3 | -1 << 0x20 - bVar3) ^ DAT_0076700c;
      UNLOCK();
      pFVar4 = (FARPROC)0x0;
    }
    else {
      uVar2 = __crt_fast_encode_pointer<>(pFVar4);
      LOCK();
      *puVar1 = uVar2;
      UNLOCK();
    }
  }
  return pFVar4;
}

