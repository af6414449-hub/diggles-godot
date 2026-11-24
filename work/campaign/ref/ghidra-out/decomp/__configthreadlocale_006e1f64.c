
/* Library Function - Single Match
    __configthreadlocale
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

int __cdecl __configthreadlocale(int _Flag)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  
  iVar2 = ___acrt_getptd();
  uVar1 = *(uint *)(iVar2 + 0x350);
  if (_Flag == -1) {
    DAT_007673b0 = 0xffffffff;
  }
  else if (_Flag != 0) {
    if (_Flag == 1) {
      uVar4 = uVar1 | 2;
    }
    else {
      if (_Flag != 2) {
        piVar3 = __errno();
        *piVar3 = 0x16;
        FUN_006e510d();
        return -1;
      }
      uVar4 = uVar1 & 0xfffffffd;
    }
    *(uint *)(iVar2 + 0x350) = uVar4;
  }
  return ((uVar1 & 2) == 0) + 1;
}

