
undefined1 __thiscall FUN_0040fb90(CAct_Fly *this)

{
  byte bVar1;
  CHeightBlockArray *pCVar2;
  CMap *pCVar3;
  int iVar4;
  int iVar5;
  undefined **ppuVar6;
  float *pfVar7;
  CHeightBlock *pCVar8;
  char *pcVar9;
  byte *pbVar10;
  code *pcVar11;
  bool bVar12;
  undefined1 uVar13;
  int *piVar14;
  uint uVar15;
  uint uVar16;
  bool bVar17;
  float fVar18;
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
  piVar14 = *(int **)&this->field_0x8;
  *(int **)&this->field_0x8 = in_stack_00000014;
  if (in_stack_00000014 != (int *)0x0) {
    *in_stack_00000014 = *in_stack_00000014 + 1;
  }
  pcVar11 = TclFreeObj_exref;
  if ((piVar14 != (int *)0x0) && (*piVar14 = *piVar14 + -1, *piVar14 < 1)) {
    TclFreeObj(piVar14);
    pcVar11 = TclFreeObj_exref;
  }
  this->i_0c = in_stack_00000008;
  piVar14 = *(int **)&this->field_0x10;
  *(int **)&this->field_0x10 = in_stack_0000000c;
  if (in_stack_0000000c != (int *)0x0) {
    *in_stack_0000000c = *in_stack_0000000c + 1;
  }
  if ((piVar14 != (int *)0x0) && (*piVar14 = *piVar14 + -1, *piVar14 < 1)) {
    (*pcVar11)(piVar14);
  }
  piVar14 = *(int **)&this->field_0x14;
  *(int **)&this->field_0x14 = in_stack_00000010;
  if (in_stack_00000010 != (int *)0x0) {
    *in_stack_00000010 = *in_stack_00000010 + 1;
  }
  if ((piVar14 != (int *)0x0) && (*piVar14 = *piVar14 + -1, *piVar14 < 1)) {
    TclFreeObj(piVar14);
  }
  if ((in_stack_0000000c != (int *)0x0) &&
     (*in_stack_0000000c = *in_stack_0000000c + -1, *in_stack_0000000c < 1)) {
    TclFreeObj(in_stack_0000000c);
  }
  pcVar11 = TclFreeObj_exref;
  if ((in_stack_00000010 != (int *)0x0) &&
     (*in_stack_00000010 = *in_stack_00000010 + -1, pcVar11 = TclFreeObj_exref,
     *in_stack_00000010 < 1)) {
    TclFreeObj(in_stack_00000010);
  }
  if ((in_stack_00000014 != (int *)0x0) &&
     (*in_stack_00000014 = *in_stack_00000014 + -1, *in_stack_00000014 < 1)) {
    (*pcVar11)();
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
  bVar12 = true;
  fVar18 = (float)0;
  while( true ) {
    uVar15 = (uint)fVar18;
    if (in_stack_00000014 == (int *)0x0) {
      iVar5 = 0;
    }
    else {
      iVar4 = Tcl_ListObjLength(0,in_stack_00000014,&iStack_54);
      iVar5 = iStack_54;
      if (iVar4 != 0) {
        iVar5 = 0;
      }
    }
    fStack_2c = (float)(uVar15 + 2);
    if (iVar5 < (int)fStack_2c) break;
    if ((in_stack_00000014 == (int *)0x0) ||
       (iVar5 = Tcl_ListObjIndex(0,in_stack_00000014,uVar15,&piStack_58), piVar14 = piStack_58,
       iVar5 != 0)) {
      piVar14 = (int *)0x0;
LAB_0040fd6e:
      ppuVar6 = &PTR_0071ce50;
    }
    else {
      if (piStack_58 == (int *)0x0) goto LAB_0040fd6e;
      *piStack_58 = *piStack_58 + 1;
      ppuVar6 = (undefined **)Tcl_GetStringFromObj(piStack_58,0);
    }
    pcVar9 = "-target";
    do {
      bVar1 = *(byte *)ppuVar6;
      bVar17 = bVar1 < (byte)*pcVar9;
      if (bVar1 != *pcVar9) {
LAB_0040fd98:
        uVar16 = -(uint)bVar17 | 1;
        goto LAB_0040fd9d;
      }
      if (bVar1 == 0) break;
      bVar1 = *(byte *)((int)ppuVar6 + 1);
      bVar17 = bVar1 < ((byte *)pcVar9)[1];
      if (bVar1 != ((byte *)pcVar9)[1]) goto LAB_0040fd98;
      ppuVar6 = (undefined **)((int)ppuVar6 + 2);
      pcVar9 = (char *)((byte *)pcVar9 + 2);
    } while (bVar1 != 0);
    uVar16 = 0;
LAB_0040fd9d:
    if ((piVar14 != (int *)0x0) && (*piVar14 = *piVar14 + -1, *piVar14 < 1)) {
      TclFreeObj(piVar14);
    }
    if (uVar16 == 0) {
      if ((in_stack_00000014 == (int *)0x0) ||
         (iVar5 = Tcl_ListObjIndex(0,in_stack_00000014,uVar15 + 1,&piStack_50), iVar5 != 0)) {
        piStack_64 = (int *)0x0;
      }
      else {
        piStack_64 = piStack_50;
        if (piStack_50 != (int *)0x0) {
          *piStack_50 = *piStack_50 + 1;
        }
      }
      pfVar7 = (float *)FUN_006bafe0(auStack_20);
      this->f_1c = *pfVar7;
      this->f_20 = pfVar7[1];
      this->f_24 = pfVar7[2];
      if ((piStack_64 != (int *)0x0) && (*piStack_64 = *piStack_64 + -1, *piStack_64 < 1)) {
        TclFreeObj(piStack_64);
      }
      bVar12 = false;
      fVar18 = fStack_2c;
    }
    else {
      if ((in_stack_00000014 == (int *)0x0) ||
         (iVar5 = Tcl_ListObjIndex(0,in_stack_00000014,uVar15,&piStack_4c), piVar14 = piStack_4c,
         iVar5 != 0)) {
        piVar14 = (int *)0x0;
LAB_0040fe6a:
        ppuVar6 = &PTR_0071ce50;
      }
      else {
        if (piStack_4c == (int *)0x0) goto LAB_0040fe6a;
        *piStack_4c = *piStack_4c + 1;
        ppuVar6 = (undefined **)Tcl_GetStringFromObj(piStack_4c,0);
      }
      pcVar9 = "-around";
      do {
        bVar1 = *(byte *)ppuVar6;
        bVar17 = bVar1 < (byte)*pcVar9;
        if (bVar1 != *pcVar9) {
LAB_0040fe94:
          uVar16 = -(uint)bVar17 | 1;
          goto LAB_0040fe99;
        }
        if (bVar1 == 0) break;
        bVar1 = *(byte *)((int)ppuVar6 + 1);
        bVar17 = bVar1 < ((byte *)pcVar9)[1];
        if (bVar1 != ((byte *)pcVar9)[1]) goto LAB_0040fe94;
        ppuVar6 = (undefined **)((int)ppuVar6 + 2);
        pcVar9 = (char *)((byte *)pcVar9 + 2);
      } while (bVar1 != 0);
      uVar16 = 0;
LAB_0040fe99:
      if ((piVar14 != (int *)0x0) && (*piVar14 = *piVar14 + -1, *piVar14 < 1)) {
        TclFreeObj(piVar14);
      }
      if (uVar16 == 0) {
        if ((in_stack_00000014 == (int *)0x0) ||
           (iVar5 = Tcl_ListObjIndex(0,in_stack_00000014,uVar15 + 1,&piStack_48), iVar5 != 0)) {
          piStack_64 = (int *)0x0;
        }
        else {
          piStack_64 = piStack_48;
          if (piStack_48 != (int *)0x0) {
            *piStack_48 = *piStack_48 + 1;
          }
        }
        pfVar7 = (float *)FUN_006bafe0(auStack_14);
        fStack_60 = *pfVar7;
        fStack_5c = pfVar7[1];
        local_68 = pfVar7[2];
        fVar18 = fStack_2c;
        if ((piStack_64 != (int *)0x0) && (*piStack_64 = *piStack_64 + -1, *piStack_64 < 1)) {
          TclFreeObj(piStack_64);
          fVar18 = fStack_2c;
        }
      }
      else {
        if ((in_stack_00000014 == (int *)0x0) ||
           (iVar5 = Tcl_ListObjIndex(0,in_stack_00000014,uVar15,&piStack_44), piVar14 = piStack_44,
           iVar5 != 0)) {
          piVar14 = (int *)0x0;
LAB_0040ff78:
          ppuVar6 = &PTR_0071ce50;
        }
        else {
          if (piStack_44 == (int *)0x0) goto LAB_0040ff78;
          *piStack_44 = *piStack_44 + 1;
          ppuVar6 = (undefined **)Tcl_GetStringFromObj(piStack_44,0);
        }
        pcVar9 = "-range";
        do {
          bVar1 = *(byte *)ppuVar6;
          bVar17 = bVar1 < (byte)*pcVar9;
          if (bVar1 != *pcVar9) {
LAB_0040ffa2:
            uVar16 = -(uint)bVar17 | 1;
            goto LAB_0040ffa7;
          }
          if (bVar1 == 0) break;
          bVar1 = *(byte *)((int)ppuVar6 + 1);
          bVar17 = bVar1 < ((byte *)pcVar9)[1];
          if (bVar1 != ((byte *)pcVar9)[1]) goto LAB_0040ffa2;
          ppuVar6 = (undefined **)((int)ppuVar6 + 2);
          pcVar9 = (char *)((byte *)pcVar9 + 2);
        } while (bVar1 != 0);
        uVar16 = 0;
LAB_0040ffa7:
        if ((piVar14 != (int *)0x0) && (*piVar14 = *piVar14 + -1, *piVar14 < 1)) {
          TclFreeObj(piVar14);
        }
        if (uVar16 == 0) {
          if (((in_stack_00000014 == (int *)0x0) ||
              (iVar5 = Tcl_ListObjIndex(0,in_stack_00000014,uVar15 + 1,&piStack_40),
              piVar14 = piStack_40, iVar5 != 0)) || (piStack_40 == (int *)0x0)) {
            fStack_6c = 0.0;
            fVar18 = fStack_2c;
          }
          else {
            *piStack_40 = *piStack_40 + 1;
            iVar5 = Tcl_GetDoubleFromObj(0,piStack_40,&dStack_28);
            if (iVar5 == 1) {
              fStack_6c = 0.0;
            }
            else {
              fStack_6c = (float)dStack_28;
            }
            *piVar14 = *piVar14 + -1;
            fVar18 = fStack_2c;
            if (*piVar14 < 1) {
              TclFreeObj(piVar14);
              fVar18 = fStack_2c;
            }
          }
        }
        else {
          if ((in_stack_00000014 == (int *)0x0) ||
             (iVar5 = Tcl_ListObjIndex(0,in_stack_00000014,uVar15,&piStack_3c), piVar14 = piStack_3c
             , iVar5 != 0)) {
            piVar14 = (int *)0x0;
LAB_0041007e:
            ppuVar6 = &PTR_0071ce50;
          }
          else {
            if (piStack_3c == (int *)0x0) goto LAB_0041007e;
            *piStack_3c = *piStack_3c + 1;
            ppuVar6 = (undefined **)Tcl_GetStringFromObj(piStack_3c,0);
          }
          pbVar10 = &DAT_0071d0b0;
          do {
            bVar1 = *(byte *)ppuVar6;
            bVar17 = bVar1 < *pbVar10;
            if (bVar1 != *pbVar10) {
LAB_004100a8:
              uVar16 = -(uint)bVar17 | 1;
              goto LAB_004100ad;
            }
            if (bVar1 == 0) break;
            bVar1 = *(byte *)((int)ppuVar6 + 1);
            bVar17 = bVar1 < pbVar10[1];
            if (bVar1 != pbVar10[1]) goto LAB_004100a8;
            ppuVar6 = (undefined **)((int)ppuVar6 + 2);
            pbVar10 = pbVar10 + 2;
          } while (bVar1 != 0);
          uVar16 = 0;
LAB_004100ad:
          if ((piVar14 != (int *)0x0) && (*piVar14 = *piVar14 + -1, *piVar14 < 1)) {
            TclFreeObj(piVar14);
          }
          fVar18 = fStack_2c;
          if (uVar16 == 0) {
            if (((in_stack_00000014 == (int *)0x0) ||
                (iVar5 = Tcl_ListObjIndex(0,in_stack_00000014,uVar15 + 1,&piStack_38),
                piVar14 = piStack_38, iVar5 != 0)) || (piStack_38 == (int *)0x0)) {
              this->c_54 = '\0';
            }
            else {
              *piStack_38 = *piStack_38 + 1;
              iVar5 = Tcl_GetBooleanFromObj(0,piStack_38,&fStack_34);
              this->c_54 = iVar5 != 1 && fStack_34 != 0.0;
              *piVar14 = *piVar14 + -1;
              if (*piVar14 < 1) {
                TclFreeObj(piVar14);
              }
            }
            this->f_40 = fStack_30 + 3.1415927;
            fVar18 = fStack_2c;
          }
        }
      }
    }
  }
  if (bVar12) {
    iStack_54 = 0;
    bVar12 = false;
    do {
      iVar5 = _rand();
      fVar18 = ((float)iVar5 * 3.0517578e-05 - 0.5) * fStack_6c;
      iVar5 = _rand();
      fStack_2c = ((float)iVar5 * 3.0517578e-05 - 0.5) * fStack_6c + local_68;
      if (15.0 <= fStack_2c) {
        fStack_2c = 15.0;
      }
      fStack_2c = fStack_2c - local_68;
      piStack_58 = (int *)(fStack_60 + fVar18);
      iVar5 = _rand();
      pCVar3 = PTR_0077241c;
      fStack_30 = local_68 + fStack_2c;
      fStack_34 = ((float)iVar5 * 3.0517578e-05 - 0.5) * ((fStack_2c + fVar18) / 3.1415927) +
                  fStack_5c;
      uVar15 = (uint)(fStack_34 * 8.0);
      fStack_2c = (float)(int)((float)piStack_58 * 8.0);
      if ((((PTR_0077241c->x0_8 + 0x21 <= (int)fStack_2c) &&
           ((int)fStack_2c < PTR_0077241c->x1_8 + -0x21)) &&
          (PTR_0077241c->y0_8 + 0x21 <= (int)uVar15)) && ((int)uVar15 < PTR_0077241c->y1_8 + -0x21))
      {
        piVar14 = (int *)FUN_00592f10(PTR_0077241c);
        pCVar2 = pCVar3->heightBlocks;
        iVar5 = *piVar14;
        if ((iVar5 < 0) || (pCVar2->count <= iVar5)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pCVar8 = pCVar2->data;
        }
        else {
          pCVar8 = pCVar2->data + iVar5;
        }
        if ((int)(uint)pCVar8->heights[(uVar15 & 7) << 3 | (uint)fStack_2c & 7] <=
            (int)fStack_30 + 1) {
          bVar12 = true;
        }
      }
      iStack_54 = iStack_54 + 1;
      if (0xf < iStack_54) {
        if (!bVar12) {
          uVar13 = 0;
          goto LAB_0041034b;
        }
        break;
      }
    } while (!bVar12);
    fVar18 = fStack_30;
    if (15.0 <= fStack_30) {
      fVar18 = 15.0;
    }
    this->f_1c = (float)piStack_58;
    this->f_20 = fStack_34;
    this->f_24 = fVar18;
  }
  uVar13 = 1;
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
  return uVar13;
}

