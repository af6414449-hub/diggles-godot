
void FUN_00532a70(uint param_1,uint param_2)

{
  CMap *pCVar1;
  ushort uVar2;
  int iVar3;
  ushort uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  char cVar8;
  uint uVar9;
  int iVar10;
  float10 fVar11;
  float in_XMM1_Da;
  float fVar12;
  float in_XMM2_Da;
  int iVar13;
  int iVar14;
  undefined4 uVar15;
  uint local_40;
  undefined8 local_28;
  int iStack_20;
  int iStack_1c;
  
  local_28 = (double)CONCAT44(local_28._4_4_,in_XMM1_Da);
  if ((((PTR_0077241c->x0f + 2.0 <= in_XMM1_Da) && (in_XMM1_Da < PTR_0077241c->x1f - 2.0)) &&
      (PTR_0077241c->y0f + 2.0 <= in_XMM2_Da)) && (in_XMM2_Da < PTR_0077241c->y1f - 2.0)) {
    iVar3 = (int)in_XMM1_Da;
    iVar6 = (int)*(float *)(DAT_00772374 + 0x194);
    if ((((float)(int)(PTR_0077241c->cellX0 + iVar6 + param_1) <= in_XMM1_Da + 0.5) &&
        ((float)(int)(PTR_0077241c->cellY0 + iVar6 + param_1) <= in_XMM2_Da + 0.5)) &&
       ((in_XMM1_Da - 0.5 <= (float)(int)((PTR_0077241c->cellX1 - iVar6) - param_1) &&
        (in_XMM2_Da - 0.5 <= (float)(int)((PTR_0077241c->cellY1 - iVar6) - param_1))))) {
      iVar6 = iVar3 * 8 + -0x10;
      iVar10 = (int)in_XMM2_Da * 8 + 0x10;
      iVar13 = (int)in_XMM2_Da * 8 + -0x10;
      iVar14 = iVar3 * 8 + 0x10;
      uVar15 = 0x10;
      FUN_005a3dd0(iVar3,iVar6,iVar13,iVar14,iVar10,0x10);
      FUN_005a3fd0(iVar6,iVar13,iVar14,iVar10,uVar15);
      local_28 = (double)(float)local_28;
      fVar11 = (float10)FUN_006f52b0();
      local_28 = (double)fVar11;
      fVar12 = (float)fVar11;
      if (0.5 <= fVar12) {
        cVar8 = SUB81(local_28,0);
      }
      else {
        fVar11 = (float10)FUN_006f52b0();
        cVar8 = SUB81(local_28,0);
        fVar12 = (float)local_28;
        if ((float)fVar11 < 0.5) {
          cVar8 = '\0';
        }
      }
      if (0.5 <= fVar12) {
        fVar11 = (float10)FUN_006f52b0();
        fVar12 = (float)local_28;
        if ((float)fVar11 < 0.5) {
          cVar8 = '\x01';
        }
      }
      if (fVar12 < 0.5) {
        fVar11 = (float10)FUN_006f52b0();
        fVar12 = (float)local_28;
        if (0.5 <= (float)fVar11) {
          cVar8 = '\x02';
        }
      }
      if (0.5 <= fVar12) {
        local_28 = (double)in_XMM2_Da;
        fVar11 = (float10)FUN_006f52b0();
        local_28 = (double)fVar11;
        if (0.5 <= (float)fVar11) {
          cVar8 = '\x03';
        }
      }
      iVar3 = FUN_00592f10(PTR_0077241c);
      if (((*(ushort *)(iVar3 + 0x14) >> (('\a' - cVar8) * '\x02' & 0x1fU) & 3) == param_1) &&
         (iVar3 = FUN_00592f10(PTR_0077241c), (*(ushort *)(iVar3 + 0x14) >> 5 & 7) == param_2)) {
        iVar3 = FUN_00592f10(PTR_0077241c);
        local_40 = *(ushort *)(iVar3 + 0x14) & 0x1f;
        iVar3 = FUN_00592f10(PTR_0077241c);
        uVar9 = 0;
        uVar4 = *(ushort *)(iVar3 + 0x14);
        local_28 = (double)CONCAT44(local_28._4_4_,(uint)uVar4);
        iVar3 = 0;
        while( true ) {
          uVar2 = uVar4 >> ((char)iVar3 + 8U & 0x1f) & 3;
          if (uVar2 == 0) {
            uVar9 = 0;
            goto LAB_00532e17;
          }
          if (uVar2 == 2) break;
          iVar3 = iVar3 + 2;
          if (7 < iVar3) {
LAB_00532e17:
            uVar5 = 0;
            uVar7 = 0;
            do {
              if ((uVar4 >> (((char)uVar7 + '\x04') * '\x02' & 0x1fU) & 3) != uVar9) {
                uVar5 = uVar5 | 1 << (uVar7 & 0x1f);
              }
              uVar7 = uVar7 + 1;
            } while ((int)uVar7 < 4);
            iVar3 = DAT_0076a338 + 0x28b8 + (uVar4 >> 5 & 7) * 0x204 + uVar9 * 0x100;
            if (uVar5 < 0x10) {
              iVar3 = uVar5 * 0x10 + iVar3;
            }
            else {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            if (*(int *)(iVar3 + 4) == 0) {
              uVar4 = (ushort)local_40;
            }
            else {
              uVar4 = (ushort)((int)(local_40 + 1) % *(int *)(iVar3 + 4));
            }
            iVar3 = FUN_00592f10(PTR_0077241c);
            *(ushort *)(iVar3 + 0x14) = *(ushort *)(iVar3 + 0x14) & 0xffe0;
            iVar3 = FUN_00592f10(PTR_0077241c);
            *(ushort *)(iVar3 + 0x14) = *(ushort *)(iVar3 + 0x14) | uVar4 & 0x1f;
            return;
          }
        }
        uVar9 = 1;
        goto LAB_00532e17;
      }
      iVar3 = FUN_00592f10(PTR_0077241c);
      uVar4 = *(ushort *)(iVar3 + 0x14);
      if (param_1 == 0) {
        param_2 = uVar4 >> 5 & 7;
      }
      iVar3 = FUN_00592f10(PTR_0077241c);
      *(ushort *)(iVar3 + 0x14) =
           (ushort)(((param_1 & 0xffff) << 9 | param_2) << 5) | uVar4 & 0x3f00;
      iVar3 = FUN_00592f10(PTR_0077241c);
      uVar4 = *(ushort *)(iVar3 + 0x14);
      if (param_1 == 0) {
        param_2 = uVar4 >> 5 & 7;
      }
      iVar3 = FUN_00592f10(PTR_0077241c);
      pCVar1 = PTR_0077241c;
      *(ushort *)(iVar3 + 0x14) =
           (ushort)(((param_1 & 0xffff) << 3 | param_2) << 5) | uVar4 & 0xfc00;
      iVar3 = FUN_00592f10(pCVar1);
      uVar4 = *(ushort *)(iVar3 + 0x14);
      if (param_1 == 0) {
        param_2 = uVar4 >> 5 & 7;
      }
      iVar3 = FUN_00592f10(PTR_0077241c);
      pCVar1 = PTR_0077241c;
      *(ushort *)(iVar3 + 0x14) =
           (ushort)(((param_1 & 0xffff) << 7 | param_2) << 5) | uVar4 & 0xcf00;
      iVar3 = FUN_00592f10(pCVar1);
      uVar4 = *(ushort *)(iVar3 + 0x14);
      if (param_1 == 0) {
        param_2 = uVar4 >> 5 & 7;
      }
      iVar10 = (int)(in_XMM1_Da + 0.5);
      iVar3 = FUN_00592f10(PTR_0077241c);
      iVar6 = (int)(in_XMM2_Da + 0.5);
      *(ushort *)(iVar3 + 0x14) =
           (ushort)(((param_1 & 0xffff) << 5 | param_2) << 5) | uVar4 & 0xf300;
      iStack_1c = iVar6 + 2;
      local_28 = (double)CONCAT44(iVar6 + -2,iVar10 + -2);
      iStack_20 = iVar10 + 2;
      FUN_00533070(&local_28,param_1);
    }
  }
  return;
}

