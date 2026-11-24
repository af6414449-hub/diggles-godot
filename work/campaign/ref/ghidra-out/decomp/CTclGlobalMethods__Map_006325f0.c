
/* WARNING: Removing unreachable block (ram,0x00632b1f) */
/* WARNING: Removing unreachable block (ram,0x00632b2e) */
/* WARNING: Removing unreachable block (ram,0x00632b35) */

void CTclGlobalMethods__Map(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  byte bVar1;
  int *piVar2;
  int *piVar3;
  undefined1 uVar4;
  char cVar5;
  int iVar6;
  undefined **ppuVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int iVar11;
  int iVar12;
  FILE *_File;
  void *_Str;
  int *piVar13;
  byte *pbVar14;
  uint uVar15;
  undefined4 extraout_ECX;
  char *pcVar16;
  byte *pbVar17;
  code *pcVar18;
  bool bVar19;
  undefined8 uVar20;
  int *piVar21;
  int *piVar22;
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
     (FUN_006cebf4(&DAT_00ca6e88,local_14), iVar6 = DAT_00783650, DAT_00ca6e88 == -1)) {
    iVar11 = DAT_00783650 * 0x40;
    DAT_00ca6e8c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar11) = "TCL:CTclGlobalMethods::Map";
    *(int *)(&DAT_00773650 + iVar11) = iVar6;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6e88);
  }
  iVar11 = DAT_00ca6e8c;
  uVar9 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6e8c * 0x40);
  iVar6 = FUN_0043fcc0();
  *(undefined4 *)(iVar6 + *(int *)(iVar6 + 0x8000) * 4) = uVar9;
  *(int *)(iVar6 + 0x8000) = *(int *)(iVar6 + 0x8000) + 1;
  iVar6 = (&DAT_00773654)[iVar11 * 0x10];
  if (iVar6 == 0) {
    uVar20 = FUN_006bd180();
    iVar6 = (&DAT_00773654)[iVar11 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar11 * 0x10) = uVar20;
  }
  (&DAT_00773654)[iVar11 * 0x10] = iVar6 + 1;
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
    puVar8 = local_44;
    if (local_40 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_40 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar8 = local_44 + 1;
  }
  piVar2 = (int *)*puVar8;
  if (piVar2 != (int *)0x0) {
    *piVar2 = *piVar2 + 1;
  }
  local_8._0_1_ = 3;
  if (piVar2 == (int *)0x0) {
    ppuVar7 = &PTR_0071ce50;
  }
  else {
    ppuVar7 = (undefined **)Tcl_GetStringFromObj(piVar2,0);
  }
  FUN_006b8fb0(ppuVar7);
  local_8._0_1_ = 4;
  uVar4 = (undefined1)local_8;
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
      puVar8 = (undefined4 *)FUN_004295e0(2);
      piVar3 = (int *)*puVar8;
      if (piVar3 != (int *)0x0) {
        *piVar3 = *piVar3 + 1;
      }
      local_20 = piVar3;
      puVar8 = (undefined4 *)FUN_004295e0(3);
      piVar13 = (int *)*puVar8;
      if (piVar13 != (int *)0x0) {
        *piVar13 = *piVar13 + 1;
      }
      local_8._0_1_ = 7;
      local_24 = 0;
      local_1c = (int *)0x0;
      if (4 < param_3) {
        puVar8 = (undefined4 *)FUN_004295e0(4);
        piVar22 = (int *)*puVar8;
        if (piVar22 != (int *)0x0) {
          *piVar22 = *piVar22 + 1;
        }
        local_24 = FUN_006baee0();
        FUN_006bad60();
      }
      if (5 < param_3) {
        puVar8 = (undefined4 *)FUN_004295e0(5);
        piVar22 = (int *)*puVar8;
        if (piVar22 != (int *)0x0) {
          *piVar22 = *piVar22 + 1;
        }
        local_1c = (int *)FUN_006baee0();
        FUN_006bad60();
      }
      if (param_3 == 7) {
        puVar8 = (undefined4 *)FUN_004295e0(6);
        piVar22 = (int *)*puVar8;
        if (piVar22 != (int *)0x0) {
          *piVar22 = *piVar22 + 1;
        }
      }
      else {
        piVar22 = (int *)0x0;
      }
      piVar21 = local_1c;
      uVar9 = FUN_006baee0(local_24,local_1c,piVar22);
      uVar10 = FUN_006baee0(uVar9);
      CGameThread__CreateMap(uVar10,uVar9,local_24,piVar21,piVar22);
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
    local_8._0_1_ = uVar4;
    if (uVar15 == 0) {
      if (param_3 < 4) {
        FUN_006bc8f0(3);
        goto LAB_00632cc6;
      }
      puVar8 = (undefined4 *)FUN_004295e0(2);
      local_1c = (int *)*puVar8;
      if (local_1c != (int *)0x0) {
        *local_1c = *local_1c + 1;
      }
      puVar8 = (undefined4 *)FUN_004295e0(3);
      piVar3 = (int *)*puVar8;
      if (piVar3 != (int *)0x0) {
        *piVar3 = *piVar3 + 1;
      }
      local_8._0_1_ = 0xb;
      local_20 = (int *)FUN_006baee0();
      iVar6 = FUN_006baee0();
      FUN_00594bc0(local_20,iVar6,extraout_ECX);
      if (local_20 == (int *)0x0) {
        iVar11 = FUN_005f8080();
        iVar12 = *(int *)(DAT_0077241c + 0x90) - iVar6;
        local_20 = (int *)(*(int *)(DAT_0077241c + 0x90) + 4);
        FUN_005fa640(0,(int)(iVar6 + (iVar6 >> 0x1f & 3U)) >> 2);
        FUN_005fc9d0(0,iVar12,0x20,local_20,4,0,0x3f800000,0,0,0,0);
        iVar6 = *(int *)(iVar11 + 0x7c) * 4;
        FUN_005fc9d0(iVar6 + -0x20,iVar12,iVar6,local_20,8,0,0x3f800000,0,0,0,0);
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
        local_20 = (int *)Tcl_NewIntObj(*(undefined4 *)(DAT_0077241c + 0x84));
        *local_20 = *local_20 + 1;
        FUN_006bb930(&local_20);
        FUN_006bad60();
        local_20 = (int *)Tcl_NewIntObj(*(undefined4 *)(DAT_0077241c + 0x88));
        *local_20 = *local_20 + 1;
        FUN_006bb930(&local_20);
        FUN_006bad60();
        if (local_64 != 0) {
          Tcl_ResetResult(local_64);
        }
        local_1c = (int *)0x0;
      }
      else {
        cVar5 = FUN_006b9930();
        if (cVar5 == '\0') {
          cVar5 = FUN_006b9930();
          if (cVar5 == '\0') {
            FUN_006bc6a0("unknown map command",0);
            goto LAB_00632cc6;
          }
          CMap__Shut(1);
          local_1c = (int *)0x0;
        }
        else {
          _File = _fopen("d:/mappack.bin","wb");
          iVar11 = DAT_0077241c;
          _Str = (void *)FUN_006ba810(0x213);
          local_20 = (int *)0xffffffff;
          iVar6 = *(int *)(iVar11 + 0x2c);
          if (0 < iVar6) {
            iVar12 = 0;
            do {
              piVar3 = local_1c;
              piVar13 = (int *)((iVar12 * 0x14) / iVar6);
              if ((int)piVar13 <= (int)local_20) {
                piVar13 = local_20;
              }
              iVar6 = iVar6 - iVar12;
              if (0x100000 < iVar6) {
                iVar6 = 0x100000;
              }
              local_20 = piVar13;
              local_1c = (int *)FUN_006c7e40(*(int *)(iVar11 + 0x34) + iVar12,iVar6,9);
              if (local_1c == (int *)0xfffffffc) {
                MessageBoxA((HWND)0x0,"Z_MEM_ERROR","Compress",0);
              }
              if (local_1c == (int *)0xfffffffe) {
                MessageBoxA((HWND)0x0,"Z_STREAM_ERROR","Compress",0);
              }
              local_1c = piVar3;
              _fwrite(&local_1c,4,1,_File);
              _fwrite(_Str,(size_t)local_1c,1,_File);
              iVar12 = iVar12 + iVar6;
              iVar6 = *(int *)(iVar11 + 0x2c);
            } while (iVar12 < iVar6);
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

