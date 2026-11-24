
void FUN_10007b50(void)

{
  int *piVar1;
  int *in_ECX;
  
  __CheckForDebuggerJustMyCode(&DAT_14170b5d);
  piVar1 = (int *)*in_ECX;
  if (piVar1 != (int *)0x0) {
    *in_ECX = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}

