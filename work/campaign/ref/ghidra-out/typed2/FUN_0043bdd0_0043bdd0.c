
void FUN_0043bdd0(void)

{
  int iVar1;
  int iVar2;
  CMap *pCVar3;
  float fVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  int in_ECX;
  uint uVar8;
  int iVar9;
  uint uVar10;
  CMapCell *pCVar11;
  int *piVar12;
  uint uVar13;
  code *pcVar14;
  undefined1 local_4c [8];
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  float local_2c;
  int *local_28;
  uint local_24;
  int *local_20;
  undefined4 local_1c;
  float local_18;
  uint local_14;
  int local_10;
  uint local_c;
  uint local_8;
  
  pcVar14 = RaiseException_exref;
  piVar12 = (int *)(DAT_00772400 + 0xa328);
  if (*(uint *)(in_ECX + 4) < 8) {
    piVar12 = piVar12 + *(uint *)(in_ECX + 4) * 4;
  }
  else {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  local_30 = *piVar12;
  iVar1 = piVar12[1];
  local_34 = piVar12[2];
  iVar2 = piVar12[3];
  if ((0 < local_34 - local_30) && (0 < iVar2 - iVar1)) {
    local_1c = *(undefined4 *)(in_ECX + 4);
    local_8 = 0xffffffff;
    local_10 = DAT_0077244c;
    iVar6 = DAT_0077244c;
    while( true ) {
      uVar13 = local_8 + 1;
      if ((int)*(uint *)(iVar6 + 0x84d7) <= (int)uVar13) break;
      local_8 = uVar13;
      if (*(uint *)(iVar6 + 0x84d7) <= uVar13) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        iVar6 = local_10;
      }
      uVar13 = *(uint *)(*(int *)(iVar6 + 0x84d3) + uVar13 * 4);
      piVar12 = (int *)(iVar6 + 0x488);
      if (uVar13 < 0x2000) {
        piVar12 = piVar12 + uVar13;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        iVar6 = local_10;
      }
      if ((*(int *)(*piVar12 + 0x36c) == *(int *)(in_ECX + 4)) &&
         (iVar9 = *(int *)(*piVar12 + 0x3e4), *(int *)(iVar9 + 0xc) == 0xe)) {
        local_28 = *(int **)(iVar9 + 0x1c);
        uVar13 = 0;
        local_2c = *(float *)(iVar9 + 0x20);
        local_c = *(uint *)(in_ECX + 0x3078);
        piVar12 = local_28;
        fVar4 = local_2c;
        if (0 < (int)local_c) {
          do {
            local_18 = fVar4;
            local_20 = piVar12;
            if (*(uint *)(in_ECX + 0x3078) <= uVar13) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            local_14 = uVar13 * 0x10;
            DAT_00772dd8 = (int *)(int)ROUND((float)local_20);
            local_24 = *(int *)(*(int *)(in_ECX + 0x3074) + local_14) - (int)DAT_00772dd8;
            if (*(uint *)(in_ECX + 0x3078) <= uVar13) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            DAT_00772dd8 = (int *)(int)ROUND(local_18);
            uVar5 = *(int *)(*(int *)(in_ECX + 0x3074) + 4 + local_14) - (int)DAT_00772dd8;
            uVar8 = (int)uVar5 >> 0x1f;
            if ((int)(((uVar5 ^ uVar8) - uVar8) +
                     ((local_24 ^ (int)local_24 >> 0x1f) - ((int)local_24 >> 0x1f))) < 5) {
              if (*(uint *)(in_ECX + 0x3078) <= uVar13) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              *(undefined4 *)(local_14 + 8 + *(int *)(in_ECX + 0x3074)) = 0x41200000;
              uVar13 = local_c + 1;
            }
            uVar13 = uVar13 + 1;
            piVar12 = local_20;
            fVar4 = local_18;
          } while ((int)uVar13 < (int)local_c);
        }
        iVar6 = local_10;
        if (uVar13 == local_c) {
          piVar12 = (int *)(in_ECX + 0x3074);
          local_c = FUN_0043d450();
          DAT_00772dd8 = (int *)(int)ROUND((float)local_28);
          local_28 = DAT_00772dd8;
          if (*(uint *)(in_ECX + 0x3078) <= local_c) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          local_14 = local_c * 0x10;
          *(int **)(local_14 + *piVar12) = local_28;
          DAT_00772dd8 = (int *)(int)ROUND(local_2c);
          local_2c = (float)DAT_00772dd8;
          if (*(uint *)(in_ECX + 0x3078) <= local_c) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          *(float *)(*piVar12 + 4 + local_14) = local_2c;
          if (*(uint *)(in_ECX + 0x3078) <= local_c) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          *(undefined4 *)(*piVar12 + 8 + local_14) = 0x3f800000;
          if (*(uint *)(in_ECX + 0x3078) <= local_c) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          *(undefined4 *)(local_14 + 0xc + *piVar12) = 0;
          iVar6 = local_10;
        }
      }
    }
    local_10 = *(int *)(in_ECX + 0x3078);
    uVar13 = 0;
    if (0 < local_10) {
      local_8 = 0;
      do {
        if (*(uint *)(in_ECX + 0x3078) <= uVar13) {
          (*pcVar14)(0xc000008c,1,0,0);
        }
        *(float *)(local_8 + 8 + *(int *)(in_ECX + 0x3074)) =
             *(float *)(local_8 + 8 + *(int *)(in_ECX + 0x3074)) - 1.0;
        if (*(uint *)(in_ECX + 0x3078) <= uVar13) {
          (*pcVar14)(0xc000008c,1,0,0);
        }
        iVar6 = *(int *)(in_ECX + 0x3074);
        if (*(float *)(local_8 + 8 + iVar6) <= 0.0) {
          uVar5 = *(uint *)(in_ECX + 0x3078);
          if (uVar5 <= uVar13) {
            (*pcVar14)(0xc000008c,1,0,0);
            iVar6 = *(int *)(in_ECX + 0x3074);
            uVar5 = *(uint *)(in_ECX + 0x3078);
          }
          pcVar14 = RaiseException_exref;
          local_2c = (float)(local_8 + iVar6);
          if (uVar5 <= uVar13) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar6 = *(int *)(in_ECX + 0x3074);
          }
          iVar9 = (int)((float)*(int *)(local_8 + iVar6) + 0.5);
          iVar6 = (int)((float)*(int *)((int)local_2c + 4) + 0.5);
          if ((((iVar9 < PTR_0077241c->cellX0) || (PTR_0077241c->cellX1 <= iVar9)) ||
              (iVar6 < PTR_0077241c->cellY0)) ||
             ((PTR_0077241c->cellY1 <= iVar6 ||
              (iVar6 = FUN_00592f10(PTR_0077241c), pcVar14 = RaiseException_exref,
              (*(uint *)(iVar6 + 8) & 0xf << ((char)local_1c * '\x04' & 0x1fU)) == 0)))) {
            uVar5 = *(uint *)(in_ECX + 0x3078);
            if (uVar5 <= uVar13) {
              (*pcVar14)(0xc000008c,1,0,0);
              uVar5 = *(uint *)(in_ECX + 0x3078);
              if (uVar5 <= uVar13) {
                (*pcVar14)(0xc000008c,1,0,0);
                uVar5 = *(uint *)(in_ECX + 0x3078);
              }
            }
            if ((int)uVar13 < (int)(uVar5 - 1)) {
              iVar6 = local_8 + *(int *)(in_ECX + 0x3074);
              FUN_006d1b90(iVar6,iVar6 + 0x10,(uVar5 - uVar13) * 0x10 + -0x10);
              uVar5 = *(uint *)(in_ECX + 0x3078);
            }
            *(uint *)(in_ECX + 0x3078) = uVar5 - 1;
            uVar13 = uVar13 - 1;
            local_8 = local_8 + -0x10;
            local_10 = local_10 + -1;
          }
          else {
            if (*(uint *)(in_ECX + 0x3078) <= uVar13) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            *(float *)(local_8 + 0xc + *(int *)(in_ECX + 0x3074)) =
                 *(float *)(local_8 + 0xc + *(int *)(in_ECX + 0x3074)) + 1.0;
          }
        }
        uVar13 = uVar13 + 1;
        local_8 = local_8 + 0x10;
      } while ((int)uVar13 < local_10);
    }
    local_24 = 2000;
    do {
      local_24 = local_24 + -1;
      local_10 = *(int *)(in_ECX + 0x307c) + 1;
      *(int *)(in_ECX + 0x307c) = local_10;
      if ((local_10 < local_30) || (local_34 <= local_10)) {
        *(int *)(in_ECX + 0x3080) = *(int *)(in_ECX + 0x3080) + 1;
        *(int *)(in_ECX + 0x307c) = local_30;
        local_10 = local_30;
      }
      local_8 = *(int *)(in_ECX + 0x3080);
      if (((int)local_8 < iVar1) || (iVar2 <= (int)local_8)) {
        *(int *)(in_ECX + 0x3080) = iVar1;
        local_8 = iVar1;
      }
      local_c = *(uint *)(in_ECX + 0x3078);
      uVar13 = 0;
      local_18 = (float)((uint)local_18 & 0xffffff00);
      if ((int)local_c < 1) {
LAB_0043c332:
        pCVar3 = PTR_0077241c;
        iVar9 = (int)((float)local_10 + 0.5);
        iVar6 = (int)((float)(int)local_8 + 0.5);
        if ((((PTR_0077241c->cellX0 <= iVar9) && (iVar9 < PTR_0077241c->cellX1)) &&
            (PTR_0077241c->cellY0 <= iVar6)) && (iVar6 < PTR_0077241c->cellY1)) {
          iVar6 = (PTR_0077241c->mapWidth * iVar6 + iVar9) % PTR_0077241c->cellCountTotal;
          if ((iVar6 < 0) || (PTR_0077241c->cellCount <= iVar6)) {
            (*pcVar14)(0xc000008c,1,0,0);
            pCVar11 = pCVar3->cells;
          }
          else {
            pCVar11 = PTR_0077241c->cells + iVar6;
          }
          if ((pCVar11->digMarks & 0xf << ((char)local_1c * '\x04' & 0x1fU)) != 0) {
            local_38 = local_8;
            local_40 = local_8;
            local_3c = local_10;
            local_44 = local_10;
            piVar12 = (int *)FUN_005981d0(local_4c,&local_44,&local_3c,local_1c);
            local_10 = *piVar12;
            local_8 = piVar12[1];
            if ((0 < local_10) && (0 < (int)local_8)) {
              uVar13 = 0;
              local_20 = (int *)((uint)local_20 & 0xffffff00);
              if (0 < (int)local_c) {
                do {
                  uVar5 = *(uint *)(in_ECX + 0x3078);
                  if (uVar5 <= uVar13) {
                    (*pcVar14)(0xc000008c,1,0,0);
                    uVar5 = *(uint *)(in_ECX + 0x3078);
                  }
                  pcVar14 = RaiseException_exref;
                  iVar6 = *(int *)(in_ECX + 0x3074);
                  local_2c = (float)(uVar13 * 0x10);
                  local_28 = (int *)(iVar6 + (int)local_2c);
                  if (uVar5 <= uVar13) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    iVar6 = *(int *)(in_ECX + 0x3074);
                  }
                  uVar5 = local_8 - *(int *)((int)local_2c + 4 + iVar6);
                  uVar8 = (int)uVar5 >> 0x1f;
                  uVar10 = local_10 - *local_28 >> 0x1f;
                  local_20 = (int *)((uint)local_20 & 0xff);
                  if ((int)(((uVar5 ^ uVar8) - uVar8) + ((local_10 - *local_28 ^ uVar10) - uVar10))
                      < 0x14) {
                    local_20 = (int *)0x1;
                    uVar13 = local_c;
                  }
                  uVar13 = uVar13 + 1;
                } while ((int)uVar13 < (int)local_c);
                if ((char)local_20 != '\0') goto LAB_0043c641;
              }
              uVar13 = *(uint *)(in_ECX + 0x3078);
              if ((uVar13 + 0x10 & 0xfffffff0) != (uVar13 + 0xf & 0xfffffff0)) {
                uVar7 = FUN_006baad0("C:\\dev\\wiggles\\CodeLib\\StdTools\\KStdLib\\Include\\DSFastArray.h"
                                     ,0x9b);
                uVar13 = *(uint *)(in_ECX + 0x3078);
                *(undefined4 *)(in_ECX + 0x3074) = uVar7;
              }
              uVar5 = uVar13 + 1;
              *(uint *)(in_ECX + 0x3078) = uVar5;
              if (uVar5 <= uVar13) {
                (*pcVar14)(0xc000008c,1,0,0);
                uVar5 = *(uint *)(in_ECX + 0x3078);
              }
              local_14 = uVar5 - 1;
              if (uVar5 <= local_14) {
                (*pcVar14)(0xc000008c,1,0,0);
              }
              uVar13 = local_14;
              *(int *)(*(int *)(in_ECX + 0x3074) + local_14 * 0x10) = local_10;
              if (*(uint *)(in_ECX + 0x3078) <= local_14) {
                (*pcVar14)(0xc000008c,1,0,0);
              }
              *(uint *)(*(int *)(in_ECX + 0x3074) + 4 + uVar13 * 0x10) = local_8;
              if (*(uint *)(in_ECX + 0x3078) <= local_14) {
                (*pcVar14)(0xc000008c,1,0,0);
              }
              *(undefined4 *)(*(int *)(in_ECX + 0x3074) + 8 + uVar13 * 0x10) = 0x3f800000;
              if (*(uint *)(in_ECX + 0x3078) <= local_14) {
                (*pcVar14)(0xc000008c,1,0,0);
              }
              *(undefined4 *)(*(int *)(in_ECX + 0x3074) + 0xc + uVar13 * 0x10) = 0;
            }
          }
        }
      }
      else {
        do {
          uVar5 = *(uint *)(in_ECX + 0x3078);
          if (uVar5 <= uVar13) {
            (*pcVar14)(0xc000008c,1,0,0);
            uVar5 = *(uint *)(in_ECX + 0x3078);
          }
          pcVar14 = RaiseException_exref;
          iVar6 = *(int *)(in_ECX + 0x3074);
          local_2c = (float)(uVar13 * 0x10);
          local_28 = (int *)(iVar6 + (int)local_2c);
          if (uVar5 <= uVar13) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar6 = *(int *)(in_ECX + 0x3074);
          }
          uVar5 = local_8 - *(int *)((int)local_2c + 4 + iVar6);
          uVar8 = (int)uVar5 >> 0x1f;
          uVar10 = local_10 - *local_28 >> 0x1f;
          local_18 = (float)((uint)local_18 & 0xff);
          if ((int)(((uVar5 ^ uVar8) - uVar8) + ((local_10 - *local_28 ^ uVar10) - uVar10)) < 8) {
            local_18 = 1.4013e-45;
            uVar13 = local_c;
          }
          uVar13 = uVar13 + 1;
        } while ((int)uVar13 < (int)local_c);
        if (SUB41(local_18,0) == '\0') goto LAB_0043c332;
      }
LAB_0043c641:
    } while (0 < (int)local_24);
  }
  return;
}

