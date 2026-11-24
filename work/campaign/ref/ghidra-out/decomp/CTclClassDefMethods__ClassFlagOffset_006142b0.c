
undefined4
CTclClassDefMethods__ClassFlagOffset
          (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  float fVar5;
  undefined8 uVar6;
  int *local_28;
  uint local_24;
  int local_20;
  double local_1c;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070a85d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6ba0) &&
     (FUN_006cebf4(&DAT_00ca6ba0,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar1 = DAT_00783650,
     DAT_00ca6ba0 == -1)) {
    iVar3 = DAT_00783650 * 0x40;
    DAT_00ca6ba4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar3) = "TCL:CTclClassDefMethods::ClassFlagOffset()";
    *(int *)(&DAT_00773650 + iVar3) = iVar1;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6ba0);
  }
  iVar3 = DAT_00ca6ba4;
  local_14 = &DAT_00ca6ba4;
  uVar4 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6ba4 * 0x40);
  iVar1 = FUN_0043fcc0();
  *(undefined4 *)(iVar1 + *(int *)(iVar1 + 0x8000) * 4) = uVar4;
  *(int *)(iVar1 + 0x8000) = *(int *)(iVar1 + 0x8000) + 1;
  iVar1 = (&DAT_00773654)[iVar3 * 0x10];
  if (iVar1 == 0) {
    uVar6 = FUN_006bd180();
    iVar1 = (&DAT_00773654)[iVar3 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar3 * 0x10) = uVar6;
  }
  (&DAT_00773654)[iVar3 * 0x10] = iVar1 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  iVar1 = DAT_00772440;
  local_8 = CONCAT31(local_8._1_3_,2);
  if (*(int *)(DAT_00772440 + 4) == 0) {
    FUN_006bc6a0("no class defined.",0);
    uVar4 = 1;
  }
  else if (param_3 == 2) {
    if (local_20 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar2 = local_28;
      if (local_24 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_24 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      piVar2 = local_28 + 1;
    }
    if (*piVar2 == 0) {
      fVar5 = 0.0;
    }
    else {
      iVar3 = Tcl_GetDoubleFromObj(0,*piVar2,&local_1c);
      if (iVar3 == 1) {
        fVar5 = 0.0;
      }
      else {
        fVar5 = (float)local_1c;
      }
    }
    uVar4 = 0;
    *(float *)(*(int *)(iVar1 + 4) + 0xcf8) = fVar5;
  }
  else {
    FUN_006bc8f0(1);
    uVar4 = 1;
  }
  local_8._0_1_ = 3;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004297b0(0);
  if (local_28 != (int *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar4;
}

