
void FUN_100095b0(void)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int *in_ECX;
  uint uVar5;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_10041ad0;
  local_10 = ExceptionList;
  uVar3 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar1 = (int *)in_ECX[0x18];
  if (piVar1 != (int *)0x0) {
    in_ECX[0x18] = 0;
    (**(code **)(*piVar1 + 8))(piVar1,uVar3);
  }
  piVar1 = (int *)in_ECX[0x17];
  if (piVar1 != (int *)0x0) {
    in_ECX[0x17] = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = (int *)in_ECX[0x16];
  if (piVar1 != (int *)0x0) {
    in_ECX[0x16] = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = (int *)in_ECX[0x15];
  if (piVar1 != (int *)0x0) {
    in_ECX[0x15] = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = (int *)in_ECX[0x14];
  if (piVar1 != (int *)0x0) {
    in_ECX[0x14] = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = (int *)in_ECX[0x13];
  if (piVar1 != (int *)0x0) {
    in_ECX[0x13] = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = (int *)in_ECX[0x12];
  if (piVar1 != (int *)0x0) {
    in_ECX[0x12] = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  FUN_1000aec0();
  uVar3 = in_ECX[5];
  if (0xf < uVar3) {
    iVar2 = *in_ECX;
    uVar5 = uVar3 + 1;
    iVar4 = iVar2;
    if (0xfff < uVar5) {
      iVar4 = *(int *)(iVar2 + -4);
      uVar5 = uVar3 + 0x24;
      if (0x1f < (iVar2 - iVar4) - 4U) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
    }
    FUN_100402ac(iVar4,uVar5);
  }
  in_ECX[4] = 0;
  in_ECX[5] = 0xf;
  *(undefined1 *)in_ECX = 0;
  ExceptionList = local_10;
  return;
}

