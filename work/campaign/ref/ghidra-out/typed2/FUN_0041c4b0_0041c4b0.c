
void FUN_0041c4b0(void)

{
  uint *puVar1;
  CMap *pCVar2;
  int iVar3;
  byte *_Dst;
  int iVar4;
  byte *pbVar5;
  CMapCell *pCVar6;
  uint uVar7;
  int *in_ECX;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  uint local_40;
  uint local_3c;
  uint local_38;
  int local_34;
  byte *local_2c;
  uint local_24;
  int local_20;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  iVar3 = in_ECX[7] + 8;
  iVar9 = in_ECX[4] + -8;
  iVar10 = in_ECX[5] + -8;
  iVar14 = in_ECX[6] + 8;
  iVar15 = iVar14 - iVar9;
  *(undefined1 *)(in_ECX + 0xb) = 0;
  iVar11 = (iVar3 - iVar10) * iVar15;
  thunk_FUN_0060fc30(0);
  _Dst = (byte *)FUN_006ba810(0x5e);
  if ((((iVar9 < PTR_0077241c->x0_8) || (iVar10 < PTR_0077241c->y0_8)) ||
      (PTR_0077241c->x1_8 <= iVar14)) || (PTR_0077241c->y1_8 <= iVar3)) {
    _memset(_Dst,0xf0f0f0f,(iVar14 - iVar9) * (iVar3 - iVar10));
    *(undefined1 *)(in_ECX + 0xb) = 1;
  }
  else {
    local_18 = iVar9;
    local_14 = iVar10;
    local_10 = iVar14;
    local_c = iVar3;
    FUN_00595e40(_Dst,&local_18);
    iVar3 = 0;
    if (0 < iVar11) {
      do {
        _Dst[iVar3] = _Dst[iVar3] & 0xf;
        iVar3 = iVar3 + 1;
      } while (iVar3 < iVar11);
    }
  }
  iVar3 = in_ECX[3];
  local_3c = 0;
  if (0 < iVar3) {
    local_38 = 0;
    do {
      if ((uint)in_ECX[3] <= local_3c) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      local_40 = 0;
      iVar14 = (int)(*(float *)(in_ECX[2] + local_38) * 8.0);
      iVar3 = (int)(((float *)(in_ECX[2] + local_38))[1] * 8.0);
      iVar16 = ((iVar3 - iVar10) * iVar15 - iVar9) + iVar14;
      iVar12 = (((iVar3 - iVar10) + -1) * iVar15 - iVar9) + iVar14;
      do {
        if ((iVar16 < 0) || (iVar11 <= iVar16)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          local_2c = _Dst;
        }
        else {
          local_2c = _Dst + iVar16;
        }
        if ((iVar12 < 0) || (iVar11 <= iVar12)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pbVar5 = _Dst;
        }
        else {
          pbVar5 = _Dst + iVar12;
        }
        if (2 < (int)((uint)*local_2c - (uint)*pbVar5)) {
          if ((uint)in_ECX[3] <= local_3c) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
LAB_0041c7d6:
          *(float *)(local_38 + 4 + in_ECX[2]) = (float)(int)(iVar3 + local_40) * 0.125;
          break;
        }
        iVar13 = (iVar3 - iVar10) - (local_40 >> 1);
        iVar4 = (iVar13 * iVar15 - iVar9) + iVar14;
        if ((iVar4 < 0) || (iVar11 <= iVar4)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          local_2c = _Dst;
        }
        else {
          local_2c = _Dst + iVar4;
        }
        iVar4 = ((iVar13 + -1) * iVar15 - iVar9) + iVar14;
        if ((iVar4 < 0) || (iVar11 <= iVar4)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pbVar5 = _Dst;
        }
        else {
          pbVar5 = _Dst + iVar4;
        }
        if (2 < (int)((uint)*local_2c - (uint)*pbVar5)) {
          if ((uint)in_ECX[3] <= local_3c) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          local_40 = -(local_40 >> 1);
          goto LAB_0041c7d6;
        }
        local_40 = local_40 + 1;
        iVar12 = iVar12 + iVar15;
        iVar16 = iVar16 + iVar15;
      } while ((int)local_40 < 3);
      local_38 = local_38 + 0xc;
      iVar3 = in_ECX[3];
      local_3c = local_3c + 1;
    } while ((int)local_3c < iVar3);
  }
  local_24 = 0;
  if (0 < iVar3) {
    local_34 = 0;
    local_20 = 0;
    do {
      if ((local_20 < 0) || (in_ECX[1] <= local_20)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        iVar3 = *in_ECX;
      }
      else {
        iVar3 = *in_ECX + local_20 * 4;
      }
      if ((uint)in_ECX[3] <= local_24) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      pCVar2 = PTR_0077241c;
      DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX[2] + local_34) * 8.0);
      iVar14 = (int)ROUND(((float *)(in_ECX[2] + local_34))[1] * 8.0) + -1;
      iVar12 = DAT_00772dd8 - iVar9;
      local_40 = 0;
      local_38 = 1000;
      if ((((DAT_00772dd8 < PTR_0077241c->x0_8 + 8) || (PTR_0077241c->x1_8 + -8 <= DAT_00772dd8)) ||
          (iVar14 < PTR_0077241c->y0_8 + 8)) || (PTR_0077241c->y1_8 + -8 <= iVar14)) {
        *(undefined1 *)(in_ECX + 0xb) = 1;
      }
      else {
        iVar13 = (int)((iVar14 >> 0x1f & 7U) + iVar14) >> 3;
        iVar4 = (int)(DAT_00772dd8 + (DAT_00772dd8 >> 0x1f & 7U)) >> 3;
        iVar16 = PTR_0077241c->cellX0;
        if (PTR_0077241c->cellX0 <= iVar4) {
          iVar16 = iVar4;
        }
        iVar4 = PTR_0077241c->cellY0;
        if (PTR_0077241c->cellY0 <= iVar13) {
          iVar4 = iVar13;
        }
        iVar13 = PTR_0077241c->cellY1 + -1;
        if (iVar4 < PTR_0077241c->cellY1) {
          iVar13 = iVar4;
        }
        iVar4 = PTR_0077241c->cellX1 + -1;
        if (iVar16 < PTR_0077241c->cellX1) {
          iVar4 = iVar16;
        }
        iVar16 = (iVar13 * PTR_0077241c->mapWidth + iVar4) % PTR_0077241c->cellCountTotal;
        if ((iVar16 < 0) || (PTR_0077241c->cellCount <= iVar16)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pCVar6 = pCVar2->cells;
        }
        else {
          pCVar6 = PTR_0077241c->cells + iVar16;
        }
        if (pCVar6->field_0x6 != -1) {
          iVar16 = (iVar14 - iVar10) * iVar15 + iVar12;
          if ((iVar16 < 0) || (iVar11 <= iVar16)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pbVar5 = _Dst;
          }
          else {
            pbVar5 = _Dst + iVar16;
          }
          local_38 = (uint)*pbVar5;
          iVar12 = ((iVar14 - iVar10) + 2) * iVar15 + iVar12;
          if ((iVar12 < 0) || (iVar11 <= iVar12)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            local_40 = (uint)*_Dst;
          }
          else {
            local_40 = (uint)_Dst[iVar12];
          }
        }
      }
      uVar8 = 0;
      do {
        if (uVar8 < local_38 * 4 + 1) {
          uVar7 = 0x10000000;
LAB_0041ca6b:
          puVar1 = (uint *)(iVar3 + uVar8 * 4);
          *puVar1 = *puVar1 | uVar7;
        }
        else if ((int)(local_40 * 4 + -1) <= (int)uVar8) {
          uVar7 = 0x8000000;
          goto LAB_0041ca6b;
        }
        uVar8 = uVar8 + 1;
      } while ((int)uVar8 < 0x40);
      local_24 = local_24 + 1;
      local_34 = local_34 + 0xc;
      local_20 = local_20 + 0x40;
    } while ((int)local_24 < in_ECX[3]);
  }
  thunk_FUN_0060fc30(_Dst);
  return;
}

