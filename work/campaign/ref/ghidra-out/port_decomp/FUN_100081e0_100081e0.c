
void FUN_100081e0(int param_1,code *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  char cVar7;
  uint uVar8;
  int iVar9;
  undefined4 *in_ECX;
  int iVar10;
  undefined4 *in_EDX;
  undefined4 *puVar11;
  int iVar12;
  undefined4 *puVar13;
  undefined4 *local_44;
  undefined4 *local_40;
  undefined4 *local_30;
  undefined4 *local_2c;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  uint local_8;
  
  local_8 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170b7c);
  uVar8 = (int)in_EDX - (int)in_ECX;
  local_2c = in_ECX;
  local_30 = in_EDX;
  do {
    if ((int)(uVar8 & 0xffffffe0) < 0x401) {
      puVar13 = in_ECX;
      puVar11 = in_ECX;
      if (in_ECX != local_30) {
        while (puVar11 = puVar11 + 8, puVar11 != local_30) {
          local_28 = *puVar11;
          uStack_24 = puVar11[1];
          uStack_20 = puVar11[2];
          uStack_1c = puVar11[3];
          local_18 = puVar11[4];
          uStack_14 = puVar11[5];
          uStack_10 = puVar11[6];
          uStack_c = puVar11[7];
          cVar7 = (*param_2)(&local_28,puVar13);
          if (cVar7 == '\0') {
            cVar7 = (*param_2)(&local_28,in_ECX);
            puVar1 = puVar11;
            puVar6 = in_ECX;
            while (cVar7 != '\0') {
              uVar2 = puVar6[1];
              uVar3 = puVar6[2];
              uVar4 = puVar6[3];
              *puVar1 = *puVar6;
              puVar1[1] = uVar2;
              puVar1[2] = uVar3;
              puVar1[3] = uVar4;
              uVar2 = puVar6[5];
              uVar3 = puVar6[6];
              uVar4 = puVar6[7];
              puVar1[4] = puVar6[4];
              puVar1[5] = uVar2;
              puVar1[6] = uVar3;
              puVar1[7] = uVar4;
              cVar7 = (*param_2)(&local_28,puVar6 + -8);
              puVar1 = puVar6;
              puVar13 = local_2c;
              puVar6 = puVar6 + -8;
            }
            *puVar1 = local_28;
            puVar1[1] = uStack_24;
            puVar1[2] = uStack_20;
            puVar1[3] = uStack_1c;
            puVar1[4] = local_18;
            puVar1[5] = uStack_14;
            puVar1[6] = uStack_10;
            puVar1[7] = uStack_c;
          }
          else {
            memmove((void *)((int)puVar11 + (0x20 - ((int)puVar11 - (int)puVar13))),puVar13,
                    (int)puVar11 - (int)puVar13);
            *puVar13 = local_28;
            puVar13[1] = uStack_24;
            puVar13[2] = uStack_20;
            puVar13[3] = uStack_1c;
            puVar13[4] = local_18;
            puVar13[5] = uStack_14;
            puVar13[6] = uStack_10;
            puVar13[7] = uStack_c;
          }
          in_ECX = in_ECX + 8;
        }
      }
LAB_100084e9:
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    if (param_1 < 1) {
      uVar8 = (int)local_30 - (int)in_ECX >> 5;
      iVar10 = (int)local_30 - (int)in_ECX >> 6;
      if (0 < iVar10) {
        iVar9 = (int)(uVar8 - 1) >> 1;
        puVar11 = in_ECX + iVar10 * 8;
        do {
          local_28 = puVar11[-8];
          uStack_24 = puVar11[-7];
          uStack_20 = puVar11[-6];
          uStack_1c = puVar11[-5];
          iVar10 = iVar10 + -1;
          local_18 = puVar11[-4];
          uStack_14 = puVar11[-3];
          uStack_10 = puVar11[-2];
          uStack_c = puVar11[-1];
          iVar5 = iVar10;
          while (iVar5 < iVar9) {
            iVar12 = iVar5 * 2 + 2;
            cVar7 = (*param_2)(in_ECX + iVar12 * 8,in_ECX + iVar12 * 8 + -8);
            if (cVar7 != '\0') {
              iVar12 = iVar5 * 2 + 1;
            }
            puVar13 = in_ECX + iVar12 * 8;
            uVar2 = puVar13[1];
            uVar3 = puVar13[2];
            uVar4 = puVar13[3];
            puVar1 = in_ECX + iVar5 * 8;
            *puVar1 = *puVar13;
            puVar1[1] = uVar2;
            puVar1[2] = uVar3;
            puVar1[3] = uVar4;
            puVar13 = in_ECX + iVar12 * 8 + 4;
            uVar2 = puVar13[1];
            uVar3 = puVar13[2];
            uVar4 = puVar13[3];
            puVar1 = in_ECX + iVar5 * 8 + 4;
            *puVar1 = *puVar13;
            puVar1[1] = uVar2;
            puVar1[2] = uVar3;
            puVar1[3] = uVar4;
            iVar5 = iVar12;
          }
          if ((iVar5 == iVar9) && ((uVar8 & 1) == 0)) {
            puVar1 = in_ECX + uVar8 * 8 + -8;
            uVar2 = puVar1[1];
            uVar3 = puVar1[2];
            uVar4 = puVar1[3];
            puVar13 = in_ECX + iVar5 * 8;
            *puVar13 = *puVar1;
            puVar13[1] = uVar2;
            puVar13[2] = uVar3;
            puVar13[3] = uVar4;
            puVar13 = in_ECX + uVar8 * 8 + -4;
            uVar2 = puVar13[1];
            uVar3 = puVar13[2];
            uVar4 = puVar13[3];
            puVar1 = in_ECX + iVar5 * 8 + 4;
            *puVar1 = *puVar13;
            puVar1[1] = uVar2;
            puVar1[2] = uVar3;
            puVar1[3] = uVar4;
            iVar5 = uVar8 - 1;
          }
          while (iVar10 < iVar5) {
            iVar12 = iVar5 + -1 >> 1;
            puVar13 = in_ECX + iVar12 * 8;
            cVar7 = (*param_2)(puVar13,&local_28);
            if (cVar7 == '\0') break;
            uVar2 = puVar13[1];
            uVar3 = puVar13[2];
            uVar4 = puVar13[3];
            puVar1 = in_ECX + iVar5 * 8;
            *puVar1 = *puVar13;
            puVar1[1] = uVar2;
            puVar1[2] = uVar3;
            puVar1[3] = uVar4;
            uVar2 = puVar13[5];
            uVar3 = puVar13[6];
            uVar4 = puVar13[7];
            puVar1 = in_ECX + iVar5 * 8 + 4;
            *puVar1 = puVar13[4];
            puVar1[1] = uVar2;
            puVar1[2] = uVar3;
            puVar1[3] = uVar4;
            iVar5 = iVar12;
          }
          puVar13 = in_ECX + iVar5 * 8;
          *puVar13 = local_28;
          puVar13[1] = uStack_24;
          puVar13[2] = uStack_20;
          puVar13[3] = uStack_1c;
          puVar13 = in_ECX + iVar5 * 8 + 4;
          *puVar13 = local_18;
          puVar13[1] = uStack_14;
          puVar13[2] = uStack_10;
          puVar13[3] = uStack_c;
          puVar11 = puVar11 + -8;
        } while (0 < iVar10);
      }
      if (1 < (int)uVar8) {
        do {
          puVar11 = local_30 + -8;
          local_28 = *puVar11;
          uStack_24 = local_30[-7];
          uStack_20 = local_30[-6];
          uStack_1c = local_30[-5];
          local_18 = local_30[-4];
          uStack_14 = local_30[-3];
          uStack_10 = local_30[-2];
          uStack_c = local_30[-1];
          uVar2 = in_ECX[1];
          uVar3 = in_ECX[2];
          uVar4 = in_ECX[3];
          *puVar11 = *in_ECX;
          local_30[-7] = uVar2;
          local_30[-6] = uVar3;
          local_30[-5] = uVar4;
          uVar2 = in_ECX[5];
          uVar3 = in_ECX[6];
          uVar4 = in_ECX[7];
          local_30[-4] = in_ECX[4];
          local_30[-3] = uVar2;
          local_30[-2] = uVar3;
          local_30[-1] = uVar4;
          FUN_100088c0((int)puVar11 - (int)in_ECX >> 5,&local_28,param_2);
          local_30 = puVar11;
        } while (0x3f < (int)((int)puVar11 - (int)in_ECX & 0xffffffe0U));
        __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
        return;
      }
      goto LAB_100084e9;
    }
    FUN_10008610(local_30,param_2);
    param_1 = (param_1 >> 1) + (param_1 >> 2);
    if ((int)((int)local_44 - (int)in_ECX & 0xffffffe0U) <
        (int)((int)local_30 - (int)local_40 & 0xffffffe0U)) {
      FUN_100081e0(param_1,param_2);
      local_2c = local_40;
      in_ECX = local_40;
    }
    else {
      FUN_100081e0(param_1,param_2);
      local_30 = local_44;
    }
    uVar8 = (int)local_30 - (int)in_ECX;
  } while( true );
}

