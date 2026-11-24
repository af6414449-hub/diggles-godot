
void FUN_0066a4f0(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  float fVar7;
  undefined4 uVar8;
  float fVar9;
  uint uVar10;
  float *pfVar11;
  uint local_5c;
  uint local_58;
  uint local_54;
  float local_50;
  uint uStack_4c;
  int *piStack_48;
  uint uStack_44;
  uint local_40;
  float local_3c;
  uint local_38;
  uint local_34;
  int *local_30;
  int *local_2c;
  uint local_28;
  undefined4 *local_24;
  uint local_20;
  int local_1c;
  float local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070fb65;
  local_10 = ExceptionList;
  uVar2 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar2;
  FUN_006bc170(param_2);
  local_8 = 0;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (param_3 == 5) {
    if (local_1c < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_24;
      if (local_20 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar6 = local_24;
      }
    }
    else {
      if (local_20 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar6 = local_24 + 1;
    }
    piVar5 = (int *)*puVar6;
    if (piVar5 == (int *)0x0) {
      local_3c = 0.0;
      local_18 = 0.0;
    }
    else {
      *piVar5 = *piVar5 + 1;
      iVar3 = Tcl_GetIntFromObj(0,piVar5,&local_54,uVar2);
      *piVar5 = *piVar5 + -1;
      local_3c = (float)(-(uint)(iVar3 != 1) & local_54);
      local_18 = local_3c;
      if (*piVar5 < 1) {
        TclFreeObj(piVar5);
      }
    }
    if (local_1c < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_24;
      if (local_20 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar6 = local_24;
      }
    }
    else {
      if (local_20 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar6 = local_24 + 2;
    }
    piVar5 = (int *)*puVar6;
    if (piVar5 == (int *)0x0) {
      local_40 = 0;
      local_28 = 0;
    }
    else {
      *piVar5 = *piVar5 + 1;
      iVar3 = Tcl_GetIntFromObj(0,piVar5,&local_58);
      *piVar5 = *piVar5 + -1;
      local_40 = -(uint)(iVar3 != 1) & local_58;
      local_28 = local_40;
      if (*piVar5 < 1) {
        TclFreeObj(piVar5);
      }
    }
    if (local_1c < 4) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_24;
      if (local_20 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar6 = local_24;
      }
    }
    else {
      if (local_20 < 4) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar6 = local_24 + 3;
    }
    piVar5 = (int *)*puVar6;
    if (piVar5 == (int *)0x0) {
      local_2c = (int *)0x0;
      local_30 = (int *)0x0;
    }
    else {
      *piVar5 = *piVar5 + 1;
      iVar3 = Tcl_GetIntFromObj(0,piVar5,&local_5c);
      *piVar5 = *piVar5 + -1;
      local_30 = (int *)(-(uint)(iVar3 != 1) & local_5c);
      local_2c = local_30;
      if (*piVar5 < 1) {
        TclFreeObj(piVar5);
      }
    }
    if (local_1c < 5) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_24;
      if (local_20 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar6 = local_24;
      }
    }
    else {
      if (local_20 < 5) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar6 = local_24 + 4;
    }
    piVar5 = (int *)*puVar6;
    if (piVar5 == (int *)0x0) {
      local_38 = 0;
      local_34 = 0;
    }
    else {
      *piVar5 = *piVar5 + 1;
      iVar3 = Tcl_GetIntFromObj(0,piVar5,&local_38);
      *piVar5 = *piVar5 + -1;
      local_38 = -(uint)(iVar3 != 1) & local_38;
      local_34 = local_38;
      if (*piVar5 < 1) {
        TclFreeObj(piVar5);
      }
    }
    fVar7 = local_18;
    if ((int)local_3c < PTR_0077241c->cellX0) {
      fVar7 = (float)PTR_0077241c->cellX0;
    }
    uStack_4c = local_28;
    if ((int)local_40 < PTR_0077241c->cellY0) {
      uStack_4c = PTR_0077241c->cellY0;
    }
    piStack_48 = local_30;
    if (PTR_0077241c->cellX1 < (int)local_2c) {
      piStack_48 = (int *)PTR_0077241c->cellX1;
    }
    uStack_44 = local_34;
    if (PTR_0077241c->cellY1 < (int)local_38) {
      uStack_44 = PTR_0077241c->cellY1;
    }
    iVar4 = uStack_4c << 3;
    iVar3 = (int)piStack_48 * 8;
    iVar1 = uStack_44 * 8;
    local_50 = fVar7;
    local_34 = uStack_44;
    local_30 = piStack_48;
    local_28 = uStack_4c;
    local_18 = fVar7;
    FUN_005d57e0(&PTR_0077241c->cellX0,8,fVar7,uStack_4c,piStack_48,uStack_44);
    FUN_005a3dd0();
    FUN_005a77a0((int)fVar7 * 8,iVar4,iVar3,iVar1,0);
    fVar9 = local_50;
    uVar2 = uStack_4c;
    piVar5 = piStack_48;
    uVar10 = uStack_44;
    FUN_005a9090(local_50,uStack_4c,piStack_48,uStack_44);
    FUN_006c2340(fVar9,uVar2,piVar5,uVar10);
    pfVar11 = &local_50;
    FUN_0057d980(pfVar11);
    FUN_0057d580(pfVar11);
    FUN_00580ae0(&local_50);
    uVar8 = 0;
    fVar9 = local_50;
    uVar2 = uStack_4c;
    piVar5 = piStack_48;
    uVar10 = uStack_44;
    FUN_00592d70(0,local_50,uStack_4c,piStack_48,uStack_44);
    FUN_00592840(uVar8,fVar9,uVar2,piVar5,uVar10);
    uVar8 = 0;
    fVar9 = local_50;
    uVar2 = uStack_4c;
    piVar5 = piStack_48;
    uVar10 = uStack_44;
    FUN_00492250(0,local_50,uStack_4c,piStack_48,uStack_44);
    FUN_0049bb70(uVar8,fVar9,uVar2,piVar5,uVar10);
    uVar2 = 0;
    local_38 = DAT_0076a338;
    if (0 < *(int *)(DAT_0076a338 + 0x286c)) {
      piVar5 = (int *)(DAT_0076a338 + 0x2868);
      fVar7 = (float)(int)fVar7;
      iVar3 = 0;
      local_2c = piVar5;
      local_18 = fVar7;
      do {
        if ((uint)piVar5[1] <= uVar2) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          piVar5 = local_2c;
          fVar7 = local_18;
        }
        fVar9 = *(float *)(*piVar5 + iVar3);
        if ((((fVar7 <= fVar9) && (fVar7 = local_18, fVar9 <= (float)(int)local_30)) &&
            (fVar9 = *(float *)(*piVar5 + 4 + iVar3), (float)(int)local_28 <= fVar9)) &&
           (fVar9 <= (float)(int)local_34)) {
          FUN_0047d810(uVar2);
          uVar2 = uVar2 - 1;
          iVar3 = iVar3 + -0x20;
          piVar5 = local_2c;
          fVar7 = local_18;
        }
        uVar2 = uVar2 + 1;
        iVar3 = iVar3 + 0x20;
      } while ((int)uVar2 < *(int *)(local_38 + 0x286c));
    }
  }
  else {
    FUN_006bc8f0(4);
  }
  local_8._0_1_ = 2;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_004297b0(0);
  if (local_24 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

