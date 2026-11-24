
void FUN_100183c0(void)

{
  int *piVar1;
  uint uVar2;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_10041ad0;
  local_10 = ExceptionList;
  uVar2 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = DirectDrawSurface7Port::vftable;
  if (in_ECX[0x13] != 0) {
    free(*(void **)(in_ECX[0x13] + 0x14));
  }
  piVar1 = (int *)in_ECX[0x12];
  if (piVar1 != (int *)0x0) {
    in_ECX[0x12] = 0;
    (**(code **)(*piVar1 + 8))(piVar1,uVar2);
  }
  piVar1 = (int *)in_ECX[0x11];
  if (piVar1 != (int *)0x0) {
    in_ECX[0x11] = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  FUN_100402ac();
  ExceptionList = local_10;
  return;
}

