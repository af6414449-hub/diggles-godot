
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___acrt_invoke_user_matherr
   
   Library: Visual Studio 2019 Release */

undefined4 ___acrt_invoke_user_matherr(undefined4 param_1)

{
  undefined4 uVar1;
  byte bVar2;
  code *pcVar3;
  
  bVar2 = (byte)DAT_0076700c & 0x1f;
  pcVar3 = (code *)((DAT_0076700c ^ _DAT_00769d4c) >> bVar2 |
                   (DAT_0076700c ^ _DAT_00769d4c) << 0x20 - bVar2);
  if (pcVar3 == (code *)0x0) {
    uVar1 = 0;
  }
  else {
    guard_check_icall(param_1);
    uVar1 = (*pcVar3)();
  }
  return uVar1;
}

