
void FUN_10010340(void)

{
  int *piVar1;
  int *in_ECX;
  
  __CheckForDebuggerJustMyCode(&DAT_14170b80);
  piVar1 = (int *)*in_ECX;
  if (piVar1 != (int *)0x0) {
    FUN_1000c790(piVar1,*(undefined4 *)(*piVar1 + 4));
    FUN_100402ac(*piVar1,0x18);
    FUN_100402ac(piVar1,0x2c);
  }
  return;
}

