
/* Library Function - Single Match
    void __cdecl free_crt_array_internal(void const * * const,unsigned int)
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void __cdecl free_crt_array_internal(void **param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0;
  uVar1 = ~-(uint)(param_1 + param_2 < param_1) & param_2 & 0x3fffffff;
  if (uVar1 != 0) {
    do {
      FID_conflict__free(*param_1);
      uVar2 = uVar2 + 1;
      param_1 = param_1 + 1;
    } while (uVar2 != uVar1);
  }
  return;
}

