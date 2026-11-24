
void FUN_100103b0(int *param_1)

{
  int *in_ECX;
  int *piVar1;
  
  __CheckForDebuggerJustMyCode(&DAT_14170b5d);
  piVar1 = (int *)*in_ECX;
  if (piVar1 != param_1) {
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 4))(param_1);
      piVar1 = (int *)*in_ECX;
    }
    *in_ECX = (int)param_1;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
  }
  return;
}

