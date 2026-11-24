
undefined4
CTclObjMethods__SetPos(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  float fVar7;
  undefined8 uVar8;
  undefined4 *local_44;
  uint local_40;
  int local_3c;
  float local_2c;
  int *local_28;
  int *piStack_24;
  int *local_20;
  float local_1c;
  undefined4 local_18;
  float fStack_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0071126d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7700) &&
     (FUN_006cebf4(&DAT_00ca7700,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca7700 == -1)) {
    iVar6 = DAT_00783650 * 0x40;
    DAT_00ca7704 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar6) = "TCL:CTclObjMethods::SetPos()";
    *(int *)(&DAT_00773650 + iVar6) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7700);
  }
  iVar6 = DAT_00ca7704;
  uVar4 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7704 * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar4;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar6 * 0x10];
  if (iVar3 == 0) {
    uVar8 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar6 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar6 * 0x10) = uVar8;
  }
  (&DAT_00773654)[iVar6 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,1);
  iVar3 = FUN_005c71c0(param_4,3,1);
  if (iVar3 == 0) {
    uVar4 = 1;
  }
  else {
    if (param_3 == 3) {
      if (local_3c < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar5 = local_44;
        if (local_40 == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
      else {
        if (local_40 < 3) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar5 = local_44 + 2;
      }
      piVar1 = (int *)*puVar5;
      if (piVar1 != (int *)0x0) {
        *piVar1 = *piVar1 + 1;
      }
      local_8 = CONCAT31(local_8._1_3_,2);
      local_20 = piVar1;
      uVar4 = FUN_006bafe0(&local_2c);
      FUN_005cd7e0(uVar4);
      if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
        TclFreeObj(piVar1);
      }
    }
    else {
      if (local_3c < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar5 = local_44;
        if (local_40 == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
      else {
        if (local_40 < 3) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar5 = local_44 + 2;
      }
      piVar1 = (int *)*puVar5;
      if (piVar1 != (int *)0x0) {
        *piVar1 = *piVar1 + 1;
      }
      if (local_3c < 4) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar5 = local_44;
        if (local_40 == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
      else {
        if (local_40 < 4) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar5 = local_44 + 3;
      }
      piVar2 = (int *)*puVar5;
      if (piVar2 != (int *)0x0) {
        *piVar2 = *piVar2 + 1;
      }
      local_8 = CONCAT31(local_8._1_3_,4);
      if (piVar1 == (int *)0x0) {
        local_1c = 0.0;
      }
      else {
        iVar6 = Tcl_GetDoubleFromObj(0,piVar1,&local_28);
        if (iVar6 == 1) {
          local_1c = 0.0;
        }
        else {
          local_1c = (float)(double)CONCAT44(piStack_24,local_28);
        }
      }
      if (piVar2 == (int *)0x0) {
        local_20 = (int *)0x0;
      }
      else {
        iVar6 = Tcl_GetDoubleFromObj(0,piVar2,&local_28);
        if (iVar6 == 1) {
          local_20 = (int *)0x0;
        }
        else {
          local_20 = (int *)(float)(double)CONCAT44(piStack_24,local_28);
        }
      }
      if (param_3 == 5) {
        puVar5 = (undefined4 *)FUN_004295e0(4);
        piStack_24 = (int *)*puVar5;
        if (piStack_24 == (int *)0x0) {
          fVar7 = 0.0;
        }
        else {
          *piStack_24 = *piStack_24 + 1;
          iVar6 = Tcl_GetDoubleFromObj(0,piStack_24,&local_18);
          if (iVar6 == 1) {
            fStack_14 = 0.0;
          }
          else {
            fStack_14 = (float)(double)CONCAT44(fStack_14,local_18);
          }
          *piStack_24 = *piStack_24 + -1;
          fVar7 = fStack_14;
          if (*piStack_24 < 1) {
            TclFreeObj(piStack_24);
            fVar7 = fStack_14;
          }
        }
      }
      else {
        fVar7 = 14.0;
      }
      local_2c = local_1c;
      local_28 = local_20;
      piStack_24 = (int *)fVar7;
      if ((((*(float *)(iVar3 + 0xc) != local_1c) || (*(float *)(iVar3 + 0x10) != (float)local_20))
          || (*(float *)(iVar3 + 0x14) != fVar7)) &&
         (FUN_005cd8e0(&local_2c), *(int *)(iVar3 + 0x238) == 0)) {
        FUN_005ebc90(iVar3);
        FUN_005eb470(iVar3);
      }
      if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
        TclFreeObj(piVar2);
      }
      if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
        TclFreeObj(piVar1);
      }
    }
    uVar4 = 0;
  }
  local_8._0_1_ = 5;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,6);
  FUN_004297b0(0);
  if (local_44 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar4;
}

