
void FUN_100077a0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 *in_ECX;
  undefined4 *puStack_80;
  undefined8 *puStack_7c;
  undefined4 uStack_78;
  int *piStack_74;
  undefined1 auStack_64 [20];
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  uint local_28;
  uint local_24;
  undefined8 local_20;
  undefined8 local_18;
  undefined4 local_10;
  uint local_c;
  
  local_c = DAT_1005000c ^ (uint)auStack_64;
  piStack_74 = (int *)0x100077c3;
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  piVar1 = in_ECX + 3;
  piStack_74 = (int *)*piVar1;
  piVar2 = (int *)*in_ECX;
  local_50 = param_1;
  local_4c = param_2;
  local_48 = param_3;
  local_34 = in_ECX[0x17];
  local_44 = 0;
  local_24 = (in_ECX[0x20] & 2) << 10 | 2;
  local_38 = 0x20;
  local_40 = 1;
  local_3c = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 3;
  local_20 = 0;
  local_18 = 0;
  local_10 = 1;
  if (piStack_74 != (int *)0x0) {
    *piVar1 = 0;
    uStack_78 = 0x10007858;
    (**(code **)(*piStack_74 + 8))();
  }
  puStack_7c = &local_20;
  uStack_78 = 0;
  puStack_80 = &local_50;
  piStack_74 = piVar1;
  iVar3 = (**(code **)(*piVar2 + 0x3c))(piVar2,in_ECX[1],in_ECX[0x19]);
  if (-1 < iVar3) {
    __security_check_cookie(local_28 ^ (uint)&puStack_80);
    return;
  }
  FUN_100053a0(iVar3);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&puStack_7c,(ThrowInfo *)&DAT_1004a24c);
}

