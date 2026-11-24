
void FUN_00510b60(void)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  undefined **ppuVar7;
  int this;
  int iVar8;
  int iVar9;
  undefined4 local_48;
  int *local_44;
  undefined4 local_40;
  int *local_3c;
  int *local_38;
  int local_34;
  int *local_30;
  int local_2c;
  int local_28;
  undefined1 local_21;
  undefined1 *puStack_20;
  void *local_1c;
  undefined1 *puStack_18;
  undefined4 local_14;
  
  puStack_20 = &stack0xfffffffc;
  local_14 = 0xffffffff;
  puStack_18 = &LAB_0070175d;
  local_1c = ExceptionList;
  uVar3 = DAT_0076700c ^ (uint)&stack0xfffffff0;
  ExceptionList = &local_1c;
  local_21 = 1;
  local_28 = this;
  piVar4 = (int *)FUN_006ba810(0x19);
  piVar4[1] = 0x14;
  piVar4[2] = -1;
  *piVar4 = 0;
  *(undefined1 *)(piVar4 + 3) = 0;
  piVar4[3] = 0x6f666e49;
  piVar4[4] = 0x7374704f;
  *(undefined1 *)(piVar4 + 5) = 0;
  piVar4[2] = 8;
  if (piVar4 != (int *)0x0) {
    *piVar4 = *piVar4 + 1;
  }
  FUN_0050e8e0(piVar4,uVar3);
  local_48 = 0x11d;
  local_44 = (int *)0x78;
  local_40 = 10;
  local_3c = (int *)0x3c;
  uVar5 = FUN_00517d80(&local_48);
  this->i_48 = uVar5;
  local_48 = 0x11d;
  local_44 = (int *)0x19;
  local_40 = 10;
  local_3c = (int *)0x1e;
  uVar5 = FUN_0054c770(&local_48,&PTR_0071ce50);
  this->i_4c = uVar5;
  piVar4 = (int *)FUN_006ba810(0x19);
  piVar4[1] = 4;
  piVar4[2] = -1;
  *piVar4 = 0;
  piVar4[3] = 0x746553;
  piVar4[2] = 3;
  if (piVar4 != (int *)0x0) {
    *piVar4 = *piVar4 + 1;
  }
  local_48 = 0xf;
  local_44 = (int *)0xbb;
  uVar5 = FUN_00526f80(&DAT_00767988);
  this->i_50 = uVar5;
  piVar4 = (int *)FUN_006ba810(0x19);
  piVar4[1] = 4;
  piVar4[2] = -1;
  *piVar4 = 0;
  piVar4[3] = 0x6c6544;
  piVar4[2] = 3;
  if (piVar4 != (int *)0x0) {
    *piVar4 = *piVar4 + 1;
  }
  local_48 = 0x41;
  local_44 = (int *)0xbb;
  uVar5 = FUN_00526f80(&DAT_00767988);
  this->i_54 = uVar5;
  piVar4 = (int *)FUN_006ba810(0x19);
  piVar4[1] = 0x14;
  piVar4[2] = -1;
  *piVar4 = 0;
  *(undefined1 *)(piVar4 + 3) = 0;
  piVar4[3] = 0x79706f43;
  *(undefined1 *)(piVar4 + 4) = 0;
  piVar4[2] = 4;
  if (piVar4 != (int *)0x0) {
    *piVar4 = *piVar4 + 1;
  }
  local_48 = 0x7d;
  local_44 = (int *)0xbb;
  uVar5 = FUN_00526f80(&DAT_00767988);
  this->i_58 = uVar5;
  piVar4 = (int *)FUN_006ba810(0x19);
  piVar4[1] = 0x14;
  piVar4[2] = -1;
  *piVar4 = 0;
  *(undefined1 *)(piVar4 + 3) = 0;
  piVar4[3] = 0x74736150;
  *(undefined2 *)(piVar4 + 4) = 0x65;
  piVar4[2] = 5;
  if (piVar4 != (int *)0x0) {
    *piVar4 = *piVar4 + 1;
  }
  local_48 = 0xcd;
  local_44 = (int *)&DAT_000000bb;
  uVar5 = FUN_00526f80(&DAT_00767988);
  this->i_5c = uVar5;
  this->i_60 = 0;
  FUN_00518020();
  if (this->i_60 != 0) {
    piVar4 = (int *)FUN_006ba810(0x19);
    piVar4[1] = 0x14;
    piVar4[2] = -1;
    *piVar4 = 0;
    *(undefined1 *)(piVar4 + 3) = 0;
    piVar4[3] = 0x74696445;
    piVar4[4] = 0x535f726f;
    piVar4[5] = 0x495f7465;
    piVar4[6] = 0x6f666e;
    piVar4[2] = 0xf;
    *piVar4 = 1;
    local_30 = piVar4;
    local_30 = (int *)FUN_00601d30(&local_30);
    local_14 = 0;
    *piVar4 = *piVar4 + -1;
    if (*piVar4 == 0) {
      FUN_006ba940();
    }
    local_14 = 0xffffffff;
    if (local_30 != (int *)0xffffffff) {
      FUN_00444ea0(0);
      piVar4 = (int *)Tcl_NewStringObj("info_string",0xffffffff);
      *piVar4 = *piVar4 + 1;
      iVar9 = *(int *)(this->i_60 + 0xc0);
      if (iVar9 == 0) {
        local_30 = (int *)0x0;
      }
      else {
        local_30 = (int *)Tcl_ObjGetVar2(iVar9,piVar4,0,0);
        if (local_30 != (int *)0x0) {
          *local_30 = *local_30 + 1;
        }
      }
      piVar1 = local_30;
      local_14 = 1;
      *piVar4 = *piVar4 + -1;
      if (*piVar4 < 1) {
        TclFreeObj(piVar4);
      }
      iVar9 = 0;
      while( true ) {
        local_2c = iVar9;
        if (piVar1 == (int *)0x0) {
          iVar8 = 0;
        }
        else {
          iVar6 = Tcl_ListObjLength(0,piVar1,&local_34);
          iVar8 = local_34;
          if (iVar6 != 0) {
            iVar8 = 0;
          }
        }
        if (iVar8 <= iVar9) break;
        if ((piVar1 == (int *)0x0) ||
           (iVar9 = Tcl_ListObjIndex(0,piVar1,iVar9,&local_38), iVar9 != 0)) {
          local_3c = (int *)0x0;
        }
        else {
          local_3c = local_38;
          if (local_38 != (int *)0x0) {
            *local_38 = *local_38 + 1;
          }
        }
        piVar4 = local_3c;
        local_14._0_1_ = 2;
        if (local_3c == (int *)0x0) {
          ppuVar7 = &PTR_0071ce50;
        }
        else {
          ppuVar7 = (undefined **)Tcl_GetStringFromObj(local_3c,0);
        }
        FUN_006b8fb0(ppuVar7);
        local_14 = CONCAT31(local_14._1_3_,4);
        if ((piVar4 != (int *)0x0) && (*piVar4 = *piVar4 + -1, *piVar4 < 1)) {
          TclFreeObj(piVar4);
        }
        iVar9 = local_28;
        FUN_00444ca0(1);
        uVar3 = *(uint *)(iVar9 + 0x6c);
        local_3c = (int *)(uVar3 - 1);
        if (uVar3 <= local_3c) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        piVar2 = local_44;
        local_3c = (int *)(*(int *)(iVar9 + 0x68) + (int)local_3c * 4);
        piVar4 = (int *)*local_3c;
        *local_3c = (int)local_44;
        if (local_44 != (int *)0x0) {
          *local_44 = *local_44 + 1;
        }
        if ((piVar4 != (int *)0x0) && (*piVar4 = *piVar4 + -1, *piVar4 == 0)) {
          FUN_006ba940();
        }
        *(int *)(*local_3c + 8) = piVar2[2];
        local_14._0_1_ = 5;
        *piVar2 = *piVar2 + -1;
        if (*piVar2 == 0) {
          FUN_006ba940();
        }
        local_14 = CONCAT31(local_14._1_3_,1);
        iVar9 = local_2c + 1;
      }
      uVar3 = *(uint *)(local_28 + 0x6c);
      while (uVar3 = uVar3 - 1, -1 < (int)uVar3) {
        if (*(uint *)(local_28 + 0x6c) <= uVar3) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        FUN_00517fc0(*(int *)(local_28 + 0x68) + uVar3 * 4,0x80000000);
        piVar1 = local_30;
      }
      if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
        TclFreeObj(piVar1);
      }
    }
  }
  ExceptionList = local_1c;
  return;
}

