
undefined4
CTclObjMethods__InfoEndProd
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  undefined8 uVar9;
  undefined4 *local_24;
  uint local_20;
  int local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070a7dd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7b78) &&
     (FUN_006cebf4(&DAT_00ca7b78,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca7b78 == -1)) {
    iVar3 = DAT_00783650 * 0x40;
    DAT_00ca7b7c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar3) = "TCL:CTclObjMethods::InfoEndProd()";
    *(int *)(&DAT_00773650 + iVar3) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7b78);
  }
  iVar3 = DAT_00ca7b7c;
  uVar7 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7b7c * 0x40);
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
  iVar2 = FUN_005c71c0(param_4,2,1);
  if (iVar2 != 0) {
    iVar2 = *(int *)(iVar2 + 0x3e0);
    if (iVar2 != 0) {
      *(int *)(iVar2 + 4) = *(int *)(iVar2 + 4) + -1;
      if (*(int *)(iVar2 + 0x48) != -1) {
        iVar3 = *(int *)(iVar2 + 0x10);
        uVar8 = 0;
        if (0 < iVar3) {
          iVar6 = 0;
          do {
            if (*(uint *)(iVar2 + 0x10) <= uVar8) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            iVar5 = *(int *)(iVar2 + 0xc);
            if (*(int *)(iVar6 + 8 + iVar5) != 0) {
              if (*(uint *)(iVar2 + 0x10) <= uVar8) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                iVar5 = *(int *)(iVar2 + 0xc);
              }
              if (*(int *)(iVar2 + 0x48) == *(int *)(*(int *)(iVar6 + 8 + iVar5) + 8)) {
                if (*(uint *)(iVar2 + 0x10) <= uVar8) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  iVar5 = *(int *)(iVar2 + 0xc);
                }
                if (*(int *)(iVar5 + 0x10 + uVar8 * 0x1c) == 10) {
                  if (*(uint *)(iVar2 + 0x10) <= uVar8) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    iVar5 = *(int *)(iVar2 + 0xc);
                  }
                  *(float *)(iVar5 + 0x14 + uVar8 * 0x1c) =
                       *(float *)(iVar5 + 0x14 + uVar8 * 0x1c) * 0.1;
                }
                else {
                  FUN_005edc10(uVar8);
                  if (*(uint *)(iVar2 + 0x10) <= uVar8) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  }
                  *(float *)(*(int *)(iVar2 + 0xc) + 0x14 + uVar8 * 0x1c) =
                       *(float *)(*(int *)(iVar2 + 0xc) + 0x14 + uVar8 * 0x1c) * 0.2;
                }
                break;
              }
            }
            uVar8 = uVar8 + 1;
            iVar6 = iVar6 + 0x1c;
          } while ((int)uVar8 < iVar3);
        }
      }
      *(undefined4 *)(iVar2 + 0x48) = 0xffffffff;
      *(undefined4 *)(iVar2 + 0x4c) = 0;
      *(undefined4 *)(iVar2 + 0x50) = 0;
      uVar7 = 0;
      goto LAB_0069e35c;
    }
    if (local_1c < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar4 = local_24;
      if (local_20 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_20 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar4 = local_24 + 1;
    }
    piVar1 = (int *)*puVar4;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    FUN_006bc6a0("no prod control",piVar1);
  }
  uVar7 = 1;
LAB_0069e35c:
  local_8._0_1_ = 3;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004297b0(0);
  if (local_24 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar7;
}

