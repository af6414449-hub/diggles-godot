
void FUN_005671a0(int param_1,int param_2,uint param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  byte bVar5;
  uint uVar6;
  int local_10;
  int local_c;
  int local_8;
  
  if ((((PTR_0077241c->cellX0 + 1 <= param_1) && (param_1 < PTR_0077241c->cellX1 + -1)) &&
      (PTR_0077241c->cellY0 + 1 <= param_2)) && (param_2 < PTR_0077241c->cellY1 + -1)) {
    iVar2 = FUN_00592f10(PTR_0077241c);
    if (param_4 < 8) {
      iVar3 = param_4 + iVar2;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      iVar3 = iVar2;
    }
    if (*(char *)(iVar3 + 0x34) != '\0') {
      if ((*(ushort *)(iVar2 + 0x18) & 3) == 0) {
        return;
      }
      if ((*(ushort *)(iVar2 + 0x18) & 3) == 3) {
        return;
      }
      local_10 = param_1;
      local_c = param_2;
      iVar3 = FUN_005968b0(&local_10);
      iVar4 = FUN_00597430();
      if (iVar3 < iVar4) {
        return;
      }
    }
    bVar5 = (byte)(param_4 * 4);
    uVar6 = ~(0xf << (bVar5 & 0x1f));
    uVar1 = *(uint *)(iVar2 + 0xc);
    *(uint *)(iVar2 + 8) = (param_3 | 8) << (bVar5 & 0x1f) | *(uint *)(iVar2 + 8) & uVar6;
    if (param_4 < 8) {
      local_8 = local_8 + param_4 * 4;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    *(uint *)(iVar2 + 0xc) = (*(uint *)(local_8 + 0xb4) & 0xf) << (bVar5 & 0x1f) | uVar6 & uVar1;
  }
  return;
}

