
void FUN_100080a0(undefined4 param_1,int *param_2)

{
  char cVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  __CheckForDebuggerJustMyCode(&DAT_14170b81);
  cVar1 = *(char *)((int)param_2 + 0xd);
  do {
    if (cVar1 != '\0') {
      return;
    }
    FUN_100080a0(param_1,param_2[2]);
    piVar2 = (int *)*param_2;
    uVar3 = param_2[9];
    if (0xf < uVar3) {
      iVar4 = param_2[4];
      uVar6 = uVar3 + 1;
      iVar5 = iVar4;
      if (0xfff < uVar6) {
        iVar5 = *(int *)(iVar4 + -4);
        uVar6 = uVar3 + 0x24;
        if (0x1f < (iVar4 - iVar5) - 4U) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
      }
      FUN_100402ac(iVar5,uVar6);
    }
    param_2[8] = 0;
    param_2[9] = 0xf;
    *(undefined1 *)(param_2 + 4) = 0;
    FUN_100402ac(param_2,0x2c);
    cVar1 = *(char *)((int)piVar2 + 0xd);
    param_2 = piVar2;
  } while( true );
}

