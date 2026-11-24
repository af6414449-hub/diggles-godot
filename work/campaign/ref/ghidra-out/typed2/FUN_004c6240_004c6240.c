
void __thiscall FUN_004c6240(CSceneRenderer *this)

{
  void **ppvVar1;
  undefined4 *puVar2;
  int iVar3;
  void *pvVar4;
  int *piVar5;
  int iVar6;
  int local_c;
  
  iVar6 = 0;
  this->flag4 = '\x01';
  if (0 < this->holeCapacity) {
    ppvVar1 = &this->holesData;
    local_c = 0;
    do {
      if ((iVar6 < 0) || (this->holeCount <= iVar6)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        piVar5 = (int *)*ppvVar1;
      }
      else {
        piVar5 = (int *)(local_c + (int)*ppvVar1);
      }
      if (*piVar5 != -1) {
        if ((((iVar6 < 0) || (this->holeCount <= iVar6)) &&
            (RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0), iVar6 < 0)) ||
           (this->holeCount <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        iVar3 = FUN_00592f10(PTR_0077241c);
        *(undefined2 *)(iVar3 + 4) = 0xffff;
      }
      if ((iVar6 < 0) || (this->holeCount <= iVar6)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        *(undefined4 *)*ppvVar1 = 0xffffffff;
        if (-1 < iVar6) goto LAB_004c633e;
LAB_004c634c:
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pvVar4 = *ppvVar1;
      }
      else {
        *(undefined4 *)(local_c + (int)*ppvVar1) = 0xffffffff;
LAB_004c633e:
        if (this->holeCount <= iVar6) goto LAB_004c634c;
        pvVar4 = (void *)((int)*ppvVar1 + local_c);
      }
      puVar2 = *(undefined4 **)((int)pvVar4 + 8);
      *(undefined4 *)((int)pvVar4 + 8) = 0;
      if (puVar2 != (undefined4 *)0x0) {
        LOCK();
        iVar3 = puVar2[1] + -1;
        puVar2[1] = iVar3;
        UNLOCK();
        if (iVar3 == 0) {
          (**(code **)*puVar2)(1);
        }
      }
      if ((iVar6 < 0) || (this->holeCount <= iVar6)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pvVar4 = *ppvVar1;
      }
      else {
        pvVar4 = (void *)((int)*ppvVar1 + local_c);
      }
      puVar2 = *(undefined4 **)((int)pvVar4 + 0xc);
      *(undefined4 *)((int)pvVar4 + 0xc) = 0;
      if (puVar2 != (undefined4 *)0x0) {
        LOCK();
        iVar3 = puVar2[1] + -1;
        puVar2[1] = iVar3;
        UNLOCK();
        if (iVar3 == 0) {
          (**(code **)*puVar2)(1);
        }
      }
      if ((iVar6 < 0) || (this->holeCount <= iVar6)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pvVar4 = *ppvVar1;
      }
      else {
        pvVar4 = (void *)((int)*ppvVar1 + local_c);
      }
      puVar2 = *(undefined4 **)((int)pvVar4 + 0x10);
      *(undefined4 *)((int)pvVar4 + 0x10) = 0;
      if (puVar2 != (undefined4 *)0x0) {
        LOCK();
        iVar3 = puVar2[1] + -1;
        puVar2[1] = iVar3;
        UNLOCK();
        if (iVar3 == 0) {
          (**(code **)*puVar2)(1);
        }
      }
      iVar6 = iVar6 + 1;
      local_c = local_c + 0x1c;
    } while (iVar6 < this->holeCapacity);
  }
  return;
}

