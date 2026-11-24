
undefined4 * FUN_10007d10(undefined4 *param_1,undefined4 *param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  code *pcVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  int iVar9;
  undefined4 *puVar10;
  int *in_ECX;
  undefined4 *puVar11;
  uint uVar12;
  undefined4 *puVar13;
  uint uVar14;
  
  __CheckForDebuggerJustMyCode(&DAT_14170b08);
  iVar2 = *in_ECX;
  iVar9 = in_ECX[1] - iVar2 >> 5;
  if (iVar9 == 0x7ffffff) goto LAB_10007e91;
  uVar1 = iVar9 + 1;
  uVar12 = in_ECX[2] - iVar2 >> 5;
  if (uVar12 <= 0x7ffffff - (uVar12 >> 1)) {
    uVar12 = (uVar12 >> 1) + uVar12;
    uVar14 = uVar1;
    if (uVar1 <= uVar12) {
      uVar14 = uVar12;
    }
    if (uVar14 < 0x8000000) {
      uVar12 = uVar14 * 0x20;
      if (uVar12 < 0x1000) {
        if (uVar12 == 0) {
          puVar13 = (undefined4 *)0x0;
        }
        else {
          puVar13 = (undefined4 *)FUN_1003ff62(uVar12);
        }
      }
      else {
        if (uVar12 + 0x23 <= uVar12) goto LAB_10007e8c;
        iVar9 = FUN_1003ff62(uVar12 + 0x23);
        if (iVar9 == 0) goto LAB_10007e86;
        puVar13 = (undefined4 *)(iVar9 + 0x23U & 0xffffffe0);
        puVar13[-1] = iVar9;
      }
      puVar11 = puVar13 + ((int)param_1 - iVar2 >> 5) * 8;
      uVar5 = param_2[1];
      uVar6 = param_2[2];
      uVar7 = param_2[3];
      *puVar11 = *param_2;
      puVar11[1] = uVar5;
      puVar11[2] = uVar6;
      puVar11[3] = uVar7;
      uVar5 = param_2[5];
      uVar6 = param_2[6];
      uVar7 = param_2[7];
      puVar11[4] = param_2[4];
      puVar11[5] = uVar5;
      puVar11[6] = uVar6;
      puVar11[7] = uVar7;
      puVar3 = (undefined4 *)in_ECX[1];
      puVar10 = (undefined4 *)*in_ECX;
      puVar8 = puVar13;
      if (param_1 == puVar3) {
        for (; puVar10 != puVar3; puVar10 = puVar10 + 8) {
          uVar5 = puVar10[1];
          uVar6 = puVar10[2];
          uVar7 = puVar10[3];
          *puVar8 = *puVar10;
          puVar8[1] = uVar5;
          puVar8[2] = uVar6;
          puVar8[3] = uVar7;
          uVar5 = puVar10[5];
          uVar6 = puVar10[6];
          uVar7 = puVar10[7];
          puVar8[4] = puVar10[4];
          puVar8[5] = uVar5;
          puVar8[6] = uVar6;
          puVar8[7] = uVar7;
          puVar8 = puVar8 + 8;
        }
      }
      else {
        FUN_100081a0(puVar10,param_1,puVar13);
        FUN_100081a0(param_1,in_ECX[1],puVar11 + 8);
      }
      iVar2 = *in_ECX;
      if (iVar2 != 0) {
        uVar12 = in_ECX[2] - iVar2 & 0xffffffe0;
        iVar9 = iVar2;
        if (0xfff < uVar12) {
          iVar9 = *(int *)(iVar2 + -4);
          uVar12 = uVar12 + 0x23;
          if (0x1f < (iVar2 - iVar9) - 4U) {
LAB_10007e86:
                    /* WARNING: Subroutine does not return */
            _invalid_parameter_noinfo_noreturn();
          }
        }
        FUN_100402ac(iVar9,uVar12);
      }
      *in_ECX = (int)puVar13;
      in_ECX[1] = (int)(puVar13 + uVar1 * 8);
      in_ECX[2] = (int)(puVar13 + uVar14 * 8);
      return puVar11;
    }
  }
LAB_10007e8c:
  FUN_10002a00();
LAB_10007e91:
  FUN_10008180();
  pcVar4 = (code *)swi(3);
  puVar13 = (undefined4 *)(*pcVar4)();
  return puVar13;
}

