
undefined4
CTclObjMethods__SetLock(undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  code *pcVar9;
  bool bVar10;
  undefined8 uVar11;
  int *piVar12;
  undefined4 *local_24;
  uint local_20;
  int local_1c;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070b745;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca75e8) &&
     (FUN_006cebf4(&DAT_00ca75e8,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar4 = DAT_00783650,
     DAT_00ca75e8 == -1)) {
    iVar7 = DAT_00783650 * 0x40;
    DAT_00ca75ec = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar7) = "TCL:CTclObjMethods::SetLock()";
    *(int *)(&DAT_00773650 + iVar7) = iVar4;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca75e8);
  }
  iVar7 = DAT_00ca75ec;
  uVar8 = *(undefined4 *)(&DAT_00773650 + DAT_00ca75ec * 0x40);
  iVar4 = FUN_0043fcc0();
  *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar8;
  *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
  iVar4 = (&DAT_00773654)[iVar7 * 0x10];
  if (iVar4 == 0) {
    uVar11 = FUN_006bd180();
    iVar4 = (&DAT_00773654)[iVar7 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar7 * 0x10) = uVar11;
  }
  uVar8 = param_4;
  piVar1 = param_3;
  (&DAT_00773654)[iVar7 * 0x10] = iVar4 + 1;
  local_8 = 0;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 1;
  FUN_006bc170(param_2);
  local_8._0_1_ = 2;
  if (piVar1 != (int *)0x3) {
    FUN_006bc8f0(2);
    uVar8 = 1;
    goto LAB_0067e135;
  }
  if (*(char *)(DAT_00772400 + 0x91) == '\0') {
    iVar4 = *(int *)(DAT_00772400 + 0xa3f8);
    if (-1 < iVar4) {
      iVar7 = DAT_00768388;
      if (*(char *)(DAT_00772400 + 0x590) != '\0') {
        iVar7 = 2;
      }
      if (iVar7 < 2 - iVar4) {
        if (iVar4 == 0) {
          puVar5 = (undefined4 *)FUN_004295e0(2);
          local_14 = (int *)*puVar5;
          if (local_14 != (int *)0x0) {
            *local_14 = *local_14 + 1;
          }
          puVar5 = (undefined4 *)FUN_004295e0(1);
          param_3 = (int *)*puVar5;
          if (param_3 != (int *)0x0) {
            *param_3 = *param_3 + 1;
          }
          uVar6 = FUN_006baf10();
          uVar6 = uVar6 & 0xff;
          uVar8 = FUN_006baee0(uVar6);
LAB_0067dfbb:
          cVar3 = FUN_005d75d0(uVar8,uVar6);
          FUN_006bad60();
          FUN_006bad60();
          if (cVar3 != '\0') goto LAB_0067e133;
        }
        else if (iVar4 == 1) {
          puVar5 = (undefined4 *)FUN_004295e0(2);
          local_14 = (int *)*puVar5;
          if (local_14 != (int *)0x0) {
            *local_14 = *local_14 + 1;
          }
          puVar5 = (undefined4 *)FUN_004295e0(1);
          param_3 = (int *)*puVar5;
          if (param_3 != (int *)0x0) {
            *param_3 = *param_3 + 1;
          }
          uVar6 = FUN_006baf10();
          uVar6 = uVar6 & 0xff;
          uVar8 = FUN_006baee0(uVar6);
          goto LAB_0067dfbb;
        }
        puVar5 = (undefined4 *)FUN_004295e0(1);
        piVar1 = (int *)*puVar5;
        if (piVar1 != (int *)0x0) {
          *piVar1 = *piVar1 + 1;
        }
        FUN_006bc6a0("invalid object",piVar1);
        uVar8 = 1;
        goto LAB_0067e135;
      }
    }
    iVar4 = FUN_005c71c0(uVar8,3,1);
    if (iVar4 == 0) {
      uVar8 = 1;
      goto LAB_0067e135;
    }
    iVar7 = iVar4;
    FUN_005ebc90(iVar4);
    FUN_005eb470(iVar7);
    puVar5 = (undefined4 *)FUN_004295e0(2);
    piVar1 = (int *)*puVar5;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    local_8._0_1_ = 3;
    param_3 = piVar1;
    cVar3 = FUN_006baf10();
    uVar6 = *(uint *)(iVar4 + 0x3d0) & 0x4000;
    if (cVar3 == '\0') {
      if (uVar6 != 0) {
        *(undefined1 *)(iVar4 + 0x3b4) = 1;
      }
      FUN_005dc6a0(uVar6);
      *(uint *)(iVar4 + 0x3d0) = *(uint *)(iVar4 + 0x3d0) & 0xffffbfff;
      if (*(int *)(iVar4 + 0x3e0) != 0) {
        *(undefined1 *)(*(int *)(iVar4 + 0x3e0) + 0x3d) = 0;
        *(undefined1 *)(*(int *)(iVar4 + 0x3e0) + 0x2b) = 0;
        *(undefined1 *)(*(int *)(iVar4 + 0x3e0) + 0x28) = 0;
      }
    }
    else {
      if (uVar6 == 0) {
        *(undefined1 *)(iVar4 + 0x3b4) = 1;
      }
      FUN_005dc6a0(uVar6);
      FUN_005dc780(iVar4,*(int *)(*(int *)(iVar4 + 0xd4) + 0xc) + 0xc);
      *(uint *)(iVar4 + 0x3d0) = *(uint *)(iVar4 + 0x3d0) & 0xffbfffff | 0x4000;
      if (*(int *)(iVar4 + 0x3e0) != 0) {
        *(undefined1 *)(*(int *)(iVar4 + 0x3e0) + 0x3d) = 0;
        *(undefined1 *)(*(int *)(iVar4 + 0x3e0) + 0x2c) = 0;
        *(undefined1 *)(*(int *)(iVar4 + 0x3e0) + 0x29) = 0;
      }
    }
    if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
      TclFreeObj(piVar1);
    }
  }
  else {
    if (local_1c < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar5 = local_24;
      if (local_20 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_20 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar5 = local_24 + 2;
    }
    piVar1 = (int *)*puVar5;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    if (local_1c < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar5 = local_24;
      if (local_20 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_20 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar5 = local_24 + 1;
    }
    piVar2 = (int *)*puVar5;
    if (piVar2 != (int *)0x0) {
      *piVar2 = *piVar2 + 1;
    }
    if (piVar1 == (int *)0x0) {
      bVar10 = false;
    }
    else {
      iVar4 = Tcl_GetBooleanFromObj(0,piVar1,&param_3);
      if (iVar4 == 1) {
        bVar10 = false;
      }
      else {
        bVar10 = param_3 != (int *)0x0;
      }
    }
    if (piVar2 == (int *)0x0) {
      cVar3 = FUN_005d75d0(0,bVar10);
      bVar10 = cVar3 == '\0';
      pcVar9 = TclFreeObj_exref;
    }
    else {
      iVar4 = Tcl_GetIntFromObj(0,piVar2,&local_14);
      piVar12 = local_14;
      if (iVar4 == 1) {
        piVar12 = (int *)0x0;
      }
      cVar3 = FUN_005d75d0(piVar12,bVar10);
      bVar10 = cVar3 == '\0';
      *piVar2 = *piVar2 + -1;
      pcVar9 = TclFreeObj_exref;
      if (*piVar2 < 1) {
        TclFreeObj(piVar2);
      }
    }
    if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
      (*pcVar9)(piVar1);
    }
    if (bVar10) {
      puVar5 = (undefined4 *)FUN_004295e0(1);
      piVar1 = (int *)*puVar5;
      if (piVar1 != (int *)0x0) {
        *piVar1 = *piVar1 + 1;
      }
      FUN_006bc6a0("invalid object",piVar1);
      uVar8 = 1;
      goto LAB_0067e135;
    }
  }
LAB_0067e133:
  uVar8 = 0;
LAB_0067e135:
  FUN_006bc0d0();
  local_8._0_1_ = 4;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,5);
  FUN_004297b0(0);
  if (local_24 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar8;
}

