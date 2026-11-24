
undefined4 CTclObjMethods__SetFSource(undefined4 param_1,undefined4 param_2,uint param_3)

{
  byte bVar1;
  int *piVar2;
  undefined1 uVar3;
  int iVar4;
  undefined4 *puVar5;
  byte *pbVar6;
  uint uVar7;
  int iVar8;
  byte *pbVar9;
  char *pcVar10;
  undefined4 uVar11;
  byte *pbVar12;
  code *pcVar13;
  byte *pbVar14;
  bool bVar15;
  undefined8 uVar16;
  undefined4 uVar17;
  int *local_54;
  int *local_50;
  int local_3c;
  int local_2c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  uVar7 = param_3;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00711c7d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7a90) &&
     (FUN_006cebf4(), iVar4 = DAT_00783650, DAT_00ca7a90 == -1)) {
    iVar8 = DAT_00783650 * 0x40;
    DAT_00ca7a94 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar8) = "TCL:CTclObjMethods::SetFSource()";
    *(int *)(&DAT_00773650 + iVar8) = iVar4;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa();
  }
  iVar8 = DAT_00ca7a94;
  uVar17 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7a94 * 0x40);
  iVar4 = FUN_0043fcc0();
  *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar17;
  *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
  iVar4 = (&DAT_00773654)[iVar8 * 0x10];
  if (iVar4 == 0) {
    uVar16 = FUN_006bd180();
    iVar4 = (&DAT_00773654)[iVar8 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar8 * 0x10) = uVar16;
  }
  (&DAT_00773654)[iVar8 * 0x10] = iVar4 + 1;
  local_8 = 0;
  FUN_006bc170();
  local_8._0_1_ = 1;
  FUN_004298b0();
  local_8._0_1_ = 2;
  uVar3 = (undefined1)local_8;
  local_8._0_1_ = 2;
  if (((int)param_3 < 2) || ((param_3 & 1) != 0)) {
    local_8._0_1_ = uVar3;
    FUN_006bc8f0();
    local_8._0_1_ = 3;
    FUN_004297b0();
    local_8 = CONCAT31(local_8._1_3_,4);
  }
  else {
    iVar4 = FUN_005c71c0();
    if (iVar4 != 0) {
      uVar17 = *(undefined4 *)(iVar4 + 0xdc);
      iVar4 = param_3 - 3;
      param_3 = 0xffffd8f0;
      uVar11 = 0xffffd8f0;
      if (0 < iVar4) {
        local_3c = (uVar7 - 4 >> 1) + 1;
        pcVar13 = TclFreeObj_exref;
        do {
          puVar5 = (undefined4 *)FUN_004295e0();
          piVar2 = (int *)*puVar5;
          if (piVar2 != (int *)0x0) {
            *piVar2 = *piVar2 + 1;
          }
          local_8 = CONCAT31(local_8._1_3_,7);
          if (piVar2 != (int *)0x0) {
            Tcl_GetStringFromObj();
          }
          FUN_006b8fb0();
          if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
            (*pcVar13)();
          }
          puVar5 = (undefined4 *)FUN_004295e0();
          piVar2 = (int *)*puVar5;
          if (piVar2 != (int *)0x0) {
            *piVar2 = *piVar2 + 1;
          }
          local_8 = CONCAT31(local_8._1_3_,10);
          pbVar9 = &DAT_0072bee8;
          pbVar14 = (byte *)(local_50 + 3);
          pbVar6 = pbVar14;
          do {
            bVar1 = *pbVar6;
            bVar15 = bVar1 < *pbVar9;
            if (bVar1 != *pbVar9) {
LAB_006990a4:
              uVar7 = -(uint)bVar15 | 1;
              goto LAB_006990a9;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar6[1];
            bVar15 = bVar1 < pbVar9[1];
            if (bVar1 != pbVar9[1]) goto LAB_006990a4;
            pbVar6 = pbVar6 + 2;
            pbVar9 = pbVar9 + 2;
          } while (bVar1 != 0);
          uVar7 = 0;
LAB_006990a9:
          if (uVar7 == 0) {
            FUN_006bafe0();
          }
          pcVar10 = "-type";
          pbVar6 = pbVar14;
          do {
            bVar1 = *pbVar6;
            bVar15 = bVar1 < (byte)*pcVar10;
            if (bVar1 != *pcVar10) {
LAB_00699100:
              uVar7 = -(uint)bVar15 | 1;
              goto LAB_00699105;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar6[1];
            bVar15 = bVar1 < ((byte *)pcVar10)[1];
            if (bVar1 != ((byte *)pcVar10)[1]) goto LAB_00699100;
            pbVar6 = pbVar6 + 2;
            pcVar10 = (char *)((byte *)pcVar10 + 2);
          } while (bVar1 != 0);
          uVar7 = 0;
LAB_00699105:
          if (uVar7 == 0) {
            if (piVar2 != (int *)0x0) {
              Tcl_GetStringFromObj();
            }
            FUN_006b8fb0();
            pcVar10 = "water";
            pbVar6 = (byte *)(local_54 + 3);
            pbVar9 = pbVar6;
            do {
              bVar1 = *pbVar9;
              bVar15 = bVar1 < (byte)*pcVar10;
              if (bVar1 != *pcVar10) {
LAB_00699160:
                uVar7 = -(uint)bVar15 | 1;
                goto LAB_00699165;
              }
              if (bVar1 == 0) break;
              bVar1 = pbVar9[1];
              bVar15 = bVar1 < ((byte *)pcVar10)[1];
              if (bVar1 != ((byte *)pcVar10)[1]) goto LAB_00699160;
              pbVar9 = pbVar9 + 2;
              pcVar10 = (char *)((byte *)pcVar10 + 2);
            } while (bVar1 != 0);
            uVar7 = 0;
LAB_00699165:
            if (uVar7 == 0) {
              param_3 = 1;
            }
            pbVar12 = &DAT_0072fe8c;
            pbVar9 = pbVar6;
            do {
              bVar1 = *pbVar9;
              bVar15 = bVar1 < *pbVar12;
              if (bVar1 != *pbVar12) {
LAB_006991a0:
                uVar7 = -(uint)bVar15 | 1;
                goto LAB_006991a5;
              }
              if (bVar1 == 0) break;
              bVar1 = pbVar9[1];
              bVar15 = bVar1 < pbVar12[1];
              if (bVar1 != pbVar12[1]) goto LAB_006991a0;
              pbVar9 = pbVar9 + 2;
              pbVar12 = pbVar12 + 2;
            } while (bVar1 != 0);
            uVar7 = 0;
LAB_006991a5:
            if (uVar7 == 0) {
              param_3 = 3;
            }
            pbVar12 = &DAT_00734864;
            pbVar9 = pbVar6;
            do {
              bVar1 = *pbVar9;
              bVar15 = bVar1 < *pbVar12;
              if (bVar1 != *pbVar12) {
LAB_006991e0:
                uVar7 = -(uint)bVar15 | 1;
                goto LAB_006991e5;
              }
              if (bVar1 == 0) break;
              bVar1 = pbVar9[1];
              bVar15 = bVar1 < pbVar12[1];
              if (bVar1 != pbVar12[1]) goto LAB_006991e0;
              pbVar9 = pbVar9 + 2;
              pbVar12 = pbVar12 + 2;
            } while (bVar1 != 0);
            uVar7 = 0;
LAB_006991e5:
            if (uVar7 == 0) {
              param_3 = 2;
            }
            pcVar10 = "lavawater";
            do {
              bVar1 = *pbVar6;
              bVar15 = bVar1 < (byte)*pcVar10;
              if (bVar1 != *pcVar10) {
LAB_00699220:
                uVar7 = -(uint)bVar15 | 1;
                goto LAB_00699225;
              }
              if (bVar1 == 0) break;
              bVar1 = pbVar6[1];
              bVar15 = bVar1 < ((byte *)pcVar10)[1];
              if (bVar1 != ((byte *)pcVar10)[1]) goto LAB_00699220;
              pbVar6 = pbVar6 + 2;
              pcVar10 = (char *)((byte *)pcVar10 + 2);
            } while (bVar1 != 0);
            uVar7 = 0;
LAB_00699225:
            if (uVar7 == 0) {
              param_3 = 4;
            }
            local_8 = CONCAT31(local_8._1_3_,0xb);
            if ((local_54 != (int *)0x0) && (*local_54 = *local_54 + -1, *local_54 == 0)) {
              FUN_006ba940();
            }
          }
          pcVar10 = "-volume";
          pbVar6 = pbVar14;
          do {
            bVar1 = *pbVar6;
            bVar15 = bVar1 < (byte)*pcVar10;
            if (bVar1 != *pcVar10) {
LAB_00699271:
              uVar7 = -(uint)bVar15 | 1;
              goto LAB_00699276;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar6[1];
            bVar15 = bVar1 < ((byte *)pcVar10)[1];
            if (bVar1 != ((byte *)pcVar10)[1]) goto LAB_00699271;
            pbVar6 = pbVar6 + 2;
            pcVar10 = (char *)((byte *)pcVar10 + 2);
          } while (bVar1 != 0);
          uVar7 = 0;
LAB_00699276:
          if ((uVar7 == 0) && (piVar2 != (int *)0x0)) {
            Tcl_GetDoubleFromObj();
          }
          pcVar10 = "-height";
          pbVar6 = pbVar14;
          do {
            bVar1 = *pbVar6;
            bVar15 = bVar1 < (byte)*pcVar10;
            if (bVar1 != *pcVar10) {
LAB_006992d2:
              uVar7 = -(uint)bVar15 | 1;
              goto LAB_006992d7;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar6[1];
            bVar15 = bVar1 < ((byte *)pcVar10)[1];
            if (bVar1 != ((byte *)pcVar10)[1]) goto LAB_006992d2;
            pbVar6 = pbVar6 + 2;
            pcVar10 = (char *)((byte *)pcVar10 + 2);
          } while (bVar1 != 0);
          uVar7 = 0;
LAB_006992d7:
          if ((uVar7 == 0) && (piVar2 != (int *)0x0)) {
            Tcl_GetDoubleFromObj();
          }
          pbVar9 = &DAT_00734888;
          pbVar6 = pbVar14;
          do {
            bVar1 = *pbVar6;
            bVar15 = bVar1 < *pbVar9;
            if (bVar1 != *pbVar9) {
LAB_00699333:
              uVar7 = -(uint)bVar15 | 1;
              goto LAB_00699338;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar6[1];
            bVar15 = bVar1 < pbVar9[1];
            if (bVar1 != pbVar9[1]) goto LAB_00699333;
            pbVar6 = pbVar6 + 2;
            pbVar9 = pbVar9 + 2;
          } while (bVar1 != 0);
          uVar7 = 0;
LAB_00699338:
          if ((uVar7 == 0) && (piVar2 != (int *)0x0)) {
            Tcl_GetDoubleFromObj();
          }
          pcVar10 = "-ventil";
          do {
            bVar1 = *pbVar14;
            bVar15 = bVar1 < (byte)*pcVar10;
            if (bVar1 != *pcVar10) {
LAB_00699398:
              uVar7 = -(uint)bVar15 | 1;
              goto LAB_0069939d;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar14[1];
            bVar15 = bVar1 < ((byte *)pcVar10)[1];
            if (bVar1 != ((byte *)pcVar10)[1]) goto LAB_00699398;
            pbVar14 = pbVar14 + 2;
            pcVar10 = (char *)((byte *)pcVar10 + 2);
          } while (bVar1 != 0);
          uVar7 = 0;
LAB_0069939d:
          if ((uVar7 == 0) && (piVar2 != (int *)0x0)) {
            Tcl_GetBooleanFromObj();
          }
          pcVar13 = TclFreeObj_exref;
          if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
            TclFreeObj();
          }
          local_8._0_1_ = 0xc;
          if ((local_50 != (int *)0x0) && (*local_50 = *local_50 + -1, *local_50 == 0)) {
            FUN_006ba940();
          }
          local_3c = local_3c + -1;
          uVar11 = param_3;
        } while (local_3c != 0);
      }
      local_8._0_1_ = 0xd;
      FUN_0057d980(uVar17,uVar11);
      local_8._0_1_ = 2;
      FUN_0057b2a0(uVar17,uVar11);
      local_8._0_1_ = 0xe;
      FUN_004297b0();
      local_8 = CONCAT31(local_8._1_3_,0xf);
      FUN_004297b0();
      if (local_2c != 0) {
        FUN_006ba940();
      }
      FUN_006bc0d0();
      FUN_0043fd30();
      ExceptionList = local_10;
      return 0;
    }
    puVar5 = (undefined4 *)FUN_004295e0();
    piVar2 = (int *)*puVar5;
    if (piVar2 != (int *)0x0) {
      *piVar2 = *piVar2 + 1;
    }
    FUN_006bc6a0();
    local_8._0_1_ = 5;
    FUN_004297b0();
    local_8 = CONCAT31(local_8._1_3_,6);
  }
  FUN_004297b0();
  if (local_2c != 0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return 1;
}

