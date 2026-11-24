
undefined4 FUN_10029dc0(void)

{
  int iVar1;
  int in_ECX;
  
  __CheckForDebuggerJustMyCode(&DAT_14170ce3);
  if (*(int *)(in_ECX + 4) == 0) {
    iVar1 = (**(code **)(in_ECX + 8))
                      (*(undefined4 *)(in_ECX + 0xc),*(undefined4 *)(in_ECX + 0x68),0);
    if (iVar1 != 0) {
      if ((*(short *)(in_ECX + 0x54) == 2) || (*(short *)(in_ECX + 0x54) == 0x11)) {
        *(undefined4 *)(in_ECX + 0xe0) = 0;
        *(undefined4 *)(in_ECX + 0xe4) = 0;
      }
      *(undefined4 *)(in_ECX + 0x70) = *(undefined4 *)(in_ECX + 0x60);
      *(undefined4 *)(in_ECX + 0x74) = *(undefined4 *)(in_ECX + 100);
      return 1;
    }
  }
  return 0;
}

