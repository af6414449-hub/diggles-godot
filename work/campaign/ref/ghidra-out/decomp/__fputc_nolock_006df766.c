
/* Library Function - Single Match
    __fputc_nolock
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

uint __fputc_nolock(uint param_1,int *param_2)

{
  int *piVar1;
  uint uVar2;
  
  piVar1 = param_2 + 2;
  *piVar1 = *piVar1 + -1;
  if (*piVar1 < 0) {
    uVar2 = FUN_006e885f(param_1,param_2);
    return uVar2;
  }
  *(undefined1 *)*param_2 = (undefined1)param_1;
  *param_2 = *param_2 + 1;
  return param_1 & 0xff;
}

