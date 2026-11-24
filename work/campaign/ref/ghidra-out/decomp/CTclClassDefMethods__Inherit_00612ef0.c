
undefined4
CTclClassDefMethods__Inherit(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  undefined **ppuVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  undefined8 uVar10;
  undefined4 *local_34;
  uint local_30;
  int local_2c;
  int *local_1c;
  uint local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070a6a5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6b68) &&
     (FUN_006cebf4(&DAT_00ca6b68,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar4 = DAT_00783650,
     DAT_00ca6b68 == -1)) {
    iVar7 = DAT_00783650 * 0x40;
    DAT_00ca6b6c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar7) = "TCL:CTclClassDefMethods::Inherit()";
    *(int *)(&DAT_00773650 + iVar7) = iVar4;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6b68);
  }
  iVar7 = DAT_00ca6b6c;
  uVar8 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6b6c * 0x40);
  iVar4 = FUN_0043fcc0();
  *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar8;
  *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
  iVar4 = (&DAT_00773654)[iVar7 * 0x10];
  if (iVar4 == 0) {
    uVar10 = FUN_006bd180();
    iVar4 = (&DAT_00773654)[iVar7 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar7 * 0x10) = uVar10;
  }
  (&DAT_00773654)[iVar7 * 0x10] = iVar4 + 1;
  local_8 = 0;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 1;
  FUN_006bc170(param_2);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (*(int *)(DAT_00772440 + 4) == 0) {
    FUN_006bc6a0("no class defined.",0);
  }
  else {
    if (1 < param_3) {
      uVar9 = 1;
      do {
        if ((int)uVar9 < local_2c) {
          if (local_30 <= uVar9) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          puVar6 = local_34 + uVar9;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          puVar6 = local_34;
          if (local_30 == 0) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
        }
        piVar1 = (int *)*puVar6;
        if (piVar1 != (int *)0x0) {
          *piVar1 = *piVar1 + 1;
        }
        local_8 = CONCAT31(local_8._1_3_,3);
        if (piVar1 == (int *)0x0) {
          ppuVar5 = &PTR_0071ce50;
        }
        else {
          ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar1,0);
        }
        FUN_006b8fb0(ppuVar5);
        local_14 = DAT_00772478;
        cVar3 = FUN_006037d0(&local_1c,&local_18);
        if (cVar3 == '\0') {
          iVar4 = 0;
        }
        else {
          if (*(uint *)(local_14 + 0x801c) <= local_18) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          iVar4 = *(int *)(*(int *)(local_14 + 0x8018) + local_18 * 4);
        }
        local_8._0_1_ = 4;
        if ((local_1c != (int *)0x0) && (*local_1c = *local_1c + -1, *local_1c == 0)) {
          FUN_006ba940();
        }
        local_8 = CONCAT31(local_8._1_3_,3);
        if (iVar4 == 0) {
          puVar6 = (undefined4 *)FUN_004295e0(uVar9);
          piVar2 = (int *)*puVar6;
          if (piVar2 != (int *)0x0) {
            *piVar2 = *piVar2 + 1;
          }
          FUN_006bc6a0("unknown class",piVar2);
          if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
            TclFreeObj(piVar1);
          }
          goto LAB_00613139;
        }
        FUN_00602220(iVar4);
        if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
          TclFreeObj(piVar1);
        }
        uVar9 = uVar9 + 1;
      } while ((int)uVar9 < param_3);
      uVar8 = 0;
      goto LAB_0061313e;
    }
    FUN_006bc8f0(1);
  }
LAB_00613139:
  uVar8 = 1;
LAB_0061313e:
  FUN_006bc0d0();
  local_8._0_1_ = 5;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,6);
  FUN_004297b0(0);
  if (local_34 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar8;
}

