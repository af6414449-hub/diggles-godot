
void FUN_005a7c90(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  CMap *pCVar4;
  
  FUN_005a7dc0();
  pCVar4 = PTR_0077241c;
  FUN_00445640(PTR_0077241c);
  *(code **)(in_ECX + 0xc) = guard_check_icall;
  if (((pCVar4 != (CMap *)0x0) && (iVar1 = pCVar4->cellX1 - pCVar4->cellX0, iVar1 != 0)) &&
     (iVar2 = pCVar4->cellY1 - pCVar4->cellY0, iVar2 != 0)) {
    FUN_006ba940();
    *(int *)(in_ECX + 0x18) = iVar2;
    *(int *)(in_ECX + 0x14) = iVar1;
    *(undefined4 *)(in_ECX + 0x28) = 0;
    *(undefined4 *)(in_ECX + 0x24) = 4;
    *(undefined4 *)(in_ECX + 0x38) = 0xff000000;
    *(undefined4 *)(in_ECX + 0x2c) = 0xff0000;
    *(undefined4 *)(in_ECX + 0x30) = 0xff00;
    *(undefined4 *)(in_ECX + 0x34) = 0xff;
    *(int *)(in_ECX + 0x1c) = iVar2 * iVar1;
    if (1 < (iVar1 + iVar2 * iVar1) * 4) {
      uVar3 = FUN_006ba810(0x11);
      *(undefined4 *)(in_ECX + 0x28) = uVar3;
    }
    FUN_006c2340(0,0,PTR_0077241c->cellX1 - PTR_0077241c->cellX0,
                 PTR_0077241c->cellY1 - PTR_0077241c->cellY0);
    pCVar4 = PTR_0077241c;
  }
  *(int *)(in_ECX + 0x54) = pCVar4->cellX0;
  *(int *)(in_ECX + 0x58) = pCVar4->cellY0;
  return;
}

