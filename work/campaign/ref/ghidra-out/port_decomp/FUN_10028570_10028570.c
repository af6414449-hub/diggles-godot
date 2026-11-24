
undefined4 FUN_10028570(uint *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int in_ECX;
  bool bVar5;
  uint local_20;
  uint uStack_1c;
  
  __CheckForDebuggerJustMyCode(&DAT_14170cf0);
  if ((in_ECX != 0) && (*(int *)(in_ECX + 0x1a2c) != 0)) {
    uVar1 = *(undefined4 *)(in_ECX + 0x3e58);
    uVar2 = *(undefined4 *)(in_ECX + 0x3e5c);
    iVar3 = FUN_100281a0();
    if (iVar3 != 0) {
      iVar3 = FUN_10027ab0(0);
      uStack_1c = 0;
      local_20 = 0;
      while (iVar3 != 0) {
        uVar4 = FUN_10041270();
        bVar5 = CARRY4(local_20,uVar4);
        local_20 = local_20 + uVar4;
        uStack_1c = uStack_1c + bVar5;
        iVar3 = FUN_10027ab0(0);
      }
      iVar3 = (**(code **)(in_ECX + 0x1a2c))(*(undefined4 *)(in_ECX + 0x1a30),0,0);
      if (iVar3 != 0) {
        *(undefined4 *)(in_ECX + 0x3e60) = 0;
        *(undefined4 *)(in_ECX + 0x3e64) = 0;
        FUN_10028100();
        iVar3 = FUN_100284a0(uVar1,uVar2);
        if (iVar3 != 0) {
          if (param_1 != (uint *)0x0) {
            *param_1 = local_20;
            param_1[1] = uStack_1c;
          }
          return 1;
        }
      }
    }
  }
  return 0;
}

