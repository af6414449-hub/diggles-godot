
void FUN_1000adb0(undefined4 *param_1)

{
  void *_Src;
  void *_Dst;
  size_t _Size;
  int iVar1;
  undefined4 *in_ECX;
  
  __CheckForDebuggerJustMyCode(&DAT_14170b08);
  *in_ECX = 0;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  _Src = (void *)*param_1;
  if (_Src != (void *)param_1[1]) {
    _Size = (int)param_1[1] - (int)_Src;
    iVar1 = (int)_Size >> 2;
    FUN_1000af30(iVar1 * -0x49249249);
    _Dst = (void *)*in_ECX;
    memmove(_Dst,_Src,_Size);
    in_ECX[1] = (void *)((int)_Dst + iVar1 * 4);
  }
  return;
}

