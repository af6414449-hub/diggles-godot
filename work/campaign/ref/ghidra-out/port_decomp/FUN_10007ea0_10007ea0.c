
undefined4 * FUN_10007ea0(void *param_1,undefined4 *param_2)

{
  uint uVar1;
  int iVar2;
  void *_Src;
  code *pcVar3;
  int iVar4;
  undefined4 *puVar5;
  int *in_ECX;
  uint uVar6;
  uint uVar7;
  void *_Dst;
  
  __CheckForDebuggerJustMyCode(&DAT_14170b08);
  iVar2 = *in_ECX;
  iVar4 = in_ECX[1] - iVar2 >> 2;
  if (iVar4 == 0x3fffffff) goto LAB_10007ffe;
  uVar1 = iVar4 + 1;
  uVar6 = in_ECX[2] - iVar2 >> 2;
  if (uVar6 <= 0x3fffffff - (uVar6 >> 1)) {
    uVar6 = (uVar6 >> 1) + uVar6;
    uVar7 = uVar1;
    if (uVar1 <= uVar6) {
      uVar7 = uVar6;
    }
    if (uVar7 < 0x40000000) {
      uVar7 = uVar7 * 4;
      if (uVar7 < 0x1000) {
        if (uVar7 == 0) {
          _Dst = (void *)0x0;
        }
        else {
          _Dst = (void *)FUN_1003ff62(uVar7);
        }
      }
      else {
        if (uVar7 + 0x23 <= uVar7) goto LAB_10007ff9;
        iVar4 = FUN_1003ff62(uVar7 + 0x23);
        if (iVar4 == 0) goto LAB_10007ff3;
        _Dst = (void *)(iVar4 + 0x23U & 0xffffffe0);
        *(int *)((int)_Dst - 4) = iVar4;
      }
      puVar5 = (undefined4 *)((int)_Dst + ((int)param_1 - iVar2 >> 2) * 4);
      *puVar5 = *param_2;
      _Src = (void *)*in_ECX;
      if (param_1 == (void *)in_ECX[1]) {
        memmove(_Dst,_Src,in_ECX[1] - (int)_Src);
      }
      else {
        memmove(_Dst,_Src,(int)param_1 - (int)_Src);
        memmove(puVar5 + 1,param_1,in_ECX[1] - (int)param_1);
      }
      iVar2 = *in_ECX;
      if (iVar2 != 0) {
        uVar6 = in_ECX[2] - iVar2 & 0xfffffffc;
        iVar4 = iVar2;
        if (0xfff < uVar6) {
          iVar4 = *(int *)(iVar2 + -4);
          uVar6 = uVar6 + 0x23;
          if (0x1f < (iVar2 - iVar4) - 4U) {
LAB_10007ff3:
                    /* WARNING: Subroutine does not return */
            _invalid_parameter_noinfo_noreturn();
          }
        }
        FUN_100402ac(iVar4,uVar6);
      }
      *in_ECX = (int)_Dst;
      in_ECX[1] = (int)((int)_Dst + uVar1 * 4);
      in_ECX[2] = (int)(uVar7 + (int)_Dst);
      return puVar5;
    }
  }
LAB_10007ff9:
  FUN_10002a00();
LAB_10007ffe:
  FUN_10008180();
  pcVar3 = (code *)swi(3);
  puVar5 = (undefined4 *)(*pcVar3)();
  return puVar5;
}

