
void FUN_005f0330(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int in_ECX;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int *piVar13;
  uint uVar14;
  uint uVar15;
  bool bVar16;
  int local_10;
  int local_c;
  
  piVar13 = (int *)(DAT_00772400 + 0xa328);
  if (*(uint *)(in_ECX + 0x1c) < 8) {
    piVar13 = piVar13 + *(uint *)(in_ECX + 0x1c) * 4;
  }
  else {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  iVar2 = *piVar13;
  iVar3 = piVar13[1];
  iVar4 = piVar13[2];
  iVar5 = piVar13[3];
  if ((0 < iVar4 - iVar2) && (0 < iVar5 - iVar3)) {
    iVar1 = *(int *)(in_ECX + 0x1c);
    uVar14 = 0;
    if (0 < *(int *)(in_ECX + 0x2c)) {
      bVar16 = *(int *)(in_ECX + 0x2c) != 0;
      local_10 = 0;
      do {
        if (!bVar16) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        piVar13 = (int *)(*(int *)(in_ECX + 0x28) + 8 + local_10);
        *piVar13 = *piVar13 + -1;
        if (*(uint *)(in_ECX + 0x2c) <= uVar14) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        if (*(int *)(*(int *)(in_ECX + 0x28) + 8 + local_10) < 1) {
          uVar15 = *(uint *)(in_ECX + 0x2c);
          if (uVar15 <= uVar14) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            uVar15 = *(uint *)(in_ECX + 0x2c);
            if (uVar15 <= uVar14) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              uVar15 = *(uint *)(in_ECX + 0x2c);
            }
          }
          if ((int)uVar14 < (int)(uVar15 - 1)) {
            iVar9 = local_10 + *(int *)(in_ECX + 0x28);
            FUN_006d1b90(iVar9,iVar9 + 0xc,(uVar15 - uVar14) * 0xc + -0xc);
            uVar15 = *(uint *)(in_ECX + 0x2c);
          }
          uVar14 = uVar14 - 1;
          *(uint *)(in_ECX + 0x2c) = uVar15 - 1;
          local_10 = local_10 + -0xc;
        }
        uVar14 = uVar14 + 1;
        local_10 = local_10 + 0xc;
        bVar16 = uVar14 < *(uint *)(in_ECX + 0x2c);
      } while ((int)uVar14 < (int)*(uint *)(in_ECX + 0x2c));
    }
    iVar9 = 1000;
    do {
      if (*(int *)(in_ECX + 0x34) < 1) {
        return;
      }
      iVar9 = iVar9 + -1;
      local_c = *(int *)(in_ECX + 0x20) + 1;
      *(int *)(in_ECX + 0x20) = local_c;
      if ((local_c < iVar2) || (iVar4 <= local_c)) {
        *(int *)(in_ECX + 0x24) = *(int *)(in_ECX + 0x24) + 1;
        *(int *)(in_ECX + 0x20) = iVar2;
        local_c = iVar2;
      }
      local_10 = *(int *)(in_ECX + 0x24);
      if ((local_10 < iVar3) || (iVar5 <= local_10)) {
        *(int *)(in_ECX + 0x24) = iVar3;
        local_10 = iVar3;
      }
      uVar14 = *(uint *)(in_ECX + 0x2c);
      uVar15 = 0;
      bVar16 = false;
      if ((int)uVar14 < 1) {
LAB_005f057f:
        if ((0 < local_c) && (0 < local_10)) {
          iVar12 = (int)((float)local_c + 0.5);
          iVar8 = (int)((float)local_10 + 0.5);
          if (((PTR_0077241c->cellX0 <= iVar12) &&
              (((iVar12 < PTR_0077241c->cellX1 && (PTR_0077241c->cellY0 <= iVar8)) &&
               (iVar8 < PTR_0077241c->cellY1)))) &&
             ((iVar8 = FUN_00592f10(PTR_0077241c),
              (*(uint *)(iVar8 + 8) & 0xf << ((byte)(iVar1 << 2) & 0x1f)) != 0 &&
              (((iVar8 = FUN_00592f10(PTR_0077241c), *(char *)(iVar8 + 6) != -1 ||
                (iVar8 = FUN_00592f10(PTR_0077241c), *(char *)(iVar8 + 6) != -1)) ||
               ((iVar8 = FUN_00592f10(PTR_0077241c), *(char *)(iVar8 + 6) != -1 ||
                (iVar8 = FUN_00592f10(PTR_0077241c), *(char *)(iVar8 + 6) != -1)))))))) {
            uVar14 = FUN_00463a40();
            if (*(uint *)(in_ECX + 0x2c) <= uVar14) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            iVar8 = uVar14 * 0xc;
            *(int *)(iVar8 + *(int *)(in_ECX + 0x28)) = local_c;
            if (*(uint *)(in_ECX + 0x2c) <= uVar14) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            *(int *)(iVar8 + 4 + *(int *)(in_ECX + 0x28)) = local_10;
            if (*(uint *)(in_ECX + 0x2c) <= uVar14) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            *(undefined4 *)(iVar8 + 8 + *(int *)(in_ECX + 0x28)) = 0x32;
            FUN_005f48f0(1);
            uVar14 = *(uint *)(in_ECX + 0x3c) - 1;
            if (*(uint *)(in_ECX + 0x3c) <= uVar14) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            iVar8 = uVar14 * 0x2c;
            *(undefined4 *)(iVar8 + *(int *)(in_ECX + 0x38)) = 0x3f000000;
            if (*(uint *)(in_ECX + 0x3c) <= uVar14) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            *(undefined4 *)(iVar8 + 4 + *(int *)(in_ECX + 0x38)) = 0x3f000000;
            if (*(uint *)(in_ECX + 0x3c) <= uVar14) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            *(undefined4 *)(iVar8 + 8 + *(int *)(in_ECX + 0x38)) = 3;
            if (*(uint *)(in_ECX + 0x3c) <= uVar14) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            *(undefined1 *)(iVar8 + 0x25 + *(int *)(in_ECX + 0x38)) = 0;
            if (*(uint *)(in_ECX + 0x3c) <= uVar14) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            *(undefined4 *)(iVar8 + 0xc + *(int *)(in_ECX + 0x38)) = 0;
            if (*(uint *)(in_ECX + 0x3c) <= uVar14) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            iVar12 = *(int *)(in_ECX + 0x38);
            *(float *)(iVar8 + 0x14 + iVar12) = (float)local_c + 0.5;
            *(float *)(iVar8 + 0x18 + iVar12) = (float)local_10 + 0.5;
            *(undefined4 *)(iVar8 + 0x1c + iVar12) = 0x41700000;
            if (*(uint *)(in_ECX + 0x3c) <= uVar14) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            *(undefined4 *)(iVar8 + 0x10 + *(int *)(in_ECX + 0x38)) = 0;
          }
        }
      }
      else {
        do {
          uVar6 = *(uint *)(in_ECX + 0x2c);
          if (uVar6 <= uVar15) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            uVar6 = *(uint *)(in_ECX + 0x2c);
            uVar14 = uVar6;
          }
          iVar8 = *(int *)(in_ECX + 0x28);
          piVar13 = (int *)(iVar8 + uVar15 * 0xc);
          if (uVar6 <= uVar15) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar8 = *(int *)(in_ECX + 0x28);
            uVar14 = *(uint *)(in_ECX + 0x2c);
          }
          uVar6 = *(int *)(uVar15 * 0xc + 4 + iVar8) - local_10;
          uVar10 = (int)uVar6 >> 0x1f;
          uVar7 = *piVar13 - local_c;
          uVar11 = (int)uVar7 >> 0x1f;
          if ((int)(((uVar6 ^ uVar10) - uVar10) + ((uVar7 ^ uVar11) - uVar11)) < 5) {
            uVar14 = *(uint *)(in_ECX + 0x2c);
            bVar16 = true;
            uVar15 = uVar14;
          }
          uVar15 = uVar15 + 1;
        } while ((int)uVar15 < (int)uVar14);
        if (!bVar16) goto LAB_005f057f;
      }
    } while (0 < iVar9);
  }
  return;
}

