
/* WARNING: Removing unreachable block (ram,0x005a7abe) */
/* WARNING: Removing unreachable block (ram,0x005a7acd) */
/* WARNING: Removing unreachable block (ram,0x005a7ade) */
/* WARNING: Removing unreachable block (ram,0x005a7af0) */
/* WARNING: Removing unreachable block (ram,0x005a7ab0) */
/* WARNING: Removing unreachable block (ram,0x005a7b1a) */
/* WARNING: Removing unreachable block (ram,0x005a7b23) */
/* WARNING: Removing unreachable block (ram,0x005a7b34) */
/* WARNING: Removing unreachable block (ram,0x005a7b56) */
/* WARNING: Removing unreachable block (ram,0x005a7b71) */
/* WARNING: Removing unreachable block (ram,0x005a7b7b) */
/* WARNING: Removing unreachable block (ram,0x005a7b96) */
/* WARNING: Removing unreachable block (ram,0x005a7ba3) */
/* WARNING: Removing unreachable block (ram,0x005a7bb9) */
/* WARNING: Removing unreachable block (ram,0x005a7bc0) */
/* WARNING: Removing unreachable block (ram,0x005a7bc6) */
/* WARNING: Removing unreachable block (ram,0x005a7bcd) */
/* WARNING: Removing unreachable block (ram,0x005a7bd3) */
/* WARNING: Removing unreachable block (ram,0x005a7bdb) */
/* WARNING: Removing unreachable block (ram,0x005a7be3) */
/* WARNING: Removing unreachable block (ram,0x005a7c13) */
/* WARNING: Removing unreachable block (ram,0x005a7c1c) */
/* WARNING: Removing unreachable block (ram,0x005a7c26) */
/* WARNING: Removing unreachable block (ram,0x005a7c3a) */
/* WARNING: Removing unreachable block (ram,0x005a7c31) */
/* WARNING: Removing unreachable block (ram,0x005a7c43) */
/* WARNING: Removing unreachable block (ram,0x005a7c62) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005a7940(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  int iVar8;
  undefined4 *puVar9;
  uint local_3c;
  undefined4 *local_38;
  void *local_1c;
  undefined1 *puStack_18;
  undefined4 local_14;
  
  puStack_18 = &LAB_00706dad;
  local_1c = ExceptionList;
  uVar7 = DAT_0076700c ^ (uint)&stack0xfffffff0;
  ExceptionList = &local_1c;
  local_14 = 0;
  FUN_006c2340(*param_2,param_2[1],param_2[2],param_2[3]);
  FUN_006c1c30(*param_1,param_1[1],param_1[2],param_1[3]);
  local_3c = 0;
  do {
    puVar9 = (undefined4 *)0x0;
    if (0xc < local_3c) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    FUN_006c2080(PTR_0077241c->x0_8,PTR_0077241c->y0_8,PTR_0077241c->x1_8,PTR_0077241c->y1_8);
    iVar8 = 0;
    while (local_38 = (undefined4 *)0x0, iVar8 < 0) {
      uVar1 = *puVar9;
      uVar2 = puVar9[1];
      uVar3 = puVar9[2];
      uVar4 = puVar9[3];
      iVar8 = iVar8 + 1;
      puVar9 = puVar9 + 4;
      if (local_3c < 0xd) {
        FUN_006c2340(uVar1,uVar2,uVar3,uVar4);
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        FUN_006c2340(uVar1,uVar2,uVar3,uVar4);
      }
    }
    local_3c = local_3c + 1;
  } while ((int)local_3c < 0xd);
  for (iVar8 = 0; iVar8 < 0; iVar8 = iVar8 + 1) {
    uVar1 = *local_38;
    puVar9 = local_38 + 1;
    puVar5 = local_38 + 2;
    puVar6 = local_38 + 3;
    local_38 = local_38 + 4;
    FUN_005a77a0(uVar1,*puVar9,*puVar5,*puVar6,1);
  }
  local_14 = 1;
  ExceptionList = local_1c;
  __security_check_cookie(uVar7 ^ (uint)&stack0xfffffff0);
  return;
}

