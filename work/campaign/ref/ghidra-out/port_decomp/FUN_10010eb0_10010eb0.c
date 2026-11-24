
void FUN_10010eb0(uint param_1,undefined4 param_2,undefined4 param_3)

{
  int *in_ECX;
  undefined1 local_18 [8];
  int local_10;
  
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  FUN_10011410(local_18,&param_1);
  if (((*(char *)(local_10 + 0xd) == '\0') && (*(uint *)(local_10 + 0x10) <= param_1)) &&
     (local_10 != *in_ECX)) {
    FUN_10011090(local_18,&param_1);
    FUN_10010c60(param_2,param_3);
    return;
  }
  FUN_100053a0(0x80004005);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_18,(ThrowInfo *)&DAT_1004a24c);
}

