
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 *
FUN_005a22f0(undefined4 *param_1,int *param_2,uint param_3,undefined4 *param_4,float param_5,
            undefined4 *param_6,int *param_7,int *param_8)

{
  code *pcVar1;
  char cVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint *puVar8;
  undefined4 *puVar9;
  float *pfVar10;
  undefined4 *puVar11;
  int in_ECX;
  CMapCell *pCVar12;
  int *piVar13;
  int *piVar14;
  CMap *pCVar15;
  undefined4 *puVar16;
  uint uVar17;
  int *piVar18;
  bool bVar19;
  float fVar20;
  longlong lVar21;
  undefined1 local_4c [8];
  int local_44;
  int local_40;
  float local_3c;
  uint local_38;
  undefined4 *local_34;
  CMap *local_30;
  int *local_2c;
  undefined4 *local_28;
  undefined4 *local_24;
  uint local_20;
  uint local_1c;
  float local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  lVar21 = CONCAT44(DAT_00b836b4,DAT_00b836b0);
  puStack_c = &LAB_00706c6d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  local_24 = (undefined4 *)in_ECX;
  if (DAT_00b836b0 == 0 && DAT_00b836b4 == 0) {
    lVar21 = FUN_006bd180(DAT_0076700c ^ (uint)&stack0xfffffffc);
  }
  __alldiv(lVar21 - CONCAT44(_DAT_00b836bc,_DAT_00b836b8),DAT_00b836c8,DAT_00b836cc);
  FUN_006f5260();
  FUN_006f514b();
  FUN_00449180();
  FUN_0043e3c0();
  uVar3 = FUN_0059a4b0();
  *(undefined4 *)(in_ECX + 0xc) = uVar3;
  pCVar15 = PTR_0077241c;
  if ((((char)PTR_0077241c->mapFlags == '\0') || (param_4 == (undefined4 *)0x0)) ||
     (cVar2 = FUN_0040b8a0(&param_2,0x28), cVar2 != '\0')) {
    *param_1 = 0;
    ExceptionList = local_10;
    return param_1;
  }
  uVar17 = param_3 & 7;
  uVar4 = (uint)param_2 & 7;
  iVar5 = FUN_00592f10(pCVar15);
  pcVar1 = RaiseException_exref;
  if ((*(byte *)((uVar17 << 3 | uVar4) + 0x3c + iVar5) & 1) == 0) {
    iVar5 = 1;
    do {
      uVar17 = param_3 + iVar5;
      uVar4 = (uint)param_2 & 7;
      iVar6 = FUN_00592f10(PTR_0077241c);
      if ((*(byte *)(((uVar17 & 7) << 3 | uVar4) + 0x3c + iVar6) & 1) != 0) {
        param_3 = param_3 + iVar5;
        pcVar1 = RaiseException_exref;
        break;
      }
      uVar4 = (int)param_2 + iVar5;
      uVar17 = param_3 & 7;
      iVar6 = FUN_00592f10(PTR_0077241c);
      if ((*(byte *)((uVar17 << 3 | uVar4 & 7) + 0x3c + iVar6) & 1) != 0) {
        param_2 = (int *)((int)param_2 + iVar5);
        pcVar1 = RaiseException_exref;
        break;
      }
      uVar4 = (int)param_2 - iVar5;
      uVar17 = param_3 & 7;
      iVar6 = FUN_00592f10(PTR_0077241c);
      if ((*(byte *)((uVar17 << 3 | uVar4 & 7) + 0x3c + iVar6) & 1) != 0) {
        param_2 = (int *)((int)param_2 - iVar5);
        pcVar1 = RaiseException_exref;
        break;
      }
      uVar17 = param_3 - iVar5;
      uVar4 = (uint)param_2 & 7;
      iVar6 = FUN_00592f10(PTR_0077241c);
      pcVar1 = RaiseException_exref;
      if ((*(byte *)(((uVar17 & 7) << 3 | uVar4) + 0x3c + iVar6) & 1) != 0) {
        param_3 = param_3 - iVar5;
        break;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < 0x21);
  }
  while( true ) {
    pCVar15 = PTR_0077241c;
    local_34 = (undefined4 *)(param_3 + 1);
    local_2c = param_2;
    local_30 = PTR_0077241c;
    iVar5 = PTR_0077241c->cellX0;
    if (PTR_0077241c->cellX0 <= (int)param_2 >> 3) {
      iVar5 = (int)param_2 >> 3;
    }
    iVar6 = PTR_0077241c->cellY0;
    if (PTR_0077241c->cellY0 <= (int)local_34 >> 3) {
      iVar6 = (int)local_34 >> 3;
    }
    iVar7 = PTR_0077241c->cellY1 + -1;
    if (iVar6 < PTR_0077241c->cellY1) {
      iVar7 = iVar6;
    }
    iVar6 = PTR_0077241c->cellX1 + -1;
    if (iVar5 < PTR_0077241c->cellX1) {
      iVar6 = iVar5;
    }
    iVar5 = (iVar7 * PTR_0077241c->mapWidth + iVar6) % PTR_0077241c->cellCountTotal;
    if ((iVar5 < 0) || (PTR_0077241c->cellCount <= iVar5)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      pCVar12 = pCVar15->cells;
    }
    else {
      pCVar12 = PTR_0077241c->cells + iVar5;
    }
    if ((pCVar12->sampleFlags[((uint)local_34 & 7) << 3 | (uint)local_2c & 7] & 2) == 0) break;
    param_3 = param_3 + 1;
  }
  local_34 = (undefined4 *)0x0;
  *(undefined4 *)((int)local_24 + 4) = 0;
  local_8 = CONCAT31(local_8._1_3_,1);
  local_1c = (int)((int)param_2 + ((int)param_2 >> 0x1f & 7U)) >> 3;
  local_30 = (CMap *)((int)(param_3 + ((int)param_3 >> 0x1f & 7U)) >> 3);
  local_28 = (undefined4 *)FUN_006ba810(0x2b8);
  if (local_28 == (undefined4 *)0x0) {
    local_28 = (undefined4 *)0x0;
  }
  else {
    local_28[1] = 0;
    *local_28 = CPath::vftable;
    local_28[2] = 0;
    local_28[3] = 0;
    local_28[4] = 0;
    local_28[5] = 0;
    local_28[6] = 0;
    local_28[7] = 0;
  }
  puVar11 = local_28;
  if (local_28 != (undefined4 *)0x0) {
    LOCK();
    local_28[1] = local_28[1] + 1;
    UNLOCK();
  }
  local_34 = local_28;
  if ((((int)local_1c < DAT_00b9bf2c + 2) || ((int)local_30 < DAT_00b9bf30 + 2)) ||
     ((DAT_00b9bf20 + -2 + DAT_00b9bf2c <= (int)local_1c ||
      (DAT_00b9bf24 + -2 + DAT_00b9bf30 <= (int)local_30)))) {
    piVar18 = local_28 + 1;
    local_28[8] = 0;
    local_28[4] = param_2;
    local_28[5] = param_3;
    local_28[9] = 0;
    local_28[6] = param_2;
    local_28[7] = param_3;
    *param_1 = local_28;
    LOCK();
    *piVar18 = *piVar18 + 1;
    UNLOCK();
    LOCK();
    iVar5 = *piVar18;
    *piVar18 = iVar5 + -1;
    UNLOCK();
    if (iVar5 + -1 != 0) {
      ExceptionList = local_10;
      return param_1;
    }
    (**(code **)*local_28)(1);
    ExceptionList = local_10;
    return param_1;
  }
  if ((char)param_7 == '\0') {
    if (7 < (uint)param_5) {
      puVar8 = (uint *)FUN_0059fda0(&local_44,local_1c,local_30,param_4,param_8);
      goto LAB_005a26f6;
    }
    puVar8 = (uint *)FUN_005a0f00(&local_44,local_1c,local_30,param_4,param_8,param_5);
    param_7 = (int *)CONCAT13(1,param_7._0_3_);
  }
  else if ((uint)param_5 < 8) {
    puVar8 = (uint *)FUN_005a1920(&local_44,local_1c,local_30,param_4,param_8,param_5);
    param_7 = (int *)CONCAT13(1,param_7._0_3_);
  }
  else {
    puVar8 = (uint *)FUN_005a0650(&local_44,local_1c,local_30,param_4,param_8);
LAB_005a26f6:
    param_7 = (int *)((uint)param_7 & 0xffffff);
  }
  param_4 = (undefined4 *)*puVar8;
  piVar18 = (int *)puVar8[1];
  if (((undefined4 *)local_1c == param_4) && (local_30 == (CMap *)piVar18)) {
    puVar9 = (undefined4 *)FUN_0059fc30(DAT_00b9bf20 * (int)local_30 + local_1c);
    piVar18 = puVar11 + 1;
    *puVar9 = 0x7fffffff;
    puVar11[8] = 0;
    puVar11[4] = param_2;
    puVar11[5] = param_3;
    puVar11[9] = 0;
    puVar11[6] = param_2;
    puVar11[7] = param_3;
    *param_1 = puVar11;
    LOCK();
    *piVar18 = *piVar18 + 1;
    UNLOCK();
    LOCK();
    iVar5 = *piVar18 + -1;
    *piVar18 = iVar5;
    UNLOCK();
    goto LAB_005a30f2;
  }
  puVar9 = (undefined4 *)FUN_0059fc30((int)piVar18 * DAT_00b9bf20 + (int)param_4);
  puVar11[8] = *puVar9;
  local_14 = puVar11 + 2;
  uVar4 = FUN_00416630();
  local_2c = (int *)uVar4;
  if ((uint)local_14[1] <= uVar4) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  param_8 = (int *)(uVar4 * 8);
  piVar13 = (int *)(*local_14 + (int)param_8);
  iVar5 = FUN_00592f10(PTR_0077241c);
  piVar14 = local_14;
  *piVar13 = (*(byte *)(iVar5 + 0x12) & 7) + (int)param_4 * 8;
  if ((uint)local_14[1] <= local_2c) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  iVar6 = *piVar14 + (int)param_8;
  iVar5 = FUN_00592f10(PTR_0077241c);
  piVar14 = local_14;
  *(uint *)(iVar6 + 4) = (*(byte *)(iVar5 + 0x12) >> 3 & 7) + (int)piVar18 * 8;
  if ((uint)local_14[1] <= local_2c) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  fVar20 = (float)param_4;
  iVar5 = *piVar14;
  local_28[4] = *(undefined4 *)(iVar5 + (int)param_8);
  local_28[5] = ((undefined4 *)(iVar5 + (int)param_8))[1];
  local_28[9] = 1;
  param_8 = piVar18;
  pfVar10 = (float *)FUN_0059fc30((int)piVar18 * DAT_00b9bf20 + (int)param_4);
  param_5 = *pfVar10;
  piVar14 = (int *)0x64;
  if (param_7._3_1_ != '\0') {
    do {
      if ((fVar20 == (float)local_1c) && ((CMap *)piVar18 == local_30)) {
LAB_005a3116:
        bVar19 = piVar14 == (int *)0x0;
LAB_005a3118:
        puVar11 = local_28;
        if (bVar19) {
          (**(code **)*local_28)(1);
          *param_1 = 0;
          LOCK();
          piVar18 = puVar11 + 1;
          iVar5 = *piVar18 + -1;
          *piVar18 = iVar5;
          UNLOCK();
          if (iVar5 != 0) {
            ExceptionList = local_10;
            return param_1;
          }
          (**(code **)*puVar11)(1);
          ExceptionList = local_10;
          return param_1;
        }
        puVar11 = (undefined4 *)FUN_0040c060(local_2c);
        iVar5 = 0;
        *puVar11 = param_2;
        puVar11[1] = param_3;
        local_28[6] = param_2;
        local_28[7] = param_3;
        if (0 < *(int *)((int)local_24 + 4)) {
          do {
            piVar18 = *(int **)((int)local_24 + 0xc);
            if ((iVar5 < 0) || (piVar18[1] <= iVar5)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              param_7 = (int *)*piVar18;
              piVar18 = *(int **)((int)local_24 + 0xc);
            }
            else {
              param_7 = (int *)(*piVar18 + iVar5 * 8);
            }
            if ((iVar5 < 0) || (piVar18[1] <= iVar5)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar6 = *piVar18;
            }
            else {
              iVar6 = *piVar18 + iVar5 * 8;
            }
            iVar6 = (*(int *)(iVar6 + 4) * DAT_00b9bf20 + *param_7) % DAT_00b9bf28;
            if ((iVar6 < 0) || (DAT_00b9bf1c <= iVar6)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pfVar10 = DAT_00b9bf18;
            }
            else {
              pfVar10 = DAT_00b9bf18 + iVar6;
            }
            *pfVar10 = NAN;
            iVar5 = iVar5 + 1;
          } while (iVar5 < *(int *)((int)local_24 + 4));
        }
        puVar11 = local_28;
        local_2c = (int *)0x0;
        local_8 = CONCAT31(local_8._1_3_,2);
        param_7 = (int *)FUN_006ba810(0x375);
        if (param_7 == (int *)0x0) {
          local_30 = (CMap *)0x0;
        }
        else {
          local_30 = (CMap *)FUN_004114d0();
        }
        piVar18 = local_14;
        pCVar15 = local_30;
        if (local_30 != (CMap *)0x0) {
          LOCK();
          *(int *)((int)local_30 + 4) = *(int *)((int)local_30 + 4) + 1;
          UNLOCK();
        }
        param_4 = (undefined4 *)puVar11[3];
        local_2c = (int *)local_30;
        while (param_4 = (undefined4 *)((int)param_4 - 1), -1 < (int)param_4) {
          if ((uint)piVar18[1] <= param_4) {
            (*pcVar1)(0xc000008c,1,0,0);
          }
          piVar14 = *(int **)((int)pCVar15 + 0xc);
          param_7 = (int *)*piVar18;
          if (((uint)(piVar14 + 0x10) & 0xffffffc0) != ((int)piVar14 + 0x3fU & 0xffffffc0)) {
            uVar3 = FUN_006baad0("C:\\dev\\wiggles\\CodeLib\\StdTools\\KStdLib\\Include\\DSFastArray.h"
                                 ,0x9b);
            piVar14 = *(int **)((int)pCVar15 + 0xc);
            *(undefined4 *)((int)pCVar15 + 8) = uVar3;
          }
          *(int **)((int)pCVar15 + 0xc) = (int *)((int)piVar14 + 1U);
          param_8 = piVar14;
          if ((int *)((int)piVar14 + 1U) <= piVar14) {
            (*pcVar1)(0xc000008c,1,0,0);
          }
          iVar5 = *(int *)((int)pCVar15 + 8);
          *(undefined4 *)(iVar5 + (int)param_8 * 8) =
               *(undefined4 *)((int)param_7 + (int)param_4 * 8);
          *(undefined4 *)(iVar5 + 4 + (int)param_8 * 8) =
               *(undefined4 *)((int)param_7 + 4 + (int)param_4 * 8);
          puVar11 = local_28;
          pcVar1 = RaiseException_exref;
        }
        *(undefined4 *)((int)pCVar15 + 0x10) = puVar11[6];
        *(undefined4 *)((int)pCVar15 + 0x14) = puVar11[7];
        *(undefined4 *)((int)pCVar15 + 0x18) = puVar11[4];
        *(undefined4 *)((int)pCVar15 + 0x1c) = puVar11[5];
        *(undefined4 *)((int)pCVar15 + 0x20) = puVar11[8];
        *(undefined4 *)((int)pCVar15 + 0x24) = puVar11[9];
        local_34 = (undefined4 *)0x0;
        LOCK();
        iVar5 = puVar11[1] + -1;
        puVar11[1] = iVar5;
        UNLOCK();
        if (iVar5 == 0) {
          (**(code **)*puVar11)(1);
        }
        puVar11 = (undefined4 *)FUN_006ba810(899);
        if (puVar11 == (undefined4 *)0x0) {
          puVar11 = (undefined4 *)0x0;
        }
        else {
          puVar11[1] = 0;
          *puVar11 = CPath::vftable;
          puVar11[2] = 0;
          puVar11[3] = 0;
          puVar11[4] = 0;
          puVar11[5] = 0;
          puVar11[6] = 0;
          puVar11[7] = 0;
        }
        if (puVar11 != (undefined4 *)0x0) {
          LOCK();
          puVar11[1] = puVar11[1] + 1;
          UNLOCK();
        }
        local_8 = CONCAT31(local_8._1_3_,3);
        puVar11[4] = *(undefined4 *)((int)pCVar15 + 0x10);
        puVar11[5] = *(undefined4 *)((int)pCVar15 + 0x14);
        puVar11[6] = *(undefined4 *)((int)pCVar15 + 0x18);
        puVar11[7] = *(undefined4 *)((int)pCVar15 + 0x1c);
        puVar11[8] = *(undefined4 *)((int)pCVar15 + 0x20);
        puVar11[9] = 0;
        param_7 = (int *)0x0;
        local_24 = puVar11;
        if (*(int *)((int)pCVar15 + 0xc) != 1 && -1 < *(int *)((int)pCVar15 + 0xc) + -1) {
          do {
            if (*(uint *)((int)pCVar15 + 0xc) <= param_7) {
              (*pcVar1)(0xc000008c,1,0,0);
            }
            param_4 = (undefined4 *)((int)param_7 * 8);
            FUN_0059fc70(&local_20,*(int *)((int)pCVar15 + 8) + (int)param_4);
            param_7 = (int *)((int)param_7 + 1);
            if (*(uint *)((int)pCVar15 + 0xc) <= param_7) {
              (*pcVar1)(0xc000008c,1,0,0);
            }
            FUN_0059fc70(&local_18,*(int *)((int)pCVar15 + 8) + (int)param_4 + 8U);
            uVar4 = puVar11[3];
            if ((uVar4 + 0x40 & 0xffffffc0) != (uVar4 + 0x3f & 0xffffffc0)) {
              uVar3 = FUN_006baad0("C:\\dev\\wiggles\\CodeLib\\StdTools\\KStdLib\\Include\\DSFastArray.h"
                                   ,0x9b);
              uVar4 = puVar11[3];
              puVar11[2] = uVar3;
            }
            puVar11[3] = uVar4 + 1;
            if (uVar4 + 1 <= uVar4) {
              (*pcVar1)(0xc000008c,1,0,0);
            }
            iVar5 = puVar11[2];
            *(uint *)(iVar5 + uVar4 * 8) = local_20;
            *(uint *)(iVar5 + 4 + uVar4 * 8) = local_1c;
            uVar17 = local_1c & 7;
            uVar4 = local_20 & 7;
            iVar5 = FUN_00592f10(PTR_0077241c);
            if ((*(byte *)((uVar17 << 3 | uVar4) + 0x3c + iVar5) & 10) != 0) {
              uVar17 = (uint)local_14 & 7;
              uVar4 = (uint)local_18 & 7;
              param_8 = local_14;
              param_4 = (undefined4 *)local_18;
              iVar5 = FUN_00592f10(PTR_0077241c);
              if ((*(byte *)((uVar17 << 3 | uVar4) + 0x3c + iVar5) & 10) != 0) {
                uVar4 = (int)(local_20 - (int)param_4) >> 0x1f;
                uVar17 = (int)(local_1c - (int)param_8) >> 0x1f;
                if ((float)(int)((local_20 - (int)param_4 ^ uVar4) - uVar4) <
                    (float)(int)((local_1c - (int)param_8 ^ uVar17) - uVar17) * 1.5) {
                  uVar4 = puVar11[3];
                  param_4 = (undefined4 *)((int)((int)param_4 + local_20) / 2);
                  param_8 = (int *)((int)(local_1c + (int)param_8) / 2);
                  if ((uVar4 + 0x40 & 0xffffffc0) != (uVar4 + 0x3f & 0xffffffc0)) {
                    uVar3 = FUN_006baad0("C:\\dev\\wiggles\\CodeLib\\StdTools\\KStdLib\\Include\\DSFastArray.h"
                                         ,0x9b);
                    uVar4 = puVar11[3];
                    puVar11[2] = uVar3;
                  }
                  puVar11[3] = uVar4 + 1;
                  if (uVar4 + 1 <= uVar4) {
                    (*pcVar1)(0xc000008c,1,0,0);
                  }
                  iVar5 = puVar11[2];
                  *(undefined4 **)(iVar5 + uVar4 * 8) = param_4;
                  *(int **)(iVar5 + 4 + uVar4 * 8) = param_8;
                }
                else {
                  param_8 = (int *)(float)(int)((int)param_8 - local_1c);
                  param_4 = (undefined4 *)(float)(int)((int)param_4 - local_20);
                  fVar20 = (float)param_8 * (float)param_8 + (float)param_4 * (float)param_4 + 0.0;
                  FUN_0040b7e0();
                  param_4 = (undefined4 *)((float)param_4 / fVar20);
                  param_8 = (int *)((float)param_8 / fVar20);
                  local_28 = (undefined4 *)(fVar20 - 2.0);
                  param_5 = 2.0;
                  if (2.0 <= (float)local_28) {
                    do {
                      local_44 = (int)ROUND(param_5 * (float)param_4) + local_20;
                      local_3c = (float)param_8 * param_5;
                      DAT_00772dd8 = (int)ROUND(local_3c);
                      local_40 = DAT_00772dd8 + local_1c;
                      puVar8 = (uint *)FUN_0059fc70(local_4c,&local_44);
                      local_3c = (float)*puVar8;
                      local_38 = puVar8[1];
                      uVar4 = puVar11[3];
                      if ((uVar4 + 0x40 & 0xffffffc0) != (uVar4 + 0x3f & 0xffffffc0)) {
                        uVar3 = FUN_006baad0("C:\\dev\\wiggles\\CodeLib\\StdTools\\KStdLib\\Include\\DSFastArray.h"
                                             ,0x9b);
                        uVar4 = puVar11[3];
                        puVar11[2] = uVar3;
                      }
                      puVar11[3] = uVar4 + 1;
                      if (uVar4 + 1 <= uVar4) {
                        (*pcVar1)(0xc000008c,1,0,0);
                      }
                      iVar5 = puVar11[2];
                      param_5 = param_5 + 2.0;
                      *(float *)(iVar5 + uVar4 * 8) = local_3c;
                      *(uint *)(iVar5 + 4 + uVar4 * 8) = local_38;
                    } while (param_5 <= (float)local_28);
                  }
                }
              }
            }
            pCVar15 = local_30;
          } while ((int)param_7 < *(int *)((int)local_30 + 0xc) + -1);
        }
        uVar4 = puVar11[3];
        if ((uVar4 + 0x40 & 0xffffffc0) != (uVar4 + 0x3f & 0xffffffc0)) {
          uVar3 = FUN_006baad0("C:\\dev\\wiggles\\CodeLib\\StdTools\\KStdLib\\Include\\DSFastArray.h"
                               ,0x9b);
          uVar4 = puVar11[3];
          puVar11[2] = uVar3;
        }
        uVar17 = uVar4 + 1;
        puVar11[3] = uVar17;
        param_4 = (undefined4 *)uVar4;
        if (*(uint *)((int)pCVar15 + 0xc) <= param_7) {
          (*pcVar1)(0xc000008c,1,0,0);
          uVar17 = puVar11[3];
        }
        param_8 = *(int **)((int)pCVar15 + 8);
        if (uVar17 <= param_4) {
          (*pcVar1)(0xc000008c,1,0,0);
        }
        iVar5 = puVar11[2];
        local_2c = (int *)0x0;
        *(undefined4 *)(iVar5 + (int)param_4 * 8) = *(undefined4 *)((int)param_8 + (int)param_7 * 8)
        ;
        *(undefined4 *)(iVar5 + 4 + (int)param_4 * 8) =
             *(undefined4 *)((int)param_8 + 4 + (int)param_7 * 8);
        puVar11[9] = puVar11[3];
        LOCK();
        iVar5 = *(int *)((int)pCVar15 + 4) + -1;
        *(int *)((int)pCVar15 + 4) = iVar5;
        UNLOCK();
        if (iVar5 == 0) {
          (*(code *)**(undefined4 **)pCVar15)(1);
        }
        param_4 = (undefined4 *)0x0;
        local_8 = CONCAT31(local_8._1_3_,4);
        if ((char)param_6 != '\0') {
          puVar9 = (undefined4 *)FUN_006ba810(0x418);
          if (puVar9 == (undefined4 *)0x0) {
            puVar16 = (undefined4 *)0x0;
          }
          else {
            puVar9[1] = 0;
            *puVar9 = CPath::vftable;
            puVar9[2] = 0;
            puVar9[3] = 0;
            puVar9[4] = 0;
            puVar9[5] = 0;
            puVar9[6] = 0;
            puVar9[7] = 0;
            puVar16 = puVar9;
          }
          if (puVar16 != (undefined4 *)0x0) {
            LOCK();
            puVar16[1] = puVar16[1] + 1;
            UNLOCK();
          }
          puVar16[4] = puVar11[4];
          puVar16[5] = puVar11[5];
          puVar16[6] = puVar11[6];
          puVar16[7] = puVar11[7];
          puVar16[8] = puVar11[8];
          param_7 = (int *)puVar16[3];
          param_4 = puVar16;
          if (((int)param_7 + 0x40U & 0xffffffc0) != ((int)param_7 + 0x3fU & 0xffffffc0)) {
            param_7 = puVar9;
            uVar3 = FUN_006baad0("C:\\dev\\wiggles\\CodeLib\\StdTools\\KStdLib\\Include\\DSFastArray.h"
                                 ,0x9b);
            param_7 = (int *)puVar16[3];
            puVar16[2] = uVar3;
          }
          uVar4 = (int)param_7 + 1;
          puVar16[3] = uVar4;
          if ((uint)puVar11[3] <= param_7) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            uVar4 = puVar16[3];
          }
          iVar5 = (int)param_7 * 8;
          param_6 = (undefined4 *)(puVar11[2] + iVar5);
          bVar19 = uVar4 <= param_7;
          param_7 = (int *)iVar5;
          if (bVar19) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          iVar5 = puVar16[2];
          *(undefined4 *)(iVar5 + (int)param_7) = *param_6;
          ((undefined4 *)(iVar5 + (int)param_7))[1] = param_6[1];
          param_7 = (int *)puVar16[3];
          if (((int)param_7 + 0x40U & 0xffffffc0) != ((int)param_7 + 0x3fU & 0xffffffc0)) {
            uVar3 = FUN_006baad0("C:\\dev\\wiggles\\CodeLib\\StdTools\\KStdLib\\Include\\DSFastArray.h"
                                 ,0x9b);
            param_7 = (int *)puVar16[3];
            puVar16[2] = uVar3;
          }
          uVar4 = (int)param_7 + 1;
          puVar16[3] = uVar4;
          if ((uint)puVar11[3] <= param_7) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            uVar4 = puVar16[3];
          }
          param_4 = (undefined4 *)((int)param_7 * 8);
          param_6 = (undefined4 *)(puVar11[2] + (int)param_4);
          if (uVar4 <= param_7) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          iVar5 = puVar16[2];
          *(undefined4 *)(iVar5 + (int)param_4) = *param_6;
          ((undefined4 *)(iVar5 + (int)param_4))[1] = param_6[1];
          puVar16[9] = 2;
          uVar4 = puVar16[3];
          if (uVar4 <= param_7) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            uVar4 = puVar16[3];
          }
          param_6 = (undefined4 *)((int)param_7 - 1);
          if (uVar4 <= param_6) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            uVar4 = puVar16[3];
          }
          if (uVar4 <= param_7) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            uVar4 = puVar16[3];
          }
          if (uVar4 <= param_6) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            uVar4 = puVar16[3];
          }
          if (uVar4 <= param_7) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            uVar4 = puVar16[3];
          }
          if (uVar4 <= param_6) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            uVar4 = puVar16[3];
          }
          if (uVar4 <= param_7) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            uVar4 = puVar16[3];
          }
          if (uVar4 <= param_6) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            uVar4 = puVar16[3];
          }
          if (uVar4 <= param_7) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            uVar4 = puVar16[3];
          }
          if (uVar4 <= param_6) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            uVar4 = puVar16[3];
          }
          if (uVar4 <= param_7) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            uVar4 = puVar16[3];
          }
          if (uVar4 <= param_6) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            uVar4 = puVar16[3];
          }
          if (uVar4 <= param_7) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            uVar4 = puVar16[3];
          }
          if (uVar4 <= param_6) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            uVar4 = puVar16[3];
          }
          if (uVar4 <= param_7) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            uVar4 = puVar16[3];
          }
          if (uVar4 <= param_6) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          param_6 = (undefined4 *)0x2;
          if (2 < (int)puVar11[3]) {
            bVar19 = 2 < (uint)puVar11[3];
            do {
              if (!bVar19) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              if ((uint)puVar16[3] <= param_7) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              if ((uint)puVar11[3] <= param_6) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              if ((uint)puVar16[3] <= param_7) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              if ((uint)puVar11[3] <= param_6) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              if ((uint)puVar16[3] <= param_7) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              if ((uint)puVar11[3] <= param_6) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              if ((uint)puVar16[3] <= param_7) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              if ((uint)puVar11[3] <= param_6) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              if ((uint)puVar16[3] <= param_7) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              if ((uint)puVar11[3] <= param_6) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              if ((uint)puVar16[3] <= param_7) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              if ((uint)puVar11[3] <= param_6) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              if ((uint)puVar16[3] <= param_7) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              if ((uint)puVar11[3] <= param_6) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              if ((uint)puVar16[3] <= param_7) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              if ((uint)puVar11[3] <= param_6) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              param_8 = (int *)puVar11[2];
              if ((uint)puVar16[3] <= param_7) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              iVar6 = puVar16[2];
              *(undefined4 *)(iVar6 + (int)param_4) =
                   *(undefined4 *)((int)param_8 + (int)param_6 * 8);
              iVar5 = (int)param_6 * 8;
              param_6 = (undefined4 *)((int)param_6 + 1);
              ((undefined4 *)(iVar6 + (int)param_4))[1] = *(undefined4 *)((int)param_8 + 4 + iVar5);
              bVar19 = param_6 < (uint)puVar11[3];
            } while ((int)param_6 < (int)puVar11[3]);
          }
          LOCK();
          iVar5 = puVar11[1] + -1;
          puVar11[1] = iVar5;
          UNLOCK();
          if (iVar5 == 0) {
            (**(code **)*puVar11)(1);
          }
          FUN_00449180();
          FUN_0043e3c0();
          piVar18 = puVar16 + 1;
          *param_1 = puVar16;
          LOCK();
          *piVar18 = *piVar18 + 1;
          UNLOCK();
          LOCK();
          iVar5 = *piVar18;
          *piVar18 = *piVar18 + -1;
          UNLOCK();
          if (iVar5 != 1) {
            ExceptionList = local_10;
            return param_1;
          }
          (**(code **)*puVar16)(1);
          ExceptionList = local_10;
          return param_1;
        }
        piVar18 = puVar11 + 1;
        *param_1 = puVar11;
        LOCK();
        *piVar18 = *piVar18 + 1;
        UNLOCK();
        LOCK();
        iVar5 = *piVar18;
        *piVar18 = *piVar18 + -1;
        UNLOCK();
        if (iVar5 != 1) {
          ExceptionList = local_10;
          return param_1;
        }
        (**(code **)*puVar11)(1);
        ExceptionList = local_10;
        return param_1;
      }
      bVar19 = piVar14 == (int *)0x0;
      if ((int)piVar14 < 1) goto LAB_005a3118;
      param_7 = (int *)((int)piVar14 + -1);
      local_2c = (int *)((int)piVar18 + 1);
      iVar5 = ((int)local_2c * DAT_00b9bf20 + (int)fVar20) % DAT_00b9bf28;
      if ((iVar5 < 0) || (DAT_00b9bf1c <= iVar5)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pfVar10 = DAT_00b9bf18;
      }
      else {
        pfVar10 = DAT_00b9bf18 + iVar5;
      }
      if (((int)*pfVar10 < (int)param_5) &&
         (cVar2 = FUN_0059aa20(fVar20,piVar18,fVar20,local_2c,param_5), cVar2 != '\0')) {
        param_8 = local_2c;
        iVar5 = ((int)local_2c * DAT_00b9bf20 + (int)fVar20) % DAT_00b9bf28;
        if ((iVar5 < 0) || (DAT_00b9bf1c <= iVar5)) {
          param_4 = (undefined4 *)fVar20;
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar10 = DAT_00b9bf18;
        }
        else {
          pfVar10 = DAT_00b9bf18 + iVar5;
          param_4 = (undefined4 *)fVar20;
        }
        param_5 = *pfVar10;
      }
      local_2c = (int *)((int)piVar18 + -1);
      iVar5 = ((int)local_2c * DAT_00b9bf20 + (int)fVar20) % DAT_00b9bf28;
      if ((iVar5 < 0) || (DAT_00b9bf1c <= iVar5)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pfVar10 = DAT_00b9bf18;
      }
      else {
        pfVar10 = DAT_00b9bf18 + iVar5;
      }
      if (((int)*pfVar10 < (int)param_5) &&
         (cVar2 = FUN_0059aa20(fVar20,piVar18,fVar20,local_2c,local_2c), cVar2 != '\0')) {
        param_8 = local_2c;
        iVar5 = ((int)local_2c * DAT_00b9bf20 + (int)fVar20) % DAT_00b9bf28;
        if ((iVar5 < 0) || (DAT_00b9bf1c <= iVar5)) {
          param_4 = (undefined4 *)fVar20;
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar10 = DAT_00b9bf18;
        }
        else {
          pfVar10 = DAT_00b9bf18 + iVar5;
          param_4 = (undefined4 *)fVar20;
        }
        param_5 = *pfVar10;
      }
      iVar5 = (DAT_00b9bf20 * (int)piVar18 + 1 + (int)fVar20) % DAT_00b9bf28;
      if ((iVar5 < 0) || (DAT_00b9bf1c <= iVar5)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pfVar10 = DAT_00b9bf18;
      }
      else {
        pfVar10 = DAT_00b9bf18 + iVar5;
      }
      if (((int)*pfVar10 < (int)param_5) &&
         (cVar2 = FUN_0059aa20(fVar20,piVar18,(int)fVar20 + 1,piVar18,pfVar10), cVar2 != '\0')) {
        param_4 = (undefined4 *)((int)fVar20 + 1);
        iVar5 = (DAT_00b9bf20 * (int)piVar18 + 1 + (int)fVar20) % DAT_00b9bf28;
        if ((iVar5 < 0) || (DAT_00b9bf1c <= iVar5)) {
          param_8 = piVar18;
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar10 = DAT_00b9bf18;
        }
        else {
          pfVar10 = DAT_00b9bf18 + iVar5;
          param_8 = piVar18;
        }
        param_5 = *pfVar10;
      }
      iVar5 = (DAT_00b9bf20 * (int)piVar18 + -1 + (int)fVar20) % DAT_00b9bf28;
      if ((iVar5 < 0) || (DAT_00b9bf1c <= iVar5)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pfVar10 = DAT_00b9bf18;
      }
      else {
        pfVar10 = DAT_00b9bf18 + iVar5;
      }
      if (((int)*pfVar10 < (int)param_5) &&
         (cVar2 = FUN_0059aa20(fVar20,piVar18,(int)fVar20 - 1,piVar18,pfVar10), cVar2 != '\0')) {
        param_4 = (undefined4 *)((int)fVar20 - 1);
        iVar5 = (DAT_00b9bf20 * (int)piVar18 + -1 + (int)fVar20) % DAT_00b9bf28;
        if ((iVar5 < 0) || (DAT_00b9bf1c <= iVar5)) {
          param_8 = piVar18;
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar10 = DAT_00b9bf18;
        }
        else {
          pfVar10 = DAT_00b9bf18 + iVar5;
          param_8 = piVar18;
        }
        param_5 = *pfVar10;
      }
      piVar13 = param_8;
      if ((((undefined4 *)fVar20 == param_4) && (piVar18 == param_8)) || (param_7 == (int *)0x0))
      goto LAB_005a2bfa;
      local_3c = (float)param_4;
      uVar4 = local_14[1];
      if ((uVar4 + 0x40 & 0xffffffc0) != (uVar4 + 0x3f & 0xffffffc0)) {
        local_2c = (int *)uVar4;
        iVar5 = FUN_006baad0("C:\\dev\\wiggles\\CodeLib\\StdTools\\KStdLib\\Include\\DSFastArray.h",
                             0x9b);
        uVar4 = local_14[1];
        *local_14 = iVar5;
      }
      local_14[1] = uVar4 + 1;
      local_2c = (int *)uVar4;
      if (uVar4 + 1 <= uVar4) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      local_38 = uVar4 * 8;
      piVar14 = (int *)(*local_14 + local_38);
      iVar5 = FUN_00592f10(PTR_0077241c);
      piVar18 = local_14;
      *piVar14 = (*(byte *)(iVar5 + 0x12) & 7) + (int)param_4 * 8;
      if ((uint)local_14[1] <= local_2c) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      iVar6 = *piVar18 + local_38;
      iVar5 = FUN_00592f10(PTR_0077241c);
      *(uint *)(iVar6 + 4) = (*(byte *)(iVar5 + 0x12) >> 3 & 7) + (int)param_8 * 8;
      local_28[9] = local_28[9] + 1;
      piVar14 = param_7;
      fVar20 = local_3c;
      piVar18 = piVar13;
    } while( true );
  }
  while( true ) {
    if ((fVar20 == (float)local_1c) && ((CMap *)piVar18 == local_30)) goto LAB_005a3116;
    bVar19 = piVar14 == (int *)0x0;
    if ((int)piVar14 < 1) goto LAB_005a3118;
    param_7 = (int *)((int)piVar14 + -1);
    local_2c = (int *)((int)piVar18 + 1);
    iVar5 = ((int)local_2c * DAT_00b9bf20 + (int)fVar20) % DAT_00b9bf28;
    if ((iVar5 < 0) || (DAT_00b9bf1c <= iVar5)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      pfVar10 = DAT_00b9bf18;
    }
    else {
      pfVar10 = DAT_00b9bf18 + iVar5;
    }
    if (((int)*pfVar10 < (int)param_5) &&
       (cVar2 = FUN_0059aad0(fVar20,piVar18,fVar20,local_2c), cVar2 != '\0')) {
      param_8 = local_2c;
      iVar5 = ((int)local_2c * DAT_00b9bf20 + (int)fVar20) % DAT_00b9bf28;
      if ((iVar5 < 0) || (DAT_00b9bf1c <= iVar5)) {
        param_4 = (undefined4 *)fVar20;
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pfVar10 = DAT_00b9bf18;
      }
      else {
        pfVar10 = DAT_00b9bf18 + iVar5;
        param_4 = (undefined4 *)fVar20;
      }
      param_5 = *pfVar10;
    }
    local_2c = (int *)((int)piVar18 + -1);
    iVar5 = ((int)local_2c * DAT_00b9bf20 + (int)fVar20) % DAT_00b9bf28;
    if ((iVar5 < 0) || (DAT_00b9bf1c <= iVar5)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      pfVar10 = DAT_00b9bf18;
    }
    else {
      pfVar10 = DAT_00b9bf18 + iVar5;
    }
    if (((int)*pfVar10 < (int)param_5) &&
       (cVar2 = FUN_0059aad0(fVar20,piVar18,fVar20,local_2c), cVar2 != '\0')) {
      param_8 = local_2c;
      iVar5 = ((int)local_2c * DAT_00b9bf20 + (int)fVar20) % DAT_00b9bf28;
      if ((iVar5 < 0) || (DAT_00b9bf1c <= iVar5)) {
        param_4 = (undefined4 *)fVar20;
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pfVar10 = DAT_00b9bf18;
      }
      else {
        pfVar10 = DAT_00b9bf18 + iVar5;
        param_4 = (undefined4 *)fVar20;
      }
      param_5 = *pfVar10;
    }
    iVar5 = (DAT_00b9bf20 * (int)piVar18 + 1 + (int)fVar20) % DAT_00b9bf28;
    if ((iVar5 < 0) || (DAT_00b9bf1c <= iVar5)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      pfVar10 = DAT_00b9bf18;
    }
    else {
      pfVar10 = DAT_00b9bf18 + iVar5;
    }
    if (((int)*pfVar10 < (int)param_5) &&
       (cVar2 = FUN_0059aad0(fVar20,piVar18,(int)fVar20 + 1,piVar18), cVar2 != '\0')) {
      param_4 = (undefined4 *)((int)fVar20 + 1);
      iVar5 = (DAT_00b9bf20 * (int)piVar18 + 1 + (int)fVar20) % DAT_00b9bf28;
      if ((iVar5 < 0) || (DAT_00b9bf1c <= iVar5)) {
        param_8 = piVar18;
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pfVar10 = DAT_00b9bf18;
      }
      else {
        pfVar10 = DAT_00b9bf18 + iVar5;
        param_8 = piVar18;
      }
      param_5 = *pfVar10;
    }
    iVar5 = (DAT_00b9bf20 * (int)piVar18 + -1 + (int)fVar20) % DAT_00b9bf28;
    if ((iVar5 < 0) || (DAT_00b9bf1c <= iVar5)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      pfVar10 = DAT_00b9bf18;
    }
    else {
      pfVar10 = DAT_00b9bf18 + iVar5;
    }
    if (((int)*pfVar10 < (int)param_5) &&
       (cVar2 = FUN_0059aad0(fVar20,piVar18,(int)fVar20 - 1,piVar18), cVar2 != '\0')) {
      param_4 = (undefined4 *)((int)fVar20 - 1);
      iVar5 = (DAT_00b9bf20 * (int)piVar18 + -1 + (int)fVar20) % DAT_00b9bf28;
      if ((iVar5 < 0) || (DAT_00b9bf1c <= iVar5)) {
        param_8 = piVar18;
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pfVar10 = DAT_00b9bf18;
      }
      else {
        pfVar10 = DAT_00b9bf18 + iVar5;
        param_8 = piVar18;
      }
      param_5 = *pfVar10;
    }
    piVar13 = param_8;
    if ((((undefined4 *)fVar20 == param_4) && (piVar18 == param_8)) || (param_7 == (int *)0x0))
    break;
    local_38 = (uint)param_4;
    uVar4 = local_14[1];
    if ((uVar4 + 0x40 & 0xffffffc0) != (uVar4 + 0x3f & 0xffffffc0)) {
      local_2c = (int *)uVar4;
      iVar5 = FUN_006baad0("C:\\dev\\wiggles\\CodeLib\\StdTools\\KStdLib\\Include\\DSFastArray.h",
                           0x9b);
      uVar4 = local_14[1];
      *local_14 = iVar5;
    }
    local_14[1] = uVar4 + 1;
    local_2c = (int *)uVar4;
    if (uVar4 + 1 <= uVar4) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    local_3c = (float)(uVar4 * 8);
    piVar14 = (int *)(*local_14 + (int)local_3c);
    iVar5 = FUN_00592f10(PTR_0077241c);
    piVar18 = local_14;
    *piVar14 = (*(byte *)(iVar5 + 0x12) & 7) + (int)param_4 * 8;
    if ((uint)local_14[1] <= local_2c) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    iVar6 = *piVar18 + (int)local_3c;
    iVar5 = FUN_00592f10(PTR_0077241c);
    *(uint *)(iVar6 + 4) = (*(byte *)(iVar5 + 0x12) >> 3 & 7) + (int)param_8 * 8;
    local_28[9] = local_28[9] + 1;
    piVar14 = param_7;
    fVar20 = (float)local_38;
    piVar18 = piVar13;
  }
  iVar5 = 0;
  if (0 < *(int *)((int)local_24 + 4)) {
    do {
      piVar18 = *(int **)((int)local_24 + 0xc);
      if ((iVar5 < 0) || (piVar18[1] <= iVar5)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        param_7 = (int *)*piVar18;
        piVar18 = *(int **)((int)local_24 + 0xc);
      }
      else {
        param_7 = (int *)(*piVar18 + iVar5 * 8);
      }
      if ((iVar5 < 0) || (piVar18[1] <= iVar5)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        iVar6 = *piVar18;
      }
      else {
        iVar6 = *piVar18 + iVar5 * 8;
      }
      iVar6 = (*(int *)(iVar6 + 4) * DAT_00b9bf20 + *param_7) % DAT_00b9bf28;
      if ((iVar6 < 0) || (DAT_00b9bf1c <= iVar6)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pfVar10 = DAT_00b9bf18;
      }
      else {
        pfVar10 = DAT_00b9bf18 + iVar6;
      }
      *pfVar10 = NAN;
      iVar5 = iVar5 + 1;
    } while (iVar5 < *(int *)((int)local_24 + 4));
  }
LAB_005a30de:
  *param_1 = 0;
  LOCK();
  iVar5 = local_28[1] + -1;
  local_28[1] = iVar5;
  UNLOCK();
  puVar11 = local_28;
LAB_005a30f2:
  if (iVar5 != 0) {
    ExceptionList = local_10;
    return param_1;
  }
  (**(code **)*puVar11)(1);
  ExceptionList = local_10;
  return param_1;
LAB_005a2bfa:
  iVar5 = 0;
  if (0 < *(int *)((int)local_24 + 4)) {
    do {
      piVar18 = *(int **)((int)local_24 + 0xc);
      if ((iVar5 < 0) || (piVar18[1] <= iVar5)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        param_7 = (int *)*piVar18;
        piVar18 = *(int **)((int)local_24 + 0xc);
      }
      else {
        param_7 = (int *)(*piVar18 + iVar5 * 8);
      }
      if ((iVar5 < 0) || (piVar18[1] <= iVar5)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        iVar6 = *piVar18;
      }
      else {
        iVar6 = *piVar18 + iVar5 * 8;
      }
      iVar6 = (*(int *)(iVar6 + 4) * DAT_00b9bf20 + *param_7) % DAT_00b9bf28;
      if ((iVar6 < 0) || (DAT_00b9bf1c <= iVar6)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pfVar10 = DAT_00b9bf18;
      }
      else {
        pfVar10 = DAT_00b9bf18 + iVar6;
      }
      *pfVar10 = NAN;
      iVar5 = iVar5 + 1;
    } while (iVar5 < *(int *)((int)local_24 + 4));
  }
  goto LAB_005a30de;
}

