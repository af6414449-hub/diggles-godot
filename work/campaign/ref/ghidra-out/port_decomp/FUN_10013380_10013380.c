
undefined4 * FUN_10013380(void *param_1,undefined4 *param_2)

{
  int iVar1;
  void *_Src;
  code *pcVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  void *_Dst;
  undefined4 *puVar6;
  int *in_ECX;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  
  __CheckForDebuggerJustMyCode(&DAT_14170b08);
  iVar1 = *in_ECX;
  iVar9 = in_ECX[1] - iVar1 >> 4;
  if (iVar9 == 0xfffffff) {
    FUN_10008180();
    pcVar2 = (code *)swi(3);
    puVar6 = (undefined4 *)(*pcVar2)();
    return puVar6;
  }
  uVar10 = iVar9 + 1;
  uVar7 = in_ECX[2] - iVar1 >> 4;
  if (0xfffffff - (uVar7 >> 1) < uVar7) {
    uVar7 = 0xfffffff;
  }
  else {
    uVar7 = (uVar7 >> 1) + uVar7;
    if (uVar7 < uVar10) {
      uVar7 = uVar10;
    }
  }
  _Dst = (void *)FUN_10007c20(uVar7);
  puVar6 = (undefined4 *)(((int)param_1 - iVar1 >> 4) * 0x10 + (int)_Dst);
  uVar3 = param_2[1];
  uVar4 = param_2[2];
  uVar5 = param_2[3];
  *puVar6 = *param_2;
  puVar6[1] = uVar3;
  puVar6[2] = uVar4;
  puVar6[3] = uVar5;
  _Src = (void *)*in_ECX;
  if (param_1 == (void *)in_ECX[1]) {
    memmove(_Dst,_Src,in_ECX[1] - (int)_Src);
  }
  else {
    memmove(_Dst,_Src,(int)param_1 - (int)_Src);
    memmove(puVar6 + 4,param_1,in_ECX[1] - (int)param_1);
  }
  iVar1 = *in_ECX;
  if (iVar1 != 0) {
    uVar8 = in_ECX[2] - iVar1 & 0xfffffff0;
    iVar9 = iVar1;
    if (0xfff < uVar8) {
      iVar9 = *(int *)(iVar1 + -4);
      uVar8 = uVar8 + 0x23;
      if (0x1f < (iVar1 - iVar9) - 4U) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
    }
    FUN_100402ac(iVar9,uVar8);
  }
  *in_ECX = (int)_Dst;
  in_ECX[1] = (int)(uVar10 * 0x10 + (int)_Dst);
  in_ECX[2] = (int)(uVar7 * 0x10 + (int)_Dst);
  return puVar6;
}

