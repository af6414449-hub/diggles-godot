
undefined1 __thiscall FUN_005110b0(ViWinInfoOpts *this)

{
  uint uVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  undefined1 uVar5;
  undefined4 *in_stack_00000004;
  undefined4 local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_00701795;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  if (in_stack_00000004[2] == DAT_0077237c) {
    uVar1 = in_stack_00000004[0x10];
    if (uVar1 != 0xffffffff) {
      if ((uint)this->i_6c <= uVar1) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      FUN_00504910(this->i_68 + uVar1 * 4);
      uVar5 = 1;
      goto LAB_005111f5;
    }
  }
  else {
    if (in_stack_00000004[2] != DAT_007723bc) {
      if (in_stack_00000004[6] == this->i_50) {
        FUN_005103c0(DAT_0076700c ^ (uint)&stack0xfffffffc);
      }
      if (in_stack_00000004[6] == this->i_54) {
        FUN_00510860();
      }
      if (in_stack_00000004[6] == this->i_58) {
        piVar2 = *(int **)(this->i_4c + 0x20);
        if (piVar2 != (int *)0x0) {
          *piVar2 = *piVar2 + 1;
        }
        local_8._0_1_ = 1;
        piVar3 = (int *)this->i_64;
        this->i_64 = (int)piVar2;
        if (piVar2 != (int *)0x0) {
          *piVar2 = *piVar2 + 1;
        }
        local_14 = piVar2;
        if ((piVar3 != (int *)0x0) && (*piVar3 = *piVar3 + -1, *piVar3 == 0)) {
          FUN_006ba940();
        }
        *(int *)(this->i_64 + 8) = piVar2[2];
        local_8._0_1_ = 2;
        if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 == 0)) {
          FUN_006ba940();
        }
        local_8 = (uint)local_8._1_3_ << 8;
      }
      if (in_stack_00000004[6] == this->i_5c) {
        FUN_00504910(&this->i_64);
      }
      uVar5 = 0;
      goto LAB_005111f5;
    }
    iVar4 = *(int *)(this->i_48 + 0x48);
    local_18 = *(undefined4 *)(iVar4 + 100);
    local_14 = (int *)(*(int *)(iVar4 + 0x68) - (int)in_stack_00000004[0x10] / 2);
    FUN_00538b40(&local_18,1);
  }
  uVar5 = 1;
LAB_005111f5:
  if (in_stack_00000004 != (undefined4 *)0x0) {
    LOCK();
    iVar4 = in_stack_00000004[1] + -1;
    in_stack_00000004[1] = iVar4;
    UNLOCK();
    if ((iVar4 == 0) && (in_stack_00000004 != (undefined4 *)0x0)) {
      (**(code **)*in_stack_00000004)(1);
    }
  }
  ExceptionList = local_10;
  return uVar5;
}

