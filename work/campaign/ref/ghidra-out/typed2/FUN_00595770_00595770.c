
void __thiscall FUN_00595770(CMap *this)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  CMapCell *pCVar8;
  int iVar9;
  uint uVar10;
  float fVar11;
  double dVar12;
  float fVar13;
  float *in_stack_00000004;
  float *in_stack_00000008;
  undefined1 *in_stack_0000000c;
  uint local_48;
  int local_44;
  int local_40;
  int local_3c;
  uint local_38;
  uint local_2c;
  uint local_28;
  int local_24;
  int local_1c;
  
  uVar7 = (uint)ROUND(*in_stack_00000008 * 8.0);
  uVar1 = (uint)ROUND(in_stack_00000008[1] * 8.0);
  DAT_00772dd8 = uVar1;
  *in_stack_0000000c = 0;
  local_3c = 1;
  local_40 = 0x7fffffff;
  if ((((this->x0_8 + 0x30 <= (int)uVar7) && ((int)uVar7 < this->x1_8 + -0x30)) &&
      (this->y0_8 + 0x30 <= (int)uVar1)) && ((int)uVar1 < this->y1_8 + -0x30)) {
    if ((9 < (int)uVar7) && (9 < (int)uVar1)) {
      iVar2 = FUN_00592f10(this);
      uVar10 = uVar1 & 7;
      if ((*(byte *)((uVar10 * 8 | uVar7 & 7) + 0x3c + iVar2) & 1) == 0) {
        iVar2 = 0x30;
        local_44 = 0x30;
        local_48 = uVar1;
        local_38 = uVar7;
        local_2c = uVar1;
        local_28 = uVar7;
        do {
          if (0 < local_3c) {
            iVar2 = local_38 - uVar7;
            local_24 = local_3c;
            do {
              local_38 = local_38 + 1;
              iVar2 = iVar2 + 1;
              iVar3 = FUN_00592f10(this);
              iVar4 = local_44;
              if (((*(byte *)((local_38 & 7 | uVar10 * 8) + 0x3c + iVar3) & 1) != 0) &&
                 (iVar3 = iVar2 * iVar2 + (local_48 - uVar1) * (local_48 - uVar1), iVar3 < local_40)
                 ) {
                *in_stack_0000000c = 1;
                dVar12 = (double)iVar3;
                if (dVar12 < 0.0) {
                  __libm_sse2_sqrt_precise();
                }
                else {
                  dVar12 = SQRT(dVar12);
                }
                local_2c = local_48;
                iVar4 = (int)((float)dVar12 + (float)dVar12 + 2.1);
                local_40 = iVar3;
                local_28 = local_38;
                if (local_44 <= iVar4) {
                  iVar4 = local_44;
                }
              }
              local_44 = iVar4;
              local_24 = local_24 + -1;
            } while (local_24 != 0);
            iVar4 = local_48 - uVar1;
            local_1c = local_3c;
            do {
              local_48 = local_48 + 1;
              iVar4 = iVar4 + 1;
              iVar2 = this->cellX0;
              if (this->cellX0 <= (int)local_38 >> 3) {
                iVar2 = (int)local_38 >> 3;
              }
              iVar3 = this->cellY0;
              if (this->cellY0 <= (int)local_48 >> 3) {
                iVar3 = (int)local_48 >> 3;
              }
              iVar5 = this->cellY1 + -1;
              if (iVar3 < this->cellY1) {
                iVar5 = iVar3;
              }
              iVar3 = this->cellX1 + -1;
              if (iVar2 < this->cellX1) {
                iVar3 = iVar2;
              }
              iVar2 = (iVar5 * this->mapWidth + iVar3) % this->cellCountTotal;
              if ((iVar2 < 0) || (this->cellCount <= iVar2)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                pCVar8 = this->cells;
              }
              else {
                pCVar8 = this->cells + iVar2;
              }
              uVar10 = local_48 & 7;
              iVar2 = local_44;
              if (((pCVar8->sampleFlags[uVar10 * 8 | local_38 & 7] & 1) != 0) &&
                 (iVar3 = iVar4 * iVar4 + (local_38 - uVar7) * (local_38 - uVar7), iVar3 < local_40)
                 ) {
                *in_stack_0000000c = 1;
                dVar12 = (double)iVar3;
                if (dVar12 < 0.0) {
                  __libm_sse2_sqrt_precise();
                }
                else {
                  dVar12 = SQRT(dVar12);
                }
                iVar2 = (int)((float)dVar12 + (float)dVar12 + 2.1);
                local_40 = iVar3;
                local_2c = local_48;
                local_28 = local_38;
                if (local_44 <= iVar2) {
                  iVar2 = local_44;
                }
              }
              local_44 = iVar2;
              local_1c = local_1c + -1;
              iVar2 = local_44;
            } while (local_1c != 0);
          }
          iVar4 = local_3c + 1;
          if (0 < iVar4) {
            iVar2 = local_38 - uVar7;
            local_1c = iVar4;
            do {
              local_38 = local_38 - 1;
              iVar2 = iVar2 + -1;
              iVar5 = (int)local_38 >> 3;
              iVar3 = this->cellX0;
              if (this->cellX0 <= iVar5) {
                iVar3 = iVar5;
              }
              iVar9 = this->cellY0;
              if (this->cellY0 <= (int)local_48 >> 3) {
                iVar9 = (int)local_48 >> 3;
              }
              iVar6 = this->cellY1 + -1;
              if (iVar9 < this->cellY1) {
                iVar6 = iVar9;
              }
              iVar9 = this->cellX1 + -1;
              if (iVar3 < this->cellX1) {
                iVar9 = iVar3;
              }
              iVar3 = (iVar6 * this->mapWidth + iVar9) % this->cellCountTotal;
              if ((iVar3 < 0) || (this->cellCount <= iVar3)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                pCVar8 = this->cells;
              }
              else {
                pCVar8 = this->cells + iVar3;
              }
              iVar3 = local_44;
              if (((pCVar8->sampleFlags[local_38 & 7 | (local_48 & 7) << 3] & 1) != 0) &&
                 (iVar9 = iVar2 * iVar2 + (local_48 - uVar1) * (local_48 - uVar1), iVar9 < local_40)
                 ) {
                *in_stack_0000000c = 1;
                dVar12 = (double)iVar9;
                if (dVar12 < 0.0) {
                  __libm_sse2_sqrt_precise();
                }
                else {
                  dVar12 = SQRT(dVar12);
                }
                local_2c = local_48;
                iVar3 = (int)((float)dVar12 + (float)dVar12 + 2.1);
                local_40 = iVar9;
                local_28 = local_38;
                if (local_44 <= iVar3) {
                  iVar3 = local_44;
                }
              }
              local_44 = iVar3;
              local_1c = local_1c + -1;
            } while (local_1c != 0);
            iVar3 = local_48 - uVar1;
            local_1c = iVar4;
            do {
              local_48 = local_48 - 1;
              iVar3 = iVar3 + -1;
              iVar2 = this->cellX0;
              if (this->cellX0 <= iVar5) {
                iVar2 = iVar5;
              }
              iVar4 = this->cellY0;
              if (this->cellY0 <= (int)local_48 >> 3) {
                iVar4 = (int)local_48 >> 3;
              }
              iVar9 = this->cellY1 + -1;
              if (iVar4 < this->cellY1) {
                iVar9 = iVar4;
              }
              iVar4 = this->cellX1 + -1;
              if (iVar2 < this->cellX1) {
                iVar4 = iVar2;
              }
              iVar2 = (iVar9 * this->mapWidth + iVar4) % this->cellCountTotal;
              if ((iVar2 < 0) || (this->cellCount <= iVar2)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                pCVar8 = this->cells;
              }
              else {
                pCVar8 = this->cells + iVar2;
              }
              uVar10 = local_48 & 7;
              iVar2 = local_44;
              if (((pCVar8->sampleFlags[uVar10 * 8 | local_38 & 7] & 1) != 0) &&
                 (iVar4 = iVar3 * iVar3 + (local_38 - uVar7) * (local_38 - uVar7), iVar4 < local_40)
                 ) {
                *in_stack_0000000c = 1;
                dVar12 = (double)iVar4;
                if (dVar12 < 0.0) {
                  __libm_sse2_sqrt_precise();
                }
                else {
                  dVar12 = SQRT(dVar12);
                }
                iVar2 = (int)((float)dVar12 + (float)dVar12 + 2.1);
                local_40 = iVar4;
                local_2c = local_48;
                local_28 = local_38;
                if (local_44 <= iVar2) {
                  iVar2 = local_44;
                }
              }
              local_44 = iVar2;
              local_1c = local_1c + -1;
              iVar2 = local_44;
            } while (local_1c != 0);
          }
          local_3c = local_3c + 2;
        } while (local_3c < iVar2);
        fVar13 = in_stack_00000008[2];
        uVar7 = FUN_004093f0(this);
        fVar11 = (float)((uVar7 & 0xff) + 1);
        if (fVar13 <= fVar11) {
          fVar13 = fVar11;
        }
        fVar11 = 14.5;
        if (fVar13 <= 14.5) {
          fVar11 = fVar13;
        }
        *in_stack_00000004 = (float)(int)local_28 * 0.125;
        in_stack_00000004[2] = fVar11;
        in_stack_00000004[1] = (float)(int)local_2c * 0.125;
        return;
      }
      *in_stack_0000000c = 1;
      fVar13 = in_stack_00000008[2];
      *in_stack_00000004 = (float)(int)uVar7 * 0.125;
      in_stack_00000004[1] = (float)(int)uVar1 * 0.125;
      in_stack_00000004[2] = fVar13;
      return;
    }
    *in_stack_00000004 = 0.0;
    in_stack_00000004[1] = 0.0;
    in_stack_00000004[2] = 0.0;
    return;
  }
  *in_stack_00000004 = *in_stack_00000008;
  in_stack_00000004[1] = in_stack_00000008[1];
  in_stack_00000004[2] = in_stack_00000008[2];
  return;
}

