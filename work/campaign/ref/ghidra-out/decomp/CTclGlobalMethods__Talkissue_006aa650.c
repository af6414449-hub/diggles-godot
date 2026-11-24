
undefined4
CTclGlobalMethods__Talkissue(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  undefined **ppuVar4;
  undefined **ppuVar5;
  uint uVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 extraout_ECX;
  byte *pbVar9;
  char *pcVar10;
  uint uVar11;
  code *pcVar12;
  undefined4 uVar13;
  bool bVar14;
  int *in_XMM0_Da;
  undefined8 uVar15;
  int *piVar16;
  int local_40;
  undefined4 *local_30;
  uint local_2c;
  int local_28;
  int *local_1c;
  int local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00711785;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7ce0) &&
     (FUN_006cebf4(&DAT_00ca7ce0,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca7ce0 == -1)) {
    iVar7 = DAT_00783650 * 0x40;
    DAT_00ca7ce4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar7) = "TCL:CTclGlobalMethods::Talkissue()";
    *(int *)(&DAT_00773650 + iVar7) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7ce0);
  }
  iVar7 = DAT_00ca7ce4;
  uVar13 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7ce4 * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar13;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar7 * 0x10];
  if (iVar3 == 0) {
    uVar15 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar7 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar7 * 0x10) = uVar15;
  }
  (&DAT_00773654)[iVar7 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  local_18 = FUN_005c71c0(param_4,3,1);
  if (local_18 != 0) {
    if (*(int *)(local_18 + 0xe8) == 1) {
      FUN_004298b0(param_3,param_4);
      piVar16 = (int *)0x0;
      local_14 = (int *)0x0;
      local_8 = CONCAT31(local_8._1_3_,3);
      if (local_28 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar8 = local_30;
        if (local_2c == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
      else {
        if (local_2c < 3) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar8 = local_30 + 2;
      }
      piVar2 = (int *)*puVar8;
      if (piVar2 == (int *)0x0) {
        ppuVar4 = &PTR_0071ce50;
      }
      else {
        *piVar2 = *piVar2 + 1;
        ppuVar4 = (undefined **)Tcl_GetStringFromObj(piVar2,0);
        *piVar2 = *piVar2 + -1;
        if (*piVar2 < 1) {
          TclFreeObj(piVar2);
        }
      }
      pbVar9 = &DAT_00722abc;
      ppuVar5 = ppuVar4;
      do {
        bVar1 = *(byte *)ppuVar5;
        bVar14 = bVar1 < *pbVar9;
        if (bVar1 != *pbVar9) {
LAB_006aa840:
          uVar6 = -(uint)bVar14 | 1;
          goto LAB_006aa845;
        }
        if (bVar1 == 0) break;
        bVar1 = *(byte *)((int)ppuVar5 + 1);
        bVar14 = bVar1 < pbVar9[1];
        if (bVar1 != pbVar9[1]) goto LAB_006aa840;
        ppuVar5 = (undefined **)((int)ppuVar5 + 2);
        pbVar9 = pbVar9 + 2;
      } while (bVar1 != 0);
      uVar6 = 0;
LAB_006aa845:
      if (uVar6 == 0) {
        if (param_3 != 5) {
          FUN_006bc8f0(4);
          goto LAB_006aad31;
        }
        FUN_004295e0(4);
        FUN_006baf80();
        local_1c = in_XMM0_Da;
        uVar13 = FUN_004295e0(3);
        FUN_005ff2c0(uVar13);
        uVar13 = FUN_006bad90();
        FUN_006baea0(uVar13);
        FUN_006bad60();
        pcVar12 = TclFreeObj_exref;
        piVar16 = local_14;
LAB_006aacd7:
        if (local_40 != 0) {
          if (piVar16 == (int *)0x0) {
            Tcl_ResetResult(local_40);
          }
          else {
            Tcl_SetObjResult(local_40,piVar16);
          }
        }
        uVar13 = 0;
        if ((piVar16 != (int *)0x0) && (*piVar16 = *piVar16 + -1, *piVar16 < 1)) {
          (*pcVar12)(piVar16);
        }
      }
      else {
        pcVar10 = "reduce";
        ppuVar5 = ppuVar4;
        do {
          bVar1 = *(byte *)ppuVar5;
          bVar14 = bVar1 < (byte)*pcVar10;
          if (bVar1 != *pcVar10) {
LAB_006aa8e2:
            uVar6 = -(uint)bVar14 | 1;
            goto LAB_006aa8e7;
          }
          if (bVar1 == 0) break;
          bVar1 = *(byte *)((int)ppuVar5 + 1);
          bVar14 = bVar1 < ((byte *)pcVar10)[1];
          if (bVar1 != ((byte *)pcVar10)[1]) goto LAB_006aa8e2;
          ppuVar5 = (undefined **)((int)ppuVar5 + 2);
          pcVar10 = (char *)((byte *)pcVar10 + 2);
        } while (bVar1 != 0);
        uVar6 = 0;
LAB_006aa8e7:
        if (uVar6 == 0) {
          if (param_3 != 4) {
LAB_006aaba3:
            FUN_006bc8f0(3);
            goto LAB_006aad31;
          }
          FUN_004295e0(3);
          FUN_006baf80();
          FUN_005ff660();
          pcVar12 = TclFreeObj_exref;
          goto LAB_006aacd7;
        }
        pbVar9 = &DAT_00735470;
        ppuVar5 = ppuVar4;
        do {
          bVar1 = *(byte *)ppuVar5;
          bVar14 = bVar1 < *pbVar9;
          if (bVar1 != *pbVar9) {
LAB_006aa943:
            uVar6 = -(uint)bVar14 | 1;
            goto LAB_006aa948;
          }
          if (bVar1 == 0) break;
          bVar1 = *(byte *)((int)ppuVar5 + 1);
          bVar14 = bVar1 < pbVar9[1];
          if (bVar1 != pbVar9[1]) goto LAB_006aa943;
          ppuVar5 = (undefined **)((int)ppuVar5 + 2);
          pbVar9 = pbVar9 + 2;
        } while (bVar1 != 0);
        uVar6 = 0;
LAB_006aa948:
        if (uVar6 == 0) {
          uVar13 = FUN_006bad90();
          FUN_006baea0(uVar13);
          FUN_006bad60();
          pcVar12 = TclFreeObj_exref;
          piVar16 = local_14;
          goto LAB_006aacd7;
        }
        pbVar9 = &DAT_0072e624;
        ppuVar5 = ppuVar4;
        do {
          bVar1 = *(byte *)ppuVar5;
          bVar14 = bVar1 < *pbVar9;
          if (bVar1 != *pbVar9) {
LAB_006aa9a5:
            uVar6 = -(uint)bVar14 | 1;
            goto LAB_006aa9aa;
          }
          if (bVar1 == 0) break;
          bVar1 = *(byte *)((int)ppuVar5 + 1);
          bVar14 = bVar1 < pbVar9[1];
          if (bVar1 != pbVar9[1]) goto LAB_006aa9a5;
          ppuVar5 = (undefined **)((int)ppuVar5 + 2);
          pbVar9 = pbVar9 + 2;
        } while (bVar1 != 0);
        uVar6 = 0;
LAB_006aa9aa:
        if (uVar6 == 0) {
          if (param_3 != 4) goto LAB_006aaba3;
          piVar16 = (int *)FUN_004295e0(3);
          iVar3 = *(int *)(local_18 + 0x3f4);
          if (*piVar16 == 0) {
            ppuVar4 = &PTR_0071ce50;
          }
          else {
            ppuVar4 = (undefined **)Tcl_GetStringFromObj(*piVar16,0);
          }
          iVar7 = *(int *)(iVar3 + 0x10);
          if ((((iVar7 != 0) && (iVar7 = (**(code **)(iVar7 + 0x2c))(iVar7,ppuVar4), iVar7 != 0)) &&
              (uVar6 = *(int *)(iVar7 + 0xc) - 1, uVar6 != 0xffffffff)) &&
             (*(uint *)(iVar3 + 4) <= uVar6)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          uVar13 = FUN_006bad90();
          FUN_006baea0(uVar13);
          FUN_006bad60();
          pcVar12 = TclFreeObj_exref;
          piVar16 = local_14;
          goto LAB_006aacd7;
        }
        pbVar9 = &DAT_0072e630;
        ppuVar5 = ppuVar4;
        do {
          bVar1 = *(byte *)ppuVar5;
          bVar14 = bVar1 < *pbVar9;
          if (bVar1 != *pbVar9) {
LAB_006aaa76:
            uVar6 = -(uint)bVar14 | 1;
            goto LAB_006aaa7b;
          }
          if (bVar1 == 0) break;
          bVar1 = *(byte *)((int)ppuVar5 + 1);
          bVar14 = bVar1 < pbVar9[1];
          if (bVar1 != pbVar9[1]) goto LAB_006aaa76;
          ppuVar5 = (undefined **)((int)ppuVar5 + 2);
          pbVar9 = pbVar9 + 2;
        } while (bVar1 != 0);
        uVar6 = 0;
LAB_006aaa7b:
        if (uVar6 != 0) {
          pbVar9 = &DAT_0072e64c;
          ppuVar5 = ppuVar4;
          do {
            bVar1 = *(byte *)ppuVar5;
            bVar14 = bVar1 < *pbVar9;
            if (bVar1 != *pbVar9) {
LAB_006aab18:
              uVar6 = -(uint)bVar14 | 1;
              goto LAB_006aab1d;
            }
            if (bVar1 == 0) break;
            bVar1 = *(byte *)((int)ppuVar5 + 1);
            bVar14 = bVar1 < pbVar9[1];
            if (bVar1 != pbVar9[1]) goto LAB_006aab18;
            ppuVar5 = (undefined **)((int)ppuVar5 + 2);
            pbVar9 = pbVar9 + 2;
          } while (bVar1 != 0);
          uVar6 = 0;
LAB_006aab1d:
          if (uVar6 == 0) {
            uVar13 = FUN_005ff510(&local_1c);
            FUN_006baea0(uVar13);
            pcVar12 = TclFreeObj_exref;
            piVar16 = local_14;
            if ((local_1c != (int *)0x0) &&
               (*local_1c = *local_1c + -1, pcVar12 = TclFreeObj_exref, *local_1c < 1)) {
              TclFreeObj(local_1c);
              piVar16 = local_14;
            }
          }
          else {
            pcVar10 = "delete";
            do {
              bVar1 = *(byte *)ppuVar4;
              bVar14 = bVar1 < (byte)*pcVar10;
              if (bVar1 != *pcVar10) {
LAB_006aab90:
                uVar6 = -(uint)bVar14 | 1;
                goto LAB_006aab95;
              }
              if (bVar1 == 0) break;
              bVar1 = *(byte *)((int)ppuVar4 + 1);
              bVar14 = bVar1 < ((byte *)pcVar10)[1];
              if (bVar1 != ((byte *)pcVar10)[1]) goto LAB_006aab90;
              ppuVar4 = (undefined **)((int)ppuVar4 + 2);
              pcVar10 = (char *)((byte *)pcVar10 + 2);
            } while (bVar1 != 0);
            uVar6 = 0;
LAB_006aab95:
            if (uVar6 != 0) {
              puVar8 = (undefined4 *)FUN_004295e0(2);
              piVar16 = (int *)*puVar8;
              if (piVar16 != (int *)0x0) {
                *piVar16 = *piVar16 + 1;
              }
              FUN_006bc6a0("invalid talkissue command",piVar16);
              goto LAB_006aad31;
            }
            if (param_3 != 4) goto LAB_006aaba3;
            local_1c = (int *)FUN_004295e0(3);
            piVar2 = *(int **)(local_18 + 0x3f4);
            if (*local_1c == 0) {
              ppuVar4 = &PTR_0071ce50;
            }
            else {
              ppuVar4 = (undefined **)Tcl_GetStringFromObj(*local_1c,0);
            }
            iVar3 = piVar2[4];
            pcVar12 = TclFreeObj_exref;
            if (((iVar3 != 0) &&
                (iVar3 = (**(code **)(iVar3 + 0x2c))(iVar3,ppuVar4), pcVar12 = TclFreeObj_exref,
                iVar3 != 0)) && (uVar6 = *(int *)(iVar3 + 0xc) - 1, uVar6 != 0xffffffff)) {
              if ((uint)piVar2[1] <= uVar6) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              piVar2[6] = (int)((float)piVar2[6] - *(float *)(*piVar2 + uVar6 * 4));
              uVar11 = piVar2[3];
              if ((uVar11 + 0x10 & 0xfffffff0) != (uVar11 + 0xf & 0xfffffff0)) {
                iVar3 = FUN_006baad0("C:\\dev\\wiggles\\CodeLib\\StdTools\\KStdLib\\Include\\DSFastArray.h"
                                     ,0x9b);
                uVar11 = piVar2[3];
                piVar2[2] = iVar3;
              }
              piVar2[3] = uVar11 + 1;
              if (uVar11 + 1 <= uVar11) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              *(uint *)(piVar2[2] + uVar11 * 4) = uVar6;
              if (*local_1c == 0) {
                ppuVar4 = &PTR_0071ce50;
              }
              else {
                ppuVar4 = (undefined **)Tcl_GetStringFromObj(*local_1c,0);
              }
              iVar3 = piVar2[4];
              pcVar12 = TclFreeObj_exref;
              if ((iVar3 != 0) &&
                 (iVar3 = (**(code **)(iVar3 + 0x2c))(iVar3,ppuVar4), pcVar12 = TclFreeObj_exref,
                 iVar3 != 0)) {
                Tcl_DeleteHashEntry(iVar3);
                pcVar12 = TclFreeObj_exref;
              }
            }
          }
          goto LAB_006aacd7;
        }
        if (param_3 == 5) {
          FUN_004295e0(4);
          FUN_006baf80();
          uVar13 = FUN_004295e0(3);
          FUN_005ff160(uVar13);
          uVar13 = FUN_006bad90();
          FUN_006baea0(uVar13);
          FUN_006bad60();
          pcVar12 = TclFreeObj_exref;
          piVar16 = local_14;
          goto LAB_006aacd7;
        }
        FUN_006bc8f0(4);
LAB_006aad31:
        uVar13 = 1;
      }
      local_8._0_1_ = 4;
      FUN_004297b0(0);
      local_8._0_1_ = 5;
      FUN_004297b0(0);
      if (local_30 != (undefined4 *)0x0) {
        FUN_006ba940();
      }
      goto LAB_006aa759;
    }
    iVar3 = *(int *)(local_18 + 0xd8) + 0xc;
    if (iVar3 == 0) {
      piVar16 = (int *)0x0;
    }
    else {
      piVar16 = (int *)Tcl_NewStringObj(iVar3,0xffffffff,extraout_ECX);
      *piVar16 = *piVar16 + 1;
    }
    FUN_006bc6a0("object is not a gnome",piVar16);
  }
  uVar13 = 1;
LAB_006aa759:
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar13;
}

