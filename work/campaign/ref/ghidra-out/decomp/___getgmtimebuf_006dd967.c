
/* Library Function - Single Match
    ___getgmtimebuf
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

tm * __cdecl ___getgmtimebuf(void)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  iVar1 = ___acrt_getptd_noexit();
  if (iVar1 != 0) {
    if (*(tm **)(iVar1 + 0x38) != (tm *)0x0) {
      return *(tm **)(iVar1 + 0x38);
    }
    uVar2 = __malloc_base(0x24);
    *(undefined4 *)(iVar1 + 0x38) = uVar2;
    FID_conflict__free((void *)0x0);
    if (*(tm **)(iVar1 + 0x38) != (tm *)0x0) {
      return *(tm **)(iVar1 + 0x38);
    }
  }
  piVar3 = __errno();
  *piVar3 = 0xc;
  return (tm *)0x0;
}

