
void FUN_10008610(undefined4 *param_1,code *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  char cVar12;
  int iVar13;
  undefined4 *puVar14;
  undefined4 *in_ECX;
  undefined4 *in_EDX;
  undefined4 *puVar15;
  undefined4 *puVar16;
  undefined4 *puVar17;
  undefined4 *puVar18;
  undefined4 *puVar19;
  undefined4 *puVar20;
  undefined4 *puVar21;
  undefined4 *local_14;
  undefined4 *local_10;
  undefined4 *local_8;
  
  __CheckForDebuggerJustMyCode(&DAT_14170b7c);
  puVar18 = param_1 + -8;
  puVar16 = in_EDX + ((int)param_1 - (int)in_EDX >> 6) * 8;
  iVar13 = (int)puVar18 - (int)in_EDX >> 5;
  puVar15 = puVar18;
  if (0x28 < iVar13) {
    iVar13 = iVar13 + 1 >> 3;
    FUN_100089c0(in_EDX + iVar13 * 0x10,param_2);
    FUN_100089c0(puVar16 + iVar13 * 8,param_2);
    puVar15 = puVar18 + iVar13 * -8;
    FUN_100089c0(puVar18,param_2);
  }
  FUN_100089c0(puVar15,param_2);
  puVar18 = puVar16;
  while (puVar15 = puVar18, in_EDX < puVar15) {
    puVar18 = puVar15 + -8;
    cVar12 = (*param_2)(puVar18,puVar15);
    if ((cVar12 != '\0') || (cVar12 = (*param_2)(puVar15,puVar18), cVar12 != '\0')) break;
  }
  do {
    puVar16 = puVar16 + 8;
    puVar18 = puVar16;
    local_14 = puVar16;
    local_8 = puVar16;
    local_10 = puVar15;
    puVar17 = puVar15;
    if (param_1 <= puVar16) break;
    cVar12 = (*param_2)(puVar16,puVar15);
    if ((cVar12 != '\0') || (cVar12 = (*param_2)(puVar15,puVar16), cVar12 != '\0')) break;
  } while( true );
joined_r0x10008724:
  puVar19 = local_10;
  if (param_1 <= puVar18) {
joined_r0x10008777:
    while (puVar14 = puVar15, puVar21 = puVar18, in_EDX < puVar15) {
      puVar20 = puVar19 + -8;
      cVar12 = (*param_2)(puVar20,puVar17);
      puVar18 = puVar17;
      puVar16 = local_8;
      if (cVar12 == '\0') {
        cVar12 = (*param_2)(puVar17,puVar20);
        puVar14 = local_10;
        puVar21 = local_14;
        if (cVar12 != '\0') break;
        puVar18 = puVar17 + -8;
        if (puVar18 != puVar20) {
          uVar1 = puVar19[-7];
          uVar2 = puVar19[-6];
          uVar3 = puVar19[-5];
          uVar4 = *puVar18;
          uVar5 = puVar17[-7];
          uVar6 = puVar17[-6];
          uVar7 = puVar17[-5];
          uVar8 = puVar17[-4];
          uVar9 = puVar17[-3];
          uVar10 = puVar17[-2];
          uVar11 = puVar17[-1];
          *puVar18 = *puVar20;
          puVar17[-7] = uVar1;
          puVar17[-6] = uVar2;
          puVar17[-5] = uVar3;
          uVar1 = puVar19[-3];
          uVar2 = puVar19[-2];
          uVar3 = puVar19[-1];
          puVar17[-4] = puVar19[-4];
          puVar17[-3] = uVar1;
          puVar17[-2] = uVar2;
          puVar17[-1] = uVar3;
          *puVar20 = uVar4;
          puVar19[-7] = uVar5;
          puVar19[-6] = uVar6;
          puVar19[-5] = uVar7;
          puVar19[-4] = uVar8;
          puVar19[-3] = uVar9;
          puVar19[-2] = uVar10;
          puVar19[-1] = uVar11;
        }
      }
      local_10 = local_10 + -8;
      puVar17 = puVar18;
      puVar18 = local_14;
      puVar19 = puVar20;
      puVar15 = local_10;
    }
    if (puVar14 == in_EDX) {
      if (puVar21 == param_1) {
        *in_ECX = puVar17;
        in_ECX[1] = puVar16;
        return;
      }
      if (puVar16 != puVar21) {
        uVar1 = puVar16[1];
        uVar2 = puVar16[2];
        uVar3 = puVar16[3];
        uVar4 = *puVar17;
        uVar5 = puVar17[1];
        uVar6 = puVar17[2];
        uVar7 = puVar17[3];
        uVar8 = puVar17[4];
        uVar9 = puVar17[5];
        uVar10 = puVar17[6];
        uVar11 = puVar17[7];
        *puVar17 = *puVar16;
        puVar17[1] = uVar1;
        puVar17[2] = uVar2;
        puVar17[3] = uVar3;
        uVar1 = puVar16[5];
        uVar2 = puVar16[6];
        uVar3 = puVar16[7];
        puVar17[4] = puVar16[4];
        puVar17[5] = uVar1;
        puVar17[6] = uVar2;
        puVar17[7] = uVar3;
        *puVar16 = uVar4;
        puVar16[1] = uVar5;
        puVar16[2] = uVar6;
        puVar16[3] = uVar7;
        puVar16[4] = uVar8;
        puVar16[5] = uVar9;
        puVar16[6] = uVar10;
        puVar16[7] = uVar11;
      }
      uVar1 = puVar21[1];
      uVar2 = puVar21[2];
      uVar3 = puVar21[3];
      puVar16 = puVar16 + 8;
      uVar4 = *puVar17;
      uVar5 = puVar17[1];
      uVar6 = puVar17[2];
      uVar7 = puVar17[3];
      uVar8 = puVar17[4];
      uVar9 = puVar17[5];
      uVar10 = puVar17[6];
      uVar11 = puVar17[7];
      *puVar17 = *puVar21;
      puVar17[1] = uVar1;
      puVar17[2] = uVar2;
      puVar17[3] = uVar3;
      uVar1 = puVar21[5];
      uVar2 = puVar21[6];
      uVar3 = puVar21[7];
      puVar17[4] = puVar21[4];
      puVar17[5] = uVar1;
      puVar17[6] = uVar2;
      puVar17[7] = uVar3;
      *puVar21 = uVar4;
      puVar21[1] = uVar5;
      puVar21[2] = uVar6;
      puVar21[3] = uVar7;
      puVar21[4] = uVar8;
      puVar21[5] = uVar9;
      puVar21[6] = uVar10;
      puVar21[7] = uVar11;
      puVar15 = puVar14;
      puVar18 = puVar21 + 8;
      local_14 = puVar21 + 8;
      local_8 = puVar16;
      puVar17 = puVar17 + 8;
    }
    else {
      puVar15 = puVar14 + -8;
      local_10 = puVar15;
      if (puVar21 == param_1) {
        puVar19 = puVar17 + -8;
        if (puVar15 != puVar19) {
          uVar1 = puVar17[-7];
          uVar2 = puVar17[-6];
          uVar3 = puVar17[-5];
          uVar4 = *puVar15;
          uVar5 = puVar14[-7];
          uVar6 = puVar14[-6];
          uVar7 = puVar14[-5];
          uVar8 = puVar14[-4];
          uVar9 = puVar14[-3];
          uVar10 = puVar14[-2];
          uVar11 = puVar14[-1];
          *puVar15 = *puVar19;
          puVar14[-7] = uVar1;
          puVar14[-6] = uVar2;
          puVar14[-5] = uVar3;
          uVar1 = puVar17[-3];
          uVar2 = puVar17[-2];
          uVar3 = puVar17[-1];
          puVar14[-4] = puVar17[-4];
          puVar14[-3] = uVar1;
          puVar14[-2] = uVar2;
          puVar14[-1] = uVar3;
          *puVar19 = uVar4;
          puVar17[-7] = uVar5;
          puVar17[-6] = uVar6;
          puVar17[-5] = uVar7;
          puVar17[-4] = uVar8;
          puVar17[-3] = uVar9;
          puVar17[-2] = uVar10;
          puVar17[-1] = uVar11;
        }
        uVar1 = puVar16[-7];
        uVar2 = puVar16[-6];
        uVar3 = puVar16[-5];
        local_8 = puVar16 + -8;
        uVar4 = *puVar19;
        uVar5 = puVar17[-7];
        uVar6 = puVar17[-6];
        uVar7 = puVar17[-5];
        uVar8 = puVar17[-4];
        uVar9 = puVar17[-3];
        uVar10 = puVar17[-2];
        uVar11 = puVar17[-1];
        *puVar19 = puVar16[-8];
        puVar17[-7] = uVar1;
        puVar17[-6] = uVar2;
        puVar17[-5] = uVar3;
        uVar1 = puVar16[-3];
        uVar2 = puVar16[-2];
        uVar3 = puVar16[-1];
        puVar17[-4] = puVar16[-4];
        puVar17[-3] = uVar1;
        puVar17[-2] = uVar2;
        puVar17[-1] = uVar3;
        *local_8 = uVar4;
        puVar16[-7] = uVar5;
        puVar16[-6] = uVar6;
        puVar16[-5] = uVar7;
        puVar16[-4] = uVar8;
        puVar16[-3] = uVar9;
        puVar16[-2] = uVar10;
        puVar16[-1] = uVar11;
        puVar16 = local_8;
        puVar18 = puVar21;
        puVar17 = puVar19;
      }
      else {
        uVar1 = puVar14[-7];
        uVar2 = puVar14[-6];
        uVar3 = puVar14[-5];
        uVar4 = *puVar21;
        uVar5 = puVar21[1];
        uVar6 = puVar21[2];
        uVar7 = puVar21[3];
        uVar8 = puVar21[4];
        uVar9 = puVar21[5];
        uVar10 = puVar21[6];
        uVar11 = puVar21[7];
        *puVar21 = *puVar15;
        puVar21[1] = uVar1;
        puVar21[2] = uVar2;
        puVar21[3] = uVar3;
        uVar1 = puVar14[-3];
        uVar2 = puVar14[-2];
        uVar3 = puVar14[-1];
        puVar21[4] = puVar14[-4];
        puVar21[5] = uVar1;
        puVar21[6] = uVar2;
        puVar21[7] = uVar3;
        *puVar15 = uVar4;
        puVar14[-7] = uVar5;
        puVar14[-6] = uVar6;
        puVar14[-5] = uVar7;
        puVar14[-4] = uVar8;
        puVar14[-3] = uVar9;
        puVar14[-2] = uVar10;
        puVar14[-1] = uVar11;
        puVar18 = puVar21 + 8;
        local_14 = puVar21 + 8;
      }
    }
    goto joined_r0x10008724;
  }
  cVar12 = (*param_2)(puVar17,puVar18);
  puVar15 = local_10;
  if (cVar12 == '\0') {
    cVar12 = (*param_2)(puVar18,puVar17);
    local_8 = puVar16;
    local_14 = puVar18;
    if (cVar12 != '\0') goto joined_r0x10008777;
    if (puVar16 != puVar18) {
      uVar1 = puVar18[1];
      uVar2 = puVar18[2];
      uVar3 = puVar18[3];
      uVar4 = *puVar16;
      uVar5 = puVar16[1];
      uVar6 = puVar16[2];
      uVar7 = puVar16[3];
      uVar8 = puVar16[4];
      uVar9 = puVar16[5];
      uVar10 = puVar16[6];
      uVar11 = puVar16[7];
      *puVar16 = *puVar18;
      puVar16[1] = uVar1;
      puVar16[2] = uVar2;
      puVar16[3] = uVar3;
      uVar1 = puVar18[5];
      uVar2 = puVar18[6];
      uVar3 = puVar18[7];
      puVar16[4] = puVar18[4];
      puVar16[5] = uVar1;
      puVar16[6] = uVar2;
      puVar16[7] = uVar3;
      *puVar18 = uVar4;
      puVar18[1] = uVar5;
      puVar18[2] = uVar6;
      puVar18[3] = uVar7;
      puVar18[4] = uVar8;
      puVar18[5] = uVar9;
      puVar18[6] = uVar10;
      puVar18[7] = uVar11;
    }
    puVar16 = puVar16 + 8;
  }
  puVar18 = puVar18 + 8;
  local_14 = puVar18;
  local_8 = puVar16;
  goto joined_r0x10008724;
}

