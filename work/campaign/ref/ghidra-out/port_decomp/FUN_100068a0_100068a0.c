
void FUN_100068a0(void)

{
  int *piVar1;
  int iVar2;
  int *in_ECX;
  undefined1 local_14 [16];
  
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  piVar1 = (int *)*in_ECX;
  if (piVar1 != (int *)0x0) {
    *in_ECX = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  iVar2 = CreateDXGIFactory1(&DAT_100447c4,in_ECX);
  if (-1 < iVar2) {
    return;
  }
  FUN_100053a0(iVar2);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_14,(ThrowInfo *)&DAT_1004a24c);
}

