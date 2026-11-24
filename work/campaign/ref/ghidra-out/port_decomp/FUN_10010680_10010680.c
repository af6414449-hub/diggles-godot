
void FUN_10010680(void)

{
  int *piVar1;
  uint uVar2;
  int *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_10041ad0;
  local_10 = ExceptionList;
  uVar2 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar1 = (int *)in_ECX[0x14];
  if (piVar1 != (int *)0x0) {
    in_ECX[0x14] = 0;
    (**(code **)(*piVar1 + 8))(piVar1,uVar2);
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
  piVar1 = (int *)in_ECX[0x11];
  if (piVar1 != (int *)0x0) {
    in_ECX[0x11] = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = (int *)in_ECX[0x10];
  if (piVar1 != (int *)0x0) {
    in_ECX[0x10] = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = (int *)in_ECX[0xf];
  if (piVar1 != (int *)0x0) {
    in_ECX[0xf] = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = (int *)in_ECX[8];
  if (piVar1 != (int *)0x0) {
    in_ECX[8] = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = (int *)in_ECX[7];
  if (piVar1 != (int *)0x0) {
    in_ECX[7] = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = (int *)in_ECX[6];
  if (piVar1 != (int *)0x0) {
    in_ECX[6] = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = (int *)in_ECX[5];
  if (piVar1 != (int *)0x0) {
    in_ECX[5] = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
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
  piVar1 = (int *)in_ECX[2];
  if (piVar1 != (int *)0x0) {
    in_ECX[2] = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = (int *)in_ECX[1];
  if (piVar1 != (int *)0x0) {
    in_ECX[1] = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = (int *)*in_ECX;
  if (piVar1 != (int *)0x0) {
    *in_ECX = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  ExceptionList = local_10;
  return;
}

