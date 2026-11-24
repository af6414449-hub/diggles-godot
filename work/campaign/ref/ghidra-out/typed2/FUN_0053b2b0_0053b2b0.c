
undefined1 __thiscall FUN_0053b2b0(ViWinSmallMap *this)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined1 uVar7;
  undefined4 *in_stack_00000004;
  undefined4 uVar8;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0070334d;
  local_10 = ExceptionList;
  uVar5 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  cVar2 = this->c_b0;
  if ((cVar2 == '\0') && (iVar6 = in_stack_00000004[2], iVar6 == DAT_00772388)) {
    if (in_stack_00000004[6] != this->i_114) {
      if (iVar6 == DAT_00772388) {
        if (in_stack_00000004[6] == this->i_110) {
          if (1.0 <= this->f_b4) {
            this->f_b4 = this->f_b4 / 1.5;
            FUN_00504ee0();
            uVar7 = 1;
            goto LAB_0053b683;
          }
          goto LAB_0053b614;
        }
        if (iVar6 == DAT_00772388) {
          if (in_stack_00000004[6] == this->i_118) {
            this->c_b2 = this->c_b2 == '\0';
            FUN_00504ee0();
            uVar7 = 1;
            goto LAB_0053b683;
          }
          if ((iVar6 == DAT_00772388) && (in_stack_00000004[6] == this->i_11c)) {
            this->c_b1 = this->c_b1 == '\0';
            FUN_00504ee0();
            uVar7 = 1;
            goto LAB_0053b683;
          }
        }
      }
      goto LAB_0053b403;
    }
    if (this->f_b4 <= 12.0) {
      this->f_b4 = this->f_b4 * 1.5;
      FUN_00504ee0();
      uVar7 = 1;
      goto LAB_0053b683;
    }
  }
  else {
LAB_0053b403:
    iVar6 = in_stack_00000004[2];
    if ((iVar6 == DAT_007723c4) &&
       ((in_stack_00000004[10] + -0xa8) * (in_stack_00000004[10] + -0xa8) +
        (in_stack_00000004[9] + -0x3c) * (in_stack_00000004[9] + -0x3c) < 0x1729)) {
      this->c_b0 = '\x01';
      iVar6 = this->i_a4;
      iVar3 = this->i_ac;
      iVar4 = in_stack_00000004[10];
      *(float *)(*(int *)(DAT_00772400 + 0x5a4) + 0x154) =
           (float)(this->i_a8 - this->i_a0) * ((float)(int)in_stack_00000004[9] / 138.0) +
           (float)this->i_a0;
      *(float *)(*(int *)(DAT_00772400 + 0x5a4) + 0x158) =
           (float)(iVar3 - iVar6) * ((float)(iVar4 + -0x59) / 138.0) + (float)iVar6;
      iVar6 = FUN_00501450();
      uVar5 = FUN_0042f510();
      if (*(uint *)(iVar6 + 0xc) <= uVar5) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(ViWinSmallMap **)(*(int *)(iVar6 + 8) + uVar5 * 4) = this;
      *(ViWinSmallMap **)(iVar6 + 0x81a4) = this;
      uVar7 = 1;
      goto LAB_0053b683;
    }
    if ((iVar6 == DAT_007723c8) && (cVar2 != '\0')) {
      this->c_b0 = '\0';
      FUN_00504ee0();
      uVar8 = 0;
      FUN_00501450(0);
      FUN_00501f80(uVar8);
      uVar7 = 1;
      goto LAB_0053b683;
    }
    if (((iVar6 != DAT_007723d4) ||
        (iVar6 = in_stack_00000004[9] + -0x3c,
        0x1728 < (in_stack_00000004[10] + -0xa8) * (in_stack_00000004[10] + -0xa8) + iVar6 * iVar6))
       || (cVar2 == '\0')) {
      piVar1 = in_stack_00000004 + 1;
      LOCK();
      *piVar1 = *piVar1 + 1;
      UNLOCK();
      if (in_stack_00000004[2] == DAT_007723ec) {
        if (in_stack_00000004 != (undefined4 *)0x0) {
          LOCK();
          iVar6 = *piVar1;
          *piVar1 = iVar6 + -1;
          UNLOCK();
          if (iVar6 + -1 == 0) {
            (**(code **)*in_stack_00000004)(1);
          }
        }
      }
      else {
        if (in_stack_00000004[2] != DAT_007723e8) {
          if (in_stack_00000004 != (undefined4 *)0x0) {
            LOCK();
            iVar6 = *piVar1;
            *piVar1 = iVar6 + -1;
            UNLOCK();
            if (iVar6 + -1 == 0) {
              (**(code **)*in_stack_00000004)(1,uVar5);
            }
          }
          uVar7 = 0;
          goto LAB_0053b683;
        }
        if (in_stack_00000004 != (undefined4 *)0x0) {
          LOCK();
          iVar6 = *piVar1;
          *piVar1 = iVar6 + -1;
          UNLOCK();
          if (iVar6 + -1 == 0) {
            (**(code **)*in_stack_00000004)(1);
            uVar7 = 1;
            goto LAB_0053b683;
          }
        }
      }
      uVar7 = 1;
      goto LAB_0053b683;
    }
    iVar6 = this->i_a4;
    iVar3 = this->i_ac;
    iVar4 = in_stack_00000004[10];
    *(float *)(*(int *)(DAT_00772400 + 0x5a4) + 0x154) =
         (float)(this->i_a8 - this->i_a0) * ((float)(int)in_stack_00000004[9] / 138.0) +
         (float)this->i_a0;
    *(float *)(*(int *)(DAT_00772400 + 0x5a4) + 0x158) =
         (float)(iVar3 - iVar6) * ((float)(iVar4 + -0x59) / 138.0) + (float)iVar6;
  }
LAB_0053b614:
  uVar7 = 1;
LAB_0053b683:
  if (in_stack_00000004 != (undefined4 *)0x0) {
    LOCK();
    piVar1 = in_stack_00000004 + 1;
    iVar6 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if ((iVar6 == 1) && (in_stack_00000004 != (undefined4 *)0x0)) {
      (**(code **)*in_stack_00000004)(1);
    }
  }
  ExceptionList = local_10;
  return uVar7;
}

