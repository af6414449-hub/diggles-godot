
/* WARNING: Removing unreachable block (ram,0x00632b1f) */
/* WARNING: Removing unreachable block (ram,0x00632b2e) */
/* WARNING: Removing unreachable block (ram,0x00632b35) */

void CTclGlobalMethods__Map(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  byte bVar1;
  int *piVar2;
  int *piVar3;
  CMap *pCVar4;
  undefined1 uVar5;
  char cVar6;
  int iVar7;
  undefined **ppuVar8;
  undefined4 *puVar9;
  undefined4 uVar10;
  int iVar11;
  int iVar12;
  FILE *_File;
  void *_Str;
  int *piVar13;
  byte *pbVar14;
  uint uVar15;
  CGameThread *this;
  undefined4 extraout_ECX;
  char *pcVar16;
  byte *pbVar17;
  code *pcVar18;
  bool bVar19;
  undefined8 uVar20;
  int *piVar21;
  int local_64;
  undefined4 *local_44;
  uint local_40;
  int local_3c;
  int *local_2c;
  undefined4 local_24;
  int *local_20;
  int *local_1c;
  byte local_15;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070cddd;
  local_10 = ExceptionList;
  local_14 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6e88) &&
     (FUN_006cebf4(&DAT_00ca6e88,local_14), iVar7 = DAT_00783650, DAT_00ca6e88 == -1)) {
    iVar11 = DAT_00783650 * 0x40;
    DAT_00ca6e8c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar11) = "TCL:CTclGlobalMethods::Map";
    *(int *)(&DAT_00773650 + iVar11) = iVar7;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6e88);
  }
  iVar11 = DAT_00ca6e8c;
  uVar10 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6e8c * 0x40);
  iVar7 = FUN_0043fcc0();
  *(undefined4 *)(iVar7 + *(int *)(iVar7 + 0x8000) * 4) = uVar10;
  *(int *)(iVar7 + 0x8000) = *(int *)(iVar7 + 0x8000) + 1;
  iVar7 = (&DAT_00773654)[iVar11 * 0x10];
  if (iVar7 == 0) {
    uVar20 = FUN_006bd180();
    iVar7 = (&DAT_00773654)[iVar11 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar11 * 0x10) = uVar20;
  }
  (&DAT_00773654)[iVar11 * 0x10] = iVar7 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (param_3 < 2) {
    FUN_006bc8f0(1);
    goto LAB_00632cf9;
  }
  if (local_3c < 2) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar9 = local_44;
    if (local_40 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_40 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar9 = local_44 + 1;
  }
  piVar2 = (int *)*puVar9;
  if (piVar2 != (int *)0x0) {
    *piVar2 = *piVar2 + 1;
  }
  local_8._0_1_ = 3;
  if (piVar2 == (int *)0x0) {
    ppuVar8 = &PTR_0071ce50;
  }
  else {
    ppuVar8 = (undefined **)Tcl_GetStringFromObj(piVar2,0);
  }
  FUN_006b8fb0(ppuVar8);
  local_8._0_1_ = 4;
  uVar5 = (undefined1)local_8;
  local_8._0_1_ = 4;
  pcVar16 = "create";
  pbVar14 = (byte *)(local_2c + 3);
  do {
    local_15 = *pbVar14;
    bVar19 = local_15 < (byte)*pcVar16;
    if (local_15 != *pcVar16) {
LAB_00632786:
      uVar15 = -(uint)bVar19 | 1;
      goto LAB_0063278b;
    }
    if (local_15 == 0) break;
    local_15 = pbVar14[1];
    bVar19 = local_15 < ((byte *)pcVar16)[1];
    if (local_15 != ((byte *)pcVar16)[1]) goto LAB_00632786;
    pbVar14 = pbVar14 + 2;
    pcVar16 = (char *)((byte *)pcVar16 + 2);
  } while (local_15 != 0);
  uVar15 = 0;
LAB_0063278b:
  pbVar14 = (byte *)(local_2c + 3);
  if (uVar15 == 0) {
    if (param_3 < 4) {
      FUN_006bc8f0(3);
LAB_00632cc6:
      local_1c = (int *)0x1;
    }
    else {
      puVar9 = (undefined4 *)FUN_004295e0(2);
      piVar3 = (int *)*puVar9;
      if (piVar3 != (int *)0x0) {
        *piVar3 = *piVar3 + 1;
      }
      local_20 = piVar3;
      puVar9 = (undefined4 *)FUN_004295e0(3);
      piVar13 = (int *)*puVar9;
      if (piVar13 != (int *)0x0) {
        *piVar13 = *piVar13 + 1;
      }
      local_8._0_1_ = 7;
      local_24 = 0;
      local_1c = (int *)0x0;
      if (4 < param_3) {
        puVar9 = (undefined4 *)FUN_004295e0(4);
        piVar21 = (int *)*puVar9;
        if (piVar21 != (int *)0x0) {
          *piVar21 = *piVar21 + 1;
        }
        local_24 = FUN_006baee0();
        FUN_006bad60();
      }
      if (5 < param_3) {
        puVar9 = (undefined4 *)FUN_004295e0(5);
        piVar21 = (int *)*puVar9;
        if (piVar21 != (int *)0x0) {
          *piVar21 = *piVar21 + 1;
        }
        local_1c = (int *)FUN_006baee0();
        FUN_006bad60();
      }
      if (param_3 == 7) {
        puVar9 = (undefined4 *)FUN_004295e0(6);
        piVar21 = (int *)*puVar9;
        if (piVar21 != (int *)0x0) {
          *piVar21 = *piVar21 + 1;
        }
      }
      else {
        piVar21 = (int *)0x0;
      }
      uVar10 = FUN_006baee0(local_24,local_1c,piVar21);
      FUN_006baee0(uVar10);
      CGameThread__CreateMap(this);
      pcVar18 = TclFreeObj_exref;
      if ((piVar13 != (int *)0x0) &&
         (*piVar13 = *piVar13 + -1, pcVar18 = TclFreeObj_exref, *piVar13 < 1)) {
        TclFreeObj(piVar13);
      }
      if ((piVar3 != (int *)0x0) && (*piVar3 = *piVar3 + -1, *piVar3 < 1)) {
        (*pcVar18)(piVar3);
      }
      local_1c = (int *)0x0;
    }
  }
  else {
    pbVar17 = &DAT_0071ccb8;
    do {
      local_15 = *pbVar14;
      bVar19 = local_15 < *pbVar17;
      if (local_15 != *pbVar17) {
LAB_00632904:
        uVar15 = -(uint)bVar19 | 1;
        goto LAB_00632909;
      }
      if (local_15 == 0) break;
      local_15 = pbVar14[1];
      bVar19 = local_15 < pbVar17[1];
      if (local_15 != pbVar17[1]) goto LAB_00632904;
      pbVar14 = pbVar14 + 2;
      pbVar17 = pbVar17 + 2;
    } while (local_15 != 0);
    uVar15 = 0;
LAB_00632909:
    pbVar14 = (byte *)(local_2c + 3);
    local_8._0_1_ = uVar5;
    if (uVar15 == 0) {
      if (param_3 < 4) {
        FUN_006bc8f0(3);
        goto LAB_00632cc6;
      }
      puVar9 = (undefined4 *)FUN_004295e0(2);
      local_1c = (int *)*puVar9;
      if (local_1c != (int *)0x0) {
        *local_1c = *local_1c + 1;
      }
      puVar9 = (undefined4 *)FUN_004295e0(3);
      piVar3 = (int *)*puVar9;
      if (piVar3 != (int *)0x0) {
        *piVar3 = *piVar3 + 1;
      }
      local_8._0_1_ = 0xb;
      local_20 = (int *)FUN_006baee0();
      iVar7 = FUN_006baee0();
      FUN_00594bc0(local_20,iVar7,extraout_ECX);
      if (local_20 == (int *)0x0) {
        iVar11 = FUN_005f8080();
        iVar12 = PTR_0077241c->cellY1 - iVar7;
        local_20 = (int *)(PTR_0077241c->cellY1 + 4);
        FUN_005fa640(0,(int)(iVar7 + (iVar7 >> 0x1f & 3U)) >> 2);
        FUN_005fc9d0(0,iVar12,0x20,local_20,4,0,0x3f800000,0,0,0,0);
        iVar7 = *(int *)(iVar11 + 0x7c) * 4;
        FUN_005fc9d0(iVar7 + -0x20,iVar12,iVar7,local_20,8,0,0x3f800000,0,0,0,0);
      }
      FUN_006bad60();
      FUN_006bad60();
      local_1c = (int *)0x0;
    }
    else {
      pcVar16 = "getoffset";
      do {
        bVar1 = *pbVar14;
        bVar19 = bVar1 < (byte)*pcVar16;
        if (bVar1 != *pcVar16) {
LAB_00632a90:
          uVar15 = -(uint)bVar19 | 1;
          goto LAB_00632a95;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar14[1];
        bVar19 = bVar1 < ((byte *)pcVar16)[1];
        if (bVar1 != ((byte *)pcVar16)[1]) goto LAB_00632a90;
        pbVar14 = pbVar14 + 2;
        pcVar16 = (char *)((byte *)pcVar16 + 2);
      } while (bVar1 != 0);
      uVar15 = 0;
LAB_00632a95:
      if (uVar15 == 0) {
        local_20 = (int *)Tcl_NewIntObj(PTR_0077241c->cellX0);
        *local_20 = *local_20 + 1;
        FUN_006bb930(&local_20);
        FUN_006bad60();
        local_20 = (int *)Tcl_NewIntObj(PTR_0077241c->cellY0);
        *local_20 = *local_20 + 1;
        FUN_006bb930(&local_20);
        FUN_006bad60();
        if (local_64 != 0) {
          Tcl_ResetResult(local_64);
        }
        local_1c = (int *)0x0;
      }
      else {
        cVar6 = FUN_006b9930();
        if (cVar6 == '\0') {
          cVar6 = FUN_006b9930();
          if (cVar6 == '\0') {
            FUN_006bc6a0("unknown map command",0);
            goto LAB_00632cc6;
          }
          CMap__Shut(PTR_0077241c);
          local_1c = (int *)0x0;
        }
        else {
          _File = _fopen("d:/mappack.bin","wb");
          pCVar4 = PTR_0077241c;
          _Str = (void *)FUN_006ba810(0x213);
          local_20 = (int *)0xffffffff;
          iVar7 = pCVar4->mapFlags6;
          if (0 < iVar7) {
            iVar11 = 0;
            do {
              piVar3 = local_1c;
              piVar13 = (int *)((iVar11 * 0x14) / iVar7);
              if ((int)piVar13 <= (int)local_20) {
                piVar13 = local_20;
              }
              iVar7 = iVar7 - iVar11;
              if (0x100000 < iVar7) {
                iVar7 = 0x100000;
              }
              local_20 = piVar13;
              local_1c = (int *)FUN_006c7e40(pCVar4->mapFlags8 + iVar11,iVar7,9);
              if (local_1c == (int *)0xfffffffc) {
                MessageBoxA((HWND)0x0,"Z_MEM_ERROR","Compress",0);
              }
              if (local_1c == (int *)0xfffffffe) {
                MessageBoxA((HWND)0x0,"Z_STREAM_ERROR","Compress",0);
              }
              local_1c = piVar3;
              _fwrite(&local_1c,4,1,_File);
              _fwrite(_Str,(size_t)local_1c,1,_File);
              iVar11 = iVar11 + iVar7;
              iVar7 = pCVar4->mapFlags6;
            } while (iVar11 < iVar7);
          }
          FUN_006cecd8(_Str,1);
          _fclose(_File);
          local_1c = (int *)0x0;
        }
      }
    }
  }
  local_8 = CONCAT31(local_8._1_3_,0x10);
  if ((local_2c != (int *)0x0) && (*local_2c = *local_2c + -1, *local_2c == 0)) {
    FUN_006ba940();
  }
  if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
    TclFreeObj(piVar2);
  }
LAB_00632cf9:
  local_8._0_1_ = 0x11;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,0x12);
  FUN_004297b0(0);
  if (local_44 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

