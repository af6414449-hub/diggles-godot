
void FUN_0058f2a0(uint param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int *in_ECX;
  uint uVar7;
  
  uVar7 = in_ECX[1];
  if (uVar7 <= param_1) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    uVar7 = in_ECX[1];
    if (uVar7 <= param_1) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      uVar7 = in_ECX[1];
    }
  }
  if ((int)param_1 < (int)(uVar7 - 1)) {
    iVar3 = *in_ECX;
    puVar2 = (undefined4 *)(iVar3 + -0x14 + uVar7 * 0x14);
    uVar4 = puVar2[1];
    uVar5 = puVar2[2];
    uVar6 = puVar2[3];
    puVar1 = (undefined4 *)(iVar3 + param_1 * 0x14);
    *puVar1 = *puVar2;
    puVar1[1] = uVar4;
    puVar1[2] = uVar5;
    puVar1[3] = uVar6;
    puVar1[4] = *(undefined4 *)(iVar3 + uVar7 * 0x14 + -4);
    in_ECX[1] = in_ECX[1] + -1;
    return;
  }
  in_ECX[1] = uVar7 - 1;
  return;
}

