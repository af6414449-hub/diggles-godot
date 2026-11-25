
void FUN_005d53f0(void)

{
  float fVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  float *in_ECX;
  int *local_8;
  
  if ((uint)*(float *)(DAT_00772478 + 0x801c) <= (uint)in_ECX[10]) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  iVar3 = FUN_00601df0(0,DAT_0077244c,0,in_ECX,in_ECX + 3);
  if (iVar3 != 0) {
    *(float *)(iVar3 + 0x3d0) = in_ECX[0xb];
    *(undefined1 *)(iVar3 + 0x2b7) = 1;
    *(float *)(iVar3 + 0x39c) = in_ECX[6];
    *(float *)(iVar3 + 0x3a0) = in_ECX[7];
    local_8 = (int *)(DAT_00772400 + 0x5c8);
    if ((uint)in_ECX[6] < 0x100) {
      local_8 = local_8 + (int)in_ECX[6];
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    fVar1 = in_ECX[7];
    iVar4 = *local_8;
    if (((int)fVar1 < 0) || (*(int *)(iVar4 + 0x38) <= (int)fVar1)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      iVar4 = *(int *)(iVar4 + 0x34);
    }
    else {
      iVar4 = (int)fVar1 * 0xe8 + *(int *)(iVar4 + 0x34);
    }
    uVar2 = *(undefined4 *)(iVar4 + 0xe0);
    *(undefined4 *)(iVar3 + 0x3a8) = uVar2;
    FUN_005cdae0(in_ECX[6],uVar2,0,0);
    *(uint *)(iVar3 + 0x2a8) = (uint)*(byte *)(in_ECX + 0xc);
    if (((*(float *)(iVar3 + 0xc) != *in_ECX) || (*(float *)(iVar3 + 0x10) != in_ECX[1])) ||
       (*(float *)(iVar3 + 0x14) != in_ECX[2])) {
      FUN_005cd8e0(in_ECX);
      if (*(int *)(iVar3 + 0x238) == 0) {
        iVar4 = iVar3;
        FUN_005ebc90(iVar3);
        FUN_005eb470(iVar4);
      }
    }
    FUN_005cd840(in_ECX + 3);
    FUN_005ebc90(iVar3);
    FUN_005eb470(iVar3);
  }
  return;
}

