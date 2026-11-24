
int FUN_10017f70(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  piVar1 = (int *)(param_1 + 0x18);
  LOCK();
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  iVar2 = *piVar1;
  if (iVar2 == 0) {
    if (DAT_10050c64 == 0) {
      piVar1 = *(int **)(param_1 + 0x14);
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1);
      }
    }
    else {
      uVar4 = *(undefined4 *)(param_1 + 0x10);
      uVar3 = *(undefined4 *)(param_1 + 0xc);
      FUN_1000ece0();
      iVar2 = param_1 + 0x14;
      FUN_10010da0(uVar3,uVar4,iVar2);
      FUN_10010eb0(uVar3,uVar4,iVar2);
    }
    *(undefined4 *)(param_1 + 0x14) = 0;
    FUN_100402ac(param_1,0x1c);
    iVar2 = 0;
  }
  return iVar2;
}

