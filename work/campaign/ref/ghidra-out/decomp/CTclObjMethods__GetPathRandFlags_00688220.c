
undefined4
CTclObjMethods__GetPathRandFlags
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  float fVar5;
  double dVar6;
  float fVar7;
  float fVar8;
  undefined8 uVar9;
  int local_38;
  int local_28;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0071162d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca77d8) &&
     (FUN_006cebf4(&DAT_00ca77d8,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar1 = DAT_00783650,
     DAT_00ca77d8 == -1)) {
    iVar2 = DAT_00783650 * 0x40;
    DAT_00ca77dc = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar2) = "TCL:CTclObjMethods::GetPathRandFlags()";
    *(int *)(&DAT_00773650 + iVar2) = iVar1;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca77d8);
  }
  iVar2 = DAT_00ca77dc;
  uVar4 = *(undefined4 *)(&DAT_00773650 + DAT_00ca77dc * 0x40);
  iVar1 = FUN_0043fcc0();
  *(undefined4 *)(iVar1 + *(int *)(iVar1 + 0x8000) * 4) = uVar4;
  *(int *)(iVar1 + 0x8000) = *(int *)(iVar1 + 0x8000) + 1;
  iVar1 = (&DAT_00773654)[iVar2 * 0x10];
  if (iVar1 == 0) {
    uVar9 = FUN_006bd180();
    iVar1 = (&DAT_00773654)[iVar2 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar2 * 0x10) = uVar9;
  }
  (&DAT_00773654)[iVar2 * 0x10] = iVar1 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  iVar1 = FUN_005c71c0(param_4,3,1);
  if ((iVar1 == 0) || (iVar2 = FUN_005c71c0(param_4,3,2), iVar2 == 0)) {
    uVar4 = 1;
  }
  else {
    uVar4 = 0x457;
    fVar7 = *(float *)(iVar1 + 0x10) - *(float *)(iVar2 + 0x10);
    fVar8 = *(float *)(iVar1 + 0xc) - *(float *)(iVar2 + 0xc);
    fVar5 = fVar7 * fVar7 + fVar8 * fVar8;
    FUN_0040b7e0();
    if (fVar5 != 0.0) {
      dVar6 = (double)(fVar8 / fVar5);
      FUN_006f52d0();
      fVar5 = (float)dVar6;
      if (fVar7 <= 0.0) {
        fVar5 = -fVar5;
      }
      fVar5 = fVar5 + 0.7853982;
      if (fVar5 < 0.0) {
        fVar5 = fVar5 + 6.2831855;
      }
      fVar5 = fVar5 / 1.5707964;
      if (fVar5 < 1.0) {
        uVar4 = 0x44d;
      }
      else if (fVar5 < 2.0) {
        uVar4 = 0x3f3;
      }
      if ((2.0 <= fVar5) && (fVar5 < 3.0)) {
        uVar4 = 0x49;
      }
      if (3.0 <= fVar5) {
        uVar4 = 0x456;
      }
    }
    piVar3 = (int *)Tcl_NewIntObj(uVar4);
    *piVar3 = *piVar3 + 1;
    iVar1 = *piVar3;
    if (local_38 != 0) {
      Tcl_SetObjResult(local_38,piVar3);
      iVar1 = *piVar3;
    }
    *piVar3 = iVar1 + -1;
    if (iVar1 + -1 < 1) {
      TclFreeObj(piVar3);
    }
    uVar4 = 0;
  }
  local_8._0_1_ = 3;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004297b0(0);
  if (local_28 != 0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar4;
}

