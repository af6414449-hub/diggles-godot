
undefined4
CTclGlobalMethods__TestD
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  FILE *_File;
  int iVar4;
  int iVar5;
  CMapCell *pCVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  CMap *pCVar11;
  undefined8 uVar12;
  int local_54;
  char local_50;
  int *local_4c;
  int *local_48;
  int local_44;
  int local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070de05;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca70f8) &&
     (FUN_006cebf4(&DAT_00ca70f8,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca70f8 == -1)) {
    iVar4 = DAT_00783650 * 0x40;
    DAT_00ca70fc = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar4) = "TCL:CTclGlobalMethods::TestD()";
    *(int *)(&DAT_00773650 + iVar4) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca70f8);
  }
  iVar4 = DAT_00ca70fc;
  uVar2 = *(undefined4 *)(&DAT_00773650 + DAT_00ca70fc * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar2;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar4 * 0x10];
  if (iVar3 == 0) {
    uVar12 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar4 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar4 * 0x10) = uVar12;
  }
  (&DAT_00773654)[iVar4 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_004298b0(param_3,param_4);
  _File = _fopen("emap.raw","wb");
  uVar10 = PTR_0077241c->y0_8;
  if ((int)uVar10 < PTR_0077241c->y1_8) {
    iVar3 = uVar10 + 4;
    pCVar11 = PTR_0077241c;
    do {
      uVar8 = pCVar11->x0_8;
      if ((int)uVar8 < pCVar11->x1_8) {
        iVar4 = iVar3 >> 3;
        local_1c = uVar8 + 4;
        do {
          local_14 = 0;
          iVar9 = pCVar11->cellX0;
          if (pCVar11->cellX0 <= (int)uVar8 >> 3) {
            iVar9 = (int)uVar8 >> 3;
          }
          iVar7 = pCVar11->cellY0;
          if (pCVar11->cellY0 <= (int)uVar10 >> 3) {
            iVar7 = (int)uVar10 >> 3;
          }
          iVar5 = pCVar11->cellY1 + -1;
          if (iVar7 < pCVar11->cellY1) {
            iVar5 = iVar7;
          }
          iVar7 = pCVar11->cellX1 + -1;
          if (iVar9 < pCVar11->cellX1) {
            iVar7 = iVar9;
          }
          iVar9 = (iVar5 * pCVar11->mapWidth + iVar7) % pCVar11->cellCountTotal;
          if ((iVar9 < 0) || (pCVar11->cellCount <= iVar9)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pCVar6 = pCVar11->cells;
            pCVar11 = PTR_0077241c;
          }
          else {
            pCVar6 = pCVar11->cells + iVar9;
          }
          bVar1 = pCVar6->sampleFlags[uVar8 & 7 | (uVar10 & 7) << 3];
          if ((bVar1 & 1) != 0) {
            local_14 = local_14 | 0x7f000000;
          }
          if ((bVar1 & 2) != 0) {
            local_14 = local_14 | 0x7f0000;
          }
          if ((bVar1 & 4) != 0) {
            local_14 = local_14 | 0x7f00;
          }
          if ((bVar1 & 8) != 0) {
            local_14 = local_14 | 0x7f;
          }
          iVar9 = local_1c >> 3;
          if ((((pCVar11->cellX0 <= iVar9) && (iVar9 < pCVar11->cellX1)) &&
              (pCVar11->cellY0 <= iVar4)) && (iVar4 < pCVar11->cellY1)) {
            iVar7 = pCVar11->cellX0;
            if (pCVar11->cellX0 <= iVar9) {
              iVar7 = iVar9;
            }
            iVar9 = pCVar11->cellY0;
            if (pCVar11->cellY0 <= iVar4) {
              iVar9 = iVar4;
            }
            iVar5 = pCVar11->cellY1 + -1;
            if (iVar9 < pCVar11->cellY1) {
              iVar5 = iVar9;
            }
            iVar9 = pCVar11->cellX1 + -1;
            if (iVar7 < pCVar11->cellX1) {
              iVar9 = iVar7;
            }
            iVar9 = (iVar5 * pCVar11->mapWidth + iVar9) % pCVar11->cellCountTotal;
            if ((iVar9 < 0) || (pCVar11->cellCount <= iVar9)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pCVar6 = pCVar11->cells;
            }
            else {
              pCVar6 = pCVar11->cells + iVar9;
            }
            if ((pCVar6->material & 0x80) != 0) {
              local_14 = 0xffffffff;
            }
          }
          _fwrite(&local_14,1,4,_File);
          uVar8 = uVar8 + 1;
          local_1c = local_1c + 1;
          pCVar11 = PTR_0077241c;
        } while ((int)uVar8 < PTR_0077241c->x1_8);
      }
      uVar10 = uVar10 + 1;
      iVar3 = iVar3 + 1;
    } while ((int)uVar10 < pCVar11->y1_8);
  }
  _fclose(_File);
  local_8._0_1_ = 2;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_004297b0(0);
  if (local_44 != 0) {
    FUN_006ba940();
  }
  if ((local_50 != '\0') && (local_54 != 0)) {
    LOCK();
    DAT_00772dd4 = DAT_00772dd4 + -1;
    UNLOCK();
    Tcl_DeleteInterp(local_54);
  }
  if (DAT_00772dd4 == 0) {
    Tcl_Finalize();
  }
  local_8._0_1_ = 4;
  if ((local_48 != (int *)0x0) && (*local_48 = *local_48 + -1, *local_48 == 0)) {
    FUN_006ba940();
  }
  local_8 = CONCAT31(local_8._1_3_,5);
  if ((local_4c != (int *)0x0) && (*local_4c = *local_4c + -1, *local_4c == 0)) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return 0;
}

