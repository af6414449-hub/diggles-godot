
void FUN_00517580(void)

{
  void *lp;
  int *piVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  BOOL BVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int this;
  undefined4 *puVar9;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00701c8d;
  local_10 = ExceptionList;
  uVar3 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (0 < this->i_48) {
    if (this->i_48 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    uVar4 = _atol((char *)(**(int **)(this + 0x44) + 0xc));
    if (uVar4 - 2 < 0x1fff) {
      this->i_4c = uVar4;
      if ((int)uVar4 < 1) {
        ExceptionList = local_10;
        return;
      }
      puVar9 = (undefined4 *)(DAT_0077244c + 0x488);
      if (uVar4 < 0x2000) {
        puVar9 = puVar9 + uVar4;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      lp = (void *)*puVar9;
      if ((((lp != (void *)0x0) && (BVar5 = IsBadReadPtr(lp,0x10), BVar5 == 0)) &&
          (*(int *)((int)lp + 8) == 0x616e4f62)) &&
         ((DAT_00768398 == '\0' || (*(int *)((int)lp + 0xdc) != 0)))) {
        iVar6 = FUN_00501450(uVar3);
        iVar7 = this->i_54 + 0x20;
        if (*(int *)(iVar6 + 0x81a0) != this->i_54) {
          cVar2 = FUN_006b97f0(iVar7);
          if (((cVar2 == '\0') && (iVar7 = FUN_006b8f20(), iVar7 != 0)) &&
             (iVar7 = this->i_34, iVar7 != 0)) {
            FUN_00514940();
            FUN_00515340(*(int *)(iVar7 + 300) + 0xc);
          }
          FUN_00504910((undefined4 *)((int)lp + 0xd8));
          ExceptionList = local_10;
          return;
        }
        cVar2 = FUN_006b97f0(iVar7);
        if (cVar2 != '\0') {
          ExceptionList = local_10;
          return;
        }
        piVar1 = *(int **)((int)lp + 0xd8);
        if (piVar1 != (int *)0x0) {
          *piVar1 = *piVar1 + 1;
        }
        local_8 = 4;
        local_14 = piVar1;
        FUN_006b91c0(this->i_54 + 0x20);
        iVar7 = FUN_005db870();
        iVar6 = FUN_005db890();
        if (0 < iVar7) {
          piVar8 = (int *)FUN_00407340(iVar7);
          if ((*piVar8 != 0) && (*(int *)(*piVar8 + 0x3f0) != 0)) {
            FUN_005db8b0(&local_14,(int)lp + 0xd8);
          }
        }
        if (0 < iVar6) {
          piVar8 = (int *)FUN_00407340(iVar6);
          if ((*piVar8 != 0) && (*(int *)(*piVar8 + 0x3f0) != 0)) {
            FUN_005db8b0(&local_14,(int)lp + 0xd8);
          }
        }
        local_8 = 5;
        if (piVar1 == (int *)0x0) {
          ExceptionList = local_10;
          return;
        }
        *piVar1 = *piVar1 + -1;
        if (*piVar1 != 0) {
          ExceptionList = local_10;
          return;
        }
        FUN_006ba940();
        ExceptionList = local_10;
        return;
      }
    }
  }
  this->i_4c = 0;
  ExceptionList = local_10;
  return;
}

