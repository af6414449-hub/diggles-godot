
/* Library Function - Single Match
    __fgetc_nolock
   
   Library: Visual Studio 2019 Release */

uint __fgetc_nolock(undefined4 *param_1)

{
  byte bVar1;
  int *piVar2;
  uint uVar3;
  
  if (param_1 == (undefined4 *)0x0) {
    piVar2 = __errno();
    *piVar2 = 0x16;
    FUN_006e510d();
    return 0xffffffff;
  }
  piVar2 = param_1 + 2;
  *piVar2 = *piVar2 + -1;
  if (*piVar2 < 0) {
    uVar3 = FUN_006e8dd6(param_1);
    return uVar3;
  }
  bVar1 = *(byte *)*param_1;
  *param_1 = (byte *)*param_1 + 1;
  return (uint)bVar1;
}

