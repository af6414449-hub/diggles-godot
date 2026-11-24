
void FUN_1000ae30(void *param_1,int param_2)

{
  void *_Dst;
  code *pcVar1;
  int iVar2;
  undefined4 *in_ECX;
  uint uVar3;
  
  __CheckForDebuggerJustMyCode(&DAT_14170b08);
  iVar2 = param_2 - (int)param_1 >> 2;
  uVar3 = iVar2 * -0x49249249;
  *in_ECX = 0;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  if (uVar3 != 0) {
    if (0x9249249 < uVar3) {
      FUN_10008180();
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    FUN_1000af30(uVar3);
    _Dst = (void *)*in_ECX;
    memmove(_Dst,param_1,param_2 - (int)param_1);
    in_ECX[1] = (void *)((int)_Dst + iVar2 * 4);
  }
  return;
}

