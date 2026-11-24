
void FUN_005a8bf0(int *param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int local_24;
  int local_20;
  int local_18;
  int local_10;
  
  iVar4 = *param_1;
  if (*param_1 < PTR_0077241c->cellX0) {
    iVar4 = PTR_0077241c->cellX0;
  }
  iVar1 = param_1[1];
  if (param_1[1] < PTR_0077241c->cellY0) {
    iVar1 = PTR_0077241c->cellY0;
  }
  local_24 = param_1[2];
  if (PTR_0077241c->cellX1 < param_1[2]) {
    local_24 = PTR_0077241c->cellX1;
  }
  iVar3 = param_1[3];
  if (PTR_0077241c->cellY1 < param_1[3]) {
    iVar3 = PTR_0077241c->cellY1;
  }
  iVar6 = iVar4 - *(int *)(in_ECX + 0x54);
  local_24 = local_24 - *(int *)(in_ECX + 0x54);
  iVar7 = iVar1 - *(int *)(in_ECX + 0x58);
  iVar3 = iVar3 - *(int *)(in_ECX + 0x58);
  iVar1 = iVar1 - PTR_0077241c->cellY0;
  iVar4 = iVar4 - PTR_0077241c->cellX0;
  if (local_24 - iVar6 < 1) {
    return;
  }
  if (iVar3 - iVar7 < 1) {
    return;
  }
  if ((iVar6 == iVar4) && (iVar7 == iVar1)) {
    return;
  }
  iVar2 = iVar6;
  if ((((iVar6 < (local_24 - iVar6) + iVar4) && (iVar7 < (iVar3 - iVar7) + iVar1)) &&
      (iVar4 < local_24)) && (iVar1 < iVar3)) {
    local_18 = (uint)(iVar4 <= iVar6) * 2 + -1;
    if (iVar7 < iVar1) {
      local_20 = -1;
      local_10 = -1;
      local_18 = 1;
      goto LAB_005a8d25;
    }
  }
  else {
    local_18 = 1;
  }
  local_10 = 1;
  local_20 = 1;
  if (local_18 != 1) {
    iVar2 = local_24 + -1;
    local_20 = 1;
    local_24 = iVar6 + -1;
  }
LAB_005a8d25:
  iVar5 = iVar3;
  if (local_10 != 1) {
    iVar5 = iVar7 + -1;
  }
  iVar8 = iVar7;
  if (local_10 != 1) {
    iVar8 = iVar3 + -1;
  }
  if (iVar8 != iVar5) {
    iVar1 = iVar8 + (iVar1 - iVar7);
    iVar3 = iVar2;
    do {
      while (iVar3 != local_24) {
        *(undefined4 *)
         (*(int *)(in_ECX + 0x28) + (iVar1 * *(int *)(in_ECX + 0x14) + iVar3 + (iVar4 - iVar6)) * 4)
             = *(undefined4 *)
                (*(int *)(in_ECX + 0x28) + (*(int *)(in_ECX + 0x14) * iVar8 + iVar3) * 4);
        iVar3 = iVar3 + local_18;
      }
      iVar8 = iVar8 + local_20;
      iVar1 = iVar1 + local_20;
      iVar3 = iVar2;
    } while (iVar8 != iVar5);
  }
  return;
}

