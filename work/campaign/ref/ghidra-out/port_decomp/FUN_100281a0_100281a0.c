
undefined4 FUN_100281a0(void)

{
  int iVar1;
  int in_ECX;
  
  __CheckForDebuggerJustMyCode(&DAT_14170cf0);
  iVar1 = (**(code **)(in_ECX + 0x1a2c))(*(undefined4 *)(in_ECX + 0x1a30),0,0);
  if (iVar1 != 0) {
    *(undefined4 *)(in_ECX + 0x3e60) = 0;
    *(undefined4 *)(in_ECX + 0x3e64) = 0;
    FUN_10028100();
    return 1;
  }
  return 0;
}

