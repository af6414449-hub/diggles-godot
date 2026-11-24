
void __thiscall FUN_005186e0(ViWinListCtrl *this)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint local_18;
  int local_14;
  int local_10 [3];
  
  if ((this->c_55 != '\0') && (cVar1 = FUN_005049a0(), cVar1 != '\0')) {
    iVar2 = FUN_00501450();
    iVar2 = *(int *)(iVar2 + 0x101d8);
    iVar3 = FUN_00504b60(local_10);
    iVar2 = iVar2 - *(int *)(iVar3 + 4);
    local_10[0] = iVar2;
    if (9 >= iVar2) {
      local_18 = *(uint *)(this->i_48 + 100);
      local_14 = *(int *)(this->i_48 + 0x68) + -5;
      FUN_00538b40(&local_18,1);
      FUN_00504ee0();
    }
    if (iVar2 < (this->i_18 - this->i_10) + -10) {
      if (9 < iVar2) {
        return;
      }
    }
    else {
      local_18 = *(uint *)(this->i_48 + 100);
      local_14 = *(int *)(this->i_48 + 0x68) + 5;
      FUN_00538b40(&local_18,1);
      FUN_00504ee0();
    }
    uVar5 = 0;
    uVar4 = this->i_50;
    iVar2 = -*(int *)(this->i_48 + 0x68);
    local_18 = uVar4;
    if (0 < (int)uVar4) {
      do {
        if ((uint)this->i_50 <= uVar5) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          uVar4 = local_18;
        }
        iVar3 = *(int *)(this->i_4c + uVar5 * 4);
        iVar2 = iVar2 + (*(int *)(iVar3 + 0x18) - *(int *)(iVar3 + 0x10));
        if (local_10[0] < iVar2) {
          FUN_00518100(uVar5);
          uVar4 = local_18;
          uVar5 = local_18;
        }
        uVar5 = uVar5 + 1;
      } while ((int)uVar5 < (int)uVar4);
    }
  }
  return;
}

