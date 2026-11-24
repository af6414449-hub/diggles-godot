
void FUN_10017ff0(int *param_1,int **param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  code *pcVar4;
  int iVar5;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar6;
  undefined4 in_EDX;
  int *piVar7;
  int *piVar8;
  int **ppiVar9;
  int local_f8 [31];
  undefined1 local_7c [16];
  undefined1 local_6c [16];
  int *local_5c;
  int *local_58;
  int *local_54;
  int *local_50;
  int *local_4c;
  int **local_48;
  int local_44;
  int *local_40;
  int local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10042a75;
  local_10 = ExceptionList;
  local_14 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_54 = param_1;
  local_48 = param_2;
  __CheckForDebuggerJustMyCode(&DAT_14170d01,in_EDX,local_14);
  piVar3 = (int *)FUN_1003ff62(0x110);
  local_50 = piVar3;
  memset(piVar3,0,0x110);
  local_5c = piVar3 + 0x11;
  *piVar3 = (int)DirectDrawSurface7Port::vftable;
  *local_5c = 0;
  piVar3[0x12] = 0;
  *(undefined1 *)(piVar3 + 10) = 0;
  piVar3[0xb] = 0;
  piVar3[0xd] = 0;
  piVar3[0xe] = 0;
  memset(local_f8,0,0x7c);
  piVar8 = local_50;
  local_58 = piVar3 + 0x14;
  piVar7 = local_f8;
  piVar3 = piVar3 + 0x14;
  for (iVar5 = 0x1f; iVar5 != 0; iVar5 = iVar5 + -1) {
    *piVar3 = *piVar7;
    piVar7 = piVar7 + 1;
    piVar3 = piVar3 + 1;
  }
  local_50[0x3e] = 0;
  local_50[9] = 0;
  local_50[1] = 0;
  local_50[2] = 0;
  local_50[3] = 0;
  local_50[4] = 0;
  local_50[5] = 0;
  local_50[6] = 0;
  local_50[7] = 0;
  local_50[8] = 0;
  if (*(code **)*local_50 == FUN_100191d0) {
    iVar5 = FUN_100191d0(local_50,&DAT_10043410,local_48);
    uVar6 = extraout_ECX;
  }
  else {
    iVar5 = (**(code **)*local_50)(local_50,&DAT_10043410,local_48);
    uVar6 = extraout_ECX_00;
  }
  piVar7 = local_54;
  if (iVar5 < 0) {
    FUN_100183c0(uVar6);
    FUN_100053a0(iVar5);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_6c,(ThrowInfo *)&DAT_1004a24c);
  }
  if (local_54[0x12] == 0) {
    local_54[0x12] = 0x20;
  }
  if (local_54[0x16] == 0) {
    local_54[0x16] = 0xff0000;
  }
  if (local_54[0x17] == 0) {
    local_54[0x17] = 0xff00;
  }
  if (local_54[0x18] == 0) {
    local_54[0x18] = 0xff;
  }
  if (local_54[0x15] == 0) {
    local_54[0x15] = 0x20;
  }
  local_48 = (int **)(local_54 + 2);
  if ((local_54[3] == 0) || (*local_48 == (int *)0x0)) {
    piVar3 = (int *)FUN_1000ece0();
    iVar5 = *piVar3;
    iVar1 = *(int *)(iVar5 + 0x78);
    iVar2 = *(int *)(iVar5 + 0x70);
    piVar7[3] = *(int *)(iVar5 + 0x74) - *(int *)(iVar5 + 0x6c);
    *local_48 = (int *)(iVar1 - iVar2);
  }
  if (*(code **)(*piVar8 + 0x60) == FUN_100188f0) {
    piVar8 = local_58;
    for (iVar5 = 0x1f; iVar5 != 0; iVar5 = iVar5 + -1) {
      *piVar8 = *piVar7;
      piVar7 = piVar7 + 1;
      piVar8 = piVar8 + 1;
    }
    local_50[0xe] = local_50[0x16];
    iVar5 = local_50[0x29];
    local_50[0xf] = iVar5;
    local_50[0xd] = local_50[0x17];
    local_50[0x3d] = ((int)(iVar5 + (iVar5 >> 0x1f & 7U)) >> 3) * local_50[0x17];
    piVar8 = local_50;
    piVar7 = local_54;
  }
  else {
    (**(code **)(*piVar8 + 0x60))(piVar7);
  }
  local_18 = (int *)0x0;
  local_8 = 0;
  if ((piVar7[0x1a] & 0x200U) == 0) {
    if (*(code **)(*piVar8 + 0x68) == FUN_10018770) {
      FUN_10018770();
    }
    else {
      (**(code **)(*piVar8 + 0x68))();
    }
    local_4c = (int *)FUN_1000ece0();
    piVar3 = local_18;
    if (local_18 != (int *)0x0) {
      local_18 = (int *)0x0;
      (**(code **)(*piVar3 + 8))(piVar3);
    }
    iVar5 = *local_4c;
    local_44 = piVar7[3];
    local_4c = *(int **)(iVar5 + 4);
    local_40 = *local_48;
    if (local_44 == 0) {
      local_44 = *(int *)(iVar5 + 0x74) - *(int *)(iVar5 + 0x6c);
    }
    if (local_40 == (int *)0x0) {
      local_40 = (int *)(*(int *)(iVar5 + 0x78) - *(int *)(iVar5 + 0x70));
    }
    local_8._0_1_ = 1;
    local_24 = 0x28;
    local_1c = 1;
    if ((piVar7[1] & 0x20000U) == 0) {
      local_3c = 1;
    }
    else {
      local_3c = piVar7[6];
    }
    local_38 = 1;
    local_30 = 1;
    local_2c = 0;
    local_28 = 0;
    local_34 = 0x1c;
    local_20 = 0;
    iVar5 = (**(code **)(*local_4c + 0x14))(local_4c,&local_44,0,&local_18);
    if (iVar5 < 0) {
      FUN_100053a0(iVar5);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_7c,(ThrowInfo *)&DAT_1004a24c);
    }
    local_8 = (uint)local_8._1_3_ << 8;
    pcVar4 = *(code **)(*piVar8 + 0x5c);
    if (pcVar4 == FUN_10018870) {
      FUN_100103b0(local_18);
      goto LAB_10018349;
    }
    ppiVar9 = &local_18;
  }
  else {
    if (piVar7[5] != 1) goto LAB_10018349;
    piVar7[5] = 0;
    piVar7[0x1a] = 0;
    piVar7[0x1b] = 0;
    piVar7[0x1c] = 0;
    piVar7[0x1d] = 0;
    piVar7[0x1a] = 4;
    local_48 = (int **)0x0;
    (**(code **)(*local_4c + 0xc))(piVar7,&local_48,0);
    (*(code *)(*local_48)[0x18])(piVar7);
    pcVar4 = *(code **)(*piVar8 + 0x48);
    ppiVar9 = local_48;
    if (pcVar4 == FUN_10018fb0) {
      piVar8[piVar8[9] + 1] = (int)local_48;
      piVar8[9] = piVar8[9] + 1;
      goto LAB_10018349;
    }
  }
  (*pcVar4)(ppiVar9);
LAB_10018349:
  piVar8 = local_18;
  local_8 = 0xffffffff;
  if (local_18 != (int *)0x0) {
    local_18 = (int *)0x0;
    (**(code **)(*piVar8 + 8))(piVar8);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

