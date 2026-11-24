
undefined4
CTclObjMethods__SetProdEnabled
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  bool bVar6;
  undefined8 uVar7;
  int local_34;
  int *local_24;
  uint local_20;
  int local_1c;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070a9ed;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca79e0) &&
     (FUN_006cebf4(&DAT_00ca79e0,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar1 = DAT_00783650,
     DAT_00ca79e0 == -1)) {
    iVar3 = DAT_00783650 * 0x40;
    DAT_00ca79e4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar3) = "TCL:CTclObjMethods::SetProdEnabled()";
    *(int *)(&DAT_00773650 + iVar3) = iVar1;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca79e0);
  }
  iVar3 = DAT_00ca79e4;
  uVar5 = *(undefined4 *)(&DAT_00773650 + DAT_00ca79e4 * 0x40);
  iVar1 = FUN_0043fcc0();
  *(undefined4 *)(iVar1 + *(int *)(iVar1 + 0x8000) * 4) = uVar5;
  *(int *)(iVar1 + 0x8000) = *(int *)(iVar1 + 0x8000) + 1;
  iVar1 = (&DAT_00773654)[iVar3 * 0x10];
  if (iVar1 == 0) {
    uVar7 = FUN_006bd180();
    iVar1 = (&DAT_00773654)[iVar3 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar3 * 0x10) = uVar7;
  }
  (&DAT_00773654)[iVar3 * 0x10] = iVar1 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  iVar1 = FUN_005c71c0(param_4,3,1);
  if (iVar1 != 0) {
    iVar3 = *(int *)(iVar1 + 0xe8);
    if ((((iVar3 == 5) || (iVar3 == 6)) || (iVar3 == 10)) || (iVar3 == 7)) {
      if (*(int *)(iVar1 + 0x3e0) != 0) {
        if (local_1c < 3) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          piVar4 = local_24;
          if (local_20 == 0) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
        }
        else {
          if (local_20 < 3) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          piVar4 = local_24 + 2;
        }
        if (*piVar4 == 0) {
          bVar6 = false;
        }
        else {
          iVar3 = Tcl_GetBooleanFromObj(0,*piVar4,&local_14);
          if (iVar3 == 1) {
            bVar6 = false;
          }
          else {
            bVar6 = local_14 != 0;
          }
        }
        *(bool *)(*(int *)(iVar1 + 0x3e0) + 100) = bVar6;
        piVar4 = (int *)Tcl_NewBooleanObj(*(undefined1 *)(*(int *)(iVar1 + 0x3e0) + 100));
        *piVar4 = *piVar4 + 1;
        iVar1 = *piVar4;
        if (local_34 != 0) {
          Tcl_SetObjResult(local_34,piVar4);
          iVar1 = *piVar4;
        }
        *piVar4 = iVar1 + -1;
        if (iVar1 + -1 < 1) {
          TclFreeObj(piVar4);
        }
      }
      uVar5 = 0;
      goto LAB_006951c7;
    }
    puVar2 = (undefined4 *)FUN_004295e0(1);
    piVar4 = (int *)*puVar2;
    if (piVar4 != (int *)0x0) {
      *piVar4 = *piVar4 + 1;
    }
    FUN_006bc6a0("object type is not production or energy or protection",piVar4);
  }
  uVar5 = 1;
LAB_006951c7:
  local_8._0_1_ = 3;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004297b0(0);
  if (local_24 != (int *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar5;
}

