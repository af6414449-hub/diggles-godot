
undefined4 FUN_006475d0(undefined4 param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  CHeightBlockArray *pCVar2;
  ushort uVar3;
  int *piVar4;
  int iVar5;
  FILE *_File;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  CMapCell *pCVar10;
  CHeightBlock *pCVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  undefined4 *puVar15;
  uint uVar16;
  CMap *pCVar17;
  CMap *pCVar18;
  int local_68;
  char local_64;
  int *local_60;
  int *local_5c;
  undefined4 *local_58;
  uint local_54;
  int local_50;
  int local_20;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070ddc5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_006bc170();
  local_8 = 0;
  FUN_004298b0(param_3);
  local_8._0_1_ = 1;
  piVar4 = (int *)FUN_006ba810();
  piVar4[1] = 0x14;
  piVar4[2] = -1;
  *piVar4 = 0;
  *(undefined1 *)(piVar4 + 3) = 0;
  piVar4[3] = 0x70616d68;
  piVar4[4] = 0x7761722e;
  *(undefined1 *)(piVar4 + 5) = 0;
  piVar4[2] = 8;
  *piVar4 = 1;
  local_8 = CONCAT31(local_8._1_3_,2);
  if (param_3 == 2) {
    if (local_50 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar15 = local_58;
      if (local_54 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_54 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar15 = local_58 + 1;
    }
    piVar1 = (int *)*puVar15;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    local_8 = CONCAT31(local_8._1_3_,3);
    if (piVar1 != (int *)0x0) {
      Tcl_GetStringFromObj(piVar1);
    }
    FUN_006b9200();
    iVar5 = FUN_006b9f40();
    if (iVar5 == -1) {
      FUN_006b9390();
    }
    local_8 = CONCAT31(local_8._1_3_,2);
    if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
      TclFreeObj();
    }
  }
  _File = _fopen((char *)(piVar4 + 3),"wb");
  uVar14 = PTR_0077241c->y0_8;
  if ((int)uVar14 < PTR_0077241c->y1_8) {
    iVar5 = uVar14 + 4;
    pCVar17 = PTR_0077241c;
    do {
      uVar16 = pCVar17->x0_8;
      if ((int)uVar16 < pCVar17->x1_8) {
        iVar6 = (int)(uVar14 + ((int)uVar14 >> 0x1f & 7U)) >> 3;
        local_20 = uVar16 + 4;
        do {
          iVar12 = pCVar17->cellX0;
          if (pCVar17->cellX0 <= (int)uVar16 >> 3) {
            iVar12 = (int)uVar16 >> 3;
          }
          iVar7 = pCVar17->cellY0;
          if (pCVar17->cellY0 <= (int)uVar14 >> 3) {
            iVar7 = (int)uVar14 >> 3;
          }
          iVar13 = pCVar17->cellY1 + -1;
          if (iVar7 < pCVar17->cellY1) {
            iVar13 = iVar7;
          }
          iVar7 = pCVar17->cellX1 + -1;
          if (iVar12 < pCVar17->cellX1) {
            iVar7 = iVar12;
          }
          iVar12 = (iVar13 * pCVar17->mapWidth + iVar7) % pCVar17->cellCountTotal;
          if ((iVar12 < 0) || (pCVar17->cellCount <= iVar12)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pCVar10 = pCVar17->cells;
            pCVar18 = PTR_0077241c;
          }
          else {
            pCVar10 = pCVar17->cells + iVar12;
            pCVar18 = pCVar17;
          }
          iVar12 = pCVar10->heightBlockIndex;
          pCVar2 = pCVar17->heightBlocks;
          if ((iVar12 < 0) || (pCVar2->count <= iVar12)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pCVar11 = pCVar2->data;
            pCVar18 = PTR_0077241c;
          }
          else {
            pCVar11 = pCVar2->data + iVar12;
          }
          local_14 = (uint)pCVar11->heights[uVar16 & 7 | (uVar14 & 7) << 3] << 4;
          iVar7 = (int)(uVar16 + ((int)uVar16 >> 0x1f & 7U)) >> 3;
          iVar12 = pCVar18->cellX0;
          if (pCVar18->cellX0 <= iVar7) {
            iVar12 = iVar7;
          }
          iVar7 = pCVar18->cellY0;
          if (pCVar18->cellY0 <= iVar6) {
            iVar7 = iVar6;
          }
          iVar13 = pCVar18->cellY1 + -1;
          if (iVar7 < pCVar18->cellY1) {
            iVar13 = iVar7;
          }
          iVar7 = pCVar18->cellX1 + -1;
          if (iVar12 < pCVar18->cellX1) {
            iVar7 = iVar12;
          }
          iVar12 = (iVar13 * pCVar18->mapWidth + iVar7) % pCVar18->cellCountTotal;
          if ((iVar12 < 0) || (pCVar18->cellCount <= iVar12)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pCVar10 = pCVar18->cells;
            pCVar18 = PTR_0077241c;
          }
          else {
            pCVar10 = pCVar18->cells + iVar12;
          }
          local_14 = local_14 + (-(uint)((pCVar10->flags & 1) != 0) & 0x32);
          if ((((pCVar18->x0_8 + 8 <= (int)uVar16) && ((int)uVar16 < pCVar18->x1_8 + -8)) &&
              (pCVar18->y0_8 + 8 <= (int)uVar14)) && ((int)uVar14 < pCVar18->y1_8 + -8)) {
            iVar7 = (int)((iVar5 >> 0x1f & 7U) + iVar5) >> 3;
            iVar13 = (int)((local_20 >> 0x1f & 7U) + local_20) >> 3;
            iVar12 = pCVar18->cellX0;
            if (pCVar18->cellX0 <= iVar13) {
              iVar12 = iVar13;
            }
            iVar9 = pCVar18->cellY0;
            if (pCVar18->cellY0 <= iVar7) {
              iVar9 = iVar7;
            }
            iVar8 = pCVar18->cellY1 + -1;
            if (iVar9 < pCVar18->cellY1) {
              iVar8 = iVar9;
            }
            iVar9 = pCVar18->cellX1 + -1;
            if (iVar12 < pCVar18->cellX1) {
              iVar9 = iVar12;
            }
            iVar12 = (iVar8 * pCVar18->mapWidth + iVar9) % pCVar18->cellCountTotal;
            if ((iVar12 < 0) || (pCVar18->cellCount <= iVar12)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pCVar10 = pCVar18->cells;
              pCVar18 = PTR_0077241c;
            }
            else {
              pCVar10 = pCVar18->cells + iVar12;
            }
            uVar3 = pCVar10->material & 3;
            iVar9 = (int)(local_20 + 1 + (local_20 + 1 >> 0x1f & 7U)) >> 3;
            iVar12 = pCVar18->cellX0;
            if (pCVar18->cellX0 <= iVar9) {
              iVar12 = iVar9;
            }
            iVar9 = pCVar18->cellY0;
            if (pCVar18->cellY0 <= iVar7) {
              iVar9 = iVar7;
            }
            iVar7 = pCVar18->cellY1 + -1;
            if (iVar9 < pCVar18->cellY1) {
              iVar7 = iVar9;
            }
            iVar9 = pCVar18->cellX1 + -1;
            if (iVar12 < pCVar18->cellX1) {
              iVar9 = iVar12;
            }
            iVar12 = (iVar7 * pCVar18->mapWidth + iVar9) % pCVar18->cellCountTotal;
            if ((iVar12 < 0) || (pCVar18->cellCount <= iVar12)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pCVar10 = pCVar18->cells;
              pCVar18 = PTR_0077241c;
            }
            else {
              pCVar10 = pCVar18->cells + iVar12;
            }
            if ((uVar3 == 0) == ((pCVar10->material & 3) == 0)) {
              iVar7 = (int)(iVar5 + 1 + (iVar5 + 1 >> 0x1f & 7U)) >> 3;
              iVar12 = pCVar18->cellX0;
              if (pCVar18->cellX0 <= iVar13) {
                iVar12 = iVar13;
              }
              iVar13 = pCVar18->cellY0;
              if (pCVar18->cellY0 <= iVar7) {
                iVar13 = iVar7;
              }
              iVar7 = pCVar18->cellY1 + -1;
              if (iVar13 < pCVar18->cellY1) {
                iVar7 = iVar13;
              }
              iVar13 = pCVar18->cellX1 + -1;
              if (iVar12 < pCVar18->cellX1) {
                iVar13 = iVar12;
              }
              iVar12 = (iVar7 * pCVar18->mapWidth + iVar13) % pCVar18->cellCountTotal;
              if ((iVar12 < 0) || (pCVar18->cellCount <= iVar12)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                pCVar10 = pCVar18->cells;
              }
              else {
                pCVar10 = pCVar18->cells + iVar12;
              }
              if ((uVar3 == 0) == ((pCVar10->material & 3) == 0)) {
                if (uVar3 == 0) {
                  if ((local_20 + iVar5 & 1U) == 0) {
                    local_14 = local_14 + -0x40;
                  }
                  else {
                    local_14 = local_14 + 0x40;
                  }
                }
                goto LAB_00647b47;
              }
            }
            local_14 = 0;
          }
LAB_00647b47:
          iVar12 = 0xff;
          if (local_14 < 0xff) {
            iVar12 = local_14;
          }
          local_14 = 0;
          if (0 < iVar12) {
            local_14 = iVar12;
          }
          _fwrite(&local_14,1,1,_File);
          uVar16 = uVar16 + 1;
          local_20 = local_20 + 1;
          pCVar17 = PTR_0077241c;
        } while ((int)uVar16 < PTR_0077241c->x1_8);
      }
      uVar14 = uVar14 + 1;
      iVar5 = iVar5 + 1;
    } while ((int)uVar14 < pCVar17->y1_8);
  }
  _fclose(_File);
  FUN_006b90d0(&stack0xffffff84,"saved heightmap as %s",piVar4 + 3);
  FUN_0054dc90();
  FUN_006b90d0(&stack0xffffff84,"\t\twidth= %d",PTR_0077241c->x1_8 - PTR_0077241c->x0_8);
  FUN_0054dc90();
  FUN_006b90d0(&stack0xffffff84,"\t\theight=%d",PTR_0077241c->y1_8 - PTR_0077241c->y0_8);
  FUN_0054dc90();
  FUN_006b90d0(&stack0xffffff84,"\t\tchannels=1");
  FUN_0054dc90();
  local_8._0_1_ = 4;
  if ((piVar4 != (int *)0x0) && (*piVar4 = *piVar4 + -1, *piVar4 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 5;
  FUN_004297b0();
  local_8 = CONCAT31(local_8._1_3_,6);
  FUN_004297b0();
  if (local_58 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  if ((local_64 != '\0') && (local_68 != 0)) {
    LOCK();
    DAT_00772dd4 = DAT_00772dd4 + -1;
    UNLOCK();
    Tcl_DeleteInterp();
  }
  if (DAT_00772dd4 == 0) {
    Tcl_Finalize();
  }
  local_8 = 7;
  if ((local_5c != (int *)0x0) && (*local_5c = *local_5c + -1, *local_5c == 0)) {
    FUN_006ba940();
  }
  local_8 = 8;
  if ((local_60 != (int *)0x0) && (*local_60 = *local_60 + -1, *local_60 == 0)) {
    FUN_006ba940();
  }
  ExceptionList = local_10;
  return 0;
}

