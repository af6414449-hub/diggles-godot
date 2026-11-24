
void FUN_1000c480(int param_1)

{
  int in_ECX;
  undefined1 local_10 [12];
  
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  if ((((param_1 != 0x1c2) && (param_1 != 0x2c2)) && (param_1 != 0x1c4)) &&
     ((param_1 != 0x2c4 && (param_1 != 0x102)))) {
    FUN_100092e0("Shader not implemented");
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_10,(ThrowInfo *)&DAT_1004a2f4);
  }
  if (*(int *)(in_ECX + 0x28) != param_1) {
    FUN_1000c540(&param_1);
    FUN_1000b5d0();
    *(int *)(in_ECX + 0x28) = param_1;
  }
  FUN_1000be50(param_1);
  return;
}

