
undefined4
CTclGlobalMethods__LGSetTemplateProps
          (undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  uint uVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  undefined **ppuVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  code *pcVar10;
  int *piVar11;
  undefined8 uVar12;
  char *pcVar13;
  undefined4 *local_3c;
  uint local_38;
  int local_34;
  int *local_1c;
  int *local_18;
  char local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070e295;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7190) &&
     (FUN_006cebf4(&DAT_00ca7190,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar4 = DAT_00783650,
     DAT_00ca7190 == -1)) {
    iVar6 = DAT_00783650 * 0x40;
    DAT_00ca7194 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar6) = "TCL:CTclGlobalMethods::LGSetTemplateProps()";
    *(int *)(&DAT_00773650 + iVar6) = iVar4;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7190);
  }
  iVar6 = DAT_00ca7194;
  uVar8 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7194 * 0x40);
  iVar4 = FUN_0043fcc0();
  *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar8;
  *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
  iVar4 = (&DAT_00773654)[iVar6 * 0x10];
  if (iVar4 == 0) {
    uVar12 = FUN_006bd180();
    iVar4 = (&DAT_00773654)[iVar6 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar6 * 0x10) = uVar12;
  }
  (&DAT_00773654)[iVar6 * 0x10] = iVar4 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_0058a820();
  if (local_34 < 2) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar9 = local_3c;
    if (local_38 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_38 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar9 = local_3c + 1;
  }
  piVar2 = (int *)*puVar9;
  if (piVar2 != (int *)0x0) {
    *piVar2 = *piVar2 + 1;
  }
  local_8._0_1_ = 3;
  local_1c = piVar2;
  if (piVar2 == (int *)0x0) {
    ppuVar5 = &PTR_0071ce50;
    piVar11 = (int *)0x0;
  }
  else {
    ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar2,0);
    piVar11 = piVar2;
  }
  FUN_006b8fb0(ppuVar5);
  local_8._0_1_ = 4;
  iVar4 = FUN_00583080(&local_18);
  local_8._0_1_ = 5;
  if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 == 0)) {
    FUN_006ba940();
  }
  local_8 = CONCAT31(local_8._1_3_,2);
  if ((piVar11 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
    TclFreeObj(piVar2);
  }
  if (iVar4 != -1) {
    if ((param_3 & 1) == 0) {
      uVar7 = 2;
      if (2 < (int)param_3) {
        do {
          uVar1 = uVar7 + 1;
          if (((int)uVar1 < 0) || (local_34 <= (int)uVar1)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            puVar9 = local_3c;
            if (local_38 == 0) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
          }
          else {
            if (local_38 <= uVar1) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            puVar9 = local_3c + uVar7 + 1;
          }
          piVar2 = (int *)*puVar9;
          if (piVar2 != (int *)0x0) {
            *piVar2 = *piVar2 + 1;
          }
          local_8 = CONCAT31(local_8._1_3_,6);
          if (piVar2 == (int *)0x0) {
            ppuVar5 = &PTR_0071ce50;
          }
          else {
            ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar2,0);
          }
          FUN_006b8fb0(ppuVar5);
          if (((int)uVar7 < 0) || (local_34 <= (int)uVar7)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            puVar9 = local_3c;
            if (local_38 == 0) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
          }
          else {
            if (local_38 <= uVar7) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            puVar9 = local_3c + uVar7;
          }
          piVar11 = (int *)*puVar9;
          if (piVar11 != (int *)0x0) {
            *piVar11 = *piVar11 + 1;
          }
          local_8._0_1_ = 8;
          if (piVar11 == (int *)0x0) {
            ppuVar5 = &PTR_0071ce50;
          }
          else {
            ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar11,0);
          }
          FUN_006b8fb0(ppuVar5);
          cVar3 = FUN_005832c0(iVar4,&local_18,&local_1c);
          local_11 = cVar3 == '\0';
          local_8 = CONCAT31(local_8._1_3_,9);
          if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 == 0)) {
            FUN_006ba940();
          }
          pcVar10 = TclFreeObj_exref;
          if ((piVar11 != (int *)0x0) &&
             (*piVar11 = *piVar11 + -1, pcVar10 = TclFreeObj_exref, *piVar11 < 1)) {
            TclFreeObj(piVar11);
          }
          local_8._0_1_ = 10;
          if ((local_1c != (int *)0x0) && (*local_1c = *local_1c + -1, *local_1c == 0)) {
            FUN_006ba940();
          }
          local_8 = CONCAT31(local_8._1_3_,2);
          if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
            (*pcVar10)(piVar2);
          }
          if (local_11 != '\0') {
            pcVar13 = "invalid param";
            goto LAB_0064d97a;
          }
          uVar7 = uVar7 + 2;
        } while ((int)uVar7 < (int)param_3);
      }
      uVar8 = 0;
      goto LAB_0064d987;
    }
    pcVar13 = "invalid paramstring";
LAB_0064d97a:
    FUN_006bc6a0(pcVar13,0);
  }
  uVar8 = 1;
LAB_0064d987:
  local_8._0_1_ = 0xb;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,0xc);
  FUN_004297b0(0);
  if (local_3c != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar8;
}

