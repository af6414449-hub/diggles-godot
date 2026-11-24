
/* Library Function - Single Match
    __malloc_base
   
   Library: Visual Studio 2019 Release */

LPVOID __malloc_base(size_t param_1)

{
  int iVar1;
  LPVOID pvVar2;
  int *piVar3;
  
  if (param_1 < 0xffffffe1) {
    if (param_1 == 0) {
      param_1 = 1;
    }
    do {
      pvVar2 = HeapAlloc(DAT_0076a210,0,param_1);
      if (pvVar2 != (LPVOID)0x0) {
        return pvVar2;
      }
      iVar1 = FUN_006e3101();
    } while ((iVar1 != 0) && (iVar1 = __callnewh(param_1), iVar1 != 0));
  }
  piVar3 = __errno();
  *piVar3 = 0xc;
  return (LPVOID)0x0;
}

