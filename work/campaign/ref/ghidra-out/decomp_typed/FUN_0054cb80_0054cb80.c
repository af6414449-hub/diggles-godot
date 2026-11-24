
void FUN_0054cb80(int *param_1)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  int this;
  undefined4 extraout_ECX;
  int *piVar4;
  undefined4 uVar5;
  int *piVar6;
  int *local_28;
  int local_24;
  int local_20;
  undefined4 local_1c;
  int local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00704475;
  local_10 = ExceptionList;
  uVar1 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = this;
  iVar2 = FUN_00501450(uVar1);
  if (*(int *)(iVar2 + 0x81a0) == this) {
    local_14 = *(int **)(param_1[1] + 0x34);
  }
  else {
    local_14 = *(int **)(param_1[1] + 0x28);
  }
  if (*(int *)(*param_1 + 8) != 0) {
    FUN_004ff430(*param_1 + 0xc,&local_14);
  }
  piVar3 = *(int **)(this + 0x20);
  if (piVar3 != (int *)0x0) {
    *piVar3 = *piVar3 + 1;
  }
  local_8 = 0;
  local_14 = piVar3;
  iVar2 = FUN_00501450(uVar1);
  if (*(int *)(iVar2 + 0x81a0) == this) {
    iVar2 = piVar3[2];
    if (iVar2 == -1) {
      piVar4 = piVar3 + 3;
      do {
        iVar2 = *piVar4;
        piVar4 = (int *)((int)piVar4 + 1);
      } while ((char)iVar2 != '\0');
      iVar2 = (int)piVar4 - ((int)piVar3 + 0xd);
      piVar3[2] = iVar2;
    }
    piVar3 = (int *)FUN_006b8df0(piVar3,iVar2 + 2);
    *(undefined2 *)(iVar2 + 0xc + (int)piVar3) = 0x7c;
    piVar3[2] = iVar2 + 1;
    this = local_18;
    local_14 = piVar3;
  }
  uVar5 = 0x54cc4d;
  FUN_004ef7b0(param_1 + 4);
  local_8 = CONCAT31(local_8._1_3_,1);
  iVar2 = this->i_20;
  piVar6 = (int *)0x54cc5f;
  piVar4 = (int *)FUN_004ef240();
  if (local_20 == *piVar4) {
    if (local_24 != 0) goto LAB_0054cc8e;
  }
  else {
    local_24 = 0;
    local_20 = *piVar4;
  }
  piVar6 = local_28 + 3;
  uVar5 = 0x54cc8b;
  local_24 = FUN_004ef660(piVar6);
LAB_0054cc8e:
  FUN_004edf70(&local_1c,iVar2 + 0xc,uVar5,piVar6);
  local_18 = (this->i_18 - this->i_10) + -3;
  local_1c = 0;
  FUN_004fdff0(&local_1c,piVar3 + 3,param_1[1] + 0x2c,&local_28,1,extraout_ECX);
  local_8 = CONCAT31(local_8._1_3_,2);
  if ((local_28 != (int *)0x0) && (*local_28 = *local_28 + -1, *local_28 == 0)) {
    FUN_006ba940();
  }
  local_8 = 3;
  if ((piVar3 != (int *)0x0) && (*piVar3 = *piVar3 + -1, *piVar3 == 0)) {
    FUN_006ba940();
  }
  ExceptionList = local_10;
  return;
}

