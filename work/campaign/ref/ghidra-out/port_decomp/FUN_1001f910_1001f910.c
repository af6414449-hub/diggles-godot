
undefined4 FUN_1001f910(void)

{
  int iVar1;
  int in_ECX;
  
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  switch(*(undefined4 *)(*(int *)(in_ECX + 0x1c0) + 0x68)) {
  case 0:
    if (*(int *)(in_ECX + 0x1cc) != 0) {
      FUN_10029e20();
    }
    break;
  case 1:
    if (*(int *)(in_ECX + 0x1cc) != 0) {
      FUN_1003f690();
    }
    break;
  case 2:
    iVar1 = *(int *)(in_ECX + 0x1cc);
    if (((iVar1 != 0) && (*(int *)(iVar1 + 0x90) != 0 || *(int *)(iVar1 + 0x94) != 0)) &&
       (*(int *)(iVar1 + 0x98) != 0 || *(int *)(iVar1 + 0x9c) != 0)) {
      *(undefined4 *)(iVar1 + 0x90) = 0;
      *(undefined4 *)(iVar1 + 0x94) = 0;
      FUN_10035290();
    }
    break;
  case 3:
    if ((*(int *)(in_ECX + 0x1cc) != 0) && (*(int *)(*(int *)(in_ECX + 0x1cc) + 0x1a2c) != 0)) {
      FUN_100281a0();
    }
  }
  *(undefined4 *)(in_ECX + 0x1c4) = 0;
  *(undefined8 *)(in_ECX + 0x60) = 0;
  return 0;
}

