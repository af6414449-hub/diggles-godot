
void FUN_1003ff62(size_t param_1)

{
  int iVar1;
  void *pvVar2;
  undefined1 local_14 [8];
  undefined4 uStack_c;
  
  do {
    uStack_c = 0x1003ff7c;
    pvVar2 = malloc(param_1);
    if (pvVar2 != (void *)0x0) {
      return;
    }
    uStack_c = 0x1003ff6f;
    iVar1 = _callnewh(param_1);
  } while (iVar1 != 0);
  if (param_1 != 0xffffffff) {
    FUN_10040b4c();
    return;
  }
  FUN_100029d0();
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_14,(ThrowInfo *)&DAT_1004a220);
}

