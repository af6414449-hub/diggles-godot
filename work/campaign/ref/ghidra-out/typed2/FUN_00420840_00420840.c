
void FUN_00420840(undefined4 param_1,int *param_2,int param_3)

{
  float *pfVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined **ppuVar9;
  float *pfVar10;
  int in_ECX;
  code *pcVar11;
  CMap *pCVar12;
  int *piVar13;
  char *pcVar14;
  uint uVar15;
  byte *pbVar16;
  int *piVar17;
  bool bVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  undefined4 uVar22;
  undefined1 local_184 [12];
  undefined1 local_178 [12];
  undefined1 local_16c [24];
  double local_154;
  double local_14c;
  double local_144;
  double local_13c;
  int local_134;
  int *local_130;
  int *local_12c;
  uint local_128;
  int *local_124;
  uint local_120;
  int *local_11c;
  uint local_118;
  int *local_114;
  uint local_110;
  int *local_10c;
  int local_108;
  int *local_104;
  int *local_100;
  int *local_fc;
  int *local_f8;
  int *local_f4;
  int *local_f0;
  int *local_ec;
  int *local_e8;
  uint local_e4;
  int *local_e0;
  int *local_dc;
  int *local_d8;
  int *local_d4;
  int *local_d0;
  int *local_cc;
  int *local_c8;
  int *local_c4;
  int local_c0;
  int *local_bc;
  int *local_b8;
  int local_b4;
  int *local_b0;
  int *local_ac;
  uint local_a8;
  int *local_a4;
  int *local_a0;
  int local_9c;
  int *local_98;
  int *local_94;
  uint local_90;
  int *local_8c;
  int *local_88;
  uint local_84;
  int *local_80;
  int *local_7c;
  int local_78;
  int *local_74;
  int *local_70;
  int *local_6c;
  int *local_68;
  int local_64;
  int *local_60;
  int *local_5c;
  int local_58;
  int *local_54;
  int *local_50;
  uint local_4c;
  int *local_48;
  int *local_44;
  int *local_40;
  int *local_3c;
  int *local_38;
  int *local_34;
  int *local_30;
  int *local_2c;
  int *local_28;
  uint local_24;
  int *local_20;
  int *local_1c;
  int local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006fa455;
  local_10 = ExceptionList;
  uVar3 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0x1ec) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x3d0) = 0xffffffff;
  local_20 = (int *)0x0;
  local_24 = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x5b4) = 0;
  piVar17 = (int *)0x0;
  local_18 = in_ECX;
  while( true ) {
    iVar8 = local_18;
    local_14 = piVar17;
    if (*param_2 == 0) {
      iVar5 = 0;
    }
    else {
      iVar4 = Tcl_ListObjLength(0,*param_2,&local_134,uVar3);
      iVar5 = local_134;
      if (iVar4 != 0) {
        iVar5 = 0;
      }
    }
    iVar4 = local_18;
    local_28 = (int *)((int)piVar17 + 2);
    if (iVar5 < (int)local_28) break;
    if ((*param_2 == 0) ||
       (iVar5 = Tcl_ListObjIndex(0,*param_2,piVar17,&local_2c), piVar17 = local_2c, iVar5 != 0)) {
      piVar17 = (int *)0x0;
LAB_00420939:
      ppuVar9 = &PTR_0071ce50;
      pcVar14 = "-target";
      do {
        bVar2 = *(byte *)ppuVar9;
        bVar18 = bVar2 < (byte)*pcVar14;
        if (bVar2 != *pcVar14) {
LAB_00420963:
          uVar15 = -(uint)bVar18 | 1;
          goto LAB_00420968;
        }
        if (bVar2 == 0) break;
        bVar2 = *(byte *)((int)ppuVar9 + 1);
        bVar18 = bVar2 < ((byte *)pcVar14)[1];
        if (bVar2 != ((byte *)pcVar14)[1]) goto LAB_00420963;
        ppuVar9 = (undefined **)((int)ppuVar9 + 2);
        pcVar14 = (char *)((byte *)pcVar14 + 2);
      } while (bVar2 != 0);
      uVar15 = 0;
LAB_00420968:
      if (piVar17 != (int *)0x0) goto LAB_0042096c;
    }
    else {
      if (local_2c == (int *)0x0) goto LAB_00420939;
      *local_2c = *local_2c + 1;
      pcVar14 = "-target";
      pbVar6 = (byte *)Tcl_GetStringFromObj(local_2c,0);
      do {
        bVar2 = *pbVar6;
        bVar18 = bVar2 < (byte)*pcVar14;
        if (bVar2 != *pcVar14) {
LAB_00420930:
          uVar15 = -(uint)bVar18 | 1;
          goto LAB_0042096c;
        }
        if (bVar2 == 0) break;
        bVar2 = pbVar6[1];
        bVar18 = bVar2 < ((byte *)pcVar14)[1];
        if (bVar2 != ((byte *)pcVar14)[1]) goto LAB_00420930;
        pbVar6 = pbVar6 + 2;
        pcVar14 = (char *)((byte *)pcVar14 + 2);
      } while (bVar2 != 0);
      uVar15 = 0;
LAB_0042096c:
      *piVar17 = *piVar17 + -1;
      if (*piVar17 < 1) {
        TclFreeObj(piVar17);
      }
    }
    iVar5 = *param_2;
    if (uVar15 == 0) {
      if ((iVar5 == 0) ||
         (iVar5 = Tcl_ListObjIndex(0,iVar5,(int)local_14 + 1,&local_30), iVar5 != 0)) {
        local_14 = (int *)0x0;
      }
      else {
        local_14 = local_30;
        if (local_30 != (int *)0x0) {
          *local_30 = *local_30 + 1;
        }
      }
      piVar13 = local_14;
      puVar7 = (undefined4 *)FUN_006bafe0(local_16c);
      *(undefined4 *)(iVar8 + 0x7a4) = *puVar7;
      *(undefined4 *)(iVar8 + 0x7a8) = puVar7[1];
      *(undefined4 *)(iVar8 + 0x7ac) = puVar7[2];
      piVar17 = local_28;
      if ((piVar13 != (int *)0x0) && (*piVar13 = *piVar13 + -1, *piVar13 < 1)) {
        TclFreeObj(piVar13);
        piVar17 = local_28;
      }
    }
    else {
      if ((iVar5 == 0) ||
         (iVar5 = Tcl_ListObjIndex(0,iVar5,local_14,&local_34), piVar17 = local_34, iVar5 != 0)) {
        piVar17 = (int *)0x0;
LAB_00420a71:
        ppuVar9 = &PTR_0071ce50;
        pbVar6 = &DAT_0071d65c;
        do {
          bVar2 = *(byte *)ppuVar9;
          bVar18 = bVar2 < *pbVar6;
          if (bVar2 != *pbVar6) {
LAB_00420aa0:
            uVar15 = -(uint)bVar18 | 1;
            goto LAB_00420aa5;
          }
          if (bVar2 == 0) break;
          bVar2 = *(byte *)((int)ppuVar9 + 1);
          bVar18 = bVar2 < pbVar6[1];
          if (bVar2 != pbVar6[1]) goto LAB_00420aa0;
          ppuVar9 = (undefined **)((int)ppuVar9 + 2);
          pbVar6 = pbVar6 + 2;
        } while (bVar2 != 0);
        uVar15 = 0;
LAB_00420aa5:
        if (piVar17 != (int *)0x0) goto LAB_00420aa9;
      }
      else {
        if (local_34 == (int *)0x0) goto LAB_00420a71;
        *local_34 = *local_34 + 1;
        pbVar16 = &DAT_0071d65c;
        pbVar6 = (byte *)Tcl_GetStringFromObj(local_34,0);
        do {
          bVar2 = *pbVar6;
          bVar18 = bVar2 < *pbVar16;
          if (bVar2 != *pbVar16) {
LAB_00420a68:
            uVar15 = -(uint)bVar18 | 1;
            goto LAB_00420aa9;
          }
          if (bVar2 == 0) break;
          bVar2 = pbVar6[1];
          bVar18 = bVar2 < pbVar16[1];
          if (bVar2 != pbVar16[1]) goto LAB_00420a68;
          pbVar6 = pbVar6 + 2;
          pbVar16 = pbVar16 + 2;
        } while (bVar2 != 0);
        uVar15 = 0;
LAB_00420aa9:
        *piVar17 = *piVar17 + -1;
        if (*piVar17 < 1) {
          TclFreeObj(piVar17);
        }
      }
      iVar5 = *param_2;
      if (uVar15 == 0) {
        if ((iVar5 == 0) ||
           (iVar8 = Tcl_ListObjIndex(0,iVar5,(int)local_14 + 1,&local_38), piVar13 = local_38,
           iVar8 != 0)) {
          local_14 = (int *)0x0;
LAB_00420b04:
          piVar13 = local_14;
          FUN_006bafe0(local_178);
        }
        else {
          local_14 = local_38;
          if (local_38 == (int *)0x0) goto LAB_00420b04;
          *local_38 = *local_38 + 1;
          FUN_006bafe0(local_178);
        }
        goto LAB_00422498;
      }
      if ((iVar5 == 0) ||
         (iVar5 = Tcl_ListObjIndex(0,iVar5,local_14,&local_3c), piVar17 = local_3c, iVar5 != 0)) {
        piVar17 = (int *)0x0;
LAB_00420b79:
        ppuVar9 = &PTR_0071ce50;
        pcVar14 = "-object";
        do {
          bVar2 = *(byte *)ppuVar9;
          bVar18 = bVar2 < (byte)*pcVar14;
          if (bVar2 != *pcVar14) {
LAB_00420ba3:
            uVar15 = -(uint)bVar18 | 1;
            goto LAB_00420ba8;
          }
          if (bVar2 == 0) break;
          bVar2 = *(byte *)((int)ppuVar9 + 1);
          bVar18 = bVar2 < ((byte *)pcVar14)[1];
          if (bVar2 != ((byte *)pcVar14)[1]) goto LAB_00420ba3;
          ppuVar9 = (undefined **)((int)ppuVar9 + 2);
          pcVar14 = (char *)((byte *)pcVar14 + 2);
        } while (bVar2 != 0);
        uVar15 = 0;
LAB_00420ba8:
        if (piVar17 != (int *)0x0) goto LAB_00420bac;
      }
      else {
        if (local_3c == (int *)0x0) goto LAB_00420b79;
        *local_3c = *local_3c + 1;
        pcVar14 = "-object";
        pbVar6 = (byte *)Tcl_GetStringFromObj(local_3c,0);
        do {
          bVar2 = *pbVar6;
          bVar18 = bVar2 < (byte)*pcVar14;
          if (bVar2 != *pcVar14) {
LAB_00420b70:
            uVar15 = -(uint)bVar18 | 1;
            goto LAB_00420bac;
          }
          if (bVar2 == 0) break;
          bVar2 = pbVar6[1];
          bVar18 = bVar2 < ((byte *)pcVar14)[1];
          if (bVar2 != ((byte *)pcVar14)[1]) goto LAB_00420b70;
          pbVar6 = pbVar6 + 2;
          pcVar14 = (char *)((byte *)pcVar14 + 2);
        } while (bVar2 != 0);
        uVar15 = 0;
LAB_00420bac:
        *piVar17 = *piVar17 + -1;
        if (*piVar17 < 1) {
          TclFreeObj(piVar17);
        }
      }
      iVar5 = *param_2;
      if (uVar15 == 0) {
        if ((iVar5 == 0) ||
           (iVar5 = Tcl_ListObjIndex(0,iVar5,(int)local_14 + 1,&local_40), iVar5 != 0)) {
          local_20 = (int *)0x0;
        }
        else {
          local_20 = local_40;
          if (local_40 != (int *)0x0) {
            *local_40 = *local_40 + 1;
          }
        }
        piVar17 = local_20;
        local_8 = 0;
        local_20 = (int *)FUN_005c8310(param_1,&local_20);
        local_8 = 0xffffffff;
        if ((piVar17 != (int *)0x0) && (*piVar17 = *piVar17 + -1, *piVar17 < 1)) {
          TclFreeObj(piVar17);
        }
        *(undefined1 *)(iVar8 + 0x7bf) = 1;
        piVar17 = local_28;
      }
      else {
        if ((iVar5 == 0) ||
           (iVar5 = Tcl_ListObjIndex(0,iVar5,local_14,&local_44), piVar17 = local_44, iVar5 != 0)) {
          piVar17 = (int *)0x0;
LAB_00420ca9:
          ppuVar9 = &PTR_0071ce50;
          pbVar6 = &DAT_0071d66c;
          do {
            bVar2 = *(byte *)ppuVar9;
            bVar18 = bVar2 < *pbVar6;
            if (bVar2 != *pbVar6) {
LAB_00420cd3:
              uVar15 = -(uint)bVar18 | 1;
              goto LAB_00420cd8;
            }
            if (bVar2 == 0) break;
            bVar2 = *(byte *)((int)ppuVar9 + 1);
            bVar18 = bVar2 < pbVar6[1];
            if (bVar2 != pbVar6[1]) goto LAB_00420cd3;
            ppuVar9 = (undefined **)((int)ppuVar9 + 2);
            pbVar6 = pbVar6 + 2;
          } while (bVar2 != 0);
          uVar15 = 0;
LAB_00420cd8:
          if (piVar17 != (int *)0x0) goto LAB_00420cdc;
        }
        else {
          if (local_44 == (int *)0x0) goto LAB_00420ca9;
          *local_44 = *local_44 + 1;
          pbVar16 = &DAT_0071d66c;
          pbVar6 = (byte *)Tcl_GetStringFromObj(local_44,0);
          do {
            bVar2 = *pbVar6;
            bVar18 = bVar2 < *pbVar16;
            if (bVar2 != *pbVar16) {
LAB_00420ca0:
              uVar15 = -(uint)bVar18 | 1;
              goto LAB_00420cdc;
            }
            if (bVar2 == 0) break;
            bVar2 = pbVar6[1];
            bVar18 = bVar2 < pbVar16[1];
            if (bVar2 != pbVar16[1]) goto LAB_00420ca0;
            pbVar6 = pbVar6 + 2;
            pbVar16 = pbVar16 + 2;
          } while (bVar2 != 0);
          uVar15 = 0;
LAB_00420cdc:
          *piVar17 = *piVar17 + -1;
          if (*piVar17 < 1) {
            TclFreeObj(piVar17);
          }
        }
        iVar5 = *param_2;
        if (uVar15 == 0) {
          if (((iVar5 != 0) &&
              (iVar8 = Tcl_ListObjIndex(0,iVar5,(int)local_14 + 1,&local_48), piVar13 = local_48,
              iVar8 == 0)) && (local_48 != (int *)0x0)) {
            *local_48 = *local_48 + 1;
            iVar8 = Tcl_GetIntFromObj(0,local_48,&local_4c);
            local_24 = -(uint)(iVar8 != 1) & local_4c;
            goto LAB_0042249c;
          }
          local_24 = 0;
          piVar17 = local_28;
        }
        else {
          if ((iVar5 == 0) ||
             (iVar5 = Tcl_ListObjIndex(0,iVar5,local_14,&local_50), piVar17 = local_50, iVar5 != 0))
          {
            piVar17 = (int *)0x0;
LAB_00420dae:
            ppuVar9 = &PTR_0071ce50;
            pcVar14 = "-dontstop";
            do {
              bVar2 = *(byte *)ppuVar9;
              bVar18 = bVar2 < (byte)*pcVar14;
              if (bVar2 != *pcVar14) {
LAB_00420dd8:
                uVar15 = -(uint)bVar18 | 1;
                goto LAB_00420ddd;
              }
              if (bVar2 == 0) break;
              bVar2 = *(byte *)((int)ppuVar9 + 1);
              bVar18 = bVar2 < ((byte *)pcVar14)[1];
              if (bVar2 != ((byte *)pcVar14)[1]) goto LAB_00420dd8;
              ppuVar9 = (undefined **)((int)ppuVar9 + 2);
              pcVar14 = (char *)((byte *)pcVar14 + 2);
            } while (bVar2 != 0);
            uVar15 = 0;
LAB_00420ddd:
            if (piVar17 != (int *)0x0) goto LAB_00420de1;
          }
          else {
            if (local_50 == (int *)0x0) goto LAB_00420dae;
            *local_50 = *local_50 + 1;
            pcVar14 = "-dontstop";
            pbVar6 = (byte *)Tcl_GetStringFromObj(local_50,0);
            do {
              bVar2 = *pbVar6;
              bVar18 = bVar2 < (byte)*pcVar14;
              if (bVar2 != *pcVar14) {
LAB_00420da5:
                uVar15 = -(uint)bVar18 | 1;
                goto LAB_00420de1;
              }
              if (bVar2 == 0) break;
              bVar2 = pbVar6[1];
              bVar18 = bVar2 < ((byte *)pcVar14)[1];
              if (bVar2 != ((byte *)pcVar14)[1]) goto LAB_00420da5;
              pbVar6 = pbVar6 + 2;
              pcVar14 = (char *)((byte *)pcVar14 + 2);
            } while (bVar2 != 0);
            uVar15 = 0;
LAB_00420de1:
            *piVar17 = *piVar17 + -1;
            if (*piVar17 < 1) {
              TclFreeObj(piVar17);
            }
          }
          iVar5 = *param_2;
          if (uVar15 == 0) {
            if ((iVar5 == 0) ||
               (iVar5 = Tcl_ListObjIndex(0,iVar5,(int)local_14 + 1,&local_54), piVar13 = local_54,
               iVar5 != 0)) {
              piVar13 = (int *)0x0;
            }
            else if (local_54 != (int *)0x0) {
              *local_54 = *local_54 + 1;
              iVar5 = Tcl_GetBooleanFromObj(0,local_54,&local_58);
              if (iVar5 == 1) {
                *(undefined1 *)(iVar8 + 0x79d) = 0;
              }
              else {
                *(bool *)(iVar8 + 0x79d) = local_58 != 0;
              }
              goto LAB_0042249c;
            }
            *(undefined1 *)(iVar8 + 0x79d) = 0;
            goto LAB_00422498;
          }
          if ((iVar5 == 0) ||
             (iVar5 = Tcl_ListObjIndex(0,iVar5,local_14,&local_5c), piVar17 = local_5c, iVar5 != 0))
          {
            piVar17 = (int *)0x0;
LAB_00420ebe:
            ppuVar9 = &PTR_0071ce50;
            pcVar14 = "-canclimb";
            do {
              bVar2 = *(byte *)ppuVar9;
              bVar18 = bVar2 < (byte)*pcVar14;
              if (bVar2 != *pcVar14) {
LAB_00420ee8:
                uVar15 = -(uint)bVar18 | 1;
                goto LAB_00420eed;
              }
              if (bVar2 == 0) break;
              bVar2 = *(byte *)((int)ppuVar9 + 1);
              bVar18 = bVar2 < ((byte *)pcVar14)[1];
              if (bVar2 != ((byte *)pcVar14)[1]) goto LAB_00420ee8;
              ppuVar9 = (undefined **)((int)ppuVar9 + 2);
              pcVar14 = (char *)((byte *)pcVar14 + 2);
            } while (bVar2 != 0);
            uVar15 = 0;
LAB_00420eed:
            if (piVar17 != (int *)0x0) goto LAB_00420ef1;
          }
          else {
            if (local_5c == (int *)0x0) goto LAB_00420ebe;
            *local_5c = *local_5c + 1;
            pcVar14 = "-canclimb";
            pbVar6 = (byte *)Tcl_GetStringFromObj(local_5c,0);
            do {
              bVar2 = *pbVar6;
              bVar18 = bVar2 < (byte)*pcVar14;
              if (bVar2 != *pcVar14) {
LAB_00420eb5:
                uVar15 = -(uint)bVar18 | 1;
                goto LAB_00420ef1;
              }
              if (bVar2 == 0) break;
              bVar2 = pbVar6[1];
              bVar18 = bVar2 < ((byte *)pcVar14)[1];
              if (bVar2 != ((byte *)pcVar14)[1]) goto LAB_00420eb5;
              pbVar6 = pbVar6 + 2;
              pcVar14 = (char *)((byte *)pcVar14 + 2);
            } while (bVar2 != 0);
            uVar15 = 0;
LAB_00420ef1:
            *piVar17 = *piVar17 + -1;
            if (*piVar17 < 1) {
              TclFreeObj(piVar17);
            }
          }
          iVar5 = *param_2;
          if (uVar15 == 0) {
            if ((iVar5 == 0) ||
               (iVar5 = Tcl_ListObjIndex(0,iVar5,(int)local_14 + 1,&local_60), piVar13 = local_60,
               iVar5 != 0)) {
              piVar13 = (int *)0x0;
            }
            else if (local_60 != (int *)0x0) {
              *local_60 = *local_60 + 1;
              iVar5 = Tcl_GetBooleanFromObj(0,local_60,&local_64);
              if (iVar5 == 1) {
                *(undefined1 *)(iVar8 + 0x7b0) = 0;
              }
              else {
                *(bool *)(iVar8 + 0x7b0) = local_64 != 0;
              }
              goto LAB_0042249c;
            }
            *(undefined1 *)(iVar8 + 0x7b0) = 0;
            goto LAB_00422498;
          }
          if ((iVar5 == 0) ||
             (iVar5 = Tcl_ListObjIndex(0,iVar5,local_14,&local_68), piVar17 = local_68, iVar5 != 0))
          {
            piVar17 = (int *)0x0;
LAB_00420fce:
            ppuVar9 = &PTR_0071ce50;
            pcVar14 = "-stopat";
            do {
              bVar2 = *(byte *)ppuVar9;
              bVar18 = bVar2 < (byte)*pcVar14;
              if (bVar2 != *pcVar14) {
LAB_00420ff8:
                uVar15 = -(uint)bVar18 | 1;
                goto LAB_00420ffd;
              }
              if (bVar2 == 0) break;
              bVar2 = *(byte *)((int)ppuVar9 + 1);
              bVar18 = bVar2 < ((byte *)pcVar14)[1];
              if (bVar2 != ((byte *)pcVar14)[1]) goto LAB_00420ff8;
              ppuVar9 = (undefined **)((int)ppuVar9 + 2);
              pcVar14 = (char *)((byte *)pcVar14 + 2);
            } while (bVar2 != 0);
            uVar15 = 0;
LAB_00420ffd:
            if (piVar17 != (int *)0x0) goto LAB_00421001;
          }
          else {
            if (local_68 == (int *)0x0) goto LAB_00420fce;
            *local_68 = *local_68 + 1;
            pcVar14 = "-stopat";
            pbVar6 = (byte *)Tcl_GetStringFromObj(local_68,0);
            do {
              bVar2 = *pbVar6;
              bVar18 = bVar2 < (byte)*pcVar14;
              if (bVar2 != *pcVar14) {
LAB_00420fc5:
                uVar15 = -(uint)bVar18 | 1;
                goto LAB_00421001;
              }
              if (bVar2 == 0) break;
              bVar2 = pbVar6[1];
              bVar18 = bVar2 < ((byte *)pcVar14)[1];
              if (bVar2 != ((byte *)pcVar14)[1]) goto LAB_00420fc5;
              pbVar6 = pbVar6 + 2;
              pcVar14 = (char *)((byte *)pcVar14 + 2);
            } while (bVar2 != 0);
            uVar15 = 0;
LAB_00421001:
            *piVar17 = *piVar17 + -1;
            if (*piVar17 < 1) {
              TclFreeObj(piVar17);
            }
          }
          iVar5 = *param_2;
          if (uVar15 == 0) {
            if ((iVar5 == 0) ||
               (iVar5 = Tcl_ListObjIndex(0,iVar5,(int)local_14 + 1,&local_6c), piVar13 = local_6c,
               iVar5 != 0)) {
              piVar13 = (int *)0x0;
            }
            else if (local_6c != (int *)0x0) {
              *local_6c = *local_6c + 1;
              iVar5 = Tcl_GetDoubleFromObj(0,local_6c,&local_13c);
              if (iVar5 == 1) {
                *(undefined4 *)(iVar8 + 0x7a0) = 0;
              }
              else {
                *(float *)(iVar8 + 0x7a0) = (float)local_13c;
              }
              goto LAB_0042249c;
            }
            *(undefined4 *)(iVar8 + 0x7a0) = 0;
            goto LAB_00422498;
          }
          if ((iVar5 == 0) ||
             (iVar5 = Tcl_ListObjIndex(0,iVar5,local_14,&local_70), piVar17 = local_70, iVar5 != 0))
          {
            piVar17 = (int *)0x0;
LAB_004210ee:
            ppuVar9 = &PTR_0071ce50;
            pcVar14 = "-useobjects";
            do {
              bVar2 = *(byte *)ppuVar9;
              bVar18 = bVar2 < (byte)*pcVar14;
              if (bVar2 != *pcVar14) {
LAB_00421118:
                uVar15 = -(uint)bVar18 | 1;
                goto LAB_0042111d;
              }
              if (bVar2 == 0) break;
              bVar2 = *(byte *)((int)ppuVar9 + 1);
              bVar18 = bVar2 < ((byte *)pcVar14)[1];
              if (bVar2 != ((byte *)pcVar14)[1]) goto LAB_00421118;
              ppuVar9 = (undefined **)((int)ppuVar9 + 2);
              pcVar14 = (char *)((byte *)pcVar14 + 2);
            } while (bVar2 != 0);
            uVar15 = 0;
LAB_0042111d:
            if (piVar17 != (int *)0x0) goto LAB_00421121;
          }
          else {
            if (local_70 == (int *)0x0) goto LAB_004210ee;
            *local_70 = *local_70 + 1;
            pcVar14 = "-useobjects";
            pbVar6 = (byte *)Tcl_GetStringFromObj(local_70,0);
            do {
              bVar2 = *pbVar6;
              bVar18 = bVar2 < (byte)*pcVar14;
              if (bVar2 != *pcVar14) {
LAB_004210e5:
                uVar15 = -(uint)bVar18 | 1;
                goto LAB_00421121;
              }
              if (bVar2 == 0) break;
              bVar2 = pbVar6[1];
              bVar18 = bVar2 < ((byte *)pcVar14)[1];
              if (bVar2 != ((byte *)pcVar14)[1]) goto LAB_004210e5;
              pbVar6 = pbVar6 + 2;
              pcVar14 = (char *)((byte *)pcVar14 + 2);
            } while (bVar2 != 0);
            uVar15 = 0;
LAB_00421121:
            *piVar17 = *piVar17 + -1;
            if (*piVar17 < 1) {
              TclFreeObj(piVar17);
            }
          }
          iVar5 = *param_2;
          if (uVar15 == 0) {
            if ((iVar5 == 0) ||
               (iVar5 = Tcl_ListObjIndex(0,iVar5,(int)local_14 + 1,&local_74), piVar13 = local_74,
               iVar5 != 0)) {
              piVar13 = (int *)0x0;
            }
            else if (local_74 != (int *)0x0) {
              *local_74 = *local_74 + 1;
              iVar5 = Tcl_GetBooleanFromObj(0,local_74,&local_78);
              if (iVar5 == 1) {
                *(undefined1 *)(iVar8 + 0x7b1) = 0;
              }
              else {
                *(bool *)(iVar8 + 0x7b1) = local_78 != 0;
              }
              goto LAB_0042249c;
            }
            *(undefined1 *)(iVar8 + 0x7b1) = 0;
            goto LAB_00422498;
          }
          if ((iVar5 == 0) ||
             (iVar5 = Tcl_ListObjIndex(0,iVar5,local_14,&local_7c), piVar17 = local_7c, iVar5 != 0))
          {
            piVar17 = (int *)0x0;
LAB_004211fe:
            ppuVar9 = &PTR_0071ce50;
            pcVar14 = "-speedtype";
            do {
              bVar2 = *(byte *)ppuVar9;
              bVar18 = bVar2 < (byte)*pcVar14;
              if (bVar2 != *pcVar14) {
LAB_00421228:
                uVar15 = -(uint)bVar18 | 1;
                goto LAB_0042122d;
              }
              if (bVar2 == 0) break;
              bVar2 = *(byte *)((int)ppuVar9 + 1);
              bVar18 = bVar2 < ((byte *)pcVar14)[1];
              if (bVar2 != ((byte *)pcVar14)[1]) goto LAB_00421228;
              ppuVar9 = (undefined **)((int)ppuVar9 + 2);
              pcVar14 = (char *)((byte *)pcVar14 + 2);
            } while (bVar2 != 0);
            uVar15 = 0;
LAB_0042122d:
            if (piVar17 != (int *)0x0) goto LAB_00421231;
          }
          else {
            if (local_7c == (int *)0x0) goto LAB_004211fe;
            *local_7c = *local_7c + 1;
            pcVar14 = "-speedtype";
            pbVar6 = (byte *)Tcl_GetStringFromObj(local_7c,0);
            do {
              bVar2 = *pbVar6;
              bVar18 = bVar2 < (byte)*pcVar14;
              if (bVar2 != *pcVar14) {
LAB_004211f5:
                uVar15 = -(uint)bVar18 | 1;
                goto LAB_00421231;
              }
              if (bVar2 == 0) break;
              bVar2 = pbVar6[1];
              bVar18 = bVar2 < ((byte *)pcVar14)[1];
              if (bVar2 != ((byte *)pcVar14)[1]) goto LAB_004211f5;
              pbVar6 = pbVar6 + 2;
              pcVar14 = (char *)((byte *)pcVar14 + 2);
            } while (bVar2 != 0);
            uVar15 = 0;
LAB_00421231:
            *piVar17 = *piVar17 + -1;
            if (*piVar17 < 1) {
              TclFreeObj(piVar17);
            }
          }
          iVar5 = *param_2;
          if (uVar15 == 0) {
            if ((iVar5 == 0) ||
               (iVar5 = Tcl_ListObjIndex(0,iVar5,(int)local_14 + 1,&local_80), piVar13 = local_80,
               iVar5 != 0)) {
              piVar13 = (int *)0x0;
            }
            else if (local_80 != (int *)0x0) {
              *local_80 = *local_80 + 1;
              iVar5 = Tcl_GetIntFromObj(0,local_80,&local_84);
              *(uint *)(iVar8 + 0x7e8) = -(uint)(iVar5 != 1) & local_84;
              goto LAB_0042249c;
            }
            *(undefined4 *)(iVar8 + 0x7e8) = 0;
            goto LAB_00422498;
          }
          if ((iVar5 == 0) ||
             (iVar5 = Tcl_ListObjIndex(0,iVar5,local_14,&local_88), piVar17 = local_88, iVar5 != 0))
          {
            piVar17 = (int *)0x0;
LAB_00421309:
            ppuVar9 = &PTR_0071ce50;
            pcVar14 = "-randompath";
            do {
              bVar2 = *(byte *)ppuVar9;
              bVar18 = bVar2 < (byte)*pcVar14;
              if (bVar2 != *pcVar14) {
LAB_00421333:
                uVar15 = -(uint)bVar18 | 1;
                goto LAB_00421338;
              }
              if (bVar2 == 0) break;
              bVar2 = *(byte *)((int)ppuVar9 + 1);
              bVar18 = bVar2 < ((byte *)pcVar14)[1];
              if (bVar2 != ((byte *)pcVar14)[1]) goto LAB_00421333;
              ppuVar9 = (undefined **)((int)ppuVar9 + 2);
              pcVar14 = (char *)((byte *)pcVar14 + 2);
            } while (bVar2 != 0);
            uVar15 = 0;
LAB_00421338:
            if (piVar17 != (int *)0x0) goto LAB_0042133c;
          }
          else {
            if (local_88 == (int *)0x0) goto LAB_00421309;
            *local_88 = *local_88 + 1;
            pcVar14 = "-randompath";
            pbVar6 = (byte *)Tcl_GetStringFromObj(local_88,0);
            do {
              bVar2 = *pbVar6;
              bVar18 = bVar2 < (byte)*pcVar14;
              if (bVar2 != *pcVar14) {
LAB_00421300:
                uVar15 = -(uint)bVar18 | 1;
                goto LAB_0042133c;
              }
              if (bVar2 == 0) break;
              bVar2 = pbVar6[1];
              bVar18 = bVar2 < ((byte *)pcVar14)[1];
              if (bVar2 != ((byte *)pcVar14)[1]) goto LAB_00421300;
              pbVar6 = pbVar6 + 2;
              pcVar14 = (char *)((byte *)pcVar14 + 2);
            } while (bVar2 != 0);
            uVar15 = 0;
LAB_0042133c:
            *piVar17 = *piVar17 + -1;
            if (*piVar17 < 1) {
              TclFreeObj(piVar17);
            }
          }
          iVar5 = *param_2;
          if (uVar15 == 0) {
            if ((iVar5 == 0) ||
               (iVar5 = Tcl_ListObjIndex(0,iVar5,(int)local_14 + 1,&local_8c), piVar13 = local_8c,
               iVar5 != 0)) {
              piVar13 = (int *)0x0;
            }
            else if (local_8c != (int *)0x0) {
              *local_8c = *local_8c + 1;
              iVar5 = Tcl_GetIntFromObj(0,local_8c,&local_90);
              *(uint *)(iVar8 + 0x7b4) = -(uint)(iVar5 != 1) & local_90;
              goto LAB_0042249c;
            }
            *(undefined4 *)(iVar8 + 0x7b4) = 0;
            goto LAB_00422498;
          }
          if ((iVar5 == 0) ||
             (iVar5 = Tcl_ListObjIndex(0,iVar5,local_14,&local_94), piVar17 = local_94, iVar5 != 0))
          {
            piVar17 = (int *)0x0;
LAB_00421421:
            ppuVar9 = &PTR_0071ce50;
            pcVar14 = "-waving";
            do {
              bVar2 = *(byte *)ppuVar9;
              bVar18 = bVar2 < (byte)*pcVar14;
              if (bVar2 != *pcVar14) {
LAB_00421450:
                uVar15 = -(uint)bVar18 | 1;
                goto LAB_00421455;
              }
              if (bVar2 == 0) break;
              bVar2 = *(byte *)((int)ppuVar9 + 1);
              bVar18 = bVar2 < ((byte *)pcVar14)[1];
              if (bVar2 != ((byte *)pcVar14)[1]) goto LAB_00421450;
              ppuVar9 = (undefined **)((int)ppuVar9 + 2);
              pcVar14 = (char *)((byte *)pcVar14 + 2);
            } while (bVar2 != 0);
            uVar15 = 0;
LAB_00421455:
            if (piVar17 != (int *)0x0) goto LAB_00421459;
          }
          else {
            if (local_94 == (int *)0x0) goto LAB_00421421;
            *local_94 = *local_94 + 1;
            pcVar14 = "-waving";
            pbVar6 = (byte *)Tcl_GetStringFromObj(local_94,0);
            do {
              bVar2 = *pbVar6;
              bVar18 = bVar2 < (byte)*pcVar14;
              if (bVar2 != *pcVar14) {
LAB_00421418:
                uVar15 = -(uint)bVar18 | 1;
                goto LAB_00421459;
              }
              if (bVar2 == 0) break;
              bVar2 = pbVar6[1];
              bVar18 = bVar2 < ((byte *)pcVar14)[1];
              if (bVar2 != ((byte *)pcVar14)[1]) goto LAB_00421418;
              pbVar6 = pbVar6 + 2;
              pcVar14 = (char *)((byte *)pcVar14 + 2);
            } while (bVar2 != 0);
            uVar15 = 0;
LAB_00421459:
            *piVar17 = *piVar17 + -1;
            if (*piVar17 < 1) {
              TclFreeObj(piVar17);
            }
          }
          iVar5 = *param_2;
          if (uVar15 == 0) {
            if ((iVar5 == 0) ||
               (iVar5 = Tcl_ListObjIndex(0,iVar5,(int)local_14 + 1,&local_98), piVar13 = local_98,
               iVar5 != 0)) {
              piVar13 = (int *)0x0;
            }
            else if (local_98 != (int *)0x0) {
              *local_98 = *local_98 + 1;
              iVar5 = Tcl_GetBooleanFromObj(0,local_98,&local_9c);
              if (iVar5 == 1) {
                *(undefined1 *)(iVar8 + 0x79c) = 0;
              }
              else {
                *(bool *)(iVar8 + 0x79c) = local_9c != 0;
              }
              goto LAB_0042249c;
            }
            *(undefined1 *)(iVar8 + 0x79c) = 0;
            goto LAB_00422498;
          }
          if ((iVar5 == 0) ||
             (iVar5 = Tcl_ListObjIndex(0,iVar5,local_14,&local_a0), piVar17 = local_a0, iVar5 != 0))
          {
            piVar17 = (int *)0x0;
LAB_00421550:
            ppuVar9 = &PTR_0071ce50;
            pcVar14 = "-randomz";
            do {
              bVar2 = *(byte *)ppuVar9;
              bVar18 = bVar2 < (byte)*pcVar14;
              if (bVar2 != *pcVar14) {
LAB_00421580:
                uVar15 = -(uint)bVar18 | 1;
                goto LAB_00421585;
              }
              if (bVar2 == 0) break;
              bVar2 = *(byte *)((int)ppuVar9 + 1);
              bVar18 = bVar2 < ((byte *)pcVar14)[1];
              if (bVar2 != ((byte *)pcVar14)[1]) goto LAB_00421580;
              ppuVar9 = (undefined **)((int)ppuVar9 + 2);
              pcVar14 = (char *)((byte *)pcVar14 + 2);
            } while (bVar2 != 0);
            uVar15 = 0;
LAB_00421585:
            if (piVar17 != (int *)0x0) goto LAB_00421589;
          }
          else {
            if (local_a0 == (int *)0x0) goto LAB_00421550;
            *local_a0 = *local_a0 + 1;
            pcVar14 = "-randomz";
            pbVar6 = (byte *)Tcl_GetStringFromObj(local_a0,0);
            do {
              bVar2 = *pbVar6;
              bVar18 = bVar2 < (byte)*pcVar14;
              if (bVar2 != *pcVar14) {
LAB_00421547:
                uVar15 = -(uint)bVar18 | 1;
                goto LAB_00421589;
              }
              if (bVar2 == 0) break;
              bVar2 = pbVar6[1];
              bVar18 = bVar2 < ((byte *)pcVar14)[1];
              if (bVar2 != ((byte *)pcVar14)[1]) goto LAB_00421547;
              pbVar6 = pbVar6 + 2;
              pcVar14 = (char *)((byte *)pcVar14 + 2);
            } while (bVar2 != 0);
            uVar15 = 0;
LAB_00421589:
            *piVar17 = *piVar17 + -1;
            if (*piVar17 < 1) {
              TclFreeObj(piVar17);
            }
          }
          iVar5 = *param_2;
          if (uVar15 == 0) {
            if ((iVar5 == 0) ||
               (iVar5 = Tcl_ListObjIndex(0,iVar5,(int)local_14 + 1,&local_a4), piVar13 = local_a4,
               iVar5 != 0)) {
              piVar13 = (int *)0x0;
            }
            else if (local_a4 != (int *)0x0) {
              *local_a4 = *local_a4 + 1;
              iVar5 = Tcl_GetIntFromObj(0,local_a4,&local_a8);
              *(uint *)(iVar8 + 0x7b8) = -(uint)(iVar5 != 1) & local_a8;
              goto LAB_0042249c;
            }
            *(undefined4 *)(iVar8 + 0x7b8) = 0;
            goto LAB_00422498;
          }
          if ((iVar5 == 0) ||
             (iVar5 = Tcl_ListObjIndex(0,iVar5,local_14,&local_ac), piVar17 = local_ac, iVar5 != 0))
          {
            piVar17 = (int *)0x0;
LAB_00421679:
            ppuVar9 = &PTR_0071ce50;
            pbVar6 = &DAT_0071d6cc;
            do {
              bVar2 = *(byte *)ppuVar9;
              bVar18 = bVar2 < *pbVar6;
              if (bVar2 != *pbVar6) {
LAB_004216a3:
                uVar15 = -(uint)bVar18 | 1;
                goto LAB_004216a8;
              }
              if (bVar2 == 0) break;
              bVar2 = *(byte *)((int)ppuVar9 + 1);
              bVar18 = bVar2 < pbVar6[1];
              if (bVar2 != pbVar6[1]) goto LAB_004216a3;
              ppuVar9 = (undefined **)((int)ppuVar9 + 2);
              pbVar6 = pbVar6 + 2;
            } while (bVar2 != 0);
            uVar15 = 0;
LAB_004216a8:
            if (piVar17 != (int *)0x0) goto LAB_004216ac;
          }
          else {
            if (local_ac == (int *)0x0) goto LAB_00421679;
            *local_ac = *local_ac + 1;
            pbVar16 = &DAT_0071d6cc;
            pbVar6 = (byte *)Tcl_GetStringFromObj(local_ac,0);
            do {
              bVar2 = *pbVar6;
              bVar18 = bVar2 < *pbVar16;
              if (bVar2 != *pbVar16) {
LAB_00421670:
                uVar15 = -(uint)bVar18 | 1;
                goto LAB_004216ac;
              }
              if (bVar2 == 0) break;
              bVar2 = pbVar6[1];
              bVar18 = bVar2 < pbVar16[1];
              if (bVar2 != pbVar16[1]) goto LAB_00421670;
              pbVar6 = pbVar6 + 2;
              pbVar16 = pbVar16 + 2;
            } while (bVar2 != 0);
            uVar15 = 0;
LAB_004216ac:
            *piVar17 = *piVar17 + -1;
            if (*piVar17 < 1) {
              TclFreeObj(piVar17);
            }
          }
          iVar5 = *param_2;
          if (uVar15 == 0) {
            if ((iVar5 == 0) ||
               (iVar5 = Tcl_ListObjIndex(0,iVar5,(int)local_14 + 1,&local_b0), piVar13 = local_b0,
               iVar5 != 0)) {
              piVar13 = (int *)0x0;
            }
            else if (local_b0 != (int *)0x0) {
              *local_b0 = *local_b0 + 1;
              iVar5 = Tcl_GetBooleanFromObj(0,local_b0,&local_b4);
              if (iVar5 == 1) {
                *(undefined1 *)(iVar8 + 0x7bc) = 0;
              }
              else {
                *(bool *)(iVar8 + 0x7bc) = local_b4 != 0;
              }
              goto LAB_0042249c;
            }
            *(undefined1 *)(iVar8 + 0x7bc) = 0;
            goto LAB_00422498;
          }
          if ((iVar5 == 0) ||
             (iVar5 = Tcl_ListObjIndex(0,iVar5,local_14,&local_b8), piVar17 = local_b8, iVar5 != 0))
          {
            piVar17 = (int *)0x0;
LAB_004217a9:
            ppuVar9 = &PTR_0071ce50;
            pcVar14 = "-forcetarget";
            do {
              bVar2 = *(byte *)ppuVar9;
              bVar18 = bVar2 < (byte)*pcVar14;
              if (bVar2 != *pcVar14) {
LAB_004217d3:
                uVar15 = -(uint)bVar18 | 1;
                goto LAB_004217d8;
              }
              if (bVar2 == 0) break;
              bVar2 = *(byte *)((int)ppuVar9 + 1);
              bVar18 = bVar2 < ((byte *)pcVar14)[1];
              if (bVar2 != ((byte *)pcVar14)[1]) goto LAB_004217d3;
              ppuVar9 = (undefined **)((int)ppuVar9 + 2);
              pcVar14 = (char *)((byte *)pcVar14 + 2);
            } while (bVar2 != 0);
            uVar15 = 0;
LAB_004217d8:
            if (piVar17 != (int *)0x0) goto LAB_004217dc;
          }
          else {
            if (local_b8 == (int *)0x0) goto LAB_004217a9;
            *local_b8 = *local_b8 + 1;
            pcVar14 = "-forcetarget";
            pbVar6 = (byte *)Tcl_GetStringFromObj(local_b8,0);
            do {
              bVar2 = *pbVar6;
              bVar18 = bVar2 < (byte)*pcVar14;
              if (bVar2 != *pcVar14) {
LAB_004217a0:
                uVar15 = -(uint)bVar18 | 1;
                goto LAB_004217dc;
              }
              if (bVar2 == 0) break;
              bVar2 = pbVar6[1];
              bVar18 = bVar2 < ((byte *)pcVar14)[1];
              if (bVar2 != ((byte *)pcVar14)[1]) goto LAB_004217a0;
              pbVar6 = pbVar6 + 2;
              pcVar14 = (char *)((byte *)pcVar14 + 2);
            } while (bVar2 != 0);
            uVar15 = 0;
LAB_004217dc:
            *piVar17 = *piVar17 + -1;
            if (*piVar17 < 1) {
              TclFreeObj(piVar17);
            }
          }
          iVar5 = *param_2;
          if (uVar15 == 0) {
            if ((iVar5 == 0) ||
               (iVar5 = Tcl_ListObjIndex(0,iVar5,(int)local_14 + 1,&local_bc), piVar13 = local_bc,
               iVar5 != 0)) {
              piVar13 = (int *)0x0;
            }
            else if (local_bc != (int *)0x0) {
              *local_bc = *local_bc + 1;
              iVar5 = Tcl_GetBooleanFromObj(0,local_bc,&local_c0);
              if (iVar5 == 1) {
                *(undefined1 *)(iVar8 + 0x7bf) = 0;
              }
              else {
                *(bool *)(iVar8 + 0x7bf) = local_c0 != 0;
              }
              goto LAB_0042249c;
            }
            *(undefined1 *)(iVar8 + 0x7bf) = 0;
            goto LAB_00422498;
          }
          if ((iVar5 == 0) ||
             (iVar5 = Tcl_ListObjIndex(0,iVar5,local_14,&local_c4), piVar17 = local_c4, iVar5 != 0))
          {
            piVar17 = (int *)0x0;
LAB_004218d9:
            ppuVar9 = &PTR_0071ce50;
            pcVar14 = "-targetdist";
            do {
              bVar2 = *(byte *)ppuVar9;
              bVar18 = bVar2 < (byte)*pcVar14;
              if (bVar2 != *pcVar14) {
LAB_00421903:
                uVar15 = -(uint)bVar18 | 1;
                goto LAB_00421908;
              }
              if (bVar2 == 0) break;
              bVar2 = *(byte *)((int)ppuVar9 + 1);
              bVar18 = bVar2 < ((byte *)pcVar14)[1];
              if (bVar2 != ((byte *)pcVar14)[1]) goto LAB_00421903;
              ppuVar9 = (undefined **)((int)ppuVar9 + 2);
              pcVar14 = (char *)((byte *)pcVar14 + 2);
            } while (bVar2 != 0);
            uVar15 = 0;
LAB_00421908:
            if (piVar17 != (int *)0x0) goto LAB_0042190c;
          }
          else {
            if (local_c4 == (int *)0x0) goto LAB_004218d9;
            *local_c4 = *local_c4 + 1;
            pcVar14 = "-targetdist";
            pbVar6 = (byte *)Tcl_GetStringFromObj(local_c4,0);
            do {
              bVar2 = *pbVar6;
              bVar18 = bVar2 < (byte)*pcVar14;
              if (bVar2 != *pcVar14) {
LAB_004218d0:
                uVar15 = -(uint)bVar18 | 1;
                goto LAB_0042190c;
              }
              if (bVar2 == 0) break;
              bVar2 = pbVar6[1];
              bVar18 = bVar2 < ((byte *)pcVar14)[1];
              if (bVar2 != ((byte *)pcVar14)[1]) goto LAB_004218d0;
              pbVar6 = pbVar6 + 2;
              pcVar14 = (char *)((byte *)pcVar14 + 2);
            } while (bVar2 != 0);
            uVar15 = 0;
LAB_0042190c:
            *piVar17 = *piVar17 + -1;
            if (*piVar17 < 1) {
              TclFreeObj(piVar17);
            }
          }
          iVar5 = *param_2;
          if (uVar15 == 0) {
            if ((iVar5 == 0) ||
               (iVar5 = Tcl_ListObjIndex(0,iVar5,(int)local_14 + 1,&local_c8), piVar13 = local_c8,
               iVar5 != 0)) {
              piVar13 = (int *)0x0;
            }
            else if (local_c8 != (int *)0x0) {
              *local_c8 = *local_c8 + 1;
              iVar5 = Tcl_GetDoubleFromObj(0,local_c8,&local_144);
              if (iVar5 == 1) {
                *(undefined4 *)(iVar8 + 0x7c8) = 0;
              }
              else {
                *(float *)(iVar8 + 0x7c8) = (float)local_144;
              }
              goto LAB_0042249c;
            }
            *(undefined4 *)(iVar8 + 0x7c8) = 0;
            goto LAB_00422498;
          }
          if ((iVar5 == 0) ||
             (iVar5 = Tcl_ListObjIndex(0,iVar5,local_14,&local_cc), piVar17 = local_cc, iVar5 != 0))
          {
            piVar17 = (int *)0x0;
LAB_00421a09:
            ppuVar9 = &PTR_0071ce50;
            pcVar14 = "-randompathwalldist";
            do {
              bVar2 = *(byte *)ppuVar9;
              bVar18 = bVar2 < (byte)*pcVar14;
              if (bVar2 != *pcVar14) {
LAB_00421a33:
                uVar15 = -(uint)bVar18 | 1;
                goto LAB_00421a38;
              }
              if (bVar2 == 0) break;
              bVar2 = *(byte *)((int)ppuVar9 + 1);
              bVar18 = bVar2 < ((byte *)pcVar14)[1];
              if (bVar2 != ((byte *)pcVar14)[1]) goto LAB_00421a33;
              ppuVar9 = (undefined **)((int)ppuVar9 + 2);
              pcVar14 = (char *)((byte *)pcVar14 + 2);
            } while (bVar2 != 0);
            uVar15 = 0;
LAB_00421a38:
            if (piVar17 != (int *)0x0) goto LAB_00421a3c;
          }
          else {
            if (local_cc == (int *)0x0) goto LAB_00421a09;
            *local_cc = *local_cc + 1;
            pcVar14 = "-randompathwalldist";
            pbVar6 = (byte *)Tcl_GetStringFromObj(local_cc,0);
            do {
              bVar2 = *pbVar6;
              bVar18 = bVar2 < (byte)*pcVar14;
              if (bVar2 != *pcVar14) {
LAB_00421a00:
                uVar15 = -(uint)bVar18 | 1;
                goto LAB_00421a3c;
              }
              if (bVar2 == 0) break;
              bVar2 = pbVar6[1];
              bVar18 = bVar2 < ((byte *)pcVar14)[1];
              if (bVar2 != ((byte *)pcVar14)[1]) goto LAB_00421a00;
              pbVar6 = pbVar6 + 2;
              pcVar14 = (char *)((byte *)pcVar14 + 2);
            } while (bVar2 != 0);
            uVar15 = 0;
LAB_00421a3c:
            *piVar17 = *piVar17 + -1;
            if (*piVar17 < 1) {
              TclFreeObj(piVar17);
            }
          }
          iVar5 = *param_2;
          if (uVar15 == 0) {
            if ((iVar5 == 0) ||
               (iVar5 = Tcl_ListObjIndex(0,iVar5,(int)local_14 + 1,&local_d0), piVar13 = local_d0,
               iVar5 != 0)) {
              piVar13 = (int *)0x0;
            }
            else if (local_d0 != (int *)0x0) {
              *local_d0 = *local_d0 + 1;
              iVar5 = Tcl_GetDoubleFromObj(0,local_d0,&local_14c);
              if (iVar5 == 1) {
                *(undefined4 *)(iVar8 + 0x7dc) = 0;
              }
              else {
                *(float *)(iVar8 + 0x7dc) = (float)local_14c;
              }
              goto LAB_0042249c;
            }
            *(undefined4 *)(iVar8 + 0x7dc) = 0;
            goto LAB_00422498;
          }
          if ((iVar5 == 0) ||
             (iVar5 = Tcl_ListObjIndex(0,iVar5,local_14,&local_d4), piVar17 = local_d4, iVar5 != 0))
          {
            piVar17 = (int *)0x0;
LAB_00421b39:
            ppuVar9 = &PTR_0071ce50;
            pcVar14 = "-walktimercallback";
            do {
              bVar2 = *(byte *)ppuVar9;
              bVar18 = bVar2 < (byte)*pcVar14;
              if (bVar2 != *pcVar14) {
LAB_00421b63:
                uVar15 = -(uint)bVar18 | 1;
                goto LAB_00421b68;
              }
              if (bVar2 == 0) break;
              bVar2 = *(byte *)((int)ppuVar9 + 1);
              bVar18 = bVar2 < ((byte *)pcVar14)[1];
              if (bVar2 != ((byte *)pcVar14)[1]) goto LAB_00421b63;
              ppuVar9 = (undefined **)((int)ppuVar9 + 2);
              pcVar14 = (char *)((byte *)pcVar14 + 2);
            } while (bVar2 != 0);
            uVar15 = 0;
LAB_00421b68:
            if (piVar17 != (int *)0x0) goto LAB_00421b6c;
          }
          else {
            if (local_d4 == (int *)0x0) goto LAB_00421b39;
            *local_d4 = *local_d4 + 1;
            pcVar14 = "-walktimercallback";
            pbVar6 = (byte *)Tcl_GetStringFromObj(local_d4,0);
            do {
              bVar2 = *pbVar6;
              bVar18 = bVar2 < (byte)*pcVar14;
              if (bVar2 != *pcVar14) {
LAB_00421b30:
                uVar15 = -(uint)bVar18 | 1;
                goto LAB_00421b6c;
              }
              if (bVar2 == 0) break;
              bVar2 = pbVar6[1];
              bVar18 = bVar2 < ((byte *)pcVar14)[1];
              if (bVar2 != ((byte *)pcVar14)[1]) goto LAB_00421b30;
              pbVar6 = pbVar6 + 2;
              pcVar14 = (char *)((byte *)pcVar14 + 2);
            } while (bVar2 != 0);
            uVar15 = 0;
LAB_00421b6c:
            *piVar17 = *piVar17 + -1;
            if (*piVar17 < 1) {
              TclFreeObj(piVar17);
            }
          }
          iVar5 = *param_2;
          if (uVar15 == 0) {
            if ((iVar5 == 0) ||
               (iVar5 = Tcl_ListObjIndex(0,iVar5,(int)local_14 + 1,&local_d8), iVar5 != 0)) {
              piVar17 = *(int **)(iVar8 + 0x7ec);
              *(undefined4 *)(iVar8 + 0x7ec) = 0;
              piVar13 = (int *)0x0;
            }
            else {
              if (local_d8 != (int *)0x0) {
                *local_d8 = *local_d8 + 1;
              }
              piVar17 = *(int **)(iVar8 + 0x7ec);
              *(int **)(iVar8 + 0x7ec) = local_d8;
              piVar13 = local_d8;
              if (local_d8 != (int *)0x0) {
                *local_d8 = *local_d8 + 1;
              }
            }
            if ((piVar17 != (int *)0x0) && (*piVar17 = *piVar17 + -1, *piVar17 < 1)) {
              TclFreeObj(piVar17);
            }
            piVar17 = local_28;
            if ((piVar13 != (int *)0x0) && (*piVar13 = *piVar13 + -1, *piVar13 < 1)) {
              TclFreeObj(piVar13);
              piVar17 = local_28;
            }
          }
          else {
            if ((iVar5 == 0) ||
               (iVar5 = Tcl_ListObjIndex(0,iVar5,local_14,&local_dc), piVar17 = local_dc, iVar5 != 0
               )) {
              piVar17 = (int *)0x0;
LAB_00421c7d:
              ppuVar9 = &PTR_0071ce50;
              pcVar14 = "-walktimercounter";
              do {
                bVar2 = *(byte *)ppuVar9;
                bVar18 = bVar2 < (byte)*pcVar14;
                if (bVar2 != *pcVar14) {
LAB_00421ca7:
                  uVar15 = -(uint)bVar18 | 1;
                  goto LAB_00421cac;
                }
                if (bVar2 == 0) break;
                bVar2 = *(byte *)((int)ppuVar9 + 1);
                bVar18 = bVar2 < ((byte *)pcVar14)[1];
                if (bVar2 != ((byte *)pcVar14)[1]) goto LAB_00421ca7;
                ppuVar9 = (undefined **)((int)ppuVar9 + 2);
                pcVar14 = (char *)((byte *)pcVar14 + 2);
              } while (bVar2 != 0);
              uVar15 = 0;
LAB_00421cac:
              if (piVar17 != (int *)0x0) goto LAB_00421cb0;
            }
            else {
              if (local_dc == (int *)0x0) goto LAB_00421c7d;
              *local_dc = *local_dc + 1;
              pcVar14 = "-walktimercounter";
              pbVar6 = (byte *)Tcl_GetStringFromObj(local_dc,0);
              do {
                bVar2 = *pbVar6;
                bVar18 = bVar2 < (byte)*pcVar14;
                if (bVar2 != *pcVar14) {
LAB_00421c74:
                  uVar15 = -(uint)bVar18 | 1;
                  goto LAB_00421cb0;
                }
                if (bVar2 == 0) break;
                bVar2 = pbVar6[1];
                bVar18 = bVar2 < ((byte *)pcVar14)[1];
                if (bVar2 != ((byte *)pcVar14)[1]) goto LAB_00421c74;
                pbVar6 = pbVar6 + 2;
                pcVar14 = (char *)((byte *)pcVar14 + 2);
              } while (bVar2 != 0);
              uVar15 = 0;
LAB_00421cb0:
              *piVar17 = *piVar17 + -1;
              if (*piVar17 < 1) {
                TclFreeObj(piVar17);
              }
            }
            iVar5 = *param_2;
            if (uVar15 == 0) {
              if ((iVar5 == 0) ||
                 (iVar5 = Tcl_ListObjIndex(0,iVar5,(int)local_14 + 1,&local_e0), piVar13 = local_e0,
                 iVar5 != 0)) {
                piVar13 = (int *)0x0;
              }
              else if (local_e0 != (int *)0x0) {
                *local_e0 = *local_e0 + 1;
                iVar5 = Tcl_GetIntFromObj(0,local_e0,&local_e4);
                *(uint *)(iVar8 + 0x7e0) = -(uint)(iVar5 != 1) & local_e4;
                goto LAB_0042249c;
              }
              *(undefined4 *)(iVar8 + 0x7e0) = 0;
              goto LAB_00422498;
            }
            if ((iVar5 == 0) ||
               (iVar5 = Tcl_ListObjIndex(0,iVar5,local_14,&local_e8), piVar17 = local_e8, iVar5 != 0
               )) {
              piVar17 = (int *)0x0;
LAB_00421d91:
              ppuVar9 = &PTR_0071ce50;
              pcVar14 = "-walkcollisioncallback";
              do {
                bVar2 = *(byte *)ppuVar9;
                bVar18 = bVar2 < (byte)*pcVar14;
                if (bVar2 != *pcVar14) {
LAB_00421dc0:
                  uVar15 = -(uint)bVar18 | 1;
                  goto LAB_00421dc5;
                }
                if (bVar2 == 0) break;
                bVar2 = *(byte *)((int)ppuVar9 + 1);
                bVar18 = bVar2 < ((byte *)pcVar14)[1];
                if (bVar2 != ((byte *)pcVar14)[1]) goto LAB_00421dc0;
                ppuVar9 = (undefined **)((int)ppuVar9 + 2);
                pcVar14 = (char *)((byte *)pcVar14 + 2);
              } while (bVar2 != 0);
              uVar15 = 0;
LAB_00421dc5:
              if (piVar17 != (int *)0x0) goto LAB_00421dc9;
            }
            else {
              if (local_e8 == (int *)0x0) goto LAB_00421d91;
              *local_e8 = *local_e8 + 1;
              pcVar14 = "-walkcollisioncallback";
              pbVar6 = (byte *)Tcl_GetStringFromObj(local_e8,0);
              do {
                bVar2 = *pbVar6;
                bVar18 = bVar2 < (byte)*pcVar14;
                if (bVar2 != *pcVar14) {
LAB_00421d88:
                  uVar15 = -(uint)bVar18 | 1;
                  goto LAB_00421dc9;
                }
                if (bVar2 == 0) break;
                bVar2 = pbVar6[1];
                bVar18 = bVar2 < ((byte *)pcVar14)[1];
                if (bVar2 != ((byte *)pcVar14)[1]) goto LAB_00421d88;
                pbVar6 = pbVar6 + 2;
                pcVar14 = (char *)((byte *)pcVar14 + 2);
              } while (bVar2 != 0);
              uVar15 = 0;
LAB_00421dc9:
              *piVar17 = *piVar17 + -1;
              if (*piVar17 < 1) {
                TclFreeObj(piVar17);
              }
            }
            iVar5 = *param_2;
            if (uVar15 == 0) {
              if ((iVar5 == 0) ||
                 (iVar8 = Tcl_ListObjIndex(0,iVar5,(int)local_14 + 1,&local_ec), iVar8 != 0)) {
                local_1c = (int *)0x0;
              }
              else {
                local_1c = local_ec;
                if (local_ec != (int *)0x0) {
                  *local_ec = *local_ec + 1;
                }
              }
              piVar13 = local_1c;
              local_8 = 1;
              if (local_1c == (int *)0x0) {
                ppuVar9 = &PTR_0071ce50;
              }
              else {
                ppuVar9 = (undefined **)Tcl_GetStringFromObj(local_1c,0);
              }
              FUN_006b9200(ppuVar9);
              local_8 = 0xffffffff;
              goto LAB_00422498;
            }
            if ((iVar5 == 0) ||
               (iVar5 = Tcl_ListObjIndex(0,iVar5,local_14,&local_f0), piVar17 = local_f0, iVar5 != 0
               )) {
              piVar17 = (int *)0x0;
LAB_00421eb1:
              ppuVar9 = &PTR_0071ce50;
              pcVar14 = "-objbreak";
              do {
                bVar2 = *(byte *)ppuVar9;
                bVar18 = bVar2 < (byte)*pcVar14;
                if (bVar2 != *pcVar14) {
LAB_00421ee0:
                  uVar15 = -(uint)bVar18 | 1;
                  goto LAB_00421ee5;
                }
                if (bVar2 == 0) break;
                bVar2 = *(byte *)((int)ppuVar9 + 1);
                bVar18 = bVar2 < ((byte *)pcVar14)[1];
                if (bVar2 != ((byte *)pcVar14)[1]) goto LAB_00421ee0;
                ppuVar9 = (undefined **)((int)ppuVar9 + 2);
                pcVar14 = (char *)((byte *)pcVar14 + 2);
              } while (bVar2 != 0);
              uVar15 = 0;
LAB_00421ee5:
              if (piVar17 != (int *)0x0) goto LAB_00421ee9;
            }
            else {
              if (local_f0 == (int *)0x0) goto LAB_00421eb1;
              *local_f0 = *local_f0 + 1;
              pcVar14 = "-objbreak";
              pbVar6 = (byte *)Tcl_GetStringFromObj(local_f0,0);
              do {
                bVar2 = *pbVar6;
                bVar18 = bVar2 < (byte)*pcVar14;
                if (bVar2 != *pcVar14) {
LAB_00421ea8:
                  uVar15 = -(uint)bVar18 | 1;
                  goto LAB_00421ee9;
                }
                if (bVar2 == 0) break;
                bVar2 = pbVar6[1];
                bVar18 = bVar2 < ((byte *)pcVar14)[1];
                if (bVar2 != ((byte *)pcVar14)[1]) goto LAB_00421ea8;
                pbVar6 = pbVar6 + 2;
                pcVar14 = (char *)((byte *)pcVar14 + 2);
              } while (bVar2 != 0);
              uVar15 = 0;
LAB_00421ee9:
              *piVar17 = *piVar17 + -1;
              if (*piVar17 < 1) {
                TclFreeObj(piVar17);
              }
            }
            iVar5 = *param_2;
            if (uVar15 == 0) {
              if (iVar5 == 0) {
                local_14 = (int *)0x0;
              }
              else {
                iVar8 = Tcl_ListObjIndex(0,iVar5,(int)local_14 + 1,&local_f4);
                if (iVar8 == 0) {
                  local_14 = local_f4;
                  if (local_f4 != (int *)0x0) {
                    *local_f4 = *local_f4 + 1;
                  }
                }
                else {
                  local_14 = (int *)0x0;
                }
              }
              piVar13 = local_14;
              local_8 = 2;
              if ((local_14 == (int *)0x0) ||
                 (iVar8 = Tcl_ListObjIndex(0,local_14,0,&local_f8), iVar8 != 0)) {
                local_1c = (int *)0x0;
              }
              else {
                local_1c = local_f8;
                if (local_f8 != (int *)0x0) {
                  *local_f8 = *local_f8 + 1;
                }
              }
              piVar17 = local_1c;
              local_8 = CONCAT31(local_8._1_3_,3);
              iVar8 = FUN_005c8310(param_1,&local_1c);
              if ((piVar17 != (int *)0x0) && (*piVar17 = *piVar17 + -1, *piVar17 < 1)) {
                TclFreeObj(piVar17);
              }
              iVar5 = local_18;
              pcVar11 = TclFreeObj_exref;
              if (iVar8 != 0) {
                *(undefined4 *)(local_18 + 0x7c0) = *(undefined4 *)(iVar8 + 0xdc);
                if ((piVar13 == (int *)0x0) ||
                   (iVar8 = Tcl_ListObjIndex(0,piVar13,1,&local_fc), piVar17 = local_fc, iVar8 != 0)
                   ) {
                  piVar17 = (int *)0x0;
LAB_0042202b:
                  *(undefined4 *)(iVar5 + 0x7c4) = 0;
                  pcVar11 = TclFreeObj_exref;
                  if (piVar17 == (int *)0x0) goto LAB_00422055;
                }
                else {
                  if (local_fc == (int *)0x0) goto LAB_0042202b;
                  *local_fc = *local_fc + 1;
                  iVar8 = Tcl_GetDoubleFromObj(0,local_fc,&local_154);
                  if (iVar8 == 1) {
                    *(undefined4 *)(iVar5 + 0x7c4) = 0;
                  }
                  else {
                    *(float *)(iVar5 + 0x7c4) = (float)local_154;
                  }
                }
                *piVar17 = *piVar17 + -1;
                pcVar11 = TclFreeObj_exref;
                if (*piVar17 < 1) {
                  TclFreeObj(piVar17);
                }
              }
LAB_00422055:
              local_8 = 0xffffffff;
              piVar17 = local_28;
              if ((piVar13 != (int *)0x0) && (*piVar13 = *piVar13 + -1, *piVar13 < 1)) {
                (*pcVar11)(piVar13);
                piVar17 = local_28;
              }
            }
            else {
              if ((iVar5 == 0) ||
                 (iVar5 = Tcl_ListObjIndex(0,iVar5,local_14,&local_100), piVar17 = local_100,
                 iVar5 != 0)) {
                piVar17 = (int *)0x0;
LAB_004220e9:
                ppuVar9 = &PTR_0071ce50;
                pcVar14 = "-animsets";
                do {
                  bVar2 = *(byte *)ppuVar9;
                  bVar18 = bVar2 < (byte)*pcVar14;
                  if (bVar2 != *pcVar14) {
LAB_00422113:
                    uVar15 = -(uint)bVar18 | 1;
                    goto LAB_00422118;
                  }
                  if (bVar2 == 0) break;
                  bVar2 = *(byte *)((int)ppuVar9 + 1);
                  bVar18 = bVar2 < ((byte *)pcVar14)[1];
                  if (bVar2 != ((byte *)pcVar14)[1]) goto LAB_00422113;
                  ppuVar9 = (undefined **)((int)ppuVar9 + 2);
                  pcVar14 = (char *)((byte *)pcVar14 + 2);
                } while (bVar2 != 0);
                uVar15 = 0;
LAB_00422118:
                if (piVar17 != (int *)0x0) goto LAB_0042211c;
              }
              else {
                if (local_100 == (int *)0x0) goto LAB_004220e9;
                *local_100 = *local_100 + 1;
                pcVar14 = "-animsets";
                pbVar6 = (byte *)Tcl_GetStringFromObj(local_100,0);
                do {
                  bVar2 = *pbVar6;
                  bVar18 = bVar2 < (byte)*pcVar14;
                  if (bVar2 != *pcVar14) {
LAB_004220e0:
                    uVar15 = -(uint)bVar18 | 1;
                    goto LAB_0042211c;
                  }
                  if (bVar2 == 0) break;
                  bVar2 = pbVar6[1];
                  bVar18 = bVar2 < ((byte *)pcVar14)[1];
                  if (bVar2 != ((byte *)pcVar14)[1]) goto LAB_004220e0;
                  pbVar6 = pbVar6 + 2;
                  pcVar14 = (char *)((byte *)pcVar14 + 2);
                } while (bVar2 != 0);
                uVar15 = 0;
LAB_0042211c:
                *piVar17 = *piVar17 + -1;
                if (*piVar17 < 1) {
                  TclFreeObj(piVar17);
                }
              }
              iVar5 = *param_2;
              if (uVar15 == 0) {
                piVar17 = local_28;
                if (((iVar5 != 0) &&
                    (iVar8 = Tcl_ListObjIndex(0,iVar5,(int)local_14 + 1,&local_104),
                    piVar13 = local_104, piVar17 = local_28, iVar8 == 0)) &&
                   (local_104 != (int *)0x0)) {
                  *local_104 = *local_104 + 1;
                  iVar5 = Tcl_ListObjLength(0,local_104,&local_108);
                  iVar8 = local_108;
                  pcVar11 = TclFreeObj_exref;
                  if (iVar5 == 0) {
                    if (0 < local_108) {
                      iVar5 = Tcl_ListObjIndex(0,piVar13,0,&local_10c);
                      piVar17 = local_10c;
                      if ((iVar5 == 0) && (local_10c != (int *)0x0)) {
                        *local_10c = *local_10c + 1;
                        iVar5 = Tcl_GetIntFromObj(0,local_10c,&local_110);
                        *(uint *)(local_18 + 8) = -(uint)(iVar5 != 1) & local_110;
                        *piVar17 = *piVar17 + -1;
                        if (*piVar17 < 1) {
                          TclFreeObj(piVar17);
                        }
                      }
                      else {
                        *(undefined4 *)(local_18 + 8) = 0;
                      }
                    }
                    if (1 < iVar8) {
                      iVar5 = Tcl_ListObjIndex(0,piVar13,1,&local_114);
                      piVar17 = local_114;
                      if ((iVar5 == 0) && (local_114 != (int *)0x0)) {
                        *local_114 = *local_114 + 1;
                        iVar5 = Tcl_GetIntFromObj(0,local_114,&local_118);
                        *(uint *)(local_18 + 0x1ec) = -(uint)(iVar5 != 1) & local_118;
                        *piVar17 = *piVar17 + -1;
                        if (*piVar17 < 1) {
                          TclFreeObj(piVar17);
                        }
                      }
                      else {
                        *(undefined4 *)(local_18 + 0x1ec) = 0;
                      }
                    }
                    if (2 < iVar8) {
                      iVar5 = Tcl_ListObjIndex(0,piVar13,2,&local_11c);
                      piVar17 = local_11c;
                      if ((iVar5 == 0) && (local_11c != (int *)0x0)) {
                        *local_11c = *local_11c + 1;
                        iVar5 = Tcl_GetIntFromObj(0,local_11c,&local_120);
                        *(uint *)(local_18 + 0x3d0) = -(uint)(iVar5 != 1) & local_120;
                        *piVar17 = *piVar17 + -1;
                        if (*piVar17 < 1) {
                          TclFreeObj(piVar17);
                        }
                      }
                      else {
                        *(undefined4 *)(local_18 + 0x3d0) = 0;
                      }
                    }
                    pcVar11 = TclFreeObj_exref;
                    if (3 < iVar8) {
                      iVar8 = Tcl_ListObjIndex(0,piVar13,3,&local_124);
                      piVar17 = local_124;
                      if ((iVar8 == 0) && (local_124 != (int *)0x0)) {
                        *local_124 = *local_124 + 1;
                        iVar8 = Tcl_GetIntFromObj(0,local_124,&local_128);
                        pcVar11 = TclFreeObj_exref;
                        *(uint *)(local_18 + 0x5b4) = -(uint)(iVar8 != 1) & local_128;
                        *piVar17 = *piVar17 + -1;
                        if (*piVar17 < 1) {
                          TclFreeObj(piVar17);
                        }
                      }
                      else {
                        *(undefined4 *)(local_18 + 0x5b4) = 0;
                        pcVar11 = TclFreeObj_exref;
                      }
                    }
                  }
                  *piVar13 = *piVar13 + -1;
                  piVar17 = local_28;
                  if (*piVar13 < 1) {
                    (*pcVar11)(piVar13);
                    piVar17 = local_28;
                  }
                }
              }
              else {
                if ((iVar5 == 0) ||
                   (iVar5 = Tcl_ListObjIndex(0,iVar5,local_14,&local_12c), piVar17 = local_12c,
                   iVar5 != 0)) {
                  piVar17 = (int *)0x0;
LAB_004223e9:
                  ppuVar9 = &PTR_0071ce50;
                  pcVar14 = "-climbrot";
                  do {
                    bVar2 = *(byte *)ppuVar9;
                    bVar18 = bVar2 < (byte)*pcVar14;
                    if (bVar2 != *pcVar14) {
LAB_00422413:
                      uVar15 = -(uint)bVar18 | 1;
                      goto LAB_00422418;
                    }
                    if (bVar2 == 0) break;
                    bVar2 = *(byte *)((int)ppuVar9 + 1);
                    bVar18 = bVar2 < ((byte *)pcVar14)[1];
                    if (bVar2 != ((byte *)pcVar14)[1]) goto LAB_00422413;
                    ppuVar9 = (undefined **)((int)ppuVar9 + 2);
                    pcVar14 = (char *)((byte *)pcVar14 + 2);
                  } while (bVar2 != 0);
                  uVar15 = 0;
LAB_00422418:
                  if (piVar17 != (int *)0x0) goto LAB_0042241c;
                }
                else {
                  if (local_12c == (int *)0x0) goto LAB_004223e9;
                  *local_12c = *local_12c + 1;
                  pcVar14 = "-climbrot";
                  pbVar6 = (byte *)Tcl_GetStringFromObj(local_12c,0);
                  do {
                    bVar2 = *pbVar6;
                    bVar18 = bVar2 < (byte)*pcVar14;
                    if (bVar2 != *pcVar14) {
LAB_004223e0:
                      uVar15 = -(uint)bVar18 | 1;
                      goto LAB_0042241c;
                    }
                    if (bVar2 == 0) break;
                    bVar2 = pbVar6[1];
                    bVar18 = bVar2 < ((byte *)pcVar14)[1];
                    if (bVar2 != ((byte *)pcVar14)[1]) goto LAB_004223e0;
                    pbVar6 = pbVar6 + 2;
                    pcVar14 = (char *)((byte *)pcVar14 + 2);
                  } while (bVar2 != 0);
                  uVar15 = 0;
LAB_0042241c:
                  *piVar17 = *piVar17 + -1;
                  if (*piVar17 < 1) {
                    TclFreeObj(piVar17);
                  }
                }
                piVar17 = local_28;
                if (uVar15 == 0) {
                  if ((*param_2 == 0) ||
                     (iVar5 = Tcl_ListObjIndex(0,*param_2,(int)local_14 + 1,&local_130), iVar5 != 0)
                     ) {
                    local_1c = (int *)0x0;
                  }
                  else {
                    local_1c = local_130;
                    if (local_130 != (int *)0x0) {
                      *local_130 = *local_130 + 1;
                    }
                  }
                  piVar13 = local_1c;
                  puVar7 = (undefined4 *)FUN_006bafe0(local_184);
                  *(undefined4 *)(iVar8 + 0x7cc) = *puVar7;
                  *(undefined4 *)(iVar8 + 2000) = puVar7[1];
                  *(undefined4 *)(iVar8 + 0x7d4) = puVar7[2];
LAB_00422498:
                  piVar17 = local_28;
                  if (piVar13 != (int *)0x0) {
LAB_0042249c:
                    *piVar13 = *piVar13 + -1;
                    piVar17 = local_28;
                    if (*piVar13 < 1) {
                      TclFreeObj(piVar13);
                      piVar17 = local_28;
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
  if (*(int *)(iVar8 + 0x7b4) != 0) {
    iVar5 = *(int *)(iVar8 + 0x7b8);
    *(undefined1 *)(iVar8 + 0x7b1) = 0;
    if (0xf < iVar5) {
      iVar5 = 0xf;
    }
    *(int *)(iVar8 + 0x7b8) = iVar5;
  }
  pCVar12 = PTR_0077241c;
  if ((local_24 == 0xffffffff) || (local_20 == (int *)0x0)) {
    if (*(char *)(iVar8 + 0x7bc) == '\0') {
      if (14.5 < *(float *)(iVar8 + 0x7ac)) {
        *(undefined4 *)(iVar8 + 0x7ac) = 0x41680000;
      }
      fVar19 = *(float *)(iVar8 + 0x7a4);
      pCVar12 = PTR_0077241c;
      if ((((PTR_0077241c->x0f + 0.0 <= fVar19) && (fVar19 < PTR_0077241c->x1f - 0.0)) &&
          (PTR_0077241c->y0f + 0.0 <= *(float *)(local_18 + 0x7a8))) &&
         (*(float *)(local_18 + 0x7a8) < PTR_0077241c->y1f - 0.0)) {
        puVar7 = (undefined4 *)
                 FUN_00423f20(fVar19,*(undefined4 *)(local_18 + 0x7a8),
                              *(undefined4 *)(local_18 + 0x7ac));
        pCVar12 = PTR_0077241c;
        *(undefined4 *)(iVar4 + 0x7a4) = *puVar7;
        *(undefined4 *)(iVar4 + 0x7a8) = puVar7[1];
        *(undefined4 *)(iVar4 + 0x7ac) = puVar7[2];
      }
    }
  }
  else {
    iVar5 = local_20[0xe8];
    if ((local_20[0xe7] != -1) && (iVar5 != -1)) {
      FUN_0040b550(local_20[0xe7]);
      iVar5 = FUN_004059a0(iVar5);
      FUN_00408920(*(undefined4 *)(iVar5 + 0x5c + local_24 * 4));
      pfVar10 = (float *)FUN_00408a10();
      pfVar1 = (float *)(iVar8 + 0x7a4);
      fVar19 = *pfVar10;
      fVar20 = pfVar10[1];
      fVar21 = pfVar10[2];
      *pfVar1 = fVar19 * 0.005;
      *(float *)(iVar8 + 0x7a8) = fVar20 * 0.005;
      *(float *)(iVar8 + 0x7ac) = fVar21 * 0.01;
      *pfVar1 = (float)local_20[3] + fVar19 * 0.005;
      *(float *)(iVar8 + 0x7a8) = (float)local_20[4] + fVar20 * 0.005;
      *(float *)(iVar8 + 0x7ac) = (float)local_20[5] + fVar21 * 0.01;
      pfVar10 = (float *)FUN_00424120();
      *pfVar1 = *pfVar10;
      *(float *)(iVar8 + 0x7a8) = pfVar10[1];
      *(float *)(iVar8 + 0x7ac) = pfVar10[2];
      pCVar12 = PTR_0077241c;
      iVar4 = local_18;
    }
  }
  iVar8 = *(int *)(iVar4 + 0x7e8);
  if (iVar8 == 0) {
    *(undefined1 *)(iVar4 + 0x7bd) = 0;
    fVar19 = *(float *)(iVar4 + 0x7a8) - *(float *)(param_3 + 0x10);
    fVar21 = *(float *)(iVar4 + 0x7a4) - *(float *)(param_3 + 0xc);
    fVar20 = (*(float *)(iVar4 + 0x7ac) - *(float *)(param_3 + 0x14)) * 0.5;
    fVar19 = fVar19 * fVar19 + fVar21 * fVar21 + fVar20 * fVar20;
    FUN_0040b7e0();
    if (9.0 < fVar19) {
      *(undefined2 *)(iVar4 + 0x7bd) = 0x101;
    }
  }
  else if (iVar8 == 1) {
    *(undefined1 *)(iVar4 + 0x7bd) = 0;
  }
  else if (iVar8 == 2) {
    *(undefined1 *)(iVar4 + 0x7bd) = 1;
  }
  if ((*(char *)(iVar4 + 0x7bd) != '\0') && (*(char *)(iVar4 + 0x7be) == '\0')) {
    *(undefined4 *)(iVar4 + 0x798) = 1;
  }
  *(undefined1 *)(iVar4 + 0x7d8) = 0;
  uVar3 = *(uint *)(param_3 + 0x36c);
  if ((uVar3 < 8) && (*(int *)(iVar4 + 0x7b4) == 0)) {
    piVar17 = (int *)(pCVar12->cellY0 + 4);
    if ((int)piVar17 <= (int)*(float *)(iVar4 + 0x7a8)) {
      piVar17 = (int *)(int)*(float *)(iVar4 + 0x7a8);
    }
    local_28 = (int *)(pCVar12->cellY1 + -5);
    if ((int)piVar17 < pCVar12->cellY1 + -4) {
      local_28 = piVar17;
    }
    iVar8 = FUN_00592f10(pCVar12);
    iVar4 = local_18;
    if (*(char *)(uVar3 + 0x34 + iVar8) != '\0') {
      uVar22 = *(undefined4 *)(param_3 + 0x36c);
      FUN_00592f10(PTR_0077241c);
      pcVar14 = (char *)FUN_00423700(uVar22);
      iVar4 = local_18;
      if (*pcVar14 != '\0') {
        uVar22 = *(undefined4 *)(param_3 + 0x36c);
        FUN_00592f10(PTR_0077241c);
        pcVar14 = (char *)FUN_00423700(uVar22);
        iVar4 = local_18;
        if (*pcVar14 != '\0') {
          uVar22 = *(undefined4 *)(param_3 + 0x36c);
          FUN_00592f10(PTR_0077241c);
          pcVar14 = (char *)FUN_00423700(uVar22);
          iVar4 = local_18;
          if (*pcVar14 != '\0') goto LAB_00422871;
        }
      }
    }
  }
  *(undefined1 *)(iVar4 + 0x7d8) = 1;
LAB_00422871:
  FUN_00422a50(param_3);
  ExceptionList = local_10;
  return;
}

