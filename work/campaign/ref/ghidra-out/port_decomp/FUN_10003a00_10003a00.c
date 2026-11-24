
void FUN_10003a00(void *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  code *pcVar4;
  void *_Dst;
  int iVar5;
  int *in_ECX;
  int *_Dst_00;
  uint uVar6;
  
  __CheckForDebuggerJustMyCode(&DAT_14170b7b);
  uVar2 = in_ECX[5];
  if (param_2 <= uVar2) {
    _Dst_00 = in_ECX;
    if (0xf < uVar2) {
      _Dst_00 = (int *)*in_ECX;
    }
    in_ECX[4] = param_2;
    memmove(_Dst_00,param_1,param_2);
    *(undefined1 *)(param_2 + (int)_Dst_00) = 0;
    return;
  }
  if (0x7fffffff < param_2) {
    FUN_10002ab0();
    pcVar4 = (code *)swi(3);
    (*pcVar4)();
    return;
  }
  uVar6 = param_2 | 0xf;
  if (uVar6 < 0x80000000) {
    if (0x7fffffff - (uVar2 >> 1) < uVar2) {
      uVar6 = 0x7fffffff;
    }
    else {
      uVar1 = (uVar2 >> 1) + uVar2;
      if (uVar6 < uVar1) {
        uVar6 = uVar1;
      }
    }
  }
  else {
    uVar6 = 0x7fffffff;
  }
  _Dst = (void *)FUN_10003e80(uVar6 + 1);
  in_ECX[5] = uVar6;
  in_ECX[4] = param_2;
  memcpy(_Dst,param_1,param_2);
  *(undefined1 *)(param_2 + (int)_Dst) = 0;
  if (0xf < uVar2) {
    uVar6 = uVar2 + 1;
    iVar3 = *in_ECX;
    iVar5 = iVar3;
    if (0xfff < uVar6) {
      iVar5 = *(int *)(iVar3 + -4);
      uVar6 = uVar2 + 0x24;
      if (0x1f < (iVar3 - iVar5) - 4U) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
    }
    FUN_100402ac(iVar5,uVar6);
  }
  *in_ECX = (int)_Dst;
  return;
}

