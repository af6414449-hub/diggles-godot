
undefined4 FUN_1001ec70(int *param_1,int param_2,int param_3)

{
  int iVar1;
  
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  if (param_3 != 0) {
    iVar1 = (**(code **)(*param_1 + 0x14))();
    (**(code **)(*param_1 + 0x10))(param_2 + iVar1);
    return 1;
  }
  (**(code **)(*param_1 + 0x10))(param_2);
  return 1;
}

