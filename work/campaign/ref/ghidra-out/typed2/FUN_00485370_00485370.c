
void FUN_00485370(int param_1,int param_2)

{
  CMap *pCVar1;
  int iVar2;
  int in_ECX;
  uint uVar3;
  uint uVar4;
  double dVar5;
  
  pCVar1 = PTR_0077241c;
  if (((((param_1 != *(int *)(in_ECX + 0x18)) || (param_2 != *(int *)(in_ECX + 0x1c))) &&
       (PTR_0077241c->cellX0 + 2 <= param_1)) &&
      ((param_1 < PTR_0077241c->cellX1 + -2 && (PTR_0077241c->cellY0 + 2 <= param_2)))) &&
     (param_2 < PTR_0077241c->cellY1 + -2)) {
    uVar4 = *(uint *)(in_ECX + 0x10);
    *(int *)(in_ECX + 0x18) = param_1;
    *(int *)(in_ECX + 0x1c) = param_2;
    iVar2 = FUN_00592f10(pCVar1);
    *(uint *)(in_ECX + 0x20) = (uint)*(byte *)(iVar2 + 7) << 8;
    if (uVar4 < 8) {
      iVar2 = iVar2 + uVar4;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    uVar3 = (uint)*(byte *)(iVar2 + 0x34);
    if ((uVar3 == 0) || (0x7f < uVar3)) {
      iVar2 = uVar3 - 0x80;
      *(int *)(in_ECX + 0x30) = iVar2;
      if (0 < iVar2) {
        dVar5 = (double)iVar2;
        iVar2 = 0x80;
        if ((int)(dVar5 * 1.3) < 0x80) {
          iVar2 = (int)(dVar5 * 1.3);
        }
        *(int *)(in_ECX + 0x30) = iVar2;
      }
      uVar3 = iVar2 * 2;
      if ((0 < (int)uVar3) && (0xff < (int)uVar3)) {
        uVar3 = 0xff;
      }
    }
    else {
      *(undefined4 *)(in_ECX + 0x30) = 0;
      uVar3 = 0;
    }
    pCVar1 = PTR_0077241c;
    iVar2 = 0xff - ((uVar3 ^ (int)uVar3 >> 0x1f) - ((int)uVar3 >> 0x1f));
    if (iVar2 < 1) {
      iVar2 = 0;
    }
    *(float *)(in_ECX + 0x40) = (float)iVar2 / 255.0;
    iVar2 = FUN_00592f10(pCVar1);
    *(uint *)(in_ECX + 0x24) = (uint)*(byte *)(iVar2 + 7) << 8;
    if (uVar4 < 8) {
      iVar2 = iVar2 + uVar4;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    uVar3 = (uint)*(byte *)(iVar2 + 0x34);
    if ((uVar3 == 0) || (0x7f < uVar3)) {
      iVar2 = uVar3 - 0x80;
      *(int *)(in_ECX + 0x34) = iVar2;
      if (0 < iVar2) {
        dVar5 = (double)iVar2;
        iVar2 = 0x80;
        if ((int)(dVar5 * 1.3) < 0x80) {
          iVar2 = (int)(dVar5 * 1.3);
        }
        *(int *)(in_ECX + 0x34) = iVar2;
      }
      uVar3 = iVar2 * 2;
      if ((0 < (int)uVar3) && (0xff < (int)uVar3)) {
        uVar3 = 0xff;
      }
    }
    else {
      *(undefined4 *)(in_ECX + 0x34) = 0;
      uVar3 = 0;
    }
    pCVar1 = PTR_0077241c;
    iVar2 = 0xff - ((uVar3 ^ (int)uVar3 >> 0x1f) - ((int)uVar3 >> 0x1f));
    if (iVar2 < 1) {
      iVar2 = 0;
    }
    *(float *)(in_ECX + 0x44) = (float)iVar2 / 255.0;
    iVar2 = FUN_00592f10(pCVar1);
    *(uint *)(in_ECX + 0x28) = (uint)*(byte *)(iVar2 + 7) << 8;
    if (uVar4 < 8) {
      iVar2 = iVar2 + uVar4;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    uVar3 = (uint)*(byte *)(iVar2 + 0x34);
    if ((uVar3 == 0) || (0x7f < uVar3)) {
      iVar2 = uVar3 - 0x80;
      *(int *)(in_ECX + 0x38) = iVar2;
      if (0 < iVar2) {
        dVar5 = (double)iVar2;
        iVar2 = 0x80;
        if ((int)(dVar5 * 1.3) < 0x80) {
          iVar2 = (int)(dVar5 * 1.3);
        }
        *(int *)(in_ECX + 0x38) = iVar2;
      }
      uVar3 = iVar2 * 2;
      if ((0 < (int)uVar3) && (0xff < (int)uVar3)) {
        uVar3 = 0xff;
      }
    }
    else {
      *(undefined4 *)(in_ECX + 0x38) = 0;
      uVar3 = 0;
    }
    pCVar1 = PTR_0077241c;
    iVar2 = 0xff - ((uVar3 ^ (int)uVar3 >> 0x1f) - ((int)uVar3 >> 0x1f));
    if (iVar2 < 1) {
      iVar2 = 0;
    }
    *(float *)(in_ECX + 0x48) = (float)iVar2 / 255.0;
    iVar2 = FUN_00592f10(pCVar1);
    *(uint *)(in_ECX + 0x2c) = (uint)*(byte *)(iVar2 + 7) << 8;
    if (uVar4 < 8) {
      iVar2 = iVar2 + uVar4;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    uVar4 = (uint)*(byte *)(iVar2 + 0x34);
    if ((uVar4 == 0) || (0x7f < uVar4)) {
      iVar2 = uVar4 - 0x80;
      *(int *)(in_ECX + 0x3c) = iVar2;
      if (0 < iVar2) {
        dVar5 = (double)iVar2;
        iVar2 = 0x80;
        if ((int)(dVar5 * 1.3) < 0x80) {
          iVar2 = (int)(dVar5 * 1.3);
        }
        *(int *)(in_ECX + 0x3c) = iVar2;
      }
      uVar4 = iVar2 * 2;
      if ((0 < (int)uVar4) && (0xff < (int)uVar4)) {
        uVar4 = 0xff;
      }
    }
    else {
      *(undefined4 *)(in_ECX + 0x3c) = 0;
      uVar4 = 0;
    }
    iVar2 = 0xff - ((uVar4 ^ (int)uVar4 >> 0x1f) - ((int)uVar4 >> 0x1f));
    if (iVar2 < 1) {
      iVar2 = 0;
    }
    *(float *)(in_ECX + 0x4c) = (float)iVar2 / 255.0;
  }
  return;
}

