
void __thiscall FUN_004c68d0(CSceneRenderer *this)

{
  void **ppvVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  void *pvVar6;
  int in_stack_00000004;
  void *local_c;
  
  iVar2 = in_stack_00000004;
  if (in_stack_00000004 == 0xffff) {
    return;
  }
  ppvVar1 = &this->holesData;
  if ((in_stack_00000004 < 0) || (this->holeCount <= in_stack_00000004)) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    pvVar6 = *ppvVar1;
    local_c = pvVar6;
    if (-1 < in_stack_00000004) goto LAB_004c694e;
LAB_004c695f:
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    piVar4 = (int *)*ppvVar1;
  }
  else {
    pvVar6 = *ppvVar1;
    local_c = (void *)((int)pvVar6 + in_stack_00000004 * 0x1c);
LAB_004c694e:
    if (this->holeCount <= in_stack_00000004) goto LAB_004c695f;
    piVar4 = (int *)(in_stack_00000004 * 0x1c + (int)pvVar6);
  }
  in_stack_00000004 = in_stack_00000004 * 0x1c;
  if ((((PTR_0077241c->cellX0 <= *piVar4) && (*piVar4 < PTR_0077241c->cellX1)) &&
      (PTR_0077241c->cellY0 <= *(int *)((int)local_c + 4))) &&
     (*(int *)((int)local_c + 4) < PTR_0077241c->cellY1)) {
    if ((((iVar2 < 0) || (this->holeCount <= iVar2)) &&
        (RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0), iVar2 < 0)) || (this->holeCount <= iVar2))
    {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    iVar5 = FUN_00592f10(PTR_0077241c);
    *(undefined2 *)(iVar5 + 4) = 0xffff;
  }
  if ((iVar2 < 0) || (this->holeCount <= iVar2)) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    *(undefined4 *)*ppvVar1 = 0xffffffff;
    if (-1 < iVar2) goto LAB_004c6a48;
  }
  else {
    *(undefined4 *)(in_stack_00000004 + (int)*ppvVar1) = 0xffffffff;
LAB_004c6a48:
    if (iVar2 < this->holeCount) {
      pvVar6 = (void *)((int)*ppvVar1 + in_stack_00000004);
      goto LAB_004c6a66;
    }
  }
  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  pvVar6 = *ppvVar1;
LAB_004c6a66:
  puVar3 = *(undefined4 **)((int)pvVar6 + 8);
  *(undefined4 *)((int)pvVar6 + 8) = 0;
  if (puVar3 != (undefined4 *)0x0) {
    LOCK();
    iVar5 = puVar3[1] + -1;
    puVar3[1] = iVar5;
    UNLOCK();
    if (iVar5 == 0) {
      (**(code **)*puVar3)(1);
    }
  }
  if ((iVar2 < 0) || (this->holeCount <= iVar2)) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    pvVar6 = *ppvVar1;
  }
  else {
    pvVar6 = (void *)((int)*ppvVar1 + in_stack_00000004);
  }
  puVar3 = *(undefined4 **)((int)pvVar6 + 0xc);
  *(undefined4 *)((int)pvVar6 + 0xc) = 0;
  if (puVar3 != (undefined4 *)0x0) {
    LOCK();
    iVar5 = puVar3[1] + -1;
    puVar3[1] = iVar5;
    UNLOCK();
    if (iVar5 == 0) {
      (**(code **)*puVar3)(1);
    }
  }
  if ((iVar2 < 0) || (this->holeCount <= iVar2)) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    pvVar6 = *ppvVar1;
  }
  else {
    pvVar6 = (void *)((int)*ppvVar1 + in_stack_00000004);
  }
  puVar3 = *(undefined4 **)((int)pvVar6 + 0x10);
  *(undefined4 *)((int)pvVar6 + 0x10) = 0;
  if (puVar3 != (undefined4 *)0x0) {
    LOCK();
    piVar4 = puVar3 + 1;
    iVar2 = *piVar4;
    *piVar4 = *piVar4 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      (**(code **)*puVar3)(1);
    }
  }
  this->flag4 = '\x01';
  return;
}

