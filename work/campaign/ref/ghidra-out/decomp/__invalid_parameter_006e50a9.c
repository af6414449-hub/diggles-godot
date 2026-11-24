
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __invalid_parameter
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void __invalid_parameter(wchar_t *param_1,wchar_t *param_2,wchar_t *param_3,uint param_4,
                        uintptr_t param_5)

{
  int iVar1;
  byte bVar2;
  code *pcVar3;
  
  iVar1 = ___acrt_getptd_noexit();
  if (((iVar1 == 0) || (pcVar3 = *(code **)(iVar1 + 0x35c), pcVar3 == (code *)0x0)) &&
     (bVar2 = (byte)DAT_0076700c & 0x1f,
     pcVar3 = (code *)((DAT_0076700c ^ _DAT_00769d60) >> bVar2 |
                      (DAT_0076700c ^ _DAT_00769d60) << 0x20 - bVar2), pcVar3 == (code *)0x0)) {
                    /* WARNING: Subroutine does not return */
    __invoke_watson(param_1,param_2,param_3,param_4,param_5);
  }
  guard_check_icall(param_1,param_2,param_3,param_4,param_5);
  (*pcVar3)();
  return;
}

