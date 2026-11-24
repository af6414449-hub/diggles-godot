
void FUN_00566550(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  uint uVar9;
  undefined4 uVar10;
  int local_3c;
  int local_38;
  
  uVar1 = *(uint *)(in_ECX + 0x11c);
  iVar3 = *(int *)(in_ECX + 0xe0);
  if (iVar3 == 1) {
    iVar6 = (int)*(float *)(in_ECX + 0xf0);
    iVar7 = (int)*(float *)(in_ECX + 0xe4);
    iVar4 = (int)*(float *)(in_ECX + 0xe8);
    iVar3 = iVar7;
    if (iVar6 <= iVar7) {
      iVar3 = iVar6;
    }
    iVar2 = (int)*(float *)(in_ECX + 0xf4);
    iVar5 = iVar4;
    if (iVar2 <= iVar4) {
      iVar5 = iVar2;
    }
    if (iVar7 <= iVar6) {
      iVar7 = iVar6;
    }
    if (iVar4 <= iVar2) {
      iVar4 = iVar2;
    }
    local_38 = PTR_0077241c->cellX0;
    if (PTR_0077241c->cellX0 <= iVar3) {
      local_38 = iVar3;
    }
    iVar3 = PTR_0077241c->cellX1;
    local_3c = PTR_0077241c->cellY0;
    if (PTR_0077241c->cellY0 <= iVar5) {
      local_3c = iVar5;
    }
    if (iVar3 <= local_38) {
      local_38 = iVar3 + -1;
    }
    iVar6 = PTR_0077241c->cellY1;
    if (iVar6 <= local_3c) {
      local_3c = iVar6 + -1;
    }
    iVar5 = PTR_0077241c->cellX0;
    if (PTR_0077241c->cellX0 <= iVar7 + 2) {
      iVar5 = iVar7 + 2;
    }
    iVar7 = PTR_0077241c->cellY0;
    if (PTR_0077241c->cellY0 <= iVar4 + 2) {
      iVar7 = iVar4 + 2;
    }
    iVar4 = iVar3 + -1;
    if (iVar5 < iVar3) {
      iVar4 = iVar5;
    }
    iVar3 = iVar6 + -1;
    if (iVar7 < iVar6) {
      iVar3 = iVar7;
    }
    piVar8 = (int *)(DAT_00772400 + 0xa328);
    if (uVar1 < 8) {
      piVar8 = piVar8 + uVar1 * 4;
      uVar9 = uVar1;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      uVar9 = *(uint *)(in_ECX + 0x11c);
    }
    iVar7 = *piVar8;
    if (local_38 < *piVar8) {
      iVar7 = local_38;
    }
    iVar6 = piVar8[1];
    if (local_3c < piVar8[1]) {
      iVar6 = local_3c;
    }
    iVar5 = piVar8[2];
    if (piVar8[2] < iVar4) {
      iVar5 = iVar4;
    }
    iVar2 = piVar8[3];
    if (piVar8[3] < iVar3) {
      iVar2 = iVar3;
    }
    piVar8 = (int *)(DAT_00772400 + 0xa328);
    if (uVar9 < 8) {
      piVar8 = piVar8 + uVar9 * 4;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    *piVar8 = iVar7;
    piVar8[1] = iVar6;
    piVar8[2] = iVar5;
    piVar8[3] = iVar2;
    for (iVar7 = local_3c; iVar7 < iVar3; iVar7 = iVar7 + 1) {
      if (local_38 < iVar4) {
        iVar5 = (iVar7 + -1) / 2;
        iVar6 = local_38;
        do {
          if (((byte)iVar5 & (byte)((iVar6 + -1) / 2) & 1) == 0) {
            FUN_005672d0(iVar6,iVar7,iVar5,uVar1);
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < iVar4);
      }
    }
    if (uVar1 < 8) {
      piVar8 = (int *)(in_ECX + 0xb4 + uVar1 * 4);
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar8 = (int *)(in_ECX + 0xb4);
    }
    *piVar8 = *piVar8 + 1;
    uVar10 = 0x40;
    iVar7 = local_38 * 8;
    iVar3 = iVar3 * 8 + 8;
    local_3c = local_3c << 3;
    iVar4 = iVar4 * 8 + 8;
    FUN_005a3dd0(local_38,iVar7,local_3c,iVar4,iVar3,0x40);
    FUN_005a3fd0(iVar7,local_3c,iVar4,iVar3,uVar10);
    iVar3 = *(int *)(in_ECX + 0xe0);
  }
  if (iVar3 == 2) {
    FUN_00567410(param_1);
  }
  *(undefined4 *)(in_ECX + 0xe0) = 0;
  return;
}

