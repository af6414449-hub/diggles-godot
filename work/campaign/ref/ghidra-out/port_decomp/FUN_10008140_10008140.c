
void FUN_10008140(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  
  __CheckForDebuggerJustMyCode(&DAT_14170b81);
  piVar1 = (int *)in_ECX[1];
  if (piVar1 != (int *)0x0) {
    FUN_100080a0(*in_ECX,*(undefined4 *)(*piVar1 + 4));
    FUN_100402ac(*piVar1,0x2c);
  }
  return;
}

