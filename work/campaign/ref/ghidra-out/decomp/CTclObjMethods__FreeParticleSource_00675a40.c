
undefined4
CTclObjMethods__FreeParticleSource
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined8 uVar8;
  undefined4 *local_34;
  uint local_30;
  int local_2c;
  uint local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00710a25;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca74c8) &&
     (FUN_006cebf4(&DAT_00ca74c8,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca74c8 == -1)) {
    iVar4 = DAT_00783650 * 0x40;
    DAT_00ca74cc = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar4) = "TCL:CTclObjMethods::FreeParticleSource()";
    *(int *)(&DAT_00773650 + iVar4) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca74c8);
  }
  iVar4 = DAT_00ca74cc;
  uVar5 = *(undefined4 *)(&DAT_00773650 + DAT_00ca74cc * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar5;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar4 * 0x10];
  if (iVar2 == 0) {
    uVar8 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar4 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar4 * 0x10) = uVar8;
  }
  (&DAT_00773654)[iVar4 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  local_14 = FUN_005c71c0(param_4,3,1);
  if (local_14 == 0) {
    uVar5 = 1;
  }
  else {
    if (local_2c < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar7 = local_34;
      if (local_30 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_30 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar7 = local_34 + 2;
    }
    piVar1 = (int *)*puVar7;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    local_8 = CONCAT31(local_8._1_3_,3);
    if (piVar1 == (int *)0x0) {
      uVar6 = 0;
    }
    else {
      iVar2 = Tcl_GetIntFromObj(0,piVar1,&local_18);
      uVar6 = -(uint)(iVar2 != 1) & local_18;
    }
    piVar3 = *(int **)(local_14 + 0x2b0);
    if (piVar3 != (int *)0x0) {
      if (uVar6 < 0x20) {
        piVar3 = piVar3 + uVar6;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      if (*piVar3 != -1) {
        puVar7 = *(undefined4 **)(local_14 + 0x2b0);
        if (uVar6 < 0x20) {
          uVar5 = puVar7[uVar6];
          FUN_00492250();
          FUN_004957e0(uVar5);
          puVar7 = (undefined4 *)(uVar6 * 4 + *(int *)(local_14 + 0x2b0));
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          uVar5 = *puVar7;
          FUN_00492250();
          FUN_004957e0(uVar5);
          puVar7 = *(undefined4 **)(local_14 + 0x2b0);
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        *puVar7 = 0xffffffff;
      }
    }
    if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
      TclFreeObj(piVar1);
    }
    uVar5 = 0;
  }
  local_8._0_1_ = 4;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,5);
  FUN_004297b0(0);
  if (local_34 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar5;
}

