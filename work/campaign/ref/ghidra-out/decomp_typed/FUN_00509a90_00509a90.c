
undefined1 FUN_00509a90(undefined4 *param_1)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int this;
  undefined1 uVar5;
  int **ppiVar6;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  iVar1 = DAT_00772378;
  puStack_c = &LAB_0070114d;
  local_10 = ExceptionList;
  uVar2 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  iVar4 = param_1[2];
  if ((iVar4 < 0) || (*(int *)(DAT_00772378 + 0xc) <= iVar4)) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    piVar3 = *(int **)(iVar1 + 8);
  }
  else {
    piVar3 = (int *)(*(int *)(DAT_00772378 + 8) + iVar4 * 4);
  }
  if ((*(int *)(*piVar3 + 8) == 1) && (param_1[2] == DAT_007723dc)) {
    if ((*(char *)(param_1 + 0x10) == '\r') && (this->i_c8 != 0)) {
      piVar3 = *(int **)(this->i_c8 + 0x20);
      if (piVar3 != (int *)0x0) {
        *piVar3 = *piVar3 + 1;
      }
      local_8._0_1_ = 1;
      local_18 = piVar3;
      iVar4 = FUN_006b8f20(uVar2);
      if (iVar4 != 0) {
        FUN_006b8fb0(&PTR_0071ce50);
        local_8._0_1_ = 2;
        FUN_00504910(&local_14);
        local_8._0_1_ = 3;
        if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
          FUN_006ba940();
        }
        ppiVar6 = &local_18;
        local_8._0_1_ = 1;
        FUN_005b28d0(ppiVar6);
        FUN_005b3570(ppiVar6);
      }
      iVar4 = this->i_c8;
      if (*(char *)(iVar4 + 0x1c) != '\0') {
        FUN_00504ee0();
        *(undefined1 *)(iVar4 + 0x1c) = 0;
      }
      local_8 = CONCAT31(local_8._1_3_,4);
      if ((piVar3 != (int *)0x0) && (*piVar3 = *piVar3 + -1, *piVar3 == 0)) {
        FUN_006ba940();
      }
    }
    uVar5 = 1;
  }
  else {
    uVar5 = 0;
  }
  if (param_1 != (undefined4 *)0x0) {
    LOCK();
    iVar4 = param_1[1] + -1;
    param_1[1] = iVar4;
    UNLOCK();
    if ((iVar4 == 0) && (param_1 != (undefined4 *)0x0)) {
      (**(code **)*param_1)(1);
    }
  }
  ExceptionList = local_10;
  return uVar5;
}

