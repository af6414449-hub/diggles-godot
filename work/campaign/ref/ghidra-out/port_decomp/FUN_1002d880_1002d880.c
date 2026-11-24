
undefined4 FUN_1002d880(uint param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  uint uVar3;
  bool bVar4;
  
  __CheckForDebuggerJustMyCode(&DAT_14170ce2);
  if ((param_2 == 0) && (param_1 < 0x80000000)) {
    iVar1 = (**(code **)(in_ECX + 4))(*(undefined4 *)(in_ECX + 8),param_1,0);
joined_r0x1002d927:
    if (iVar1 != 0) {
LAB_1002d929:
      *(undefined4 *)(in_ECX + 0x14) = 0x400;
      *(undefined4 *)(in_ECX + 0x18) = 0x20;
      *(undefined4 *)(in_ECX + 0x101c) = 0;
      *(undefined4 *)(in_ECX + 0xc) = 0;
      *(undefined4 *)(in_ECX + 0x10) = 0;
      return 1;
    }
  }
  else {
    iVar1 = (**(code **)(in_ECX + 4))(*(undefined4 *)(in_ECX + 8),0x7fffffff,0);
    if (iVar1 != 0) {
      uVar3 = param_1 + 0x80000001;
      iVar1 = param_2 + -1 + (uint)(0x7ffffffe < param_1);
      while( true ) {
        if ((iVar1 == 0) && (uVar3 < 0x80000000)) {
          if (uVar3 == 0) goto LAB_1002d929;
          iVar1 = (**(code **)(in_ECX + 4))(*(undefined4 *)(in_ECX + 8),uVar3,1);
          goto joined_r0x1002d927;
        }
        iVar2 = (**(code **)(in_ECX + 4))(*(undefined4 *)(in_ECX + 8),0x7fffffff,1);
        if (iVar2 == 0) break;
        bVar4 = 0x7ffffffe < uVar3;
        uVar3 = uVar3 + 0x80000001;
        iVar1 = iVar1 + -1 + (uint)bVar4;
      }
    }
  }
  return 0;
}

