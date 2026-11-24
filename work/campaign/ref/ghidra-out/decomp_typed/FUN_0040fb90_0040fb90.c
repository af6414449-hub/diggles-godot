
undefined1 FUN_0040fb90(undefined4 param_1,int param_2,int *param_3,int *param_4,int *param_5)

{
  byte bVar1;
  int iVar2;
  undefined **ppuVar3;
  undefined4 *puVar4;
  float *pfVar5;
  int iVar6;
  int this;
  char *pcVar7;
  byte *pbVar8;
  code *pcVar9;
  bool bVar10;
  undefined1 uVar11;
  int *piVar12;
  uint uVar13;
  uint uVar14;
  bool bVar15;
  float fVar16;
  float fStack_6c;
  float local_68;
  int *piStack_64;
  float fStack_60;
  float fStack_5c;
  int *piStack_58;
  int iStack_54;
  int *piStack_50;
  int *piStack_4c;
  int *piStack_48;
  int *piStack_44;
  int *piStack_40;
  int *piStack_3c;
  int *piStack_38;
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  double dStack_28;
  undefined1 auStack_20 [12];
  undefined1 auStack_14 [16];
  
  this->i_0c = param_2;
  this->c_54 = 0;
  if (param_5 != (int *)0x0) {
    *param_5 = *param_5 + 1;
  }
  if (param_4 != (int *)0x0) {
    *param_4 = *param_4 + 1;
  }
  if (param_3 != (int *)0x0) {
    *param_3 = *param_3 + 1;
  }
  piVar12 = *(int **)(this + 8);
  *(int **)(this + 8) = param_5;
  if (param_5 != (int *)0x0) {
    *param_5 = *param_5 + 1;
  }
  pcVar9 = TclFreeObj_exref;
  if ((piVar12 != (int *)0x0) && (*piVar12 = *piVar12 + -1, *piVar12 < 1)) {
    TclFreeObj(piVar12);
    pcVar9 = TclFreeObj_exref;
  }
  this->i_0c = param_2;
  piVar12 = *(int **)(this + 0x10);
  *(int **)(this + 0x10) = param_3;
  if (param_3 != (int *)0x0) {
    *param_3 = *param_3 + 1;
  }
  if ((piVar12 != (int *)0x0) && (*piVar12 = *piVar12 + -1, *piVar12 < 1)) {
    (*pcVar9)(piVar12);
  }
  piVar12 = *(int **)(this + 0x14);
  *(int **)(this + 0x14) = param_4;
  if (param_4 != (int *)0x0) {
    *param_4 = *param_4 + 1;
  }
  if ((piVar12 != (int *)0x0) && (*piVar12 = *piVar12 + -1, *piVar12 < 1)) {
    TclFreeObj(piVar12);
  }
  if ((param_3 != (int *)0x0) && (*param_3 = *param_3 + -1, *param_3 < 1)) {
    TclFreeObj(param_3);
  }
  pcVar9 = TclFreeObj_exref;
  if ((param_4 != (int *)0x0) && (*param_4 = *param_4 + -1, pcVar9 = TclFreeObj_exref, *param_4 < 1)
     ) {
    TclFreeObj(param_4);
  }
  if ((param_5 != (int *)0x0) && (*param_5 = *param_5 + -1, *param_5 < 1)) {
    (*pcVar9)(param_5);
  }
  fStack_60 = *(float *)(param_2 + 0xc);
  local_68 = *(float *)(param_2 + 0x14);
  fStack_5c = *(float *)(param_2 + 0x10);
  fStack_6c = 3.0;
  fStack_30 = *(float *)(param_2 + 0x44);
  this->f_44 = *(undefined4 *)(param_2 + 0x48);
  this->f_48 = 0;
  this->c_4c = 0;
  this->f_40 = fStack_30 - 1.5707964;
  this->i_50 = 0;
  bVar10 = true;
  fVar16 = (float)0;
  while( true ) {
    uVar13 = (uint)fVar16;
    if (param_5 == (int *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar6 = Tcl_ListObjLength(0,param_5,&iStack_54);
      iVar2 = iStack_54;
      if (iVar6 != 0) {
        iVar2 = 0;
      }
    }
    fStack_2c = (float)(uVar13 + 2);
    if (iVar2 < (int)fStack_2c) break;
    if ((param_5 == (int *)0x0) ||
       (iVar2 = Tcl_ListObjIndex(0,param_5,uVar13,&piStack_58), piVar12 = piStack_58, iVar2 != 0)) {
      piVar12 = (int *)0x0;
LAB_0040fd6e:
      ppuVar3 = &PTR_0071ce50;
    }
    else {
      if (piStack_58 == (int *)0x0) goto LAB_0040fd6e;
      *piStack_58 = *piStack_58 + 1;
      ppuVar3 = (undefined **)Tcl_GetStringFromObj(piStack_58,0);
    }
    pcVar7 = "-target";
    do {
      bVar1 = *(byte *)ppuVar3;
      bVar15 = bVar1 < (byte)*pcVar7;
      if (bVar1 != *pcVar7) {
LAB_0040fd98:
        uVar14 = -(uint)bVar15 | 1;
        goto LAB_0040fd9d;
      }
      if (bVar1 == 0) break;
      bVar1 = *(byte *)((int)ppuVar3 + 1);
      bVar15 = bVar1 < ((byte *)pcVar7)[1];
      if (bVar1 != ((byte *)pcVar7)[1]) goto LAB_0040fd98;
      ppuVar3 = (undefined **)((int)ppuVar3 + 2);
      pcVar7 = (char *)((byte *)pcVar7 + 2);
    } while (bVar1 != 0);
    uVar14 = 0;
LAB_0040fd9d:
    if ((piVar12 != (int *)0x0) && (*piVar12 = *piVar12 + -1, *piVar12 < 1)) {
      TclFreeObj(piVar12);
    }
    if (uVar14 == 0) {
      if ((param_5 == (int *)0x0) ||
         (iVar2 = Tcl_ListObjIndex(0,param_5,uVar13 + 1,&piStack_50), iVar2 != 0)) {
        piStack_64 = (int *)0x0;
      }
      else {
        piStack_64 = piStack_50;
        if (piStack_50 != (int *)0x0) {
          *piStack_50 = *piStack_50 + 1;
        }
      }
      puVar4 = (undefined4 *)FUN_006bafe0(auStack_20);
      this->f_1c = *puVar4;
      this->f_20 = puVar4[1];
      this->f_24 = puVar4[2];
      if ((piStack_64 != (int *)0x0) && (*piStack_64 = *piStack_64 + -1, *piStack_64 < 1)) {
        TclFreeObj(piStack_64);
      }
      bVar10 = false;
      fVar16 = fStack_2c;
    }
    else {
      if ((param_5 == (int *)0x0) ||
         (iVar2 = Tcl_ListObjIndex(0,param_5,uVar13,&piStack_4c), piVar12 = piStack_4c, iVar2 != 0))
      {
        piVar12 = (int *)0x0;
LAB_0040fe6a:
        ppuVar3 = &PTR_0071ce50;
      }
      else {
        if (piStack_4c == (int *)0x0) goto LAB_0040fe6a;
        *piStack_4c = *piStack_4c + 1;
        ppuVar3 = (undefined **)Tcl_GetStringFromObj(piStack_4c,0);
      }
      pcVar7 = "-around";
      do {
        bVar1 = *(byte *)ppuVar3;
        bVar15 = bVar1 < (byte)*pcVar7;
        if (bVar1 != *pcVar7) {
LAB_0040fe94:
          uVar14 = -(uint)bVar15 | 1;
          goto LAB_0040fe99;
        }
        if (bVar1 == 0) break;
        bVar1 = *(byte *)((int)ppuVar3 + 1);
        bVar15 = bVar1 < ((byte *)pcVar7)[1];
        if (bVar1 != ((byte *)pcVar7)[1]) goto LAB_0040fe94;
        ppuVar3 = (undefined **)((int)ppuVar3 + 2);
        pcVar7 = (char *)((byte *)pcVar7 + 2);
      } while (bVar1 != 0);
      uVar14 = 0;
LAB_0040fe99:
      if ((piVar12 != (int *)0x0) && (*piVar12 = *piVar12 + -1, *piVar12 < 1)) {
        TclFreeObj(piVar12);
      }
      if (uVar14 == 0) {
        if ((param_5 == (int *)0x0) ||
           (iVar2 = Tcl_ListObjIndex(0,param_5,uVar13 + 1,&piStack_48), iVar2 != 0)) {
          piStack_64 = (int *)0x0;
        }
        else {
          piStack_64 = piStack_48;
          if (piStack_48 != (int *)0x0) {
            *piStack_48 = *piStack_48 + 1;
          }
        }
        pfVar5 = (float *)FUN_006bafe0(auStack_14);
        fStack_60 = *pfVar5;
        fStack_5c = pfVar5[1];
        local_68 = pfVar5[2];
        fVar16 = fStack_2c;
        if ((piStack_64 != (int *)0x0) && (*piStack_64 = *piStack_64 + -1, *piStack_64 < 1)) {
          TclFreeObj(piStack_64);
          fVar16 = fStack_2c;
        }
      }
      else {
        if ((param_5 == (int *)0x0) ||
           (iVar2 = Tcl_ListObjIndex(0,param_5,uVar13,&piStack_44), piVar12 = piStack_44, iVar2 != 0
           )) {
          piVar12 = (int *)0x0;
LAB_0040ff78:
          ppuVar3 = &PTR_0071ce50;
        }
        else {
          if (piStack_44 == (int *)0x0) goto LAB_0040ff78;
          *piStack_44 = *piStack_44 + 1;
          ppuVar3 = (undefined **)Tcl_GetStringFromObj(piStack_44,0);
        }
        pcVar7 = "-range";
        do {
          bVar1 = *(byte *)ppuVar3;
          bVar15 = bVar1 < (byte)*pcVar7;
          if (bVar1 != *pcVar7) {
LAB_0040ffa2:
            uVar14 = -(uint)bVar15 | 1;
            goto LAB_0040ffa7;
          }
          if (bVar1 == 0) break;
          bVar1 = *(byte *)((int)ppuVar3 + 1);
          bVar15 = bVar1 < ((byte *)pcVar7)[1];
          if (bVar1 != ((byte *)pcVar7)[1]) goto LAB_0040ffa2;
          ppuVar3 = (undefined **)((int)ppuVar3 + 2);
          pcVar7 = (char *)((byte *)pcVar7 + 2);
        } while (bVar1 != 0);
        uVar14 = 0;
LAB_0040ffa7:
        if ((piVar12 != (int *)0x0) && (*piVar12 = *piVar12 + -1, *piVar12 < 1)) {
          TclFreeObj(piVar12);
        }
        if (uVar14 == 0) {
          if (((param_5 == (int *)0x0) ||
              (iVar2 = Tcl_ListObjIndex(0,param_5,uVar13 + 1,&piStack_40), piVar12 = piStack_40,
              iVar2 != 0)) || (piStack_40 == (int *)0x0)) {
            fStack_6c = 0.0;
            fVar16 = fStack_2c;
          }
          else {
            *piStack_40 = *piStack_40 + 1;
            iVar2 = Tcl_GetDoubleFromObj(0,piStack_40,&dStack_28);
            if (iVar2 == 1) {
              fStack_6c = 0.0;
            }
            else {
              fStack_6c = (float)dStack_28;
            }
            *piVar12 = *piVar12 + -1;
            fVar16 = fStack_2c;
            if (*piVar12 < 1) {
              TclFreeObj(piVar12);
              fVar16 = fStack_2c;
            }
          }
        }
        else {
          if ((param_5 == (int *)0x0) ||
             (iVar2 = Tcl_ListObjIndex(0,param_5,uVar13,&piStack_3c), piVar12 = piStack_3c,
             iVar2 != 0)) {
            piVar12 = (int *)0x0;
LAB_0041007e:
            ppuVar3 = &PTR_0071ce50;
          }
          else {
            if (piStack_3c == (int *)0x0) goto LAB_0041007e;
            *piStack_3c = *piStack_3c + 1;
            ppuVar3 = (undefined **)Tcl_GetStringFromObj(piStack_3c,0);
          }
          pbVar8 = &DAT_0071d0b0;
          do {
            bVar1 = *(byte *)ppuVar3;
            bVar15 = bVar1 < *pbVar8;
            if (bVar1 != *pbVar8) {
LAB_004100a8:
              uVar14 = -(uint)bVar15 | 1;
              goto LAB_004100ad;
            }
            if (bVar1 == 0) break;
            bVar1 = *(byte *)((int)ppuVar3 + 1);
            bVar15 = bVar1 < pbVar8[1];
            if (bVar1 != pbVar8[1]) goto LAB_004100a8;
            ppuVar3 = (undefined **)((int)ppuVar3 + 2);
            pbVar8 = pbVar8 + 2;
          } while (bVar1 != 0);
          uVar14 = 0;
LAB_004100ad:
          if ((piVar12 != (int *)0x0) && (*piVar12 = *piVar12 + -1, *piVar12 < 1)) {
            TclFreeObj(piVar12);
          }
          fVar16 = fStack_2c;
          if (uVar14 == 0) {
            if (((param_5 == (int *)0x0) ||
                (iVar2 = Tcl_ListObjIndex(0,param_5,uVar13 + 1,&piStack_38), piVar12 = piStack_38,
                iVar2 != 0)) || (piStack_38 == (int *)0x0)) {
              this->c_54 = 0;
            }
            else {
              *piStack_38 = *piStack_38 + 1;
              iVar2 = Tcl_GetBooleanFromObj(0,piStack_38,&fStack_34);
              this->c_54 = iVar2 != 1 && fStack_34 != 0.0;
              *piVar12 = *piVar12 + -1;
              if (*piVar12 < 1) {
                TclFreeObj(piVar12);
              }
            }
            this->f_40 = fStack_30 + 3.1415927;
            fVar16 = fStack_2c;
          }
        }
      }
    }
  }
  if (bVar10) {
    iStack_54 = 0;
    bVar10 = false;
    do {
      iVar2 = _rand();
      fVar16 = ((float)iVar2 * 3.0517578e-05 - 0.5) * fStack_6c;
      iVar2 = _rand();
      fStack_2c = ((float)iVar2 * 3.0517578e-05 - 0.5) * fStack_6c + local_68;
      if (15.0 <= fStack_2c) {
        fStack_2c = 15.0;
      }
      fStack_2c = fStack_2c - local_68;
      piStack_58 = (int *)(fStack_60 + fVar16);
      iVar6 = _rand();
      iVar2 = DAT_0077241c;
      fStack_30 = local_68 + fStack_2c;
      fStack_34 = ((float)iVar6 * 3.0517578e-05 - 0.5) * ((fStack_2c + fVar16) / 3.1415927) +
                  fStack_5c;
      uVar13 = (uint)(fStack_34 * 8.0);
      fStack_2c = (float)(int)((float)piStack_58 * 8.0);
      if ((((*(int *)(DAT_0077241c + 0x94) + 0x21 <= (int)fStack_2c) &&
           ((int)fStack_2c < *(int *)(DAT_0077241c + 0x9c) + -0x21)) &&
          (*(int *)(DAT_0077241c + 0x98) + 0x21 <= (int)uVar13)) &&
         ((int)uVar13 < *(int *)(DAT_0077241c + 0xa0) + -0x21)) {
        piVar12 = (int *)FUN_00592f10((int)fStack_2c >> 3,(int)uVar13 >> 3);
        iVar2 = *(int *)(iVar2 + 0x24);
        iVar6 = *piVar12;
        if ((iVar6 < 0) || (*(int *)(iVar2 + 0x14) <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(iVar2 + 0x10);
        }
        else {
          iVar2 = iVar6 * 0x59 + *(int *)(iVar2 + 0x10);
        }
        if ((int)(uint)*(byte *)(((uVar13 & 7) << 3 | (uint)fStack_2c & 7) + iVar2) <=
            (int)fStack_30 + 1) {
          bVar10 = true;
        }
      }
      iStack_54 = iStack_54 + 1;
      if (0xf < iStack_54) {
        if (!bVar10) {
          uVar11 = 0;
          goto LAB_0041034b;
        }
        break;
      }
    } while (!bVar10);
    fVar16 = fStack_30;
    if (15.0 <= fStack_30) {
      fVar16 = 15.0;
    }
    *(int **)(this + 0x1c) = piStack_58;
    this->f_20 = fStack_34;
    this->f_24 = fVar16;
  }
  uVar11 = 1;
LAB_0041034b:
  if ((param_3 != (int *)0x0) && (*param_3 = *param_3 + -1, *param_3 < 1)) {
    TclFreeObj(param_3);
  }
  if ((param_4 != (int *)0x0) && (*param_4 = *param_4 + -1, *param_4 < 1)) {
    TclFreeObj(param_4);
  }
  if ((param_5 != (int *)0x0) && (*param_5 = *param_5 + -1, *param_5 < 1)) {
    TclFreeObj(param_5);
  }
  return uVar11;
}

