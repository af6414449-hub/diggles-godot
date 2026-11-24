
/* Library Function - Single Match
    __realloc_base
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

LPVOID __realloc_base(void *param_1,uint param_2)

{
  LPVOID pvVar1;
  int *piVar2;
  int iVar3;
  
  if (param_1 == (void *)0x0) {
    pvVar1 = (LPVOID)__malloc_base(param_2);
  }
  else {
    if (param_2 == 0) {
      FID_conflict__free(param_1);
    }
    else {
      if (param_2 < 0xffffffe1) {
        do {
          pvVar1 = HeapReAlloc(DAT_0076a210,0,param_1,param_2);
          if (pvVar1 != (LPVOID)0x0) {
            return pvVar1;
          }
          iVar3 = FUN_006e3101();
        } while ((iVar3 != 0) && (iVar3 = __callnewh(param_2), iVar3 != 0));
      }
      piVar2 = __errno();
      *piVar2 = 0xc;
    }
    pvVar1 = (LPVOID)0x0;
  }
  return pvVar1;
}

