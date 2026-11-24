
undefined4
CTclObjMethods__SetCameraFollow
          (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  float fVar8;
  undefined8 uVar9;
  undefined4 *local_28;
  uint local_24;
  int local_20;
  undefined4 local_18;
  float fStack_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070c3dd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7a70) &&
     (FUN_006cebf4(&DAT_00ca7a70,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca7a70 == -1)) {
    iVar3 = DAT_00783650 * 0x40;
    DAT_00ca7a74 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar3) = "TCL:CTclObjMethods::SetCameraFollow()";
    *(int *)(&DAT_00773650 + iVar3) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7a70);
  }
  iVar3 = DAT_00ca7a74;
  uVar7 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7a74 * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar7;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar3 * 0x10];
  if (iVar2 == 0) {
    uVar9 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar3 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar3 * 0x10) = uVar9;
  }
  (&DAT_00773654)[iVar3 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (local_20 < 2) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar6 = local_28;
    if (local_24 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_24 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar6 = local_28 + 1;
  }
  piVar1 = (int *)*puVar6;
  if (piVar1 == (int *)0x0) {
LAB_006986e1:
    fStack_14 = 0.0;
    if (param_3 == 3) {
      if (local_20 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar6 = local_28;
        if (local_24 == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
      else {
        if (local_24 < 3) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar6 = local_28 + 2;
      }
      piVar1 = (int *)*puVar6;
      if (piVar1 == (int *)0x0) {
        fStack_14 = 0.0;
      }
      else {
        *piVar1 = *piVar1 + 1;
        iVar2 = Tcl_GetDoubleFromObj(0,piVar1,&local_18);
        if (iVar2 == 1) {
          fStack_14 = 0.0;
        }
        else {
          fStack_14 = (float)(double)CONCAT44(fStack_14,local_18);
        }
        *piVar1 = *piVar1 + -1;
        if (*piVar1 < 1) {
          TclFreeObj(piVar1);
        }
      }
    }
    iVar3 = FUN_005c71c0(param_4,2,1);
    iVar2 = DAT_00772400;
    if (iVar3 == 0) {
      uVar7 = 1;
      goto LAB_006987e7;
    }
    iVar4 = *(int *)(DAT_00772400 + 0x5a4);
    *(undefined4 *)(DAT_00772400 + 0xa0d4) = *(undefined4 *)(iVar3 + 0xdc);
    if (0.0 < fStack_14) {
      fVar8 = 2.5;
      if (fStack_14 <= 2.5) {
        fVar8 = fStack_14;
      }
      *(float *)(iVar4 + 0x15c) = fVar8;
      iVar4 = *(int *)(iVar2 + 0x5a4);
    }
    *(undefined1 *)(iVar4 + 0x140) = 0;
  }
  else {
    *piVar1 = *piVar1 + 1;
    iVar2 = Tcl_GetIntFromObj(0,piVar1,&fStack_14);
    *piVar1 = *piVar1 + -1;
    uVar5 = -(uint)(iVar2 != 1) & (uint)fStack_14;
    if (*piVar1 < 1) {
      TclFreeObj(piVar1);
    }
    if (uVar5 != 0xffffffff) goto LAB_006986e1;
    *(undefined4 *)(DAT_00772400 + 0xa0d4) = 0xffffffff;
  }
  uVar7 = 0;
LAB_006987e7:
  local_8._0_1_ = 3;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004297b0(0);
  if (local_28 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar7;
}

