
undefined1 __thiscall FUN_0054c900(ViWinTextEdit *this)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  ViWinTextEdit *pVVar4;
  int *piVar5;
  int iVar6;
  char *pcVar7;
  undefined1 uVar8;
  undefined4 *in_stack_00000004;
  ViWinTextEdit *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  iVar2 = DAT_00772378;
  puStack_c = &LAB_00704435;
  local_10 = ExceptionList;
  uVar3 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  iVar6 = in_stack_00000004[2];
  local_14 = this;
  if ((iVar6 < 0) || (*(int *)(DAT_00772378 + 0xc) <= iVar6)) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    piVar5 = *(int **)(iVar2 + 8);
  }
  else {
    piVar5 = (int *)(*(int *)(DAT_00772378 + 8) + iVar6 * 4);
  }
  if (((*(int *)(*piVar5 + 8) == 0) && (in_stack_00000004[2] == DAT_007723c4)) &&
     (pVVar4 = (ViWinTextEdit *)FUN_00504a00(uVar3), pVVar4 != this)) {
    this[1].i_20 = (int)pVVar4;
  }
  iVar2 = DAT_00772378;
  iVar6 = in_stack_00000004[2];
  if ((iVar6 < 0) || (*(int *)(DAT_00772378 + 0xc) <= iVar6)) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    piVar5 = *(int **)(iVar2 + 8);
  }
  else {
    piVar5 = (int *)(*(int *)(DAT_00772378 + 8) + iVar6 * 4);
  }
  if ((*(int *)(*piVar5 + 8) == 1) && (in_stack_00000004[2] == DAT_007723dc)) {
    local_14 = (ViWinTextEdit *)CONCAT31(local_14._1_3_,*(undefined1 *)(in_stack_00000004 + 0x10));
    switch(*(undefined1 *)(in_stack_00000004 + 0x10)) {
    case 8:
      iVar6 = FUN_006b8f20();
      if (iVar6 != 0) {
        iVar6 = FUN_006b8f20();
        FUN_006b9b20(&local_14,0,iVar6 + -1);
        local_8._0_1_ = 1;
        FUN_006b91c0(&local_14);
        local_8._0_1_ = 2;
        if ((local_14 != (ViWinTextEdit *)0x0) &&
           (*(int *)local_14 = *(int *)local_14 + -1, *(int *)local_14 == 0)) {
          FUN_006ba940();
        }
        local_8 = (uint)local_8._1_3_ << 8;
      }
      break;
    case 9:
    case 0xd:
      if (this[2].field_0x1 == '\0') {
        if (this[1].i_20 == 0) {
          iVar6 = FUN_00501450();
          *(undefined4 *)(iVar6 + 0x81a0) = 0;
        }
        else {
          FUN_00504a00(uVar3);
        }
      }
      break;
    default:
      iVar6 = this->i_20;
      if (*(int *)(iVar6 + 8) == -1) {
        pcVar7 = (char *)(iVar6 + 0xc);
        do {
          cVar1 = *pcVar7;
          pcVar7 = pcVar7 + 1;
        } while (cVar1 != '\0');
        *(int *)(iVar6 + 8) = (int)pcVar7 - (iVar6 + 0xd);
        iVar6 = this->i_20;
      }
      if (*(int *)(iVar6 + 8) < *(int *)&this[2].field_0x14) {
LAB_0054caaa:
        FUN_006b9330(local_14);
      }
      break;
    case 0x20:
      if ((*(char *)(this + 2) != '\0') &&
         (iVar6 = FUN_006b8f20(), iVar6 < *(int *)&this[2].field_0x14)) goto LAB_0054caaa;
    }
    FUN_00504ee0();
  }
  if (in_stack_00000004 != (undefined4 *)0x0) {
    LOCK();
    in_stack_00000004[1] = in_stack_00000004[1] + 1;
    UNLOCK();
  }
  if (in_stack_00000004[2] == DAT_007723ec) {
    if (in_stack_00000004 != (undefined4 *)0x0) {
      LOCK();
      iVar6 = in_stack_00000004[1] + -1;
      in_stack_00000004[1] = iVar6;
      UNLOCK();
      if (iVar6 == 0) {
        (**(code **)*in_stack_00000004)(1);
      }
    }
  }
  else {
    if (in_stack_00000004[2] != DAT_007723e8) {
      if (in_stack_00000004 != (undefined4 *)0x0) {
        LOCK();
        iVar6 = in_stack_00000004[1] + -1;
        in_stack_00000004[1] = iVar6;
        UNLOCK();
        if (iVar6 == 0) {
          (**(code **)*in_stack_00000004)(1);
        }
      }
      uVar8 = 0;
      goto LAB_0054cb1f;
    }
    if (in_stack_00000004 != (undefined4 *)0x0) {
      LOCK();
      iVar6 = in_stack_00000004[1] + -1;
      in_stack_00000004[1] = iVar6;
      UNLOCK();
      if (iVar6 == 0) {
        (**(code **)*in_stack_00000004)(1);
        uVar8 = 1;
        goto LAB_0054cb1f;
      }
    }
  }
  uVar8 = 1;
LAB_0054cb1f:
  if (in_stack_00000004 != (undefined4 *)0x0) {
    LOCK();
    piVar5 = in_stack_00000004 + 1;
    iVar6 = *piVar5;
    *piVar5 = *piVar5 + -1;
    UNLOCK();
    if ((iVar6 == 1) && (in_stack_00000004 != (undefined4 *)0x0)) {
      (**(code **)*in_stack_00000004)(1);
    }
  }
  ExceptionList = local_10;
  return uVar8;
}

