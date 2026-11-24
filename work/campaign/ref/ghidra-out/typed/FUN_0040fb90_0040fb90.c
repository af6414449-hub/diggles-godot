
undefined1 __thiscall FUN_0040fb90(CAct_Fly *this)

{
  byte bVar1;
  int iVar2;
  undefined **ppuVar3;
  float *pfVar4;
  int iVar5;
  char *pcVar6;
  byte *pbVar7;
  code *pcVar8;
  bool bVar9;
  undefined1 uVar10;
  int *piVar11;
  uint uVar12;
  uint uVar13;
  bool bVar14;
  float fVar15;
  int in_stack_00000008;
  int *in_stack_0000000c;
  int *in_stack_00000010;
  int *in_stack_00000014;
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
  
  this->i_0c = in_stack_00000008;
  this->c_54 = '\0';
  if (in_stack_00000014 != (int *)0x0) {
    *in_stack_00000014 = *in_stack_00000014 + 1;
  }
  if (in_stack_00000010 != (int *)0x0) {
    *in_stack_00000010 = *in_stack_00000010 + 1;
  }
  if (in_stack_0000000c != (int *)0x0) {
    *in_stack_0000000c = *in_stack_0000000c + 1;
  }
  piVar11 = *(int **)&this->field_0x8;
  *(int **)&this->field_0x8 = in_stack_00000014;
  if (in_stack_00000014 != (int *)0x0) {
    *in_stack_00000014 = *in_stack_00000014 + 1;
  }
  pcVar8 = TclFreeObj_exref;
  if ((piVar11 != (int *)0x0) && (*piVar11 = *piVar11 + -1, *piVar11 < 1)) {
    TclFreeObj(piVar11);
    pcVar8 = TclFreeObj_exref;
  }
  this->i_0c = in_stack_00000008;
  piVar11 = *(int **)&this->field_0x10;
  *(int **)&this->field_0x10 = in_stack_0000000c;
  if (in_stack_0000000c != (int *)0x0) {
    *in_stack_0000000c = *in_stack_0000000c + 1;
  }
  if ((piVar11 != (int *)0x0) && (*piVar11 = *piVar11 + -1, *piVar11 < 1)) {
    (*pcVar8)(piVar11);
  }
  piVar11 = *(int **)&this->field_0x14;
  *(int **)&this->field_0x14 = in_stack_00000010;
  if (in_stack_00000010 != (int *)0x0) {
    *in_stack_00000010 = *in_stack_00000010 + 1;
  }
  if ((piVar11 != (int *)0x0) && (*piVar11 = *piVar11 + -1, *piVar11 < 1)) {
    TclFreeObj(piVar11);
  }
  if ((in_stack_0000000c != (int *)0x0) &&
     (*in_stack_0000000c = *in_stack_0000000c + -1, *in_stack_0000000c < 1)) {
    TclFreeObj(in_stack_0000000c);
  }
  pcVar8 = TclFreeObj_exref;
  if ((in_stack_00000010 != (int *)0x0) &&
     (*in_stack_00000010 = *in_stack_00000010 + -1, pcVar8 = TclFreeObj_exref,
     *in_stack_00000010 < 1)) {
    TclFreeObj(in_stack_00000010);
  }
  if ((in_stack_00000014 != (int *)0x0) &&
     (*in_stack_00000014 = *in_stack_00000014 + -1, *in_stack_00000014 < 1)) {
    (*pcVar8)();
  }
  fStack_60 = *(float *)(in_stack_00000008 + 0xc);
  local_68 = *(float *)(in_stack_00000008 + 0x14);
  fStack_5c = *(float *)(in_stack_00000008 + 0x10);
  fStack_6c = 3.0;
  fStack_30 = *(float *)(in_stack_00000008 + 0x44);
  this->f_44 = *(float *)(in_stack_00000008 + 0x48);
  this->f_48 = 0.0;
  this->c_4c = '\0';
  this->f_40 = fStack_30 - 1.5707964;
  this->i_50 = 0;
  bVar9 = true;
  fVar15 = (float)0;
  while( true ) {
    uVar12 = (uint)fVar15;
    if (in_stack_00000014 == (int *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar5 = Tcl_ListObjLength(0,in_stack_00000014,&iStack_54);
      iVar2 = iStack_54;
      if (iVar5 != 0) {
        iVar2 = 0;
      }
    }
    fStack_2c = (float)(uVar12 + 2);
    if (iVar2 < (int)fStack_2c) break;
    if ((in_stack_00000014 == (int *)0x0) ||
       (iVar2 = Tcl_ListObjIndex(0,in_stack_00000014,uVar12,&piStack_58), piVar11 = piStack_58,
       iVar2 != 0)) {
      piVar11 = (int *)0x0;
LAB_0040fd6e:
      ppuVar3 = &PTR_0071ce50;
    }
    else {
      if (piStack_58 == (int *)0x0) goto LAB_0040fd6e;
      *piStack_58 = *piStack_58 + 1;
      ppuVar3 = (undefined **)Tcl_GetStringFromObj(piStack_58,0);
    }
    pcVar6 = "-target";
    do {
      bVar1 = *(byte *)ppuVar3;
      bVar14 = bVar1 < (byte)*pcVar6;
      if (bVar1 != *pcVar6) {
LAB_0040fd98:
        uVar13 = -(uint)bVar14 | 1;
        goto LAB_0040fd9d;
      }
      if (bVar1 == 0) break;
      bVar1 = *(byte *)((int)ppuVar3 + 1);
      bVar14 = bVar1 < ((byte *)pcVar6)[1];
      if (bVar1 != ((byte *)pcVar6)[1]) goto LAB_0040fd98;
      ppuVar3 = (undefined **)((int)ppuVar3 + 2);
      pcVar6 = (char *)((byte *)pcVar6 + 2);
    } while (bVar1 != 0);
    uVar13 = 0;
LAB_0040fd9d:
    if ((piVar11 != (int *)0x0) && (*piVar11 = *piVar11 + -1, *piVar11 < 1)) {
      TclFreeObj(piVar11);
    }
    if (uVar13 == 0) {
      if ((in_stack_00000014 == (int *)0x0) ||
         (iVar2 = Tcl_ListObjIndex(0,in_stack_00000014,uVar12 + 1,&piStack_50), iVar2 != 0)) {
        piStack_64 = (int *)0x0;
      }
      else {
        piStack_64 = piStack_50;
        if (piStack_50 != (int *)0x0) {
          *piStack_50 = *piStack_50 + 1;
        }
      }
      pfVar4 = (float *)FUN_006bafe0(auStack_20);
      this->f_1c = *pfVar4;
      this->f_20 = pfVar4[1];
      this->f_24 = pfVar4[2];
      if ((piStack_64 != (int *)0x0) && (*piStack_64 = *piStack_64 + -1, *piStack_64 < 1)) {
        TclFreeObj(piStack_64);
      }
      bVar9 = false;
      fVar15 = fStack_2c;
    }
    else {
      if ((in_stack_00000014 == (int *)0x0) ||
         (iVar2 = Tcl_ListObjIndex(0,in_stack_00000014,uVar12,&piStack_4c), piVar11 = piStack_4c,
         iVar2 != 0)) {
        piVar11 = (int *)0x0;
LAB_0040fe6a:
        ppuVar3 = &PTR_0071ce50;
      }
      else {
        if (piStack_4c == (int *)0x0) goto LAB_0040fe6a;
        *piStack_4c = *piStack_4c + 1;
        ppuVar3 = (undefined **)Tcl_GetStringFromObj(piStack_4c,0);
      }
      pcVar6 = "-around";
      do {
        bVar1 = *(byte *)ppuVar3;
        bVar14 = bVar1 < (byte)*pcVar6;
        if (bVar1 != *pcVar6) {
LAB_0040fe94:
          uVar13 = -(uint)bVar14 | 1;
          goto LAB_0040fe99;
        }
        if (bVar1 == 0) break;
        bVar1 = *(byte *)((int)ppuVar3 + 1);
        bVar14 = bVar1 < ((byte *)pcVar6)[1];
        if (bVar1 != ((byte *)pcVar6)[1]) goto LAB_0040fe94;
        ppuVar3 = (undefined **)((int)ppuVar3 + 2);
        pcVar6 = (char *)((byte *)pcVar6 + 2);
      } while (bVar1 != 0);
      uVar13 = 0;
LAB_0040fe99:
      if ((piVar11 != (int *)0x0) && (*piVar11 = *piVar11 + -1, *piVar11 < 1)) {
        TclFreeObj(piVar11);
      }
      if (uVar13 == 0) {
        if ((in_stack_00000014 == (int *)0x0) ||
           (iVar2 = Tcl_ListObjIndex(0,in_stack_00000014,uVar12 + 1,&piStack_48), iVar2 != 0)) {
          piStack_64 = (int *)0x0;
        }
        else {
          piStack_64 = piStack_48;
          if (piStack_48 != (int *)0x0) {
            *piStack_48 = *piStack_48 + 1;
          }
        }
        pfVar4 = (float *)FUN_006bafe0(auStack_14);
        fStack_60 = *pfVar4;
        fStack_5c = pfVar4[1];
        local_68 = pfVar4[2];
        fVar15 = fStack_2c;
        if ((piStack_64 != (int *)0x0) && (*piStack_64 = *piStack_64 + -1, *piStack_64 < 1)) {
          TclFreeObj(piStack_64);
          fVar15 = fStack_2c;
        }
      }
      else {
        if ((in_stack_00000014 == (int *)0x0) ||
           (iVar2 = Tcl_ListObjIndex(0,in_stack_00000014,uVar12,&piStack_44), piVar11 = piStack_44,
           iVar2 != 0)) {
          piVar11 = (int *)0x0;
LAB_0040ff78:
          ppuVar3 = &PTR_0071ce50;
        }
        else {
          if (piStack_44 == (int *)0x0) goto LAB_0040ff78;
          *piStack_44 = *piStack_44 + 1;
          ppuVar3 = (undefined **)Tcl_GetStringFromObj(piStack_44,0);
        }
        pcVar6 = "-range";
        do {
          bVar1 = *(byte *)ppuVar3;
          bVar14 = bVar1 < (byte)*pcVar6;
          if (bVar1 != *pcVar6) {
LAB_0040ffa2:
            uVar13 = -(uint)bVar14 | 1;
            goto LAB_0040ffa7;
          }
          if (bVar1 == 0) break;
          bVar1 = *(byte *)((int)ppuVar3 + 1);
          bVar14 = bVar1 < ((byte *)pcVar6)[1];
          if (bVar1 != ((byte *)pcVar6)[1]) goto LAB_0040ffa2;
          ppuVar3 = (undefined **)((int)ppuVar3 + 2);
          pcVar6 = (char *)((byte *)pcVar6 + 2);
        } while (bVar1 != 0);
        uVar13 = 0;
LAB_0040ffa7:
        if ((piVar11 != (int *)0x0) && (*piVar11 = *piVar11 + -1, *piVar11 < 1)) {
          TclFreeObj(piVar11);
        }
        if (uVar13 == 0) {
          if (((in_stack_00000014 == (int *)0x0) ||
              (iVar2 = Tcl_ListObjIndex(0,in_stack_00000014,uVar12 + 1,&piStack_40),
              piVar11 = piStack_40, iVar2 != 0)) || (piStack_40 == (int *)0x0)) {
            fStack_6c = 0.0;
            fVar15 = fStack_2c;
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
            *piVar11 = *piVar11 + -1;
            fVar15 = fStack_2c;
            if (*piVar11 < 1) {
              TclFreeObj(piVar11);
              fVar15 = fStack_2c;
            }
          }
        }
        else {
          if ((in_stack_00000014 == (int *)0x0) ||
             (iVar2 = Tcl_ListObjIndex(0,in_stack_00000014,uVar12,&piStack_3c), piVar11 = piStack_3c
             , iVar2 != 0)) {
            piVar11 = (int *)0x0;
LAB_0041007e:
            ppuVar3 = &PTR_0071ce50;
          }
          else {
            if (piStack_3c == (int *)0x0) goto LAB_0041007e;
            *piStack_3c = *piStack_3c + 1;
            ppuVar3 = (undefined **)Tcl_GetStringFromObj(piStack_3c,0);
          }
          pbVar7 = &DAT_0071d0b0;
          do {
            bVar1 = *(byte *)ppuVar3;
            bVar14 = bVar1 < *pbVar7;
            if (bVar1 != *pbVar7) {
LAB_004100a8:
              uVar13 = -(uint)bVar14 | 1;
              goto LAB_004100ad;
            }
            if (bVar1 == 0) break;
            bVar1 = *(byte *)((int)ppuVar3 + 1);
            bVar14 = bVar1 < pbVar7[1];
            if (bVar1 != pbVar7[1]) goto LAB_004100a8;
            ppuVar3 = (undefined **)((int)ppuVar3 + 2);
            pbVar7 = pbVar7 + 2;
          } while (bVar1 != 0);
          uVar13 = 0;
LAB_004100ad:
          if ((piVar11 != (int *)0x0) && (*piVar11 = *piVar11 + -1, *piVar11 < 1)) {
            TclFreeObj(piVar11);
          }
          fVar15 = fStack_2c;
          if (uVar13 == 0) {
            if (((in_stack_00000014 == (int *)0x0) ||
                (iVar2 = Tcl_ListObjIndex(0,in_stack_00000014,uVar12 + 1,&piStack_38),
                piVar11 = piStack_38, iVar2 != 0)) || (piStack_38 == (int *)0x0)) {
              this->c_54 = '\0';
            }
            else {
              *piStack_38 = *piStack_38 + 1;
              iVar2 = Tcl_GetBooleanFromObj(0,piStack_38,&fStack_34);
              this->c_54 = iVar2 != 1 && fStack_34 != 0.0;
              *piVar11 = *piVar11 + -1;
              if (*piVar11 < 1) {
                TclFreeObj(piVar11);
              }
            }
            this->f_40 = fStack_30 + 3.1415927;
            fVar15 = fStack_2c;
          }
        }
      }
    }
  }
  if (bVar9) {
    iStack_54 = 0;
    bVar9 = false;
    do {
      iVar2 = _rand();
      fVar15 = ((float)iVar2 * 3.0517578e-05 - 0.5) * fStack_6c;
      iVar2 = _rand();
      fStack_2c = ((float)iVar2 * 3.0517578e-05 - 0.5) * fStack_6c + local_68;
      if (15.0 <= fStack_2c) {
        fStack_2c = 15.0;
      }
      fStack_2c = fStack_2c - local_68;
      piStack_58 = (int *)(fStack_60 + fVar15);
      iVar5 = _rand();
      iVar2 = DAT_0077241c;
      fStack_30 = local_68 + fStack_2c;
      fStack_34 = ((float)iVar5 * 3.0517578e-05 - 0.5) * ((fStack_2c + fVar15) / 3.1415927) +
                  fStack_5c;
      uVar12 = (uint)(fStack_34 * 8.0);
      fStack_2c = (float)(int)((float)piStack_58 * 8.0);
      if ((((*(int *)(DAT_0077241c + 0x94) + 0x21 <= (int)fStack_2c) &&
           ((int)fStack_2c < *(int *)(DAT_0077241c + 0x9c) + -0x21)) &&
          (*(int *)(DAT_0077241c + 0x98) + 0x21 <= (int)uVar12)) &&
         ((int)uVar12 < *(int *)(DAT_0077241c + 0xa0) + -0x21)) {
        piVar11 = (int *)FUN_00592f10((int)fStack_2c >> 3,(int)uVar12 >> 3);
        iVar2 = *(int *)(iVar2 + 0x24);
        iVar5 = *piVar11;
        if ((iVar5 < 0) || (*(int *)(iVar2 + 0x14) <= iVar5)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(iVar2 + 0x10);
        }
        else {
          iVar2 = iVar5 * 0x59 + *(int *)(iVar2 + 0x10);
        }
        if ((int)(uint)*(byte *)(((uVar12 & 7) << 3 | (uint)fStack_2c & 7) + iVar2) <=
            (int)fStack_30 + 1) {
          bVar9 = true;
        }
      }
      iStack_54 = iStack_54 + 1;
      if (0xf < iStack_54) {
        if (!bVar9) {
          uVar10 = 0;
          goto LAB_0041034b;
        }
        break;
      }
    } while (!bVar9);
    fVar15 = fStack_30;
    if (15.0 <= fStack_30) {
      fVar15 = 15.0;
    }
    this->f_1c = (float)piStack_58;
    this->f_20 = fStack_34;
    this->f_24 = fVar15;
  }
  uVar10 = 1;
LAB_0041034b:
  if ((in_stack_0000000c != (int *)0x0) &&
     (*in_stack_0000000c = *in_stack_0000000c + -1, *in_stack_0000000c < 1)) {
    TclFreeObj(in_stack_0000000c);
  }
  if ((in_stack_00000010 != (int *)0x0) &&
     (*in_stack_00000010 = *in_stack_00000010 + -1, *in_stack_00000010 < 1)) {
    TclFreeObj(in_stack_00000010);
  }
  if ((in_stack_00000014 != (int *)0x0) &&
     (*in_stack_00000014 = *in_stack_00000014 + -1, *in_stack_00000014 < 1)) {
    TclFreeObj(in_stack_00000014);
  }
  return uVar10;
}

