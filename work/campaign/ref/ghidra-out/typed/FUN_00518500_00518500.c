
/* WARNING: Type propagation algorithm not settling */

void __thiscall FUN_00518500(ViWinListCtrl *this)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int *in_stack_00000004;
  int local_1c;
  int local_14 [4];
  
  if (this->i_3c == 0) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  iVar1 = this->i_48;
  if (*(int *)this->i_38 != iVar1) {
    iVar2 = this->i_3c;
    uVar4 = 0;
    if (0 < iVar2) {
      do {
        if ((uint)this->i_3c <= uVar4) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        if (*(int *)(this->i_38 + uVar4 * 4) == iVar1) {
          FUN_0040b5c0(uVar4);
          FUN_00506020(0);
          if (this->i_3c == 0) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          *(int *)this->i_38 = iVar1;
          break;
        }
        uVar4 = uVar4 + 1;
      } while ((int)uVar4 < iVar2);
    }
  }
  uVar4 = 0;
  iVar1 = this->i_50;
  local_14[0] = *(int *)(this->i_48 + 0x68);
  if (iVar1 < 1) {
    FUN_00518350();
  }
  else {
    do {
      if ((uint)this->i_50 <= uVar4) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      uVar4 = uVar4 + 1;
    } while ((int)uVar4 < iVar1);
    FUN_00518350();
    local_14[1] = 0;
    uVar4 = 0;
    local_1c = 0;
    do {
      if (uVar4 == this->i_44) {
        if ((uint)this->i_50 <= uVar4) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        iVar2 = *(int *)(this->i_4c + uVar4 * 4);
        uVar3 = *(uint *)(iVar2 + 0x24) | 0x1000000;
      }
      else {
        if ((uint)this->i_50 <= uVar4) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        iVar2 = *(int *)(this->i_4c + uVar4 * 4);
        uVar3 = *(uint *)(iVar2 + 0x24) & 0xfeffffff;
      }
      if (uVar3 != *(uint *)(iVar2 + 0x24)) {
        *(uint *)(iVar2 + 0x24) = uVar3;
        FUN_00504ee0();
      }
      local_14[2] = local_1c - local_14[0];
      if ((uint)this->i_50 <= uVar4) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      FUN_00504a70(local_14 + 1);
      if ((uint)this->i_50 <= uVar4) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      iVar2 = *(int *)(this->i_4c + uVar4 * 4);
      uVar4 = uVar4 + 1;
      local_1c = local_1c + (*(int *)(iVar2 + 0x18) - *(int *)(iVar2 + 0x10));
    } while ((int)uVar4 < iVar1);
  }
  local_14[0] = *(int *)(in_stack_00000004[1] + 0x28);
  if (*(int *)(*in_stack_00000004 + 8) != 0) {
    FUN_004ff430(*in_stack_00000004 + 0xc,local_14);
  }
  return;
}

