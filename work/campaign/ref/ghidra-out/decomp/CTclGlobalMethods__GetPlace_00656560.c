
undefined4
CTclGlobalMethods__GetPlace(undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  byte bVar1;
  int *piVar2;
  undefined1 uVar3;
  int iVar4;
  undefined **ppuVar5;
  uint uVar6;
  undefined4 *puVar7;
  int *piVar8;
  undefined4 uVar9;
  int iVar10;
  char *pcVar11;
  byte *pbVar12;
  byte *extraout_ECX;
  int *piVar13;
  int *piVar14;
  int *piVar15;
  code *pcVar16;
  bool bVar17;
  ulonglong uVar18;
  undefined8 uVar19;
  undefined1 local_e0 [12];
  undefined1 local_d4 [12];
  float local_c8 [3];
  double local_bc;
  double local_b4;
  double local_ac;
  double local_a4;
  double local_9c;
  double local_94;
  double local_8c;
  double local_84;
  double local_7c;
  double local_74;
  double local_6c;
  double local_64;
  undefined4 *local_5c;
  uint local_58;
  undefined4 local_54;
  undefined4 local_50;
  int *local_4c;
  int *local_38;
  int *local_34;
  int *local_30;
  char local_29;
  int *local_28;
  int *local_24;
  undefined4 *local_20;
  int *local_1c;
  int local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070eb85;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7290) &&
     (FUN_006cebf4(&DAT_00ca7290,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar4 = DAT_00783650,
     DAT_00ca7290 == -1)) {
    iVar10 = DAT_00783650 * 0x40;
    DAT_00ca7294 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar10) = "TCL:CTclGlobalMethods::GetPlace()";
    *(int *)(&DAT_00773650 + iVar10) = iVar4;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7290);
  }
  iVar10 = DAT_00ca7294;
  local_5c = &DAT_00ca7294;
  uVar9 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7294 * 0x40);
  iVar4 = FUN_0043fcc0();
  *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar9;
  *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
  iVar4 = (&DAT_00773654)[iVar10 * 0x10];
  if (iVar4 == 0) {
    uVar19 = FUN_006bd180();
    iVar4 = (&DAT_00773654)[iVar10 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar10 * 0x10) = uVar19;
  }
  (&DAT_00773654)[iVar10 * 0x10] = iVar4 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  piVar2 = param_3;
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_005a9190();
  uVar18 = 0xbf800000;
  piVar13 = (int *)0x1;
  local_50 = 0xbf800000;
  local_54 = 0xbf800000;
  local_58 = 0xbf800000;
  local_29 = '\0';
  pcVar16 = RaiseException_exref;
  if (1 < (int)piVar2) {
    do {
      if (((int)piVar13 < 0) || (local_18 <= (int)piVar13)) {
        (*pcVar16)(0xc000008c,1,0,0);
        puVar7 = local_20;
        if (local_1c == (int *)0x0) {
          (*pcVar16)(0xc000008c,1,0,0);
          puVar7 = local_20;
        }
      }
      else {
        if (local_1c <= piVar13) {
          (*pcVar16)(0xc000008c,1,0,0);
        }
        puVar7 = local_20 + (int)piVar13;
      }
      piVar2 = (int *)*puVar7;
      if (piVar2 != (int *)0x0) {
        *piVar2 = *piVar2 + 1;
      }
      piVar14 = (int *)((int)piVar13 + 1);
      local_8 = CONCAT31(local_8._1_3_,3);
      local_24 = piVar2;
      if (piVar2 == (int *)0x0) {
        ppuVar5 = &PTR_0071ce50;
      }
      else {
        ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar2,0);
      }
      pcVar11 = "-center";
      do {
        bVar1 = *(byte *)ppuVar5;
        bVar17 = bVar1 < (byte)*pcVar11;
        if (bVar1 != *pcVar11) {
LAB_006566f2:
          uVar6 = -(uint)bVar17 | 1;
          goto LAB_006566f7;
        }
        if (bVar1 == 0) break;
        bVar1 = *(byte *)((int)ppuVar5 + 1);
        bVar17 = bVar1 < ((byte *)pcVar11)[1];
        if (bVar1 != ((byte *)pcVar11)[1]) goto LAB_006566f2;
        ppuVar5 = (undefined **)((int)ppuVar5 + 2);
        pcVar11 = (char *)((byte *)pcVar11 + 2);
      } while (bVar1 != 0);
      uVar6 = 0;
LAB_006566f7:
      if (uVar6 == 0) {
        local_14 = (int *)((int)piVar13 + 2);
        if ((int)param_3 < (int)local_14) {
LAB_0065776f:
          pcVar11 = "invalid params";
          piVar13 = (int *)0x0;
LAB_0065777d:
          FUN_006bc6a0(pcVar11,piVar13);
          FUN_006bad60();
          FUN_00429650();
          FUN_006bc0d0();
          FUN_0043fd30();
          ExceptionList = local_10;
          return 1;
        }
        if (((int)piVar14 < 0) || (local_18 <= (int)piVar14)) {
          (*pcVar16)(0xc000008c,1,0,0);
          puVar7 = local_20;
          if (local_1c == (int *)0x0) {
            (*pcVar16)(0xc000008c,1,0,0);
            puVar7 = local_20;
          }
        }
        else {
          if (local_1c <= piVar14) {
            (*pcVar16)(0xc000008c,1,0,0);
          }
          puVar7 = local_20 + (int)piVar14;
        }
        piVar13 = local_14;
        piVar14 = (int *)*puVar7;
        if (piVar14 != (int *)0x0) {
          *piVar14 = *piVar14 + 1;
        }
        local_38 = piVar14;
        puVar7 = (undefined4 *)FUN_006bafe0(local_d4);
        local_50 = *puVar7;
        local_54 = puVar7[1];
        local_58 = puVar7[2];
        uVar18 = (ulonglong)local_58;
        pcVar16 = RaiseException_exref;
        if ((piVar14 != (int *)0x0) &&
           (*piVar14 = *piVar14 + -1, pcVar16 = RaiseException_exref, *piVar14 < 1)) {
          TclFreeObj(piVar14);
          pcVar16 = RaiseException_exref;
        }
      }
      else {
        if (piVar2 == (int *)0x0) {
          ppuVar5 = &PTR_0071ce50;
        }
        else {
          ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar2,0);
        }
        pcVar11 = "-rect";
        do {
          bVar1 = *(byte *)ppuVar5;
          bVar17 = bVar1 < (byte)*pcVar11;
          if (bVar1 != *pcVar11) {
LAB_006567f4:
            uVar6 = -(uint)bVar17 | 1;
            goto LAB_006567f9;
          }
          if (bVar1 == 0) break;
          bVar1 = *(byte *)((int)ppuVar5 + 1);
          bVar17 = bVar1 < ((byte *)pcVar11)[1];
          if (bVar1 != ((byte *)pcVar11)[1]) goto LAB_006567f4;
          ppuVar5 = (undefined **)((int)ppuVar5 + 2);
          pcVar11 = (char *)((byte *)pcVar11 + 2);
        } while (bVar1 != 0);
        uVar6 = 0;
LAB_006567f9:
        if (uVar6 == 0) {
          if ((int)param_3 < (int)piVar13 + 5) goto LAB_0065776f;
          if (((int)piVar14 < 0) || (local_18 <= (int)piVar14)) {
            (*pcVar16)(0xc000008c,1,0,0);
            puVar7 = local_20;
            if (local_1c == (int *)0x0) {
              (*pcVar16)(0xc000008c,1,0,0);
              puVar7 = local_20;
            }
          }
          else {
            if (local_1c <= piVar14) {
              (*pcVar16)(0xc000008c,1,0,0);
            }
            puVar7 = local_20 + (int)piVar14;
          }
          piVar14 = (int *)*puVar7;
          if (piVar14 != (int *)0x0) {
            *piVar14 = *piVar14 + 1;
          }
          piVar15 = (int *)((int)piVar13 + 2);
          if (piVar14 == (int *)0x0) {
            local_34 = (int *)0x0;
          }
          else {
            iVar4 = Tcl_GetDoubleFromObj(0,piVar14,&local_64);
            if (iVar4 == 1) {
              local_34 = (int *)0x0;
            }
            else {
              local_34 = (int *)(float)local_64;
            }
            *piVar14 = *piVar14 + -1;
            if (*piVar14 < 1) {
              TclFreeObj(piVar14);
            }
          }
          if (((int)piVar15 < 0) || (local_18 <= (int)piVar15)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            puVar7 = local_20;
            if (local_1c == (int *)0x0) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              puVar7 = local_20;
            }
          }
          else {
            if (local_1c <= piVar15) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            puVar7 = local_20 + (int)piVar15;
          }
          piVar14 = (int *)*puVar7;
          if (piVar14 != (int *)0x0) {
            *piVar14 = *piVar14 + 1;
          }
          piVar15 = (int *)((int)piVar13 + 3);
          if (piVar14 == (int *)0x0) {
            local_30 = (int *)0x0;
          }
          else {
            iVar4 = Tcl_GetDoubleFromObj(0,piVar14,&local_6c);
            if (iVar4 == 1) {
              local_30 = (int *)0x0;
            }
            else {
              local_30 = (int *)(float)local_6c;
            }
            *piVar14 = *piVar14 + -1;
            if (*piVar14 < 1) {
              TclFreeObj(piVar14);
            }
          }
          if (((int)piVar15 < 0) || (local_18 <= (int)piVar15)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            puVar7 = local_20;
            if (local_1c == (int *)0x0) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              puVar7 = local_20;
            }
          }
          else {
            if (local_1c <= piVar15) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            puVar7 = local_20 + (int)piVar15;
          }
          piVar14 = (int *)*puVar7;
          if (piVar14 != (int *)0x0) {
            *piVar14 = *piVar14 + 1;
          }
          piVar15 = piVar13 + 1;
          if (piVar14 == (int *)0x0) {
            local_24 = (int *)0x0;
          }
          else {
            iVar4 = Tcl_GetDoubleFromObj(0,piVar14,&local_74);
            if (iVar4 == 1) {
              local_24 = (int *)0x0;
            }
            else {
              local_24 = (int *)(float)local_74;
            }
            *piVar14 = *piVar14 + -1;
            if (*piVar14 < 1) {
              TclFreeObj(piVar14);
            }
          }
          if (((int)piVar15 < 0) || (local_18 <= (int)piVar15)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            puVar7 = local_20;
            if (local_1c == (int *)0x0) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              puVar7 = local_20;
            }
          }
          else {
            if (local_1c <= piVar15) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            puVar7 = local_20 + (int)piVar15;
          }
          piVar14 = (int *)*puVar7;
          if (piVar14 != (int *)0x0) {
            *piVar14 = *piVar14 + 1;
          }
          if (piVar14 == (int *)0x0) {
            uVar18 = 0;
          }
          else {
            iVar4 = Tcl_GetDoubleFromObj(0,piVar14,&local_7c);
            if (iVar4 == 1) {
              local_28 = (int *)0x0;
            }
            else {
              local_28 = (int *)(float)local_7c;
            }
            uVar18 = ZEXT48(local_28);
            *piVar14 = *piVar14 + -1;
            if (*piVar14 < 1) {
              TclFreeObj(piVar14);
              uVar18 = ZEXT48(local_28);
            }
          }
          pcVar16 = RaiseException_exref;
          iVar4 = *(int *)(DAT_0077241c + 0x1c);
          *(undefined4 *)(iVar4 + 8) = local_50;
          *(undefined4 *)(iVar4 + 0xc) = local_54;
          *(uint *)(iVar4 + 0x10) = local_58;
          *(int **)(iVar4 + 0x18) = local_34;
          *(int **)(iVar4 + 0x1c) = local_30;
          *(undefined1 *)(iVar4 + 0x14) = 1;
          *(int **)(iVar4 + 0x20) = local_24;
          *(int *)(iVar4 + 0x24) = (int)uVar18;
          piVar13 = (int *)((int)piVar13 + 5);
        }
        else {
          if (piVar2 == (int *)0x0) {
            ppuVar5 = &PTR_0071ce50;
          }
          else {
            ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar2,0);
          }
          pbVar12 = &DAT_00730ac8;
          do {
            bVar1 = *(byte *)ppuVar5;
            bVar17 = bVar1 < *pbVar12;
            if (bVar1 != *pbVar12) {
LAB_00656b20:
              uVar6 = -(uint)bVar17 | 1;
              goto LAB_00656b25;
            }
            if (bVar1 == 0) break;
            bVar1 = *(byte *)((int)ppuVar5 + 1);
            bVar17 = bVar1 < pbVar12[1];
            if (bVar1 != pbVar12[1]) goto LAB_00656b20;
            ppuVar5 = (undefined **)((int)ppuVar5 + 2);
            pbVar12 = pbVar12 + 2;
          } while (bVar1 != 0);
          uVar6 = 0;
LAB_00656b25:
          if (uVar6 == 0) {
            if ((int)param_3 < (int)piVar13 + 5) goto LAB_0065776f;
            if (((int)piVar14 < 0) || (local_18 <= (int)piVar14)) {
              (*pcVar16)(0xc000008c,1,0,0);
              puVar7 = local_20;
              if (local_1c == (int *)0x0) {
                (*pcVar16)(0xc000008c,1,0,0);
                puVar7 = local_20;
              }
            }
            else {
              if (local_1c <= piVar14) {
                (*pcVar16)(0xc000008c,1,0,0);
              }
              puVar7 = local_20 + (int)piVar14;
            }
            piVar14 = (int *)*puVar7;
            if (piVar14 != (int *)0x0) {
              *piVar14 = *piVar14 + 1;
            }
            piVar15 = (int *)((int)piVar13 + 2);
            if (piVar14 == (int *)0x0) {
              local_4c = (int *)0x0;
            }
            else {
              iVar4 = Tcl_GetDoubleFromObj(0,piVar14,&local_84);
              if (iVar4 == 1) {
                local_4c = (int *)0x0;
              }
              else {
                local_4c = (int *)(float)local_84;
              }
              *piVar14 = *piVar14 + -1;
              if (*piVar14 < 1) {
                TclFreeObj(piVar14);
              }
            }
            if (((int)piVar15 < 0) || (local_18 <= (int)piVar15)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              puVar7 = local_20;
              if (local_1c == (int *)0x0) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                puVar7 = local_20;
              }
            }
            else {
              if (local_1c <= piVar15) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              puVar7 = local_20 + (int)piVar15;
            }
            piVar14 = (int *)*puVar7;
            if (piVar14 != (int *)0x0) {
              *piVar14 = *piVar14 + 1;
            }
            piVar15 = (int *)((int)piVar13 + 3);
            if (piVar14 == (int *)0x0) {
              local_28 = (int *)0x0;
            }
            else {
              iVar4 = Tcl_GetDoubleFromObj(0,piVar14,&local_8c);
              if (iVar4 == 1) {
                local_28 = (int *)0x0;
              }
              else {
                local_28 = (int *)(float)local_8c;
              }
              *piVar14 = *piVar14 + -1;
              if (*piVar14 < 1) {
                TclFreeObj(piVar14);
              }
            }
            if (((int)piVar15 < 0) || (local_18 <= (int)piVar15)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              puVar7 = local_20;
              if (local_1c == (int *)0x0) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                puVar7 = local_20;
              }
            }
            else {
              if (local_1c <= piVar15) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              puVar7 = local_20 + (int)piVar15;
            }
            piVar14 = (int *)*puVar7;
            if (piVar14 != (int *)0x0) {
              *piVar14 = *piVar14 + 1;
            }
            piVar15 = piVar13 + 1;
            if (piVar14 == (int *)0x0) {
              local_30 = (int *)0x0;
            }
            else {
              iVar4 = Tcl_GetDoubleFromObj(0,piVar14,&local_94);
              if (iVar4 == 1) {
                local_30 = (int *)0x0;
              }
              else {
                local_30 = (int *)(float)local_94;
              }
              *piVar14 = *piVar14 + -1;
              if (*piVar14 < 1) {
                TclFreeObj(piVar14);
              }
            }
            if (((int)piVar15 < 0) || (local_18 <= (int)piVar15)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              puVar7 = local_20;
              if (local_1c == (int *)0x0) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                puVar7 = local_20;
              }
            }
            else {
              if (local_1c <= piVar15) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              puVar7 = local_20 + (int)piVar15;
            }
            piVar14 = (int *)*puVar7;
            if (piVar14 != (int *)0x0) {
              *piVar14 = *piVar14 + 1;
            }
            if (piVar14 == (int *)0x0) {
              local_34 = (int *)0x0;
            }
            else {
              iVar4 = Tcl_GetDoubleFromObj(0,piVar14,&local_9c);
              if (iVar4 == 1) {
                local_34 = (int *)0x0;
              }
              else {
                local_34 = (int *)(float)local_9c;
              }
              *piVar14 = *piVar14 + -1;
              if (*piVar14 < 1) {
                TclFreeObj(piVar14);
              }
            }
            piVar15 = local_34;
            piVar14 = *(int **)(DAT_0077241c + 0x1c);
            local_38 = local_4c;
            local_14 = local_28;
            if ((float)local_30 < (float)local_4c) {
              local_38 = local_30;
              local_30 = local_4c;
            }
            if ((float)local_34 < (float)local_28) {
              local_34 = local_28;
              local_14 = piVar15;
            }
            piVar15 = (int *)piVar14[1];
            if (((uint)(piVar15 + 4) & 0xfffffff0) != ((int)piVar15 + 0xfU & 0xfffffff0)) {
              iVar4 = FUN_006baad0("C:\\dev\\wiggles\\CodeLib\\StdTools\\KStdLib\\Include\\DSFastArray.h"
                                   ,0x9b);
              piVar15 = (int *)piVar14[1];
              *piVar14 = iVar4;
            }
            piVar8 = (int *)((int)piVar15 + 1);
            piVar14[1] = (int)piVar8;
            if (piVar8 <= piVar15) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              piVar8 = (int *)piVar14[1];
            }
            local_28 = (int *)((int)piVar8 - 1);
            if (piVar8 <= local_28) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            local_4c = (int *)((int)local_28 * 0x10);
            *(int **)((int)local_4c + *piVar14) = local_38;
            if ((int *)piVar14[1] <= local_28) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            *(int **)(*piVar14 + 8 + (int)local_4c) = local_14;
            if ((int *)piVar14[1] <= local_28) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            *(int **)(*piVar14 + 4 + (int)local_4c) = local_30;
            if ((int *)piVar14[1] <= local_28) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            pcVar16 = RaiseException_exref;
            uVar18 = ZEXT48(local_34);
            *(int **)(*piVar14 + 0xc + (int)local_4c) = local_34;
            piVar13 = (int *)((int)piVar13 + 5);
          }
          else {
            if (piVar2 == (int *)0x0) {
              ppuVar5 = &PTR_0071ce50;
            }
            else {
              ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar2,0);
            }
            pcVar11 = "-circle";
            do {
              bVar1 = *(byte *)ppuVar5;
              bVar17 = bVar1 < (byte)*pcVar11;
              if (bVar1 != *pcVar11) {
LAB_00656f45:
                uVar6 = -(uint)bVar17 | 1;
                goto LAB_00656f4a;
              }
              if (bVar1 == 0) break;
              bVar1 = *(byte *)((int)ppuVar5 + 1);
              bVar17 = bVar1 < ((byte *)pcVar11)[1];
              if (bVar1 != ((byte *)pcVar11)[1]) goto LAB_00656f45;
              ppuVar5 = (undefined **)((int)ppuVar5 + 2);
              pcVar11 = (char *)((byte *)pcVar11 + 2);
            } while (bVar1 != 0);
            uVar6 = 0;
LAB_00656f4a:
            if (uVar6 == 0) {
              local_14 = (int *)((int)piVar13 + 2);
              if ((int)param_3 < (int)local_14) goto LAB_0065776f;
              puVar7 = (undefined4 *)FUN_004295e0(piVar14);
              piVar13 = local_14;
              piVar14 = (int *)*puVar7;
              if (piVar14 == (int *)0x0) {
                uVar18 = 0;
              }
              else {
                *piVar14 = *piVar14 + 1;
                iVar4 = Tcl_GetDoubleFromObj(0,piVar14,&local_a4);
                if (iVar4 == 1) {
                  local_14 = (int *)0x0;
                }
                else {
                  local_14 = (int *)(float)local_a4;
                }
                uVar18 = ZEXT48(local_14);
                *piVar14 = *piVar14 + -1;
                if (*piVar14 < 1) {
                  TclFreeObj(piVar14);
                  uVar18 = ZEXT48(local_14);
                }
              }
              pcVar16 = RaiseException_exref;
              iVar4 = *(int *)(DAT_0077241c + 0x1c);
              *(undefined4 *)(iVar4 + 8) = local_50;
              *(undefined4 *)(iVar4 + 0xc) = local_54;
              *(undefined1 *)(iVar4 + 0x14) = 0;
              *(uint *)(iVar4 + 0x10) = local_58;
              *(int *)(iVar4 + 0x28) = (int)uVar18;
            }
            else {
              if (piVar2 == (int *)0x0) {
                ppuVar5 = &PTR_0071ce50;
              }
              else {
                ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar2,0);
              }
              pcVar11 = "-random";
              do {
                bVar1 = *(byte *)ppuVar5;
                bVar17 = bVar1 < (byte)*pcVar11;
                if (bVar1 != *pcVar11) {
LAB_00657040:
                  uVar6 = -(uint)bVar17 | 1;
                  goto LAB_00657045;
                }
                if (bVar1 == 0) break;
                bVar1 = *(byte *)((int)ppuVar5 + 1);
                bVar17 = bVar1 < ((byte *)pcVar11)[1];
                if (bVar1 != ((byte *)pcVar11)[1]) goto LAB_00657040;
                ppuVar5 = (undefined **)((int)ppuVar5 + 2);
                pcVar11 = (char *)((byte *)pcVar11 + 2);
              } while (bVar1 != 0);
              uVar6 = 0;
LAB_00657045:
              if (uVar6 == 0) {
                local_14 = (int *)((int)piVar13 + 2);
                if ((int)param_3 < (int)local_14) goto LAB_0065776f;
                puVar7 = (undefined4 *)FUN_004295e0(piVar14);
                piVar13 = local_14;
                piVar14 = (int *)*puVar7;
                if (piVar14 == (int *)0x0) {
                  uVar18 = 0;
                }
                else {
                  *piVar14 = *piVar14 + 1;
                  iVar4 = Tcl_GetDoubleFromObj(0,piVar14,&local_ac);
                  if (iVar4 == 1) {
                    local_14 = (int *)0x0;
                  }
                  else {
                    local_14 = (int *)(float)local_ac;
                  }
                  uVar18 = ZEXT48(local_14);
                  *piVar14 = *piVar14 + -1;
                  if (*piVar14 < 1) {
                    TclFreeObj(piVar14);
                    uVar18 = ZEXT48(local_14);
                  }
                }
                pcVar16 = RaiseException_exref;
                *(int *)(*(int *)(DAT_0077241c + 0x1c) + 0x4c) = (int)uVar18;
              }
              else {
                if (piVar2 == (int *)0x0) {
                  ppuVar5 = &PTR_0071ce50;
                }
                else {
                  ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar2,0);
                }
                pcVar11 = "-placelock";
                do {
                  bVar1 = *(byte *)ppuVar5;
                  bVar17 = bVar1 < (byte)*pcVar11;
                  if (bVar1 != *pcVar11) {
LAB_00657113:
                    uVar6 = -(uint)bVar17 | 1;
                    goto LAB_00657118;
                  }
                  if (bVar1 == 0) break;
                  bVar1 = *(byte *)((int)ppuVar5 + 1);
                  bVar17 = bVar1 < ((byte *)pcVar11)[1];
                  if (bVar1 != ((byte *)pcVar11)[1]) goto LAB_00657113;
                  ppuVar5 = (undefined **)((int)ppuVar5 + 2);
                  pcVar11 = (char *)((byte *)pcVar11 + 2);
                } while (bVar1 != 0);
                uVar6 = 0;
LAB_00657118:
                if (uVar6 == 0) {
                  local_14 = (int *)((int)piVar13 + 2);
                  if ((int)param_3 < (int)local_14) goto LAB_0065776f;
                  puVar7 = (undefined4 *)FUN_004295e0(piVar14);
                  piVar13 = local_14;
                  piVar14 = (int *)*puVar7;
                  if (piVar14 == (int *)0x0) {
                    uVar18 = 0;
                  }
                  else {
                    *piVar14 = *piVar14 + 1;
                    iVar4 = Tcl_GetDoubleFromObj(0,piVar14,&local_b4);
                    if (iVar4 == 1) {
                      local_14 = (int *)0x0;
                    }
                    else {
                      local_14 = (int *)(float)local_b4;
                    }
                    uVar18 = ZEXT48(local_14);
                    *piVar14 = *piVar14 + -1;
                    if (*piVar14 < 1) {
                      TclFreeObj(piVar14);
                      uVar18 = ZEXT48(local_14);
                    }
                  }
                  pcVar16 = RaiseException_exref;
                  *(int *)(*(int *)(DAT_0077241c + 0x1c) + 0x2c) = (int)uVar18;
                }
                else {
                  if (piVar2 == (int *)0x0) {
                    ppuVar5 = &PTR_0071ce50;
                  }
                  else {
                    ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar2,0);
                  }
                  pcVar11 = "-mindist";
                  do {
                    bVar1 = *(byte *)ppuVar5;
                    bVar17 = bVar1 < (byte)*pcVar11;
                    if (bVar1 != *pcVar11) {
LAB_006571e6:
                      uVar6 = -(uint)bVar17 | 1;
                      goto LAB_006571eb;
                    }
                    if (bVar1 == 0) break;
                    bVar1 = *(byte *)((int)ppuVar5 + 1);
                    bVar17 = bVar1 < ((byte *)pcVar11)[1];
                    if (bVar1 != ((byte *)pcVar11)[1]) goto LAB_006571e6;
                    ppuVar5 = (undefined **)((int)ppuVar5 + 2);
                    pcVar11 = (char *)((byte *)pcVar11 + 2);
                  } while (bVar1 != 0);
                  uVar6 = 0;
LAB_006571eb:
                  if (uVar6 == 0) {
                    local_14 = (int *)((int)piVar13 + 2);
                    if ((int)param_3 < (int)local_14) goto LAB_0065776f;
                    puVar7 = (undefined4 *)FUN_004295e0(piVar14);
                    piVar13 = local_14;
                    piVar14 = (int *)*puVar7;
                    if (piVar14 == (int *)0x0) {
                      uVar18 = 0;
                    }
                    else {
                      *piVar14 = *piVar14 + 1;
                      iVar4 = Tcl_GetDoubleFromObj(0,piVar14,&local_bc);
                      if (iVar4 == 1) {
                        local_14 = (int *)0x0;
                      }
                      else {
                        local_14 = (int *)(float)local_bc;
                      }
                      uVar18 = ZEXT48(local_14);
                      *piVar14 = *piVar14 + -1;
                      if (*piVar14 < 1) {
                        TclFreeObj(piVar14);
                        uVar18 = ZEXT48(local_14);
                      }
                    }
                    pcVar16 = RaiseException_exref;
                    *(int *)(*(int *)(DAT_0077241c + 0x1c) + 0x30) = (int)uVar18;
                  }
                  else {
                    if (piVar2 == (int *)0x0) {
                      ppuVar5 = &PTR_0071ce50;
                    }
                    else {
                      ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar2,0);
                    }
                    pcVar11 = "-except";
                    do {
                      bVar1 = *(byte *)ppuVar5;
                      bVar17 = bVar1 < (byte)*pcVar11;
                      if (bVar1 != *pcVar11) {
LAB_006572c0:
                        uVar6 = -(uint)bVar17 | 1;
                        goto LAB_006572c5;
                      }
                      if (bVar1 == 0) break;
                      bVar1 = *(byte *)((int)ppuVar5 + 1);
                      bVar17 = bVar1 < ((byte *)pcVar11)[1];
                      if (bVar1 != ((byte *)pcVar11)[1]) goto LAB_006572c0;
                      ppuVar5 = (undefined **)((int)ppuVar5 + 2);
                      pcVar11 = (char *)((byte *)pcVar11 + 2);
                    } while (bVar1 != 0);
                    uVar6 = 0;
LAB_006572c5:
                    if (uVar6 == 0) {
                      if ((int)param_3 < (int)piVar13 + 2) goto LAB_0065776f;
                      uVar9 = FUN_005c71c0(param_4,0,piVar14);
                      pcVar16 = RaiseException_exref;
                      *(undefined4 *)(*(int *)(DAT_0077241c + 0x1c) + 0x3c) = uVar9;
                      piVar13 = (int *)((int)piVar13 + 2);
                    }
                    else {
                      if (piVar2 == (int *)0x0) {
                        ppuVar5 = &PTR_0071ce50;
                      }
                      else {
                        ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar2,0);
                      }
                      pcVar11 = "-nearpos";
                      do {
                        bVar1 = *(byte *)ppuVar5;
                        bVar17 = bVar1 < (byte)*pcVar11;
                        if (bVar1 != *pcVar11) {
LAB_00657340:
                          uVar6 = -(uint)bVar17 | 1;
                          goto LAB_00657345;
                        }
                        if (bVar1 == 0) break;
                        bVar1 = *(byte *)((int)ppuVar5 + 1);
                        bVar17 = bVar1 < ((byte *)pcVar11)[1];
                        if (bVar1 != ((byte *)pcVar11)[1]) goto LAB_00657340;
                        ppuVar5 = (undefined **)((int)ppuVar5 + 2);
                        pcVar11 = (char *)((byte *)pcVar11 + 2);
                      } while (bVar1 != 0);
                      uVar6 = 0;
LAB_00657345:
                      if (uVar6 == 0) {
                        if ((int)param_3 < (int)piVar13 + 2) goto LAB_0065776f;
                        puVar7 = (undefined4 *)FUN_004295e0(piVar14);
                        local_14 = (int *)*puVar7;
                        if (local_14 != (int *)0x0) {
                          *local_14 = *local_14 + 1;
                        }
                        puVar7 = (undefined4 *)FUN_006bafe0(local_e0);
                        iVar4 = *(int *)(DAT_0077241c + 0x1c);
                        *(undefined4 *)(iVar4 + 0x40) = *puVar7;
                        *(undefined4 *)(iVar4 + 0x44) = puVar7[1];
                        *(undefined4 *)(iVar4 + 0x48) = puVar7[2];
                        FUN_006bad60();
                        piVar13 = (int *)((int)piVar13 + 2);
                        pcVar16 = RaiseException_exref;
                      }
                      else {
                        if (piVar2 == (int *)0x0) {
                          ppuVar5 = &PTR_0071ce50;
                        }
                        else {
                          ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar2,0);
                        }
                        piVar15 = (int *)uVar18;
                        pcVar11 = "-walldist";
                        do {
                          bVar1 = *(byte *)ppuVar5;
                          bVar17 = bVar1 < (byte)*pcVar11;
                          if (bVar1 != *pcVar11) {
LAB_006573e5:
                            uVar6 = -(uint)bVar17 | 1;
                            goto LAB_006573ea;
                          }
                          if (bVar1 == 0) break;
                          bVar1 = *(byte *)((int)ppuVar5 + 1);
                          bVar17 = bVar1 < ((byte *)pcVar11)[1];
                          if (bVar1 != ((byte *)pcVar11)[1]) goto LAB_006573e5;
                          ppuVar5 = (undefined **)((int)ppuVar5 + 2);
                          pcVar11 = (char *)((byte *)pcVar11 + 2);
                        } while (bVar1 != 0);
                        uVar6 = 0;
LAB_006573ea:
                        if (uVar6 == 0) {
                          if ((int)param_3 < (int)piVar13 + 2) goto LAB_0065776f;
                          puVar7 = (undefined4 *)FUN_004295e0(piVar14);
                          local_14 = (int *)*puVar7;
                          if (local_14 != (int *)0x0) {
                            *local_14 = *local_14 + 1;
                          }
                          FUN_006baf80();
                          local_38 = piVar15;
                          FUN_006bad60();
                          pcVar16 = RaiseException_exref;
                          uVar18 = ZEXT48(local_38);
                          *(int **)(*(int *)(DAT_0077241c + 0x1c) + 0x34) = local_38;
                          piVar13 = (int *)((int)piVar13 + 2);
                        }
                        else {
                          if (piVar2 == (int *)0x0) {
                            ppuVar5 = &PTR_0071ce50;
                          }
                          else {
                            ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar2,0);
                          }
                          piVar15 = (int *)uVar18;
                          pcVar11 = "-rimdist";
                          do {
                            bVar1 = *(byte *)ppuVar5;
                            bVar17 = bVar1 < (byte)*pcVar11;
                            if (bVar1 != *pcVar11) {
LAB_00657480:
                              uVar6 = -(uint)bVar17 | 1;
                              goto LAB_00657485;
                            }
                            if (bVar1 == 0) break;
                            bVar1 = *(byte *)((int)ppuVar5 + 1);
                            bVar17 = bVar1 < ((byte *)pcVar11)[1];
                            if (bVar1 != ((byte *)pcVar11)[1]) goto LAB_00657480;
                            ppuVar5 = (undefined **)((int)ppuVar5 + 2);
                            pcVar11 = (char *)((byte *)pcVar11 + 2);
                          } while (bVar1 != 0);
                          uVar6 = 0;
LAB_00657485:
                          if (uVar6 == 0) {
                            if ((int)param_3 < (int)piVar13 + 2) goto LAB_0065776f;
                            puVar7 = (undefined4 *)FUN_004295e0(piVar14);
                            local_14 = (int *)*puVar7;
                            if (local_14 != (int *)0x0) {
                              *local_14 = *local_14 + 1;
                            }
                            FUN_006baf80();
                            local_38 = piVar15;
                            FUN_006bad60();
                            pcVar16 = RaiseException_exref;
                            uVar18 = ZEXT48(local_38);
                            *(int **)(*(int *)(DAT_0077241c + 0x1c) + 0x38) = local_38;
                            piVar13 = (int *)((int)piVar13 + 2);
                          }
                          else {
                            if (piVar2 == (int *)0x0) {
                              ppuVar5 = &PTR_0071ce50;
                            }
                            else {
                              ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar2,0);
                            }
                            pcVar11 = "-materials";
                            do {
                              bVar1 = *(byte *)ppuVar5;
                              bVar17 = bVar1 < (byte)*pcVar11;
                              if (bVar1 != *pcVar11) {
LAB_00657520:
                                uVar6 = -(uint)bVar17 | 1;
                                goto LAB_00657525;
                              }
                              if (bVar1 == 0) break;
                              bVar1 = *(byte *)((int)ppuVar5 + 1);
                              bVar17 = bVar1 < ((byte *)pcVar11)[1];
                              if (bVar1 != ((byte *)pcVar11)[1]) goto LAB_00657520;
                              ppuVar5 = (undefined **)((int)ppuVar5 + 2);
                              pcVar11 = (char *)((byte *)pcVar11 + 2);
                            } while (bVar1 != 0);
                            uVar6 = 0;
LAB_00657525:
                            if (uVar6 == 0) {
                              piVar13 = (int *)((int)piVar13 + 2);
                              if ((int)param_3 < (int)piVar13) goto LAB_0065776f;
                              puVar7 = (undefined4 *)FUN_004295e0(piVar14);
                              local_14 = (int *)*puVar7;
                              if (local_14 != (int *)0x0) {
                                *local_14 = *local_14 + 1;
                              }
                              local_28 = piVar13;
                              uVar3 = FUN_006baf10();
                              FUN_006bad60();
                              *(undefined1 *)(*(int *)(DAT_0077241c + 0x1c) + 0x50) = uVar3;
                              pcVar16 = RaiseException_exref;
                            }
                            else {
                              if (piVar2 == (int *)0x0) {
                                ppuVar5 = &PTR_0071ce50;
                              }
                              else {
                                ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar2,0);
                              }
                              pcVar11 = "-placelockidexcept";
                              do {
                                bVar1 = *(byte *)ppuVar5;
                                bVar17 = bVar1 < (byte)*pcVar11;
                                if (bVar1 != *pcVar11) {
LAB_006575b5:
                                  uVar6 = -(uint)bVar17 | 1;
                                  goto LAB_006575ba;
                                }
                                if (bVar1 == 0) break;
                                bVar1 = *(byte *)((int)ppuVar5 + 1);
                                bVar17 = bVar1 < ((byte *)pcVar11)[1];
                                if (bVar1 != ((byte *)pcVar11)[1]) goto LAB_006575b5;
                                ppuVar5 = (undefined **)((int)ppuVar5 + 2);
                                pcVar11 = (char *)((byte *)pcVar11 + 2);
                              } while (bVar1 != 0);
                              uVar6 = 0;
LAB_006575ba:
                              if (uVar6 == 0) {
                                if ((int)param_3 < (int)piVar13 + 2) goto LAB_0065776f;
                                puVar7 = (undefined4 *)FUN_004295e0(piVar14);
                                local_14 = (int *)*puVar7;
                                if (local_14 != (int *)0x0) {
                                  *local_14 = *local_14 + 1;
                                }
                                uVar9 = FUN_006baee0();
                                FUN_006bad60();
                                *(undefined4 *)(*(int *)(DAT_0077241c + 0x1c) + 0x54) = uVar9;
                                piVar13 = (int *)((int)piVar13 + 2);
                                pcVar16 = RaiseException_exref;
                              }
                              else {
                                if (piVar2 == (int *)0x0) {
                                  ppuVar5 = &PTR_0071ce50;
                                }
                                else {
                                  ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar2,0);
                                }
                                pcVar11 = "-enableplacelockcheck";
                                do {
                                  bVar1 = *(byte *)ppuVar5;
                                  bVar17 = bVar1 < (byte)*pcVar11;
                                  if (bVar1 != *pcVar11) {
LAB_00657647:
                                    uVar6 = -(uint)bVar17 | 1;
                                    goto LAB_0065764c;
                                  }
                                  if (bVar1 == 0) break;
                                  bVar1 = *(byte *)((int)ppuVar5 + 1);
                                  bVar17 = bVar1 < ((byte *)pcVar11)[1];
                                  if (bVar1 != ((byte *)pcVar11)[1]) goto LAB_00657647;
                                  ppuVar5 = (undefined **)((int)ppuVar5 + 2);
                                  pcVar11 = (char *)((byte *)pcVar11 + 2);
                                } while (bVar1 != 0);
                                uVar6 = 0;
LAB_0065764c:
                                if (uVar6 == 0) {
                                  piVar13 = (int *)((int)piVar13 + 2);
                                  if ((int)param_3 < (int)piVar13) goto LAB_0065776f;
                                  puVar7 = (undefined4 *)FUN_004295e0(piVar14);
                                  local_14 = (int *)*puVar7;
                                  if (local_14 != (int *)0x0) {
                                    *local_14 = *local_14 + 1;
                                  }
                                  local_28 = piVar13;
                                  uVar3 = FUN_006baf10();
                                  FUN_006bad60();
                                  *(undefined1 *)(*(int *)(DAT_0077241c + 0x1c) + 0x58) = uVar3;
                                  pcVar16 = RaiseException_exref;
                                }
                                else {
                                  if (piVar2 == (int *)0x0) {
                                    ppuVar5 = &PTR_0071ce50;
                                  }
                                  else {
                                    ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar2,0);
                                  }
                                  pcVar11 = "-checkfree";
                                  do {
                                    bVar1 = *(byte *)ppuVar5;
                                    bVar17 = bVar1 < (byte)*pcVar11;
                                    if (bVar1 != *pcVar11) {
LAB_006576e0:
                                      uVar6 = -(uint)bVar17 | 1;
                                      goto LAB_006576e5;
                                    }
                                    if (bVar1 == 0) break;
                                    bVar1 = *(byte *)((int)ppuVar5 + 1);
                                    bVar17 = bVar1 < ((byte *)pcVar11)[1];
                                    if (bVar1 != ((byte *)pcVar11)[1]) goto LAB_006576e0;
                                    ppuVar5 = (undefined **)((int)ppuVar5 + 2);
                                    pcVar11 = (char *)((byte *)pcVar11 + 2);
                                  } while (bVar1 != 0);
                                  uVar6 = 0;
LAB_006576e5:
                                  if (uVar6 != 0) {
                                    if (piVar2 == (int *)0x0) {
                                      ppuVar5 = &PTR_0071ce50;
                                    }
                                    else {
                                      ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar2,0);
                                      pcVar11 = (char *)extraout_ECX;
                                    }
                                    if (ppuVar5 == (undefined **)0x0) {
                                      pcVar11 = "unknown option";
                                      piVar13 = (int *)0x0;
                                    }
                                    else {
                                      piVar13 = (int *)Tcl_NewStringObj(ppuVar5,0xffffffff,pcVar11);
                                      *piVar13 = *piVar13 + 1;
                                      pcVar11 = "unknown option";
                                    }
                                    goto LAB_0065777d;
                                  }
                                  local_29 = '\x01';
                                  *(undefined1 *)(*(int *)(DAT_0077241c + 0x1c) + 0x59) = 1;
                                  piVar13 = piVar14;
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      local_8 = CONCAT31(local_8._1_3_,2);
      if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
        TclFreeObj(piVar2);
      }
    } while ((int)piVar13 < (int)param_3);
  }
  CPlaceFinder__FindPlace(local_c8);
  if (local_29 == '\0') {
    puVar7 = (undefined4 *)FUN_006badc0(local_c8);
  }
  else {
    param_3 = (int *)Tcl_NewBooleanObj(local_c8[0] == 0.0);
    *param_3 = *param_3 + 1;
    puVar7 = &param_3;
  }
  FUN_006bc670(puVar7);
  FUN_006bad60();
  FUN_00429650();
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return 0;
}

