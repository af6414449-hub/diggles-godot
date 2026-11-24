
void FUN_1002d960(undefined1 *param_1)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  uint *in_EDX;
  uint uVar4;
  int local_18;
  uint local_14;
  uint local_10;
  undefined2 local_c;
  undefined1 local_a;
  uint local_8;
  
  local_8 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170ce2);
  local_10 = 0;
  local_c = 0;
  local_a = 0;
  iVar2 = FUN_1002d650(&local_10);
  if (iVar2 != 0) {
    if (-1 < (char)(byte)local_10) {
      *in_EDX = local_10 & 0xff;
      in_EDX[1] = 0;
      *param_1 = 0;
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    if (((byte)local_10 & 0xe0) == 0xc0) {
      iVar2 = 2;
    }
    else if (((byte)local_10 & 0xf0) == 0xe0) {
      iVar2 = 3;
    }
    else if (((byte)local_10 & 0xf8) == 0xf0) {
      iVar2 = 4;
    }
    else if (((byte)local_10 & 0xfc) == 0xf8) {
      iVar2 = 5;
    }
    else if (((byte)local_10 & 0xfe) == 0xfc) {
      iVar2 = 6;
    }
    else {
      if ((byte)local_10 != 0xfe) goto LAB_1002dabb;
      iVar2 = 7;
    }
    local_14 = 0;
    uVar4 = 0xff >> (char)iVar2 + 1 & local_10 & 0xff;
    local_18 = 1;
    while (iVar3 = FUN_1002d650((int)&local_10 + local_18), iVar3 != 0) {
      local_14 = local_14 << 6 | uVar4 >> 0x1a;
      pbVar1 = (byte *)((int)&local_10 + local_18);
      local_18 = local_18 + 1;
      uVar4 = uVar4 << 6 | (uint)(*pbVar1 & 0x3f);
      if (iVar2 <= local_18) {
        in_EDX[1] = local_14;
        *in_EDX = uVar4;
        *param_1 = 0;
        __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
        return;
      }
    }
  }
LAB_1002dabb:
  in_EDX[1] = 0;
  *in_EDX = 0;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

