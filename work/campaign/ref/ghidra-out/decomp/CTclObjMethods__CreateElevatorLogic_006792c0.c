
undefined4
CTclObjMethods__CreateElevatorLogic
          (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  undefined8 uVar10;
  int local_2c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00710da8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if (*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7530) {
    FUN_006cebf4(&DAT_00ca7530,DAT_0076700c ^ (uint)&stack0xfffffffc);
    iVar2 = DAT_00783650;
    if (DAT_00ca7530 == -1) {
      iVar3 = DAT_00783650 * 0x40;
      DAT_00ca7534 = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar3) = "TCL:CTclObjMethods::CreateElevatorLogic()";
      *(int *)(&DAT_00773650 + iVar3) = iVar2;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa(&DAT_00ca7530);
    }
  }
  iVar3 = DAT_00ca7534;
  uVar8 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7534 * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar8;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar3 * 0x10];
  if (iVar2 == 0) {
    uVar10 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar3 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar3 * 0x10) = uVar10;
  }
  (&DAT_00773654)[iVar3 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (param_3 == 4) {
    iVar2 = FUN_005c71c0(param_4,3,1);
    if (iVar2 != 0) {
      iVar3 = FUN_005c71c0(param_4,3,2);
      if (iVar3 != 0) {
        puVar4 = (undefined4 *)FUN_004295e0(3);
        piVar1 = (int *)*puVar4;
        if (piVar1 == (int *)0x0) {
          param_3._3_1_ = FUN_006baf10();
        }
        else {
          *piVar1 = *piVar1 + 1;
          param_3._3_1_ = FUN_006baf10();
          *piVar1 = *piVar1 + -1;
          if (*piVar1 < 1) {
            TclFreeObj(piVar1);
          }
        }
        puVar4 = *(undefined4 **)(iVar2 + 0x3ec);
        if (puVar4 == (undefined4 *)0x0) {
          puVar4 = (undefined4 *)FUN_006ba810(0x498);
          if (puVar4 == (undefined4 *)0x0) {
            puVar4 = (undefined4 *)0x0;
          }
          else {
            puVar4[1] = 0;
            puVar4[2] = 0;
            puVar4[3] = 0;
          }
          *(undefined4 **)(iVar2 + 0x3ec) = puVar4;
        }
        if (puVar4[1] == 0) {
          *puVar4 = 0;
          iVar5 = FUN_006ba810(0x122);
          local_8._0_1_ = 3;
          if (iVar5 == 0) {
            iVar5 = 0;
          }
          else {
            iVar5 = FUN_00607b10();
          }
          local_8 = CONCAT31(local_8._1_3_,2);
          *(int *)(iVar5 + 0x20c) = iVar2;
          *(undefined4 *)(iVar5 + 0x210) = *(undefined4 *)(iVar2 + 0xdc);
          *(int *)(iVar5 + 0x214) = iVar3;
          FUN_0060a2c0();
          *(char *)(iVar5 + 0x204) = param_3._3_1_;
          iVar3 = DAT_0076a338;
          if (param_3._3_1_ == '\0') {
            FUN_00492250();
            uVar8 = FUN_006074b0();
            *(undefined4 *)(iVar5 + 0x208) = uVar8;
          }
          else if (DAT_0076a338 != 0) {
            FUN_0047e300(1);
            uVar6 = *(int *)(iVar3 + 0x19f0e) - 1;
            piVar1 = (int *)(DAT_0076a338 + 0x19f0a);
            if (*(uint *)(DAT_0076a338 + 0x19f0e) <= uVar6) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            iVar3 = DAT_0076a338;
            iVar7 = uVar6 * 0x20;
            *(undefined4 *)(iVar7 + *piVar1) = *(undefined4 *)(iVar5 + 0x210);
            iVar9 = iVar3;
            if (*(uint *)(iVar3 + 0x19f0e) <= uVar6) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar9 = DAT_0076a338;
            }
            *(undefined4 *)(iVar7 + 4 + *(int *)(iVar3 + 0x19f0a)) = 0;
            iVar3 = iVar9;
            if (*(uint *)(iVar9 + 0x19f0e) <= uVar6) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar3 = DAT_0076a338;
            }
            iVar9 = *(int *)(iVar9 + 0x19f0a);
            *(undefined4 *)(iVar7 + 0x10 + iVar9) = 0;
            *(undefined4 *)(iVar7 + 0xc + iVar9) = 0;
            *(undefined4 *)(iVar7 + 8 + iVar9) = 0;
            if (*(uint *)(iVar3 + 0x19f0e) <= uVar6) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            iVar3 = *(int *)(iVar3 + 0x19f0a);
            *(undefined4 *)(iVar7 + 0x1c + iVar3) = 0;
            *(undefined4 *)(iVar7 + 0x18 + iVar3) = 0;
            *(undefined4 *)(iVar7 + 0x14 + iVar3) = 0;
          }
          *(undefined4 *)(iVar5 + 0x1fc) = *(undefined4 *)(iVar2 + 0x3d0);
          *(undefined4 *)(iVar5 + 0x200) = *(undefined4 *)(iVar2 + 0x3d0);
          *(int *)(*(int *)(iVar2 + 0x3ec) + 4) = iVar5;
        }
        uVar8 = 0;
        goto LAB_00679392;
      }
    }
  }
  else {
    FUN_006bc8f0(3);
  }
  uVar8 = 1;
LAB_00679392:
  local_8._0_1_ = 4;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,5);
  FUN_004297b0(0);
  if (local_2c != 0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar8;
}

