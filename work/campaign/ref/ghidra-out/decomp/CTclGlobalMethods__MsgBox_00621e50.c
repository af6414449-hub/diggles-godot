
undefined4
CTclGlobalMethods__MsgBox(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  uint uVar1;
  char *pcVar2;
  char cVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  undefined4 *puVar8;
  int iVar9;
  int *piVar10;
  undefined **ppuVar11;
  int *piVar12;
  undefined8 in_XMM0_Qa;
  undefined8 uVar13;
  undefined4 *local_3c;
  uint local_38;
  int local_34;
  undefined **local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070bb05;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6c58) &&
     (FUN_006cebf4(&DAT_00ca6c58,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar6 = DAT_00783650,
     DAT_00ca6c58 == -1)) {
    iVar9 = DAT_00783650 * 0x40;
    DAT_00ca6c5c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar9) = "TCL:CTclGlobalMethods::MsgBox()";
    *(int *)(&DAT_00773650 + iVar9) = iVar6;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6c58);
  }
  iVar9 = DAT_00ca6c5c;
  uVar4 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6c5c * 0x40);
  iVar6 = FUN_0043fcc0();
  *(undefined4 *)(iVar6 + *(int *)(iVar6 + 0x8000) * 4) = uVar4;
  *(int *)(iVar6 + 0x8000) = *(int *)(iVar6 + 0x8000) + 1;
  iVar6 = (&DAT_00773654)[iVar9 * 0x10];
  if (iVar6 == 0) {
    uVar13 = FUN_006bd180();
    iVar6 = (&DAT_00773654)[iVar9 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar9 * 0x10) = uVar13;
  }
  (&DAT_00773654)[iVar9 * 0x10] = iVar6 + 1;
  local_8 = 0;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 1;
  piVar7 = (int *)FUN_006ba810(0x19);
  piVar7[1] = 4;
  *(undefined1 *)(piVar7 + 3) = 0;
  piVar7[2] = 0;
  *piVar7 = 1;
  local_8 = CONCAT31(local_8._1_3_,2);
  local_14 = 1;
  if (1 < param_3) {
    do {
      if ((int)local_14 < local_34) {
        if (local_38 <= local_14) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar8 = local_3c + local_14;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar8 = local_3c;
        if (local_38 == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
      piVar12 = (int *)*puVar8;
      if (piVar12 != (int *)0x0) {
        *piVar12 = *piVar12 + 1;
      }
      local_8._0_1_ = 3;
      if (piVar12 == (int *)0x0) {
        local_18 = &PTR_0071ce50;
      }
      else {
        local_18 = (undefined **)Tcl_GetStringFromObj(piVar12,0);
      }
      iVar6 = piVar7[2];
      if (iVar6 == -1) {
        piVar10 = piVar7 + 3;
        do {
          iVar6 = *piVar10;
          piVar10 = (int *)((int)piVar10 + 1);
        } while ((char)iVar6 != '\0');
        iVar6 = (int)piVar10 - ((int)piVar7 + 0xd);
        piVar7[2] = iVar6;
      }
      ppuVar11 = local_18;
      do {
        cVar3 = *(char *)ppuVar11;
        ppuVar11 = (undefined **)((int)ppuVar11 + 1);
      } while (cVar3 != '\0');
      pcVar2 = (char *)((int)ppuVar11 + (iVar6 - ((int)local_18 + 1)));
      piVar7 = (int *)FUN_006b8df0(piVar7,pcVar2 + 1);
      FUN_006d2250(iVar6 + 0xc + (int)piVar7,local_18,
                   (char *)((int)ppuVar11 + (1 - (int)((int)local_18 + 1))));
      piVar7[2] = (int)pcVar2;
      local_8 = CONCAT31(local_8._1_3_,2);
      if ((piVar12 != (int *)0x0) && (*piVar12 = *piVar12 + -1, *piVar12 < 1)) {
        TclFreeObj(piVar12);
      }
      if ((int)local_14 < param_3 + -1) {
        iVar6 = piVar7[2];
        if (iVar6 == -1) {
          piVar12 = piVar7 + 3;
          do {
            iVar6 = *piVar12;
            piVar12 = (int *)((int)piVar12 + 1);
          } while ((char)iVar6 != '\0');
          iVar6 = (int)piVar12 - ((int)piVar7 + 0xd);
          piVar7[2] = iVar6;
        }
        piVar7 = (int *)FUN_006b8df0(piVar7,iVar6 + 2);
        *(undefined2 *)(iVar6 + 0xc + (int)piVar7) = 10;
        piVar7[2] = iVar6 + 1;
      }
      local_14 = local_14 + 1;
    } while ((int)local_14 < param_3);
  }
  if (DAT_00772368 == (undefined4 *)0x0) {
    puVar8 = (undefined4 *)FUN_006ba810(0x51);
    if (puVar8 == (undefined4 *)0x0) {
      DAT_00772368 = (undefined4 *)0x0;
    }
    else {
      *puVar8 = 0;
      puVar8[1] = 0;
      puVar8[0xd] = 0;
      puVar8[2] = 0xffffffff;
      puVar8[3] = 0xffffffff;
      *(undefined1 *)(puVar8 + 8) = 0;
      FUN_0043e3c0();
      *(undefined8 *)(puVar8 + 4) = in_XMM0_Qa;
      *(undefined8 *)(puVar8 + 6) = 0x3ff4000000000000;
      DAT_00772368 = puVar8;
    }
  }
  iVar6 = FUN_00501450();
  if (*(int *)(iVar6 + 0x8194) != 0) {
    iVar6 = FUN_00501450();
    iVar6 = *(int *)(iVar6 + 0x8194);
    FUN_00444ca0(1);
    uVar5 = *(uint *)(iVar6 + 0x88);
    uVar1 = uVar5 - 1;
    if (uVar5 <= uVar1) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    iVar6 = *(int *)(iVar6 + 0x84);
    piVar12 = *(int **)(iVar6 + uVar1 * 4);
    *(int **)(iVar6 + uVar1 * 4) = piVar7;
    *piVar7 = *piVar7 + 1;
    if ((piVar12 != (int *)0x0) && (*piVar12 = *piVar12 + -1, *piVar12 == 0)) {
      FUN_006ba940();
    }
    *(int *)(*(int *)(iVar6 + uVar1 * 4) + 8) = piVar7[2];
  }
  local_8._0_1_ = 4;
  *piVar7 = *piVar7 + -1;
  if (*piVar7 == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 5;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,6);
  FUN_004297b0(0);
  if (local_3c != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return 0;
}

