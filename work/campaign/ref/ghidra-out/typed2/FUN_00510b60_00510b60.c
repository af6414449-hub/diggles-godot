
void __thiscall FUN_00510b60(ViWinInfoOpts *this)

{
  uint uVar1;
  int *piVar2;
  int *piVar3;
  ViWinInfoOpts *pVVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  undefined **ppuVar8;
  int iVar9;
  undefined4 local_48;
  int *local_44;
  undefined4 local_40;
  int *local_3c;
  int *local_38;
  int local_34;
  int *local_30;
  int local_2c;
  ViWinInfoOpts *local_28;
  undefined1 local_21;
  undefined1 *puStack_20;
  void *local_1c;
  undefined1 *puStack_18;
  undefined4 local_14;
  
  puStack_20 = &stack0xfffffffc;
  local_14 = 0xffffffff;
  puStack_18 = &LAB_0070175d;
  local_1c = ExceptionList;
  ExceptionList = &local_1c;
  local_21 = 1;
  local_28 = this;
  piVar5 = (int *)FUN_006ba810(0x19,this,DAT_0076700c ^ (uint)&stack0xfffffff0);
  piVar5[1] = 0x14;
  piVar5[2] = -1;
  *piVar5 = 0;
  *(undefined1 *)(piVar5 + 3) = 0;
  piVar5[3] = 0x6f666e49;
  piVar5[4] = 0x7374704f;
  *(undefined1 *)(piVar5 + 5) = 0;
  piVar5[2] = 8;
  if (piVar5 != (int *)0x0) {
    *piVar5 = *piVar5 + 1;
  }
  FUN_0050e8e0();
  local_48 = 0x11d;
  local_44 = (int *)0x78;
  local_40 = 10;
  local_3c = (int *)0x3c;
  iVar6 = FUN_00517d80(&local_48);
  this->i_48 = iVar6;
  local_48 = 0x11d;
  local_44 = (int *)0x19;
  local_40 = 10;
  local_3c = (int *)0x1e;
  iVar6 = FUN_0054c770(&local_48,&PTR_0071ce50);
  this->i_4c = iVar6;
  piVar5 = (int *)FUN_006ba810(0x19);
  piVar5[1] = 4;
  piVar5[2] = -1;
  *piVar5 = 0;
  piVar5[3] = 0x746553;
  piVar5[2] = 3;
  if (piVar5 != (int *)0x0) {
    *piVar5 = *piVar5 + 1;
  }
  local_48 = 0xf;
  local_44 = (int *)0xbb;
  iVar6 = FUN_00526f80(&DAT_00767988);
  this->i_50 = iVar6;
  piVar5 = (int *)FUN_006ba810(0x19);
  piVar5[1] = 4;
  piVar5[2] = -1;
  *piVar5 = 0;
  piVar5[3] = 0x6c6544;
  piVar5[2] = 3;
  if (piVar5 != (int *)0x0) {
    *piVar5 = *piVar5 + 1;
  }
  local_48 = 0x41;
  local_44 = (int *)0xbb;
  iVar6 = FUN_00526f80(&DAT_00767988);
  this->i_54 = iVar6;
  piVar5 = (int *)FUN_006ba810(0x19);
  piVar5[1] = 0x14;
  piVar5[2] = -1;
  *piVar5 = 0;
  *(undefined1 *)(piVar5 + 3) = 0;
  piVar5[3] = 0x79706f43;
  *(undefined1 *)(piVar5 + 4) = 0;
  piVar5[2] = 4;
  if (piVar5 != (int *)0x0) {
    *piVar5 = *piVar5 + 1;
  }
  local_48 = 0x7d;
  local_44 = (int *)0xbb;
  iVar6 = FUN_00526f80(&DAT_00767988);
  this->i_58 = iVar6;
  piVar5 = (int *)FUN_006ba810(0x19);
  piVar5[1] = 0x14;
  piVar5[2] = -1;
  *piVar5 = 0;
  *(undefined1 *)(piVar5 + 3) = 0;
  piVar5[3] = 0x74736150;
  *(undefined2 *)(piVar5 + 4) = 0x65;
  piVar5[2] = 5;
  if (piVar5 != (int *)0x0) {
    *piVar5 = *piVar5 + 1;
  }
  local_48 = 0xcd;
  local_44 = (int *)&DAT_000000bb;
  iVar6 = FUN_00526f80(&DAT_00767988);
  this->i_5c = iVar6;
  this->i_60 = 0;
  FUN_00518020();
  if (this->i_60 != 0) {
    piVar5 = (int *)FUN_006ba810(0x19);
    piVar5[1] = 0x14;
    piVar5[2] = -1;
    *piVar5 = 0;
    *(undefined1 *)(piVar5 + 3) = 0;
    piVar5[3] = 0x74696445;
    piVar5[4] = 0x535f726f;
    piVar5[5] = 0x495f7465;
    piVar5[6] = 0x6f666e;
    piVar5[2] = 0xf;
    *piVar5 = 1;
    local_30 = piVar5;
    local_30 = (int *)FUN_00601d30(&local_30);
    local_14 = 0;
    *piVar5 = *piVar5 + -1;
    if (*piVar5 == 0) {
      FUN_006ba940();
    }
    local_14 = 0xffffffff;
    if (local_30 != (int *)0xffffffff) {
      FUN_00444ea0(0);
      piVar5 = (int *)Tcl_NewStringObj("info_string",0xffffffff);
      *piVar5 = *piVar5 + 1;
      iVar6 = *(int *)(this->i_60 + 0xc0);
      if (iVar6 == 0) {
        local_30 = (int *)0x0;
      }
      else {
        local_30 = (int *)Tcl_ObjGetVar2(iVar6,piVar5,0,0);
        if (local_30 != (int *)0x0) {
          *local_30 = *local_30 + 1;
        }
      }
      piVar2 = local_30;
      local_14 = 1;
      *piVar5 = *piVar5 + -1;
      if (*piVar5 < 1) {
        TclFreeObj(piVar5);
      }
      iVar6 = 0;
      while( true ) {
        local_2c = iVar6;
        if (piVar2 == (int *)0x0) {
          iVar9 = 0;
        }
        else {
          iVar7 = Tcl_ListObjLength(0,piVar2,&local_34);
          iVar9 = local_34;
          if (iVar7 != 0) {
            iVar9 = 0;
          }
        }
        pVVar4 = local_28;
        if (iVar9 <= iVar6) break;
        if ((piVar2 == (int *)0x0) ||
           (iVar6 = Tcl_ListObjIndex(0,piVar2,iVar6,&local_38), iVar6 != 0)) {
          local_3c = (int *)0x0;
        }
        else {
          local_3c = local_38;
          if (local_38 != (int *)0x0) {
            *local_38 = *local_38 + 1;
          }
        }
        piVar5 = local_3c;
        local_14._0_1_ = 2;
        if (local_3c == (int *)0x0) {
          ppuVar8 = &PTR_0071ce50;
        }
        else {
          ppuVar8 = (undefined **)Tcl_GetStringFromObj(local_3c,0);
        }
        FUN_006b8fb0(ppuVar8);
        local_14 = CONCAT31(local_14._1_3_,4);
        if ((piVar5 != (int *)0x0) && (*piVar5 = *piVar5 + -1, *piVar5 < 1)) {
          TclFreeObj(piVar5);
        }
        pVVar4 = local_28;
        FUN_00444ca0(1);
        uVar1 = pVVar4->i_6c;
        local_3c = (int *)(uVar1 - 1);
        if (uVar1 <= local_3c) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        piVar3 = local_44;
        local_3c = (int *)(pVVar4->i_68 + (int)local_3c * 4);
        piVar5 = (int *)*local_3c;
        *local_3c = (int)local_44;
        if (local_44 != (int *)0x0) {
          *local_44 = *local_44 + 1;
        }
        if ((piVar5 != (int *)0x0) && (*piVar5 = *piVar5 + -1, *piVar5 == 0)) {
          FUN_006ba940();
        }
        *(int *)(*local_3c + 8) = piVar3[2];
        local_14._0_1_ = 5;
        *piVar3 = *piVar3 + -1;
        if (*piVar3 == 0) {
          FUN_006ba940();
        }
        local_14 = CONCAT31(local_14._1_3_,1);
        iVar6 = local_2c + 1;
      }
      uVar1 = local_28->i_6c;
      while (uVar1 = uVar1 - 1, -1 < (int)uVar1) {
        if ((uint)pVVar4->i_6c <= uVar1) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        FUN_00517fc0(pVVar4->i_68 + uVar1 * 4,0x80000000);
        piVar2 = local_30;
      }
      if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
        TclFreeObj(piVar2);
      }
    }
  }
  ExceptionList = local_1c;
  return;
}

