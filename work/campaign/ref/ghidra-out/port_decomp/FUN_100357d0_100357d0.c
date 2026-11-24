
void FUN_100357d0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 int param_5)

{
  int iVar1;
  int in_ECX;
  undefined1 local_50 [2];
  undefined2 local_4e;
  undefined4 local_44;
  undefined1 local_40;
  undefined1 local_3f;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_1c;
  undefined4 local_18;
  undefined2 local_14;
  undefined1 local_12;
  uint local_10;
  uint local_c;
  
  local_c = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170ce2);
  *(undefined4 *)(in_ECX + 0xc) = 0;
  iVar1 = FUN_1001ec50(param_3,&local_10,4);
  if (iVar1 == 4) {
    if (((local_10 << 0x18 & 0x7f000000) == 0) &&
       ((local_10 >> 0x18 | (local_10 & 0xff0000) >> 8 | (local_10 & 0xff00) << 8) == 0x22)) {
      iVar1 = FUN_100353e0(local_50);
      if (iVar1 != 0) {
        *(undefined4 *)(in_ECX + 0x18) = local_44;
        *(undefined1 *)(in_ECX + 0x1c) = local_40;
        *(undefined1 *)(in_ECX + 0x1d) = local_3f;
        *(undefined4 *)(in_ECX + 0x20) = local_38;
        *(undefined2 *)(in_ECX + 0x28) = local_4e;
        *(undefined4 *)(in_ECX + 0x38) = 1;
        *(undefined4 *)(in_ECX + 0x24) = local_34;
        *(uint *)(in_ECX + 0x3c) = (local_10 << 0x18) >> 0x1f ^ 1;
        __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
        return;
      }
    }
    else if (param_5 != 0) {
      *(undefined4 *)(in_ECX + 0x38) = 0;
      *(undefined4 *)(in_ECX + 0x3c) = 0;
      iVar1 = FUN_10034760(in_ECX + 0x1070);
      if ((iVar1 != 0) && (*(char *)(in_ECX + 0x1083) != '\0')) {
        *(undefined4 *)(in_ECX + 0x18) = *(undefined4 *)(in_ECX + 0x107c);
        local_1c = 0x4030201;
        local_18 = 0x8070605;
        local_14 = 0x202;
        local_12 = 2;
        *(undefined1 *)(in_ECX + 0x1c) =
             *(undefined1 *)((int)&local_1c + (int)*(char *)(in_ECX + 0x1082));
        *(undefined2 *)(in_ECX + 0x28) = 0xffff;
        *(char *)(in_ECX + 0x1d) = *(char *)(in_ECX + 0x1083);
        __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
        return;
      }
    }
  }
  __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
  return;
}

