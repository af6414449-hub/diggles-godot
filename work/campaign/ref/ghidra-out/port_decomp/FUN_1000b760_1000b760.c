
void FUN_1000b760(undefined4 *param_1)

{
  uint uVar1;
  char *pcVar2;
  size_t _Size;
  code *pcVar3;
  undefined8 *in_ECX;
  uint uVar4;
  undefined8 *local_c;
  
  __CheckForDebuggerJustMyCode(&DAT_14170b7b);
  _Size = param_1[4];
  if (0xc < 0x7fffffff - _Size) {
    if (0xf < (uint)param_1[5]) {
      param_1 = (undefined4 *)*param_1;
    }
    uVar1 = _Size + 0xd;
    *(undefined4 *)(in_ECX + 2) = 0;
    uVar4 = 0xf;
    *(undefined4 *)((int)in_ECX + 0x14) = 0;
    local_c = in_ECX;
    if (0xf < uVar1) {
      uVar4 = uVar1 | 0xf;
      if (uVar4 < 0x80000000) {
        if (uVar4 < 0x16) {
          uVar4 = 0x16;
        }
      }
      else {
        uVar4 = 0x7fffffff;
      }
      local_c = (undefined8 *)FUN_10003e80(-(uint)(0xfffffffe < uVar4) | uVar4 + 1);
      *(undefined8 **)in_ECX = local_c;
    }
    *(uint *)((int)in_ECX + 0x14) = uVar4;
    *(uint *)(in_ECX + 2) = uVar1;
    *local_c = 0x6168535c61746164;
    pcVar2 = (char *)(local_c + 1);
    pcVar2[0] = 'd';
    pcVar2[1] = 'e';
    pcVar2[2] = 'r';
    pcVar2[3] = 's';
    *(undefined1 *)((int)local_c + 0xc) = 0x5c;
    memcpy((void *)((int)local_c + 0xd),param_1,_Size);
    *(undefined1 *)((int)local_c + _Size + 0xd) = 0;
    return;
  }
  FUN_10002ab0();
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}

