
undefined4
CTclObjMethods__SetElevatorProperties
          (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  float in_XMM0_Da;
  undefined8 uVar6;
  char *pcVar7;
  int *piVar8;
  undefined4 *local_28;
  uint local_24;
  int local_20;
  undefined4 local_18;
  int *piStack_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070c3dd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7a00) &&
     (FUN_006cebf4(&DAT_00ca7a00,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar1 = DAT_00783650,
     DAT_00ca7a00 == -1)) {
    iVar4 = DAT_00783650 * 0x40;
    DAT_00ca7a04 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar4) = "TCL:CTclObjMethods::SetElevatorProperties()";
    *(int *)(&DAT_00773650 + iVar4) = iVar1;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7a00);
  }
  iVar4 = DAT_00ca7a04;
  uVar5 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7a04 * 0x40);
  iVar1 = FUN_0043fcc0();
  *(undefined4 *)(iVar1 + *(int *)(iVar1 + 0x8000) * 4) = uVar5;
  *(int *)(iVar1 + 0x8000) = *(int *)(iVar1 + 0x8000) + 1;
  iVar1 = (&DAT_00773654)[iVar4 * 0x10];
  if (iVar1 == 0) {
    uVar6 = FUN_006bd180();
    iVar1 = (&DAT_00773654)[iVar4 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar4 * 0x10) = uVar6;
  }
  (&DAT_00773654)[iVar4 * 0x10] = iVar1 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  iVar1 = FUN_005c71c0(param_4,5,1);
  if (iVar1 != 0) {
    if (*(int *)(iVar1 + 0x3ec) == 0) {
      if (local_20 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar2 = local_28;
        if (local_24 == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
      else {
        if (local_24 < 2) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar2 = local_28 + 1;
      }
      piVar8 = (int *)*puVar2;
      if (piVar8 != (int *)0x0) {
        *piVar8 = *piVar8 + 1;
      }
      pcVar7 = "no transport logic";
    }
    else {
      if (*(int *)(*(int *)(iVar1 + 0x3ec) + 4) != 0) {
        puVar2 = (undefined4 *)FUN_004295e0(2);
        piVar8 = (int *)*puVar2;
        if (piVar8 == (int *)0x0) {
          *(undefined4 *)(*(int *)(*(int *)(iVar1 + 0x3ec) + 4) + 0x224) = 0;
        }
        else {
          *piVar8 = *piVar8 + 1;
          iVar3 = Tcl_GetDoubleFromObj(0,piVar8,&local_18);
          iVar4 = *(int *)(*(int *)(iVar1 + 0x3ec) + 4);
          if (iVar3 == 1) {
            *(undefined4 *)(iVar4 + 0x224) = 0;
          }
          else {
            in_XMM0_Da = (float)(double)CONCAT44(piStack_14,local_18);
            *(float *)(iVar4 + 0x224) = in_XMM0_Da;
          }
          *piVar8 = *piVar8 + -1;
          if (*piVar8 < 1) {
            TclFreeObj(piVar8);
          }
        }
        puVar2 = (undefined4 *)FUN_004295e0(3);
        piVar8 = (int *)*puVar2;
        if (piVar8 == (int *)0x0) {
          *(undefined4 *)(*(int *)(*(int *)(iVar1 + 0x3ec) + 4) + 0x218) = 0;
        }
        else {
          *piVar8 = *piVar8 + 1;
          iVar4 = Tcl_GetIntFromObj(0,piVar8,&piStack_14);
          if (iVar4 == 1) {
            *(undefined4 *)(*(int *)(*(int *)(iVar1 + 0x3ec) + 4) + 0x218) = 0;
          }
          else {
            *(int **)(*(int *)(*(int *)(iVar1 + 0x3ec) + 4) + 0x218) = piStack_14;
          }
          *piVar8 = *piVar8 + -1;
          if (*piVar8 < 1) {
            TclFreeObj(piVar8);
          }
        }
        puVar2 = (undefined4 *)FUN_004295e0(4);
        piVar8 = (int *)*puVar2;
        if (piVar8 == (int *)0x0) {
          *(undefined4 *)(*(int *)(*(int *)(iVar1 + 0x3ec) + 4) + 0x21c) = 0;
        }
        else {
          *piVar8 = *piVar8 + 1;
          iVar3 = Tcl_GetDoubleFromObj(0,piVar8,&local_18);
          iVar4 = *(int *)(*(int *)(iVar1 + 0x3ec) + 4);
          if (iVar3 == 1) {
            *(undefined4 *)(iVar4 + 0x21c) = 0;
          }
          else {
            in_XMM0_Da = (float)(double)CONCAT44(piStack_14,local_18);
            *(float *)(iVar4 + 0x21c) = in_XMM0_Da;
          }
          *piVar8 = *piVar8 + -1;
          if (*piVar8 < 1) {
            TclFreeObj(piVar8);
          }
        }
        if (5 < param_3) {
          puVar2 = (undefined4 *)FUN_004295e0(5);
          piStack_14 = (int *)*puVar2;
          if (piStack_14 != (int *)0x0) {
            *piStack_14 = *piStack_14 + 1;
          }
          FUN_006baf80();
          *(float *)(*(int *)(*(int *)(iVar1 + 0x3ec) + 4) + 0x220) = in_XMM0_Da;
          FUN_006bad60();
        }
        if (param_3 == 7) {
          puVar2 = (undefined4 *)FUN_004295e0(6);
          piStack_14 = (int *)*puVar2;
          if (piStack_14 != (int *)0x0) {
            *piStack_14 = *piStack_14 + 1;
          }
          uVar5 = FUN_006baee0();
          *(undefined4 *)(*(int *)(*(int *)(iVar1 + 0x3ec) + 4) + 0x228) = uVar5;
          FUN_006bad60();
        }
        uVar5 = 0;
        goto LAB_00695bae;
      }
      puVar2 = (undefined4 *)FUN_004295e0(1);
      piVar8 = (int *)*puVar2;
      if (piVar8 != (int *)0x0) {
        *piVar8 = *piVar8 + 1;
      }
      pcVar7 = "no elevator logic";
    }
    FUN_006bc6a0(pcVar7,piVar8);
  }
  uVar5 = 1;
LAB_00695bae:
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
  return uVar5;
}

