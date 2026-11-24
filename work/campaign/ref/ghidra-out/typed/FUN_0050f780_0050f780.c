
undefined1 __thiscall FUN_0050f780(ViWinFinder *this)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  undefined4 uVar5;
  int *piVar6;
  byte *pbVar7;
  undefined1 uVar8;
  int *piVar9;
  uint uVar10;
  bool bVar11;
  undefined4 *in_stack_00000004;
  undefined4 local_24;
  int *local_20;
  int *local_1c;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_007015d5;
  local_10 = ExceptionList;
  uVar3 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  iVar2 = in_stack_00000004[2];
  if (iVar2 == DAT_007723c8) {
    this->c_54 = '\x01';
    uVar8 = 1;
    goto LAB_0050f95a;
  }
  if (iVar2 == DAT_0077237c) {
    uVar10 = in_stack_00000004[0x10];
    this->c_54 = '\x01';
    if (uVar10 == 0xffffffff) {
LAB_0050f954:
      uVar8 = 1;
      goto LAB_0050f95a;
    }
    iVar2 = this->i_44;
    if (*(uint *)(iVar2 + 0x50) <= uVar10) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    piVar9 = *(int **)(*(int *)(*(int *)(iVar2 + 0x4c) + uVar10 * 4) + 0x20);
    if (piVar9 != (int *)0x0) {
      *piVar9 = *piVar9 + 1;
    }
    local_8._0_1_ = 1;
    local_1c = piVar9;
    local_14 = piVar9;
    FUN_006b9b20(&local_18,0,2);
    pbVar7 = &DAT_00725504;
    pbVar4 = (byte *)(local_18 + 3);
    do {
      bVar1 = *pbVar4;
      bVar11 = bVar1 < *pbVar7;
      if (bVar1 != *pbVar7) {
LAB_0050f851:
        uVar10 = -(uint)bVar11 | 1;
        goto LAB_0050f856;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar4[1];
      bVar11 = bVar1 < pbVar7[1];
      if (bVar1 != pbVar7[1]) goto LAB_0050f851;
      pbVar4 = pbVar4 + 2;
      pbVar7 = pbVar7 + 2;
    } while (bVar1 != 0);
    uVar10 = 0;
LAB_0050f856:
    local_8._0_1_ = 2;
    if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 == 0)) {
      FUN_006ba940();
    }
    local_8._0_1_ = 1;
    if (uVar10 == 0) {
      uVar5 = FUN_006b99f0(&local_20,2);
      local_8._0_1_ = 3;
      piVar6 = (int *)FUN_006b95d0(uVar5);
      local_8._0_1_ = 4;
      piVar9 = (int *)*piVar6;
      if (piVar9 != (int *)0x0) {
        *piVar9 = *piVar9 + 1;
      }
      local_14 = piVar9;
      if ((local_1c != (int *)0x0) && (*local_1c = *local_1c + -1, *local_1c == 0)) {
        FUN_006ba940();
      }
      piVar9[2] = *(int *)(*piVar6 + 8);
      local_8._0_1_ = 5;
      if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 == 0)) {
        FUN_006ba940();
      }
      local_8._0_1_ = 6;
      if ((local_20 != (int *)0x0) && (*local_20 = *local_20 + -1, *local_20 == 0)) {
        FUN_006ba940();
      }
    }
    local_8 = CONCAT31(local_8._1_3_,7);
    if ((piVar9 != (int *)0x0) && (*piVar9 = *piVar9 + -1, *piVar9 == 0)) {
      FUN_006ba940();
      uVar8 = 1;
      goto LAB_0050f95a;
    }
  }
  else {
    if (iVar2 != DAT_007723bc) {
      if ((iVar2 != DAT_00772388) || (in_stack_00000004[6] != this->i_48)) {
        uVar8 = 0;
        goto LAB_0050f95a;
      }
      this->c_4c = this->c_4c == '\0';
      goto LAB_0050f954;
    }
    iVar2 = *(int *)(this->i_44 + 0x48);
    local_24 = *(undefined4 *)(iVar2 + 100);
    local_20 = (int *)(*(int *)(iVar2 + 0x68) - (int)in_stack_00000004[0x10] / 2);
    FUN_00538b40(&local_24,1);
  }
  uVar8 = 1;
LAB_0050f95a:
  if (in_stack_00000004 != (undefined4 *)0x0) {
    LOCK();
    iVar2 = in_stack_00000004[1] + -1;
    in_stack_00000004[1] = iVar2;
    UNLOCK();
    if ((iVar2 == 0) && (in_stack_00000004 != (undefined4 *)0x0)) {
      (**(code **)*in_stack_00000004)(1,uVar3);
    }
  }
  ExceptionList = local_10;
  return uVar8;
}

