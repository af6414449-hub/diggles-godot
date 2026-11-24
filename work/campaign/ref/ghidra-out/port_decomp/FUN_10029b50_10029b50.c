
void FUN_10029b50(void)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  undefined8 local_18;
  uint local_c;
  
  local_c = DAT_1005000c ^ (uint)&local_18;
  __CheckForDebuggerJustMyCode(&DAT_14170ce3);
  if (in_ECX == 0) {
    __security_check_cookie(local_c ^ (uint)&local_18);
    return;
  }
  if (*(code **)(in_ECX + 4) != (code *)0x0) {
    uVar2 = 1;
    if (*(int *)(in_ECX + 0x20) != 0) {
      uVar2 = 7;
    }
    uVar2 = uVar2 & *(uint *)(in_ECX + 0x60);
    if (uVar2 != 0) {
      local_18 = 0;
      (**(code **)(in_ECX + 4))(*(undefined4 *)(in_ECX + 0xc),&local_18,uVar2);
    }
    pcVar1 = *(code **)(in_ECX + 8);
    if ((pcVar1 != (code *)0x0) && (*(int *)(in_ECX + 0x80) == 0)) {
      if (*(int *)(in_ECX + 0x20) == 0) {
        iVar3 = (*pcVar1)(*(undefined4 *)(in_ECX + 0xc),4,0);
        if (iVar3 != 0) {
          uVar4 = FUN_10029ae0(*(undefined4 *)(in_ECX + 0x60),*(undefined4 *)(in_ECX + 100));
          local_18 = CONCAT44(local_18._4_4_,uVar4);
          (**(code **)(in_ECX + 4))(*(undefined4 *)(in_ECX + 0xc),&local_18,4);
        }
        iVar3 = (**(code **)(in_ECX + 8))
                          (*(undefined4 *)(in_ECX + 0xc),*(int *)(in_ECX + 0x68) + 4,0);
        if (iVar3 == 0) goto LAB_10029cd7;
        uVar4 = *(undefined4 *)(in_ECX + 0x60);
        if (*(int *)(in_ECX + 100) != 0) {
          uVar4 = 0xffffffff;
        }
        local_18 = CONCAT44(local_18._4_4_,uVar4);
        uVar4 = 4;
      }
      else {
        iVar3 = (*pcVar1)(*(undefined4 *)(in_ECX + 0xc),0x10,0);
        if (iVar3 != 0) {
          local_18 = FUN_10029b20(*(undefined4 *)(in_ECX + 0x60),*(undefined4 *)(in_ECX + 100));
          (**(code **)(in_ECX + 4))(*(undefined4 *)(in_ECX + 0xc),&local_18,8);
        }
        iVar3 = (**(code **)(in_ECX + 8))
                          (*(undefined4 *)(in_ECX + 0xc),*(int *)(in_ECX + 0x68) + 0x10,0);
        if (iVar3 == 0) goto LAB_10029cd7;
        local_18 = CONCAT44(*(int *)(in_ECX + 100) + (uint)(0xffffffe7 < *(uint *)(in_ECX + 0x60)),
                            *(uint *)(in_ECX + 0x60) + 0x18);
        uVar4 = 8;
      }
      (**(code **)(in_ECX + 4))(*(undefined4 *)(in_ECX + 0xc),&local_18,uVar4);
    }
  }
LAB_10029cd7:
  __security_check_cookie(local_c ^ (uint)&local_18);
  return;
}

