
/* WARNING: Removing unreachable block (ram,0x005a8ecf) */
/* WARNING: Removing unreachable block (ram,0x005a8ede) */
/* WARNING: Removing unreachable block (ram,0x005a8eef) */
/* WARNING: Removing unreachable block (ram,0x005a8efe) */
/* WARNING: Removing unreachable block (ram,0x005a8ec1) */
/* WARNING: Removing unreachable block (ram,0x005a8f24) */
/* WARNING: Removing unreachable block (ram,0x005a8f2d) */
/* WARNING: Removing unreachable block (ram,0x005a8f3e) */
/* WARNING: Removing unreachable block (ram,0x005a8f60) */
/* WARNING: Removing unreachable block (ram,0x005a8f7b) */
/* WARNING: Removing unreachable block (ram,0x005a8f85) */
/* WARNING: Removing unreachable block (ram,0x005a8fa0) */
/* WARNING: Removing unreachable block (ram,0x005a8fad) */
/* WARNING: Removing unreachable block (ram,0x005a8fc3) */
/* WARNING: Removing unreachable block (ram,0x005a8fca) */
/* WARNING: Removing unreachable block (ram,0x005a8fd0) */
/* WARNING: Removing unreachable block (ram,0x005a8fd7) */
/* WARNING: Removing unreachable block (ram,0x005a8fdd) */
/* WARNING: Removing unreachable block (ram,0x005a8fe5) */
/* WARNING: Removing unreachable block (ram,0x005a8fed) */
/* WARNING: Removing unreachable block (ram,0x005a901d) */
/* WARNING: Removing unreachable block (ram,0x005a9026) */
/* WARNING: Removing unreachable block (ram,0x005a9030) */
/* WARNING: Removing unreachable block (ram,0x005a9044) */
/* WARNING: Removing unreachable block (ram,0x005a903b) */
/* WARNING: Removing unreachable block (ram,0x005a904d) */
/* WARNING: Removing unreachable block (ram,0x005a9067) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005a8db0(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  CMap *pCVar5;
  uint uVar6;
  int in_ECX;
  int iVar7;
  undefined4 *puVar8;
  void *local_1c;
  undefined1 *puStack_18;
  undefined4 local_14;
  
  local_14 = 0xffffffff;
  puStack_18 = &LAB_006fe60d;
  local_1c = ExceptionList;
  uVar6 = DAT_0076700c ^ (uint)&stack0xfffffff0;
  ExceptionList = &local_1c;
  FUN_006c2d00(uVar6);
  local_14 = 0;
  FUN_006c2340(*param_2,param_2[1],param_2[2],param_2[3]);
  FUN_006c1c30(*param_1,param_1[1],param_1[2],param_1[3]);
  FUN_006c2080(PTR_0077241c->cellX0,PTR_0077241c->cellY0,PTR_0077241c->cellX1,PTR_0077241c->cellY1);
  puVar8 = (undefined4 *)0x0;
  for (iVar7 = 0; iVar7 < 0; iVar7 = iVar7 + 1) {
    uVar1 = *puVar8;
    puVar2 = puVar8 + 1;
    puVar3 = puVar8 + 2;
    puVar4 = puVar8 + 3;
    puVar8 = puVar8 + 4;
    FUN_006c2340(uVar1,*puVar2,*puVar3,*puVar4);
  }
  FUN_005a8bf0(param_1);
  pCVar5 = PTR_0077241c;
  *(int *)(in_ECX + 0x54) = PTR_0077241c->cellX0;
  *(int *)(in_ECX + 0x58) = pCVar5->cellY0;
  local_14 = 1;
  ExceptionList = local_1c;
  __security_check_cookie(uVar6 ^ (uint)&stack0xfffffff0);
  return;
}

