
void FUN_00590620(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  if (param_1 != DAT_007683d8) {
    iVar1 = DAT_007683d8;
    if (DAT_007683d8 < param_1) {
      iVar1 = param_1;
    }
    uVar5 = 8;
    iVar2 = PTR_0077241c->x0_8;
    iVar1 = iVar1 * 8 + 8;
    iVar3 = PTR_0077241c->y0_8;
    iVar4 = PTR_0077241c->x1_8;
    FUN_005a3dd0(PTR_0077241c,iVar2,iVar3,iVar4,iVar1,8);
    FUN_005a3fd0(iVar2,iVar3,iVar4,iVar1,uVar5);
    DAT_007683d8 = param_1;
  }
  return;
}

