
undefined4 FUN_10018540(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined1 local_18 [16];
  undefined4 *local_8;
  
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  puVar1 = (undefined4 *)FUN_1003ff62(8);
  *puVar1 = DirectDrawClipperPort::vftable;
  puVar1[1] = 0;
  local_8 = puVar1;
  iVar2 = FUN_100186f0(puVar1,&DAT_10043420,param_2);
  if (-1 < iVar2) {
    return 0;
  }
  FUN_100402ac(puVar1,8);
  FUN_100053a0(iVar2);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_18,(ThrowInfo *)&DAT_1004a24c);
}

