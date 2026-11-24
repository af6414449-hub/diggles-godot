
undefined4
CTclGlobalMethods__Sparetime(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  byte bVar1;
  float fVar2;
  int iVar3;
  undefined **ppuVar4;
  undefined **ppuVar5;
  uint uVar6;
  undefined4 *puVar7;
  uint uVar8;
  int iVar9;
  char *pcVar10;
  uint uVar11;
  int *piVar12;
  undefined4 uVar13;
  bool bVar14;
  undefined4 in_XMM0_Da;
  float fVar15;
  undefined8 uVar16;
  int local_4c;
  undefined4 *local_3c;
  uint local_38;
  int local_34;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  int *local_1c;
  uint local_18;
  float local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007125d5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7ce8) &&
     (FUN_006cebf4(&DAT_00ca7ce8,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca7ce8 == -1)) {
    iVar9 = DAT_00783650 * 0x40;
    DAT_00ca7cec = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar9) = "TCL:CTclGlobalMethods::Sparetime()";
    *(int *)(&DAT_00773650 + iVar9) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7ce8);
  }
  iVar9 = DAT_00ca7cec;
  uVar13 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7cec * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar13;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar9 * 0x10];
  if (iVar3 == 0) {
    uVar16 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar9 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar9 * 0x10) = uVar16;
  }
  (&DAT_00773654)[iVar9 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  local_14 = (float)FUN_005c71c0(param_4,3,1);
  if (local_14 == 0.0) {
    uVar13 = 1;
    goto LAB_006ab387;
  }
  FUN_004298b0(param_3,param_4);
  local_1c = (int *)0x0;
  local_8 = CONCAT31(local_8._1_3_,3);
  local_18 = FUN_005f4a70();
  if (local_34 < 3) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar7 = local_3c;
    if (local_38 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_38 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar7 = local_3c + 2;
  }
  piVar12 = (int *)*puVar7;
  if (piVar12 == (int *)0x0) {
    ppuVar4 = &PTR_0071ce50;
  }
  else {
    *piVar12 = *piVar12 + 1;
    ppuVar4 = (undefined **)Tcl_GetStringFromObj(piVar12,0);
    *piVar12 = *piVar12 + -1;
    if (*piVar12 < 1) {
      TclFreeObj(piVar12);
    }
  }
  pcVar10 = "announce";
  ppuVar5 = ppuVar4;
  do {
    bVar1 = *(byte *)ppuVar5;
    bVar14 = bVar1 < (byte)*pcVar10;
    if (bVar1 != *pcVar10) {
LAB_006aaf60:
      uVar6 = -(uint)bVar14 | 1;
      goto LAB_006aaf65;
    }
    if (bVar1 == 0) break;
    bVar1 = *(byte *)((int)ppuVar5 + 1);
    bVar14 = bVar1 < ((byte *)pcVar10)[1];
    if (bVar1 != ((byte *)pcVar10)[1]) goto LAB_006aaf60;
    ppuVar5 = (undefined **)((int)ppuVar5 + 2);
    pcVar10 = (char *)((byte *)pcVar10 + 2);
  } while (bVar1 != 0);
  uVar6 = 0;
LAB_006aaf65:
  piVar12 = (int *)0x0;
  if (uVar6 == 0) {
    if (param_3 != 4) {
      FUN_006bc8f0(3);
      goto LAB_006ab35a;
    }
    FUN_004295e0(3);
    local_24 = (float)FUN_005f4ee0();
    uVar6 = local_18;
    if (local_24 == -NAN) {
      puVar7 = (undefined4 *)FUN_004295e0(3);
      piVar12 = (int *)*puVar7;
      if (piVar12 != (int *)0x0) {
        *piVar12 = *piVar12 + 1;
      }
LAB_006aafb0:
      pcVar10 = "invalid category";
      goto LAB_006ab352;
    }
    local_20 = *(float *)((int)local_14 + 0xdc);
    local_18 = FUN_005f4ad0(local_20);
    if (local_18 == 0xffffffff) {
      uVar11 = *(uint *)(uVar6 + 0x15);
      if ((uVar11 + 0x10 & 0xfffffff0) != (uVar11 + 0xf & 0xfffffff0)) {
        uVar13 = FUN_006baad0("C:\\dev\\wiggles\\CodeLib\\StdTools\\KStdLib\\Include\\DSFastArray.h"
                              ,0x9b);
        uVar11 = *(uint *)(uVar6 + 0x15);
        *(undefined4 *)(uVar6 + 0x11) = uVar13;
      }
      uVar8 = uVar11 + 1;
      *(uint *)(uVar6 + 0x15) = uVar8;
      if (uVar8 <= uVar11) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        uVar8 = *(uint *)(uVar6 + 0x15);
      }
      local_18 = uVar8 - 1;
      if (uVar8 <= local_18) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(float *)(*(int *)(uVar6 + 0x11) + 4 + local_18 * 8) = local_20;
    }
    if (*(uint *)(uVar6 + 0x15) <= local_18) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    *(float *)(*(int *)(uVar6 + 0x11) + local_18 * 8) = local_24;
LAB_006ab2fc:
    if (local_4c != 0) {
      if (piVar12 == (int *)0x0) {
        Tcl_ResetResult(local_4c);
      }
      else {
        Tcl_SetObjResult(local_4c,piVar12);
      }
    }
    uVar13 = 0;
    if ((piVar12 != (int *)0x0) && (*piVar12 = *piVar12 + -1, *piVar12 < 1)) {
      TclFreeObj(piVar12);
    }
  }
  else {
    pcVar10 = "disannounce";
    ppuVar5 = ppuVar4;
    do {
      bVar1 = *(byte *)ppuVar5;
      bVar14 = bVar1 < (byte)*pcVar10;
      if (bVar1 != *pcVar10) {
LAB_006ab0a0:
        uVar6 = -(uint)bVar14 | 1;
        goto LAB_006ab0a5;
      }
      if (bVar1 == 0) break;
      bVar1 = *(byte *)((int)ppuVar5 + 1);
      bVar14 = bVar1 < ((byte *)pcVar10)[1];
      if (bVar1 != ((byte *)pcVar10)[1]) goto LAB_006ab0a0;
      ppuVar5 = (undefined **)((int)ppuVar5 + 2);
      pcVar10 = (char *)((byte *)pcVar10 + 2);
    } while (bVar1 != 0);
    uVar6 = 0;
LAB_006ab0a5:
    if (uVar6 == 0) {
      iVar3 = FUN_005f4ad0(*(undefined4 *)((int)local_14 + 0xdc));
      if (iVar3 == -1) {
        puVar7 = (undefined4 *)FUN_004295e0(2);
        piVar12 = (int *)*puVar7;
        if (piVar12 != (int *)0x0) {
          *piVar12 = *piVar12 + 1;
        }
        pcVar10 = "sparetime place not found ";
        goto LAB_006ab352;
      }
      FUN_005f4f80(iVar3);
      goto LAB_006ab2fc;
    }
    pcVar10 = "queryrange";
    ppuVar5 = ppuVar4;
    do {
      bVar1 = *(byte *)ppuVar5;
      bVar14 = bVar1 < (byte)*pcVar10;
      if (bVar1 != *pcVar10) {
LAB_006ab117:
        uVar6 = -(uint)bVar14 | 1;
        goto LAB_006ab11c;
      }
      if (bVar1 == 0) break;
      bVar1 = *(byte *)((int)ppuVar5 + 1);
      bVar14 = bVar1 < ((byte *)pcVar10)[1];
      if (bVar1 != ((byte *)pcVar10)[1]) goto LAB_006ab117;
      ppuVar5 = (undefined **)((int)ppuVar5 + 2);
      pcVar10 = (char *)((byte *)pcVar10 + 2);
    } while (bVar1 != 0);
    uVar6 = 0;
LAB_006ab11c:
    if (uVar6 == 0) {
      if (param_3 == 5) {
        FUN_004295e0(3);
        iVar3 = FUN_005f4ee0();
        if (iVar3 != -1) {
          FUN_004295e0(4);
          FUN_006baf80();
          uVar13 = FUN_005f4b20(&local_24,*(undefined4 *)((int)local_14 + 0x36c),iVar3,
                                *(undefined4 *)((int)local_14 + 0xc),
                                *(undefined4 *)((int)local_14 + 0x10),
                                *(undefined4 *)((int)local_14 + 0x14),in_XMM0_Da);
          FUN_006baea0(uVar13);
LAB_006ab2f4:
          FUN_006bad60();
          piVar12 = local_1c;
          goto LAB_006ab2fc;
        }
LAB_006ab154:
        puVar7 = (undefined4 *)FUN_004295e0(3);
        piVar12 = (int *)*puVar7;
        if (piVar12 == (int *)0x0) goto LAB_006aafb0;
        *piVar12 = *piVar12 + 1;
        pcVar10 = "invalid category";
LAB_006ab352:
        FUN_006bc6a0(pcVar10,piVar12);
      }
      else {
        FUN_006bc8f0(4);
      }
    }
    else {
      pcVar10 = "queryrect";
      do {
        bVar1 = *(byte *)ppuVar4;
        bVar14 = bVar1 < (byte)*pcVar10;
        if (bVar1 != *pcVar10) {
LAB_006ab1f0:
          uVar6 = -(uint)bVar14 | 1;
          goto LAB_006ab1f5;
        }
        if (bVar1 == 0) break;
        bVar1 = *(byte *)((int)ppuVar4 + 1);
        bVar14 = bVar1 < ((byte *)pcVar10)[1];
        if (bVar1 != ((byte *)pcVar10)[1]) goto LAB_006ab1f0;
        ppuVar4 = (undefined **)((int)ppuVar4 + 2);
        pcVar10 = (char *)((byte *)pcVar10 + 2);
      } while (bVar1 != 0);
      uVar6 = 0;
LAB_006ab1f5:
      if (uVar6 != 0) {
        puVar7 = (undefined4 *)FUN_004295e0(2);
        piVar12 = (int *)*puVar7;
        if (piVar12 != (int *)0x0) {
          *piVar12 = *piVar12 + 1;
        }
        pcVar10 = "invalid sparetime command";
        goto LAB_006ab352;
      }
      if (param_3 == 8) {
        FUN_004295e0(3);
        iVar3 = FUN_005f4ee0();
        fVar2 = local_14;
        if (iVar3 != -1) {
          fVar15 = *(float *)((int)local_14 + 0x10);
          local_20 = fVar15;
          local_14 = *(float *)((int)local_14 + 0xc);
          FUN_004295e0(4);
          FUN_006baf80();
          fVar15 = fVar15 + local_14;
          local_2c = fVar15;
          FUN_004295e0(5);
          FUN_006baf80();
          fVar15 = fVar15 + local_20;
          local_28 = fVar15;
          FUN_004295e0(6);
          FUN_006baf80();
          fVar15 = fVar15 + local_14;
          local_24 = fVar15;
          FUN_004295e0(7);
          FUN_006baf80();
          uVar13 = FUN_005f4d00(&local_2c,*(undefined4 *)((int)fVar2 + 0x36c),iVar3,local_2c,
                                local_28,local_24,fVar15 + local_20);
          FUN_006baea0(uVar13);
          goto LAB_006ab2f4;
        }
        goto LAB_006ab154;
      }
      FUN_006bc8f0(7);
    }
LAB_006ab35a:
    uVar13 = 1;
  }
  local_8._0_1_ = 4;
  FUN_004297b0(0);
  local_8._0_1_ = 5;
  FUN_004297b0(0);
  if (local_3c != (undefined4 *)0x0) {
    FUN_006ba940();
  }
LAB_006ab387:
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar13;
}

