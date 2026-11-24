
undefined1 __thiscall FUN_005179c0(ViWinLayoutCC_EditName *this)

{
  undefined4 *puVar1;
  uint uVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  undefined1 uVar7;
  int *piVar8;
  undefined4 *in_stack_00000004;
  int *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00701cf5;
  local_10 = ExceptionList;
  uVar4 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  if (in_stack_00000004[2] == DAT_007723b8) {
    iVar5 = FUN_00501450();
    if (*(int *)(iVar5 + 0x81a0) == this->i_54) {
      this->c_50 = '\x01';
      FUN_005177c0();
      uVar7 = 1;
      goto LAB_00517c20;
    }
    if (this->c_50 == '\0') {
      this->c_50 = '\0';
      FUN_005177c0();
    }
    else {
      iVar5 = this->i_34;
      if (iVar5 != 0) {
        FUN_00514940();
        FUN_00515340(*(int *)(iVar5 + 300) + 0xc);
        uVar7 = 1;
        goto LAB_00517c20;
      }
    }
  }
  else {
    uVar2 = this->i_4c;
    if (0 < (int)uVar2) {
      piVar8 = (int *)(DAT_0077244c + 0x488);
      if (uVar2 < 0x2000) {
        piVar8 = piVar8 + uVar2;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      local_14 = *piVar8;
      if (local_14 != 0) {
        puVar1 = (undefined4 *)(local_14 + 0xd8);
        cVar3 = FUN_006b97f0(this->i_54 + 0x20);
        if (cVar3 == '\0') {
          piVar8 = (int *)*puVar1;
          if (piVar8 != (int *)0x0) {
            *piVar8 = *piVar8 + 1;
          }
          local_8 = CONCAT31(local_8._1_3_,1);
          local_18 = piVar8;
          FUN_006b91c0(this->i_54 + 0x20);
          iVar5 = FUN_005db870();
          local_14 = FUN_005db890();
          if (0 < iVar5) {
            piVar6 = (int *)FUN_00407340(iVar5);
            if ((*piVar6 != 0) && (*(int *)(*piVar6 + 0x3f0) != 0)) {
              FUN_005db8b0(&local_18,puVar1);
            }
          }
          if (0 < local_14) {
            piVar6 = (int *)FUN_00407340(local_14);
            if ((*piVar6 != 0) && (*(int *)(*piVar6 + 0x3f0) != 0)) {
              FUN_005db8b0(&local_18,puVar1);
            }
          }
          iVar5 = FUN_00501450();
          if ((*(int *)(iVar5 + 0x81a0) != this->i_54) && (iVar5 = this->i_34, iVar5 != 0)) {
            FUN_00514940();
            FUN_00515340(*(int *)(iVar5 + 300) + 0xc);
          }
          local_8 = CONCAT31(local_8._1_3_,2);
          if ((piVar8 != (int *)0x0) && (*piVar8 = *piVar8 + -1, *piVar8 == 0)) {
            FUN_006ba940();
          }
        }
      }
    }
    if (in_stack_00000004 != (undefined4 *)0x0) {
      LOCK();
      in_stack_00000004[1] = in_stack_00000004[1] + 1;
      UNLOCK();
    }
    if (in_stack_00000004[2] == DAT_007723ec) {
      if (in_stack_00000004 != (undefined4 *)0x0) {
        LOCK();
        iVar5 = in_stack_00000004[1] + -1;
        in_stack_00000004[1] = iVar5;
        UNLOCK();
        if (iVar5 == 0) {
          (**(code **)*in_stack_00000004)(1);
          uVar7 = 1;
          goto LAB_00517c20;
        }
      }
    }
    else {
      if (in_stack_00000004[2] != DAT_007723e8) {
        if (in_stack_00000004 != (undefined4 *)0x0) {
          LOCK();
          iVar5 = in_stack_00000004[1] + -1;
          in_stack_00000004[1] = iVar5;
          UNLOCK();
          if (iVar5 == 0) {
            (**(code **)*in_stack_00000004)(1,uVar4);
          }
        }
        uVar7 = 0;
        goto LAB_00517c20;
      }
      if (in_stack_00000004 != (undefined4 *)0x0) {
        LOCK();
        iVar5 = in_stack_00000004[1] + -1;
        in_stack_00000004[1] = iVar5;
        UNLOCK();
        if (iVar5 == 0) {
          (**(code **)*in_stack_00000004)(1);
          uVar7 = 1;
          goto LAB_00517c20;
        }
      }
    }
  }
  uVar7 = 1;
LAB_00517c20:
  if (in_stack_00000004 != (undefined4 *)0x0) {
    LOCK();
    piVar8 = in_stack_00000004 + 1;
    iVar5 = *piVar8;
    *piVar8 = *piVar8 + -1;
    UNLOCK();
    if ((iVar5 == 1) && (in_stack_00000004 != (undefined4 *)0x0)) {
      (**(code **)*in_stack_00000004)(1);
    }
  }
  ExceptionList = local_10;
  return uVar7;
}

