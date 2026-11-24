
void * __thiscall FUN_004c6430(CSceneRenderer *this)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  CMap *pCVar4;
  void *pvVar5;
  int iVar6;
  CMapCell *pCVar7;
  undefined4 *puVar8;
  void *pvVar9;
  int iVar10;
  int iVar11;
  int in_stack_00000004;
  int in_stack_00000008;
  int in_stack_0000000c;
  void *in_stack_00000010;
  
  if (in_stack_00000004 < PTR_0077241c->cellX0) {
    in_stack_00000004 = PTR_0077241c->cellX0;
  }
  if (in_stack_00000008 < PTR_0077241c->cellY0) {
    in_stack_00000008 = PTR_0077241c->cellY0;
  }
  if (PTR_0077241c->cellX1 < in_stack_0000000c) {
    in_stack_0000000c = PTR_0077241c->cellX1;
  }
  pvVar5 = (void *)PTR_0077241c->cellY1;
  if ((int)pvVar5 < (int)in_stack_00000010) {
    in_stack_00000010 = pvVar5;
  }
  for (; iVar3 = in_stack_00000004, pCVar4 = PTR_0077241c,
      in_stack_00000008 < (int)in_stack_00000010; in_stack_00000008 = in_stack_00000008 + 1) {
    for (; PTR_0077241c = pCVar4, iVar3 < in_stack_0000000c; iVar3 = iVar3 + 1) {
      iVar11 = pCVar4->cellX0;
      if (pCVar4->cellX0 <= iVar3) {
        iVar11 = iVar3;
      }
      iVar10 = pCVar4->cellY0;
      if (pCVar4->cellY0 <= in_stack_00000008) {
        iVar10 = in_stack_00000008;
      }
      iVar6 = pCVar4->cellY1 + -1;
      if (iVar10 < pCVar4->cellY1) {
        iVar6 = iVar10;
      }
      iVar10 = pCVar4->cellX1 + -1;
      if (iVar11 < pCVar4->cellX1) {
        iVar10 = iVar11;
      }
      iVar11 = (iVar6 * pCVar4->mapWidth + iVar10) % pCVar4->cellCountTotal;
      if ((iVar11 < 0) || (pCVar4->cellCount <= iVar11)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pCVar7 = pCVar4->cells;
      }
      else {
        pCVar7 = pCVar4->cells + iVar11;
      }
      pCVar4 = PTR_0077241c;
      pvVar5 = (void *)(uint)pCVar7->objectIndex;
      if (pCVar7->objectIndex != 0xffff) {
        iVar11 = PTR_0077241c->cellX0;
        if (PTR_0077241c->cellX0 <= iVar3) {
          iVar11 = iVar3;
        }
        iVar10 = PTR_0077241c->cellY0;
        if (PTR_0077241c->cellY0 <= in_stack_00000008) {
          iVar10 = in_stack_00000008;
        }
        iVar6 = PTR_0077241c->cellY1 + -1;
        if (iVar10 < PTR_0077241c->cellY1) {
          iVar6 = iVar10;
        }
        iVar10 = PTR_0077241c->cellX1 + -1;
        if (iVar11 < PTR_0077241c->cellX1) {
          iVar10 = iVar11;
        }
        iVar11 = (iVar6 * PTR_0077241c->mapWidth + iVar10) % PTR_0077241c->cellCountTotal;
        if ((iVar11 < 0) || (PTR_0077241c->cellCount <= iVar11)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pCVar7 = pCVar4->cells;
        }
        else {
          pCVar7 = PTR_0077241c->cells + iVar11;
        }
        pCVar7->objectIndex = 0xffff;
        if ((int)pvVar5 < this->holeCount) {
          puVar8 = (undefined4 *)((int)this->holesData + (int)pvVar5 * 0x1c);
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          puVar8 = (undefined4 *)this->holesData;
        }
        *puVar8 = 0xffffffff;
        if ((int)pvVar5 < this->holeCount) {
          pvVar9 = (void *)((int)this->holesData + (int)pvVar5 * 0x1c);
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pvVar9 = this->holesData;
        }
        puVar8 = *(undefined4 **)((int)pvVar9 + 8);
        *(undefined4 *)((int)pvVar9 + 8) = 0;
        if (puVar8 != (undefined4 *)0x0) {
          LOCK();
          iVar11 = puVar8[1] + -1;
          puVar8[1] = iVar11;
          UNLOCK();
          if (iVar11 == 0) {
            (**(code **)*puVar8)(1);
          }
        }
        if ((int)pvVar5 < this->holeCount) {
          pvVar9 = (void *)((int)this->holesData + (int)pvVar5 * 0x1c);
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pvVar9 = this->holesData;
        }
        puVar8 = *(undefined4 **)((int)pvVar9 + 0xc);
        *(undefined4 *)((int)pvVar9 + 0xc) = 0;
        if (puVar8 != (undefined4 *)0x0) {
          LOCK();
          iVar11 = puVar8[1] + -1;
          puVar8[1] = iVar11;
          UNLOCK();
          if (iVar11 == 0) {
            (**(code **)*puVar8)(1);
          }
        }
        if ((int)pvVar5 < this->holeCount) {
          pvVar5 = (void *)((int)this->holesData + (int)pvVar5 * 0x1c);
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pvVar5 = this->holesData;
        }
        puVar8 = *(undefined4 **)((int)pvVar5 + 0x10);
        *(undefined4 *)((int)pvVar5 + 0x10) = 0;
        if (puVar8 != (undefined4 *)0x0) {
          LOCK();
          puVar1 = puVar8 + 1;
          uVar2 = *puVar1;
          pvVar5 = (void *)*puVar1;
          *puVar1 = uVar2 - 1;
          UNLOCK();
          if (uVar2 - 1 == 0) {
            pvVar5 = (void *)(**(code **)*puVar8)(1);
          }
        }
        this->flag4 = '\x01';
      }
      pCVar4 = PTR_0077241c;
    }
  }
  return pvVar5;
}

