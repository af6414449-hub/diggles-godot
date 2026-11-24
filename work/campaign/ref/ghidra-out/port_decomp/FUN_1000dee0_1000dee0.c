
void FUN_1000dee0(void)

{
  int *piVar1;
  int iVar2;
  int *in_ECX;
  undefined4 in_EDX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_10042230;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  __CheckForDebuggerJustMyCode(&DAT_14170510,in_EDX,DAT_1005000c ^ (uint)&stack0xfffffffc);
  piVar1 = (int *)in_ECX[0x32d];
  if (piVar1 != (int *)0x0) {
    in_ECX[0x32d] = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = (int *)in_ECX[0x32c];
  if (piVar1 != (int *)0x0) {
    in_ECX[0x32c] = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = (int *)in_ECX[0x32b];
  if (piVar1 != (int *)0x0) {
    in_ECX[0x32b] = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = (int *)in_ECX[0x32a];
  if (piVar1 != (int *)0x0) {
    in_ECX[0x32a] = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = (int *)in_ECX[0x329];
  if (piVar1 != (int *)0x0) {
    in_ECX[0x329] = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  _eh_vector_destructor_iterator_(in_ECX + 0x21d,4,8,FUN_10007ac0);
  _eh_vector_destructor_iterator_(in_ECX + 0x215,4,8,FUN_10007ac0);
  _eh_vector_destructor_iterator_(in_ECX + 0x20d,4,8,FUN_10007ac0);
  _eh_vector_destructor_iterator_(in_ECX + 0x205,4,8,FUN_10007ac0);
  piVar1 = (int *)in_ECX[4];
  if (piVar1 != (int *)0x0) {
    in_ECX[4] = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = (int *)in_ECX[3];
  if (piVar1 != (int *)0x0) {
    in_ECX[3] = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  iVar2 = in_ECX[2];
  if (iVar2 != 0) {
    FUN_100103f0();
    FUN_100402ac(iVar2,0xac);
  }
  piVar1 = (int *)in_ECX[1];
  if (piVar1 != (int *)0x0) {
    FUN_1000c790(piVar1,*(undefined4 *)(*piVar1 + 4));
    FUN_100402ac(*piVar1,0x18);
    FUN_100402ac(piVar1,0x2c);
  }
  iVar2 = *in_ECX;
  if (iVar2 != 0) {
    FUN_10010680();
    FUN_100402ac(iVar2,0xd8);
  }
  ExceptionList = local_10;
  return;
}

