
void FUN_00594bc0(int param_1,int param_2)

{
  CMap *pCVar1;
  undefined4 extraout_ECX;
  int iVar2;
  int *piVar3;
  int *piVar4;
  undefined4 uVar5;
  int *piVar6;
  CMap *local_58;
  int local_54;
  int local_50;
  int iStack_4c;
  int iStack_48;
  int iStack_44;
  int local_40;
  int iStack_3c;
  int iStack_38;
  int iStack_34;
  int local_30;
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  uint local_14;
  
  pCVar1 = PTR_0077241c;
  local_14 = DAT_0076700c ^ (uint)&local_58;
  local_58 = PTR_0077241c;
  param_1 = param_1 + PTR_0077241c->originX;
  local_40 = PTR_0077241c->cellX0;
  iStack_3c = PTR_0077241c->cellY0;
  iStack_38 = PTR_0077241c->cellX1;
  iStack_34 = PTR_0077241c->cellY1;
  local_54 = 0;
  if (-1 < param_1) {
    local_54 = param_1;
  }
  param_2 = PTR_0077241c->originY + param_2;
  local_30 = PTR_0077241c->x0_8;
  iStack_2c = PTR_0077241c->y0_8;
  iStack_28 = PTR_0077241c->x1_8;
  iStack_24 = PTR_0077241c->y1_8;
  iVar2 = 0;
  if (-1 < param_2) {
    iVar2 = param_2;
  }
  PTR_0077241c->originX = local_54;
  pCVar1->originY = iVar2;
  local_50 = local_54 * 8;
  pCVar1->originX8 = local_50;
  iStack_4c = iVar2 * 8;
  pCVar1->originY8 = iStack_4c;
  pCVar1->cellX0 = local_54;
  pCVar1->cellY0 = iVar2;
  pCVar1->cellX1 = local_54 + pCVar1->mapWidth;
  pCVar1->cellY1 = pCVar1->mapHeight + iVar2;
  pCVar1->x0f = (float)pCVar1->cellX0;
  pCVar1->y0f = (float)pCVar1->cellY0;
  pCVar1->x1f = (float)pCVar1->cellX1;
  pCVar1->y1f = (float)pCVar1->cellY1;
  iStack_44 = pCVar1->mapHeight8 + iStack_4c;
  iStack_48 = pCVar1->mapWidth8 + local_50;
  pCVar1->scanlineTotal = pCVar1->mapWidth * iVar2 + local_54;
  *(undefined1 *)((int)&pCVar1->mapFlags + 1) = 1;
  pCVar1->x0_8 = local_50;
  pCVar1->y0_8 = iStack_4c;
  pCVar1->x1_8 = iStack_48;
  pCVar1->y1_8 = iStack_44;
  pCVar1->x0_8f = (float)pCVar1->x0_8;
  pCVar1->y0_8f = (float)pCVar1->y0_8;
  pCVar1->x1_8f = (float)pCVar1->x1_8;
  pCVar1->y1_8f = (float)pCVar1->y1_8;
  FUN_0059a320();
  pCVar1 = local_58;
  piVar4 = &local_40;
  piVar6 = &local_58->cellX0;
  piVar3 = piVar6;
  FUN_005a9090(piVar4,piVar6);
  FUN_005a8db0(piVar4,piVar3);
  piVar4 = &pCVar1->x0_8;
  piVar3 = &local_30;
  uVar5 = extraout_ECX;
  FUN_005a3dd0(extraout_ECX,piVar3,piVar4,extraout_ECX);
  FUN_005a7940(piVar3,piVar4,uVar5);
  FUN_005d5c30(&local_40,piVar6);
  piVar4 = &local_40;
  piVar3 = piVar6;
  FUN_0057d980(piVar4,piVar6);
  FUN_0057d6e0(piVar4,piVar3);
  FUN_00580c20(local_40,iStack_3c,iStack_38,iStack_34,*piVar6,pCVar1->cellY0,pCVar1->cellX1,
               pCVar1->cellY1);
  piVar4 = &local_40;
  piVar3 = piVar6;
  FUN_00592d70(piVar4,piVar6);
  FUN_00592a80(piVar4,piVar3);
  piVar4 = &local_40;
  FUN_00492250(piVar4,piVar6);
  FUN_0049be30(piVar4,piVar6);
  FUN_004455c0(4);
  __security_check_cookie(local_14 ^ (uint)&local_58);
  return;
}

