
undefined4 FUN_100284a0(uint param_1,uint param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  longlong lVar5;
  
  __CheckForDebuggerJustMyCode(&DAT_14170cf0);
  if ((in_ECX != 0) && (*(int *)(in_ECX + 0x1a2c) != 0)) {
    if (param_1 == 0 && param_2 == 0) {
      uVar2 = FUN_100281a0();
      return uVar2;
    }
    if ((*(int *)(in_ECX + 0x52a0) != 0) && (*(int *)(in_ECX + 0x52a4) != 0)) {
      uVar2 = FUN_100281f0(param_1,param_2);
      return uVar2;
    }
    uVar1 = *(uint *)(in_ECX + 0x3e5c);
    if (((param_1 == *(uint *)(in_ECX + 0x3e58)) && (param_2 == uVar1)) ||
       (((uVar1 < param_2 ||
         (((uVar1 <= param_2 && (*(uint *)(in_ECX + 0x3e58) <= param_1)) ||
          (iVar3 = FUN_100281a0(), iVar3 != 0)))) &&
        (iVar3 = param_1 - *(uint *)(in_ECX + 0x3e58),
        iVar4 = (param_2 - *(int *)(in_ECX + 0x3e5c)) - (uint)(param_1 < *(uint *)(in_ECX + 0x3e58))
        , lVar5 = FUN_10027ee0(iVar3,iVar4), lVar5 == CONCAT44(iVar4,iVar3))))) {
      return 1;
    }
  }
  return 0;
}

