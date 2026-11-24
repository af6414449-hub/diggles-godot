
void FUN_005672d0(int param_1,int param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  byte bVar7;
  uint uVar8;
  int local_10;
  int local_c;
  int local_8;
  
  if (param_1 < PTR_0077241c->cellX0 + 1) {
    return;
  }
  if (PTR_0077241c->cellX1 + -1 <= param_1) {
    return;
  }
  if (param_2 < PTR_0077241c->cellY0 + 1) {
    return;
  }
  if (param_2 < PTR_0077241c->cellY1 + -1) {
    iVar4 = FUN_00592f10(PTR_0077241c);
    if (param_4 < 8) {
      iVar5 = param_4 + iVar4;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      iVar5 = iVar4;
    }
    if (*(char *)(iVar5 + 0x34) != '\0') {
      if ((*(ushort *)(iVar4 + 0x18) & 3) == 0) {
        return;
      }
      if ((*(ushort *)(iVar4 + 0x18) & 3) == 3) {
        return;
      }
      local_10 = param_1;
      local_c = param_2;
      iVar5 = FUN_005968b0(&local_10);
      iVar6 = FUN_00597430();
      if (iVar5 < iVar6) {
        return;
      }
    }
    uVar1 = *(uint *)(iVar4 + 8);
    cVar3 = FUN_00566870(param_1,param_2,1);
    if (cVar3 != '\0') {
      bVar7 = (byte)(param_4 * 4);
      uVar8 = ~(0xf << (bVar7 & 0x1f));
      uVar2 = *(uint *)(iVar4 + 0xc);
      *(uint *)(iVar4 + 8) = uVar8 & uVar1 | 3 << (bVar7 & 0x1f);
      if (param_4 < 8) {
        local_8 = local_8 + param_4 * 4;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(uint *)(iVar4 + 0xc) = (*(uint *)(local_8 + 0xb4) & 0xf) << (bVar7 & 0x1f) | uVar8 & uVar2;
    }
    return;
  }
  return;
}

