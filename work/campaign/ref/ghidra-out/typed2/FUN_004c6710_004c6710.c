
void __thiscall FUN_004c6710(CSceneRenderer *this)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  void *pvVar5;
  code *pcVar6;
  int in_stack_00000004;
  int in_stack_00000008;
  
  if ((((PTR_0077241c->cellX0 <= in_stack_00000004) && (in_stack_00000004 < PTR_0077241c->cellX1))
      && (PTR_0077241c->cellY0 <= in_stack_00000008)) && (in_stack_00000008 < PTR_0077241c->cellY1))
  {
    iVar2 = FUN_00592f10(PTR_0077241c);
    uVar3 = (uint)*(ushort *)(iVar2 + 4);
    if (*(ushort *)(iVar2 + 4) != 0xffff) {
      iVar2 = FUN_00592f10(PTR_0077241c);
      pcVar6 = RaiseException_exref;
      *(undefined2 *)(iVar2 + 4) = 0xffff;
      if ((int)uVar3 < this->holeCount) {
        puVar4 = (undefined4 *)((int)this->holesData + uVar3 * 0x1c);
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar4 = (undefined4 *)this->holesData;
        pcVar6 = RaiseException_exref;
      }
      *puVar4 = 0xffffffff;
      if ((int)uVar3 < this->holeCount) {
        pvVar5 = (void *)((int)this->holesData + uVar3 * 0x1c);
      }
      else {
        (*pcVar6)(0xc000008c,1,0,0);
        pvVar5 = this->holesData;
      }
      puVar4 = *(undefined4 **)((int)pvVar5 + 8);
      *(undefined4 *)((int)pvVar5 + 8) = 0;
      if (puVar4 != (undefined4 *)0x0) {
        LOCK();
        iVar2 = puVar4[1] + -1;
        puVar4[1] = iVar2;
        UNLOCK();
        if (iVar2 == 0) {
          (**(code **)*puVar4)(1);
        }
      }
      if ((int)uVar3 < this->holeCount) {
        pvVar5 = (void *)((int)this->holesData + uVar3 * 0x1c);
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pvVar5 = this->holesData;
      }
      puVar4 = *(undefined4 **)((int)pvVar5 + 0xc);
      *(undefined4 *)((int)pvVar5 + 0xc) = 0;
      if (puVar4 != (undefined4 *)0x0) {
        LOCK();
        iVar2 = puVar4[1] + -1;
        puVar4[1] = iVar2;
        UNLOCK();
        if (iVar2 == 0) {
          (**(code **)*puVar4)(1);
        }
      }
      if ((int)uVar3 < this->holeCount) {
        pvVar5 = (void *)((int)this->holesData + uVar3 * 0x1c);
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pvVar5 = this->holesData;
      }
      puVar4 = *(undefined4 **)((int)pvVar5 + 0x10);
      *(undefined4 *)((int)pvVar5 + 0x10) = 0;
      if (puVar4 != (undefined4 *)0x0) {
        LOCK();
        piVar1 = puVar4 + 1;
        iVar2 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar2 == 1) {
          (**(code **)*puVar4)(1);
        }
      }
      this->flag4 = '\x01';
    }
  }
  return;
}

