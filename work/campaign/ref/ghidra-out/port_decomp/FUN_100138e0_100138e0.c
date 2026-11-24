
void FUN_100138e0(undefined4 param_1,uint param_2)

{
  uint uVar1;
  size_t _Size;
  void *_Src;
  code *pcVar2;
  uint uVar3;
  void *_Dst;
  undefined4 *in_ECX;
  undefined1 *puVar4;
  uint uVar5;
  void *pvVar6;
  undefined4 *local_8;
  
  __CheckForDebuggerJustMyCode(&DAT_14170b7b);
  uVar1 = in_ECX[5];
  _Size = in_ECX[4];
  if (param_2 <= uVar1 - _Size) {
    in_ECX[4] = param_2 + _Size;
    local_8 = in_ECX;
    if (0xf < uVar1) {
      local_8 = (undefined4 *)*in_ECX;
    }
    memmove((void *)((int)local_8 + _Size),&DAT_1004529c,param_2);
    *(undefined1 *)((int)local_8 + _Size + param_2) = 0;
    return;
  }
  if (0x7fffffff - _Size < param_2) {
    FUN_10002ab0();
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  uVar5 = param_2 + _Size | 0xf;
  if (uVar5 < 0x80000000) {
    if (0x7fffffff - (uVar1 >> 1) < uVar1) {
      uVar5 = 0x7fffffff;
    }
    else {
      uVar3 = (uVar1 >> 1) + uVar1;
      if (uVar5 < uVar3) {
        uVar5 = uVar3;
      }
    }
  }
  else {
    uVar5 = 0x7fffffff;
  }
  _Dst = (void *)FUN_10003e80(-(uint)(0xfffffffe < uVar5) | uVar5 + 1);
  in_ECX[4] = param_2 + _Size;
  in_ECX[5] = uVar5;
  puVar4 = (undefined1 *)((int)_Dst + _Size + param_2);
  if (uVar1 < 0x10) {
    memcpy(_Dst,in_ECX,_Size);
    memcpy((void *)((int)_Dst + _Size),&DAT_1004529c,param_2);
    *puVar4 = 0;
    *in_ECX = _Dst;
    return;
  }
  _Src = (void *)*in_ECX;
  memcpy(_Dst,_Src,_Size);
  memcpy((void *)((int)_Dst + _Size),&DAT_1004529c,param_2);
  uVar5 = uVar1 + 1;
  *puVar4 = 0;
  pvVar6 = _Src;
  if (0xfff < uVar5) {
    pvVar6 = *(void **)((int)_Src + -4);
    uVar5 = uVar1 + 0x24;
    if (0x1f < (uint)((int)_Src + (-4 - (int)pvVar6))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
  }
  FUN_100402ac(pvVar6,uVar5);
  *in_ECX = _Dst;
  return;
}

