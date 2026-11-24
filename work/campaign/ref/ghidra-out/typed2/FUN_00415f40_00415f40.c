
undefined4 * FUN_00415f40(undefined4 param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  byte bVar3;
  undefined4 *puVar4;
  int in_ECX;
  int iVar5;
  uint uVar6;
  uint uVar7;
  float local_c;
  
  local_c = *(float *)(in_ECX + 0x24);
  if (((param_3 == 0) && (local_c == -1.0)) && ((int)param_2 < *(int *)(in_ECX + 0x1c))) {
    iVar5 = *(int *)(in_ECX + 0x10);
    uVar7 = *(int *)(iVar5 + 0xc) - 1;
    uVar6 = param_2 + 1;
    if ((int)uVar7 <= (int)(param_2 + 1)) {
      uVar6 = uVar7;
    }
    if ((int)param_2 < (int)uVar7) {
      uVar7 = param_2;
    }
    if (*(uint *)(iVar5 + 0xc) <= uVar6) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      iVar5 = *(int *)(in_ECX + 0x10);
    }
    if (*(uint *)(iVar5 + 0xc) <= uVar7) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    FUN_004093f0(PTR_0077241c);
    FUN_004093f0(PTR_0077241c);
    bVar3 = FUN_004093f0(PTR_0077241c);
    local_c = 15.0;
    if ((float)bVar3 + 1.0 <= 15.0) {
      local_c = (float)bVar3 + 1.0;
    }
  }
  puVar4 = (undefined4 *)FUN_006ba810(0xc6);
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    puVar4[3] = 0;
    puVar4[4] = 0;
    *puVar4 = CAct_WalkFloor::vftable;
    puVar4[0xc] = 0;
    puVar4[0xb] = 0;
    puVar4[10] = 0;
    puVar4[0xe] = 0;
    puVar4[0xf] = 0;
    puVar4[6] = 0;
    puVar4[5] = 0;
    puVar4[7] = 0;
  }
  iVar5 = *(int *)(in_ECX + 0x10);
  if (iVar5 != 0) {
    LOCK();
    *(int *)(iVar5 + 4) = *(int *)(iVar5 + 4) + 1;
    UNLOCK();
  }
  uVar1 = *(undefined4 *)(in_ECX + 4);
  iVar2 = *(int *)(in_ECX + 0xc);
  if (iVar2 != 0) {
    LOCK();
    *(int *)(iVar2 + 4) = *(int *)(iVar2 + 4) + 1;
    UNLOCK();
  }
  FUN_0041a910(iVar2,uVar1,iVar5,param_1,param_2,param_3 == 0,local_c);
  return puVar4;
}

