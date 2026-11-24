
undefined4 FUN_100164b0(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  bool bVar5;
  undefined1 local_14 [16];
  
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  piVar3 = &DAT_10043440;
  uVar4 = 0xc;
  do {
    if (*piVar3 != *param_1) {
      return 0x80004005;
    }
    piVar3 = piVar3 + 1;
    param_1 = param_1 + 1;
    bVar5 = 3 < uVar4;
    uVar4 = uVar4 - 4;
  } while (bVar5);
  puVar1 = (undefined4 *)FUN_1003ff62(0x6c);
  puVar1[1] = IDirect3DDevice7Extensions::vftable;
  *puVar1 = Direct3DDevice7Port::vftable;
  puVar1[1] = Direct3DDevice7Port::vftable;
  puVar1[2] = 0;
  *(undefined1 *)(puVar1 + 0x1a) = 0;
  iVar2 = FUN_100179e0(puVar1,&DAT_10043450,param_3);
  if (-1 < iVar2) {
    return 0;
  }
  FUN_100402ac(puVar1,0x6c);
  FUN_100053a0(iVar2);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_14,(ThrowInfo *)&DAT_1004a24c);
}

