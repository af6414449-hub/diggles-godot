
/* WARNING: Removing unreachable block (ram,0x100236c4) */
/* WARNING: Removing unreachable block (ram,0x10023694) */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_10023220(int param_1,int param_2)

{
  float *pfVar1;
  float *pfVar2;
  float *pfVar3;
  float *pfVar4;
  float *pfVar5;
  int *piVar6;
  int iVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  uint uVar15;
  float *pfVar16;
  int in_ECX;
  float *pfVar17;
  float *in_EDX;
  int iVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  float fVar30;
  float fVar31;
  float fVar32;
  float fVar33;
  float fVar34;
  float fVar35;
  float fVar36;
  float fVar37;
  float fVar38;
  float fVar39;
  int local_74;
  float *local_70;
  float *local_6c;
  float local_5c [7];
  float local_40;
  float local_3c;
  float local_38 [7];
  float local_1c;
  float local_18;
  uint local_14;
  
  local_14 = DAT_1005000c ^ (uint)&stack0xfffffff0;
  __CheckForDebuggerJustMyCode(&DAT_14170cf0);
  if (0 < param_2) {
    local_6c = (float *)(in_ECX + 4);
    local_74 = -(int)in_EDX;
    local_70 = in_EDX;
    do {
      pfVar17 = local_6c + 0xd;
      fVar24 = *local_6c - local_6c[1];
      fVar20 = local_6c[1] + *local_6c;
      fVar21 = local_6c[3] - local_6c[2];
      fVar33 = -(local_6c[3] + local_6c[2]);
      fVar22 = local_6c[7] - local_6c[6];
      fVar32 = -(local_6c[6] + local_6c[7]);
      fVar25 = local_6c[8] - local_6c[9];
      fVar23 = local_6c[9] + local_6c[8];
      fVar29 = local_6c[0xc] - *pfVar17;
      fVar19 = (fVar33 + fVar32) * 0.9396926;
      fVar26 = *pfVar17 + local_6c[0xc];
      fVar27 = local_6c[0xf] - local_6c[0xe];
      fVar30 = -(local_6c[0xe] + local_6c[0xf]);
      fVar31 = -(local_6c[10] + local_6c[0xb]) * 0.5 + -local_6c[-1];
      fVar28 = (fVar32 - fVar30) * 0.17364818;
      fVar34 = -local_6c[-1] - -(local_6c[10] + local_6c[0xb]);
      fVar32 = (fVar30 - fVar33) + fVar32;
      fVar33 = (fVar30 + fVar33) * 0.76604444;
      fVar35 = fVar34 - fVar32 * 0.5;
      local_38[4] = fVar32 + fVar34;
      fVar34 = (fVar31 - fVar33) + fVar28;
      fVar33 = (fVar31 - fVar19) + fVar33;
      fVar28 = (fVar19 + fVar31) - fVar28;
      fVar19 = (local_6c[5] + local_6c[4]) * 0.8660254;
      fVar32 = (fVar23 - fVar26) * 0.34202015;
      fVar31 = (fVar20 + fVar23) * 0.9848077;
      fVar30 = (fVar26 + fVar20) * 0.64278764;
      fVar23 = ((fVar20 - fVar23) - fVar26) * 0.8660254;
      fVar20 = (fVar31 - fVar19) - fVar30;
      fVar31 = (fVar32 - fVar19) - fVar31;
      fVar30 = (fVar19 + fVar32) - fVar30;
      local_38[0] = fVar28 - fVar31;
      local_18 = fVar31 + fVar28;
      local_38[1] = fVar23 + fVar35;
      local_1c = fVar35 - fVar23;
      local_38[2] = fVar33 - fVar30;
      local_38[6] = fVar30 + fVar33;
      local_38[3] = fVar20 + fVar34;
      local_38[5] = fVar34 - fVar20;
      fVar28 = (local_6c[4] - local_6c[5]) * 0.5 + local_6c[0x10];
      fVar26 = local_6c[0x10] - (local_6c[4] - local_6c[5]);
      fVar20 = (fVar25 - fVar24) * 0.17364818;
      fVar30 = (fVar29 + fVar25) * 0.9396926;
      fVar25 = (fVar24 - fVar29) + fVar25;
      fVar19 = (fVar24 + fVar29) * 0.76604444;
      fVar24 = (fVar28 - fVar30) + fVar19;
      fVar32 = (fVar30 + fVar28) - fVar20;
      local_5c[4] = fVar25 + fVar26;
      fVar26 = fVar26 - fVar25 * 0.5;
      fVar20 = (fVar28 - fVar19) + fVar20;
      iVar18 = 0;
      fVar19 = (local_6c[0xb] - local_6c[10]) * 0.8660254;
      fVar33 = (fVar27 + fVar22) * 0.9848077;
      fVar23 = (fVar22 - fVar21) * 0.34202015;
      fVar28 = (fVar21 + fVar27) * 0.64278764;
      fVar22 = ((fVar27 - fVar22) - fVar21) * 0.8660254;
      fVar30 = (fVar23 - fVar19) - fVar33;
      fVar21 = (fVar19 + fVar23) - fVar28;
      fVar28 = (fVar33 - fVar19) - fVar28;
      local_5c[0] = fVar32 - fVar30;
      local_3c = fVar30 + fVar32;
      local_5c[2] = fVar24 - fVar21;
      local_5c[6] = fVar21 + fVar24;
      local_5c[1] = -(fVar22 + fVar26);
      local_40 = -(fVar26 - fVar22);
      local_5c[3] = -(fVar28 + fVar20);
      local_5c[5] = -(fVar20 - fVar28);
      if ((DAT_1416f070 == 0) && (piVar6 = (int *)cpuid_basic_info(0), 0 < *piVar6)) {
        iVar7 = cpuid_Version_info(1);
        uVar15 = *(uint *)(iVar7 + 8) & 0x4000000;
        DAT_1416f070 = uVar15 + 1;
      }
      else {
        uVar15 = DAT_1416f070 - 1;
      }
      if (uVar15 == 0) {
LAB_100237de:
        pfVar17 = local_6c + (0x10 - iVar18);
        pfVar16 = (float *)(param_1 + 0x24 + iVar18 * 4);
        iVar18 = iVar18 * 4;
        do {
          fVar19 = *(float *)(((int)&DAT_10047660 - param_1) + (int)pfVar16);
          fVar28 = *(float *)(iVar18 + (int)local_70);
          fVar30 = *(float *)((int)local_5c + iVar18) * *(float *)((int)&DAT_10047660 + iVar18) +
                   fVar19 * *(float *)((int)local_38 + iVar18);
          *(float *)(iVar18 + (int)local_70) =
               *(float *)((int)&DAT_10047660 + iVar18) * *(float *)((int)local_38 + iVar18) -
               fVar19 * *(float *)((int)local_5c + iVar18);
          *(float *)(iVar18 + -4 + (int)local_6c) = pfVar16[-9] * fVar28 - *pfVar16 * fVar30;
          iVar18 = iVar18 + 4;
          pfVar1 = pfVar16 + -9;
          fVar19 = *pfVar16;
          pfVar16 = pfVar16 + 1;
          *pfVar17 = *pfVar1 * fVar30 + fVar19 * fVar28;
          pfVar17 = pfVar17 + -1;
        } while (iVar18 < 0x24);
      }
      else {
        pfVar16 = local_70;
        do {
          fVar11 = *pfVar16;
          fVar12 = pfVar16[1];
          fVar13 = pfVar16[2];
          fVar14 = pfVar16[3];
          pfVar1 = (float *)((int)local_38 + local_74 + (int)pfVar16);
          fVar19 = pfVar1[1];
          fVar28 = pfVar1[2];
          fVar30 = pfVar1[3];
          pfVar2 = (float *)((int)local_5c + local_74 + (int)pfVar16);
          fVar20 = pfVar2[1];
          fVar21 = pfVar2[2];
          fVar22 = pfVar2[3];
          pfVar4 = (float *)((int)&DAT_10047660 + local_74 + (int)pfVar16);
          fVar23 = pfVar4[1];
          fVar33 = pfVar4[2];
          fVar32 = pfVar4[3];
          pfVar5 = (float *)(&DAT_10047684 + local_74 + (int)pfVar16);
          fVar24 = pfVar5[1];
          fVar25 = pfVar5[2];
          fVar26 = pfVar5[3];
          pfVar3 = (float *)(param_1 + local_74 + (int)pfVar16);
          fVar27 = *pfVar3;
          fVar31 = pfVar3[1];
          fVar29 = pfVar3[2];
          fVar34 = pfVar3[3];
          pfVar3 = (float *)(param_1 + 0x24 + iVar18 * 4);
          fVar35 = *pfVar3;
          fVar8 = pfVar3[1];
          fVar9 = pfVar3[2];
          fVar10 = pfVar3[3];
          iVar18 = iVar18 + 4;
          fVar36 = *pfVar4 * *pfVar2 + *pfVar5 * *pfVar1;
          fVar37 = fVar23 * fVar20 + fVar24 * fVar19;
          fVar38 = fVar33 * fVar21 + fVar25 * fVar28;
          fVar39 = fVar32 * fVar22 + fVar26 * fVar30;
          *pfVar16 = *pfVar4 * *pfVar1 - *pfVar5 * *pfVar2;
          pfVar16[1] = fVar23 * fVar19 - fVar24 * fVar20;
          pfVar16[2] = fVar33 * fVar28 - fVar25 * fVar21;
          pfVar16[3] = fVar32 * fVar30 - fVar26 * fVar22;
          pfVar1 = (float *)((int)pfVar16 + (int)local_6c + (-4 - (int)local_70));
          *pfVar1 = fVar27 * fVar11 - fVar36 * fVar35;
          pfVar1[1] = fVar31 * fVar12 - fVar37 * fVar8;
          pfVar1[2] = fVar29 * fVar13 - fVar38 * fVar9;
          pfVar1[3] = fVar34 * fVar14 - fVar39 * fVar10;
          pfVar16 = pfVar16 + 4;
          *pfVar17 = fVar39 * fVar34 + fVar10 * fVar14;
          pfVar17[1] = fVar38 * fVar29 + fVar9 * fVar13;
          pfVar17[2] = fVar37 * fVar31 + fVar8 * fVar12;
          pfVar17[3] = fVar36 * fVar27 + fVar35 * fVar11;
          pfVar17 = pfVar17 + -4;
        } while (iVar18 < 8);
        if (iVar18 < 9) goto LAB_100237de;
      }
      local_70 = local_70 + 9;
      local_6c = local_6c + 0x12;
      local_74 = local_74 + -0x24;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffff0);
  return;
}

