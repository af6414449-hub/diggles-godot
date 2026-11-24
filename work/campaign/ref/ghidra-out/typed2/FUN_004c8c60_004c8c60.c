
void __thiscall FUN_004c8c60(CSceneRenderer *this)

{
  void **ppvVar1;
  undefined4 *puVar2;
  int iVar3;
  void *pvVar4;
  int iVar5;
  int *piVar6;
  int in_stack_00000004;
  undefined4 *in_stack_00000008;
  
  ppvVar1 = &this->holesData;
  if ((in_stack_00000004 < 0) || (this->holeCount <= in_stack_00000004)) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    piVar6 = (int *)*ppvVar1;
  }
  else {
    piVar6 = (int *)(in_stack_00000004 * 0x1c + (int)*ppvVar1);
  }
  iVar5 = in_stack_00000004 * 0x1c;
  if (*piVar6 != -1) {
    if ((((in_stack_00000004 < 0) || (this->holeCount <= in_stack_00000004)) &&
        (RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0), in_stack_00000004 < 0)) ||
       (this->holeCount <= in_stack_00000004)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    iVar3 = FUN_00592f10(PTR_0077241c);
    *(undefined2 *)(iVar3 + 4) = 0xffff;
  }
  if ((in_stack_00000004 < 0) || (this->holeCount <= in_stack_00000004)) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    *(int *)((int)*ppvVar1 + 0x18) = this->holeTail;
    if (-1 < in_stack_00000004) goto LAB_004c8d67;
LAB_004c8d7a:
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    *(undefined4 *)*ppvVar1 = *in_stack_00000008;
    if (-1 < in_stack_00000004) goto LAB_004c8d9a;
LAB_004c8dac:
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    *(undefined4 *)((int)*ppvVar1 + 4) = in_stack_00000008[1];
    if (-1 < in_stack_00000004) goto LAB_004c8dce;
  }
  else {
    *(int *)((int)*ppvVar1 + iVar5 + 0x18) = this->holeTail;
LAB_004c8d67:
    if (this->holeCount <= in_stack_00000004) goto LAB_004c8d7a;
    *(undefined4 *)(iVar5 + (int)*ppvVar1) = *in_stack_00000008;
LAB_004c8d9a:
    if (this->holeCount <= in_stack_00000004) goto LAB_004c8dac;
    *(undefined4 *)((int)*ppvVar1 + iVar5 + 4) = in_stack_00000008[1];
LAB_004c8dce:
    if (in_stack_00000004 < this->holeCount) {
      pvVar4 = (void *)((int)*ppvVar1 + iVar5);
      goto LAB_004c8df8;
    }
  }
  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  pvVar4 = *ppvVar1;
LAB_004c8df8:
  puVar2 = *(undefined4 **)((int)pvVar4 + 8);
  iVar5 = in_stack_00000008[2];
  *(int *)((int)pvVar4 + 8) = iVar5;
  if (iVar5 != 0) {
    LOCK();
    *(int *)(iVar5 + 4) = *(int *)(iVar5 + 4) + 1;
    UNLOCK();
  }
  if (puVar2 != (undefined4 *)0x0) {
    LOCK();
    iVar5 = puVar2[1] + -1;
    puVar2[1] = iVar5;
    UNLOCK();
    if (iVar5 == 0) {
      (**(code **)*puVar2)(1);
    }
  }
  if ((in_stack_00000004 < 0) || (this->holeCount <= in_stack_00000004)) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    pvVar4 = *ppvVar1;
  }
  else {
    pvVar4 = (void *)((int)*ppvVar1 + in_stack_00000004 * 0x1c);
  }
  puVar2 = *(undefined4 **)((int)pvVar4 + 0xc);
  iVar5 = in_stack_00000008[3];
  *(int *)((int)pvVar4 + 0xc) = iVar5;
  if (iVar5 != 0) {
    LOCK();
    *(int *)(iVar5 + 4) = *(int *)(iVar5 + 4) + 1;
    UNLOCK();
  }
  if (puVar2 != (undefined4 *)0x0) {
    LOCK();
    iVar5 = puVar2[1] + -1;
    puVar2[1] = iVar5;
    UNLOCK();
    if (iVar5 == 0) {
      (**(code **)*puVar2)(1);
    }
  }
  if ((in_stack_00000004 < 0) || (this->holeCount <= in_stack_00000004)) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    pvVar4 = *ppvVar1;
  }
  else {
    pvVar4 = (void *)((int)*ppvVar1 + in_stack_00000004 * 0x1c);
  }
  puVar2 = *(undefined4 **)((int)pvVar4 + 0x10);
  iVar5 = in_stack_00000008[4];
  *(int *)((int)pvVar4 + 0x10) = iVar5;
  if (iVar5 != 0) {
    LOCK();
    *(int *)(iVar5 + 4) = *(int *)(iVar5 + 4) + 1;
    UNLOCK();
  }
  if (puVar2 != (undefined4 *)0x0) {
    LOCK();
    iVar5 = puVar2[1] + -1;
    puVar2[1] = iVar5;
    UNLOCK();
    if (iVar5 == 0) {
      (**(code **)*puVar2)(1);
    }
  }
  iVar5 = FUN_00592f10(PTR_0077241c);
  *(short *)(iVar5 + 4) = (short)in_stack_00000004;
  return;
}

