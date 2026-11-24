
void FUN_10018970(int *param_1,undefined4 *param_2)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  undefined1 local_84 [104];
  int local_1c;
  uint local_8;
  
  local_8 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  iVar1 = 0;
  if (0 < *(int *)(in_ECX + 0x24)) {
    puVar2 = (undefined4 *)(in_ECX + 4);
    do {
      (**(code **)(*(int *)*puVar2 + 100))(local_84);
      if (local_1c == *param_1) {
        *param_2 = *(undefined4 *)(in_ECX + 4 + iVar1 * 4);
        break;
      }
      iVar1 = iVar1 + 1;
      puVar2 = puVar2 + 1;
    } while (iVar1 < *(int *)(in_ECX + 0x24));
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

