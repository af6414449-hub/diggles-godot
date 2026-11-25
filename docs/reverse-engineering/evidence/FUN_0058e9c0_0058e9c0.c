
undefined4 FUN_0058e9c0(int param_1,int param_2,int param_3,uint *param_4)

{
  int iVar1;
  uint uVar2;
  int in_ECX;
  int iVar3;
  undefined4 uVar4;
  bool bVar5;
  int local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070672d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_0040ba00(DAT_0076700c ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  local_14 = 0;
  if (0 < *(int *)(in_ECX + 0x2c)) {
    iVar3 = 0;
    bVar5 = *(int *)(in_ECX + 0x2c) != 0;
    do {
      uVar2 = local_14;
      if (!bVar5) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      iVar1 = *(int *)(in_ECX + 0x28);
      if (*(int *)(iVar3 + 0xc + iVar1) == param_1) {
        if (*(uint *)(in_ECX + 0x2c) <= uVar2) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar1 = *(int *)(in_ECX + 0x28);
        }
        if (*(int *)(iVar1 + 0x10 + iVar3) == param_3) {
          if (*(uint *)(in_ECX + 0x2c) <= uVar2) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar1 = *(int *)(in_ECX + 0x28);
          }
          if (*(int *)(iVar1 + 0x14 + iVar3) == param_2) {
            FUN_00491db0(&local_14);
          }
        }
      }
      local_14 = uVar2 + 1;
      iVar3 = iVar3 + 0x1c;
      bVar5 = local_14 < *(uint *)(in_ECX + 0x2c);
    } while ((int)local_14 < (int)*(uint *)(in_ECX + 0x2c));
  }
  if (local_18 == 0) {
    uVar4 = 0xffffffff;
  }
  else {
    uVar2 = *param_4;
    if ((uVar2 == 0xffffffff) || ((int)local_18 <= (int)uVar2)) {
      uVar2 = FUN_0049c670();
      uVar2 = (uint)((longlong)(ulonglong)(uVar2 & 0x7fffffff) % (longlong)(int)local_18);
      *param_4 = uVar2;
      if (local_18 <= uVar2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else if (local_18 <= uVar2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    uVar4 = *(undefined4 *)(local_1c + uVar2 * 4);
  }
  local_8 = 3;
  FUN_0040b980(0);
  if (local_1c != 0) {
    FUN_006ba940();
  }
  ExceptionList = local_10;
  return uVar4;
}

