
void FUN_100088c0(uint param_1,undefined4 *param_2,code *param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char cVar5;
  int iVar6;
  undefined4 *puVar7;
  int in_ECX;
  int iVar8;
  int in_EDX;
  int iVar9;
  int iVar10;
  
  __CheckForDebuggerJustMyCode(&DAT_14170b7c);
  iVar6 = (int)(param_1 - 1) >> 1;
  iVar10 = in_EDX;
  iVar9 = in_EDX;
  if (in_EDX < iVar6) {
    do {
      iVar9 = iVar10 * 2 + 2;
      iVar8 = iVar9 * 0x20 + in_ECX;
      cVar5 = (*param_3)(iVar8,iVar8 + -0x20);
      if (cVar5 != '\0') {
        iVar9 = iVar10 * 2 + 1;
      }
      puVar7 = (undefined4 *)(iVar9 * 0x20 + in_ECX);
      uVar2 = puVar7[1];
      uVar3 = puVar7[2];
      uVar4 = puVar7[3];
      puVar1 = (undefined4 *)(iVar10 * 0x20 + in_ECX);
      *puVar1 = *puVar7;
      puVar1[1] = uVar2;
      puVar1[2] = uVar3;
      puVar1[3] = uVar4;
      puVar7 = (undefined4 *)(iVar9 * 0x20 + 0x10 + in_ECX);
      uVar2 = puVar7[1];
      uVar3 = puVar7[2];
      uVar4 = puVar7[3];
      puVar1 = (undefined4 *)(iVar10 * 0x20 + 0x10 + in_ECX);
      *puVar1 = *puVar7;
      puVar1[1] = uVar2;
      puVar1[2] = uVar3;
      puVar1[3] = uVar4;
      iVar10 = iVar9;
    } while (iVar9 < iVar6);
  }
  if ((iVar9 == iVar6) && ((param_1 & 1) == 0)) {
    puVar1 = (undefined4 *)(param_1 * 0x20 + -0x20 + in_ECX);
    uVar2 = puVar1[1];
    uVar3 = puVar1[2];
    uVar4 = puVar1[3];
    puVar7 = (undefined4 *)(iVar9 * 0x20 + in_ECX);
    *puVar7 = *puVar1;
    puVar7[1] = uVar2;
    puVar7[2] = uVar3;
    puVar7[3] = uVar4;
    puVar7 = (undefined4 *)(param_1 * 0x20 + -0x10 + in_ECX);
    uVar2 = puVar7[1];
    uVar3 = puVar7[2];
    uVar4 = puVar7[3];
    puVar1 = (undefined4 *)(iVar9 * 0x20 + 0x10 + in_ECX);
    *puVar1 = *puVar7;
    puVar1[1] = uVar2;
    puVar1[2] = uVar3;
    puVar1[3] = uVar4;
    iVar9 = param_1 - 1;
  }
  while (in_EDX < iVar9) {
    iVar10 = iVar9 + -1 >> 1;
    puVar7 = (undefined4 *)(iVar10 * 0x20 + in_ECX);
    cVar5 = (*param_3)(puVar7,param_2);
    if (cVar5 == '\0') break;
    uVar2 = puVar7[1];
    uVar3 = puVar7[2];
    uVar4 = puVar7[3];
    puVar1 = (undefined4 *)(iVar9 * 0x20 + in_ECX);
    *puVar1 = *puVar7;
    puVar1[1] = uVar2;
    puVar1[2] = uVar3;
    puVar1[3] = uVar4;
    uVar2 = puVar7[5];
    uVar3 = puVar7[6];
    uVar4 = puVar7[7];
    puVar1 = (undefined4 *)(iVar9 * 0x20 + 0x10 + in_ECX);
    *puVar1 = puVar7[4];
    puVar1[1] = uVar2;
    puVar1[2] = uVar3;
    puVar1[3] = uVar4;
    iVar9 = iVar10;
  }
  uVar2 = param_2[1];
  uVar3 = param_2[2];
  uVar4 = param_2[3];
  puVar7 = (undefined4 *)(iVar9 * 0x20 + in_ECX);
  *puVar7 = *param_2;
  puVar7[1] = uVar2;
  puVar7[2] = uVar3;
  puVar7[3] = uVar4;
  uVar2 = param_2[5];
  uVar3 = param_2[6];
  uVar4 = param_2[7];
  puVar7 = (undefined4 *)(iVar9 * 0x20 + 0x10 + in_ECX);
  *puVar7 = param_2[4];
  puVar7[1] = uVar2;
  puVar7[2] = uVar3;
  puVar7[3] = uVar4;
  return;
}

