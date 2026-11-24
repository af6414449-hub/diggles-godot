
void FUN_00516ba0(void)

{
  void *lp;
  int iVar1;
  uint uVar2;
  uint uVar3;
  BOOL BVar4;
  int iVar5;
  int iVar6;
  int this;
  undefined4 *puVar7;
  undefined4 in_XMM0_Da;
  float fVar8;
  float local_8;
  
  if (this->i_48 == 0) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  uVar3 = _atol((char *)(**(int **)(this + 0x44) + 0xc));
  if (uVar3 - 2 < 0x1fff) {
    this->i_4c = uVar3;
    if (0 < (int)uVar3) {
      puVar7 = (undefined4 *)(DAT_0077244c + 0x488);
      if (uVar3 < 0x2000) {
        puVar7 = puVar7 + uVar3;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      lp = (void *)*puVar7;
      if ((((lp == (void *)0x0) || (BVar4 = IsBadReadPtr(lp,0x10), BVar4 != 0)) ||
          (*(int *)((int)lp + 8) != 0x616e4f62)) ||
         ((DAT_00768398 != '\0' && (*(int *)((int)lp + 0xdc) == 0)))) {
        this->i_4c = 0;
        return;
      }
      iVar5 = FUN_005da0f0();
      FUN_005dadf0(*(undefined4 *)(iVar5 + 0x300c));
      this->i_54 = in_XMM0_Da;
      fVar8 = 0.0;
      iVar1 = *(int *)(iVar5 + 0x3008);
      uVar3 = 0;
      local_8 = 0.0;
      if (0 < iVar1) {
        do {
          if (*(uint *)(iVar5 + 0x3008) <= uVar3) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          uVar2 = *(uint *)(*(int *)(iVar5 + 0x3004) + uVar3 * 4);
          if (*(int *)((int)lp + 0x21c) == 0) {
            if (uVar2 < 0x200) {
              iVar6 = FUN_005da0f0();
              fVar8 = *(float *)(iVar6 + 0x1804 + uVar2 * 4);
            }
            else {
LAB_00516ce7:
              fVar8 = 0.0;
            }
          }
          else {
            if (0x1ff < uVar2) goto LAB_00516ce7;
            fVar8 = *(float *)(*(int *)((int)lp + 0x21c) + uVar2 * 4);
          }
          fVar8 = fVar8 + local_8;
          uVar3 = uVar3 + 1;
          local_8 = fVar8;
        } while ((int)uVar3 < iVar1);
      }
      if (fVar8 != this->f_50) {
        this->f_50 = fVar8;
        FUN_00504ee0();
      }
      return;
    }
  }
  else {
    this->i_4c = 0;
  }
  this->f_50 = 0;
  return;
}

