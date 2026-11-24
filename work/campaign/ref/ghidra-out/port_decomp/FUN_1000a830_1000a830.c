
void FUN_1000a830(int param_1)

{
  int *piVar1;
  char *pcVar2;
  int *piVar3;
  int *piVar4;
  void *pvVar5;
  char *in_ECX;
  undefined4 in_EDX;
  undefined4 uVar6;
  int iVar7;
  float in_XMM2_Da;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10041e7d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = param_1;
  __CheckForDebuggerJustMyCode(&DAT_14170d01,in_EDX,DAT_1005000c ^ (uint)&stack0xfffffffc);
  if (*in_ECX != '\0') {
    *in_ECX = '\0';
    FUN_1000b330();
    FUN_1000b060();
    FUN_1000b060();
    FUN_1000b060();
    FUN_1000b060();
    FUN_1000b060();
  }
  if (DAT_10050c64 == (int *)0x0) {
    pvVar5 = (void *)FUN_1003ff62(0xcbc);
    local_8 = 0;
    memset(pvVar5,0,0xcbc);
    DAT_10050c64 = (int *)FUN_1000e160();
    local_8 = 0xffffffff;
  }
  piVar1 = (int *)(in_ECX + 0x3c);
  piVar3 = (int *)*piVar1;
  piVar4 = *(int **)(*DAT_10050c64 + 8);
  if (piVar3 != (int *)0x0) {
    *piVar1 = 0;
    (**(code **)(*piVar3 + 8))(piVar3);
  }
  (**(code **)(*piVar4 + 0x16c))(piVar4,piVar1,in_ECX + 0x44,in_ECX + 0x54);
  piVar1 = *(int **)(in_ECX + 0x40);
  pcVar2 = in_ECX + 0x40;
  if (piVar1 != (int *)0x0) {
    pcVar2[0] = '\0';
    pcVar2[1] = '\0';
    pcVar2[2] = '\0';
    pcVar2[3] = '\0';
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  (**(code **)(*piVar4 + 0x178))(piVar4,pcVar2);
  piVar1 = *(int **)(in_ECX + 0x38);
  pcVar2 = in_ECX + 0x38;
  if (piVar1 != (int *)0x0) {
    pcVar2[0] = '\0';
    pcVar2[1] = '\0';
    pcVar2[2] = '\0';
    pcVar2[3] = '\0';
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  (**(code **)(*piVar4 + 0x170))(piVar4,pcVar2,in_ECX + 0x58);
  piVar1 = *(int **)(in_ECX + 0x60);
  pcVar2 = in_ECX + 0x60;
  if (piVar1 != (int *)0x0) {
    pcVar2[0] = '\0';
    pcVar2[1] = '\0';
    pcVar2[2] = '\0';
    pcVar2[3] = '\0';
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  (**(code **)(*piVar4 + 300))(piVar4,0,1,pcVar2);
  piVar1 = *(int **)(in_ECX + 100);
  pcVar2 = in_ECX + 100;
  if (piVar1 != (int *)0x0) {
    pcVar2[0] = '\0';
    pcVar2[1] = '\0';
    pcVar2[2] = '\0';
    pcVar2[3] = '\0';
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  (**(code **)(*piVar4 + 300))(piVar4,1,1,pcVar2);
  if (DAT_10050c64 == (int *)0x0) {
    pvVar5 = (void *)FUN_1003ff62(0xcbc);
    local_8 = 1;
    memset(pvVar5,0,0xcbc);
    DAT_10050c64 = (int *)FUN_1000e160();
    local_8 = 0xffffffff;
  }
  piVar1 = *(int **)(*DAT_10050c64 + 8);
  (**(code **)(*piVar1 + 0x8c))(piVar1,*(undefined4 *)(in_ECX + 0x30),0,0xffffffff);
  (**(code **)(*piVar1 + 0xac))(piVar1,*(undefined4 *)(in_ECX + 0x34));
  (**(code **)(*piVar1 + 0x90))(piVar1,*(undefined4 *)(in_ECX + 0x2c),1);
  uVar6 = *(undefined4 *)(local_14 + 0x44);
  if (in_ECX[1] != '\0') {
    FUN_1000a620(local_14);
    uVar6 = *(undefined4 *)(in_ECX + 0x6c);
  }
  FUN_1000abf0(&DAT_10050e38,*(undefined4 *)(in_ECX + 0x7c),uVar6,0);
  FUN_1000a400();
  FUN_1000abf0(&DAT_10050da8,*(undefined4 *)(in_ECX + 0x88),uVar6,0);
  iVar7 = 0;
  if (0.0 < (float)(byte)in_ECX[2] * in_XMM2_Da) {
    do {
      FUN_1000abf0(&DAT_10050d18,*(undefined4 *)(in_ECX + 0x94),*(undefined4 *)(in_ECX + 0x8c),0);
      FUN_1000abf0(&DAT_10050f58,*(undefined4 *)(in_ECX + 0x88),*(undefined4 *)(in_ECX + 0x98),0);
      iVar7 = iVar7 + 1;
    } while ((float)iVar7 < (float)(byte)in_ECX[2] * in_XMM2_Da);
  }
  iVar7 = local_14;
  FUN_1000abf0(&DAT_10050fe8,*(undefined4 *)(local_14 + 0x1c),uVar6,*(undefined4 *)(in_ECX + 0x8c));
  if (DAT_10050c64 == (int *)0x0) {
    pvVar5 = (void *)FUN_1003ff62(0xcbc);
    local_8 = 2;
    memset(pvVar5,0,0xcbc);
    DAT_10050c64 = (int *)FUN_1000e160();
    local_8 = 0xffffffff;
  }
  piVar1 = *(int **)(*DAT_10050c64 + 8);
  (**(code **)(*piVar1 + 0x8c))
            (piVar1,*(undefined4 *)(in_ECX + 0x3c),in_ECX + 0x44,*(undefined4 *)(in_ECX + 0x54));
  (**(code **)(*piVar1 + 0xac))(piVar1,*(undefined4 *)(in_ECX + 0x40));
  (**(code **)(*piVar1 + 0x90))
            (piVar1,*(undefined4 *)(in_ECX + 0x38),*(undefined4 *)(in_ECX + 0x58));
  (**(code **)(*piVar1 + 0x28))(piVar1,0,1,in_ECX + 0x60);
  (**(code **)(*piVar1 + 0x28))(piVar1,1,1,in_ECX + 100);
  local_14 = *(int *)(iVar7 + 0x1c);
  uVar6 = *(undefined4 *)(iVar7 + 0x20);
  if (DAT_10050c64 == (int *)0x0) {
    pvVar5 = (void *)FUN_1003ff62(0xcbc);
    local_8 = 3;
    memset(pvVar5,0,0xcbc);
    DAT_10050c64 = (int *)FUN_1000e160();
    local_8 = 0xffffffff;
  }
  (**(code **)(**(int **)(*DAT_10050c64 + 8) + 0x84))
            (*(int **)(*DAT_10050c64 + 8),1,&local_14,uVar6);
  ExceptionList = local_10;
  return;
}

